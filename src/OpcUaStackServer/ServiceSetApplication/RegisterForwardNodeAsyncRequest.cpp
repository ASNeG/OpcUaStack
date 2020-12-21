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

#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardNodeAsyncRequest.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterForwardNodeAsyncRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterForwardNodeAsyncRequest::RegisterForwardNodeAsyncRequest(void)
	: Object()
	, nodesToRegisterArraySPtr_(boost::make_shared<OpcUaNodeIdArray>())
	, forwardNodeAsync_(boost::make_shared<ForwardNodeAsync>())
	, applicationContextArray_(boost::make_shared<BaseClassArray>())
	{
	}

	RegisterForwardNodeAsyncRequest::~RegisterForwardNodeAsyncRequest(void)
	{
	}

	void 
	RegisterForwardNodeAsyncRequest::nodesToRegister(const OpcUaNodeIdArray::SPtr nodesToRegister)
	{
		nodesToRegisterArraySPtr_ = nodesToRegister;
	}
	
	OpcUaNodeIdArray::SPtr 
	RegisterForwardNodeAsyncRequest::nodesToRegister(void) const
	{
		return nodesToRegisterArraySPtr_;
	}

	bool
	RegisterForwardNodeAsyncRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return nodesToRegisterArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	RegisterForwardNodeAsyncRequest::opcUaBinaryDecode(std::istream& is)
	{
		return nodesToRegisterArraySPtr_->opcUaBinaryDecode(is);
	}

	void
	RegisterForwardNodeAsyncRequest::forwardNodeAsync(ForwardNodeAsync::SPtr forwardInfo)
	{
		forwardNodeAsync_ = forwardInfo;
	}

	ForwardNodeAsync::SPtr
	RegisterForwardNodeAsyncRequest::forwardNodeAsync(void)
	{
		return forwardNodeAsync_;
	}

	void
	RegisterForwardNodeAsyncRequest::applicationContextArray(BaseClassArray::SPtr& applicationContextArray)
	{
		applicationContextArray_ = applicationContextArray;
	}

	BaseClassArray::SPtr&
	RegisterForwardNodeAsyncRequest::applicationContextArray(void)
	{
		return applicationContextArray_;
	}

}
