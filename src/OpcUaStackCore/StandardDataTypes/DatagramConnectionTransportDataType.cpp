/*
    DataTypeClass: DatagramConnectionTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
    
    DatagramConnectionTransportDataType::DatagramConnectionTransportDataType(const DatagramConnectionTransportDataType& value)
    : ConnectionTransportDataType()
    , discoveryAddress_()
    {
        const_cast<DatagramConnectionTransportDataType*>(&value)->copyTo(*this);
    }
    
    DatagramConnectionTransportDataType::~DatagramConnectionTransportDataType(void)
    {
    }
    
    OpcUaExtensibleParameter&
    DatagramConnectionTransportDataType::discoveryAddress(void)
    {
        return discoveryAddress_;
    }
    
    bool
    DatagramConnectionTransportDataType::operator==(const DatagramConnectionTransportDataType& value)
    {
        DatagramConnectionTransportDataType* dst = const_cast<DatagramConnectionTransportDataType*>(&value);
        if (discoveryAddress_ != dst->discoveryAddress()) return false;
        return true;
    }
    
    bool
    DatagramConnectionTransportDataType::operator!=(const DatagramConnectionTransportDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    DatagramConnectionTransportDataType::copyTo(DatagramConnectionTransportDataType& value)
    {
        discoveryAddress_.copyTo(value.discoveryAddress());
    }
    
    DatagramConnectionTransportDataType&
    DatagramConnectionTransportDataType::operator=(const DatagramConnectionTransportDataType& value)
    {
        const_cast<DatagramConnectionTransportDataType*>(&value)->copyTo(*this);
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
    DatagramConnectionTransportDataType::factory(void)
    {
    	return constructSPtr<DatagramConnectionTransportDataType>();
    }
    
    std::string
    DatagramConnectionTransportDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DatagramConnectionTransportDataType::typeName(void)
    {
    	return "DatagramConnectionTransportDataType";
    }
    
    OpcUaNodeId
    DatagramConnectionTransportDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)17467,0);
    }
    
    OpcUaNodeId
    DatagramConnectionTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)17468, 0);
    }
    
    OpcUaNodeId
    DatagramConnectionTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)17472, 0);
    }
    
    OpcUaNodeId
    DatagramConnectionTransportDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)17476, 0);
    }
    
    void
    DatagramConnectionTransportDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        ConnectionTransportDataType::opcUaBinaryEncode(os);
        discoveryAddress_.opcUaBinaryEncode(os);
    }
    
    void
    DatagramConnectionTransportDataType::opcUaBinaryDecode(std::istream& is)
    {
        ConnectionTransportDataType::opcUaBinaryDecode(is);
        discoveryAddress_.opcUaBinaryDecode(is);
    }
    
    bool
    DatagramConnectionTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DatagramConnectionTransportDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DatagramConnectionTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!discoveryAddress_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DatagramConnectionTransportDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DiscoveryAddress", elementTree));
    
        return true;
    }
    
    bool
    DatagramConnectionTransportDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DatagramConnectionTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DatagramConnectionTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("DiscoveryAddress");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DatagramConnectionTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!discoveryAddress_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DatagramConnectionTransportDataType decode xml error - decode failed")
                .parameter("Element", "DiscoveryAddress");
            return false;
        }
    
        return true;
    }
    
    bool
    DatagramConnectionTransportDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!discoveryAddress_.jsonEncode(elementTree))
        {
    	     Log(Error, "DatagramConnectionTransportDataType json encoder error")
    		     .parameter("Element", "discoveryAddress_");
            return false;
        }
        pt.push_back(std::make_pair("DiscoveryAddress", elementTree));
    
        return true;
    }
    
    bool
    DatagramConnectionTransportDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "DiscoveryAddress";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DatagramConnectionTransportDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!discoveryAddress_.jsonDecode(*tree)) {
            Log(Error, "DatagramConnectionTransportDataType decode json error - decode failed")
                .parameter("Element", "DiscoveryAddress");
            return false;
        }
    
        return true;
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
    	return *const_cast<DatagramConnectionTransportDataType*>(this) == *dst;
    }
    
    void
    DatagramConnectionTransportDataType::out(std::ostream& os)
    {
        os << "DiscoveryAddress="; discoveryAddress_.out(os);
    }

}
