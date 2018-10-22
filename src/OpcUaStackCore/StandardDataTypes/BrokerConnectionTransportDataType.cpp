/*
    DataTypeClass: BrokerConnectionTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/BrokerConnectionTransportDataType.h"

namespace OpcUaStackCore
{
    
    BrokerConnectionTransportDataType::BrokerConnectionTransportDataType(void)
    : ConnectionTransportDataType()
    , resourceUri_()
    , authenticationProfileUri_()
    {
    }
    
    BrokerConnectionTransportDataType::~BrokerConnectionTransportDataType(void)
    {
    }
    
    OpcUaString&
    BrokerConnectionTransportDataType::resourceUri(void)
    {
        return resourceUri_;
    }
    
    OpcUaString&
    BrokerConnectionTransportDataType::authenticationProfileUri(void)
    {
        return authenticationProfileUri_;
    }
    
    bool
    BrokerConnectionTransportDataType::operator==(const BrokerConnectionTransportDataType& value) const
    {
        BrokerConnectionTransportDataType* dst = const_cast<BrokerConnectionTransportDataType*>(&value);
        if (resourceUri_ != dst->resourceUri()) return false;
        if (authenticationProfileUri_ != dst->authenticationProfileUri()) return false;
        return true;
    }
    
    void
    BrokerConnectionTransportDataType::copyTo(BrokerConnectionTransportDataType& value)
    {
        value.resourceUri_ = resourceUri_;
        value.authenticationProfileUri_ = authenticationProfileUri_;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    BrokerConnectionTransportDataType::factory(void)
    {
    	return constructSPtr<BrokerConnectionTransportDataType>();
    }
    
    OpcUaNodeId
    BrokerConnectionTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    OpcUaNodeId
    BrokerConnectionTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId(0, 0);
    }
    
    void
    BrokerConnectionTransportDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        resourceUri_.opcUaBinaryEncode(os);
        authenticationProfileUri_.opcUaBinaryEncode(os);
    }
    
    void
    BrokerConnectionTransportDataType::opcUaBinaryDecode(std::istream& is)
    {
        resourceUri_.opcUaBinaryDecode(is);
        authenticationProfileUri_.opcUaBinaryDecode(is);
    }
    
    bool
    BrokerConnectionTransportDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    BrokerConnectionTransportDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    BrokerConnectionTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
    }
    
    bool
    BrokerConnectionTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    BrokerConnectionTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    void
    BrokerConnectionTransportDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	BrokerConnectionTransportDataType* dst = dynamic_cast<BrokerConnectionTransportDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    BrokerConnectionTransportDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	BrokerConnectionTransportDataType* dst = dynamic_cast<BrokerConnectionTransportDataType*>(&extensionObjectBase);
    	return *this == *dst;
    }
    
    void
    BrokerConnectionTransportDataType::out(std::ostream& os)
    {
        os << "ResourceUri="; resourceUri_.out(os);
        os << ", AuthenticationProfileUri="; authenticationProfileUri_.out(os);
    }

}
