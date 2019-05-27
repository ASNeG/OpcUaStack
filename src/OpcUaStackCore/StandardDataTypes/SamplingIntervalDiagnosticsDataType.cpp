/*
    DataTypeClass: SamplingIntervalDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/SamplingIntervalDiagnosticsDataType.h"

namespace OpcUaStackCore
{
    
    SamplingIntervalDiagnosticsDataType::SamplingIntervalDiagnosticsDataType(void)
    : Object()
    , ExtensionObjectBase()
    , samplingInterval_()
    , monitoredItemCount_()
    , maxMonitoredItemCount_()
    , disabledMonitoredItemCount_()
    {
    }
    
    SamplingIntervalDiagnosticsDataType::SamplingIntervalDiagnosticsDataType(const SamplingIntervalDiagnosticsDataType& value)
    : Object()
    , ExtensionObjectBase()
    , samplingInterval_()
    , monitoredItemCount_()
    , maxMonitoredItemCount_()
    , disabledMonitoredItemCount_()
    {
        const_cast<SamplingIntervalDiagnosticsDataType*>(&value)->copyTo(*this);
    }
    
    SamplingIntervalDiagnosticsDataType::~SamplingIntervalDiagnosticsDataType(void)
    {
    }
    
    OpcUaDuration&
    SamplingIntervalDiagnosticsDataType::samplingInterval(void)
    {
        return samplingInterval_;
    }
    
    OpcUaUInt32&
    SamplingIntervalDiagnosticsDataType::monitoredItemCount(void)
    {
        return monitoredItemCount_;
    }
    
    OpcUaUInt32&
    SamplingIntervalDiagnosticsDataType::maxMonitoredItemCount(void)
    {
        return maxMonitoredItemCount_;
    }
    
    OpcUaUInt32&
    SamplingIntervalDiagnosticsDataType::disabledMonitoredItemCount(void)
    {
        return disabledMonitoredItemCount_;
    }
    
    bool
    SamplingIntervalDiagnosticsDataType::operator==(const SamplingIntervalDiagnosticsDataType& value)
    {
        SamplingIntervalDiagnosticsDataType* dst = const_cast<SamplingIntervalDiagnosticsDataType*>(&value);
        if (samplingInterval_ != dst->samplingInterval()) return false;
        if (monitoredItemCount_ != dst->monitoredItemCount()) return false;
        if (maxMonitoredItemCount_ != dst->maxMonitoredItemCount()) return false;
        if (disabledMonitoredItemCount_ != dst->disabledMonitoredItemCount()) return false;
        return true;
    }
    
    bool
    SamplingIntervalDiagnosticsDataType::operator!=(const SamplingIntervalDiagnosticsDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    SamplingIntervalDiagnosticsDataType::copyTo(SamplingIntervalDiagnosticsDataType& value)
    {
        value.samplingInterval_ = samplingInterval_;
        value.monitoredItemCount_ = monitoredItemCount_;
        value.maxMonitoredItemCount_ = maxMonitoredItemCount_;
        value.disabledMonitoredItemCount_ = disabledMonitoredItemCount_;
    }
    
    SamplingIntervalDiagnosticsDataType&
    SamplingIntervalDiagnosticsDataType::operator=(const SamplingIntervalDiagnosticsDataType& value)
    {
        const_cast<SamplingIntervalDiagnosticsDataType*>(&value)->copyTo(*this);
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
    SamplingIntervalDiagnosticsDataType::factory(void)
    {
    	return constructSPtr<SamplingIntervalDiagnosticsDataType>();
    }
    
    std::string
    SamplingIntervalDiagnosticsDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    SamplingIntervalDiagnosticsDataType::typeName(void)
    {
    	return "SamplingIntervalDiagnosticsDataType";
    }
    
    OpcUaNodeId
    SamplingIntervalDiagnosticsDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)856,0);
    }
    
    OpcUaNodeId
    SamplingIntervalDiagnosticsDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)858, 0);
    }
    
    OpcUaNodeId
    SamplingIntervalDiagnosticsDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)857, 0);
    }
    
    OpcUaNodeId
    SamplingIntervalDiagnosticsDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15365, 0);
    }
    
    void
    SamplingIntervalDiagnosticsDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,samplingInterval_);
        OpcUaNumber::opcUaBinaryEncode(os,monitoredItemCount_);
        OpcUaNumber::opcUaBinaryEncode(os,maxMonitoredItemCount_);
        OpcUaNumber::opcUaBinaryEncode(os,disabledMonitoredItemCount_);
    }
    
    void
    SamplingIntervalDiagnosticsDataType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,samplingInterval_);
        OpcUaNumber::opcUaBinaryDecode(is,monitoredItemCount_);
        OpcUaNumber::opcUaBinaryDecode(is,maxMonitoredItemCount_);
        OpcUaNumber::opcUaBinaryDecode(is,disabledMonitoredItemCount_);
    }
    
    bool
    SamplingIntervalDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "SamplingIntervalDiagnosticsDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    SamplingIntervalDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, samplingInterval_))
        {
            Log(Error, "SamplingIntervalDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SamplingInterval", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, monitoredItemCount_))
        {
            Log(Error, "SamplingIntervalDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MonitoredItemCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, maxMonitoredItemCount_))
        {
            Log(Error, "SamplingIntervalDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MaxMonitoredItemCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, disabledMonitoredItemCount_))
        {
            Log(Error, "SamplingIntervalDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DisabledMonitoredItemCount", elementTree));
    
        return true;
    }
    
    bool
    SamplingIntervalDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SamplingIntervalDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("SamplingInterval");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, samplingInterval_)) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MonitoredItemCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, monitoredItemCount_)) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("MaxMonitoredItemCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, maxMonitoredItemCount_)) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DisabledMonitoredItemCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, disabledMonitoredItemCount_)) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    SamplingIntervalDiagnosticsDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, samplingInterval_))
        {
    	     Log(Error, "SamplingIntervalDiagnosticsDataType json encoder error")
    		     .parameter("Element", "samplingInterval_");
           return false;
        }
        pt.push_back(std::make_pair("SamplingInterval", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, monitoredItemCount_))
        {
    	     Log(Error, "SamplingIntervalDiagnosticsDataType json encoder error")
    		     .parameter("Element", "monitoredItemCount_");
           return false;
        }
        pt.push_back(std::make_pair("MonitoredItemCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, maxMonitoredItemCount_))
        {
    	     Log(Error, "SamplingIntervalDiagnosticsDataType json encoder error")
    		     .parameter("Element", "maxMonitoredItemCount_");
           return false;
        }
        pt.push_back(std::make_pair("MaxMonitoredItemCount", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, disabledMonitoredItemCount_))
        {
    	     Log(Error, "SamplingIntervalDiagnosticsDataType json encoder error")
    		     .parameter("Element", "disabledMonitoredItemCount_");
           return false;
        }
        pt.push_back(std::make_pair("DisabledMonitoredItemCount", elementTree));
    
        return true;
    }
    
    bool
    SamplingIntervalDiagnosticsDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "SamplingInterval";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, samplingInterval_)) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MonitoredItemCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, monitoredItemCount_)) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "MaxMonitoredItemCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, maxMonitoredItemCount_)) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DisabledMonitoredItemCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, disabledMonitoredItemCount_)) {
            Log(Error, "SamplingIntervalDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    SamplingIntervalDiagnosticsDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	SamplingIntervalDiagnosticsDataType* dst = dynamic_cast<SamplingIntervalDiagnosticsDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    SamplingIntervalDiagnosticsDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	SamplingIntervalDiagnosticsDataType* dst = dynamic_cast<SamplingIntervalDiagnosticsDataType*>(&extensionObjectBase);
    	return *const_cast<SamplingIntervalDiagnosticsDataType*>(this) == *dst;
    }
    
    void
    SamplingIntervalDiagnosticsDataType::out(std::ostream& os)
    {
        os << "SamplingInterval=" << samplingInterval_;
        os << ", MonitoredItemCount=" << monitoredItemCount_;
        os << ", MaxMonitoredItemCount=" << maxMonitoredItemCount_;
        os << ", DisabledMonitoredItemCount=" << disabledMonitoredItemCount_;
    }

}
