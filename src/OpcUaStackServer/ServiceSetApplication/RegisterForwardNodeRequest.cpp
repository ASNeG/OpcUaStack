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

#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardNodeRequest.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterForwardNodeRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterForwardNodeRequest::RegisterForwardNodeRequest(void)
	: Object()
	, nodesToRegisterArraySPtr_(boost::make_shared<OpcUaNodeIdArray>())
	, forwardNodeSync_(boost::make_shared<ForwardNodeSync>())
	, applicationContextArray_(boost::make_shared<BaseClassArray>())
	{
	}

	RegisterForwardNodeRequest::~RegisterForwardNodeRequest(void)
	{
	}

	void 
	RegisterForwardNodeRequest::nodesToRegister(const OpcUaNodeIdArray::SPtr nodesToRegister)
	{
		nodesToRegisterArraySPtr_ = nodesToRegister;
	}
	
	OpcUaNodeIdArray::SPtr 
	RegisterForwardNodeRequest::nodesToRegister(void) const
	{
		return nodesToRegisterArraySPtr_;
	}

	bool
	RegisterForwardNodeRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return nodesToRegisterArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	RegisterForwardNodeRequest::opcUaBinaryDecode(std::istream& is)
	{
		return nodesToRegisterArraySPtr_->opcUaBinaryDecode(is);
	}

	void
	RegisterForwardNodeRequest::forwardNodeSync(ForwardNodeSync::SPtr forwardInfo)
	{
		forwardNodeSync_ = forwardInfo;
	}

	ForwardNodeSync::SPtr
	RegisterForwardNodeRequest::forwardNodeSync(void)
	{
		return forwardNodeSync_;
	}

	void
	RegisterForwardNodeRequest::applicationContextArray(BaseClassArray::SPtr& applicationContextArray)
	{
		applicationContextArray_ = applicationContextArray;
	}

	BaseClassArray::SPtr&
	RegisterForwardNodeRequest::applicationContextArray(void)
	{
		return applicationContextArray_;
	}

}
