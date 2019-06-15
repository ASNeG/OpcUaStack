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
		bool rc = true;
		rc = rc & jsonObjectSPtrEncode(pt, nodeIdSPtr_, "NodeId");
		rc = rc & jsonObjectEncode(pt, indexRange_, "IndexRange", true);
		if (dataEncoding_.namespaceIndex() != 0 || const_cast<OpcUaQualifiedName*>(&dataEncoding_)->name().exist()) {
			rc = rc & jsonObjectEncode(pt, dataEncoding_, "DataEncoding", true);
		}
		rc = rc & jsonObjectEncode(pt, continuationPoint_, "ContinuationPoint", true);
		return rc;
	}

	bool
	HistoryReadValueId::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		bool rc = true;
		rc = rc & jsonObjectSPtrDecode(pt, nodeIdSPtr_, "NodeId");
		rc = rc & jsonObjectDecode(pt, indexRange_, "IndexRange", true);
		rc = rc & jsonObjectDecode(pt, dataEncoding_, "DataEncoding", true);
		rc = rc & jsonObjectDecode(pt, continuationPoint_, "ContinuationPoint", true);
		return rc;
	}

}
