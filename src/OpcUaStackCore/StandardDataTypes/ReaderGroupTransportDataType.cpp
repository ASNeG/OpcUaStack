/*
    DataTypeClass: ReaderGroupTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ReaderGroupTransportDataType.h"

namespace OpcUaStackCore
{
    
    ReaderGroupTransportDataType::ReaderGroupTransportDataType(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    ReaderGroupTransportDataType::ReaderGroupTransportDataType(const ReaderGroupTransportDataType& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<ReaderGroupTransportDataType*>(&value)->copyTo(*this);
    }
    
    ReaderGroupTransportDataType::~ReaderGroupTransportDataType(void)
    {
    }
    
    bool
    ReaderGroupTransportDataType::operator==(const ReaderGroupTransportDataType& value)
    {
        ReaderGroupTransportDataType* dst = const_cast<ReaderGroupTransportDataType*>(&value);
        return true;
    }
    
    bool
    ReaderGroupTransportDataType::operator!=(const ReaderGroupTransportDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    ReaderGroupTransportDataType::copyTo(ReaderGroupTransportDataType& value)
    {
    }
    
    ReaderGroupTransportDataType&
    ReaderGroupTransportDataType::operator=(const ReaderGroupTransportDataType& value)
    {
        const_cast<ReaderGroupTransportDataType*>(&value)->copyTo(*this);
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
    ReaderGroupTransportDataType::factory(void)
    {
    	return constructSPtr<ReaderGroupTransportDataType>();
    }
    
    std::string
    ReaderGroupTransportDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ReaderGroupTransportDataType::typeName(void)
    {
    	return "ReaderGroupTransportDataType";
    }
    
    OpcUaNodeId
    ReaderGroupTransportDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15621,0);
    }
    
    OpcUaNodeId
    ReaderGroupTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15701, 0);
    }
    
    OpcUaNodeId
    ReaderGroupTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15995, 0);
    }
    
    OpcUaNodeId
    ReaderGroupTransportDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16284, 0);
    }
    
    void
    ReaderGroupTransportDataType::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    ReaderGroupTransportDataType::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    ReaderGroupTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReaderGroupTransportDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReaderGroupTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    ReaderGroupTransportDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReaderGroupTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReaderGroupTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    ReaderGroupTransportDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    ReaderGroupTransportDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    ReaderGroupTransportDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ReaderGroupTransportDataType* dst = dynamic_cast<ReaderGroupTransportDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ReaderGroupTransportDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ReaderGroupTransportDataType* dst = dynamic_cast<ReaderGroupTransportDataType*>(&extensionObjectBase);
    	return *const_cast<ReaderGroupTransportDataType*>(this) == *dst;
    }
    
    void
    ReaderGroupTransportDataType::out(std::ostream& os)
    {
    }

}
