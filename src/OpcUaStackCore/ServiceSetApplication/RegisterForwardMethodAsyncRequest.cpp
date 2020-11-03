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

#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardMethodAsyncRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterForwardMethodAsyncRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterForwardMethodAsyncRequest::RegisterForwardMethodAsyncRequest(void)
	: Object()
	, forwardMethodAsync_(boost::make_shared<ForwardMethodAsync>())
	, objectNodeId_()
	, methodNodeId_()
	{
	}

	RegisterForwardMethodAsyncRequest::~RegisterForwardMethodAsyncRequest(void)
	{
	}

	void
	RegisterForwardMethodAsyncRequest::forwardMethodAsync(ForwardMethodAsync::SPtr forwardMethodAsync)
	{
		forwardMethodAsync_ = forwardMethodAsync;
	}

	ForwardMethodAsync::SPtr&
	RegisterForwardMethodAsyncRequest::forwardMethodAsync(void)
	{
		return forwardMethodAsync_;
	}

	void
	RegisterForwardMethodAsyncRequest::objectNodeId(OpcUaNodeId& objectNodeId)
	{
		objectNodeId.copyTo(objectNodeId_);
	}

	OpcUaNodeId&
	RegisterForwardMethodAsyncRequest::objectNodeId(void)
	{
		return objectNodeId_;
	}

	void
	RegisterForwardMethodAsyncRequest::methodNodeId(OpcUaNodeId& methodNodeId)
	{
		methodNodeId.copyTo(methodNodeId_);
	}

	OpcUaNodeId&
	RegisterForwardMethodAsyncRequest::methodNodeId(void)
	{
		return methodNodeId_;
	}

}
