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
	, writeValueArraySPtr_(boost::make_shared<WriteValueArray>())
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
	WriteRequest::jsonEncodeImpl(boost::property_tree::ptree& pt) const
	{
		return jsonArraySPtrEncode(pt, writeValueArraySPtr_, "NodesToWrite");
	}

	bool
	WriteRequest::jsonDecodeImpl(const boost::property_tree::ptree& pt)
	{
		return jsonArraySPtrDecode(pt, writeValueArraySPtr_, "NodesToWrite");
	}
}
