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

	bool
	Server::init(void)
	{
		if (!Core::init()) return false;
		if (!initInformationModel()) return false;
		if (!setInformationModel()) return false;
		if (!initService()) return false;
		if (!initSession()) return false;
		return true;
	}

	void
	Server::cleanup(void)
	{
		Core::cleanup();
	}

	void 
	Server::start(void)
	{
		ioService_.start();
		sessionManager_.openServerSocket(
			"OpcUaServer/Endpoints", config(),
			"OpcUaServer/Endpoints", config()
		);
	
		IOService::secSleep(40000);

		ioService_.stop();
	}
	
	void 
	Server::stop(void)
	{
	}

	bool 
	Server::initInformationModel(void)
	{
		std::vector<std::string>::iterator it;
		std::vector<std::string> configVec;
		config().getValues("OpcUaServer/InformationModel/NodeSetFile", configVec);
		if  (configVec.size()) {
			Log(Error, "nodeset file not exist in configuration file")
				.parameter("ConfigurationFileName", config().configFileName())
				.parameter("Path", "OpcUaServer/InformationModel/NodeSetFile");
			return false;
		}

		for (it=configVec.begin(); it!=configVec.end(); it++) {
			std::string nodeSetFileName = *it;

			ConfigXml configXml;
			if (!configXml.parse(nodeSetFileName)) {
				Log(Error, "node set file error")
					.parameter("NodeSetFileName", nodeSetFileName);
				return false;
			}

			NodeSetXmlParser nodeSetXmlParser;
			if (!nodeSetXmlParser.decode(configXml.ptree())) {
				Log(Error, "node set parser error")
					.parameter("NodeSetFileName", nodeSetFileName);
				return false;
			}

			if (!InformationModelNodeSet::initial(informationModel_, nodeSetXmlParser)) {
				Log(Error, "node set initialisation error")
					.parameter("NodeSetFileName", nodeSetFileName);
				return false;
			}
		}

		return true;
	}

	bool
	Server::setInformationModel(void)
	{
		// FIXME: todo
		OpcUaString::SPtr stringValue;

		{ // set NamespaceArray	
			OpcUaVariant variant;
		
			stringValue = OpcUaString::construct();
			*stringValue = "http://opcfoundation.org/UA/";
			variant.variant(0, stringValue);
		
			variant.arrayLength(1);
			informationModel_->setValue(OpcUaId_Server_NamespaceArray, AttributeId_Value, variant);
		}

		{ // ServerStatus
			OpcUaVariant variant;
			variant.variant((OpcUaUInt32)0);
			informationModel_->setValue(OpcUaId_Server_ServerStatus_State, AttributeId_Value, variant);
		}

		return false;
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
		return false;
	}

	bool
	Server::initSession(void)
	{
		EndpointDescriptionArray::SPtr endpointDescriptionArray = EndpointDescriptionArray::construct();
		bool rc = EndpointDescriptionConfig::endpointDescriptions(
			endpointDescriptionArray, 
			"OpcUaServer/Endpoints", 
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

		return false;
	}

}