/*
    DataTypeClass: ConnectionTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

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
    
    ConnectionTransportDataType::~ConnectionTransportDataType(void)
    {
    }
    
    bool
    ConnectionTransportDataType::operator==(const ConnectionTransportDataType& value) const
    {
        ConnectionTransportDataType* dst = const_cast<ConnectionTransportDataType*>(&value);
        return true;
    }
    
    bool
    ConnectionTransportDataType::operator!=(const ConnectionTransportDataType& value) const
    {
        return !this->operator==(value);
    }
    
    void
    ConnectionTransportDataType::copyTo(ConnectionTransportDataType& value)
    {
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
    
    OpcUaNodeId
    ConnectionTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    ConnectionTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
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
    ConnectionTransportDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ConnectionTransportDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ConnectionTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }
    
    bool
    ConnectionTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ConnectionTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
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
    	return *this == *dst;
    }
    
    void
    ConnectionTransportDataType::out(std::ostream& os)
    {
    }

}
