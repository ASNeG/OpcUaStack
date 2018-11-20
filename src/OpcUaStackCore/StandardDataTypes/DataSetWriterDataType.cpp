/*
    DataTypeClass: DataSetWriterDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataSetWriterDataType.h"

namespace OpcUaStackCore
{
    
    DataSetWriterDataType::DataSetWriterDataType(void)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , enabled_()
    , dataSetWriterId_()
    , dataSetFieldContentMask_()
    , keyFrameCount_()
    , dataSetName_()
    , dataSetWriterProperties_()
    , transportSettings_()
    , messageSettings_()
    {
    }
    
    DataSetWriterDataType::~DataSetWriterDataType(void)
    {
    }
    
    OpcUaString&
    DataSetWriterDataType::name(void)
    {
        return name_;
    }
    
    OpcUaBoolean&
    DataSetWriterDataType::enabled(void)
    {
        return enabled_;
    }
    
    OpcUaUInt16&
    DataSetWriterDataType::dataSetWriterId(void)
    {
        return dataSetWriterId_;
    }
    
    OpcUaDataSetFieldContentMask&
    DataSetWriterDataType::dataSetFieldContentMask(void)
    {
        return dataSetFieldContentMask_;
    }
    
    OpcUaUInt32&
    DataSetWriterDataType::keyFrameCount(void)
    {
        return keyFrameCount_;
    }
    
    OpcUaString&
    DataSetWriterDataType::dataSetName(void)
    {
        return dataSetName_;
    }
    
    KeyValuePairArray&
    DataSetWriterDataType::dataSetWriterProperties(void)
    {
        return dataSetWriterProperties_;
    }
    
    OpcUaExtensibleParameter&
    DataSetWriterDataType::transportSettings(void)
    {
        return transportSettings_;
    }
    
    OpcUaExtensibleParameter&
    DataSetWriterDataType::messageSettings(void)
    {
        return messageSettings_;
    }
    
    bool
    DataSetWriterDataType::operator==(const DataSetWriterDataType& value)
    {
        DataSetWriterDataType* dst = const_cast<DataSetWriterDataType*>(&value);
        if (name_ != dst->name()) return false;
        if (enabled_ != dst->enabled()) return false;
        if (dataSetWriterId_ != dst->dataSetWriterId()) return false;
        if (dataSetFieldContentMask_ != dst->dataSetFieldContentMask()) return false;
        if (keyFrameCount_ != dst->keyFrameCount()) return false;
        if (dataSetName_ != dst->dataSetName()) return false;
        if (dataSetWriterProperties_ != dst->dataSetWriterProperties()) return false;
        if (transportSettings_ != dst->transportSettings()) return false;
        if (messageSettings_ != dst->messageSettings()) return false;
        return true;
    }
    
    bool
    DataSetWriterDataType::operator!=(const DataSetWriterDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataSetWriterDataType::copyTo(DataSetWriterDataType& value)
    {
        name_.copyTo(value.name());
        value.enabled_ = enabled_;
        value.dataSetWriterId_ = dataSetWriterId_;
        value.dataSetFieldContentMask_ = dataSetFieldContentMask_;
        value.keyFrameCount_ = keyFrameCount_;
        dataSetName_.copyTo(value.dataSetName());
        dataSetWriterProperties_.copyTo(value.dataSetWriterProperties());
        transportSettings_.copyTo(value.transportSettings());
        messageSettings_.copyTo(value.messageSettings());
    }
    
    DataSetWriterDataType&
    DataSetWriterDataType::operator=(const DataSetWriterDataType& value)
    {
        const_cast<DataSetWriterDataType*>(&value)->copyTo(*this);
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
    DataSetWriterDataType::factory(void)
    {
    	return constructSPtr<DataSetWriterDataType>();
    }
    
    std::string
    DataSetWriterDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataSetWriterDataType::typeName(void)
    {
    	return "DataSetWriterDataType";
    }
    
    OpcUaNodeId
    DataSetWriterDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15597,0);
    }
    
    OpcUaNodeId
    DataSetWriterDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15682, 0);
    }
    
    OpcUaNodeId
    DataSetWriterDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15955, 0);
    }
    
    OpcUaNodeId
    DataSetWriterDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16156, 0);
    }
    
    void
    DataSetWriterDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        name_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,enabled_);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetWriterId_);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetFieldContentMask_);
        OpcUaNumber::opcUaBinaryEncode(os,keyFrameCount_);
        dataSetName_.opcUaBinaryEncode(os);
        dataSetWriterProperties_.opcUaBinaryEncode(os);
        transportSettings_.opcUaBinaryEncode(os);
        messageSettings_.opcUaBinaryEncode(os);
    }
    
    void
    DataSetWriterDataType::opcUaBinaryDecode(std::istream& is)
    {
        name_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,enabled_);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetWriterId_);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetFieldContentMask_);
        OpcUaNumber::opcUaBinaryDecode(is,keyFrameCount_);
        dataSetName_.opcUaBinaryDecode(is);
        dataSetWriterProperties_.opcUaBinaryDecode(is);
        transportSettings_.opcUaBinaryDecode(is);
        messageSettings_.opcUaBinaryDecode(is);
    }
    
    bool
    DataSetWriterDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    DataSetWriterDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DataSetWriterDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataSetWriterDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, enabled_)) return false;
        pt.push_back(std::make_pair("Enabled", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetWriterId_)) return false;
        pt.push_back(std::make_pair("DataSetWriterId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetFieldContentMask_)) return false;
        pt.push_back(std::make_pair("DataSetFieldContentMask", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, keyFrameCount_)) return false;
        pt.push_back(std::make_pair("KeyFrameCount", elementTree));
    
        elementTree.clear();
        if (!dataSetName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DataSetName", elementTree));
    
        elementTree.clear();
        if (!dataSetWriterProperties_.xmlEncode(elementTree, "KeyValuePair", xmlns)) return false;
        pt.push_back(std::make_pair("DataSetWriterProperties", elementTree));
    
        elementTree.clear();
        if (!transportSettings_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TransportSettings", elementTree));
    
        elementTree.clear();
        if (!messageSettings_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("MessageSettings", elementTree));
    
        return true;
    }
    
    bool
    DataSetWriterDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataSetWriterDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Name");
        if (!tree) return false;
        if (!name_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Enabled");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, enabled_)) return false;
    
        tree = pt.get_child_optional("DataSetWriterId");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, dataSetWriterId_)) return false;
    
        tree = pt.get_child_optional("DataSetFieldContentMask");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, dataSetFieldContentMask_)) return false;
    
        tree = pt.get_child_optional("KeyFrameCount");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, keyFrameCount_)) return false;
    
        tree = pt.get_child_optional("DataSetName");
        if (!tree) return false;
        if (!dataSetName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("DataSetWriterProperties");
        if (!tree) return false;
        if (!dataSetWriterProperties_.xmlDecode(*tree, "KeyValuePair", xmlns)) return false;
    
        tree = pt.get_child_optional("TransportSettings");
        if (!tree) return false;
        if (!transportSettings_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("MessageSettings");
        if (!tree) return false;
        if (!messageSettings_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    DataSetWriterDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    DataSetWriterDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    DataSetWriterDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    DataSetWriterDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    DataSetWriterDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataSetWriterDataType* dst = dynamic_cast<DataSetWriterDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataSetWriterDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataSetWriterDataType* dst = dynamic_cast<DataSetWriterDataType*>(&extensionObjectBase);
    	return *const_cast<DataSetWriterDataType*>(this) == *dst;
    }
    
    void
    DataSetWriterDataType::out(std::ostream& os)
    {
        os << "Name="; name_.out(os);
        os << ", Enabled=" << enabled_;
        os << ", DataSetWriterId=" << dataSetWriterId_;
        os << ", DataSetFieldContentMask=" << dataSetFieldContentMask_;
        os << ", KeyFrameCount=" << keyFrameCount_;
        os << ", DataSetName="; dataSetName_.out(os);
        os << ", DataSetWriterProperties="; dataSetWriterProperties_.out(os);
        os << ", TransportSettings="; transportSettings_.out(os);
        os << ", MessageSettings="; messageSettings_.out(os);
    }

}
