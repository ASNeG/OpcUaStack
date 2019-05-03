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

#include "OpcUaStackCore/ServiceSet/ReadRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadRequest::ReadRequest(void)
	: Object()
	, maxAge_()
	, timestampsToReturn_()
	, readValueIdArraySPtr_(constructSPtr<ReadValueIdArray>())
	{
	}

	ReadRequest::~ReadRequest(void)
	{
	}

	void 
	ReadRequest::maxAge(const OpcUaDouble& maxAge)
	{
		maxAge_ = maxAge;
	}
	
	OpcUaDouble 
	ReadRequest::maxAge(void) const
	{
		return maxAge_;
	}
	
	void 
	ReadRequest::timestampsToReturn(const OpcUaInt32& timestampsToReturn)
	{
		timestampsToReturn_ = timestampsToReturn;
	}
	
	OpcUaInt32 
	ReadRequest::timestampsToReturn(void) const
	{
		return timestampsToReturn_;
	}
	
	void 
	ReadRequest::readValueIdArray(const ReadValueIdArray::SPtr readValueIdArraySPtr)
	{
		readValueIdArraySPtr_ = readValueIdArraySPtr;
	}
	
	ReadValueIdArray::SPtr 
	ReadRequest::readValueIdArray(void) const
	{
		return readValueIdArraySPtr_;
	}

	bool
	ReadRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, maxAge_);
		OpcUaNumber::opcUaBinaryEncode(os, timestampsToReturn_);
		readValueIdArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool 
	ReadRequest::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, maxAge_);
		OpcUaNumber::opcUaBinaryDecode(is, timestampsToReturn_);
		readValueIdArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}

	bool
	ReadRequest::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree)) {
			Log(Error, "ReadRequest json encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	ReadRequest::jsonEncode(boost::property_tree::ptree& pt)
	{
		// encode max age
		if (maxAge_ != 0) {
			if (!JsonNumber::jsonEncode(pt, maxAge_, "MaxAge")) {
				Log(Error, "ReadRequest json encode error")
					.parameter("Element", "MaxAge");
				return false;
			}
		}

		// encode timestamps to return
		if (!JsonNumber::jsonEncode(pt, timestampsToReturn_, "TimestampsToReturn")) {
			Log(Error, "ReadRequest json encode error")
				.parameter("Element", "TimestampsToReturn");
			return false;
		}

		// encode value id array
		if (!readValueIdArraySPtr_->jsonEncode(pt, "NodesToRead")) {
			Log(Error, "ReadRequest json encode error")
				.parameter("Element", "ValueIds");
			return false;
		}

		return true;
	}

	bool
	ReadRequest::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tmpTree;

		tmpTree = pt.get_child_optional(element);
		if (!tmpTree) {
			Log(Error, "ReadRequest json decoder error")
				.parameter("Element", element);
				return false;
		}
		return jsonDecode(*tmpTree);
	}

	bool
	ReadRequest::jsonDecode(boost::property_tree::ptree& pt)
	{
		// decode max age
		if (!JsonNumber::jsonDecode(pt, maxAge_, "MaxAge")) {
			maxAge_ = 0;
		}

		// decode timestamps to return
		if (!JsonNumber::jsonDecode(pt, timestampsToReturn_, "TimestampsToReturn")) {
			timestampsToReturn_ = 0;
		}

		// decode value id array
		if (!readValueIdArraySPtr_->jsonDecode(pt, "NodesToRead")) {
			Log(Error, "ReadRequest json decode error")
			    .parameter("Element", "NodesToRead");
			return false;
		}

		return true;
	}

}
