/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"

namespace OpcUaStackCore
{

	uint32_t ServiceTransaction::uniqueTransactionId_ = 0;
	boost::mutex ServiceTransaction::mutex_;

	uint32_t 
	ServiceTransaction::getUniqueTransactionId(void)
	{
		uint32_t transactionId;
		mutex_.lock();
		transactionId = uniqueTransactionId_;
		uniqueTransactionId_++;
		mutex_.unlock();
		return transactionId;
	}

	ServiceTransaction::ServiceTransaction(OpcUaUInt32 nodeTypeRequest, OpcUaUInt32 nodeTypeResponse)
	: requestTimeout_(0)
	, requestHeader_()
	, responseHeader_()
	, sync_(false)
	, conditionBool_()
	, handle_()
	, userContext_()
	{
		nodeTypeRequest_.set(nodeTypeRequest);
		nodeTypeResponse_.set(nodeTypeResponse);
		transactionId_ = getUniqueTransactionId();
	}
	
	ServiceTransaction::~ServiceTransaction(void)
	{
	}

	void 
	ServiceTransaction::channelId(OpcUaUInt32 channelId)
	{
		channelId_ = channelId;
	}
		
	OpcUaUInt32 
	ServiceTransaction::channelId(void)
	{
		return channelId_;
	}

	void 
	ServiceTransaction::sessionId(uint32_t sessionId)
	{
		sessionId_ = sessionId;
	}

	OpcUaUInt32 
	ServiceTransaction::sessionId(void)
	{
		return sessionId_;
	}

	void
	ServiceTransaction::handle(Object::SPtr& handle)
	{
		handle_ = handle;
	}

	Object::SPtr
	ServiceTransaction::handle(void)
	{
		return handle_;
	}

	OpcUaUInt32 
	ServiceTransaction::transactionId(void)
	{
		return transactionId_;
	}

	void 
	ServiceTransaction::sync(bool sync)
	{
		sync_ = sync;
	}

	bool 
	ServiceTransaction::sync(void)
	{
		return sync_;
	}

	ConditionBool&
	ServiceTransaction::conditionBool(void)
	{
		return conditionBool_;
	}

	void 
	ServiceTransaction::requestHeader(RequestHeader::SPtr requestHeader)
	{
		requestHeader_ = requestHeader;
	}

	RequestHeader::SPtr 
	ServiceTransaction::requestHeader(void)
	{
		if (requestHeader_.get() == nullptr) {
			requestHeader_ = constructSPtr<RequestHeader>();
		}
		return requestHeader_;
	}

	void 
	ServiceTransaction::responseHeader(ResponseHeader::SPtr responseHeader)
	{
		responseHeader_ = responseHeader;
	}

	ResponseHeader::SPtr 
	ServiceTransaction::responseHeader(void)
	{
		if (responseHeader_.get() == nullptr) {
			responseHeader_ = constructSPtr<ResponseHeader>();
		}
		return responseHeader_;
	}

	OpcUaNodeId& 
	ServiceTransaction::nodeTypeRequest(void)
	{
		return nodeTypeRequest_;
	}

	OpcUaNodeId&
	ServiceTransaction::nodeTypeResponse(void)
	{
		return nodeTypeResponse_;
	}

	Component*
	ServiceTransaction::componentService(void)
	{
		return componentService_;
	}

	void 
	ServiceTransaction::componentService(Component* componentService)
	{
		componentService_ = componentService;
	}
	
	Component*
	ServiceTransaction::componentSession(void)
	{
		return componentSession_;
	}

	void 
	ServiceTransaction::componentSession(Component* componentSession)
	{
		componentSession_ = componentSession;
	}

	void
	ServiceTransaction::userContext(UserContext::SPtr& userContext)
	{
		userContext_ = userContext;
	}

	UserContext::SPtr&
	ServiceTransaction::userContext(void)
	{
		return userContext_;
	}

	void 
	ServiceTransaction::statusCode(OpcUaStatusCode statusCode)
	{
		statusCode_ = statusCode;
	}
		
	OpcUaStatusCode 
	ServiceTransaction::statusCode(void)
	{
		return statusCode_;
	}

	void
	ServiceTransaction::requestTimeout(uint32_t requestTimeout)
	{
		requestTimeout_ = requestTimeout;
	}

	void
	ServiceTransaction::calcRequestTimeout(uint32_t& requestTimeout)
	{
		if (requestTimeout_ != 0) requestTimeout = requestTimeout_;
	}

}
