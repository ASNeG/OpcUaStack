/*
    DataTypeClass: DatagramConnectionTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DatagramConnectionTransportDataType.h"

namespace OpcUaStackCore
{
    
    DatagramConnectionTransportDataType::DatagramConnectionTransportDataType(void)
    : ConnectionTransportDataType()
    , discoveryAddress_()
    {
    }
    
    DatagramConnectionTransportDataType::~DatagramConnectionTransportDataType(void)
    {
    }
    
    OpcUaExtensionObject&
    DatagramConnectionTransportDataType::discoveryAddress(void)
    {
        return discoveryAddress_;
    }
    
    bool
    DatagramConnectionTransportDataType::operator==(const DatagramConnectionTransportDataType& value) const
    {
        DatagramConnectionTransportDataType* dst = const_cast<DatagramConnectionTransportDataType*>(&value);
        if (discoveryAddress_ != dst->discoveryAddress()) return false;
        return true;
    }
    
    bool
    DatagramConnectionTransportDataType::operator!=(const DatagramConnectionTransportDataType& value) const
    {
        return !this->operator==(value);
    }
    
    void
    DatagramConnectionTransportDataType::copyTo(DatagramConnectionTransportDataType& value)
    {
        value.discoveryAddress_ = discoveryAddress_;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    DatagramConnectionTransportDataType::factory(void)
    {
    	return constructSPtr<DatagramConnectionTransportDataType>();
    }
    
    OpcUaNodeId
    DatagramConnectionTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    DatagramConnectionTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    void
    DatagramConnectionTransportDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        discoveryAddress_.opcUaBinaryEncode(os);
    }
    
    void
    DatagramConnectionTransportDataType::opcUaBinaryDecode(std::istream& is)
    {
        discoveryAddress_.opcUaBinaryDecode(is);
    }
    
    bool
    DatagramConnectionTransportDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    DatagramConnectionTransportDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DatagramConnectionTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }
    
    bool
    DatagramConnectionTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DatagramConnectionTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    void
    DatagramConnectionTransportDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DatagramConnectionTransportDataType* dst = dynamic_cast<DatagramConnectionTransportDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DatagramConnectionTransportDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DatagramConnectionTransportDataType* dst = dynamic_cast<DatagramConnectionTransportDataType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    DatagramConnectionTransportDataType::out(std::ostream& os)
    {
        os << "DiscoveryAddress="; discoveryAddress_.out(os);
    }

}
