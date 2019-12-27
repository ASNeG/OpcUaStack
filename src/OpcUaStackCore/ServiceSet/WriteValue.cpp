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

#include "OpcUaStackCore/ServiceSet/WriteValue.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaAttributeId.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa WriteValue
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	WriteValue::WriteValue(void)
	: Object()
	, nodeIdSPtr_()
	, attributeId_()
	, indexRange_()
	, dataValue_()
	{
		nodeIdSPtr_ = boost::make_shared<OpcUaNodeId>();
	}

	WriteValue::~WriteValue(void)
	{
	}


	void 
	WriteValue::nodeId(const OpcUaNodeId::SPtr nodeId)
	{
		nodeIdSPtr_ = nodeId;
	}


	OpcUaNodeId::SPtr
	WriteValue::nodeId(void)
	{
		return nodeIdSPtr_;
	}
		
	void 
	WriteValue::attributeId(const OpcUaUInt32& attributeId)
	{
		attributeId_ = attributeId;
	}

	OpcUaUInt32 
	WriteValue::attributeId(void) const
	{
		return attributeId_;
	}

	void 
	WriteValue::indexRange(const std::string& indexRange)
	{
		indexRange_.value(indexRange);
	}

	std::string 
	WriteValue::indexRange(void) const
	{
		return indexRange_.value();
	}
	
	void
	WriteValue::dataValue(const OpcUaDataValue& dataValue)
	{
		dataValue_ = dataValue;
	}

	OpcUaDataValue& 
	WriteValue::dataValue(void)
	{
		return dataValue_;
	}

	void 
	WriteValue::nodeId(const OpcUaInt16& namespaceIndex, const OpcUaInt32& identifier)
	{
		nodeIdSPtr_->namespaceIndex(namespaceIndex);
		nodeIdSPtr_->nodeId(identifier);
	}

	bool
	WriteValue::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= nodeIdSPtr_->opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		rc &= indexRange_.opcUaBinaryEncode(os);
		rc &= dataValue_.opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	WriteValue::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= nodeIdSPtr_->opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		rc &= indexRange_.opcUaBinaryDecode(is);
		rc &= dataValue_.opcUaBinaryDecode(is);

		return rc;
	}

	bool
	WriteValue::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc = true;
		rc = rc & jsonObjectSPtrEncode(pt, nodeIdSPtr_, "NodeId");
		rc = rc & jsonNumberEncode(pt, attributeId_, "AttributeId", true, (OpcUaInt32)AttributeId_Value);
		rc = rc & jsonObjectEncode(pt, indexRange_, "IndexRange", true);
		rc = rc & jsonObjectEncode(pt, dataValue_, "Value");
		return rc;
	}

	bool
	WriteValue::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		bool rc = true;
		rc = rc & jsonObjectSPtrDecode(pt, nodeIdSPtr_, "NodeId");
		rc = rc & jsonNumberDecode(pt, attributeId_, "AttributeId", true, (OpcUaInt32)AttributeId_Value);
		rc = rc & jsonObjectDecode(pt, indexRange_, "IndexRange", true);
		rc = rc & jsonObjectDecode(pt, dataValue_, "Value");
		return rc;
	}
}
