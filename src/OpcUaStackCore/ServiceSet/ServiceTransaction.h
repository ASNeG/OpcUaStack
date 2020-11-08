/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ServiceTransaction_h__
#define __OpcUaStackCore_ServiceTransaction_h__

#include <future>
#include <boost/thread/mutex.hpp>
#include <OpcUaStackCore/MessageBus/MessageBus.h>
#include "OpcUaStackCore/Base/UserContext.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ServiceTransaction
	: public Message
	{
	  public:
		typedef boost::shared_ptr<ServiceTransaction> SPtr;

		ServiceTransaction(OpcUaUInt32 nodeTypeRequest, OpcUaUInt32 nodeTypeResponse);
		virtual ~ServiceTransaction(void);

		virtual SPtr constructTransaction(void) = 0;

		void handle(Object::SPtr& handle);
		Object::SPtr handle(void);

		OpcUaUInt32 transactionId(void);
		OpcUaNodeId& nodeTypeRequest(void);
		OpcUaNodeId& nodeTypeResponse(void);

		void channelId(OpcUaUInt32 channelId);
		OpcUaUInt32 channelId(void);
		void sessionId(uint32_t sessionId);
		OpcUaUInt32 sessionId(void);

		void sync(bool sync);
		bool sync(void);
		std::promise<bool>& promise(void);

		void requestHeader(RequestHeader::SPtr requestHeader);
		RequestHeader::SPtr requestHeader(void);
		void responseHeader(ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void);

		void memberService(const MessageBusMember::WPtr& memberService);
		MessageBusMember::WPtr& memberService(void);
		void memberServiceSession(const MessageBusMember::WPtr& memberServiceSession);
		MessageBusMember::WPtr& memberServiceSession(void);

		void userContext(UserContext::SPtr& userContext);
		UserContext::SPtr& userContext(void);

		virtual bool opcUaBinaryEncodeRequest(std::ostream& os) const = 0;
		virtual bool opcUaBinaryEncodeResponse(std::ostream& os) const = 0;
		virtual bool opcUaBinaryDecodeRequest(std::istream& is) = 0;
		virtual bool opcUaBinaryDecodeResponse(std::istream& is) = 0;

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

		Object::SPtr handle_;

		uint32_t requestTimeout_;

		bool sync_;
		std::promise<bool> promise_;

		OpcUaUInt32 channelId_;
		OpcUaUInt32 sessionId_;
		OpcUaUInt32 transactionId_;
		OpcUaNodeId nodeTypeRequest_;
		OpcUaNodeId nodeTypeResponse_;

		RequestHeader::SPtr requestHeader_;
		ResponseHeader::SPtr responseHeader_;

		MessageBusMember::WPtr memberService_;
		MessageBusMember::WPtr memberServiceSession_;

		UserContext::SPtr userContext_;
		OpcUaStatusCode statusCode_;
	};

}

#endif
