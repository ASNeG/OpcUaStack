/*
    DataTypeClass: ConnectionTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ConnectionTransportDataType.h"

namespace OpcUaStackCore
{
    
    ConnectionTransportDataType::ConnectionTransportDataType(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    ConnectionTransportDataType::ConnectionTransportDataType(const ConnectionTransportDataType& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<ConnectionTransportDataType*>(&value)->copyTo(*this);
    }
    
    ConnectionTransportDataType::~ConnectionTransportDataType(void)
    {
    }
    
    bool
    ConnectionTransportDataType::operator==(const ConnectionTransportDataType& value)
    {
        ConnectionTransportDataType* dst = const_cast<ConnectionTransportDataType*>(&value);
        return true;
    }
    
    bool
    ConnectionTransportDataType::operator!=(const ConnectionTransportDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    ConnectionTransportDataType::copyTo(ConnectionTransportDataType& value)
    {
    }
    
    ConnectionTransportDataType&
    ConnectionTransportDataType::operator=(const ConnectionTransportDataType& value)
    {
        const_cast<ConnectionTransportDataType*>(&value)->copyTo(*this);
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
    ConnectionTransportDataType::factory(void)
    {
    	return constructSPtr<ConnectionTransportDataType>();
    }
    
    std::string
    ConnectionTransportDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ConnectionTransportDataType::typeName(void)
    {
    	return "ConnectionTransportDataType";
    }
    
    OpcUaNodeId
    ConnectionTransportDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15618,0);
    }
    
    OpcUaNodeId
    ConnectionTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15695, 0);
    }
    
    OpcUaNodeId
    ConnectionTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15993, 0);
    }
    
    OpcUaNodeId
    ConnectionTransportDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16282, 0);
    }
    
    void
    ConnectionTransportDataType::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    ConnectionTransportDataType::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    ConnectionTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ConnectionTransportDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ConnectionTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    ConnectionTransportDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ConnectionTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ConnectionTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    ConnectionTransportDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    ConnectionTransportDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    ConnectionTransportDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ConnectionTransportDataType* dst = dynamic_cast<ConnectionTransportDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ConnectionTransportDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ConnectionTransportDataType* dst = dynamic_cast<ConnectionTransportDataType*>(&extensionObjectBase);
    	return *const_cast<ConnectionTransportDataType*>(this) == *dst;
    }
    
    void
    ConnectionTransportDataType::out(std::ostream& os)
    {
    }

}
