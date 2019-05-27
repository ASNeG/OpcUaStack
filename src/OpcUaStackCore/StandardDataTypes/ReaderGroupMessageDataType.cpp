/*
    DataTypeClass: ReaderGroupMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ReaderGroupMessageDataType.h"

namespace OpcUaStackCore
{
    
    ReaderGroupMessageDataType::ReaderGroupMessageDataType(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    ReaderGroupMessageDataType::ReaderGroupMessageDataType(const ReaderGroupMessageDataType& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<ReaderGroupMessageDataType*>(&value)->copyTo(*this);
    }
    
    ReaderGroupMessageDataType::~ReaderGroupMessageDataType(void)
    {
    }
    
    bool
    ReaderGroupMessageDataType::operator==(const ReaderGroupMessageDataType& value)
    {
        ReaderGroupMessageDataType* dst = const_cast<ReaderGroupMessageDataType*>(&value);
        return true;
    }
    
    bool
    ReaderGroupMessageDataType::operator!=(const ReaderGroupMessageDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    ReaderGroupMessageDataType::copyTo(ReaderGroupMessageDataType& value)
    {
    }
    
    ReaderGroupMessageDataType&
    ReaderGroupMessageDataType::operator=(const ReaderGroupMessageDataType& value)
    {
        const_cast<ReaderGroupMessageDataType*>(&value)->copyTo(*this);
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
    ReaderGroupMessageDataType::factory(void)
    {
    	return constructSPtr<ReaderGroupMessageDataType>();
    }
    
    std::string
    ReaderGroupMessageDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ReaderGroupMessageDataType::typeName(void)
    {
    	return "ReaderGroupMessageDataType";
    }
    
    OpcUaNodeId
    ReaderGroupMessageDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15622,0);
    }
    
    OpcUaNodeId
    ReaderGroupMessageDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15702, 0);
    }
    
    OpcUaNodeId
    ReaderGroupMessageDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15996, 0);
    }
    
    OpcUaNodeId
    ReaderGroupMessageDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16285, 0);
    }
    
    void
    ReaderGroupMessageDataType::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    ReaderGroupMessageDataType::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    ReaderGroupMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReaderGroupMessageDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReaderGroupMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    ReaderGroupMessageDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReaderGroupMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReaderGroupMessageDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    ReaderGroupMessageDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    ReaderGroupMessageDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    ReaderGroupMessageDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ReaderGroupMessageDataType* dst = dynamic_cast<ReaderGroupMessageDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ReaderGroupMessageDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ReaderGroupMessageDataType* dst = dynamic_cast<ReaderGroupMessageDataType*>(&extensionObjectBase);
    	return *const_cast<ReaderGroupMessageDataType*>(this) == *dst;
    }
    
    void
    ReaderGroupMessageDataType::out(std::ostream& os)
    {
    }

}
