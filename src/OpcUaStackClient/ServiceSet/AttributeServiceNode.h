/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_AttributeServiceNode_h__
#define __OpcUaStackClient_AttributeServiceNode_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h"
#include "OpcUaStackCore/StandardDataTypes/NodeClass.h"
#include "OpcUaStackClient/ServiceSet/AttributeService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT AttributeServiceNodeIf
	{
	  public:
		AttributeServiceNodeIf(void) {}
		virtual ~AttributeServiceNodeIf(void) {}

		virtual void attributeServiceNodeDone(OpcUaStatusCode statusCode) = 0;
		virtual void attributeServiceNodeResult(AttributeId attributeId, OpcUaDataValue::SPtr& dataValue) = 0;
	};


	class DLLEXPORT AttributeServiceNode
	{
	  public:
		typedef boost::shared_ptr<AttributeServiceNode> SPtr;

		AttributeServiceNode(void);
		~AttributeServiceNode(void);

		void attributeService(AttributeService::SPtr& attributeService);
		void attributeServiceNodeIf(AttributeServiceNodeIf* attributeServiceNodeIf);
		void nodeId(OpcUaNodeId& nodeId);
		void attributeIds(
			const AttributeId& attributeId1
		);
		void attributeIds(
			const AttributeId& attributeId1,
			const AttributeId& attributeId2
		);
		void attributeIds(
			const AttributeId& attributeId1,
			const AttributeId& attributeId2,
			const AttributeId& attributeId3
		);
		void attributeIds(
			const AttributeId& attributeId1,
			const AttributeId& attributeId2,
			const AttributeId& attributeId3,
			const AttributeId& attributeId4
		);
		void attributeIds(
			const AttributeId& attributeId1,
			const AttributeId& attributeId2,
			const AttributeId& attributeId3,
			const AttributeId& attributeId4,
			const AttributeId& attributeId5
		);
		void attributeIds(NodeClass::Enum nodeClassType);

		void asyncReadNode(void);

	  private:
		void attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead);

		AttributeService::SPtr attributeService_;
		AttributeServiceNodeIf* attributeServiceNodeIf_;

		OpcUaNodeId nodeId_;
		std::vector<AttributeId> attributeIdVec_;

	};

}

#endif
