/*
    DataTypeClass: WriterGroupDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/WriterGroupDataType.h"

namespace OpcUaStackCore
{
    
    WriterGroupDataType::WriterGroupDataType(void)
    : PubSubGroupDataType()
    , writerGroupId_()
    , publishingInterval_()
    , keepAliveTime_()
    , priority_()
    , localeIds_()
    , transportSettings_()
    , messageSettings_()
    , dataSetWriters_()
    {
    }
    
    WriterGroupDataType::WriterGroupDataType(const WriterGroupDataType& value)
    : PubSubGroupDataType()
    , writerGroupId_()
    , publishingInterval_()
    , keepAliveTime_()
    , priority_()
    , localeIds_()
    , transportSettings_()
    , messageSettings_()
    , dataSetWriters_()
    {
        const_cast<WriterGroupDataType*>(&value)->copyTo(*this);
    }
    
    WriterGroupDataType::~WriterGroupDataType(void)
    {
    }
    
    OpcUaUInt16&
    WriterGroupDataType::writerGroupId(void)
    {
        return writerGroupId_;
    }
    
    OpcUaDuration&
    WriterGroupDataType::publishingInterval(void)
    {
        return publishingInterval_;
    }
    
    OpcUaDuration&
    WriterGroupDataType::keepAliveTime(void)
    {
        return keepAliveTime_;
    }
    
    OpcUaByte&
    WriterGroupDataType::priority(void)
    {
        return priority_;
    }
    
    OpcUaLocaleIdArray&
    WriterGroupDataType::localeIds(void)
    {
        return localeIds_;
    }
    
    OpcUaExtensibleParameter&
    WriterGroupDataType::transportSettings(void)
    {
        return transportSettings_;
    }
    
    OpcUaExtensibleParameter&
    WriterGroupDataType::messageSettings(void)
    {
        return messageSettings_;
    }
    
    DataSetWriterDataTypeArray&
    WriterGroupDataType::dataSetWriters(void)
    {
        return dataSetWriters_;
    }
    
    bool
    WriterGroupDataType::operator==(const WriterGroupDataType& value)
    {
        WriterGroupDataType* dst = const_cast<WriterGroupDataType*>(&value);
        if (writerGroupId_ != dst->writerGroupId()) return false;
        if (publishingInterval_ != dst->publishingInterval()) return false;
        if (keepAliveTime_ != dst->keepAliveTime()) return false;
        if (priority_ != dst->priority()) return false;
        if (localeIds_ != dst->localeIds()) return false;
        if (transportSettings_ != dst->transportSettings()) return false;
        if (messageSettings_ != dst->messageSettings()) return false;
        if (dataSetWriters_ != dst->dataSetWriters()) return false;
        return true;
    }
    
    bool
    WriterGroupDataType::operator!=(const WriterGroupDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    WriterGroupDataType::copyTo(WriterGroupDataType& value)
    {
        value.writerGroupId_ = writerGroupId_;
        value.publishingInterval_ = publishingInterval_;
        value.keepAliveTime_ = keepAliveTime_;
        value.priority_ = priority_;
        localeIds_.copyTo(value.localeIds());
        transportSettings_.copyTo(value.transportSettings());
        messageSettings_.copyTo(value.messageSettings());
        dataSetWriters_.copyTo(value.dataSetWriters());
    }
    
    WriterGroupDataType&
    WriterGroupDataType::operator=(const WriterGroupDataType& value)
    {
        const_cast<WriterGroupDataType*>(&value)->copyTo(*this);
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
    WriterGroupDataType::factory(void)
    {
    	return constructSPtr<WriterGroupDataType>();
    }
    
    std::string
    WriterGroupDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    WriterGroupDataType::typeName(void)
    {
    	return "WriterGroupDataType";
    }
    
    OpcUaNodeId
    WriterGroupDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15480,0);
    }
    
    OpcUaNodeId
    WriterGroupDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21150, 0);
    }
    
    OpcUaNodeId
    WriterGroupDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21174, 0);
    }
    
    OpcUaNodeId
    WriterGroupDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21198, 0);
    }
    
    void
    WriterGroupDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        PubSubGroupDataType::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,writerGroupId_);
        OpcUaNumber::opcUaBinaryEncode(os,publishingInterval_);
        OpcUaNumber::opcUaBinaryEncode(os,keepAliveTime_);
        OpcUaNumber::opcUaBinaryEncode(os,priority_);
        localeIds_.opcUaBinaryEncode(os);
        transportSettings_.opcUaBinaryEncode(os);
        messageSettings_.opcUaBinaryEncode(os);
        dataSetWriters_.opcUaBinaryEncode(os);
    }
    
    void
    WriterGroupDataType::opcUaBinaryDecode(std::istream& is)
    {
        PubSubGroupDataType::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,writerGroupId_);
        OpcUaNumber::opcUaBinaryDecode(is,publishingInterval_);
        OpcUaNumber::opcUaBinaryDecode(is,keepAliveTime_);
        OpcUaNumber::opcUaBinaryDecode(is,priority_);
        localeIds_.opcUaBinaryDecode(is);
        transportSettings_.opcUaBinaryDecode(is);
        messageSettings_.opcUaBinaryDecode(is);
        dataSetWriters_.opcUaBinaryDecode(is);
    }
    
    bool
    WriterGroupDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "WriterGroupDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    WriterGroupDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, writerGroupId_))
        {
            Log(Error, "WriterGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("WriterGroupId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, publishingInterval_))
        {
            Log(Error, "WriterGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublishingInterval", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, keepAliveTime_))
        {
            Log(Error, "WriterGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("KeepAliveTime", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, priority_))
        {
            Log(Error, "WriterGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Priority", elementTree));
    
        elementTree.clear();
        if (!localeIds_.xmlEncode(elementTree, "LocaleId", xmlns)) {
            Log(Error, "WriterGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("LocaleIds", elementTree));
    
        elementTree.clear();
        if (!transportSettings_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "WriterGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TransportSettings", elementTree));
    
        elementTree.clear();
        if (!messageSettings_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "WriterGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MessageSettings", elementTree));
    
        elementTree.clear();
        if (!dataSetWriters_.xmlEncode(elementTree, "DataSetWriterDataType", xmlns)) {
            Log(Error, "WriterGroupDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetWriters", elementTree));
    
        return true;
    }
    
    bool
    WriterGroupDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    WriterGroupDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("WriterGroupId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, writerGroupId_)) {
            Log(Error, "WriterGroupDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("PublishingInterval");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, publishingInterval_)) {
            Log(Error, "WriterGroupDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("KeepAliveTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, keepAliveTime_)) {
            Log(Error, "WriterGroupDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("Priority");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, priority_)) {
            Log(Error, "WriterGroupDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("LocaleIds");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!localeIds_.xmlDecode(*tree, "LocaleId", xmlns)) {
            Log(Error, "WriterGroupDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TransportSettings");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportSettings_.xmlDecode(*tree, xmlns)) {
            Log(Error, "WriterGroupDataType decode xml error - decode failed")
                .parameter("Element", "TransportSettings");
            return false;
        }
    
        elementName = xmlns.addPrefix("MessageSettings");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!messageSettings_.xmlDecode(*tree, xmlns)) {
            Log(Error, "WriterGroupDataType decode xml error - decode failed")
                .parameter("Element", "MessageSettings");
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetWriters");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetWriters_.xmlDecode(*tree, "DataSetWriterDataType", xmlns)) {
            Log(Error, "WriterGroupDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    WriterGroupDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, writerGroupId_))
        {
    	     Log(Error, "WriterGroupDataType json encoder error")
    		     .parameter("Element", "writerGroupId_");
           return false;
        }
        pt.push_back(std::make_pair("WriterGroupId", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, publishingInterval_))
        {
    	     Log(Error, "WriterGroupDataType json encoder error")
    		     .parameter("Element", "publishingInterval_");
           return false;
        }
        pt.push_back(std::make_pair("PublishingInterval", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, keepAliveTime_))
        {
    	     Log(Error, "WriterGroupDataType json encoder error")
    		     .parameter("Element", "keepAliveTime_");
           return false;
        }
        pt.push_back(std::make_pair("KeepAliveTime", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, priority_))
        {
    	     Log(Error, "WriterGroupDataType json encoder error")
    		     .parameter("Element", "priority_");
           return false;
        }
        pt.push_back(std::make_pair("Priority", elementTree));
    
        elementTree.clear();
        if (!localeIds_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "WriterGroupDataType json encoder error")
    		     .parameter("Element", "localeIds_");
            return false;
        }
        pt.push_back(std::make_pair("LocaleIds", elementTree));
    
        elementTree.clear();
        if (!transportSettings_.jsonEncode(elementTree))
        {
    	     Log(Error, "WriterGroupDataType json encoder error")
    		     .parameter("Element", "transportSettings_");
            return false;
        }
        pt.push_back(std::make_pair("TransportSettings", elementTree));
    
        elementTree.clear();
        if (!messageSettings_.jsonEncode(elementTree))
        {
    	     Log(Error, "WriterGroupDataType json encoder error")
    		     .parameter("Element", "messageSettings_");
            return false;
        }
        pt.push_back(std::make_pair("MessageSettings", elementTree));
    
        elementTree.clear();
        if (!dataSetWriters_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "WriterGroupDataType json encoder error")
    		     .parameter("Element", "dataSetWriters_");
            return false;
        }
        pt.push_back(std::make_pair("DataSetWriters", elementTree));
    
        return true;
    }
    
    bool
    WriterGroupDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "WriterGroupId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, writerGroupId_)) {
            Log(Error, "WriterGroupDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "PublishingInterval";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, publishingInterval_)) {
            Log(Error, "WriterGroupDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "KeepAliveTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, keepAliveTime_)) {
            Log(Error, "WriterGroupDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "Priority";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, priority_)) {
            Log(Error, "WriterGroupDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "LocaleIds";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!localeIds_.jsonDecode(*tree, "")) {
            Log(Error, "WriterGroupDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "TransportSettings";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportSettings_.jsonDecode(*tree)) {
            Log(Error, "WriterGroupDataType decode json error - decode failed")
                .parameter("Element", "TransportSettings");
            return false;
        }
    
        elementName = "MessageSettings";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!messageSettings_.jsonDecode(*tree)) {
            Log(Error, "WriterGroupDataType decode json error - decode failed")
                .parameter("Element", "MessageSettings");
            return false;
        }
    
        elementName = "DataSetWriters";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetWriters_.jsonDecode(*tree, "")) {
            Log(Error, "WriterGroupDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    WriterGroupDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	WriterGroupDataType* dst = dynamic_cast<WriterGroupDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    WriterGroupDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	WriterGroupDataType* dst = dynamic_cast<WriterGroupDataType*>(&extensionObjectBase);
    	return *const_cast<WriterGroupDataType*>(this) == *dst;
    }
    
    void
    WriterGroupDataType::out(std::ostream& os)
    {
        os << "WriterGroupId=" << writerGroupId_;
        os << ", PublishingInterval=" << publishingInterval_;
        os << ", KeepAliveTime=" << keepAliveTime_;
        os << ", Priority=" << priority_;
        os << ", LocaleIds="; localeIds_.out(os);
        os << ", TransportSettings="; transportSettings_.out(os);
        os << ", MessageSettings="; messageSettings_.out(os);
        os << ", DataSetWriters="; dataSetWriters_.out(os);
    }

}
