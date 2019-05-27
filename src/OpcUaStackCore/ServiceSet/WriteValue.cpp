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
		nodeIdSPtr_ = constructSPtr<OpcUaNodeId>();
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

	void 
	WriteValue::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		indexRange_.opcUaBinaryEncode(os);
		dataValue_.opcUaBinaryEncode(os);
	}
	
	void 
	WriteValue::opcUaBinaryDecode(std::istream& is)
	{
		nodeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		indexRange_.opcUaBinaryDecode(is);
		dataValue_.opcUaBinaryDecode(is);
	}

	bool
	WriteValue::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		// encode node id
		if (!nodeIdSPtr_->jsonEncode(pt, "NodeId")) {
			Log(Error, "WriteValue json encode error")
				.parameter("Element", "NodeId");
			return false;
		}

		// encode attribute id
		if (attributeId_ != AttributeId_Value) {
			if (!JsonNumber::jsonEncode(pt, attributeId_, "AttributeId")) {
				Log(Error, "WriteValue json encode error")
					.parameter("Element", "AttributeId");
				return false;
			}
		}

		// encode index range
		if (indexRange_.exist()) {
			if (!indexRange_.jsonEncode(pt, "IndexRange")) {
				Log(Error, "WriteValue json encode error")
					.parameter("Element", "IndexRange");
				return false;
			}
		}

		// encode data value
		if (!dataValue_.jsonEncode(pt, "Value")) {
			Log(Error, "WriteValue json encode error")
				.parameter("Element", "Value");
			return false;
		}
	}

	bool
	WriteValue::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		// decode node id
		if (!nodeIdSPtr_->jsonDecode(pt, "NodeId")) {
			Log(Error, "WriteValue json decode error")
			    .parameter("Element", "NodeId");
			return false;
		}

		// decode attribute id
		if (!JsonNumber::jsonDecode(pt, attributeId_, "AttributeId")) {
			attributeId_ = AttributeId_Value;
		}

		// decode index range
		indexRange_ = "";
		auto indexRange = pt.get_child_optional("IndexRange");
		if (indexRange) {
			if (!indexRange_.jsonDecode(*indexRange)) {
				return false;
			}
		}

		// decode data value
		if (!dataValue_.jsonDecode(pt, "Value")) {
			Log(Error, "WriteValue json decode error")
			    .parameter("Element", "Value");
			return false;
		}

		return true;
	}
}
