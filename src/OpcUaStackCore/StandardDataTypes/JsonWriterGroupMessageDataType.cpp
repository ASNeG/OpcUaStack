/*
    DataTypeClass: JsonWriterGroupMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/JsonWriterGroupMessageDataType.h"

namespace OpcUaStackCore
{
    
    JsonWriterGroupMessageDataType::JsonWriterGroupMessageDataType(void)
    : WriterGroupMessageDataType()
    , networkMessageContentMask_()
    {
    }
    
    JsonWriterGroupMessageDataType::~JsonWriterGroupMessageDataType(void)
    {
    }
    
    OpcUaJsonNetworkMessageContentMask&
    JsonWriterGroupMessageDataType::networkMessageContentMask(void)
    {
        return networkMessageContentMask_;
    }
    
    bool
    JsonWriterGroupMessageDataType::operator==(const JsonWriterGroupMessageDataType& value)
    {
        JsonWriterGroupMessageDataType* dst = const_cast<JsonWriterGroupMessageDataType*>(&value);
        if (networkMessageContentMask_ != dst->networkMessageContentMask()) return false;
        return true;
    }
    
    bool
    JsonWriterGroupMessageDataType::operator!=(const JsonWriterGroupMessageDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    JsonWriterGroupMessageDataType::copyTo(JsonWriterGroupMessageDataType& value)
    {
        value.networkMessageContentMask_ = networkMessageContentMask_;
    }
    
    JsonWriterGroupMessageDataType&
    JsonWriterGroupMessageDataType::operator=(const JsonWriterGroupMessageDataType& value)
    {
        const_cast<JsonWriterGroupMessageDataType*>(&value)->copyTo(*this);
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
    JsonWriterGroupMessageDataType::factory(void)
    {
    	return constructSPtr<JsonWriterGroupMessageDataType>();
    }
    
    std::string
    JsonWriterGroupMessageDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    JsonWriterGroupMessageDataType::typeName(void)
    {
    	return "JsonWriterGroupMessageDataType";
    }
    
    OpcUaNodeId
    JsonWriterGroupMessageDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15657,0);
    }
    
    OpcUaNodeId
    JsonWriterGroupMessageDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15719, 0);
    }
    
    OpcUaNodeId
    JsonWriterGroupMessageDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16017, 0);
    }
    
    OpcUaNodeId
    JsonWriterGroupMessageDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16393, 0);
    }
    
    void
    JsonWriterGroupMessageDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        WriterGroupMessageDataType::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,networkMessageContentMask_);
    }
    
    void
    JsonWriterGroupMessageDataType::opcUaBinaryDecode(std::istream& is)
    {
        WriterGroupMessageDataType::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,networkMessageContentMask_);
    }
    
    bool
    JsonWriterGroupMessageDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    JsonWriterGroupMessageDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    JsonWriterGroupMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    JsonWriterGroupMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, networkMessageContentMask_)) return false;
        pt.push_back(std::make_pair("NetworkMessageContentMask", elementTree));
    
        return true;
    }
    
    bool
    JsonWriterGroupMessageDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "JsonWriterGroupMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    JsonWriterGroupMessageDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("NetworkMessageContentMask");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "JsonWriterGroupMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, networkMessageContentMask_)) {
            Log(Error, "JsonWriterGroupMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    JsonWriterGroupMessageDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    JsonWriterGroupMessageDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    JsonWriterGroupMessageDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    JsonWriterGroupMessageDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    JsonWriterGroupMessageDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	JsonWriterGroupMessageDataType* dst = dynamic_cast<JsonWriterGroupMessageDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    JsonWriterGroupMessageDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	JsonWriterGroupMessageDataType* dst = dynamic_cast<JsonWriterGroupMessageDataType*>(&extensionObjectBase);
    	return *const_cast<JsonWriterGroupMessageDataType*>(this) == *dst;
    }
    
    void
    JsonWriterGroupMessageDataType::out(std::ostream& os)
    {
        os << "NetworkMessageContentMask=" << networkMessageContentMask_;
    }

}
