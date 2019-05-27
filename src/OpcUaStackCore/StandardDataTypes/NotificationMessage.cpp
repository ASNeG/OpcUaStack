/*
    DataTypeClass: NotificationMessage

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/NotificationMessage.h"

namespace OpcUaStackCore
{
    
    NotificationMessage::NotificationMessage(void)
    : Object()
    , ExtensionObjectBase()
    , sequenceNumber_()
    , publishTime_()
    , notificationData_()
    {
    }
    
    NotificationMessage::NotificationMessage(const NotificationMessage& value)
    : Object()
    , ExtensionObjectBase()
    , sequenceNumber_()
    , publishTime_()
    , notificationData_()
    {
        const_cast<NotificationMessage*>(&value)->copyTo(*this);
    }
    
    NotificationMessage::~NotificationMessage(void)
    {
    }
    
    OpcUaCounter&
    NotificationMessage::sequenceNumber(void)
    {
        return sequenceNumber_;
    }
    
    OpcUaUtcTime&
    NotificationMessage::publishTime(void)
    {
        return publishTime_;
    }
    
    OpcUaExtensibleParameterArray&
    NotificationMessage::notificationData(void)
    {
        return notificationData_;
    }
    
    bool
    NotificationMessage::operator==(const NotificationMessage& value)
    {
        NotificationMessage* dst = const_cast<NotificationMessage*>(&value);
        if (sequenceNumber_ != dst->sequenceNumber()) return false;
        if (publishTime_ != dst->publishTime()) return false;
        if (notificationData_ != dst->notificationData()) return false;
        return true;
    }
    
    bool
    NotificationMessage::operator!=(const NotificationMessage& value)
    {
        return !this->operator==(value);
    }
    
    void
    NotificationMessage::copyTo(NotificationMessage& value)
    {
        value.sequenceNumber_ = sequenceNumber_;
        publishTime_.copyTo(value.publishTime());
        notificationData_.copyTo(value.notificationData());
    }
    
    NotificationMessage&
    NotificationMessage::operator=(const NotificationMessage& value)
    {
        const_cast<NotificationMessage*>(&value)->copyTo(*this);
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
    NotificationMessage::factory(void)
    {
    	return constructSPtr<NotificationMessage>();
    }
    
    std::string
    NotificationMessage::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    NotificationMessage::typeName(void)
    {
    	return "NotificationMessage";
    }
    
    OpcUaNodeId
    NotificationMessage::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)803,0);
    }
    
    OpcUaNodeId
    NotificationMessage::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)805, 0);
    }
    
    OpcUaNodeId
    NotificationMessage::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)804, 0);
    }
    
    OpcUaNodeId
    NotificationMessage::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15343, 0);
    }
    
    void
    NotificationMessage::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,sequenceNumber_);
        publishTime_.opcUaBinaryEncode(os);
        notificationData_.opcUaBinaryEncode(os);
    }
    
    void
    NotificationMessage::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,sequenceNumber_);
        publishTime_.opcUaBinaryDecode(is);
        notificationData_.opcUaBinaryDecode(is);
    }
    
    bool
    NotificationMessage::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "NotificationMessage encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    NotificationMessage::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, sequenceNumber_))
        {
            Log(Error, "NotificationMessage encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SequenceNumber", elementTree));
    
        elementTree.clear();
        if (!publishTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "NotificationMessage encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublishTime", elementTree));
    
        elementTree.clear();
        if (!notificationData_.xmlEncode(elementTree, "ExtensibleParameter", xmlns)) {
            Log(Error, "NotificationMessage encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NotificationData", elementTree));
    
        return true;
    }
    
    bool
    NotificationMessage::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NotificationMessage decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    NotificationMessage::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("SequenceNumber");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NotificationMessage decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, sequenceNumber_)) {
            Log(Error, "NotificationMessage decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("PublishTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NotificationMessage decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publishTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "NotificationMessage decode xml error - decode failed")
                .parameter("Element", "PublishTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("NotificationData");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NotificationMessage decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!notificationData_.xmlDecode(*tree, "ExtensibleParameter", xmlns)) {
            Log(Error, "NotificationMessage decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    NotificationMessage::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, sequenceNumber_))
        {
    	     Log(Error, "NotificationMessage json encoder error")
    		     .parameter("Element", "sequenceNumber_");
           return false;
        }
        pt.push_back(std::make_pair("SequenceNumber", elementTree));
    
        elementTree.clear();
        if (!publishTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "NotificationMessage json encoder error")
    		     .parameter("Element", "publishTime_");
            return false;
        }
        pt.push_back(std::make_pair("PublishTime", elementTree));
    
        elementTree.clear();
        if (!notificationData_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "NotificationMessage json encoder error")
    		     .parameter("Element", "notificationData_");
            return false;
        }
        pt.push_back(std::make_pair("NotificationData", elementTree));
    
        return true;
    }
    
    bool
    NotificationMessage::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "SequenceNumber";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NotificationMessage decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, sequenceNumber_)) {
            Log(Error, "NotificationMessage decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "PublishTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NotificationMessage decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publishTime_.jsonDecode(*tree)) {
            Log(Error, "NotificationMessage decode json error - decode failed")
                .parameter("Element", "PublishTime");
            return false;
        }
    
        elementName = "NotificationData";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "NotificationMessage decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!notificationData_.jsonDecode(*tree, "")) {
            Log(Error, "NotificationMessage decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    NotificationMessage::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	NotificationMessage* dst = dynamic_cast<NotificationMessage*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    NotificationMessage::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	NotificationMessage* dst = dynamic_cast<NotificationMessage*>(&extensionObjectBase);
    	return *const_cast<NotificationMessage*>(this) == *dst;
    }
    
    void
    NotificationMessage::out(std::ostream& os)
    {
        os << "SequenceNumber=" << sequenceNumber_;
        os << ", PublishTime="; publishTime_.out(os);
        os << ", NotificationData="; notificationData_.out(os);
    }

}
