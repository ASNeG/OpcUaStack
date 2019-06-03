/*
    DataTypeClass: PubSubConnectionDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/PubSubConnectionDataType.h"

namespace OpcUaStackCore
{
    
    PubSubConnectionDataType::PubSubConnectionDataType(void)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , enabled_()
    , publisherId_()
    , transportProfileUri_()
    , address_()
    , connectionProperties_()
    , transportSettings_()
    , writerGroups_()
    , readerGroups_()
    {
    }
    
    PubSubConnectionDataType::PubSubConnectionDataType(const PubSubConnectionDataType& value)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , enabled_()
    , publisherId_()
    , transportProfileUri_()
    , address_()
    , connectionProperties_()
    , transportSettings_()
    , writerGroups_()
    , readerGroups_()
    {
        const_cast<PubSubConnectionDataType*>(&value)->copyTo(*this);
    }
    
    PubSubConnectionDataType::~PubSubConnectionDataType(void)
    {
    }
    
    OpcUaString&
    PubSubConnectionDataType::name(void)
    {
        return name_;
    }
    
    OpcUaBoolean&
    PubSubConnectionDataType::enabled(void)
    {
        return enabled_;
    }
    
    OpcUaVariant&
    PubSubConnectionDataType::publisherId(void)
    {
        return publisherId_;
    }
    
    OpcUaString&
    PubSubConnectionDataType::transportProfileUri(void)
    {
        return transportProfileUri_;
    }
    
    OpcUaExtensibleParameter&
    PubSubConnectionDataType::address(void)
    {
        return address_;
    }
    
    KeyValuePairArray&
    PubSubConnectionDataType::connectionProperties(void)
    {
        return connectionProperties_;
    }
    
    OpcUaExtensibleParameter&
    PubSubConnectionDataType::transportSettings(void)
    {
        return transportSettings_;
    }
    
    WriterGroupDataTypeArray&
    PubSubConnectionDataType::writerGroups(void)
    {
        return writerGroups_;
    }
    
    ReaderGroupDataTypeArray&
    PubSubConnectionDataType::readerGroups(void)
    {
        return readerGroups_;
    }
    
    bool
    PubSubConnectionDataType::operator==(const PubSubConnectionDataType& value)
    {
        PubSubConnectionDataType* dst = const_cast<PubSubConnectionDataType*>(&value);
        if (name_ != dst->name()) return false;
        if (enabled_ != dst->enabled()) return false;
        if (publisherId_ != dst->publisherId()) return false;
        if (transportProfileUri_ != dst->transportProfileUri()) return false;
        if (address_ != dst->address()) return false;
        if (connectionProperties_ != dst->connectionProperties()) return false;
        if (transportSettings_ != dst->transportSettings()) return false;
        if (writerGroups_ != dst->writerGroups()) return false;
        if (readerGroups_ != dst->readerGroups()) return false;
        return true;
    }
    
    bool
    PubSubConnectionDataType::operator!=(const PubSubConnectionDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    PubSubConnectionDataType::copyTo(PubSubConnectionDataType& value)
    {
        name_.copyTo(value.name());
        value.enabled_ = enabled_;
        publisherId_.copyTo(value.publisherId());
        transportProfileUri_.copyTo(value.transportProfileUri());
        address_.copyTo(value.address());
        connectionProperties_.copyTo(value.connectionProperties());
        transportSettings_.copyTo(value.transportSettings());
        writerGroups_.copyTo(value.writerGroups());
        readerGroups_.copyTo(value.readerGroups());
    }
    
    PubSubConnectionDataType&
    PubSubConnectionDataType::operator=(const PubSubConnectionDataType& value)
    {
        const_cast<PubSubConnectionDataType*>(&value)->copyTo(*this);
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
    PubSubConnectionDataType::factory(void)
    {
    	return constructSPtr<PubSubConnectionDataType>();
    }
    
    std::string
    PubSubConnectionDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    PubSubConnectionDataType::typeName(void)
    {
    	return "PubSubConnectionDataType";
    }
    
    OpcUaNodeId
    PubSubConnectionDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15617,0);
    }
    
    OpcUaNodeId
    PubSubConnectionDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15694, 0);
    }
    
    OpcUaNodeId
    PubSubConnectionDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15992, 0);
    }
    
    OpcUaNodeId
    PubSubConnectionDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16281, 0);
    }
    
    void
    PubSubConnectionDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        name_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,enabled_);
        publisherId_.opcUaBinaryEncode(os);
        transportProfileUri_.opcUaBinaryEncode(os);
        address_.opcUaBinaryEncode(os);
        connectionProperties_.opcUaBinaryEncode(os);
        transportSettings_.opcUaBinaryEncode(os);
        writerGroups_.opcUaBinaryEncode(os);
        readerGroups_.opcUaBinaryEncode(os);
    }
    
    void
    PubSubConnectionDataType::opcUaBinaryDecode(std::istream& is)
    {
        name_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,enabled_);
        publisherId_.opcUaBinaryDecode(is);
        transportProfileUri_.opcUaBinaryDecode(is);
        address_.opcUaBinaryDecode(is);
        connectionProperties_.opcUaBinaryDecode(is);
        transportSettings_.opcUaBinaryDecode(is);
        writerGroups_.opcUaBinaryDecode(is);
        readerGroups_.opcUaBinaryDecode(is);
    }
    
    bool
    PubSubConnectionDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "PubSubConnectionDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PubSubConnectionDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PubSubConnectionDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, enabled_))
        {
            Log(Error, "PubSubConnectionDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Enabled", elementTree));
    
        elementTree.clear();
        if (!publisherId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PubSubConnectionDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublisherId", elementTree));
    
        elementTree.clear();
        if (!transportProfileUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PubSubConnectionDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TransportProfileUri", elementTree));
    
        elementTree.clear();
        if (!address_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PubSubConnectionDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Address", elementTree));
    
        elementTree.clear();
        if (!connectionProperties_.xmlEncode(elementTree, "KeyValuePair", xmlns)) {
            Log(Error, "PubSubConnectionDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ConnectionProperties", elementTree));
    
        elementTree.clear();
        if (!transportSettings_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "PubSubConnectionDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TransportSettings", elementTree));
    
        elementTree.clear();
        if (!writerGroups_.xmlEncode(elementTree, "WriterGroupDataType", xmlns)) {
            Log(Error, "PubSubConnectionDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("WriterGroups", elementTree));
    
        elementTree.clear();
        if (!readerGroups_.xmlEncode(elementTree, "ReaderGroupDataType", xmlns)) {
            Log(Error, "PubSubConnectionDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ReaderGroups", elementTree));
    
        return true;
    }
    
    bool
    PubSubConnectionDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConnectionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PubSubConnectionDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Name");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConnectionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PubSubConnectionDataType decode xml error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        elementName = xmlns.addPrefix("Enabled");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConnectionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, enabled_)) {
            Log(Error, "PubSubConnectionDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("PublisherId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConnectionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publisherId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PubSubConnectionDataType decode xml error - decode failed")
                .parameter("Element", "PublisherId");
            return false;
        }
    
        elementName = xmlns.addPrefix("TransportProfileUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConnectionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportProfileUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PubSubConnectionDataType decode xml error - decode failed")
                .parameter("Element", "TransportProfileUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("Address");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConnectionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!address_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PubSubConnectionDataType decode xml error - decode failed")
                .parameter("Element", "Address");
            return false;
        }
    
        elementName = xmlns.addPrefix("ConnectionProperties");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConnectionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!connectionProperties_.xmlDecode(*tree, "KeyValuePair", xmlns)) {
            Log(Error, "PubSubConnectionDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TransportSettings");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConnectionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportSettings_.xmlDecode(*tree, xmlns)) {
            Log(Error, "PubSubConnectionDataType decode xml error - decode failed")
                .parameter("Element", "TransportSettings");
            return false;
        }
    
        elementName = xmlns.addPrefix("WriterGroups");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConnectionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!writerGroups_.xmlDecode(*tree, "WriterGroupDataType", xmlns)) {
            Log(Error, "PubSubConnectionDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ReaderGroups");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "PubSubConnectionDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!readerGroups_.xmlDecode(*tree, "ReaderGroupDataType", xmlns)) {
            Log(Error, "PubSubConnectionDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    PubSubConnectionDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, name_, "Name");
        rc = rc & jsonNumberEncode(pt, enabled_, "Enabled");
        rc = rc & jsonObjectEncode(pt, publisherId_, "PublisherId");
        rc = rc & jsonObjectEncode(pt, transportProfileUri_, "TransportProfileUri");
        rc = rc & jsonObjectEncode(pt, address_, "Address");
        rc = rc & jsonObjectEncode(pt, connectionProperties_, "ConnectionProperties");
        rc = rc & jsonObjectEncode(pt, transportSettings_, "TransportSettings");
        rc = rc & jsonObjectEncode(pt, writerGroups_, "WriterGroups");
        rc = rc & jsonObjectEncode(pt, readerGroups_, "ReaderGroups");
    
        return rc;
    }
    
    bool
    PubSubConnectionDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, name_, "Name");
        rc = rc & jsonNumberDecode(pt, enabled_, "Enabled");
        rc = rc & jsonObjectDecode(pt, publisherId_, "PublisherId");
        rc = rc & jsonObjectDecode(pt, transportProfileUri_, "TransportProfileUri");
        rc = rc & jsonObjectDecode(pt, address_, "Address");
        rc = rc & jsonObjectDecode(pt, connectionProperties_, "ConnectionProperties");
        rc = rc & jsonObjectDecode(pt, transportSettings_, "TransportSettings");
        rc = rc & jsonObjectDecode(pt, writerGroups_, "WriterGroups");
        rc = rc & jsonObjectDecode(pt, readerGroups_, "ReaderGroups");
    
        return rc;
    }
    
    void
    PubSubConnectionDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	PubSubConnectionDataType* dst = dynamic_cast<PubSubConnectionDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    PubSubConnectionDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	PubSubConnectionDataType* dst = dynamic_cast<PubSubConnectionDataType*>(&extensionObjectBase);
    	return *const_cast<PubSubConnectionDataType*>(this) == *dst;
    }
    
    void
    PubSubConnectionDataType::out(std::ostream& os)
    {
        os << "Name="; name_.out(os);
        os << ", Enabled=" << enabled_;
        os << ", PublisherId="; publisherId_.out(os);
        os << ", TransportProfileUri="; transportProfileUri_.out(os);
        os << ", Address="; address_.out(os);
        os << ", ConnectionProperties="; connectionProperties_.out(os);
        os << ", TransportSettings="; transportSettings_.out(os);
        os << ", WriterGroups="; writerGroups_.out(os);
        os << ", ReaderGroups="; readerGroups_.out(os);
    }

}
