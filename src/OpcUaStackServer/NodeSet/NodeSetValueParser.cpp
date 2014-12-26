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

		if (locale) {
			destValue->locale(*locale);
		}
		else {
			destValue->locale("");
		}

		if (text) {
			destValue->text(*text);
		}
		else {
			destValue->text("");
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
		if (xmls != "") {
			xmls_.append(":");
		}

		bool rc = false;
		std::string dataTypeString;

		switch (opcUaVariant.variantType())
		{
			case OpcUaBuildInType_OpcUaBoolean:
			{
				dataTypeString = "OpcUaBoolean";
				rc = encode<OpcUaBoolean>(ptree, opcUaVariant, "Boolean");
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
#if 0
		OpcUaBuildInType_OpcUaSByte = 2,
		OpcUaBuildInType_OpcUaByte = 3,
		OpcUaBuildInType_OpcUaInt16 = 4,
		OpcUaBuildInType_OpcUaUInt16 = 5,
		OpcUaBuildInType_OpcUaInt32 = 6,
		OpcUaBuildInType_OpcUaUInt32 = 7,
		OpcUaBuildInType_OpcUaInt64 = 8,
		OpcUaBuildInType_OpcUaUInt64 = 9,
		OpcUaBuildInType_OpcUaFloat = 10,
		OpcUaBuildInType_OpcUaDouble = 11,
		OpcUaBuildInType_OpcUaString = 12,
		OpcUaBuildInType_OpcUaDateTime = 13,
		OpcUaBuildInType_OpcUaGuid = 14,
		OpcUaBuildInType_OpcUaByteString = 15,
		OpcUaBuildInType_OpcUaXmlElement = 16,
		OpcUaBuildInType_OpcUaNodeId = 17,
		OpcUaBuildInType_OpcUaExpandedNodeId = 18,
		OpcUaBuildInType_OpcUaStatusCode = 19,
		OpcUaBuildInType_OpcUaQualifiedName = 20,
		OpcUaBuildInType_OpcUaLocalizedText = 21,
		OpcUaBuildInType_OpcUaExtensionObject = 22,
		OpcUaBuildInType_OpcUaDataValue = 23,
		OpcUaBuildInType_OpcUaVariant = 24,
		OpcUaBuildInType_OpcUaDiagnosticInfo = 25
#endif
		}

		if (!rc) {
			Log(Warning, "encode value error")
				.parameter("DataType", dataTypeString)
				.parameter("NodeId", nodeId);
		}

		return true;
	}

#if 0
			xmls_ = xmls;

		// Test whether the value tag exist. If not exit function
		boost::optional<boost::property_tree::ptree&> ptreeValue = ptree.get_child_optional("Value");
		if (!ptreeValue) return false;
		if (ptreeValue->begin() == ptreeValue->end()) return false;

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
			default:
			{
				Log(Error, "data type unknown in node set value parser")
					.parameter("DataType", dataTypeString);
				return false;
			}
		}

		if (!rc) {
			Log(Warning, "parse value error")
				.parameter("DataType", dataTypeString)
				.parameter("NodeId", nodeId);
		}

		return rc;
#endif

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

}