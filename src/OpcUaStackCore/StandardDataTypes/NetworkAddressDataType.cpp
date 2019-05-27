/*
    DataTypeClass: NetworkAddressDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/NetworkAddressDataType.h"

namespace OpcUaStackCore
{
    
    NetworkAddressDataType::NetworkAddressDataType(void)
    : Object()
    , ExtensionObjectBase()
    , networkInterface_()
    {
    }
    
    NetworkAddressDataType::NetworkAddressDataType(const NetworkAddressDataType& value)
    : Object()
    , ExtensionObjectBase()
    , networkInterface_()
    {
        const_cast<NetworkAddressDataType*>(&value)->copyTo(*this);
    }
    
    NetworkAddressDataType::~NetworkAddressDataType(void)
    {
    }
    
    OpcUaString&
    NetworkAddressDataType::networkInterface(void)
    {
        return networkInterface_;
    }
    
    bool
    NetworkAddressDataType::operator==(const NetworkAddressDataType& value)
    {
        NetworkAddressDataType* dst = const_cast<NetworkAddressDataType*>(&value);
        if (networkInterface_ != dst->networkInterface()) return false;
        return true;
    }
    
    bool
    NetworkAddressDataType::operator!=(const NetworkAddressDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    NetworkAddressDataType::copyTo(NetworkAddressDataType& value)
    {
        networkInterface_.copyTo(value.networkInterface());
    }
    
    NetworkAddressDataType&
    NetworkAddressDataType::operator=(const NetworkAddressDataType& value)
    {
        const_cast<NetworkAddressDataType*>(&value)->copyTo(*this);
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
    NetworkAddressDataType::factory(void)
    {
    	return constructSPtr<NetworkAddressDataType>();
    }
    
    std::string
    NetworkAddressDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    NetworkAddressDataType::typeName(void)
    {
    	return "NetworkAddressDataType";
    }
    
    OpcUaNodeId
    NetworkAddressDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15502,0);
    }
    
    OpcUaNodeId
    NetworkAddressDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21151, 0);
    }
    
    OpcUaNodeId
    NetworkAddressDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21175, 0);
    }
    
    OpcUaNodeId
    NetworkAddressDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21199, 0);
    }
    
    void
    NetworkAddressDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        networkInterface_.opcUaBinaryEncode(os);
    }
    
    void
    NetworkAddressDataType::opcUaBinaryDecode(std::istream& is)
    {
        networkInterface_.opcUaBinaryDecode(is);
    }
    
    bool
    NetworkAddressDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "NetworkAddressDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    NetworkAddressDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!networkInterface_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "NetworkAddressDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NetworkInterface", elementTree));
    
        return true;
    }
    
    bool
    NetworkAddressDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NetworkAddressDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    NetworkAddressDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("NetworkInterface");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NetworkAddressDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!networkInterface_.xmlDecode(*tree, xmlns)) {
            Log(Error, "NetworkAddressDataType decode xml error - decode failed")
                .parameter("Element", "NetworkInterface");
            return false;
        }
    
        return true;
    }
    
    bool
    NetworkAddressDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!networkInterface_.jsonEncode(elementTree))
        {
    	     Log(Error, "NetworkAddressDataType json encoder error")
    		     .parameter("Element", "networkInterface_");
            return false;
        }
        pt.push_back(std::make_pair("NetworkInterface", elementTree));
    
        return true;
    }
    
    bool
    NetworkAddressDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "NetworkInterface";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NetworkAddressDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!networkInterface_.jsonDecode(*tree)) {
            Log(Error, "NetworkAddressDataType decode json error - decode failed")
                .parameter("Element", "NetworkInterface");
            return false;
        }
    
        return true;
    }
    
    void
    NetworkAddressDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	NetworkAddressDataType* dst = dynamic_cast<NetworkAddressDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    NetworkAddressDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	NetworkAddressDataType* dst = dynamic_cast<NetworkAddressDataType*>(&extensionObjectBase);
    	return *const_cast<NetworkAddressDataType*>(this) == *dst;
    }
    
    void
    NetworkAddressDataType::out(std::ostream& os)
    {
        os << "NetworkInterface="; networkInterface_.out(os);
    }

}
