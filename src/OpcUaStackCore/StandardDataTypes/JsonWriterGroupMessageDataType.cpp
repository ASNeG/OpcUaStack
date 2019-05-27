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
    
    JsonWriterGroupMessageDataType::JsonWriterGroupMessageDataType(const JsonWriterGroupMessageDataType& value)
    : WriterGroupMessageDataType()
    , networkMessageContentMask_()
    {
        const_cast<JsonWriterGroupMessageDataType*>(&value)->copyTo(*this);
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
    JsonWriterGroupMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "JsonWriterGroupMessageDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    JsonWriterGroupMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, networkMessageContentMask_))
        {
            Log(Error, "JsonWriterGroupMessageDataType encode xml error");
            return false;
        }
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
    JsonWriterGroupMessageDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, networkMessageContentMask_))
        {
    	     Log(Error, "JsonWriterGroupMessageDataType json encoder error")
    		     .parameter("Element", "networkMessageContentMask_");
           return false;
        }
        pt.push_back(std::make_pair("NetworkMessageContentMask", elementTree));
    
        return true;
    }
    
    bool
    JsonWriterGroupMessageDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "NetworkMessageContentMask";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "JsonWriterGroupMessageDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, networkMessageContentMask_)) {
            Log(Error, "JsonWriterGroupMessageDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
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
