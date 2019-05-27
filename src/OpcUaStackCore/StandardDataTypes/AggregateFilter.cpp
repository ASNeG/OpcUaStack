/*
    DataTypeClass: AggregateFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/AggregateFilter.h"

namespace OpcUaStackCore
{
    
    AggregateFilter::AggregateFilter(void)
    : MonitoringFilter()
    , startTime_()
    , aggregateType_()
    , processingInterval_()
    , aggregateConfiguration_()
    {
    }
    
    AggregateFilter::AggregateFilter(const AggregateFilter& value)
    : MonitoringFilter()
    , startTime_()
    , aggregateType_()
    , processingInterval_()
    , aggregateConfiguration_()
    {
        const_cast<AggregateFilter*>(&value)->copyTo(*this);
    }
    
    AggregateFilter::~AggregateFilter(void)
    {
    }
    
    OpcUaUtcTime&
    AggregateFilter::startTime(void)
    {
        return startTime_;
    }
    
    OpcUaNodeId&
    AggregateFilter::aggregateType(void)
    {
        return aggregateType_;
    }
    
    OpcUaDuration&
    AggregateFilter::processingInterval(void)
    {
        return processingInterval_;
    }
    
    AggregateConfiguration&
    AggregateFilter::aggregateConfiguration(void)
    {
        return aggregateConfiguration_;
    }
    
    bool
    AggregateFilter::operator==(const AggregateFilter& value)
    {
        AggregateFilter* dst = const_cast<AggregateFilter*>(&value);
        if (startTime_ != dst->startTime()) return false;
        if (aggregateType_ != dst->aggregateType()) return false;
        if (processingInterval_ != dst->processingInterval()) return false;
        if (aggregateConfiguration_ != dst->aggregateConfiguration()) return false;
        return true;
    }
    
    bool
    AggregateFilter::operator!=(const AggregateFilter& value)
    {
        return !this->operator==(value);
    }
    
    void
    AggregateFilter::copyTo(AggregateFilter& value)
    {
        startTime_.copyTo(value.startTime());
        aggregateType_.copyTo(value.aggregateType());
        value.processingInterval_ = processingInterval_;
        aggregateConfiguration_.copyTo(value.aggregateConfiguration());
    }
    
    AggregateFilter&
    AggregateFilter::operator=(const AggregateFilter& value)
    {
        const_cast<AggregateFilter*>(&value)->copyTo(*this);
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
    AggregateFilter::factory(void)
    {
    	return constructSPtr<AggregateFilter>();
    }
    
    std::string
    AggregateFilter::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    AggregateFilter::typeName(void)
    {
    	return "AggregateFilter";
    }
    
    OpcUaNodeId
    AggregateFilter::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)728,0);
    }
    
    OpcUaNodeId
    AggregateFilter::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)730, 0);
    }
    
    OpcUaNodeId
    AggregateFilter::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)729, 0);
    }
    
    OpcUaNodeId
    AggregateFilter::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15312, 0);
    }
    
    void
    AggregateFilter::opcUaBinaryEncode(std::ostream& os) const
    {
        MonitoringFilter::opcUaBinaryEncode(os);
        startTime_.opcUaBinaryEncode(os);
        aggregateType_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,processingInterval_);
        aggregateConfiguration_.opcUaBinaryEncode(os);
    }
    
    void
    AggregateFilter::opcUaBinaryDecode(std::istream& is)
    {
        MonitoringFilter::opcUaBinaryDecode(is);
        startTime_.opcUaBinaryDecode(is);
        aggregateType_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,processingInterval_);
        aggregateConfiguration_.opcUaBinaryDecode(is);
    }
    
    bool
    AggregateFilter::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "AggregateFilter encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    AggregateFilter::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!startTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AggregateFilter encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!aggregateType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AggregateFilter encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AggregateType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, processingInterval_))
        {
            Log(Error, "AggregateFilter encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ProcessingInterval", elementTree));
    
        elementTree.clear();
        if (!aggregateConfiguration_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AggregateFilter encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AggregateConfiguration", elementTree));
    
        return true;
    }
    
    bool
    AggregateFilter::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AggregateFilter::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("StartTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!startTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AggregateFilter decode xml error - decode failed")
                .parameter("Element", "StartTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("AggregateType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!aggregateType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AggregateFilter decode xml error - decode failed")
                .parameter("Element", "AggregateType");
            return false;
        }
    
        elementName = xmlns.addPrefix("ProcessingInterval");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, processingInterval_)) {
            Log(Error, "AggregateFilter decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("AggregateConfiguration");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!aggregateConfiguration_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AggregateFilter decode xml error - decode failed")
                .parameter("Element", "AggregateConfiguration");
            return false;
        }
    
        return true;
    }
    
    bool
    AggregateFilter::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!startTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "AggregateFilter json encoder error")
    		     .parameter("Element", "startTime_");
            return false;
        }
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!aggregateType_.jsonEncode(elementTree))
        {
    	     Log(Error, "AggregateFilter json encoder error")
    		     .parameter("Element", "aggregateType_");
            return false;
        }
        pt.push_back(std::make_pair("AggregateType", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, processingInterval_))
        {
    	     Log(Error, "AggregateFilter json encoder error")
    		     .parameter("Element", "processingInterval_");
           return false;
        }
        pt.push_back(std::make_pair("ProcessingInterval", elementTree));
    
        elementTree.clear();
        if (!aggregateConfiguration_.jsonEncode(elementTree))
        {
    	     Log(Error, "AggregateFilter json encoder error")
    		     .parameter("Element", "aggregateConfiguration_");
            return false;
        }
        pt.push_back(std::make_pair("AggregateConfiguration", elementTree));
    
        return true;
    }
    
    bool
    AggregateFilter::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "StartTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilter decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!startTime_.jsonDecode(*tree)) {
            Log(Error, "AggregateFilter decode json error - decode failed")
                .parameter("Element", "StartTime");
            return false;
        }
    
        elementName = "AggregateType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilter decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!aggregateType_.jsonDecode(*tree)) {
            Log(Error, "AggregateFilter decode json error - decode failed")
                .parameter("Element", "AggregateType");
            return false;
        }
    
        elementName = "ProcessingInterval";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilter decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, processingInterval_)) {
            Log(Error, "AggregateFilter decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "AggregateConfiguration";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilter decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!aggregateConfiguration_.jsonDecode(*tree)) {
            Log(Error, "AggregateFilter decode json error - decode failed")
                .parameter("Element", "AggregateConfiguration");
            return false;
        }
    
        return true;
    }
    
    void
    AggregateFilter::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	AggregateFilter* dst = dynamic_cast<AggregateFilter*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    AggregateFilter::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	AggregateFilter* dst = dynamic_cast<AggregateFilter*>(&extensionObjectBase);
    	return *const_cast<AggregateFilter*>(this) == *dst;
    }
    
    void
    AggregateFilter::out(std::ostream& os)
    {
        os << "StartTime="; startTime_.out(os);
        os << ", AggregateType="; aggregateType_.out(os);
        os << ", ProcessingInterval=" << processingInterval_;
        os << ", AggregateConfiguration="; aggregateConfiguration_.out(os);
    }

}
