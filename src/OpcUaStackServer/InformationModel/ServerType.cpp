#include "OpcUaStackServer/InformationModel/ServerType.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackServer
{

	ServerType::ServerType(void)
	: ObjectTypeNodeClass()
	{
		// BaseNodeClass
		nodeId().data().set(OpcUaId_ServerType);
		browseName().data().set("ServerType");
		displayName().data().set("en", "ServerType");

		// ObjectTypeNodeClass
		isAbstract().data() = false;

		OpcUaNodeId nodeId;
		nodeId.set(OpcUaId_Server_ServerArray); hasProperty().push_back(nodeId);
		nodeId.set(OpcUaId_Server_NamespaceArray); hasProperty().push_back(nodeId);
		nodeId.set(OpcUaId_Server_ServiceLevel); hasProperty().push_back(nodeId);
		nodeId.set(OpcUaId_Server_Auditing); hasProperty().push_back(nodeId);
		nodeId.set(OpcUaId_Server_ServerStatus); hasComponent().push_back(nodeId);
		nodeId.set(OpcUaId_Server_ServerCapabilities); hasComponent().push_back(nodeId);
		nodeId.set(OpcUaId_Server_ServerDiagnostics); hasComponent().push_back(nodeId);
		nodeId.set(OpcUaId_Server_VendorServerInfo); hasComponent().push_back(nodeId);
		nodeId.set(OpcUaId_Server_ServerRedundancy); hasComponent().push_back(nodeId);
	}


	ServerType::~ServerType(void)
	{
	}

}