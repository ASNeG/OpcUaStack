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

#include "OpcUaStackCore/ServiceSet/UnregisterNodesRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa UnregisterNodesRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	UnregisterNodesRequest::UnregisterNodesRequest(void)
	: Object()
	, nodesToUnregisterArraySPtr_(constructSPtr<OpcUaNodeIdArray>())
	{
	}

	UnregisterNodesRequest::~UnregisterNodesRequest(void)
	{
	}

	void 
	UnregisterNodesRequest::nodesToUnregister(const OpcUaNodeIdArray::SPtr nodesToUnregister)
	{
		nodesToUnregisterArraySPtr_ = nodesToUnregister;
	}
	
	OpcUaNodeIdArray::SPtr 
	UnregisterNodesRequest::nodesToUnregister(void) const
	{
		return nodesToUnregisterArraySPtr_;
	}

	void 
	UnregisterNodesRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		nodesToUnregisterArraySPtr_->opcUaBinaryEncode(os);	
	}
	
	void 
	UnregisterNodesRequest::opcUaBinaryDecode(std::istream& is)
	{
		nodesToUnregisterArraySPtr_->opcUaBinaryDecode(is);
	}

}
