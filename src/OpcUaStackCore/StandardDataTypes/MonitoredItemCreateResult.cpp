/*
    DataTypeClass: MonitoredItemCreateResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/MonitoredItemCreateResult.h"

namespace OpcUaStackCore
{
    
    MonitoredItemCreateResult::MonitoredItemCreateResult(void)
    : Object()
    , ExtensionObjectBase()
    , statusCode_()
    , monitoredItemId_()
    , revisedSamplingInterval_()
    , revisedQueueSize_()
    , filterResult_()
    {
    }
    
    MonitoredItemCreateResult::~MonitoredItemCreateResult(void)
    {
    }
    
    OpcUaStatus&
    MonitoredItemCreateResult::statusCode(void)
    {
        return statusCode_;
    }
    
    OpcUaIntegerId&
    MonitoredItemCreateResult::monitoredItemId(void)
    {
        return monitoredItemId_;
    }
    
    OpcUaDuration&
    MonitoredItemCreateResult::revisedSamplingInterval(void)
    {
        return revisedSamplingInterval_;
    }
    
    OpcUaCounter&
    MonitoredItemCreateResult::revisedQueueSize(void)
    {
        return revisedQueueSize_;
    }
    
    OpcUaExtensibleParameter&
    MonitoredItemCreateResult::filterResult(void)
    {
        return filterResult_;
    }
    
    bool
    MonitoredItemCreateResult::operator==(const MonitoredItemCreateResult& value)
    {
        MonitoredItemCreateResult* dst = const_cast<MonitoredItemCreateResult*>(&value);
        if (statusCode_ != dst->statusCode()) return false;
        if (monitoredItemId_ != dst->monitoredItemId()) return false;
        if (revisedSamplingInterval_ != dst->revisedSamplingInterval()) return false;
        if (revisedQueueSize_ != dst->revisedQueueSize()) return false;
        if (filterResult_ != dst->filterResult()) return false;
        return true;
    }
    
    bool
    MonitoredItemCreateResult::operator!=(const MonitoredItemCreateResult& value)
    {
        return !this->operator==(value);
    }
    
    void
    MonitoredItemCreateResult::copyTo(MonitoredItemCreateResult& value)
    {
        statusCode_.copyTo(value.statusCode());
        value.monitoredItemId_ = monitoredItemId_;
        value.revisedSamplingInterval_ = revisedSamplingInterval_;
        value.revisedQueueSize_ = revisedQueueSize_;
        filterResult_.copyTo(value.filterResult());
    }
    
    MonitoredItemCreateResult&
    MonitoredItemCreateResult::operator=(const MonitoredItemCreateResult& value)
    {
        const_cast<MonitoredItemCreateResult*>(&value)->copyTo(*this);
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
    MonitoredItemCreateResult::factory(void)
    {
    	return constructSPtr<MonitoredItemCreateResult>();
    }
    
    std::string
    MonitoredItemCreateResult::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    MonitoredItemCreateResult::typeName(void)
    {
    	return "MonitoredItemCreateResult";
    }
    
    OpcUaNodeId
    MonitoredItemCreateResult::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)746,0);
    }
    
    OpcUaNodeId
    MonitoredItemCreateResult::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)748, 0);
    }
    
    OpcUaNodeId
    MonitoredItemCreateResult::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)747, 0);
    }
    
    OpcUaNodeId
    MonitoredItemCreateResult::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15322, 0);
    }
    
    void
    MonitoredItemCreateResult::opcUaBinaryEncode(std::ostream& os) const
    {
        statusCode_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,monitoredItemId_);
        OpcUaNumber::opcUaBinaryEncode(os,revisedSamplingInterval_);
        OpcUaNumber::opcUaBinaryEncode(os,revisedQueueSize_);
        filterResult_.opcUaBinaryEncode(os);
    }
    
    void
    MonitoredItemCreateResult::opcUaBinaryDecode(std::istream& is)
    {
        statusCode_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,monitoredItemId_);
        OpcUaNumber::opcUaBinaryDecode(is,revisedSamplingInterval_);
        OpcUaNumber::opcUaBinaryDecode(is,revisedQueueSize_);
        filterResult_.opcUaBinaryDecode(is);
    }
    
    bool
    MonitoredItemCreateResult::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    MonitoredItemCreateResult::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    MonitoredItemCreateResult::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    MonitoredItemCreateResult::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!statusCode_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("StatusCode", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, monitoredItemId_)) return false;
        pt.push_back(std::make_pair("MonitoredItemId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, revisedSamplingInterval_)) return false;
        pt.push_back(std::make_pair("RevisedSamplingInterval", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, revisedQueueSize_)) return false;
        pt.push_back(std::make_pair("RevisedQueueSize", elementTree));
    
        elementTree.clear();
        if (!filterResult_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("FilterResult", elementTree));
    
        return true;
    }
    
    bool
    MonitoredItemCreateResult::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    MonitoredItemCreateResult::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("StatusCode");
        if (!tree) return false;
        if (!statusCode_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("MonitoredItemId");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, monitoredItemId_)) return false;
    
        tree = pt.get_child_optional("RevisedSamplingInterval");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, revisedSamplingInterval_)) return false;
    
        tree = pt.get_child_optional("RevisedQueueSize");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, revisedQueueSize_)) return false;
    
        tree = pt.get_child_optional("FilterResult");
        if (!tree) return false;
        if (!filterResult_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    MonitoredItemCreateResult::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    MonitoredItemCreateResult::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    MonitoredItemCreateResult::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    MonitoredItemCreateResult::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    MonitoredItemCreateResult::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	MonitoredItemCreateResult* dst = dynamic_cast<MonitoredItemCreateResult*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    MonitoredItemCreateResult::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	MonitoredItemCreateResult* dst = dynamic_cast<MonitoredItemCreateResult*>(&extensionObjectBase);
    	return *const_cast<MonitoredItemCreateResult*>(this) == *dst;
    }
    
    void
    MonitoredItemCreateResult::out(std::ostream& os)
    {
        os << "StatusCode="; statusCode_.out(os);
        os << ", MonitoredItemId=" << monitoredItemId_;
        os << ", RevisedSamplingInterval=" << revisedSamplingInterval_;
        os << ", RevisedQueueSize=" << revisedQueueSize_;
        os << ", FilterResult="; filterResult_.out(os);
    }

}
