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
    PubSubConnectionDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    PubSubConnectionDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    PubSubConnectionDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    PubSubConnectionDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, enabled_)) return false;
        pt.push_back(std::make_pair("Enabled", elementTree));
    
        elementTree.clear();
        if (!publisherId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("PublisherId", elementTree));
    
        elementTree.clear();
        if (!transportProfileUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TransportProfileUri", elementTree));
    
        elementTree.clear();
        if (!address_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Address", elementTree));
    
        elementTree.clear();
        if (!connectionProperties_.xmlEncode(elementTree, "KeyValuePair", xmlns)) return false;
        pt.push_back(std::make_pair("ConnectionProperties", elementTree));
    
        elementTree.clear();
        if (!transportSettings_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TransportSettings", elementTree));
    
        elementTree.clear();
        if (!writerGroups_.xmlEncode(elementTree, "WriterGroupDataType", xmlns)) return false;
        pt.push_back(std::make_pair("WriterGroups", elementTree));
    
        elementTree.clear();
        if (!readerGroups_.xmlEncode(elementTree, "ReaderGroupDataType", xmlns)) return false;
        pt.push_back(std::make_pair("ReaderGroups", elementTree));
    
        return true;
    }
    
    bool
    PubSubConnectionDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    PubSubConnectionDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Name");
        if (!tree) return false;
        if (!name_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Enabled");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, enabled_)) return false;
    
        tree = pt.get_child_optional("PublisherId");
        if (!tree) return false;
        if (!publisherId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("TransportProfileUri");
        if (!tree) return false;
        if (!transportProfileUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Address");
        if (!tree) return false;
        if (!address_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ConnectionProperties");
        if (!tree) return false;
        if (!connectionProperties_.xmlDecode(*tree, "KeyValuePair", xmlns)) return false;
    
        tree = pt.get_child_optional("TransportSettings");
        if (!tree) return false;
        if (!transportSettings_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("WriterGroups");
        if (!tree) return false;
        if (!writerGroups_.xmlDecode(*tree, "WriterGroupDataType", xmlns)) return false;
    
        tree = pt.get_child_optional("ReaderGroups");
        if (!tree) return false;
        if (!readerGroups_.xmlDecode(*tree, "ReaderGroupDataType", xmlns)) return false;
    
        return true;
    }
    
    bool
    PubSubConnectionDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    PubSubConnectionDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    PubSubConnectionDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    PubSubConnectionDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
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
