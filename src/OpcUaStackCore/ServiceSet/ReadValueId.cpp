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

#include "OpcUaStackCore/ServiceSet/ReadValueId.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa ReadValueId
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	ReadValueId::ReadValueId(void)
	: Object()
	, nodeIdSPtr_()
	, attributeId_(AttributeId_Value)
	, indexRange_()
	, dataEncoding_()
	{
		nodeIdSPtr_ = boost::make_shared<OpcUaNodeId>();
	}

	ReadValueId::~ReadValueId(void)
	{
	}

	void 
	ReadValueId::nodeId(const OpcUaNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}

	OpcUaNodeId::SPtr
	ReadValueId::nodeId(void)
	{
		return nodeIdSPtr_;
	}
		
	void 
	ReadValueId::attributeId(const OpcUaUInt32& attributeId)
	{
		attributeId_ = attributeId;
	}

	OpcUaUInt32 
	ReadValueId::attributeId(void) const
	{
		return attributeId_;
	}

	void 
	ReadValueId::indexRange(const OpcUaString& indexRange)
	{
		indexRange_ = indexRange;
	}

	std::string 
	ReadValueId::indexRange(void) const
	{
		return indexRange_.value();
	}
	
	void 
	ReadValueId::dataEncoding(const OpcUaQualifiedName& dataEncoding)
	{
		dataEncoding_ = dataEncoding;
	}
	
	OpcUaQualifiedName&
	ReadValueId::dataEncoding(void)
	{
		return dataEncoding_;
	}


	void 
	ReadValueId::nodeId(const OpcUaInt16& namespaceIndex, const OpcUaInt32& identifier)
	{
		nodeIdSPtr_->namespaceIndex(namespaceIndex);
		nodeIdSPtr_->nodeId(identifier);
	}
	
	void 
	ReadValueId::indexRange(const std::string& value)
	{
		indexRange_.value(value);
	}

	void 
	ReadValueId::dataEncoding(const OpcUaInt16& namespaceIndex, const std::string& name)
	{
		dataEncoding_ = namespaceIndex;
		dataEncoding_ = name;
	}

	void 
	ReadValueId::dataEncoding(const std::string& name)
	{
		dataEncoding_ = name;
	}

	void
	ReadValueId::copyTo(ReadValueId& readValueId)
	{
		nodeIdSPtr_->copyTo(*readValueId.nodeId().get());
		readValueId.attributeId(attributeId_);
		OpcUaString indexRange;
		indexRange_.copyTo(indexRange);
		readValueId.indexRange(indexRange);
		dataEncoding_.copyTo(readValueId.dataEncoding());
	}

	bool
	ReadValueId::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= nodeIdSPtr_->opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		rc &= indexRange_.opcUaBinaryEncode(os);
		rc &= dataEncoding_.opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	ReadValueId::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= nodeIdSPtr_->opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		rc &= indexRange_.opcUaBinaryDecode(is);
		rc &= dataEncoding_.opcUaBinaryDecode(is);

		return true;
	}

	bool
	ReadValueId::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc = true;
		rc = rc & jsonObjectSPtrEncode(pt, nodeIdSPtr_, "NodeId");
		rc = rc & jsonNumberEncode(pt, attributeId_, "AttributeId", true, (OpcUaInt32)13);
		rc = rc & jsonObjectEncode(pt, indexRange_, "IndexRange", true);
		rc = rc & jsonObjectEncode(pt, dataEncoding_, "DataEncoding", true);
		return rc;
	}

	bool
	ReadValueId::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		bool rc = true;
		rc = rc & jsonObjectSPtrDecode(pt, nodeIdSPtr_, "NodeId");
		rc = rc & jsonNumberDecode(pt, attributeId_, "AttributeId", true, (OpcUaInt32)13);
		rc = rc & jsonObjectDecode(pt, indexRange_, "IndexRange", true);
		rc = rc & jsonObjectDecode(pt, dataEncoding_, "DataEncoding", true);
		return rc;
	}

}
