/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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
	, historyReadDetailsSPtr_(constructSPtr<OpcUaExtensibleParameter>())
	, timestampsToReturn_()
	, releaseContinuationPoints_()
	, nodesToReadArraySPtr_(constructSPtr<HistoryReadValueIdArray>())
	{
	}

	HistoryReadRequest::~HistoryReadRequest(void)
	{
	}

	void 
	HistoryReadRequest::historyReadDetails(const OpcUaExtensibleParameter::SPtr historyReadDetails)
	{
		historyReadDetailsSPtr_ = historyReadDetails;
	}
	
	OpcUaExtensibleParameter::SPtr
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

	bool
	HistoryReadRequest::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		// encode history read details
		if (!historyReadDetailsSPtr_->jsonEncode(pt, "HistoryReadDetails")) {
			Log(Error, "HistoryReadRequest json encode error")
				.parameter("Element", "HistoryReadDetails");
			return false;
		}

		// encode timestamps to return
		auto timestampToReturn = (uint32_t)timestampsToReturn_;
		if (!JsonNumber::jsonEncode(pt, timestampToReturn, "TimestampsToReturn")) {
			Log(Error, "HistoryReadRequest json encode error")
				.parameter("Element", "TimestampsToReturn");
			return false;
		}

		// encode release continuation point
		if (!JsonNumber::jsonEncode(pt, releaseContinuationPoints_, "ReleaseContinuationPoints")) {
			Log(Error, "HistoryReadRequest json encode error")
				.parameter("Element", "ReleaseContinuationPoints");
			return false;
		}

		// encode value id array
		if (!nodesToReadArraySPtr_->jsonEncode(pt, "NodesToRead")) {
			Log(Error, "HistoryReadRequest json encode error")
				.parameter("Element", "NodesToRead");
			return false;
		}

		return true;
	}

	bool
	HistoryReadRequest::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		boost::optional<const boost::property_tree::ptree&> tmpTree;

		// encode history read details
		if (!historyReadDetailsSPtr_->jsonDecode(pt, "HistoryReadDetails")) {
			Log(Error, "HistoryReadRequest json decode error")
				.parameter("Element", "HistoryReadDetails");
			return false;
		}

		// decode timestamps to return
		uint32_t timestampsToReturn;
		if (!JsonNumber::jsonDecode(pt, timestampsToReturn, "TimestampsToReturn")) {
			timestampsToReturn_ = TimestampsToReturn_Source;
		}
		else {
			timestampsToReturn_ = (TimestampsToReturn)timestampsToReturn;
		}

		// decode release continuation point
		tmpTree = pt.get_child_optional("ReleaseContinuationPoints");
		if (tmpTree) {
			if (!JsonNumber::jsonDecode(pt, releaseContinuationPoints_, "ReleaseContinuationPoints")) {
				Log(Error, "HistoryReadRequest json decode error")
					.parameter("Element", "ReleaseContinuationPoints");
				return false;
			}
		}

		// decode value id array
		if (!nodesToReadArraySPtr_->jsonDecode(pt, "NodesToRead")) {
			Log(Error, "HistoryReadRequest json decode error")
			    .parameter("Element", "NodesToRead");
			return false;
		}

		return true;
	}

}
