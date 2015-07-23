#ifndef __OpcUaStackCore_ServiceTransaction_h__
#define __OpcUaStackCore_ServiceTransaction_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ConditionBool.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ServiceTransaction
	: public Object
	, public Message
	{
	  public:
		typedef boost::shared_ptr<ServiceTransaction> SPtr;

		ServiceTransaction(OpcUaUInt32 nodeTypeRequest, OpcUaUInt32 nodeTypeResponse);
		virtual ~ServiceTransaction(void);

		virtual SPtr constructTransaction(void) = 0;

		OpcUaUInt32 transactionId(void);
		OpcUaNodeId& nodeTypeRequest(void);
		OpcUaNodeId& nodeTypeResponse(void);

		void channelId(OpcUaUInt32 channelId);
		OpcUaUInt32 channelId(void);
		void sessionId(uint32_t sessionId);
		OpcUaUInt32 sessionId(void);

		void sync(bool sync);
		bool sync(void);
		ConditionBool& conditionBool(void);

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
		void requestTimeout(uint32_t requestTimeout);
		void calcRequestTimeout(uint32_t& requestTimeout);

		uint32_t requestId_;

		virtual std::string requestName(void) = 0;
		virtual std::string responseName(void) = 0;

	  private:
		static uint32_t uniqueTransactionId_;
		static boost::mutex mutex_;
		static uint32_t getUniqueTransactionId(void);

		uint32_t requestTimeout_;

		bool sync_;
		ConditionBool conditionBool_;

		OpcUaUInt32 channelId_;
		OpcUaUInt32 sessionId_;
		OpcUaUInt32 transactionId_;
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
