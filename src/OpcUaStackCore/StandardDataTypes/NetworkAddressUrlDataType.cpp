/*
    DataTypeClass: NetworkAddressUrlDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/NetworkAddressUrlDataType.h"

namespace OpcUaStackCore
{
    
    NetworkAddressUrlDataType::NetworkAddressUrlDataType(void)
    : NetworkAddressDataType()
    , url_()
    {
    }
    
    NetworkAddressUrlDataType::NetworkAddressUrlDataType(const NetworkAddressUrlDataType& value)
    : NetworkAddressDataType()
    , url_()
    {
        const_cast<NetworkAddressUrlDataType*>(&value)->copyTo(*this);
    }
    
    NetworkAddressUrlDataType::~NetworkAddressUrlDataType(void)
    {
    }
    
    OpcUaString&
    NetworkAddressUrlDataType::url(void)
    {
        return url_;
    }
    
    bool
    NetworkAddressUrlDataType::operator==(const NetworkAddressUrlDataType& value)
    {
        NetworkAddressUrlDataType* dst = const_cast<NetworkAddressUrlDataType*>(&value);
        if (url_ != dst->url()) return false;
        return true;
    }
    
    bool
    NetworkAddressUrlDataType::operator!=(const NetworkAddressUrlDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    NetworkAddressUrlDataType::copyTo(NetworkAddressUrlDataType& value)
    {
        url_.copyTo(value.url());
    }
    
    NetworkAddressUrlDataType&
    NetworkAddressUrlDataType::operator=(const NetworkAddressUrlDataType& value)
    {
        const_cast<NetworkAddressUrlDataType*>(&value)->copyTo(*this);
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
    NetworkAddressUrlDataType::factory(void)
    {
    	return constructSPtr<NetworkAddressUrlDataType>();
    }
    
    std::string
    NetworkAddressUrlDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    NetworkAddressUrlDataType::typeName(void)
    {
    	return "NetworkAddressUrlDataType";
    }
    
    OpcUaNodeId
    NetworkAddressUrlDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15510,0);
    }
    
    OpcUaNodeId
    NetworkAddressUrlDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21152, 0);
    }
    
    OpcUaNodeId
    NetworkAddressUrlDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21176, 0);
    }
    
    OpcUaNodeId
    NetworkAddressUrlDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21200, 0);
    }
    
    void
    NetworkAddressUrlDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        NetworkAddressDataType::opcUaBinaryEncode(os);
        url_.opcUaBinaryEncode(os);
    }
    
    void
    NetworkAddressUrlDataType::opcUaBinaryDecode(std::istream& is)
    {
        NetworkAddressDataType::opcUaBinaryDecode(is);
        url_.opcUaBinaryDecode(is);
    }
    
    bool
    NetworkAddressUrlDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "NetworkAddressUrlDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    NetworkAddressUrlDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!url_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "NetworkAddressUrlDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Url", elementTree));
    
        return true;
    }
    
    bool
    NetworkAddressUrlDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NetworkAddressUrlDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    NetworkAddressUrlDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Url");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NetworkAddressUrlDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!url_.xmlDecode(*tree, xmlns)) {
            Log(Error, "NetworkAddressUrlDataType decode xml error - decode failed")
                .parameter("Element", "Url");
            return false;
        }
    
        return true;
    }
    
    bool
    NetworkAddressUrlDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!url_.jsonEncode(elementTree))
        {
    	     Log(Error, "NetworkAddressUrlDataType json encoder error")
    		     .parameter("Element", "url_");
            return false;
        }
        pt.push_back(std::make_pair("Url", elementTree));
    
        return true;
    }
    
    bool
    NetworkAddressUrlDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Url";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NetworkAddressUrlDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!url_.jsonDecode(*tree)) {
            Log(Error, "NetworkAddressUrlDataType decode json error - decode failed")
                .parameter("Element", "Url");
            return false;
        }
    
        return true;
    }
    
    void
    NetworkAddressUrlDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	NetworkAddressUrlDataType* dst = dynamic_cast<NetworkAddressUrlDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    NetworkAddressUrlDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	NetworkAddressUrlDataType* dst = dynamic_cast<NetworkAddressUrlDataType*>(&extensionObjectBase);
    	return *const_cast<NetworkAddressUrlDataType*>(this) == *dst;
    }
    
    void
    NetworkAddressUrlDataType::out(std::ostream& os)
    {
        os << "Url="; url_.out(os);
    }

}
