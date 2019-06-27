/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackServer/Server/Server.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"
#include "OpcUaStackServer/ServiceSet/EndpointDescriptionConfig.h"


using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	Server::Server(void)
	: Core()
	, ioThread_(constructSPtr<IOThread>())
	, informationModel_(constructSPtr<InformationModel>())
	, sessionManager_()
	, serviceManager_()
	, applicationManager_()
	, serverInfo_()
	, serverStatusDataType_()
	, applicationCertificate_()
	, cryptoManager_()
	{
	}

	Server::~Server(void)
	{
	}

	InformationModel::SPtr 
	Server::getInformationModel(void)
	{
		return informationModel_;
	}

	IOThread*
	Server::ioThread(void)
	{
		return ioThread_.get();
	}

	bool
	Server::init(void)
	{
		bool rc = true;

		Log(Info, "init opc ua core stack");
		rc = rc && Core::init();

		Log(Info, "init crypto");
		rc = rc && initCrypto();

		Log(Info, "init opc ua server stack information model (structure)");
		rc = rc && readInformationModel();

		Log(Info, "init opc ua server stack information model (data)");
		rc = rc && initInformationModel();

		Log(Info, "init opc ua server stack service");
		rc = rc && initService();

		Log(Info, "init opc ua server stack session");
		rc = rc && initSession();

		Log(Info, "init application");
		rc = rc && initApplication();

#if 0
		std::vector<std::string> namespaceUris;
		//namespaceUris.push_back("http://yourorganisation.org/Raspberry/");
		namespaceUris.push_back("http://yourorganisation.org/Test-Server/");
		writeInformationModel("NodeSet.xml", namespaceUris);
#endif

		return rc;
	}

	bool
	Server::shutdown(void)
	{
		Log(Info, "shutdown opc ua server stack session");
		shutdownSession();

		Log(Info, "shutdown opc ua server stack service");
		shutdownService();

		Log(Info, "shutdown opc ua server stack information model (data)");
		shutdownInformationModel();

		Log(Info, "shutdown opc ua core stack");
		Core::cleanup();

		return true;
	}

	bool 
	Server::start(void)
	{

		// startup application
		Log(Info, "startup application");
		Component* applicationService = Component::getComponent("ApplicationService");
		applicationManager_.serviceComponent(applicationService);

		if (!applicationManager_.startup()) {
			Log(Error, "server application manager start failed");
			return false;
		}

		// startup opc ua stack
		Log(Info, "start opc ua server stack");
		if (!ioThread_->startup())
		{
			Log(Error, "server io thread start failed");
			return false;
		}
		
		if (!sessionManager_.startup()) {
			Log(Error, "server session manager start failed");
			return false;
		}
	
		return true;
	}
	
	void 
	Server::stop(void)
	{
		// shutdown opc ua stack
		Log(Info, "stop opc ua server stack");
		sessionManager_.shutdown();
		ioThread_->shutdown();

		// shutdown application
		Log(Info, "shutdown application");
		applicationManager_.shutdown();
	}

	ApplicationManager&
	Server::applicationManager(void)
	{
		return applicationManager_;
	}

	ServiceManager&
	Server::serviceManager(void)
	{
		return serviceManager_;
	}

	bool
	Server::writeInformationModel(const std::string& nodeSetFileName, std::vector<std::string>& namespaceUris)
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
	Server::readInformationModel(void)
	{
		std::vector<std::string>::iterator it;
		std::vector<std::string> configVec;
		config().getValues("OpcUaServer.InformationModel.NodeSetFile", configVec);
		if  (configVec.size() == 0) {
			Log(Error, "nodeset file not exist in configuration file")
				.parameter("ConfigurationFileName", config().configFileName())
				.parameter("Path", "OpcUaServer.InformationModel.NodeSetFile");
			return false;
		}

		for (it=configVec.begin(); it!=configVec.end(); it++) {
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

#if 0 // FIXME: Beispiel - Lesen von Namespace Informationen
			NamespaceVec::iterator it;
			NodeSetNamespace& nodeSetNamespace = nodeSetXmlParser.nodeSetNamespace();
			NamespaceVec& namespaceVec = nodeSetNamespace.localNamespaceVec();
			std::cout << "NodeSetFileName=" << nodeSetFileName << std::endl;
			for (it = namespaceVec.begin(); it != namespaceVec.end(); it++) {
				std::cout << "NamespaceUri" << *it << ", NamespaceIndex=" << nodeSetNamespace.mapToGlobalNamespaceIndex(*it) << std::endl;
			}
#endif

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
	// information model
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool
	Server::initInformationModel(void)
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
			OpcUaString::SPtr stringValue = constructSPtr<OpcUaString>();
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
	Server::shutdownInformationModel(void)
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
	Server::initCrypto(void)
	{
		bool rc;

		// decode endpoint configuration
		endpointDescriptionSet_ = constructSPtr<EndpointDescriptionSet>();
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
		applicationCertificate_ = constructSPtr<ApplicationCertificate>();
		applicationCertificate_->uri(serverInfo_.serverUri());
		rc = ApplicationCertificateConfig::parse(
			applicationCertificate_,
			"OpcUaServer.ApplicationCertificate",
			&config(),
			config().configFileName()
		);
		if (!rc) {
			Log(Error, "parse application certificate error");
			return false;
		}
		if (!applicationCertificate_->init()) {
			Log(Error, "init application certificate error");
			return false;
		}

		// create crypto manager
		cryptoManager_ = constructSPtr<CryptoManager>();

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
	Server::initService(void)
	{
		if (!serviceManager_.init(sessionManager_)) {
			Log log(Error, "init service manager error");
			return false;
		}

		if (!serviceManager_.informatinModel(informationModel_)) {
			Log log(Error, "init service manager error");
			return false;
		}

		if (!serviceManager_.ioThread(ioThread_.get())) {
			Log log(Error, "init servcice manager error");
			return false;
		}

		if (!serviceManager_.init()) {
			Log log(Error, "init service manager error");
			return false;
		}
		return true;
	}

	bool
	Server::shutdownService(void)
	{
		serviceManager_.shutdown();
		return true;
	}

	bool
	Server::initSession(void)
	{
		// create discovery service
		DiscoveryService::SPtr discoveryService = serviceManager_.discoveryService();
		discoveryService->endpointDescriptionSet(endpointDescriptionSet_);
		discoveryService->applicationCertificate(applicationCertificate_);

		// initialize session manager
		sessionManager_.ioThread(ioThread_.get());
		sessionManager_.endpointDescriptionSet(endpointDescriptionSet_);
		sessionManager_.applicationCertificate(applicationCertificate_);
		sessionManager_.cryptoManager(cryptoManager_);
		sessionManager_.config(&config());

		return true;
	}

	bool
	Server::shutdownSession(void)
	{
		applicationCertificate_->cleanup();
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
	Server::initApplication(void)
	{
		applicationManager_.applicationCertificate(applicationCertificate_);
		applicationManager_.cryptoManager(cryptoManager_);
		return true;
	}

}
