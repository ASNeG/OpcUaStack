/*
    DataTypeClass: EndpointType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EndpointType.h"

namespace OpcUaStackCore
{
    
    EndpointType::EndpointType(void)
    : Object()
    , ExtensionObjectBase()
    , endpointUrl_()
    , securityMode_()
    , securityPolicyUri_()
    , transportProfileUri_()
    {
    }
    
    EndpointType::EndpointType(const EndpointType& value)
    : Object()
    , ExtensionObjectBase()
    , endpointUrl_()
    , securityMode_()
    , securityPolicyUri_()
    , transportProfileUri_()
    {
        const_cast<EndpointType*>(&value)->copyTo(*this);
    }
    
    EndpointType::~EndpointType(void)
    {
    }
    
    OpcUaString&
    EndpointType::endpointUrl(void)
    {
        return endpointUrl_;
    }
    
    MessageSecurityMode&
    EndpointType::securityMode(void)
    {
        return securityMode_;
    }
    
    OpcUaString&
    EndpointType::securityPolicyUri(void)
    {
        return securityPolicyUri_;
    }
    
    OpcUaString&
    EndpointType::transportProfileUri(void)
    {
        return transportProfileUri_;
    }
    
    bool
    EndpointType::operator==(const EndpointType& value)
    {
        EndpointType* dst = const_cast<EndpointType*>(&value);
        if (endpointUrl_ != dst->endpointUrl()) return false;
        if (securityMode_ != dst->securityMode()) return false;
        if (securityPolicyUri_ != dst->securityPolicyUri()) return false;
        if (transportProfileUri_ != dst->transportProfileUri()) return false;
        return true;
    }
    
    bool
    EndpointType::operator!=(const EndpointType& value)
    {
        return !this->operator==(value);
    }
    
    void
    EndpointType::copyTo(EndpointType& value)
    {
        endpointUrl_.copyTo(value.endpointUrl());
        securityMode_.copyTo(value.securityMode());
        securityPolicyUri_.copyTo(value.securityPolicyUri());
        transportProfileUri_.copyTo(value.transportProfileUri());
    }
    
    EndpointType&
    EndpointType::operator=(const EndpointType& value)
    {
        const_cast<EndpointType*>(&value)->copyTo(*this);
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
    EndpointType::factory(void)
    {
    	return constructSPtr<EndpointType>();
    }
    
    std::string
    EndpointType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EndpointType::typeName(void)
    {
    	return "EndpointType";
    }
    
    OpcUaNodeId
    EndpointType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15528,0);
    }
    
    OpcUaNodeId
    EndpointType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15671, 0);
    }
    
    OpcUaNodeId
    EndpointType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15949, 0);
    }
    
    OpcUaNodeId
    EndpointType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16150, 0);
    }
    
    void
    EndpointType::opcUaBinaryEncode(std::ostream& os) const
    {
        endpointUrl_.opcUaBinaryEncode(os);
        securityMode_.opcUaBinaryEncode(os);
        securityPolicyUri_.opcUaBinaryEncode(os);
        transportProfileUri_.opcUaBinaryEncode(os);
    }
    
    void
    EndpointType::opcUaBinaryDecode(std::istream& is)
    {
        endpointUrl_.opcUaBinaryDecode(is);
        securityMode_.opcUaBinaryDecode(is);
        securityPolicyUri_.opcUaBinaryDecode(is);
        transportProfileUri_.opcUaBinaryDecode(is);
    }
    
    bool
    EndpointType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EndpointType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!endpointUrl_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EndpointUrl", elementTree));
    
        elementTree.clear();
        if (!securityMode_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityMode", elementTree));
    
        elementTree.clear();
        if (!securityPolicyUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityPolicyUri", elementTree));
    
        elementTree.clear();
        if (!transportProfileUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EndpointType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TransportProfileUri", elementTree));
    
        return true;
    }
    
    bool
    EndpointType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EndpointType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("EndpointUrl");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endpointUrl_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EndpointType decode xml error - decode failed")
                .parameter("Element", "EndpointUrl");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityMode");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityMode_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EndpointType decode xml error - decode failed")
                .parameter("Element", "SecurityMode");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityPolicyUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityPolicyUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EndpointType decode xml error - decode failed")
                .parameter("Element", "SecurityPolicyUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("TransportProfileUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportProfileUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EndpointType decode xml error - decode failed")
                .parameter("Element", "TransportProfileUri");
            return false;
        }
    
        return true;
    }
    
    bool
    EndpointType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!endpointUrl_.jsonEncode(elementTree))
        {
    	     Log(Error, "EndpointType json encoder error")
    		     .parameter("Element", "endpointUrl_");
            return false;
        }
        pt.push_back(std::make_pair("EndpointUrl", elementTree));
    
        elementTree.clear();
        if (!securityMode_.jsonEncode(elementTree))
        {
    	     Log(Error, "EndpointType json encoder error")
    		     .parameter("Element", "securityMode_");
            return false;
        }
        pt.push_back(std::make_pair("SecurityMode", elementTree));
    
        elementTree.clear();
        if (!securityPolicyUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "EndpointType json encoder error")
    		     .parameter("Element", "securityPolicyUri_");
            return false;
        }
        pt.push_back(std::make_pair("SecurityPolicyUri", elementTree));
    
        elementTree.clear();
        if (!transportProfileUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "EndpointType json encoder error")
    		     .parameter("Element", "transportProfileUri_");
            return false;
        }
        pt.push_back(std::make_pair("TransportProfileUri", elementTree));
    
        return true;
    }
    
    bool
    EndpointType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "EndpointUrl";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endpointUrl_.jsonDecode(*tree)) {
            Log(Error, "EndpointType decode json error - decode failed")
                .parameter("Element", "EndpointUrl");
            return false;
        }
    
        elementName = "SecurityMode";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityMode_.jsonDecode(*tree)) {
            Log(Error, "EndpointType decode json error - decode failed")
                .parameter("Element", "SecurityMode");
            return false;
        }
    
        elementName = "SecurityPolicyUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityPolicyUri_.jsonDecode(*tree)) {
            Log(Error, "EndpointType decode json error - decode failed")
                .parameter("Element", "SecurityPolicyUri");
            return false;
        }
    
        elementName = "TransportProfileUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EndpointType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportProfileUri_.jsonDecode(*tree)) {
            Log(Error, "EndpointType decode json error - decode failed")
                .parameter("Element", "TransportProfileUri");
            return false;
        }
    
        return true;
    }
    
    void
    EndpointType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EndpointType* dst = dynamic_cast<EndpointType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EndpointType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EndpointType* dst = dynamic_cast<EndpointType*>(&extensionObjectBase);
    	return *const_cast<EndpointType*>(this) == *dst;
    }
    
    void
    EndpointType::out(std::ostream& os)
    {
        os << "EndpointUrl="; endpointUrl_.out(os);
        os << ", SecurityMode="; securityMode_.out(os);
        os << ", SecurityPolicyUri="; securityPolicyUri_.out(os);
        os << ", TransportProfileUri="; transportProfileUri_.out(os);
    }

}
