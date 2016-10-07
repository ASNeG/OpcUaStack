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

#include "OpcUaStackCore/ServiceSet/RegisterNodesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterNodesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterNodesRequest::RegisterNodesRequest(void)
	: ObjectPool<RegisterNodesRequest>()
	, nodesToRegisterArraySPtr_(constructSPtr<OpcUaNodeIdArray>())
	{
	}

	RegisterNodesRequest::~RegisterNodesRequest(void)
	{
	}

	void 
	RegisterNodesRequest::nodesToRegister(const OpcUaNodeIdArray::SPtr nodesToRegister)
	{
		nodesToRegisterArraySPtr_ = nodesToRegister;
	}
	
	OpcUaNodeIdArray::SPtr 
	RegisterNodesRequest::nodesToRegister(void) const
	{
		return nodesToRegisterArraySPtr_;
	}

	void 
	RegisterNodesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		nodesToRegisterArraySPtr_->opcUaBinaryEncode(os);	
	}
	
	void 
	RegisterNodesRequest::opcUaBinaryDecode(std::istream& is)
	{
		nodesToRegisterArraySPtr_->opcUaBinaryDecode(is);
	}

}
