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

#include <boost/date_time/date_facet.hpp>
#include <locale>
#include "OpcUaStackServer/NodeSet/NodeSetValueParser.h"
#include "OpcUaStackCore/Base/Log.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// DataTypeElement
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	DataTypeElement::DataTypeElement(void)
	: buildInType_(OpcUaBuildInType_Unknown)
	, isArray_(true)
	{
	}

	DataTypeElement::DataTypeElement(OpcUaBuildInType buildInType, bool isArray)
	: buildInType_(buildInType)
	, isArray_(isArray)
	{
	}

	DataTypeElement::~DataTypeElement(void)
	{
	}

	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// NodeSetParser
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	NodeSetValueParser::DataTypeElementMap NodeSetValueParser::dataTypeElementMap_;
	bool NodeSetValueParser::initial_ = false;

	NodeSetValueParser::NodeSetValueParser(void)
	: xmls_("")
	{
		start();
	}

	NodeSetValueParser::~NodeSetValueParser(void)
	{
	}

	void 
	NodeSetValueParser::insertDataTypeElement(const std::string& elementName, const DataTypeElement& dataTypeELement)
	{
		dataTypeElementMap_.insert(std::make_pair(elementName, dataTypeELement));
	}

	bool 
	NodeSetValueParser::findDataTypeElement(const std::string& elementName, DataTypeElement& dataTypeElement)
	{
		DataTypeElementMap::iterator it;
		it = dataTypeElementMap_.find(elementName);  
		if (it == dataTypeElementMap_.end()) return false;
		dataTypeElement = it->second;
		return true;
	}

	void
	NodeSetValueParser::start(void)
	{
		if (initial_) return;
		initial_ = true;

		// decode elements
		insertDataTypeElement("Boolean", DataTypeElement(OpcUaBuildInType_OpcUaBoolean, false));
		insertDataTypeElement("ListOfBoolean", DataTypeElement(OpcUaBuildInType_OpcUaBoolean, true));
		insertDataTypeElement("SByte", DataTypeElement(OpcUaBuildInType_OpcUaSByte, false));
		insertDataTypeElement("ListOfSByte", DataTypeElement(OpcUaBuildInType_OpcUaSByte, true));
		insertDataTypeElement("Byte", DataTypeElement(OpcUaBuildInType_OpcUaByte, false));
		insertDataTypeElement("ListOfByte", DataTypeElement(OpcUaBuildInType_OpcUaByte, true));
		insertDataTypeElement("Int16", DataTypeElement(OpcUaBuildInType_OpcUaInt16, false));
		insertDataTypeElement("ListOfInt16", DataTypeElement(OpcUaBuildInType_OpcUaInt16, true));
		insertDataTypeElement("UInt16", DataTypeElement(OpcUaBuildInType_OpcUaUInt16, false));
		insertDataTypeElement("ListOfUInt16", DataTypeElement(OpcUaBuildInType_OpcUaUInt16, true));
		insertDataTypeElement("Int32", DataTypeElement(OpcUaBuildInType_OpcUaInt32, false));
		insertDataTypeElement("ListOfInt32", DataTypeElement(OpcUaBuildInType_OpcUaInt32, true));
		insertDataTypeElement("UInt32", DataTypeElement(OpcUaBuildInType_OpcUaUInt32, false));
		insertDataTypeElement("ListOfUInt32", DataTypeElement(OpcUaBuildInType_OpcUaUInt32, true));
		insertDataTypeElement("Int64", DataTypeElement(OpcUaBuildInType_OpcUaInt64, false));
		insertDataTypeElement("ListOfInt64", DataTypeElement(OpcUaBuildInType_OpcUaInt64, true));
		insertDataTypeElement("UInt64", DataTypeElement(OpcUaBuildInType_OpcUaUInt64, false));
		insertDataTypeElement("ListOfUInt64", DataTypeElement(OpcUaBuildInType_OpcUaUInt64, true));
		insertDataTypeElement("Float", DataTypeElement(OpcUaBuildInType_OpcUaFloat, false));
		insertDataTypeElement("ListOfFloat", DataTypeElement(OpcUaBuildInType_OpcUaFloat, true));
		insertDataTypeElement("Double", DataTypeElement(OpcUaBuildInType_OpcUaDouble, false));
		insertDataTypeElement("ListOfDouble", DataTypeElement(OpcUaBuildInType_OpcUaDouble, true));
		insertDataTypeElement("String", DataTypeElement(OpcUaBuildInType_OpcUaString, false));
		insertDataTypeElement("ListOfString", DataTypeElement(OpcUaBuildInType_OpcUaString, true));
		insertDataTypeElement("ByteString", DataTypeElement(OpcUaBuildInType_OpcUaByteString, false));
		insertDataTypeElement("ListOfByteString", DataTypeElement(OpcUaBuildInType_OpcUaByteString, true));
		insertDataTypeElement("LocalizedText", DataTypeElement(OpcUaBuildInType_OpcUaLocalizedText, false));
		insertDataTypeElement("ListOfLocalizedText", DataTypeElement(OpcUaBuildInType_OpcUaLocalizedText, true));
		insertDataTypeElement("DateTime", DataTypeElement(OpcUaBuildInType_OpcUaDateTime, false));
		insertDataTypeElement("ListOfDateTime", DataTypeElement(OpcUaBuildInType_OpcUaDateTime, true));
		insertDataTypeElement("Guid", DataTypeElement(OpcUaBuildInType_OpcUaGuid, false));
		insertDataTypeElement("ListOfGuid", DataTypeElement(OpcUaBuildInType_OpcUaGuid, true));
		insertDataTypeElement("NodeId", DataTypeElement(OpcUaBuildInType_OpcUaNodeId, false));
		insertDataTypeElement("ListOfNodeId", DataTypeElement(OpcUaBuildInType_OpcUaNodeId, true));
		insertDataTypeElement("QualifiedName", DataTypeElement(OpcUaBuildInType_OpcUaQualifiedName, false));
		insertDataTypeElement("ListOfQualifiedName", DataTypeElement(OpcUaBuildInType_OpcUaQualifiedName, true));
		insertDataTypeElement("ExtensionObject", DataTypeElement(OpcUaBuildInType_OpcUaExtensionObject, false));
		insertDataTypeElement("ListOfExtensionObject", DataTypeElement(OpcUaBuildInType_OpcUaExtensionObject, true));
	}


	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// decode value
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	bool 
	NodeSetValueParser::decodeValue(const std::string& nodeId, boost::property_tree::ptree& ptree, OpcUaVariant& variant, const std::string& xmls)
	{
		xmls_ = xmls;

		// Test whether the value tag exist. If not exit function
		boost::optional<boost::property_tree::ptree&> ptreeValue = ptree.get_child_optional("Value");
		if (!ptreeValue) return false;
		if (ptreeValue->begin() == ptreeValue->end()) return false;

		// xmlns="http://opcfoundation.org/UA/2008/02/Types.xsd"
		boost::optional<std::string> xmlSchema = ptreeValue->front().second.get_optional<std::string>("<xmlattr>.xmlns");
		if (xmlSchema) {
			if (*xmlSchema == "http://opcfoundation.org/UA/2008/02/Types.xsd") {
				xmls_ = "";
			}
		}

		// Test whether the data type of the value exist in data type element list. If not exit function
		std::string dataTypeString = cutxmls(ptreeValue->front().first);
		DataTypeElement dataTypeElement;
		if (!findDataTypeElement(dataTypeString, dataTypeElement)) {
			Log(Warning, "data type unknown in node set value parser")
				.parameter("DataType", dataTypeString)
				.parameter("NodeId", nodeId);
			return false;
		}

		// execute decoder function depending on the variable type
		bool rc;
		switch (dataTypeElement.buildInType_)
		{
			case OpcUaBuildInType_OpcUaBoolean: rc = decode<OpcUaBoolean>(dataTypeElement, *ptreeValue, variant, "Boolean"); break;
			case OpcUaBuildInType_OpcUaSByte: rc = decode<OpcUaSByte>(dataTypeElement, *ptreeValue, variant, "SByte"); break;
			case OpcUaBuildInType_OpcUaByte: rc = decode<OpcUaByte>(dataTypeElement, *ptreeValue, variant, "Byte"); break;
			case OpcUaBuildInType_OpcUaUInt16: rc = decode<OpcUaUInt16>(dataTypeElement, *ptreeValue, variant, "UInt16"); break;
			case OpcUaBuildInType_OpcUaInt16: rc = decode<OpcUaInt16>(dataTypeElement, *ptreeValue, variant, "Int16"); break;
			case OpcUaBuildInType_OpcUaUInt32: rc = decode<OpcUaUInt32>(dataTypeElement, *ptreeValue, variant, "UInt32"); break;
			case OpcUaBuildInType_OpcUaInt32: rc = decode<OpcUaInt32>(dataTypeElement, *ptreeValue, variant, "Int32"); break;
			case OpcUaBuildInType_OpcUaUInt64: rc = decode<OpcUaUInt64>(dataTypeElement, *ptreeValue, variant, "UInt64"); break;
			case OpcUaBuildInType_OpcUaInt64: rc = decode<OpcUaInt64>(dataTypeElement, *ptreeValue, variant, "Int64"); break;
			case OpcUaBuildInType_OpcUaFloat: rc = decode<OpcUaFloat>(dataTypeElement, *ptreeValue, variant, "Float"); break;
			case OpcUaBuildInType_OpcUaDouble: rc = decode<OpcUaDouble>(dataTypeElement, *ptreeValue, variant, "Double"); break;
			case OpcUaBuildInType_OpcUaDateTime: rc = decode<OpcUaDateTime>(dataTypeElement, *ptreeValue, variant, "DateTime"); break;
			case OpcUaBuildInType_OpcUaString: rc = decodeSPtr<OpcUaString>(dataTypeElement, *ptreeValue, variant, "String"); break;
			case OpcUaBuildInType_OpcUaByteString: rc = decodeSPtr<OpcUaByteString>(dataTypeElement, *ptreeValue, variant, "ByteString"); break;
			case OpcUaBuildInType_OpcUaLocalizedText: rc = decodeSPtr<OpcUaLocalizedText>(dataTypeElement, *ptreeValue, variant, "LocalizedText"); break;
			case OpcUaBuildInType_OpcUaGuid: rc = decodeSPtr<OpcUaGuid>(dataTypeElement, *ptreeValue, variant, "Guid"); break;
			case OpcUaBuildInType_OpcUaNodeId: rc = decodeSPtr<OpcUaNodeId>(dataTypeElement, *ptreeValue, variant, "NodeId"); break;
			case OpcUaBuildInType_OpcUaQualifiedName: rc = decodeSPtr<OpcUaQualifiedName>(dataTypeElement, *ptreeValue, variant, "QualifiedName"); break;
			case OpcUaBuildInType_OpcUaExtensionObject: rc = decodeSPtr<OpcUaExtensionObject>(dataTypeElement, *ptreeValue, variant, "ExtensionObject"); break;
			default:
			{
				Log(Error, "data type unknown in node set value decoder")
					.parameter("NodeId", nodeId)
					.parameter("DataType", dataTypeString);
				return false;
			}
		}

		if (!rc) {
			Log(Warning, "decode value error")
				.parameter("NodeId", nodeId)
				.parameter("DataType", dataTypeString);
		}

		return rc;
	}

	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaBoolean& destValue, const std::string& tag)
	{
		std::string sourceValue = ptree.get_value<std::string>();
		if (sourceValue == "true") destValue = true;
		else destValue = false;
		return true;
	}

	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaByte& destValue, const std::string& tag)
	{
		std::string sourceValue = ptree.get_value<std::string>();
		try {
			destValue = (OpcUaByte)boost::lexical_cast<OpcUaUInt16>(sourceValue);
		} catch(boost::bad_lexical_cast& e) {
			Log(Error, "bad_lexical_cast in decode")
				.parameter("Tag", tag)
				.parameter("SourceValue", sourceValue)
				.parameter("What", e.what());
			return false;
		}
		return true;
	}
		
	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaSByte& destValue, const std::string& tag)
	{
		std::string sourceValue = ptree.get_value<std::string>();
		try {
			destValue = (OpcUaSByte)boost::lexical_cast<OpcUaInt16>(sourceValue);
		} catch(boost::bad_lexical_cast& e) {
			Log(Error, "bad_lexical_cast in decode")
				.parameter("Tag", tag)
				.parameter("SourceValue", sourceValue)
				.parameter("What", e.what());
			return false;
		}
		return true;
	}

	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaDateTime& destValue, const std::string& tag)
	{
		std::string sourceValue = ptree.get_value<std::string>();
		if (sourceValue.empty()) {
			Log(Error, "time format error")
				.parameter("Tag", tag)
				.parameter("SourceValue", sourceValue);
			return false;
		}

		return destValue.fromISOString(sourceValue);
	}

	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaString::SPtr destValue, const std::string& tag)
	{
		std::string sourceValue = ptree.get_value<std::string>();
		destValue->value(sourceValue);
		return true;
	}

	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaByteString::SPtr destValue, const std::string& tag)
	{
		std::string sourceValue = ptree.get_value<std::string>();
		destValue->value(sourceValue.c_str(), sourceValue.length()); 
		return true;
	}
	
	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaLocalizedText::SPtr destValue, const std::string& tag)
	{
		boost::optional<std::string> locale = ptree.get_optional<std::string>(addxmls("Locale"));
		boost::optional<std::string> text = ptree.get_optional<std::string>(addxmls("Text"));

		if (!locale) {
			destValue->locale("");

		}
		else {
			destValue->locale(*locale);
		}

		if (!text) {
			destValue->text("");
		}
		else {
			destValue->text(*text);
		}

		return true;
	}

	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaGuid::SPtr destValue, const std::string& tag)
	{
		boost::optional<std::string> sourceValue = ptree.get_optional<std::string>(addxmls("String"));
		
		if (!sourceValue) {
			Log(Error, "value empty")
				.parameter("Tag", tag)
				.parameter("SourceValue", sourceValue);
			return false;
		}
		*destValue = *sourceValue;
		return true;
	}

	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaNodeId::SPtr destValue, const std::string& tag)
	{
		boost::optional<std::string> sourceValue = ptree.get_optional<std::string>(addxmls("Identifier"));
		if (!sourceValue) {
			Log(Error, "value empty")
				.parameter("Tag", addxmls("Identifier"));
			return false;
		}

		std::string s = *sourceValue;
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
		bool rc = destValue->fromString(s);
		if (!rc) {
			Log(Error, "value format error")
				.parameter("Tag", "uax:Identifier")
				.parameter("SourceValue", s);
		}
		return rc;
	}

	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaQualifiedName::SPtr destValue, const std::string& tag)
	{
		boost::optional<std::string> namespaceIndex = ptree.get_optional<std::string>(addxmls("NamespaceIndex"));
		if (namespaceIndex) {
			try {
				OpcUaUInt16 ns = boost::lexical_cast<OpcUaInt16>(*namespaceIndex);
				destValue->namespaceIndex(ns);
			} catch(boost::bad_lexical_cast& e) {
				Log(Error, "bad_lexical_cast in decode")
					.parameter("Tag", tag)
					.parameter("SourceValue", *namespaceIndex)
					.parameter("What", e.what());
				return false;
			}
		}

		boost::optional<std::string> name = ptree.get_optional<std::string>(addxmls("Name"));
		if (name) {
			destValue->name(*name);
		}

		return true;
	}

	bool
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaExtensionObject::SPtr destValue, const std::string& tag)
	{
		Xmlns xmlns;
		xmlns.xmlns("uax");
		if (!destValue->decode(ptree, xmlns)) {
			Log(Error, "invalid value in decode")
				.parameter("Tag", tag);
			return false;
		}
		//destValue->out(std::cout); std::cout << std::endl;
		return true;
	}

	std::string
	NodeSetValueParser::cutxmls(const std::string& tag)
	{
		std::string newTag = tag;
		size_t pos = newTag.find(":");
		if (pos != std::string::npos) {
			newTag = newTag.substr(pos+1);
		}
		return newTag;
	}

	std::string 
	NodeSetValueParser::addxmls(const std::string& tag)
	{
		if (xmls_ == "") return tag;
		return xmls_ + std::string(":") + tag;
	}


	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	//
	// encode value
	//
	// ---------------------------------------------------------------------------
	// ---------------------------------------------------------------------------
	bool 
	NodeSetValueParser::encodeValue(const std::string& nodeId, boost::property_tree::ptree& ptree, OpcUaVariant& opcUaVariant, const std::string& xmls)
	{
		xmls_ = xmls;

		bool rc = false;
		std::string dataTypeString;

		switch (opcUaVariant.variantType())
		{
			case OpcUaBuildInType_OpcUaBoolean:
			{
				dataTypeString = "Boolean";
				rc = encode<OpcUaBoolean>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaSByte:
			{
				dataTypeString = "SByte";
				rc = encode<OpcUaSByte>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaByte:
			{
				dataTypeString = "Byte";
				rc = encode<OpcUaByte>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaInt16:
			{
				dataTypeString = "Int16";
				rc = encode<OpcUaInt16>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaUInt16:
			{
				dataTypeString = "UInt16";
				rc = encode<OpcUaUInt16>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaInt32:
			{
				dataTypeString = "Int32";
				rc = encode<OpcUaInt32>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaUInt32:
			{
				dataTypeString = "UInt32";
				rc = encode<OpcUaUInt32>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaInt64:
			{
				dataTypeString = "Int64";
				rc = encode<OpcUaInt64>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaUInt64:
			{
				dataTypeString = "UInt64";
				rc = encode<OpcUaUInt64>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaFloat:
			{
				dataTypeString = "Float";
				rc = encode<OpcUaFloat>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaDouble:
			{
				dataTypeString = "Double";
				rc = encode<OpcUaDouble>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaDateTime:
			{
				dataTypeString = "DateTime";
				rc = encode<OpcUaDateTime>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaString:
			{
				dataTypeString = "String";
				rc = encodeSPtr<OpcUaString>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaGuid:
			{
				dataTypeString = "Guid";
				rc = encodeSPtr<OpcUaGuid>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaByteString:
			{
				dataTypeString = "ByteString";
				rc = encodeSPtr<OpcUaByteString>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaNodeId:
			{
				dataTypeString = "NodeId";
				rc = encodeSPtr<OpcUaNodeId>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaQualifiedName:
			{
				dataTypeString = "QualifiedName";
				rc = encodeSPtr<OpcUaQualifiedName>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			case OpcUaBuildInType_OpcUaLocalizedText:
			{
				dataTypeString = "LocalizedText";
				rc = encodeSPtr<OpcUaLocalizedText>(ptree, opcUaVariant, dataTypeString);
				break; 
			}
			default:
			{
				std::stringstream ss;
				ss << opcUaVariant.variantType();
				Log(Error, "data type unknown in node set value encoder")
					.parameter("NodeId", nodeId)
					.parameter("DataType", ss.str());
				return false;
			}
		}

		if (!rc) {
			Log(Warning, "encode value error")
				.parameter("DataType", dataTypeString)
				.parameter("NodeId", nodeId);
		}

		return true;
	}

	bool 
	NodeSetValueParser::encode(boost::property_tree::ptree& ptree, OpcUaBoolean& value, const std::string& tag)
	{
		if (value) {
			ptree.put(tag, "true");
		}
		else {
			ptree.put(tag, "false");
		}
		return true;
	}

	bool 
	NodeSetValueParser::encode(boost::property_tree::ptree& ptree, OpcUaByte& value, const std::string& tag)
	{
		std::stringstream ss;
		ss << (int16_t)value;
		ptree.put(tag, ss.str());
		return true;
	}
		
	bool 
	NodeSetValueParser::encode(boost::property_tree::ptree& ptree, OpcUaSByte& value, const std::string& tag)
	{
		std::stringstream ss;
		ss << (int16_t)value;
		ptree.put(tag, ss.str());
		return true;
	}

	bool 
	NodeSetValueParser::encode(boost::property_tree::ptree& ptree, OpcUaDateTime& value, const std::string& tag)
	{
		ptree.put(tag, value.toISOString());
		return true;
	}

	bool 
	NodeSetValueParser::encode(boost::property_tree::ptree& ptree, OpcUaString::SPtr value, const std::string& tag)
	{
		ptree.put(tag, value->value());
		return true;
	}

	bool 
	NodeSetValueParser::encode(boost::property_tree::ptree& ptree, OpcUaByteString::SPtr value, const std::string& tag)
	{
		OpcUaByte *data;
		OpcUaInt32 dataLen;
		value->value(&data, &dataLen);
		if (dataLen < 0) {
			ptree.put(tag, std::string(""));
			return true;
		}
		std::string byteString((char*)data, dataLen);
		ptree.put(tag, byteString);
		return true;
	}
	
	bool 
	NodeSetValueParser::encode(boost::property_tree::ptree& ptree, OpcUaLocalizedText::SPtr value, const std::string& tag)
	{
		std::string text = value->text().value();
		ptree.put(tag + std::string(".") + addxmls("Text"), text);

		std::string locale = value->locale().value();
		ptree.put(tag + std::string(".") + addxmls("Locale"), locale);
		return true;
	}

	bool 
	NodeSetValueParser::encode(boost::property_tree::ptree& ptree, OpcUaGuid::SPtr value, const std::string& tag)
	{
		std::string guidString = *value;
		std::string localTag = tag + std::string(".") + addxmls(std::string("String"));
		ptree.put(localTag, guidString);
		return true;
	}

	bool 
	NodeSetValueParser::encode(boost::property_tree::ptree& ptree, OpcUaNodeId::SPtr value, const std::string& tag)
	{
		std::string localTag = tag + std::string(".") + addxmls(std::string("Identifier"));
		ptree.put(localTag, value->toString());
		return true;
	}

	bool 
	NodeSetValueParser::encode(boost::property_tree::ptree& ptree, OpcUaQualifiedName::SPtr value, const std::string& tag)
	{
		if (value->namespaceIndex() != 0 ) {
			std::stringstream ss;
			ss << value->namespaceIndex();;
			std::string localTag = tag + std::string(".") + addxmls(std::string("NamespaceIndex"));
			ptree.put(localTag, ss.str());
		}

		std::string localTag = tag + std::string(".") + addxmls(std::string("Name"));
		ptree.put(localTag, value->name().value());
		return true;
	}

	bool
	NodeSetValueParser::encode(boost::property_tree::ptree& ptree, OpcUaExtensionObject::SPtr value, const std::string& tag)
	{
		// FIXME: todo
		return false;
	}

}
