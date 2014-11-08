#ifndef __OpcUaStackCore_ServiceTransaction_h__
#define __OpcUaStackCore_ServiceTransaction_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OPcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ServiceTransaction : public Object, public Message 
	{
	  public:
		typedef boost::shared_ptr<ServiceTransaction> SPtr;

		ServiceTransaction(OpcUaUInt32 nodeTypeRequest, OpcUaUInt32 nodeTypeResponse);
		virtual ~ServiceTransaction(void);

		virtual SPtr constructTransaction(void) = 0;

		uint32_t transactionId(void);
		OpcUaNodeId& nodeTypeRequest(void);
		OpcUaNodeId& nodeTypeResponse(void);

		void sessionId(uint32_t sessionId);
		uint32_t sessionId(void);

		void requestHeader(RequestHeader::SPtr requestHeader);
		RequestHeader::SPtr requestHeader(void);
		void responseHeader(ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void);

		Component* componentService(void);
		void componentService(Component* componentService);
		Component* componentSession(void);
		void componentSession(Component* componentSession);

		virtual void opcUaBinaryEncodeRequest(std::ostream& os) const = 0;
		virtual void opcUaBinaryEncodeResponse(std::ostream& os) const = 0;
		virtual void opcUaBinaryDecodeRequest(std::istream& is) = 0;
		virtual void opcUaBinaryDecodeResponse(std::istream& is) = 0;

		void statusCode(OpcUaStatusCode statusCode);
		OpcUaStatusCode statusCode(void);

		uint32_t requestId_;

		virtual std::string requestName(void) = 0;
		virtual std::string responseName(void) = 0;

	  private:
		static uint32_t uniqueTransactionId_;
		static boost::mutex mutex_;
		static uint32_t getUniqueTransactionId(void);

		uint32_t sessionId_;
		uint32_t transactionId_;
		OpcUaNodeId nodeTypeRequest_;
		OpcUaNodeId nodeTypeResponse_;

		RequestHeader::SPtr requestHeader_;
		ResponseHeader::SPtr responseHeader_;

		Component* componentService_;
		Component* componentSession_;

		OpcUaStatusCode statusCode_;
	};

}

#endif