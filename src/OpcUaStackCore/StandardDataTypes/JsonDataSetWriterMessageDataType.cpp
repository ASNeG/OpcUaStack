/*
    DataTypeClass: JsonDataSetWriterMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/JsonDataSetWriterMessageDataType.h"

namespace OpcUaStackCore
{
    
    JsonDataSetWriterMessageDataType::JsonDataSetWriterMessageDataType(void)
    : DataSetWriterMessageDataType()
    , dataSetMessageContentMask_()
    {
    }
    
    JsonDataSetWriterMessageDataType::JsonDataSetWriterMessageDataType(const JsonDataSetWriterMessageDataType& value)
    : DataSetWriterMessageDataType()
    , dataSetMessageContentMask_()
    {
        const_cast<JsonDataSetWriterMessageDataType*>(&value)->copyTo(*this);
    }
    
    JsonDataSetWriterMessageDataType::~JsonDataSetWriterMessageDataType(void)
    {
    }
    
    OpcUaJsonDataSetMessageContentMask&
    JsonDataSetWriterMessageDataType::dataSetMessageContentMask(void)
    {
        return dataSetMessageContentMask_;
    }
    
    bool
    JsonDataSetWriterMessageDataType::operator==(const JsonDataSetWriterMessageDataType& value)
    {
        JsonDataSetWriterMessageDataType* dst = const_cast<JsonDataSetWriterMessageDataType*>(&value);
        if (dataSetMessageContentMask_ != dst->dataSetMessageContentMask()) return false;
        return true;
    }
    
    bool
    JsonDataSetWriterMessageDataType::operator!=(const JsonDataSetWriterMessageDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    JsonDataSetWriterMessageDataType::copyTo(JsonDataSetWriterMessageDataType& value)
    {
        value.dataSetMessageContentMask_ = dataSetMessageContentMask_;
    }
    
    JsonDataSetWriterMessageDataType&
    JsonDataSetWriterMessageDataType::operator=(const JsonDataSetWriterMessageDataType& value)
    {
        const_cast<JsonDataSetWriterMessageDataType*>(&value)->copyTo(*this);
        return *this;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    JsonDataSetWriterMessageDataType::factory(void)
    {
    	return constructSPtr<JsonDataSetWriterMessageDataType>();
    }
    
    std::string
    JsonDataSetWriterMessageDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    JsonDataSetWriterMessageDataType::typeName(void)
    {
    	return "JsonDataSetWriterMessageDataType";
    }
    
    OpcUaNodeId
    JsonDataSetWriterMessageDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15664,0);
    }
    
    OpcUaNodeId
    JsonDataSetWriterMessageDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15724, 0);
    }
    
    OpcUaNodeId
    JsonDataSetWriterMessageDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16018, 0);
    }
    
    OpcUaNodeId
    JsonDataSetWriterMessageDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16394, 0);
    }
    
    void
    JsonDataSetWriterMessageDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        DataSetWriterMessageDataType::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetMessageContentMask_);
    }
    
    void
    JsonDataSetWriterMessageDataType::opcUaBinaryDecode(std::istream& is)
    {
        DataSetWriterMessageDataType::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetMessageContentMask_);
    }
    
    bool
    JsonDataSetWriterMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "JsonDataSetWriterMessageDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    JsonDataSetWriterMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetMessageContentMask_))
        {
            Log(Error, "JsonDataSetWriterMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetMessageContentMask", elementTree));
    
        return true;
    }
    
    bool
    JsonDataSetWriterMessageDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "JsonDataSetWriterMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    JsonDataSetWriterMessageDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("DataSetMessageContentMask");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "JsonDataSetWriterMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, dataSetMessageContentMask_)) {
            Log(Error, "JsonDataSetWriterMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    JsonDataSetWriterMessageDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, dataSetMessageContentMask_))
        {
    	     Log(Error, "JsonDataSetWriterMessageDataType json encoder error")
    		     .parameter("Element", "dataSetMessageContentMask_");
           return false;
        }
        pt.push_back(std::make_pair("DataSetMessageContentMask", elementTree));
    
        return true;
    }
    
    bool
    JsonDataSetWriterMessageDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "DataSetMessageContentMask";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "JsonDataSetWriterMessageDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, dataSetMessageContentMask_)) {
            Log(Error, "JsonDataSetWriterMessageDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    JsonDataSetWriterMessageDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	JsonDataSetWriterMessageDataType* dst = dynamic_cast<JsonDataSetWriterMessageDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    JsonDataSetWriterMessageDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	JsonDataSetWriterMessageDataType* dst = dynamic_cast<JsonDataSetWriterMessageDataType*>(&extensionObjectBase);
    	return *const_cast<JsonDataSetWriterMessageDataType*>(this) == *dst;
    }
    
    void
    JsonDataSetWriterMessageDataType::out(std::ostream& os)
    {
        os << "DataSetMessageContentMask=" << dataSetMessageContentMask_;
    }

}
