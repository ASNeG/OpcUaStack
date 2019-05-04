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

#include "OpcUaStackCore/ServiceSet/WriteRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa WriteRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	WriteRequest::WriteRequest(void)
	: Object()
	, writeValueArraySPtr_(constructSPtr<WriteValueArray>())
	{
	}


	WriteRequest::~WriteRequest(void)
	{
	}

	void 
	WriteRequest::writeValueArray(const WriteValueArray::SPtr writeValueArray)
	{
		writeValueArraySPtr_ = writeValueArray;
	}

	WriteValueArray::SPtr 
	WriteRequest::writeValueArray(void) const
	{
		return writeValueArraySPtr_;
	}

	bool 
	WriteRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		writeValueArraySPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool
	WriteRequest::opcUaBinaryDecode(std::istream& is)
	{
		writeValueArraySPtr_->opcUaBinaryDecode(is);
		return true;
	}

	bool
	WriteRequest::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree)) {
			Log(Error, "WriteRequest json encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	WriteRequest::jsonEncode(boost::property_tree::ptree& pt)
	{
		// encode write value array
		if (!writeValueArraySPtr_->jsonEncode(pt, "NodesToWrite", "")) {
			Log(Error, "WriteRequest json encode error")
				.parameter("Element", "NodesToWrite");
			return false;
		}

		return true;
	}

	bool
	WriteRequest::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tmpTree;

		tmpTree = pt.get_child_optional(element);
		if (!tmpTree) {
			Log(Error, "WriteRequest json decoder error")
				.parameter("Element", element);
				return false;
		}
		return jsonDecode(*tmpTree);
	}

	bool
	WriteRequest::jsonDecode(boost::property_tree::ptree& pt)
	{
		// decode write value array
		if (!writeValueArraySPtr_->jsonDecode(pt, "NodesToWrite", "")) {
			Log(Error, "writeRequest json decode error")
			    .parameter("Element", "NodesToWrite");
			return false;
		}

		return true;
	}
}
