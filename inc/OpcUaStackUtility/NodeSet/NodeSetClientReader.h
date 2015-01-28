#ifndef __OpcUaStackUtility_NodeSetClientReader_h__
#define __OpcUaStackUtility_NodeSetClientReader_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/ConditionBool.h"
#include "OpcUaStackCore/ServiceSet/ReferenceDescription.h"
#include "OpcUaStackClient/Client/Client.h"
#include "OpcUaStackClient/ServiceSet/SessionIf.h"
#include "OpcUaStackServer/NodeSet/NodeSetBaseParser.h"
#include "OpcUaStackServer/NodeSet/NodeSetNamespace.h"

using namespace OpcUaStackClient;
using namespace OpcUaStackServer;

namespace OpcUaStackUtility
{

	class DLLEXPORT NodeSetClientReader 
	: public NodeSetBaseParser
	, public SessionIf
	{
	  public:
		NodeSetClientReader(void);
		~NodeSetClientReader(void);

		bool readNodes(
			const std::string& sessionConfigPrefix, Config& sessionConfig,
			const std::string& secureChannelConfigPrefix, Config& secureChannelConfig,
			uint32_t operationTimeout = 5000
		);

		NodeSetNamespace& nodeSetNamespace(void);

		//- SessionIf interface -----------------------------------------------
		void error(void);
		void createSessionComplete(OpcUaStatusCode opcUaStatusCode);
		void activateSessionComplete(OpcUaStatusCode opcUaStatusCode);
		//- SessionIf interface -----------------------------------------------

	  private:
		bool checkVariantType(
			OpcUaNodeId& nodeId, 
			const std::string& attributeName, 
			OpcUaVariant::SPtr variant,
			OpcUaBuildInType buildInType
		);
		bool readNamespaceArray(void);
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
		Session::SPtr session_;
		bool error_;

		typedef std::set<OpcUaNodeId> NodeIdSet;
		NodeIdSet nodeIdSet_;
	};

}

#endif