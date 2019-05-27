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

#include "OpcUaStackCore/ServiceSet/HistoryReadValueId.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryReadValueId
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryReadValueId::HistoryReadValueId(void)
	: Object()
	, nodeIdSPtr_(constructSPtr<OpcUaNodeId>())
	, indexRange_()
	, dataEncoding_()
	, continuationPoint_()
	{
	}

	HistoryReadValueId::~HistoryReadValueId(void)
	{
	}

	void 
	HistoryReadValueId::nodeId(const OpcUaNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}

	OpcUaNodeId::SPtr
	HistoryReadValueId::nodeId(void)
	{
		return nodeIdSPtr_;
	}

	void 
	HistoryReadValueId::indexRange(const OpcUaString& indexRange)
	{
		indexRange_ = indexRange;
	}

	std::string 
	HistoryReadValueId::indexRange(void) const
	{
		return indexRange_.value();
	}
	
	void 
	HistoryReadValueId::dataEncoding(const OpcUaQualifiedName& dataEncoding)
	{
		dataEncoding_ = dataEncoding;
	}
	
	OpcUaQualifiedName&
	HistoryReadValueId::dataEncoding(void)
	{
		return dataEncoding_;
	}

	void 
	HistoryReadValueId::continuationPoint(const OpcUaByteString& continuationPoint)
	{
		continuationPoint_ = continuationPoint;
	}
	
	OpcUaByteString& 
	HistoryReadValueId::continuationPoint(void)
	{
		return continuationPoint_;
	}

	void 
	HistoryReadValueId::nodeId(const OpcUaInt16& namespaceIndex, const OpcUaInt32& identifier)
	{
		nodeIdSPtr_->namespaceIndex(namespaceIndex);
		nodeIdSPtr_->nodeId(identifier);
	}
	
	void 
	HistoryReadValueId::indexRange(const std::string& value)
	{
		indexRange_.value(value);
	}

	void 
	HistoryReadValueId::dataEncoding(const OpcUaInt16& namespaceIndex, const std::string& name)
	{
		dataEncoding_ = namespaceIndex;
		dataEncoding_ = name;
	}

	void 
	HistoryReadValueId::dataEncoding(const std::string& name)
	{
		dataEncoding_ = name;
	}

	void 
	HistoryReadValueId::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeIdSPtr_->opcUaBinaryEncode(os);
		indexRange_.opcUaBinaryEncode(os);
		dataEncoding_.opcUaBinaryEncode(os);
		continuationPoint_.opcUaBinaryEncode(os);
	}
	
	void 
	HistoryReadValueId::opcUaBinaryDecode(std::istream& is)
	{
		nodeIdSPtr_->opcUaBinaryDecode(is);
		indexRange_.opcUaBinaryDecode(is);
		dataEncoding_.opcUaBinaryDecode(is);
		continuationPoint_.opcUaBinaryDecode(is);
	}

	bool
	HistoryReadValueId::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		// encode node id
		if (!nodeIdSPtr_->jsonEncode(pt, "NodeId")) {
			Log(Error, "HistoryReadValueId json encode error")
				.parameter("Element", "NodeId");
			return false;
		}

		// encode index range
		if (indexRange_.exist()) {
			if (!indexRange_.jsonEncode(pt, "IndexRange")) {
				Log(Error, "HistoryReadValueId json encode error")
					.parameter("Element", "IndexRange");
				return false;
			}
		}

		// encode data encoding
		if (dataEncoding_.namespaceIndex() != 0 || const_cast<OpcUaQualifiedName*>(&dataEncoding_)->name().exist()) {
			if (!dataEncoding_.jsonEncode(pt, "DataEncoding")) {
				Log(Error, "HistoryReadValueId json encode error")
					.parameter("Element", "DataEncoding");
				return false;
			}
		}

		// encode continuation point
		if (continuationPoint_.exist()) {
			if (!continuationPoint_.jsonEncode(pt, "ContinuationPoint")) {
				Log(Error, "HistoryReadValueId json encode error")
					.parameter("Element", "ContinuationPoint");
				return false;
			}
		}

		return true;
	}

	bool
	HistoryReadValueId::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		// decode node id
		if (!nodeIdSPtr_->jsonDecode(pt, "NodeId")) {
			Log(Error, "HistoryReadValueId json decode error")
			    .parameter("Element", "NodeId");
			return false;
		}

		// decode index range
		indexRange_ = "";
		auto indexRange = pt.get_child_optional("IndexRange");
		if (indexRange) {
			if (!indexRange_.jsonDecode(*indexRange)) {
				Log(Error, "HistoryReadValueId json decode error")
				    .parameter("Element", "IndexRange");
				return false;
			}
		}

		// decode data encoding
		dataEncoding_ = "";
		auto dataEncoding = pt.get_child_optional("DataEncoding");
		if (dataEncoding) {
			if (!dataEncoding_.jsonDecode(pt, "DataEncoding")) {
				Log(Error, "HistoryReadValueId json decode error")
				    .parameter("Element", "DataEncoding");
				return false;
			}
		}

		// decode continuation point
		auto continuationPoint = pt.get_child_optional("ContinuationPoint");
		if (continuationPoint) {
			if (!continuationPoint_.jsonDecode(pt, "ContinuationPoint")) {
				Log(Error, "HistoryReadValueId json decode error")
				    .parameter("Element", "ContinuationPoint");
				return false;
			}
		}

		return true;
	}

}
