/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/RegisterForwardRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterForwardRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterForwardRequest::RegisterForwardRequest(void)
	: ObjectPool<RegisterForwardRequest>()
	, nodesToRegisterArraySPtr_(OpcUaNodeIdArray::construct())
	, forwardInfoSync_(ForwardInfoSync::construct())
	{
	}

	RegisterForwardRequest::~RegisterForwardRequest(void)
	{
	}

	void 
	RegisterForwardRequest::nodesToRegister(const OpcUaNodeIdArray::SPtr nodesToRegister)
	{
		nodesToRegisterArraySPtr_ = nodesToRegister;
	}
	
	OpcUaNodeIdArray::SPtr 
	RegisterForwardRequest::nodesToRegister(void) const
	{
		return nodesToRegisterArraySPtr_;
	}

	void 
	RegisterForwardRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		nodesToRegisterArraySPtr_->opcUaBinaryEncode(os);	
	}
	
	void 
	RegisterForwardRequest::opcUaBinaryDecode(std::istream& is)
	{
		nodesToRegisterArraySPtr_->opcUaBinaryDecode(is);
	}

	void
	RegisterForwardRequest::forwardInfoSync(ForwardInfoSync::SPtr forwardInfo)
	{
		forwardInfoSync_ = forwardInfo;
	}

	ForwardInfoSync::SPtr
	RegisterForwardRequest::forwardInfoSync(void)
	{
		return forwardInfoSync_;
	}

}
