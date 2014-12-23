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
		rc = rc && setInformationModel();

		Log(Info, "init opc ua server stack service");
		rc = rc && initService();

		Log(Info, "init opc ua server stack session");
		rc = rc && initSession();

#if 0
		writeInformationModel("NodeSet.xml");
#endif

		return rc;
	}

	void
	Server::cleanup(void)
	{
		Core::cleanup();
	}

	bool 
	Server::start(void)
	{
		Log(Info, "start opc ua server stack");

		ioService_.start();
		sessionManager_.openServerSocket(
			"OpcUaServer.Endpoints.EndpointDescription", config(),
			"OpcUaServer.Endpoints.EndpointDescription", config()
		);
	
		IOService::secSleep(40000);

		ioService_.stop();
		return true;
	}
	
	void 
	Server::stop(void)
	{
	}

	bool
	Server::writeInformationModel(const std::string& nodeSetFileName)
	{
		NodeSetXmlParser nodeSetXmlParser;

		if (!InformationModelNodeSet::initial(nodeSetXmlParser, informationModel_)) {
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

	bool
	Server::setInformationModel(void)
	{
		// add namespaces to namespace array
		{
			NodeSetNamespace nodeSetNamespace;
			NamespaceArray namespaceArray;
			namespaceArray.informationModel(informationModel_);
			namespaceArray.addNamespaceNames(nodeSetNamespace.globalNamespaceVec());
		}

		// set server status
		{ 
			OpcUaDataValue dataValue;
			dataValue.variant()->variant((OpcUaUInt32)0);
			dataValue.statusCode(Success);
			dataValue.sourceTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
			dataValue.serverTimestamp().dateTime(boost::posix_time::microsec_clock::local_time());
			bool rc = informationModel_->setValue(OpcUaId_Server_ServerStatus_State, AttributeId_Value, dataValue);
		}

		return true;
	}

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

}