/*
    DataTypeClass: PubSubGroupDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/PubSubGroupDataType.h"

namespace OpcUaStackCore
{
    
    PubSubGroupDataType::PubSubGroupDataType(void)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , enabled_()
    , securityMode_()
    , securityGroupId_()
    , securityKeyServices_()
    , maxNetworkMessageSize_()
    , groupProperties_()
    {
    }
    
    PubSubGroupDataType::~PubSubGroupDataType(void)
    {
    }
    
    OpcUaString&
    PubSubGroupDataType::name(void)
    {
        return name_;
    }
    
    OpcUaBoolean&
    PubSubGroupDataType::enabled(void)
    {
        return enabled_;
    }
    
    MessageSecurityMode&
    PubSubGroupDataType::securityMode(void)
    {
        return securityMode_;
    }
    
    OpcUaString&
    PubSubGroupDataType::securityGroupId(void)
    {
        return securityGroupId_;
    }
    
    EndpointDescriptionArray&
    PubSubGroupDataType::securityKeyServices(void)
    {
        return securityKeyServices_;
    }
    
    OpcUaUInt32&
    PubSubGroupDataType::maxNetworkMessageSize(void)
    {
        return maxNetworkMessageSize_;
    }
    
    KeyValuePairArray&
    PubSubGroupDataType::groupProperties(void)
    {
        return groupProperties_;
    }
    
    bool
    PubSubGroupDataType::operator==(const PubSubGroupDataType& value)
    {
        PubSubGroupDataType* dst = const_cast<PubSubGroupDataType*>(&value);
        if (name_ != dst->name()) return false;
        if (enabled_ != dst->enabled()) return false;
        if (securityMode_ != dst->securityMode()) return false;
        if (securityGroupId_ != dst->securityGroupId()) return false;
        if (securityKeyServices_ != dst->securityKeyServices()) return false;
        if (maxNetworkMessageSize_ != dst->maxNetworkMessageSize()) return false;
        if (groupProperties_ != dst->groupProperties()) return false;
        return true;
    }
    
    bool
    PubSubGroupDataType::operator!=(const PubSubGroupDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    PubSubGroupDataType::copyTo(PubSubGroupDataType& value)
    {
        name_.copyTo(value.name());
        value.enabled_ = enabled_;
        securityMode_.copyTo(value.securityMode());
        securityGroupId_.copyTo(value.securityGroupId());
        securityKeyServices_.copyTo(value.securityKeyServices());
        value.maxNetworkMessageSize_ = maxNetworkMessageSize_;
        groupProperties_.copyTo(value.groupProperties());
    }
    
    PubSubGroupDataType&
    PubSubGroupDataType::operator=(const PubSubGroupDataType& value)
    {
        const_cast<PubSubGroupDataType*>(&value)->copyTo(*this);
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
    PubSubGroupDataType::factory(void)
    {
    	return constructSPtr<PubSubGroupDataType>();
    }
    
    std::string
    PubSubGroupDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    PubSubGroupDataType::typeName(void)
    {
    	return "PubSubGroupDataType";
    }
    
    OpcUaNodeId
    PubSubGroupDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15609,0);
    }
    
    OpcUaNodeId
    PubSubGroupDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15689, 0);
    }
    
    OpcUaNodeId
    PubSubGroupDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15988, 0);
    }
    
    OpcUaNodeId
    PubSubGroupDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16159, 0);
    }
    
    void
    PubSubGroupDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        name_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,enabled_);
        securityMode_.opcUaBinaryEncode(os);
        securityGroupId_.opcUaBinaryEncode(os);
        securityKeyServices_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,maxNetworkMessageSize_);
        groupProperties_.opcUaBinaryEncode(os);
    }
    
    void
    PubSubGroupDataType::opcUaBinaryDecode(std::istream& is)
    {
        name_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,enabled_);
        securityMode_.opcUaBinaryDecode(is);
        securityGroupId_.opcUaBinaryDecode(is);
        securityKeyServices_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,maxNetworkMessageSize_);
        groupProperties_.opcUaBinaryDecode(is);
    }
    
    bool
    PubSubGroupDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    PubSubGroupDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    PubSubGroupDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PubSubGroupDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, enabled_)) return false;
        pt.push_back(std::make_pair("Enabled", elementTree));
    
        elementTree.clear();
        if (!securityMode_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SecurityMode", elementTree));
    
        elementTree.clear();
        if (!securityGroupId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SecurityGroupId", elementTree));
    
        elementTree.clear();
        if (!securityKeyServices_.xmlEncode(elementTree, "EndpointDescription", xmlns)) return false;
        pt.push_back(std::make_pair("SecurityKeyServices", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxNetworkMessageSize_)) return false;
        pt.push_back(std::make_pair("MaxNetworkMessageSize", elementTree));
    
        elementTree.clear();
        if (!groupProperties_.xmlEncode(elementTree, "KeyValuePair", xmlns)) return false;
        pt.push_back(std::make_pair("GroupProperties", elementTree));
    
        return true;
    }
    
    bool
    PubSubGroupDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PubSubGroupDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Name");
        if (!tree) return false;
        if (!name_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Enabled");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, enabled_)) return false;
    
        tree = pt.get_child_optional("SecurityMode");
        if (!tree) return false;
        if (!securityMode_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SecurityGroupId");
        if (!tree) return false;
        if (!securityGroupId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SecurityKeyServices");
        if (!tree) return false;
        if (!securityKeyServices_.xmlDecode(*tree, "EndpointDescription", xmlns)) return false;
    
        tree = pt.get_child_optional("MaxNetworkMessageSize");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, maxNetworkMessageSize_)) return false;
    
        tree = pt.get_child_optional("GroupProperties");
        if (!tree) return false;
        if (!groupProperties_.xmlDecode(*tree, "KeyValuePair", xmlns)) return false;
    
        return true;
    }
    
    bool
    PubSubGroupDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    PubSubGroupDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    PubSubGroupDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    PubSubGroupDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    PubSubGroupDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	PubSubGroupDataType* dst = dynamic_cast<PubSubGroupDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    PubSubGroupDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	PubSubGroupDataType* dst = dynamic_cast<PubSubGroupDataType*>(&extensionObjectBase);
    	return *const_cast<PubSubGroupDataType*>(this) == *dst;
    }
    
    void
    PubSubGroupDataType::out(std::ostream& os)
    {
        os << "Name="; name_.out(os);
        os << ", Enabled=" << enabled_;
        os << ", SecurityMode="; securityMode_.out(os);
        os << ", SecurityGroupId="; securityGroupId_.out(os);
        os << ", SecurityKeyServices="; securityKeyServices_.out(os);
        os << ", MaxNetworkMessageSize=" << maxNetworkMessageSize_;
        os << ", GroupProperties="; groupProperties_.out(os);
    }

}
