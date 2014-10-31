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
	NodeSetValueParser::insertDataTypeElement(const std::string& elementName, DataTypeElement& dataTypeELement)
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

		insertDataTypeElement("Int32", DataTypeElement(OpcUaBuildInType_OpcUaInt32, false));
		insertDataTypeElement("ListOfInt32", DataTypeElement(OpcUaBuildInType_OpcUaInt32, true));
		insertDataTypeElement("UInt32", DataTypeElement(OpcUaBuildInType_OpcUaUInt32, false));
		insertDataTypeElement("ListOfUInt32", DataTypeElement(OpcUaBuildInType_OpcUaUInt32, true));
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
			case OpcUaBuildInType_OpcUaUInt32: rc = decode(dataTypeElement, *ptreeValue, variant); break;
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
	NodeSetValueParser::decode(DataTypeElement& dataTypeElement, boost::property_tree::ptree& ptreeValue, OpcUaVariant& variant)
	{
		bool rc;
		if (dataTypeElement.isArray_) {
			OpcUaVariantValue::Vec variantValueVec;
			rc = decode(ptreeValue.front().second, variantValueVec);
			if (rc) variant.variant(variantValueVec);
		}
		else {
			OpcUaUInt32 uint32;
			rc = decode(ptreeValue.front().second, uint32);
			if (rc) variant.variant(uint32);
		}
		return rc;
	}

	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaUInt32& uint32)
	{
		std::string value = ptree.get_value<std::string>();
		try {
			uint32 = boost::lexical_cast<OpcUaUInt32>(value);
		} catch(boost::bad_lexical_cast &) {
			Log(Error, "bad_lexical_cast in decodeUInt32");
			return false;
		}
		return true;
	}

	bool 
	NodeSetValueParser::decode(boost::property_tree::ptree& ptree, OpcUaVariantValue::Vec& variantValueVec)
	{
		if (ptree.size() == 0) return false;

		boost::property_tree::ptree::iterator it;
		for (it = ptree.begin(); it!=ptree.end(); it++) {
			std::string tag = cutxmls(it->first);
			if (tag != "UInt32") return false;

			OpcUaUInt32 uint32;
			if (!decode(it->second, uint32)) return false;
			
			OpcUaVariantValue variantValue;
			variantValue.variant(uint32);
			variantValueVec.push_back(variantValue);
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

}

#if 0
	<Value>
      <uax:UInt32>123</uax:UInt32>
    </Value>

	       <Value>
            <uax:ListOfUInt32>
                <uax:UInt32>1</uax:UInt32>
                <uax:UInt32>2</uax:UInt32>
                <uax:UInt32>3</uax:UInt32>
            </uax:ListOfUInt32>
        </Value>


#endif