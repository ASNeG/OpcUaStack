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
    
    DataSetReaderDataType::DataSetReaderDataType(const DataSetReaderDataType& value)
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
        const_cast<DataSetReaderDataType*>(&value)->copyTo(*this);
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
    	return boost::make_shared<DataSetReaderDataType>();
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
    DataSetReaderDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetReaderDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataSetReaderDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, enabled_))
        {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Enabled", elementTree));
    
        elementTree.clear();
        if (!publisherId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublisherId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, writerGroupId_))
        {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("WriterGroupId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetWriterId_))
        {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetWriterId", elementTree));
    
        elementTree.clear();
        if (!dataSetMetaData_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetMetaData", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetFieldContentMask_))
        {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetFieldContentMask", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, messageReceiveTimeout_))
        {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MessageReceiveTimeout", elementTree));
    
        elementTree.clear();
        if (!securityMode_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityMode", elementTree));
    
        elementTree.clear();
        if (!securityGroupId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityGroupId", elementTree));
    
        elementTree.clear();
        if (!securityKeyServices_.xmlEncode(elementTree, "EndpointDescription", xmlns)) {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityKeyServices", elementTree));
    
        elementTree.clear();
        if (!dataSetReaderProperties_.xmlEncode(elementTree, "KeyValuePair", xmlns)) {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetReaderProperties", elementTree));
    
        elementTree.clear();
        if (!transportSettings_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TransportSettings", elementTree));
    
        elementTree.clear();
        if (!messageSettings_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MessageSettings", elementTree));
    
        elementTree.clear();
        if (!subscribedDataSet_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetReaderDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SubscribedDataSet", elementTree));
    
        return true;
    }
    
    bool
    DataSetReaderDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataSetReaderDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Name");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        elementName = xmlns.addPrefix("Enabled");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, enabled_)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("PublisherId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publisherId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", "PublisherId");
            return false;
        }
    
        elementName = xmlns.addPrefix("WriterGroupId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, writerGroupId_)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetWriterId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, dataSetWriterId_)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetMetaData");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetMetaData_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", "DataSetMetaData");
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetFieldContentMask");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, dataSetFieldContentMask_)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MessageReceiveTimeout");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, messageReceiveTimeout_)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityMode");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityMode_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", "SecurityMode");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityGroupId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityGroupId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", "SecurityGroupId");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityKeyServices");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityKeyServices_.xmlDecode(*tree, "EndpointDescription", xmlns)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetReaderProperties");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetReaderProperties_.xmlDecode(*tree, "KeyValuePair", xmlns)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TransportSettings");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportSettings_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", "TransportSettings");
            return false;
        }
    
        elementName = xmlns.addPrefix("MessageSettings");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!messageSettings_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", "MessageSettings");
            return false;
        }
    
        elementName = xmlns.addPrefix("SubscribedDataSet");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!subscribedDataSet_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataSetReaderDataType decode xml error - decode failed")
                .parameter("Element", "SubscribedDataSet");
            return false;
        }
    
        return true;
    }
    
    bool
    DataSetReaderDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, name_, "Name", true);
        rc = rc & jsonNumberEncode(pt, enabled_, "Enabled");
        rc = rc & jsonObjectEncode(pt, publisherId_, "PublisherId", true);
        rc = rc & jsonNumberEncode(pt, writerGroupId_, "WriterGroupId");
        rc = rc & jsonNumberEncode(pt, dataSetWriterId_, "DataSetWriterId");
        rc = rc & jsonObjectEncode(pt, dataSetMetaData_, "DataSetMetaData", true);
        rc = rc & jsonNumberEncode(pt, dataSetFieldContentMask_, "DataSetFieldContentMask");
        rc = rc & jsonNumberEncode(pt, messageReceiveTimeout_, "MessageReceiveTimeout");
        rc = rc & jsonObjectEncode(pt, securityMode_, "SecurityMode", true);
        rc = rc & jsonObjectEncode(pt, securityGroupId_, "SecurityGroupId", true);
        rc = rc & jsonArrayEncode(pt, securityKeyServices_, "SecurityKeyServices", true);
        rc = rc & jsonArrayEncode(pt, dataSetReaderProperties_, "DataSetReaderProperties", true);
        rc = rc & jsonObjectEncode(pt, transportSettings_, "TransportSettings", true);
        rc = rc & jsonObjectEncode(pt, messageSettings_, "MessageSettings", true);
        rc = rc & jsonObjectEncode(pt, subscribedDataSet_, "SubscribedDataSet", true);
    
        return rc;
    }
    
    bool
    DataSetReaderDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, name_, "Name", true);
        rc = rc & jsonNumberDecode(pt, enabled_, "Enabled");
        rc = rc & jsonObjectDecode(pt, publisherId_, "PublisherId", true);
        rc = rc & jsonNumberDecode(pt, writerGroupId_, "WriterGroupId");
        rc = rc & jsonNumberDecode(pt, dataSetWriterId_, "DataSetWriterId");
        rc = rc & jsonObjectDecode(pt, dataSetMetaData_, "DataSetMetaData", true);
        rc = rc & jsonNumberDecode(pt, dataSetFieldContentMask_, "DataSetFieldContentMask");
        rc = rc & jsonNumberDecode(pt, messageReceiveTimeout_, "MessageReceiveTimeout");
        rc = rc & jsonObjectDecode(pt, securityMode_, "SecurityMode", true);
        rc = rc & jsonObjectDecode(pt, securityGroupId_, "SecurityGroupId", true);
        rc = rc & jsonArrayDecode(pt, securityKeyServices_, "SecurityKeyServices", true);
        rc = rc & jsonArrayDecode(pt, dataSetReaderProperties_, "DataSetReaderProperties", true);
        rc = rc & jsonObjectDecode(pt, transportSettings_, "TransportSettings", true);
        rc = rc & jsonObjectDecode(pt, messageSettings_, "MessageSettings", true);
        rc = rc & jsonObjectDecode(pt, subscribedDataSet_, "SubscribedDataSet", true);
    
        return rc;
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
