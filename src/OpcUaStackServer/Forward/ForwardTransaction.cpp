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

}
