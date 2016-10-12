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

#include "OpcUaStackCore/ServiceSet/HistoryReadRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryReadRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryReadRequest::HistoryReadRequest(void)
	: Object()
	, historyReadDetailsSPtr_(constructSPtr<ExtensibleParameter>())
	, timestampsToReturn_()
	, releaseContinuationPoints_()
	, nodesToReadArraySPtr_(constructSPtr<HistoryReadValueIdArray>())
	{
	}

	HistoryReadRequest::~HistoryReadRequest(void)
	{
	}

	void 
	HistoryReadRequest::historyReadDetails(const ExtensibleParameter::SPtr historyReadDetails)
	{
		historyReadDetailsSPtr_ = historyReadDetails;
	}
	
	ExtensibleParameter::SPtr 
	HistoryReadRequest::historyReadDetails(void) const
	{
		return historyReadDetailsSPtr_;
	}
	
	void 
	HistoryReadRequest::timestampsToReturn(const TimestampsToReturn timestampsToReturn)
	{
		timestampsToReturn_ = timestampsToReturn;
	}
	
	TimestampsToReturn 
	HistoryReadRequest::timestampsToReturn(void)
	{
		return timestampsToReturn_;
	}
	
	void 
	HistoryReadRequest::releaseContinuationPoints(const OpcUaBoolean& releaseContinuationPoints)
	{
		releaseContinuationPoints_ = releaseContinuationPoints;
	}
	
	OpcUaBoolean 
	HistoryReadRequest::releaseContinuationPoints(void)
	{
		return releaseContinuationPoints_;
	}
	
	void 
	HistoryReadRequest::nodesToRead(const HistoryReadValueIdArray::SPtr nodesToRead)
	{
		nodesToReadArraySPtr_ = nodesToRead;
	}
	
	HistoryReadValueIdArray::SPtr 
	HistoryReadRequest::nodesToRead(void) const
	{
		return nodesToReadArraySPtr_;
	}

	bool 
	HistoryReadRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		historyReadDetailsSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)timestampsToReturn_);
		OpcUaNumber::opcUaBinaryEncode(os, releaseContinuationPoints_);
		nodesToReadArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool 
	HistoryReadRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 tmp;
		historyReadDetailsSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		timestampsToReturn_ = (TimestampsToReturn)tmp;
		OpcUaNumber::opcUaBinaryDecode(is, releaseContinuationPoints_);
		nodesToReadArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}

}
