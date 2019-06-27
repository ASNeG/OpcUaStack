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

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef std::set<OpcUaNodeId::SPtr, OpcUaNodeSPtrLess> ReferenceTypeNodeIdSet;

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
		static ReferenceType nodeIdToReferenceType(OpcUaNodeId& nodeId);
		static std::string nodeIdToString(OpcUaNodeId& nodeId);
		static OpcUaNodeId::SPtr stringToNodeId(const std::string& referenceTypeString);

		static OpcUaNodeId::SPtr typeNodeId(ReferenceType referenceType);
		static OpcUaNodeId::SPtr hasPropertyTypeNodeId(void);
		static OpcUaNodeId::SPtr hasComponentTypeNodeId(void);
		static OpcUaNodeId::SPtr hasModellingRuleTypeNodeId(void);
		static OpcUaNodeId::SPtr hasTypeDefinitionTypeNodeId(void);
		static OpcUaNodeId::SPtr hasModelParentTypeNodeId(void);
		static OpcUaNodeId::SPtr hasEventSourceTypeNodeId(void);
		static OpcUaNodeId::SPtr hasNotifierTypeNodeId(void);
		static OpcUaNodeId::SPtr organizesTypeNodeId(void);
		static OpcUaNodeId::SPtr hasDescriptionTypeNodeId(void);
		static OpcUaNodeId::SPtr hasEncodingTypeNodeId(void);
		static OpcUaNodeId::SPtr hasSubtypeTypeNodeId(void);
		static OpcUaNodeId::SPtr nodeIdTypeNodeId(void);
		static OpcUaNodeId::SPtr generateEventsTypeNodeId(void);
		static OpcUaNodeId::SPtr alwaysGeneratesEventTypeNodeId(void);
		static OpcUaNodeId::SPtr hierarchicalReferencesTypeNodeId(void);

	  private:
		static OpcUaNodeId::SPtr hasPropertyTypeNodeId_;
		static OpcUaNodeId::SPtr hasComponentTypeNodeId_;
		static OpcUaNodeId::SPtr hasModellingRuleTypeNodeId_;
		static OpcUaNodeId::SPtr hasTypeDefinitionTypeNodeId_;
		static OpcUaNodeId::SPtr hasModelParentTypeNodeId_;
		static OpcUaNodeId::SPtr hasEventSourceTypeNodeId_;
		static OpcUaNodeId::SPtr hasNotifierTypeNodeId_;
		static OpcUaNodeId::SPtr organizesTypeNodeId_;
		static OpcUaNodeId::SPtr hasDescriptionTypeNodeId_;
		static OpcUaNodeId::SPtr hasEncodingTypeNodeId_;
		static OpcUaNodeId::SPtr hasSubtypeTypeNodeId_;
		static OpcUaNodeId::SPtr nodeIdTypeNodeId_;
		static OpcUaNodeId::SPtr generateEventsTypeNodeId_;
		static OpcUaNodeId::SPtr alwaysGeneratesEventTypeNodeId_;
		static OpcUaNodeId::SPtr hierarchicalReferencesTypeNodeId_;

		static ReferenceTypeNodeIdSet referenceTypeNodeIdSet_;
	};

}

#endif
