#include "OpcUaStackServer/InformationModel/ServerCapabilitiesType.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackServer
{

	ServerCapabilitiesType::ServerCapabilitiesType(void)
	: ObjectTypeNodeClass()
	{
		// BaseNodeClass
		nodeId().data().set(OpcUaId_ServerCapabilitiesType);
		browseName().data().set("ServerCapabilitiesType");
		displayName().data().set("en", "ServerCapabilitiesType");

		// ObjectTypeNodeClass
		isAbstract().data() = false;

		OpcUaNodeId nodeId;
		nodeId.set(OpcUaId_ServerCapabilitiesType_ServerProfileArray); hasProperty().push_back(nodeId);
		nodeId.set(OpcUaId_ServerCapabilitiesType_LocaleIdArray); hasProperty().push_back(nodeId);
		nodeId.set(OpcUaId_ServerCapabilitiesType_MinSupportedSampleRate); hasProperty().push_back(nodeId);
		nodeId.set(OpcUaId_ServerCapabilitiesType_MaxBrowseContinuationPoints); hasProperty().push_back(nodeId);
		nodeId.set(OpcUaId_ServerCapabilitiesType_MaxQueryContinuationPoints); hasProperty().push_back(nodeId);
		nodeId.set(OpcUaId_ServerCapabilitiesType_MaxHistoryContinuationPoints); hasProperty().push_back(nodeId);
		nodeId.set(OpcUaId_ServerCapabilitiesType_SoftwareCertificates); hasProperty().push_back(nodeId);
		nodeId.set(OpcUaId_ServerCapabilitiesType_ModellingRules); hasComponent().push_back(nodeId);
		nodeId.set(OpcUaId_ServerCapabilitiesType_AggregateFunctions); hasComponent().push_back(nodeId);
		//nodeId.set(); hasComponent().push_back(nodeId);     vendor specific into
	}


	ServerCapabilitiesType::~ServerCapabilitiesType(void)
	{
	}

}