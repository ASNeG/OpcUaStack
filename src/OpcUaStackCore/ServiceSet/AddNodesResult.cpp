/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/AddNodesResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddNodesResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddNodesResult::AddNodesResult(void)
	: statusCode_()
	, addedNodeIdSPtr_()
	{
		addedNodeIdSPtr_ = boost::make_shared<OpcUaNodeId>();
	}

	AddNodesResult::~AddNodesResult(void)
	{
	}

	void
	AddNodesResult::statusCode(OpcUaStatusCode statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaStatusCode
	AddNodesResult::statusCode(void) const
	{
		return statusCode_;
	}


	void
	AddNodesResult::addedNodeId(const OpcUaNodeId::SPtr addedNodeIdSPtr)
	{
		addedNodeIdSPtr_ = addedNodeIdSPtr;
	}

	OpcUaNodeId::SPtr
	AddNodesResult::addedNodeId(void) const
	{
		return addedNodeIdSPtr_;
	}
	
	void 
	AddNodesResult::copyTo(AddNodesResult& addNodesResult)
	{
		addNodesResult.statusCode(statusCode_);
		addedNodeIdSPtr_->copyTo(*addNodesResult.addedNodeId().get());
	}

	void
	AddNodesResult::out(std::ostream& os) const
	{
		os << "StatusCode=" << statusCode_;
		os << ", AddedNodeId="; addedNodeIdSPtr_->out(os);
	}

	bool
	AddNodesResult::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		rc &= addedNodeIdSPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	AddNodesResult::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaUInt32 tmp;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		rc &= addedNodeIdSPtr_->opcUaBinaryDecode(is);

		return rc;
	}

}
