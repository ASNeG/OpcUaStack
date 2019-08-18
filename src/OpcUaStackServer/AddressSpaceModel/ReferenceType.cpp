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

#include "OpcUaStackServer/AddressSpaceModel/ReferenceType.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include <boost/algorithm/string/predicate.hpp>

using namespace OpcUaStackCore;

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
	OpcUaNodeId::SPtr ReferenceTypeMap::generateEventsTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::alwaysGeneratesEventTypeNodeId_;
	OpcUaNodeId::SPtr ReferenceTypeMap::hierarchicalReferencesTypeNodeId_;

	ReferenceTypeNodeIdSet ReferenceTypeMap::referenceTypeNodeIdSet_;

	std::string 
	ReferenceTypeMap::typeToString(ReferenceType referenceType)
	{
		switch (referenceType)
		{
			case ReferenceType_Unknown: return "Unknown";
			case ReferenceType_HasComponent: return "HasComponent";
			case ReferenceType_HasProperty: return "HasProperty";
			case ReferenceType_HasModellingRule: return "HasModellingRule";
			case ReferenceType_HasTypeDefinition: return "HasTypeDefinition";
			case ReferenceType_HasModelParent: return "HasModelParent";
			case ReferenceType_HasEventSource: return "HasEventSource";
			case ReferenceType_HasNotifier: return "HasNotifier";
			case ReferenceType_Organizes: return "Organizes";
			case ReferenceType_HasDescription: return "HasDescription";
			case ReferenceType_HasEncoding: return "HasEncoding";
			case ReferenceType_HasSubtype: return "HasSubtype";
			case ReferenceType_GenerateEvents: return "GenerateEvents";
			case ReferenceType_AlwaysGeneratesEvent: return "AlwaysGeneratesEvent";
			case ReferenceType_HierarchicalReferences: return "HierarchicalReferences";
			default: return "Unknown";
		}
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
		else if (referenceTypeString == "GenerateEvents") return ReferenceType_GenerateEvents;
		else if (referenceTypeString == "AlwaysGeneratesEvent") return ReferenceType_AlwaysGeneratesEvent;
		else if (referenceTypeString == "HierarchicalReferences") return ReferenceType_HierarchicalReferences;
		return ReferenceType_Unknown;
	}

	OpcUaNodeId::SPtr
	ReferenceTypeMap::stringToNodeId(const std::string& referenceTypeString)
	{
		// check if type is a standard reference type
		ReferenceType referenceType = stringToType(referenceTypeString);
		if (referenceType != ReferenceType_Unknown) return typeNodeId(referenceType);

		// parse type nodeid 
		OpcUaNodeId::SPtr nodeId = boost::make_shared<OpcUaNodeId>();
		if (!nodeId->fromString(referenceTypeString)) {
			OpcUaNodeId::SPtr nodeIdTmp;
			return nodeIdTmp;
		}

		ReferenceTypeNodeIdSet::iterator it;
		it = referenceTypeNodeIdSet_.find(nodeId);
		if (it != referenceTypeNodeIdSet_.end()) return *it;

		referenceTypeNodeIdSet_.insert(nodeId);
		return nodeId;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::typeNodeId(ReferenceType referenceType)
	{
		switch (referenceType)
		{
			case ReferenceType_HasComponent: return hasComponentTypeNodeId();
			case ReferenceType_HasProperty: return hasPropertyTypeNodeId();
			case ReferenceType_HasModellingRule: return hasModellingRuleTypeNodeId();
			case ReferenceType_HasTypeDefinition: return hasTypeDefinitionTypeNodeId();
			case ReferenceType_HasModelParent: return hasModelParentTypeNodeId();
			case ReferenceType_HasEventSource: return hasEventSourceTypeNodeId();
			case ReferenceType_HasNotifier: return hasNotifierTypeNodeId();
			case ReferenceType_Organizes: return organizesTypeNodeId();
			case ReferenceType_HasDescription: return hasDescriptionTypeNodeId();
			case ReferenceType_HasEncoding: return hasEncodingTypeNodeId();
			case ReferenceType_HasSubtype: return hasSubtypeTypeNodeId();
			case ReferenceType_GenerateEvents: return generateEventsTypeNodeId();
			case ReferenceType_AlwaysGeneratesEvent: return alwaysGeneratesEventTypeNodeId();
			case ReferenceType_HierarchicalReferences: return hierarchicalReferencesTypeNodeId();
			default:
			{
				OpcUaNodeId::SPtr nodeId;
				return nodeId;
			}
		}
	}

	ReferenceType 
	ReferenceTypeMap::nodeIdToReferenceType(OpcUaNodeId& nodeId)
	{
		if (nodeId.namespaceIndex() != 0) return ReferenceType_Unknown;
		if (nodeId.nodeIdType() != OpcUaBuildInType_OpcUaUInt32) return ReferenceType_Unknown;
		switch (nodeId.nodeId<OpcUaUInt32>())
		{
			case OpcUaId_HasProperty: return ReferenceType_HasProperty;
			case OpcUaId_HasComponent: return ReferenceType_HasComponent;
			case OpcUaId_HasModellingRule: return ReferenceType_HasModellingRule;
			case OpcUaId_HasTypeDefinition: return ReferenceType_HasTypeDefinition;
			case OpcUaId_HasModelParent: return ReferenceType_HasModelParent;
			case OpcUaId_HasEventSource: return ReferenceType_HasEventSource;
			case OpcUaId_HasNotifier: return ReferenceType_HasNotifier;
			case OpcUaId_Organizes: return ReferenceType_Organizes;
			case OpcUaId_HasDescription: return ReferenceType_HasDescription;
			case OpcUaId_HasEncoding: return ReferenceType_HasEncoding;
			case OpcUaId_HasSubtype: return ReferenceType_HasSubtype;
			case OpcUaId_GeneratesEvent: return ReferenceType_GenerateEvents;
			case OpcUaId_AlwaysGeneratesEvent: return ReferenceType_AlwaysGeneratesEvent;
			case OpcUaId_HierarchicalReferences: return ReferenceType_HierarchicalReferences;
			default: return ReferenceType_Unknown;
		}
	}

	std::string 
	ReferenceTypeMap::nodeIdToString(OpcUaNodeId& nodeId)
	{
		ReferenceType referenceType = nodeIdToReferenceType(nodeId);
		if (referenceType != ReferenceType_Unknown) {
			return typeToString(referenceType);
		}
		return nodeId.toString();
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasPropertyTypeNodeId(void)
	{
		if (hasPropertyTypeNodeId_.get() == nullptr) {
			hasPropertyTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			hasPropertyTypeNodeId_->nodeId(OpcUaId_HasProperty);
		}
		return hasPropertyTypeNodeId_;
	}

	OpcUaNodeId::SPtr
	ReferenceTypeMap::hasComponentTypeNodeId(void)
	{
		if (hasComponentTypeNodeId_.get() == nullptr) {
			hasComponentTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			hasComponentTypeNodeId_->nodeId(OpcUaId_HasComponent);
		}
		return hasComponentTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasModellingRuleTypeNodeId(void)
	{
		if (hasModellingRuleTypeNodeId_.get() == nullptr) {
			hasModellingRuleTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			hasModellingRuleTypeNodeId_->nodeId(OpcUaId_HasModellingRule);
		}
		return hasModellingRuleTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasTypeDefinitionTypeNodeId(void)
	{
		if (hasTypeDefinitionTypeNodeId_.get() == nullptr) {
			hasTypeDefinitionTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			hasTypeDefinitionTypeNodeId_->nodeId(OpcUaId_HasTypeDefinition);
		}
		return hasTypeDefinitionTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasModelParentTypeNodeId(void)
	{
		if (hasModelParentTypeNodeId_.get() == nullptr) {
			hasModelParentTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			hasModelParentTypeNodeId_->nodeId(OpcUaId_HasModelParent); 
		}
		return hasModelParentTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasEventSourceTypeNodeId(void)
	{
		if (hasEventSourceTypeNodeId_.get() == nullptr) {
			hasEventSourceTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			hasEventSourceTypeNodeId_->nodeId(OpcUaId_HasEventSource);
		}
		return hasEventSourceTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasNotifierTypeNodeId(void)
	{
		if (hasNotifierTypeNodeId_.get() == nullptr) {
			hasNotifierTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			hasNotifierTypeNodeId_->nodeId(OpcUaId_HasNotifier);
		}
		return hasNotifierTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::organizesTypeNodeId(void)
	{
		if (organizesTypeNodeId_.get() == nullptr) {
			organizesTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			organizesTypeNodeId_->nodeId(OpcUaId_Organizes);
		}
		return organizesTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasDescriptionTypeNodeId(void)
	{
		if (hasDescriptionTypeNodeId_.get() == nullptr) {
			hasDescriptionTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			hasDescriptionTypeNodeId_->nodeId(OpcUaId_HasDescription);
		}
		return hasDescriptionTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasEncodingTypeNodeId(void)
	{
		if (hasEncodingTypeNodeId_.get() == nullptr) {
			hasEncodingTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			hasEncodingTypeNodeId_->nodeId(OpcUaId_HasEncoding);
		}
		return hasEncodingTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hasSubtypeTypeNodeId(void)
	{
		if (hasSubtypeTypeNodeId_.get() == nullptr) {
			hasSubtypeTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			hasSubtypeTypeNodeId_->nodeId(OpcUaId_HasSubtype);
		}
		return hasSubtypeTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::nodeIdTypeNodeId(void)
	{
		if (nodeIdTypeNodeId_.get() == nullptr) {
			nodeIdTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			nodeIdTypeNodeId_->nodeId(OpcUaId_NodeId);
		}
		return nodeIdTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::generateEventsTypeNodeId(void)
	{
		if (generateEventsTypeNodeId_.get() == nullptr) {
			generateEventsTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			generateEventsTypeNodeId_->nodeId(OpcUaId_GeneratesEvent);
		}
		return generateEventsTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::alwaysGeneratesEventTypeNodeId(void)
	{
		if (alwaysGeneratesEventTypeNodeId_.get() == nullptr) {
			alwaysGeneratesEventTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			alwaysGeneratesEventTypeNodeId_->nodeId(OpcUaId_AlwaysGeneratesEvent);
		}
		return alwaysGeneratesEventTypeNodeId_;
	}

	OpcUaNodeId::SPtr 
	ReferenceTypeMap::hierarchicalReferencesTypeNodeId(void)
	{
		if (hierarchicalReferencesTypeNodeId_.get() == nullptr) {
			hierarchicalReferencesTypeNodeId_ = boost::make_shared<OpcUaNodeId>();
			hierarchicalReferencesTypeNodeId_->nodeId(OpcUaId_HierarchicalReferences);
		}
		return hierarchicalReferencesTypeNodeId_;
	}

}
