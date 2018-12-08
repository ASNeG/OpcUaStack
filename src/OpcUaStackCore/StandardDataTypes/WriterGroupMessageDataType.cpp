/*
    DataTypeClass: WriterGroupMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/WriterGroupMessageDataType.h"

namespace OpcUaStackCore
{
    
    WriterGroupMessageDataType::WriterGroupMessageDataType(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    WriterGroupMessageDataType::~WriterGroupMessageDataType(void)
    {
    }
    
    bool
    WriterGroupMessageDataType::operator==(const WriterGroupMessageDataType& value)
    {
        WriterGroupMessageDataType* dst = const_cast<WriterGroupMessageDataType*>(&value);
        return true;
    }
    
    bool
    WriterGroupMessageDataType::operator!=(const WriterGroupMessageDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    WriterGroupMessageDataType::copyTo(WriterGroupMessageDataType& value)
    {
    }
    
    WriterGroupMessageDataType&
    WriterGroupMessageDataType::operator=(const WriterGroupMessageDataType& value)
    {
        const_cast<WriterGroupMessageDataType*>(&value)->copyTo(*this);
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
    WriterGroupMessageDataType::factory(void)
    {
    	return constructSPtr<WriterGroupMessageDataType>();
    }
    
    std::string
    WriterGroupMessageDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    WriterGroupMessageDataType::typeName(void)
    {
    	return "WriterGroupMessageDataType";
    }
    
    OpcUaNodeId
    WriterGroupMessageDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15616,0);
    }
    
    OpcUaNodeId
    WriterGroupMessageDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15693, 0);
    }
    
    OpcUaNodeId
    WriterGroupMessageDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15991, 0);
    }
    
    OpcUaNodeId
    WriterGroupMessageDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16280, 0);
    }
    
    void
    WriterGroupMessageDataType::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    WriterGroupMessageDataType::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    WriterGroupMessageDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    WriterGroupMessageDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    WriterGroupMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "WriterGroupMessageDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    WriterGroupMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    WriterGroupMessageDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    WriterGroupMessageDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    WriterGroupMessageDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        boost::property_tree::ptree elementTree;
        if (!jsonEncode(elementTree)) {
    	     Log(Error, "WriterGroupMessageDataType json encoder error")
    		     .parameter("Element", element);
     	     return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    WriterGroupMessageDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    WriterGroupMessageDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
        boost::optional<boost::property_tree::ptree&> tmpTree;
    
        tmpTree = pt.get_child_optional(element);
        if (!tmpTree) {
     	     Log(Error, "WriterGroupMessageDataType json decoder error")
    		    .parameter("Element", element);
    		 return false;
        }
        return jsonDecode(*tmpTree);
    }
    
    bool
    WriterGroupMessageDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    WriterGroupMessageDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	WriterGroupMessageDataType* dst = dynamic_cast<WriterGroupMessageDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    WriterGroupMessageDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	WriterGroupMessageDataType* dst = dynamic_cast<WriterGroupMessageDataType*>(&extensionObjectBase);
    	return *const_cast<WriterGroupMessageDataType*>(this) == *dst;
    }
    
    void
    WriterGroupMessageDataType::out(std::ostream& os)
    {
    }

}
