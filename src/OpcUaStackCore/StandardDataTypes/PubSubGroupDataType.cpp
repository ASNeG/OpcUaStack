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
    
    PubSubGroupDataType::PubSubGroupDataType(const PubSubGroupDataType& value)
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
        const_cast<PubSubGroupDataType*>(&value)->copyTo(*this);
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
    	return boost::make_shared<PubSubGroupDataType>();
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
    PubSubGroupDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "PubSubGroupDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PubSubGroupDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PubSubGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, enabled_))
        {
            Log(Error, "PubSubGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Enabled", elementTree));
    
        elementTree.clear();
        if (!securityMode_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PubSubGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityMode", elementTree));
    
        elementTree.clear();
        if (!securityGroupId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PubSubGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityGroupId", elementTree));
    
        elementTree.clear();
        if (!securityKeyServices_.xmlEncode(elementTree, "EndpointDescription", xmlns)) {
            Log(Error, "PubSubGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityKeyServices", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxNetworkMessageSize_))
        {
            Log(Error, "PubSubGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxNetworkMessageSize", elementTree));
    
        elementTree.clear();
        if (!groupProperties_.xmlEncode(elementTree, "KeyValuePair", xmlns)) {
            Log(Error, "PubSubGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("GroupProperties", elementTree));
    
        return true;
    }
    
    bool
    PubSubGroupDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PubSubGroupDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Name");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PubSubGroupDataType decode xml error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        elementName = xmlns.addPrefix("Enabled");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, enabled_)) {
            Log(Error, "PubSubGroupDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityMode");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityMode_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PubSubGroupDataType decode xml error - decode failed")
                .parameter("Element", "SecurityMode");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityGroupId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityGroupId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PubSubGroupDataType decode xml error - decode failed")
                .parameter("Element", "SecurityGroupId");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityKeyServices");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityKeyServices_.xmlDecode(*tree, "EndpointDescription", xmlns)) {
            Log(Error, "PubSubGroupDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxNetworkMessageSize");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxNetworkMessageSize_)) {
            Log(Error, "PubSubGroupDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("GroupProperties");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!groupProperties_.xmlDecode(*tree, "KeyValuePair", xmlns)) {
            Log(Error, "PubSubGroupDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    PubSubGroupDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, name_, "Name", true);
        rc = rc & jsonNumberEncode(pt, enabled_, "Enabled");
        rc = rc & jsonObjectEncode(pt, securityMode_, "SecurityMode", true);
        rc = rc & jsonObjectEncode(pt, securityGroupId_, "SecurityGroupId", true);
        rc = rc & jsonArrayEncode(pt, securityKeyServices_, "SecurityKeyServices", true);
        rc = rc & jsonNumberEncode(pt, maxNetworkMessageSize_, "MaxNetworkMessageSize");
        rc = rc & jsonArrayEncode(pt, groupProperties_, "GroupProperties", true);
    
        return rc;
    }
    
    bool
    PubSubGroupDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, name_, "Name", true);
        rc = rc & jsonNumberDecode(pt, enabled_, "Enabled");
        rc = rc & jsonObjectDecode(pt, securityMode_, "SecurityMode", true);
        rc = rc & jsonObjectDecode(pt, securityGroupId_, "SecurityGroupId", true);
        rc = rc & jsonArrayDecode(pt, securityKeyServices_, "SecurityKeyServices", true);
        rc = rc & jsonNumberDecode(pt, maxNetworkMessageSize_, "MaxNetworkMessageSize");
        rc = rc & jsonArrayDecode(pt, groupProperties_, "GroupProperties", true);
    
        return rc;
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
