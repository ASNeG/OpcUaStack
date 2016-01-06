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
	: ObjectPool<BrowsePathResult>()
	, statusCode_()
	, targetArraySPtr_(RelativePathElementArray::construct())
	, targetIdSPtr_(constructSPtr<OpcUaExpandedNodeId>())
	, remainingPathIndex_()
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
	BrowsePathResult::targets(const RelativePathElementArray::SPtr targets)
	{
		targetArraySPtr_ = targets;
	}
	
	RelativePathElementArray::SPtr 
	BrowsePathResult::targets(void) const
	{
		return targetArraySPtr_;
	}
	
	void 
	BrowsePathResult::tragetId(const OpcUaExpandedNodeId::SPtr targetId)
	{
		targetIdSPtr_ = targetId;
	}
	
	OpcUaExpandedNodeId::SPtr 
	BrowsePathResult::targetId(void)
	{
		return targetIdSPtr_;
	}
	
	void 
	BrowsePathResult::remainingPathIndex(const OpcUaUInt32& remainingPathIndex)
	{
		remainingPathIndex_ = remainingPathIndex;
	}
	
	OpcUaUInt32 
	BrowsePathResult::remainingPathIndex(void)
	{
		return remainingPathIndex_;
	}

	void 
	BrowsePathResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
		targetArraySPtr_->opcUaBinaryEncode(os);
		targetIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, remainingPathIndex_);
	}
	
	void 
	BrowsePathResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		targetArraySPtr_->opcUaBinaryDecode(is);
		targetIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, remainingPathIndex_);
	}

}
