#include "OpcUaStackServer/AddressSpaceModel/ReferenceType.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include <boost/algorithm/string/predicate.hpp>

namespace OpcUaStackServer
{

	OpcUaNodeId::SPtr ReferenceTypeMap::hasPropertyTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::hasComponentTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::hasModellingRuleTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::hasTypeDefinitionTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::hasModelParentTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::hasEventSourceTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::hasNotifierTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::organizesTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::hasDescriptionTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::hasEncodingTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::hasSubtypeTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::nodeIdTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::hasModelParameterTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::generateEventsTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::alwaysGeneratesEventTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::hierarchicalReferencesTypeNodeId_;

	std::string 
	ReferenceTypeMap::typeToString(ReferenceType referenceType)
	{
		switch (referenceType)
		{
			case ReferenceType_Unknown:
				return "Unknown";
			case ReferenceType_HasComponent:
				return "HasComponent";
			case ReferenceType_HasProperty:
				return "HasProperty";
			case ReferenceType_HasModellingRule:
				return "HasModellingRule";
			case ReferenceType_HasTypeDefinition:
				return "HasTypeDefinition";
			case ReferenceType_HasModelParent:
				return "HasModelParent";
			case ReferenceType_HasEventSource:
				return "HasEventSource";
			case ReferenceType_HasNotifier:
				return "HasNotifier";
			case ReferenceType_Organizes:
				return "Organizes";
			case ReferenceType_HasDescription:
				return "HasDescription";
			case ReferenceType_HasEncoding:
				return "HasEncoding";
			case ReferenceType_HasSubtype:
				return "HasSubtype";
			case ReferenceType_HasModelParameter:
				return "HasModelParameter";
			case ReferenceType_GenerateEvents:
				return "GenerateEvents";
			case ReferenceType_AlwaysGeneratesEvent:
				return "AlwaysGeneratesEvent";
			case ReferenceType_HierarchicalReferences:
				return "HierarchicalReferences";
		}
		return "Unknown";
	}

