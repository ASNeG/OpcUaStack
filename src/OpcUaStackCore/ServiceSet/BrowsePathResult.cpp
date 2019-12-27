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

#include "OpcUaStackCore/ServiceSet/BrowsePathResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa BrowsePathResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	BrowsePathResult::BrowsePathResult(void)
	: Object()
	, statusCode_()
	, targetArraySPtr_(boost::make_shared<BrowsePathTargetArray>())
	{
	}

	BrowsePathResult::~BrowsePathResult(void)
	{
	}

	void 
	BrowsePathResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode& 
	BrowsePathResult::statusCode(void)
	{
		return statusCode_;
	}
	
	void 
	BrowsePathResult::targets(const BrowsePathTargetArray::SPtr targets)
	{
		targetArraySPtr_ = targets;
	}
	
	BrowsePathTargetArray::SPtr
	BrowsePathResult::targets(void) const
	{
		return targetArraySPtr_;
	}
	
	bool
	BrowsePathResult::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		rc &= targetArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	BrowsePathResult::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaUInt32 tmp;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		rc &= targetArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

}
