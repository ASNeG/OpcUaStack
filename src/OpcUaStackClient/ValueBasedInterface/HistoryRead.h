/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_HistoryRead_h__
#define __OpcUaStackClient_HistoryRead_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"
#include "OpcUaStackClient/ServiceSet/AttributeService.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaStackClient
{

	class DLLEXPORT HistoryRead
	{
	  public:
		typedef std::function<
			void (OpcUaStatusCode statusCode, OpcUaDataValue::Vec& dataValueVec)
		> ResultHandler;

		HistoryRead(void);
		~HistoryRead(void);

		void attributeService(AttributeService::SPtr& attributeService);
		void maxNumResultValuesPerRequest(uint32_t maxNumResultValuesPerRequest);
		void maxNumResultValuesPerNode(uint32_t maxNumResultValuesPerNode);

		OpcUaStatusCode syncHistoryRead(
			const OpcUaNodeId& nodeId,
			boost::posix_time::ptime startTime,
			boost::posix_time::ptime endTime,
			OpcUaDataValue::Vec& dataValueVec
		);
		void asyncHistoryRead(
			const OpcUaNodeId& nodeId,
			boost::posix_time::ptime startTime,
			boost::posix_time::ptime endTime,
			const ResultHandler& resultHandler
		);
		void asyncCancel(void);

	  private:
		void asyncHistoryRead(void);
		void asyncHistoryReadComplete(
			bool releaseContinuationPoints,
			ServiceTransactionHistoryRead::SPtr& trx
		);

		// input parameter
		OpcUaNodeId nodeId_;
		boost::posix_time::ptime startTime_;
		boost::posix_time::ptime endTime_;
		ResultHandler resultHandler_;

		// output parameter
		OpcUaDataValue::Vec dataValueVec_;

		// runtime parameter
		AttributeService::SPtr attributeService_;
		bool cancel_;
		bool releaseContinuationPoint_;

		TimestampsToReturn timestampToReturn_;
		uint32_t maxNumResultValuesPerRequest_;
		uint32_t maxNumResultValuesPerNode_;
		uint32_t actNumResultValuesPerNode_;
		OpcUaByteString continuationPoint_;
	};

}

#endif
