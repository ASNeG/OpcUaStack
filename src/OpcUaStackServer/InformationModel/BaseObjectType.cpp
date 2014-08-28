#include "OpcUaStackServer/InformationModel/BaseObjectType.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackServer
{

	BaseObjectType::BaseObjectType(void)
	: ObjectTypeNodeClass()
	{
		// BaseNodeClass
		nodeId().data().set(OpcUaId_BaseObjectType);
		browseName().data().set("BaseObjectType");
		displayName().data().set("en", "BaseObjectType");

		// ObjectTypeNodeClass
		isAbstract().data() = false;

		OpcUaNodeId nodeId;
		nodeId.set(OpcUaId_ServerType); hasSubtypes().push_back(nodeId);
		nodeId.set(OpcUaId_ServerCapabilitiesType); hasSubtypes().push_back(nodeId);
		nodeId.set(OpcUaId_ServerDiagnosticsType); hasSubtypes().push_back(nodeId);
		nodeId.set(OpcUaId_SessionsDiagnosticsSummaryType); hasSubtypes().push_back(nodeId);
		nodeId.set(OpcUaId_SessionDiagnosticsObjectType); hasSubtypes().push_back(nodeId);
		nodeId.set(OpcUaId_VendorServerInfoType); hasSubtypes().push_back(nodeId);
		nodeId.set(OpcUaId_ServerRedundancyType); hasSubtypes().push_back(nodeId);
		nodeId.set(OpcUaId_BaseEventType); hasSubtypes().push_back(nodeId);
		nodeId.set(OpcUaId_ModellingRuleType); hasSubtypes().push_back(nodeId);
		nodeId.set(OpcUaId_FolderType); hasSubtypes().push_back(nodeId);
		nodeId.set(OpcUaId_DataTypeEncodingType); hasSubtypes().push_back(nodeId);
		nodeId.set(OpcUaId_DataTypeSystemType); hasSubtypes().push_back(nodeId);
	}


	BaseObjectType::~BaseObjectType(void)
	{
	}

}