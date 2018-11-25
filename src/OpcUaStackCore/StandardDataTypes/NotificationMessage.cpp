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
    NotificationMessage::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    NotificationMessage::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    NotificationMessage::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    NotificationMessage::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, sequenceNumber_)) return false;
        pt.push_back(std::make_pair("SequenceNumber", elementTree));
    
        elementTree.clear();
        if (!publishTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("PublishTime", elementTree));
    
        elementTree.clear();
        if (!notificationData_.xmlEncode(elementTree, "ExtensibleParameter", xmlns)) return false;
        pt.push_back(std::make_pair("NotificationData", elementTree));
    
        return true;
    }
    
    bool
    NotificationMessage::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    NotificationMessage::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("SequenceNumber");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, sequenceNumber_)) return false;
    
        tree = pt.get_child_optional("PublishTime");
        if (!tree) return false;
        if (!publishTime_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("NotificationData");
        if (!tree) return false;
        if (!notificationData_.xmlDecode(*tree, "ExtensibleParameter", xmlns)) return false;
    
        return true;
    }
    
    bool
    NotificationMessage::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    NotificationMessage::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    NotificationMessage::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    NotificationMessage::jsonDecode(boost::property_tree::ptree& pt)
    {
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
