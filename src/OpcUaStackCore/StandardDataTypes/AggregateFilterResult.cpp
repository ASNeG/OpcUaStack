/*
    DataTypeClass: AggregateFilterResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/AggregateFilterResult.h"

namespace OpcUaStackCore
{
    
    AggregateFilterResult::AggregateFilterResult(void)
    : MonitoringFilterResult()
    , revisedStartTime_()
    , revisedProcessingInterval_()
    , revisedAggregateConfiguration_()
    {
    }
    
    AggregateFilterResult::AggregateFilterResult(const AggregateFilterResult& value)
    : MonitoringFilterResult()
    , revisedStartTime_()
    , revisedProcessingInterval_()
    , revisedAggregateConfiguration_()
    {
        const_cast<AggregateFilterResult*>(&value)->copyTo(*this);
    }
    
    AggregateFilterResult::~AggregateFilterResult(void)
    {
    }
    
    OpcUaUtcTime&
    AggregateFilterResult::revisedStartTime(void)
    {
        return revisedStartTime_;
    }
    
    OpcUaDuration&
    AggregateFilterResult::revisedProcessingInterval(void)
    {
        return revisedProcessingInterval_;
    }
    
    AggregateConfiguration&
    AggregateFilterResult::revisedAggregateConfiguration(void)
    {
        return revisedAggregateConfiguration_;
    }
    
    bool
    AggregateFilterResult::operator==(const AggregateFilterResult& value)
    {
        AggregateFilterResult* dst = const_cast<AggregateFilterResult*>(&value);
        if (revisedStartTime_ != dst->revisedStartTime()) return false;
        if (revisedProcessingInterval_ != dst->revisedProcessingInterval()) return false;
        if (revisedAggregateConfiguration_ != dst->revisedAggregateConfiguration()) return false;
        return true;
    }
    
    bool
    AggregateFilterResult::operator!=(const AggregateFilterResult& value)
    {
        return !this->operator==(value);
    }
    
    void
    AggregateFilterResult::copyTo(AggregateFilterResult& value)
    {
        revisedStartTime_.copyTo(value.revisedStartTime());
        value.revisedProcessingInterval_ = revisedProcessingInterval_;
        revisedAggregateConfiguration_.copyTo(value.revisedAggregateConfiguration());
    }
    
    AggregateFilterResult&
    AggregateFilterResult::operator=(const AggregateFilterResult& value)
    {
        const_cast<AggregateFilterResult*>(&value)->copyTo(*this);
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
    AggregateFilterResult::factory(void)
    {
    	return constructSPtr<AggregateFilterResult>();
    }
    
    std::string
    AggregateFilterResult::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    AggregateFilterResult::typeName(void)
    {
    	return "AggregateFilterResult";
    }
    
    OpcUaNodeId
    AggregateFilterResult::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)737,0);
    }
    
    OpcUaNodeId
    AggregateFilterResult::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)739, 0);
    }
    
    OpcUaNodeId
    AggregateFilterResult::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)738, 0);
    }
    
    OpcUaNodeId
    AggregateFilterResult::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15315, 0);
    }
    
    void
    AggregateFilterResult::opcUaBinaryEncode(std::ostream& os) const
    {
        MonitoringFilterResult::opcUaBinaryEncode(os);
        revisedStartTime_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,revisedProcessingInterval_);
        revisedAggregateConfiguration_.opcUaBinaryEncode(os);
    }
    
    void
    AggregateFilterResult::opcUaBinaryDecode(std::istream& is)
    {
        MonitoringFilterResult::opcUaBinaryDecode(is);
        revisedStartTime_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,revisedProcessingInterval_);
        revisedAggregateConfiguration_.opcUaBinaryDecode(is);
    }
    
    bool
    AggregateFilterResult::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "AggregateFilterResult encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    AggregateFilterResult::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!revisedStartTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AggregateFilterResult encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RevisedStartTime", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, revisedProcessingInterval_))
        {
            Log(Error, "AggregateFilterResult encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RevisedProcessingInterval", elementTree));
    
        elementTree.clear();
        if (!revisedAggregateConfiguration_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "AggregateFilterResult encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RevisedAggregateConfiguration", elementTree));
    
        return true;
    }
    
    bool
    AggregateFilterResult::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilterResult decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AggregateFilterResult::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("RevisedStartTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilterResult decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!revisedStartTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AggregateFilterResult decode xml error - decode failed")
                .parameter("Element", "RevisedStartTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("RevisedProcessingInterval");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilterResult decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, revisedProcessingInterval_)) {
            Log(Error, "AggregateFilterResult decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("RevisedAggregateConfiguration");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilterResult decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!revisedAggregateConfiguration_.xmlDecode(*tree, xmlns)) {
            Log(Error, "AggregateFilterResult decode xml error - decode failed")
                .parameter("Element", "RevisedAggregateConfiguration");
            return false;
        }
    
        return true;
    }
    
    bool
    AggregateFilterResult::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!revisedStartTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "AggregateFilterResult json encoder error")
    		     .parameter("Element", "revisedStartTime_");
            return false;
        }
        pt.push_back(std::make_pair("RevisedStartTime", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, revisedProcessingInterval_))
        {
    	     Log(Error, "AggregateFilterResult json encoder error")
    		     .parameter("Element", "revisedProcessingInterval_");
           return false;
        }
        pt.push_back(std::make_pair("RevisedProcessingInterval", elementTree));
    
        elementTree.clear();
        if (!revisedAggregateConfiguration_.jsonEncode(elementTree))
        {
    	     Log(Error, "AggregateFilterResult json encoder error")
    		     .parameter("Element", "revisedAggregateConfiguration_");
            return false;
        }
        pt.push_back(std::make_pair("RevisedAggregateConfiguration", elementTree));
    
        return true;
    }
    
    bool
    AggregateFilterResult::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "RevisedStartTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilterResult decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!revisedStartTime_.jsonDecode(*tree)) {
            Log(Error, "AggregateFilterResult decode json error - decode failed")
                .parameter("Element", "RevisedStartTime");
            return false;
        }
    
        elementName = "RevisedProcessingInterval";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilterResult decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, revisedProcessingInterval_)) {
            Log(Error, "AggregateFilterResult decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "RevisedAggregateConfiguration";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "AggregateFilterResult decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!revisedAggregateConfiguration_.jsonDecode(*tree)) {
            Log(Error, "AggregateFilterResult decode json error - decode failed")
                .parameter("Element", "RevisedAggregateConfiguration");
            return false;
        }
    
        return true;
    }
    
    void
    AggregateFilterResult::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	AggregateFilterResult* dst = dynamic_cast<AggregateFilterResult*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    AggregateFilterResult::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	AggregateFilterResult* dst = dynamic_cast<AggregateFilterResult*>(&extensionObjectBase);
    	return *const_cast<AggregateFilterResult*>(this) == *dst;
    }
    
    void
    AggregateFilterResult::out(std::ostream& os)
    {
        os << "RevisedStartTime="; revisedStartTime_.out(os);
        os << ", RevisedProcessingInterval=" << revisedProcessingInterval_;
        os << ", RevisedAggregateConfiguration="; revisedAggregateConfiguration_.out(os);
    }

}
