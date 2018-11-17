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
        OpcUaNumber::opcUaBinaryEncode(os,dataSetMessageContentMask_);
    }
    
    void
    JsonDataSetWriterMessageDataType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,dataSetMessageContentMask_);
    }
    
    bool
    JsonDataSetWriterMessageDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    JsonDataSetWriterMessageDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    JsonDataSetWriterMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    JsonDataSetWriterMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetMessageContentMask_)) return false;
        pt.push_back(std::make_pair("DataSetMessageContentMask", elementTree));
    
        return true;
    }
    
    bool
    JsonDataSetWriterMessageDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    JsonDataSetWriterMessageDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("DataSetMessageContentMask");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, dataSetMessageContentMask_)) return false;
    
        return true;
    }
    
    bool
    JsonDataSetWriterMessageDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    JsonDataSetWriterMessageDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    JsonDataSetWriterMessageDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    JsonDataSetWriterMessageDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
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
