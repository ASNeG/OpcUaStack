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

namespace OpcUaStackClient
{

	class DLLEXPORT AttributeServiceNodeIf
	{
	  public:
		AttributeServiceNodeIf(void) {}
		virtual ~AttributeServiceNodeIf(void) {}

		virtual void attributeServiceNodeDone(OpcUaStackCore::OpcUaStatusCode statusCode) = 0;
		virtual void attributeServiceNodeResult(OpcUaStackCore::AttributeId attributeId, OpcUaStackCore::OpcUaDataValue::SPtr& dataValue) = 0;
	};


	class DLLEXPORT AttributeServiceNode
	{
	  public:
		typedef boost::shared_ptr<AttributeServiceNode> SPtr;

		AttributeServiceNode(void);
		~AttributeServiceNode(void);

		void attributeService(AttributeService::SPtr& attributeService);
		void attributeServiceNodeIf(AttributeServiceNodeIf* attributeServiceNodeIf);
		void nodeId(OpcUaStackCore::OpcUaNodeId& nodeId);
		void attributeIds(
			const OpcUaStackCore::AttributeId& attributeId1
		);
		void attributeIds(
			const OpcUaStackCore::AttributeId& attributeId1,
			const OpcUaStackCore::AttributeId& attributeId2
		);
		void attributeIds(
			const OpcUaStackCore::AttributeId& attributeId1,
			const OpcUaStackCore::AttributeId& attributeId2,
			const OpcUaStackCore::AttributeId& attributeId3
		);
		void attributeIds(
			const OpcUaStackCore::AttributeId& attributeId1,
			const OpcUaStackCore::AttributeId& attributeId2,
			const OpcUaStackCore::AttributeId& attributeId3,
			const OpcUaStackCore::AttributeId& attributeId4
		);
		void attributeIds(
			const OpcUaStackCore::AttributeId& attributeId1,
			const OpcUaStackCore::AttributeId& attributeId2,
			const OpcUaStackCore::AttributeId& attributeId3,
			const OpcUaStackCore::AttributeId& attributeId4,
			const OpcUaStackCore::AttributeId& attributeId5
		);
		void attributeIds(OpcUaStackCore::NodeClass::Enum nodeClassType);

		void asyncReadNode(void);
		void syncReadNode(void);

	  private:
		OpcUaStackCore::ServiceTransactionRead::SPtr createTransaction(void);
		void attributeServiceReadResponse(OpcUaStackCore::ServiceTransactionRead::SPtr serviceTransactionRead);

		AttributeService::SPtr attributeService_;
		AttributeServiceNodeIf* attributeServiceNodeIf_;

		OpcUaStackCore::OpcUaNodeId nodeId_;
		std::vector<OpcUaStackCore::AttributeId> attributeIdVec_;

	};

}

#endif
