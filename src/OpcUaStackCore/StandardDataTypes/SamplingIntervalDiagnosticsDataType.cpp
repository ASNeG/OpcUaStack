/*
    DataTypeClass: SamplingIntervalDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

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
    	return boost::make_shared<SamplingIntervalDiagnosticsDataType>();
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
    
    bool
    SamplingIntervalDiagnosticsDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= OpcUaNumber::opcUaBinaryEncode(os,samplingInterval_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,monitoredItemCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,maxMonitoredItemCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,disabledMonitoredItemCount_);
        return rc;
    }
    
    bool
    SamplingIntervalDiagnosticsDataType::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= OpcUaNumber::opcUaBinaryDecode(is,samplingInterval_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,monitoredItemCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,maxMonitoredItemCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,disabledMonitoredItemCount_);
        return rc;
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
        bool rc = true;
    
        rc = rc & jsonNumberEncode(pt, samplingInterval_, "SamplingInterval");
        rc = rc & jsonNumberEncode(pt, monitoredItemCount_, "MonitoredItemCount");
        rc = rc & jsonNumberEncode(pt, maxMonitoredItemCount_, "MaxMonitoredItemCount");
        rc = rc & jsonNumberEncode(pt, disabledMonitoredItemCount_, "DisabledMonitoredItemCount");
    
        return rc;
    }
    
    bool
    SamplingIntervalDiagnosticsDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonNumberDecode(pt, samplingInterval_, "SamplingInterval");
        rc = rc & jsonNumberDecode(pt, monitoredItemCount_, "MonitoredItemCount");
        rc = rc & jsonNumberDecode(pt, maxMonitoredItemCount_, "MaxMonitoredItemCount");
        rc = rc & jsonNumberDecode(pt, disabledMonitoredItemCount_, "DisabledMonitoredItemCount");
    
        return rc;
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
