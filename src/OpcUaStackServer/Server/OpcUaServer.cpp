/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/asio/ip/host_name.hpp>
#include <OpcUaStackCore/Certificate/ApplicationCertificateConfig.h>
#include <OpcUaStackServer/Server/OpcUaServer.h>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackServer/ServiceSet/EndpointDescriptionConfig.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	OpcUaServer::OpcUaServer(void)
	: Core()
	, informationModel_(boost::make_shared<InformationModel>())
	, sessionManager_()
	, serviceManager_()
	, applicationManager_()
	, serverInfo_()
	, serverStatusDataType_()
	, cryptoManager_()
	{
		// create thread pool
		createThreadPool();

		// create message bus
		createMessageBus();
	}

	OpcUaServer::~OpcUaServer(void)
	{
	}

	void
	OpcUaServer::createThreadPool(void)
	{
		// create thread pool
		ioThread_ = boost::make_shared<IOThread>();
		ioThread_->numberThreads(2);
		ioThread_->name("Srv");
	}

	void
	OpcUaServer::createMessageBus(void)
	{
		messageBus_ = boost::make_shared<MessageBus>();
		messageBus_->debugLogging(true); // FIXME: add parameter to configuration file or rework logging
	}

	InformationModel::SPtr 
	OpcUaServer::getInformationModel(void)
	{
		return informationModel_;
	}

	IOThread::SPtr
	OpcUaServer::ioThread(void)
	{
		return ioThread_;
	}

	MessageBus::SPtr
	OpcUaServer::messageBus(void)
	{
		return messageBus_;
	}

	bool
	OpcUaServer::startup(void)
	{
		bool rc = true;

		Log(Info, "init thread pool");
		rc = rc && initOpcUaServer();

		Log(Info, "init opc ua core stack");
		rc = rc && Core::init();

		Log(Info, "init crypto");
		rc = rc && initCrypto();

		Log(Info, "init opc ua server stack information model (structure)");
		rc = rc && readInformationModel();

		Log(Info, "init opc ua server stack information model (data)");
		rc = rc && initInformationModel();

		Log(Info, "init opc ua server stack service manager");
		rc = rc && initServiceManager();

		Log(Info, "init opc ua server stack session manager");
		rc = rc && initSessionManager();

		Log(Info, "init application");
		rc = rc && initApplication();

		return rc;
	}

	bool
	OpcUaServer::shutdown(void)
	{
		Log(Info, "shutdown opc ua server stack session");
		shutdownSessionManager();

		Log(Info, "shutdown opc ua server stack service");
		shutdownServiceManager();

		Log(Info, "shutdown opc ua server stack information model (data)");
		shutdownInformationModel();

		Log(Info, "shutdown opc ua core stack");
		Core::cleanup();

		// stop threads
		Log(Info, "shutdown ioThread");
		ioThread_->shutdown();

		return true;
	}

	bool 
	OpcUaServer::start(void)
	{
		Log(Info, "startup ioThread");
		if (!ioThread_->startup())
		{
			Log(Error, "server io thread start failed");
			return false;
		}

		// startup application
		Log(Info, "startup application");
		if (!applicationManager_.startup()) {
			Log(Error, "server application manager start failed");
			return false;
		}

		// startup opc ua stack
		Log(Info, "start opc ua server stack");
		if (!sessionManager_.startup()) {
			Log(Error, "server session manager start failed");
			return false;
		}
	
		return true;
	}
	
	void 
	OpcUaServer::stop(void)
	{
		// shutdown opc ua stack
		Log(Info, "shutdown session manager");
		sessionManager_.shutdown();

		// shutdown application
		Log(Info, "shutdown application");
		applicationManager_.shutdown();
	}

	ApplicationManager&
	OpcUaServer::applicationManager(void)
	{
		return applicationManager_;
	}

	ServiceManager&
	OpcUaServer::serviceManager(void)
	{
		return serviceManager_;
	}

	CryptoManager::SPtr&
	OpcUaServer::cryptoManager(void)
	{
		return cryptoManager_;
	}

	bool
	OpcUaServer::writeInformationModel(const std::string& nodeSetFileName, std::vector<std::string>& namespaceUris)
	{
		NodeSetXmlParser nodeSetXmlParser;

		if (!InformationModelNodeSet::initial(nodeSetXmlParser, informationModel_, namespaceUris)) {
			Log(Error, "node set initialisation error")
				.parameter("NodeSetFileName", nodeSetFileName);
			return false;
		}

		ConfigXml configXml;
		if (!nodeSetXmlParser.encode(configXml.ptree())) {
			Log(Error, "node set encode error")
				.parameter("NodeSetFileName", nodeSetFileName);
			return false;
		}

		if (!configXml.write(nodeSetFileName)) {
			Log(Error, "node set file write error")
				.parameter("NodeSetFileName", nodeSetFileName)
				.parameter("ErrorMessage", configXml.errorMessage());
			return false;
		}
			
		return true;
	}

	bool 
	OpcUaServer::readInformationModel(void)
	{
		std::vector<std::string> configVec;
		config().getValues("OpcUaServer.InformationModel.NodeSetFile", configVec);
		if  (configVec.size() == 0) {
			Log(Error, "nodeset file not exist in configuration file")
				.parameter("ConfigurationFileName", config().configFileName())
				.parameter("Path", "OpcUaServer.InformationModel.NodeSetFile");
			return false;
		}

		for (auto it=configVec.begin(); it!=configVec.end(); it++) {
			std::string nodeSetFileName = *it;

			Log(Info, "read node set file")
				.parameter("NodeSetFile", nodeSetFileName);

			ConfigXml configXml;
			if (!configXml.parse(nodeSetFileName)) {
				Log(Error, "node set file parse error")
					.parameter("NodeSetFileName", nodeSetFileName)
					.parameter("ErrorMessage", configXml.errorMessage());
				return false;
			}

			NodeSetXmlParser nodeSetXmlParser;
			if (!nodeSetXmlParser.decode(configXml.ptree())) {
				Log(Error, "node set decode error")
					.parameter("NodeSetFileName", nodeSetFileName);
				return false;
			}

			if (!InformationModelNodeSet::initial(informationModel_, nodeSetXmlParser)) {
				Log(Error, "node set initialisation error")
					.parameter("NodeSetFileName", nodeSetFileName);
				return false;
			}
		}

		// check forward references only once
		if (!InformationModelNodeSet::checkForwardReferences(informationModel_)) {
			Log(Error, "node set forward references error");
			return false;
		}

		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// opc ua server
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaServer::initOpcUaServer(void)
	{
		// read optional thread pool information for server thread pool
		std::string threadPoolName;
		if (config().getConfigParameter("OpcUaServer.Server.ServerThreadPool.Name", threadPoolName)) {
			ioThread_->name(threadPoolName);
		}

		uint32_t numberThreads;
		if (config().getConfigParameter("OpcUaServer.Server.ServerThreadPool.NumberThreads", numberThreads)) {
			ioThread_->numberThreads(numberThreads);
		}

		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// information model
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaServer::initInformationModel(void)
	{
		// replace namespaces by namespace array
		{
			NodeSetNamespace nodeSetNamespace;
			NamespaceArray namespaceArray;
			namespaceArray.informationModel(informationModel_);
			namespaceArray.replaceNamespaceNames(nodeSetNamespace.globalNamespaceVec());
		}

		// set server array
		{
			std::string hostname = boost::asio::ip::host_name();
			ServerArray serverArray;
			serverArray.informationModel(informationModel_);
			serverArray.addServerName("urn:" + hostname + ":asneg:ASNeG-Demo");
		}

		// set locale id array
		{
			OpcUaDataValue dataValue;
			informationModel_->getValue(OpcUaId_Server_ServerCapabilities_LocaleIdArray, AttributeId_Value, dataValue);
			OpcUaString::SPtr stringValue = boost::make_shared<OpcUaString>();
			*stringValue = "en";
			dataValue.variant()->pushBack(stringValue);
			dataValue.statusCode(Success);
			dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
			dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
			bool rc = informationModel_->setValue(OpcUaId_Server_ServerCapabilities_LocaleIdArray, AttributeId_Value, dataValue);
		}

		// ServerStatusDataType
		serverStatusDataType_.init(informationModel_);

		return true;
	}

	bool
	OpcUaServer::shutdownInformationModel(void)
	{
		serverStatusDataType_.shutdown();
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// crypto
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaServer::initCrypto(void)
	{
		bool rc;

		// decode endpoint configuration
		endpointDescriptionSet_ = boost::make_shared<EndpointDescriptionSet>();
		rc = EndpointDescriptionConfig::endpointDescriptions(
			endpointDescriptionSet_,
			"OpcUaServer.Endpoints",
			&config(),
			config().configFileName()
		);
		if (!rc) {
			Log(Error, "endpoint description array error");
			return false;
		}

		// decode server info
		rc = serverInfo_.parse(&config(), "OpcUaServer.ServerInfo");
		if (!rc) {
			Log(Error, "server info error");
			return false;
		}

		// decode certificate configuration
		auto certificateManager = boost::make_shared<CertificateManager>();
		rc = ApplicationCertificateConfig::parse(
			certificateManager,
			"OpcUaServer.ServerInfo",
			"OpcUaServer.ApplicationCertificate",
			&config(),
			config().configFileName()
		);
		if (!rc) {
			Log(Error, "parse application certificate configuration error");
			return false;
		}
		if (!certificateManager->init()) {
			return false;
		}

		// create application certificate
		auto applicationCertificate = boost::make_shared<ApplicationCertificate>();
		if (!applicationCertificate->init(certificateManager)) {
			Log(Error, "init application certificate error");
			return false;
		}

		// create crypto manager
		cryptoManager_ = boost::make_shared<CryptoManager>();
		cryptoManager_->certificateManager(certificateManager);
		cryptoManager_->applicationCertificate(applicationCertificate);

		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// service
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaServer::initServiceManager(void)
	{
		serviceManager_.ioThread(ioThread_);
		serviceManager_.messageBus(messageBus_);
		serviceManager_.endpointDescriptionSet(endpointDescriptionSet_);
		serviceManager_.cryptoManager(cryptoManager_);

		if (!serviceManager_.initService(sessionManager_)) {
			Log log(Error, "init service manager error");
			return false;
		}

		serviceManager_.informationModel(informationModel_);

		if (!serviceManager_.init()) {
			Log log(Error, "init service manager error");
			return false;
		}
		return true;
	}

	bool
	OpcUaServer::shutdownServiceManager(void)
	{
		serviceManager_.shutdown();
		return true;
	}

	bool
	OpcUaServer::initSessionManager(void)
	{
		// initialize session manager
		sessionManager_.ioThread(ioThread_.get());
		sessionManager_.messageBus(messageBus_);
		sessionManager_.endpointDescriptionSet(endpointDescriptionSet_);
		sessionManager_.cryptoManager(cryptoManager_);
		sessionManager_.config(&config());

		return true;
	}

	bool
	OpcUaServer::shutdownSessionManager(void)
	{
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// init application
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	OpcUaServer::initApplication(void)
	{
		applicationManager_.ioThread(ioThread_);
		applicationManager_.messageBus(messageBus_);
		applicationManager_.cryptoManager(cryptoManager_);
		return true;
	}

}
