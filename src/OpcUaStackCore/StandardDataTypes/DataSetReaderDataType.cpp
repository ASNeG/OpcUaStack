/*
    DataTypeClass: DataSetReaderDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataSetReaderDataType.h"

namespace OpcUaStackCore
{
    
    DataSetReaderDataType::DataSetReaderDataType(void)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , enabled_()
    , publisherId_()
    , writerGroupId_()
    , dataSetWriterId_()
    , dataSetMetaData_()
    , dataSetFieldContentMask_()
    , messageReceiveTimeout_()
    , securityMode_()
    , securityGroupId_()
    , securityKeyServices_()
    , dataSetReaderProperties_()
    , transportSettings_()
    , messageSettings_()
    , subscribedDataSet_()
    {
    }
    
    DataSetReaderDataType::~DataSetReaderDataType(void)
    {
    }
    
    OpcUaString&
    DataSetReaderDataType::name(void)
    {
        return name_;
    }
    
    OpcUaBoolean&
    DataSetReaderDataType::enabled(void)
    {
        return enabled_;
    }
    
    OpcUaVariant&
    DataSetReaderDataType::publisherId(void)
    {
        return publisherId_;
    }
    
    OpcUaUInt16&
    DataSetReaderDataType::writerGroupId(void)
    {
        return writerGroupId_;
    }
    
    OpcUaUInt16&
    DataSetReaderDataType::dataSetWriterId(void)
    {
        return dataSetWriterId_;
    }
    
    DataSetMetaDataType&
    DataSetReaderDataType::dataSetMetaData(void)
    {
        return dataSetMetaData_;
    }
    
    OpcUaDataSetFieldContentMask&
    DataSetReaderDataType::dataSetFieldContentMask(void)
    {
        return dataSetFieldContentMask_;
    }
    
    OpcUaDuration&
    DataSetReaderDataType::messageReceiveTimeout(void)
    {
        return messageReceiveTimeout_;
    }
    
    MessageSecurityMode&
    DataSetReaderDataType::securityMode(void)
    {
        return securityMode_;
    }
    
    OpcUaString&
    DataSetReaderDataType::securityGroupId(void)
    {
        return securityGroupId_;
    }
    
    EndpointDescriptionArray&
    DataSetReaderDataType::securityKeyServices(void)
    {
        return securityKeyServices_;
    }
    
    KeyValuePairArray&
    DataSetReaderDataType::dataSetReaderProperties(void)
    {
        return dataSetReaderProperties_;
    }
    
    OpcUaExtensibleParameter&
    DataSetReaderDataType::transportSettings(void)
    {
        return transportSettings_;
    }
    
    OpcUaExtensibleParameter&
    DataSetReaderDataType::messageSettings(void)
    {
        return messageSettings_;
    }
    
    OpcUaExtensibleParameter&
    DataSetReaderDataType::subscribedDataSet(void)
    {
        return subscribedDataSet_;
    }
    
    bool
    DataSetReaderDataType::operator==(const DataSetReaderDataType& value)
    {
        DataSetReaderDataType* dst = const_cast<DataSetReaderDataType*>(&value);
        if (name_ != dst->name()) return false;
        if (enabled_ != dst->enabled()) return false;
        if (publisherId_ != dst->publisherId()) return false;
        if (writerGroupId_ != dst->writerGroupId()) return false;
        if (dataSetWriterId_ != dst->dataSetWriterId()) return false;
        if (dataSetMetaData_ != dst->dataSetMetaData()) return false;
        if (dataSetFieldContentMask_ != dst->dataSetFieldContentMask()) return false;
        if (messageReceiveTimeout_ != dst->messageReceiveTimeout()) return false;
        if (securityMode_ != dst->securityMode()) return false;
        if (securityGroupId_ != dst->securityGroupId()) return false;
        if (securityKeyServices_ != dst->securityKeyServices()) return false;
        if (dataSetReaderProperties_ != dst->dataSetReaderProperties()) return false;
        if (transportSettings_ != dst->transportSettings()) return false;
        if (messageSettings_ != dst->messageSettings()) return false;
        if (subscribedDataSet_ != dst->subscribedDataSet()) return false;
        return true;
    }
    
    bool
    DataSetReaderDataType::operator!=(const DataSetReaderDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataSetReaderDataType::copyTo(DataSetReaderDataType& value)
    {
        name_.copyTo(value.name());
        value.enabled_ = enabled_;
        publisherId_.copyTo(value.publisherId());
        value.writerGroupId_ = writerGroupId_;
        value.dataSetWriterId_ = dataSetWriterId_;
        dataSetMetaData_.copyTo(value.dataSetMetaData());
        value.dataSetFieldContentMask_ = dataSetFieldContentMask_;
        value.messageReceiveTimeout_ = messageReceiveTimeout_;
        securityMode_.copyTo(value.securityMode());
        securityGroupId_.copyTo(value.securityGroupId());
        securityKeyServices_.copyTo(value.securityKeyServices());
        dataSetReaderProperties_.copyTo(value.dataSetReaderProperties());
        transportSettings_.copyTo(value.transportSettings());
        messageSettings_.copyTo(value.messageSettings());
        subscribedDataSet_.copyTo(value.subscribedDataSet());
    }
    
    DataSetReaderDataType&
    DataSetReaderDataType::operator=(const DataSetReaderDataType& value)
    {
        const_cast<DataSetReaderDataType*>(&value)->copyTo(*this);
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
    DataSetReaderDataType::factory(void)
    {
    	return constructSPtr<DataSetReaderDataType>();
    }
    
    std::string
    DataSetReaderDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataSetReaderDataType::typeName(void)
    {
    	return "DataSetReaderDataType";
    }
    
    OpcUaNodeId
    DataSetReaderDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15623,0);
    }
    
    OpcUaNodeId
    DataSetReaderDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15703, 0);
    }
    
    OpcUaNodeId
    DataSetReaderDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16007, 0);
    }
    
    OpcUaNodeId
    DataSetReaderDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16286, 0);
    }
    
    void
    DataSetReaderDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        name_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,enabled_);
        publisherId_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,writerGroupId_);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetWriterId_);
        dataSetMetaData_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetFieldContentMask_);
        OpcUaNumber::opcUaBinaryEncode(os,messageReceiveTimeout_);
        securityMode_.opcUaBinaryEncode(os);
        securityGroupId_.opcUaBinaryEncode(os);
        securityKeyServices_.opcUaBinaryEncode(os);
        dataSetReaderProperties_.opcUaBinaryEncode(os);
        transportSettings_.opcUaBinaryEncode(os);
        messageSettings_.opcUaBinaryEncode(os);
        subscribedDataSet_.opcUaBinaryEncode(os);
    }
    
    void
    DataSetReaderDataType::opcUaBinaryDecode(std::istream& is)
    {
        name_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,enabled_);
        publisherId_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,writerGroupId_);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetWriterId_);
        dataSetMetaData_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetFieldContentMask_);
        OpcUaNumber::opcUaBinaryDecode(is,messageReceiveTimeout_);
        securityMode_.opcUaBinaryDecode(is);
        securityGroupId_.opcUaBinaryDecode(is);
        securityKeyServices_.opcUaBinaryDecode(is);
        dataSetReaderProperties_.opcUaBinaryDecode(is);
        transportSettings_.opcUaBinaryDecode(is);
        messageSettings_.opcUaBinaryDecode(is);
        subscribedDataSet_.opcUaBinaryDecode(is);
    }
    
    bool
    DataSetReaderDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    DataSetReaderDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DataSetReaderDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataSetReaderDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
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
        if(!XmlNumber::xmlEncode(elementTree, writerGroupId_)) return false;
        pt.push_back(std::make_pair("WriterGroupId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetWriterId_)) return false;
        pt.push_back(std::make_pair("DataSetWriterId", elementTree));
    
        elementTree.clear();
        if (!dataSetMetaData_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DataSetMetaData", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetFieldContentMask_)) return false;
        pt.push_back(std::make_pair("DataSetFieldContentMask", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, messageReceiveTimeout_)) return false;
        pt.push_back(std::make_pair("MessageReceiveTimeout", elementTree));
    
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
        if (!dataSetReaderProperties_.xmlEncode(elementTree, "KeyValuePair", xmlns)) return false;
        pt.push_back(std::make_pair("DataSetReaderProperties", elementTree));
    
        elementTree.clear();
        if (!transportSettings_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TransportSettings", elementTree));
    
        elementTree.clear();
        if (!messageSettings_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("MessageSettings", elementTree));
    
        elementTree.clear();
        if (!subscribedDataSet_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SubscribedDataSet", elementTree));
    
        return true;
    }
    
    bool
    DataSetReaderDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataSetReaderDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
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
    
        tree = pt.get_child_optional("WriterGroupId");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, writerGroupId_)) return false;
    
        tree = pt.get_child_optional("DataSetWriterId");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, dataSetWriterId_)) return false;
    
        tree = pt.get_child_optional("DataSetMetaData");
        if (!tree) return false;
        if (!dataSetMetaData_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("DataSetFieldContentMask");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, dataSetFieldContentMask_)) return false;
    
        tree = pt.get_child_optional("MessageReceiveTimeout");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, messageReceiveTimeout_)) return false;
    
        tree = pt.get_child_optional("SecurityMode");
        if (!tree) return false;
        if (!securityMode_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SecurityGroupId");
        if (!tree) return false;
        if (!securityGroupId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SecurityKeyServices");
        if (!tree) return false;
        if (!securityKeyServices_.xmlDecode(*tree, "EndpointDescription", xmlns)) return false;
    
        tree = pt.get_child_optional("DataSetReaderProperties");
        if (!tree) return false;
        if (!dataSetReaderProperties_.xmlDecode(*tree, "KeyValuePair", xmlns)) return false;
    
        tree = pt.get_child_optional("TransportSettings");
        if (!tree) return false;
        if (!transportSettings_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("MessageSettings");
        if (!tree) return false;
        if (!messageSettings_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SubscribedDataSet");
        if (!tree) return false;
        if (!subscribedDataSet_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    DataSetReaderDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    DataSetReaderDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    DataSetReaderDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    DataSetReaderDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    DataSetReaderDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataSetReaderDataType* dst = dynamic_cast<DataSetReaderDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataSetReaderDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataSetReaderDataType* dst = dynamic_cast<DataSetReaderDataType*>(&extensionObjectBase);
    	return *const_cast<DataSetReaderDataType*>(this) == *dst;
    }
    
    void
    DataSetReaderDataType::out(std::ostream& os)
    {
        os << "Name="; name_.out(os);
        os << ", Enabled=" << enabled_;
        os << ", PublisherId="; publisherId_.out(os);
        os << ", WriterGroupId=" << writerGroupId_;
        os << ", DataSetWriterId=" << dataSetWriterId_;
        os << ", DataSetMetaData="; dataSetMetaData_.out(os);
        os << ", DataSetFieldContentMask=" << dataSetFieldContentMask_;
        os << ", MessageReceiveTimeout=" << messageReceiveTimeout_;
        os << ", SecurityMode="; securityMode_.out(os);
        os << ", SecurityGroupId="; securityGroupId_.out(os);
        os << ", SecurityKeyServices="; securityKeyServices_.out(os);
        os << ", DataSetReaderProperties="; dataSetReaderProperties_.out(os);
        os << ", TransportSettings="; transportSettings_.out(os);
        os << ", MessageSettings="; messageSettings_.out(os);
        os << ", SubscribedDataSet="; subscribedDataSet_.out(os);
    }

}
