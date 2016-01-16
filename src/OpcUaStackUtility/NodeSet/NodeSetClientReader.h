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

#ifndef __OpcUaStackUtility_NodeSetClientReader_h__
#define __OpcUaStackUtility_NodeSetClientReader_h__

#if 0
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ConditionBool.h"
#include "OpcUaStackCore/ServiceSet/ReferenceDescription.h"
#include "OpcUaStackClient/Client/Client.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceIf.h"
#include "OpcUaStackServer/NodeSet/NodeSetBaseParser.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

using namespace OpcUaStackClient;
using namespace OpcUaStackServer;

namespace OpcUaStackUtility
{

	class DLLEXPORT NodeSetClientReader 
	: public NodeSetBaseParser
	, public SessionServiceIf
	{
	  public:
		NodeSetClientReader(void);
		virtual ~NodeSetClientReader(void);


		bool readNodes(
			const std::string& sessionConfigPrefix, Config& sessionConfig,
			const std::string& secureChannelConfigPrefix, Config& secureChannelConfig,
			OpcUaNodeId& nodeId,
			uint32_t operationTimeout = 120000
		);
		bool readNodes(
			const std::string& sessionConfigPrefix, Config& sessionConfig,
			const std::string& secureChannelConfigPrefix, Config& secureChannelConfig,
			uint32_t operationTimeout = 120000
		);

		NodeSetNamespace& nodeSetNamespace(void);

		//- SessionIf interface -----------------------------------------------
		void sessionStateUpdate(SessionBase& session, SessionState sessionState);
		//- SessionIf interface -----------------------------------------------

	  private:
		bool checkVariantType(
			OpcUaNodeId& nodeId, 
			const std::string& attributeName, 
			OpcUaVariant::SPtr variant,
			OpcUaBuildInType buildInType
		);
		bool readNamespaceArray(void);
		bool browse(
			OpcUaNodeId& nodeId,
			ReferenceDescription::SPtr referenceDescription,
			OpcUaByteString::SPtr continuationPoint
		);
		bool browse(OpcUaNodeId& nodeId);
		bool browse(
			std::vector<OpcUaNodeId>& nodeIdVec, 
			ReferenceDescription::Vec& referenceDescriptionVec
		);
		bool createNode(
			OpcUaNodeId& nodeId, 
			ReferenceDescription::SPtr nodeReferenceDescription, 
			ReferenceDescription::Vec& referenceDescriptionVec
		);
		bool readAttributes(
			OpcUaNodeId nodeId, 
			std::vector<AttributeId>& attributeIdVec, 
			std::vector<OpcUaDataValue::SPtr>& dataValueVec
		);
		bool readNodeBase(
			OpcUaNodeId& nodeId, 
			BaseNodeClass::SPtr baseNodeClass, 
			ReferenceDescription::SPtr referenceDescription, 
			std::vector<OpcUaDataValue::SPtr>& dataValueVec
		);
		bool addReferences(
			BaseNodeClass::SPtr baseNodeClass,
			ReferenceDescription::Vec& referenceDescriptionVec
		);
		bool readObject(
			OpcUaNodeId& nodeId, 
			ReferenceDescription::SPtr nodeReferenceDescription,
			ReferenceDescription::Vec& referenceDescriptionVec
		);
		bool readVariable(
			OpcUaNodeId& nodeId, 
			ReferenceDescription::SPtr nodeReferenceDescription,
			ReferenceDescription::Vec& referenceDescriptionVec
		);
		bool readMethod(
			OpcUaNodeId& nodeId, 
			ReferenceDescription::SPtr nodeReferenceDescription,
			ReferenceDescription::Vec& referenceDescriptionVec
		);
		bool readObjectType(
			OpcUaNodeId& nodeId, 
			ReferenceDescription::SPtr nodeReferenceDescription,
			ReferenceDescription::Vec& referenceDescriptionVec
		);
		bool readVariableType(
			OpcUaNodeId& nodeId, 
			ReferenceDescription::SPtr nodeReferenceDescription,
			ReferenceDescription::Vec& referenceDescriptionVec
		);
		bool readReferenceType(
			OpcUaNodeId& nodeId, 
			ReferenceDescription::SPtr nodeReferenceDescription,
			ReferenceDescription::Vec& referenceDescriptionVec
		);
		bool readDataType(
			OpcUaNodeId& nodeId, 
			ReferenceDescription::SPtr nodeReferenceDescription,
			ReferenceDescription::Vec& referenceDescriptionVec
		);
		bool readView(
			OpcUaNodeId& nodeId, 
			ReferenceDescription::SPtr nodeReferenceDescription,
			ReferenceDescription::Vec& referenceDescriptionVec
		);
	
		Client client_;
		NodeSetNamespace nodeSetNamespace_;
		ConditionBool condition_;
		
		uint32_t operationTimeout_;
		SessionOld::SPtr session_;
		bool error_;

		typedef std::set<OpcUaNodeId> NodeIdSet;
		NodeIdSet nodeIdSet_;
	};

}
#endif

#endif