	ReferenceType 
	ReferenceTypeMap::stringToType(std::string referenceTypeString)
	{
		if (referenceTypeString == "HasComponent") return ReferenceType_HasComponent;
		else if (referenceTypeString == "HasProperty") return ReferenceType_HasProperty;
		else if (referenceTypeString == "HasModellingRule") return ReferenceType_HasModellingRule;
		else if (referenceTypeString == "HasTypeDefinition") return ReferenceType_HasTypeDefinition;
		else if (referenceTypeString == "HasModelParent") return ReferenceType_HasModelParent;
		else if (referenceTypeString == "HasEventSource") return ReferenceType_HasEventSource;
		else if (referenceTypeString == "HasNotifier") return ReferenceType_HasNotifier;
		else if (referenceTypeString == "Organizes") return ReferenceType_Organizes;
		else if (referenceTypeString == "HasDescription") return ReferenceType_HasDescription;
		else if (referenceTypeString == "HasEncoding") return ReferenceType_HasEncoding;
		else if (referenceTypeString == "HasSubtype") return ReferenceType_HasSubtype;
		else if (boost::contains(referenceTypeString, "i=")) return ReferenceType_NodeId;
		else if (referenceTypeString == "hasModelParameter") ReferenceType_HasModelParameter;
		else if (referenceTypeString == "generateEvents") ReferenceType_GenerateEvents;
		else if (referenceTypeString == "alwaysGeneratesEvent") ReferenceType_AlwaysGeneratesEvent;
		else if (referenceTypeString == "hierarchicalReferences") ReferenceType_HierarchicalReferences;
		return ReferenceType_Unknown;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasPropertyTypeNodeId(void)
	{
		if (hasPropertyTypeNodeId_.get() == nullptr) {
			hasPropertyTypeNodeId_ = OpcUaNodeId::construct();
			hasPropertyTypeNodeId_->nodeId(OpcUaId_HasProperty);
		}
		return hasPropertyTypeNodeId_;
	}

	OpcUaNodeId::SPtr
	ReferenceTypeMap::hasComponentTypeNodeId(void)
	{
		if (hasComponentTypeNodeId_.get() == nullptr) {
			hasComponentTypeNodeId_ = OpcUaNodeId::construct();
			hasComponentTypeNodeId_->nodeId(OpcUaId_HasComponent);
		}
		return hasComponentTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasModellingRuleTypeNodeId(void)
	{
		if (hasModellingRuleTypeNodeId_.get() == nullptr) {
			hasModellingRuleTypeNodeId_ = OpcUaNodeId::construct();
			hasModellingRuleTypeNodeId_->nodeId(OpcUaId_HasModellingRule);
		}
		return hasModellingRuleTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasTypeDefinitionTypeNodeId(void)
	{
		if (hasTypeDefinitionTypeNodeId_.get() == nullptr) {
			hasTypeDefinitionTypeNodeId_ = OpcUaNodeId::construct();
			hasTypeDefinitionTypeNodeId_->nodeId(OpcUaId_HasTypeDefinition);
		}
		return hasTypeDefinitionTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasModelParentTypeNodeId(void)
	{
		if (hasModelParentTypeNodeId_.get() == nullptr) {
			hasModelParentTypeNodeId_ = OpcUaNodeId::construct();
			hasModelParentTypeNodeId_->nodeId(4711); // FIXME: this is not right...
		}
		return hasModelParentTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasEventSourceTypeNodeId(void)
	{
		if (hasEventSourceTypeNodeId_.get() == nullptr) {
			hasEventSourceTypeNodeId_ = OpcUaNodeId::construct();
			hasEventSourceTypeNodeId_->nodeId(OpcUaId_HasEventSource);
		}
		return hasEventSourceTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasNotifierTypeNodeId(void)
	{
		if (hasNotifierTypeNodeId_.get() == nullptr) {
			hasNotifierTypeNodeId_ = OpcUaNodeId::construct();
			hasNotifierTypeNodeId_->nodeId(OpcUaId_HasNotifier);
		}
		return hasNotifierTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::organizesTypeNodeId(void)
	{
		if (organizesTypeNodeId_.get() == nullptr) {
			organizesTypeNodeId_ = OpcUaNodeId::construct();
			organizesTypeNodeId_->nodeId(OpcUaId_Organizes);
		}
		return organizesTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasDescriptionTypeNodeId(void)
	{
		if (hasDescriptionTypeNodeId_.get() == nullptr) {
			hasDescriptionTypeNodeId_ = OpcUaNodeId::construct();
			hasDescriptionTypeNodeId_->nodeId(OpcUaId_HasDescription);
		}
		return hasDescriptionTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasEncodingTypeNodeId(void)
	{
		if (hasEncodingTypeNodeId_.get() == nullptr) {
			hasEncodingTypeNodeId_ = OpcUaNodeId::construct();
			hasEncodingTypeNodeId_->nodeId(OpcUaId_HasEncoding);
		}
		return hasEncodingTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasSubtypeTypeNodeId(void)
	{
		if (hasSubtypeTypeNodeId_.get() == nullptr) {
			hasSubtypeTypeNodeId_ = OpcUaNodeId::construct();
			hasSubtypeTypeNodeId_->nodeId(OpcUaId_HasSubtype);
		}
		return hasSubtypeTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::nodeIdTypeNodeId(void)
	{
		if (nodeIdTypeNodeId_.get() == nullptr) {
			nodeIdTypeNodeId_ = OpcUaNodeId::construct();
			nodeIdTypeNodeId_->nodeId(OpcUaId_NodeId);
		}
		return nodeIdTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasModelParameterTypeNodeId(void)
	{
		if (hasModelParameterTypeNodeId_.get() == nullptr) {
			hasModelParameterTypeNodeId_ = OpcUaNodeId::construct();
			hasModelParameterTypeNodeId_->nodeId(4711);  // FIXME: this ist not right ...
		}
		return hasModelParameterTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::generateEventsTypeNodeId(void)
	{
		if (generateEventsTypeNodeId_.get() == nullptr) {
			generateEventsTypeNodeId_ = OpcUaNodeId::construct();
			generateEventsTypeNodeId_->nodeId(OpcUaId_GeneratesEvent);
		}
		return generateEventsTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::alwaysGeneratesEventTypeNodeId(void)
	{
		if (alwaysGeneratesEventTypeNodeId_.get() == nullptr) {
			alwaysGeneratesEventTypeNodeId_ = OpcUaNodeId::construct();
			alwaysGeneratesEventTypeNodeId_->nodeId(OpcUaId_AlwaysGeneratesEvent);
		}
		return generateEventsTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hierarchicalReferencesTypeNodeId(void)
	{
		if (hierarchicalReferencesTypeNodeId_.get() == nullptr) {
			hierarchicalReferencesTypeNodeId_ = OpcUaNodeId::construct();
			hierarchicalReferencesTypeNodeId_->nodeId(OpcUaId_HierarchicalReferences);
		}
		return hierarchicalReferencesTypeNodeId_;
	}

}
