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
	}

	bool 
	NodeSetValueParser::decodeValue(const std::string& nodeId, boost::property_tree::ptree& ptree, OpcUaVariant& variant)
	{
		boost::optional<boost::property_tree::ptree&> ptreeValue = ptree.get_child_optional("Value");
		if (!ptreeValue) return false;
		if (ptreeValue->size() != 1) return false;

		std::string dataTypeString = cutxmls(ptreeValue->front().first);
		DataTypeElement dataTypeElement;
		if (!findDataTypeElement(dataTypeString, dataTypeElement)) {
			Log(Warning, "data type unknown in node set value parser")
				.parameter("DataType", dataTypeString)
				.parameter("NodeId", nodeId);
			return false;
		}

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
			case OpcUaBuildInType_OpcUaString: rc = decodeSPtr<OpcUaString>(dataTypeElement, *ptreeValue, variant, "String"); break;
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

	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaString::SPtr destValue, const std::string& tag)
	{
		std::string sourceValue = ptree.get_value<std::string>();
		destValue->value(sourceValue);
		return true;
	}

}