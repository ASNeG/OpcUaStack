/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaStackServer/Forward/ForwardTransaction.h>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ForwardTransaction::ForwardTransaction(
		OpcUaUInt32 nodeTypeRequest,
		OpcUaUInt32 nodeTypeResponse
	)
	: Message(Message::ForwardTransaction)
	{
		nodeTypeRequest_ = nodeTypeRequest;
		nodeTypeResponse_ = nodeTypeResponse;
	}

	ForwardTransaction::~ForwardTransaction(void)
	{
	}

	OpcUaNodeId&
	ForwardTransaction::nodeTypeRequest(void)
	{
		return nodeTypeRequest_;
	}

	OpcUaNodeId&
	ForwardTransaction::nodeTypeResponse(void)
	{
		return nodeTypeResponse_;
	}

	void
	ForwardTransaction::messageBusMemberSource(const MessageBusMember::WPtr& messageBusMemberSource)
	{
		messageBusMemberSource_ = messageBusMemberSource;
	}

	MessageBusMember::WPtr
	ForwardTransaction::messageBusMemberSource(void)
	{
		return messageBusMemberSource_;
	}

	void
	ForwardTransaction::messageBusMemberTarget(const MessageBusMember::WPtr& messageBusMemberTarget)
	{
		messageBusMemberTarget_ = messageBusMemberTarget;
	}

	MessageBusMember::WPtr
	ForwardTransaction::messageBusMemberTarget(void)
	{
		return messageBusMemberTarget_;
	}

	void
	ForwardTransaction::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	ForwardTransaction::name(void)
	{
		return name_;
	}

	void
	ForwardTransaction::applicationContext(const BaseClass::SPtr& applicationContext)
	{
		applicationContext_ = applicationContext;
	}

	BaseClass::SPtr
	ForwardTransaction::applicationContext(void)
	{
		return applicationContext_;
	}

	void
	ForwardTransaction::forwardJob(const Object::WPtr& forwardJob)
	{
		forwardJob_ = forwardJob;
	}

	Object::WPtr&
	ForwardTransaction::forwardJob(void)
	{
		return forwardJob_;
	}

	void
	ForwardTransaction::idx(uint32_t idx)
	{
		idx_ = idx;
	}

	uint32_t
	ForwardTransaction::idx(void)
	{
		return idx_;
	}

	void
	ForwardTransaction::complete(bool complete)
	{
		complete_ = complete;
	}

	bool
	ForwardTransaction::complete(void)
	{
		return complete_;
	}

	void
	ForwardTransaction::userContext(const UserContext::SPtr& userContext)
	{
		userContext_ = userContext;
	}

	UserContext::SPtr
	ForwardTransaction::userContext(void)
	{
		return userContext_;
	}

	void
	ForwardTransaction::statusCode(OpcUaStatusCode statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaStatusCode
	ForwardTransaction::statusCode(void)
	{
		return statusCode_;
	}

}
