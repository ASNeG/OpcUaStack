/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardCallRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterForwardCallRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterForwardCallRequest::RegisterForwardCallRequest(void)
	: Object()
	, nodesToRegisterArraySPtr_(constructSPtr<OpcUaNodeIdArray>())
	, forwardInfoSync_(constructSPtr<ForwardInfoSync>())
	{
	}

	RegisterForwardCallRequest::~RegisterForwardCallRequest(void)
	{
	}

	void 
	RegisterForwardCallRequest::nodesToRegister(const OpcUaNodeIdArray::SPtr nodesToRegister)
	{
		nodesToRegisterArraySPtr_ = nodesToRegister;
	}
	
	OpcUaNodeIdArray::SPtr 
	RegisterForwardCallRequest::nodesToRegister(void) const
	{
		return nodesToRegisterArraySPtr_;
	}

	void 
	RegisterForwardCallRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		nodesToRegisterArraySPtr_->opcUaBinaryEncode(os);	
	}
	
	void 
	RegisterForwardCallRequest::opcUaBinaryDecode(std::istream& is)
	{
		nodesToRegisterArraySPtr_->opcUaBinaryDecode(is);
	}

	void
	RegisterForwardCallRequest::forwardInfoSync(ForwardInfoSync::SPtr forwardInfo)
	{
		forwardInfoSync_ = forwardInfo;
	}

	ForwardInfoSync::SPtr
	RegisterForwardCallRequest::forwardInfoSync(void)
	{
		return forwardInfoSync_;
	}

}
