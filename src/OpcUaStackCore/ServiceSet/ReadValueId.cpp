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
		nodeIdSPtr_ = constructSPtr<OpcUaNodeId>();
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
	ReadValueId::opcUaBinaryEncode(std::ostream& os) const
	{
		nodeIdSPtr_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, attributeId_);
		indexRange_.opcUaBinaryEncode(os);
		dataEncoding_.opcUaBinaryEncode(os);
	}
	
	void 
	ReadValueId::opcUaBinaryDecode(std::istream& is)
	{
		nodeIdSPtr_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, attributeId_);
		indexRange_.opcUaBinaryDecode(is);
		dataEncoding_.opcUaBinaryDecode(is);
	}

	bool
	ReadValueId::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::property_tree::ptree elementTree;
		if (!jsonEncode(elementTree)) {
			Log(Error, "ReadValueId json encoder error")
				.parameter("Element", element);
			return false;
		}
		pt.push_back(std::make_pair(element, elementTree));
		return true;
	}

	bool
	ReadValueId::jsonEncode(boost::property_tree::ptree& pt)
	{
		// encode node id
		if (!nodeIdSPtr_->jsonEncode(pt, "NodeId")) {
			Log(Error, "ReadValueId json encode error")
				.parameter("Element", "NodeId");
			return false;
		}

		// encode attribute id
		if (attributeId_ != AttributeId_Value) {
			if (!JsonNumber::jsonEncode(pt, attributeId_, "AttributeId")) {
				Log(Error, "ReadValueId json encode error")
					.parameter("Element", "AttributeId");
				return false;
			}
		}

		// encode index range
		if (indexRange_.exist()) {
			if (!indexRange_.jsonEncode(pt, "IndexRange")) {
				Log(Error, "ReadValueId json encode error")
					.parameter("Element", "IndexRange");
				return false;
			}
		}

		// encode data encoding
		if (dataEncoding_.namespaceIndex() != 0 || dataEncoding_.name().exist()) {
			if (!dataEncoding_.jsonEncode(pt, "DataEncoding")) {
				Log(Error, "ReadValueId json encode error")
					.parameter("Element", "DataEncoding");
				return false;
			}
		}

		return true;
	}

	bool
	ReadValueId::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
	{
		boost::optional<boost::property_tree::ptree&> tmpTree;

		tmpTree = pt.get_child_optional(element);
		if (!tmpTree) {
			Log(Error, "ReadValueId json decoder error")
				.parameter("Element", element);
				return false;
		}
		return jsonDecode(*tmpTree);
	}

	bool
	ReadValueId::jsonDecode(boost::property_tree::ptree& pt)
	{
		// decode node id
		if (!nodeIdSPtr_->jsonDecode(pt, "NodeId")) {
			Log(Error, "ReadValueId json decode error")
			    .parameter("Element", "NodeId");
			return false;
		}

		// decode attribute id
		attributeId_ = AttributeId_Value;
		auto attributeId = pt.get_child_optional("AttributeId");
		if (attributeId) {
			if (!JsonNumber::jsonDecode(pt, attributeId_, "AttributeId")) {
				attributeId_ = AttributeId_Value;
			}
		}

		// decode index range
		indexRange_ = "";
		auto indexRange = pt.get_child_optional("IndexRange");
		if (indexRange) {
			if (!indexRange_.jsonDecode(*indexRange)) {
				Log(Error, "ReadValueId json decode error")
					.parameter("Element", "IndexRange");
				return false;
			}
		}

		// decode data encoding
		dataEncoding_ = "";
		auto dataEncoding = pt.get_child_optional("DataEncoding");
		if (dataEncoding) {
			if (!dataEncoding_.jsonDecode(pt, "DataEncoding")) {
				Log(Error, "ReadValueId json decode error")
				    .parameter("Element", "DataEncoding");
				return false;
			}
		}

		return true;
	}

}
