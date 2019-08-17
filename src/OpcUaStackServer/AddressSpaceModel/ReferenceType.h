/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_ReferenceType_h__
#define __OpcUaStackServer_ReferenceType_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include <string>
#include <set>

namespace OpcUaStackServer
{

	typedef std::set<OpcUaStackCore::OpcUaNodeId::SPtr, OpcUaStackCore::OpcUaNodeSPtrLess> ReferenceTypeNodeIdSet;

	typedef enum {
		ReferenceType_Unknown,
		ReferenceType_HasComponent,
		ReferenceType_HasProperty,
		ReferenceType_HasModellingRule,
		ReferenceType_HasTypeDefinition,
		ReferenceType_HasModelParent,
		ReferenceType_HasEventSource,
		ReferenceType_HasNotifier,
		ReferenceType_Organizes,
		ReferenceType_HasDescription,
		ReferenceType_HasEncoding,
		ReferenceType_HasSubtype,
		ReferenceType_NodeId,
		ReferenceType_GenerateEvents,
		ReferenceType_AlwaysGeneratesEvent,
		ReferenceType_HierarchicalReferences
	} ReferenceType;

	class DLLEXPORT ReferenceTypeMap
	{
	  public:
		static std::string typeToString(ReferenceType referenceType);
		static ReferenceType stringToType(std::string referenceTypeString);
		static ReferenceType nodeIdToReferenceType(OpcUaStackCore::OpcUaNodeId& nodeId);
		static std::string nodeIdToString(OpcUaStackCore::OpcUaNodeId& nodeId);
		static OpcUaStackCore::OpcUaNodeId::SPtr stringToNodeId(const std::string& referenceTypeString);

		static OpcUaStackCore::OpcUaNodeId::SPtr typeNodeId(ReferenceType referenceType);
		static OpcUaStackCore::OpcUaNodeId::SPtr hasPropertyTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr hasComponentTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr hasModellingRuleTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr hasTypeDefinitionTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr hasModelParentTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr hasEventSourceTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr hasNotifierTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr organizesTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr hasDescriptionTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr hasEncodingTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr hasSubtypeTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr nodeIdTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr generateEventsTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr alwaysGeneratesEventTypeNodeId(void);
		static OpcUaStackCore::OpcUaNodeId::SPtr hierarchicalReferencesTypeNodeId(void);

	  private:
		static OpcUaStackCore::OpcUaNodeId::SPtr hasPropertyTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr hasComponentTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr hasModellingRuleTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr hasTypeDefinitionTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr hasModelParentTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr hasEventSourceTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr hasNotifierTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr organizesTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr hasDescriptionTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr hasEncodingTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr hasSubtypeTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr nodeIdTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr generateEventsTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr alwaysGeneratesEventTypeNodeId_;
		static OpcUaStackCore::OpcUaNodeId::SPtr hierarchicalReferencesTypeNodeId_;

		static ReferenceTypeNodeIdSet referenceTypeNodeIdSet_;
	};

}

#endif
