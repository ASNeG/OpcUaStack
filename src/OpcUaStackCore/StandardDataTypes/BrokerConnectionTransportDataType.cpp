/*
    DataTypeClass: BrokerConnectionTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
    BrokerConnectionTransportDataType::operator==(const BrokerConnectionTransportDataType& value)
    {
        BrokerConnectionTransportDataType* dst = const_cast<BrokerConnectionTransportDataType*>(&value);
        if (resourceUri_ != dst->resourceUri()) return false;
        if (authenticationProfileUri_ != dst->authenticationProfileUri()) return false;
        return true;
    }
    
    bool
    BrokerConnectionTransportDataType::operator!=(const BrokerConnectionTransportDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    BrokerConnectionTransportDataType::copyTo(BrokerConnectionTransportDataType& value)
    {
        resourceUri_.copyTo(value.resourceUri());
        authenticationProfileUri_.copyTo(value.authenticationProfileUri());
    }
    
    BrokerConnectionTransportDataType&
    BrokerConnectionTransportDataType::operator=(const BrokerConnectionTransportDataType& value)
    {
        const_cast<BrokerConnectionTransportDataType*>(&value)->copyTo(*this);
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
    BrokerConnectionTransportDataType::factory(void)
    {
    	return constructSPtr<BrokerConnectionTransportDataType>();
    }
    
    std::string
    BrokerConnectionTransportDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    BrokerConnectionTransportDataType::typeName(void)
    {
    	return "BrokerConnectionTransportDataType";
    }
    
    OpcUaNodeId
    BrokerConnectionTransportDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15007,0);
    }
    
    OpcUaNodeId
    BrokerConnectionTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15479, 0);
    }
    
    OpcUaNodeId
    BrokerConnectionTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15579, 0);
    }
    
    OpcUaNodeId
    BrokerConnectionTransportDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15726, 0);
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
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    BrokerConnectionTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!resourceUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ResourceUri", elementTree));
    
        elementTree.clear();
        if (!authenticationProfileUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("AuthenticationProfileUri", elementTree));
    
        return true;
    }
    
    bool
    BrokerConnectionTransportDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    BrokerConnectionTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("ResourceUri");
        if (!tree) return false;
        if (!resourceUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("AuthenticationProfileUri");
        if (!tree) return false;
        if (!authenticationProfileUri_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    BrokerConnectionTransportDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    BrokerConnectionTransportDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    BrokerConnectionTransportDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    BrokerConnectionTransportDataType::jsonDecode(boost::property_tree::ptree& pt)
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
    	return *const_cast<BrokerConnectionTransportDataType*>(this) == *dst;
    }
    
    void
    BrokerConnectionTransportDataType::out(std::ostream& os)
    {
        os << "ResourceUri="; resourceUri_.out(os);
        os << ", AuthenticationProfileUri="; authenticationProfileUri_.out(os);
    }

}
