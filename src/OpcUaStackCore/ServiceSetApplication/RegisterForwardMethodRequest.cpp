/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardMethodRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterForwardMethodRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterForwardMethodRequest::RegisterForwardMethodRequest(void)
	: Object()
	, forwardMethodSync_(boost::make_shared<ForwardMethodSync>())
	, objectNodeId_()
	, methodNodeId_()
	{
	}

	RegisterForwardMethodRequest::~RegisterForwardMethodRequest(void)
	{
	}

	bool
	RegisterForwardMethodRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return false;
	}
	
	bool
	RegisterForwardMethodRequest::opcUaBinaryDecode(std::istream& is)
	{
		return false;
	}

	void
	RegisterForwardMethodRequest::forwardMethodSync(ForwardMethodSync::SPtr forwardMethodSync)
	{
		forwardMethodSync_ = forwardMethodSync;
	}

	ForwardMethodSync::SPtr&
	RegisterForwardMethodRequest::forwardMethodSync(void)
	{
		return forwardMethodSync_;
	}

	void
	RegisterForwardMethodRequest::objectNodeId(OpcUaNodeId& objectNodeId)
	{
		objectNodeId.copyTo(objectNodeId_);
	}

	OpcUaNodeId&
	RegisterForwardMethodRequest::objectNodeId(void)
	{
		return objectNodeId_;
	}

	void
	RegisterForwardMethodRequest::methodNodeId(OpcUaNodeId& methodNodeId)
	{
		methodNodeId.copyTo(methodNodeId_);
	}

	OpcUaNodeId&
	RegisterForwardMethodRequest::methodNodeId(void)
	{
		return methodNodeId_;
	}

}
