#ifndef __OpcUaStackClient_ServiceTransaction_h__
#define __OpcUaStackClient_ServiceTransaction_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT ServiceTransaction
	{
	  public:
		ServiceTransaction(OpcUaUInt32 nodeTypeRequest, OpcUaUInt32 nodeTypeResponse);
		virtual ~ServiceTransaction(void);

		uint32_t transactionId(void);
		OpcUaNodeId& nodeTypeRequest(void);
		OpcUaNodeId& nodeTypeResponse(void);

		virtual RequestHeader::SPtr getRequestHeader(void) = 0;
		virtual ResponseHeader::SPtr getResponseHeader(void) = 0;

		virtual void opcUaBinaryEncodeRequest(std::ostream& os) const = 0;
		virtual void opcUaBinaryEncodeResponse(std::ostream& os) const = 0;
		virtual void opcUaBinaryDecodeRequest(std::istream& is) = 0;
		virtual void opcUaBinaryDecodeResponse(std::istream& is) = 0;

	  private:
		static uint32_t uniqueTransactionId_;
		static boost::mutex mutex_;
		static uint32_t getUniqueTransactionId(void);

		uint32_t transactionId_;
		OpcUaNodeId nodeTypeRequest_;
		OpcUaNodeId nodeTypeResponse_;
	};

}

#endif