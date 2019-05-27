/*
    DataTypeClass: ReadProcessedDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ReadProcessedDetails.h"

namespace OpcUaStackCore
{
    
    ReadProcessedDetails::ReadProcessedDetails(void)
    : HistoryReadDetails()
    , startTime_()
    , endTime_()
    , processingInterval_()
    , aggregateType_()
    , aggregateConfiguration_()
    {
    }
    
    ReadProcessedDetails::ReadProcessedDetails(const ReadProcessedDetails& value)
    : HistoryReadDetails()
    , startTime_()
    , endTime_()
    , processingInterval_()
    , aggregateType_()
    , aggregateConfiguration_()
    {
        const_cast<ReadProcessedDetails*>(&value)->copyTo(*this);
    }
    
    ReadProcessedDetails::~ReadProcessedDetails(void)
    {
    }
    
    OpcUaUtcTime&
    ReadProcessedDetails::startTime(void)
    {
        return startTime_;
    }
    
    OpcUaUtcTime&
    ReadProcessedDetails::endTime(void)
    {
        return endTime_;
    }
    
    OpcUaDuration&
    ReadProcessedDetails::processingInterval(void)
    {
        return processingInterval_;
    }
    
    OpcUaNodeIdArray&
    ReadProcessedDetails::aggregateType(void)
    {
        return aggregateType_;
    }
    
    AggregateConfiguration&
    ReadProcessedDetails::aggregateConfiguration(void)
    {
        return aggregateConfiguration_;
    }
    
    bool
    ReadProcessedDetails::operator==(const ReadProcessedDetails& value)
    {
        ReadProcessedDetails* dst = const_cast<ReadProcessedDetails*>(&value);
        if (startTime_ != dst->startTime()) return false;
        if (endTime_ != dst->endTime()) return false;
        if (processingInterval_ != dst->processingInterval()) return false;
        if (aggregateType_ != dst->aggregateType()) return false;
        if (aggregateConfiguration_ != dst->aggregateConfiguration()) return false;
        return true;
    }
    
    bool
    ReadProcessedDetails::operator!=(const ReadProcessedDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    ReadProcessedDetails::copyTo(ReadProcessedDetails& value)
    {
        startTime_.copyTo(value.startTime());
        endTime_.copyTo(value.endTime());
        value.processingInterval_ = processingInterval_;
        aggregateType_.copyTo(value.aggregateType());
        aggregateConfiguration_.copyTo(value.aggregateConfiguration());
    }
    
    ReadProcessedDetails&
    ReadProcessedDetails::operator=(const ReadProcessedDetails& value)
    {
        const_cast<ReadProcessedDetails*>(&value)->copyTo(*this);
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
    ReadProcessedDetails::factory(void)
    {
    	return constructSPtr<ReadProcessedDetails>();
    }
    
    std::string
    ReadProcessedDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ReadProcessedDetails::typeName(void)
    {
    	return "ReadProcessedDetails";
    }
    
    OpcUaNodeId
    ReadProcessedDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)650,0);
    }
    
    OpcUaNodeId
    ReadProcessedDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)652, 0);
    }
    
    OpcUaNodeId
    ReadProcessedDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)651, 0);
    }
    
    OpcUaNodeId
    ReadProcessedDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15264, 0);
    }
    
    void
    ReadProcessedDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryReadDetails::opcUaBinaryEncode(os);
        startTime_.opcUaBinaryEncode(os);
        endTime_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,processingInterval_);
        aggregateType_.opcUaBinaryEncode(os);
        aggregateConfiguration_.opcUaBinaryEncode(os);
    }
    
    void
    ReadProcessedDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryReadDetails::opcUaBinaryDecode(is);
        startTime_.opcUaBinaryDecode(is);
        endTime_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,processingInterval_);
        aggregateType_.opcUaBinaryDecode(is);
        aggregateConfiguration_.opcUaBinaryDecode(is);
    }
    
    bool
    ReadProcessedDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReadProcessedDetails encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReadProcessedDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!startTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReadProcessedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!endTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReadProcessedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EndTime", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, processingInterval_))
        {
            Log(Error, "ReadProcessedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ProcessingInterval", elementTree));
    
        elementTree.clear();
        if (!aggregateType_.xmlEncode(elementTree, "NodeId", xmlns)) {
            Log(Error, "ReadProcessedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AggregateType", elementTree));
    
        elementTree.clear();
        if (!aggregateConfiguration_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReadProcessedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AggregateConfiguration", elementTree));
    
        return true;
    }
    
    bool
    ReadProcessedDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadProcessedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReadProcessedDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("StartTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadProcessedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!startTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ReadProcessedDetails decode xml error - decode failed")
                .parameter("Element", "StartTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("EndTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadProcessedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ReadProcessedDetails decode xml error - decode failed")
                .parameter("Element", "EndTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("ProcessingInterval");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadProcessedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, processingInterval_)) {
            Log(Error, "ReadProcessedDetails decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("AggregateType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadProcessedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!aggregateType_.xmlDecode(*tree, "NodeId", xmlns)) {
            Log(Error, "ReadProcessedDetails decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("AggregateConfiguration");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadProcessedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!aggregateConfiguration_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ReadProcessedDetails decode xml error - decode failed")
                .parameter("Element", "AggregateConfiguration");
            return false;
        }
    
        return true;
    }
    
    bool
    ReadProcessedDetails::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!startTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ReadProcessedDetails json encoder error")
    		     .parameter("Element", "startTime_");
            return false;
        }
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!endTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ReadProcessedDetails json encoder error")
    		     .parameter("Element", "endTime_");
            return false;
        }
        pt.push_back(std::make_pair("EndTime", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, processingInterval_))
        {
    	     Log(Error, "ReadProcessedDetails json encoder error")
    		     .parameter("Element", "processingInterval_");
           return false;
        }
        pt.push_back(std::make_pair("ProcessingInterval", elementTree));
    
        elementTree.clear();
        if (!aggregateType_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ReadProcessedDetails json encoder error")
    		     .parameter("Element", "aggregateType_");
            return false;
        }
        pt.push_back(std::make_pair("AggregateType", elementTree));
    
        elementTree.clear();
        if (!aggregateConfiguration_.jsonEncode(elementTree))
        {
    	     Log(Error, "ReadProcessedDetails json encoder error")
    		     .parameter("Element", "aggregateConfiguration_");
            return false;
        }
        pt.push_back(std::make_pair("AggregateConfiguration", elementTree));
    
        return true;
    }
    
    bool
    ReadProcessedDetails::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "StartTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadProcessedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!startTime_.jsonDecode(*tree)) {
            Log(Error, "ReadProcessedDetails decode json error - decode failed")
                .parameter("Element", "StartTime");
            return false;
        }
    
        elementName = "EndTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadProcessedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endTime_.jsonDecode(*tree)) {
            Log(Error, "ReadProcessedDetails decode json error - decode failed")
                .parameter("Element", "EndTime");
            return false;
        }
    
        elementName = "ProcessingInterval";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadProcessedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, processingInterval_)) {
            Log(Error, "ReadProcessedDetails decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "AggregateType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadProcessedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!aggregateType_.jsonDecode(*tree, "")) {
            Log(Error, "ReadProcessedDetails decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "AggregateConfiguration";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadProcessedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!aggregateConfiguration_.jsonDecode(*tree)) {
            Log(Error, "ReadProcessedDetails decode json error - decode failed")
                .parameter("Element", "AggregateConfiguration");
            return false;
        }
    
        return true;
    }
    
    void
    ReadProcessedDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ReadProcessedDetails* dst = dynamic_cast<ReadProcessedDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ReadProcessedDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ReadProcessedDetails* dst = dynamic_cast<ReadProcessedDetails*>(&extensionObjectBase);
    	return *const_cast<ReadProcessedDetails*>(this) == *dst;
    }
    
    void
    ReadProcessedDetails::out(std::ostream& os)
    {
        os << "StartTime="; startTime_.out(os);
        os << ", EndTime="; endTime_.out(os);
        os << ", ProcessingInterval=" << processingInterval_;
        os << ", AggregateType="; aggregateType_.out(os);
        os << ", AggregateConfiguration="; aggregateConfiguration_.out(os);
    }

}
