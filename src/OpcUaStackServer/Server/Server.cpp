/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
	, informationModel_(InformationModel::construct())
	, sessionManager_()
	, serviceManager_()
	, applicationManager_()
	, serverStatusDataType_()
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

	IOService*
	Server::ioService(void)
	{
		return &ioService_;
	}

	bool
	Server::init(void)
	{
		bool rc = true;

		Log(Info, "init opc ua core stack");
		rc = rc && Core::init();

		Log(Info, "init opc ua server stack information model (structure)");
		rc = rc && readInformationModel();

		Log(Info, "init opc ua server stack information model (data)");
		rc = rc && initInformationModel();

		Log(Info, "init opc ua server stack service");
		rc = rc && initService();

		Log(Info, "init opc ua server stack session");
		rc = rc && initSession();

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
		Log(Info, "start application");
		Component* applicationService = Component::getComponent("ApplicationService");
		applicationManager_.serviceComponent(applicationService);

		if (!applicationManager_.startup()) {
			return false;
		}

		// startup opc ua stack
		Log(Info, "start opc ua server stack");
		ioService_.start();
		sessionManager_.openServerSocket(
			"OpcUaServer.Endpoints.EndpointDescription", config(),
			"OpcUaServer.Endpoints.EndpointDescription", config()
		);
	
		return true;
	}
	
	void 
	Server::stop(void)
	{
		// shutdown opc ua stack
		Log(Info, "stop opc ua server stack");
		sessionManager_.closeServerSocket();
		ioService_.stop();

		// shutdown application
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
			Log(Error, "node set file error")
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
				Log(Error, "node set file error")
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
			OpcUaString::SPtr stringValue = OpcUaString::construct();
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

		if (!serviceManager_.ioService(&ioService_)) {
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
		EndpointDescriptionArray::SPtr endpointDescriptionArray = EndpointDescriptionArray::construct();
		bool rc = EndpointDescriptionConfig::endpointDescriptions(
			endpointDescriptionArray, 
			"OpcUaServer.Endpoints", 
			&config(),
			config().configFileName()
		);
		if (!rc) {
			Log(Error, "endpoint description array error");
			return false;
		}

		DiscoveryService::SPtr discoveryService = DiscoveryService::construct();
		discoveryService->endpointDescriptionArray(endpointDescriptionArray);
		sessionManager_.discoveryService(discoveryService);
		sessionManager_.ioService(&ioService_);

		return true;
	}

	bool
	Server::shutdownSession(void)
	{
		// FIXME: todo
		return true;
	}

}
