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
    AggregateFilterResult::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    AggregateFilterResult::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    AggregateFilterResult::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    AggregateFilterResult::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!revisedStartTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("RevisedStartTime", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, revisedProcessingInterval_)) return false;
        pt.push_back(std::make_pair("RevisedProcessingInterval", elementTree));
    
        elementTree.clear();
        if (!revisedAggregateConfiguration_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("RevisedAggregateConfiguration", elementTree));
    
        return true;
    }
    
    bool
    AggregateFilterResult::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AggregateFilterResult::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("RevisedStartTime");
        if (!tree) return false;
        if (!revisedStartTime_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("RevisedProcessingInterval");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, revisedProcessingInterval_)) return false;
    
        tree = pt.get_child_optional("RevisedAggregateConfiguration");
        if (!tree) return false;
        if (!revisedAggregateConfiguration_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    AggregateFilterResult::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    AggregateFilterResult::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    AggregateFilterResult::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    AggregateFilterResult::jsonDecode(boost::property_tree::ptree& pt)
    {
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
