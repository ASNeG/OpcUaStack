/*
    DataTypeClass: ReadEventDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ReadEventDetails.h"

namespace OpcUaStackCore
{
    
    ReadEventDetails::ReadEventDetails(void)
    : HistoryReadDetails()
    , numValuesPerNode_()
    , startTime_()
    , endTime_()
    , filter_()
    {
    }
    
    ReadEventDetails::~ReadEventDetails(void)
    {
    }
    
    OpcUaCounter&
    ReadEventDetails::numValuesPerNode(void)
    {
        return numValuesPerNode_;
    }
    
    OpcUaUtcTime&
    ReadEventDetails::startTime(void)
    {
        return startTime_;
    }
    
    OpcUaUtcTime&
    ReadEventDetails::endTime(void)
    {
        return endTime_;
    }
    
    EventFilter&
    ReadEventDetails::filter(void)
    {
        return filter_;
    }
    
    bool
    ReadEventDetails::operator==(const ReadEventDetails& value)
    {
        ReadEventDetails* dst = const_cast<ReadEventDetails*>(&value);
        if (numValuesPerNode_ != dst->numValuesPerNode()) return false;
        if (startTime_ != dst->startTime()) return false;
        if (endTime_ != dst->endTime()) return false;
        if (filter_ != dst->filter()) return false;
        return true;
    }
    
    bool
    ReadEventDetails::operator!=(const ReadEventDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    ReadEventDetails::copyTo(ReadEventDetails& value)
    {
        value.numValuesPerNode_ = numValuesPerNode_;
        startTime_.copyTo(value.startTime());
        endTime_.copyTo(value.endTime());
        filter_.copyTo(value.filter());
    }
    
    ReadEventDetails&
    ReadEventDetails::operator=(const ReadEventDetails& value)
    {
        const_cast<ReadEventDetails*>(&value)->copyTo(*this);
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
    ReadEventDetails::factory(void)
    {
    	return constructSPtr<ReadEventDetails>();
    }
    
    std::string
    ReadEventDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ReadEventDetails::typeName(void)
    {
    	return "ReadEventDetails";
    }
    
    OpcUaNodeId
    ReadEventDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)644,0);
    }
    
    OpcUaNodeId
    ReadEventDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)646, 0);
    }
    
    OpcUaNodeId
    ReadEventDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)645, 0);
    }
    
    OpcUaNodeId
    ReadEventDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15262, 0);
    }
    
    void
    ReadEventDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryReadDetails::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,numValuesPerNode_);
        startTime_.opcUaBinaryEncode(os);
        endTime_.opcUaBinaryEncode(os);
        filter_.opcUaBinaryEncode(os);
    }
    
    void
    ReadEventDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryReadDetails::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,numValuesPerNode_);
        startTime_.opcUaBinaryDecode(is);
        endTime_.opcUaBinaryDecode(is);
        filter_.opcUaBinaryDecode(is);
    }
    
    bool
    ReadEventDetails::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ReadEventDetails::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ReadEventDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReadEventDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, numValuesPerNode_)) return false;
        pt.push_back(std::make_pair("NumValuesPerNode", elementTree));
    
        elementTree.clear();
        if (!startTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!endTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("EndTime", elementTree));
    
        elementTree.clear();
        if (!filter_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Filter", elementTree));
    
        return true;
    }
    
    bool
    ReadEventDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReadEventDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("NumValuesPerNode");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, numValuesPerNode_)) return false;
    
        tree = pt.get_child_optional("StartTime");
        if (!tree) return false;
        if (!startTime_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("EndTime");
        if (!tree) return false;
        if (!endTime_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Filter");
        if (!tree) return false;
        if (!filter_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    ReadEventDetails::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    ReadEventDetails::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    ReadEventDetails::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    ReadEventDetails::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    ReadEventDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ReadEventDetails* dst = dynamic_cast<ReadEventDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ReadEventDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ReadEventDetails* dst = dynamic_cast<ReadEventDetails*>(&extensionObjectBase);
    	return *const_cast<ReadEventDetails*>(this) == *dst;
    }
    
    void
    ReadEventDetails::out(std::ostream& os)
    {
        os << "NumValuesPerNode=" << numValuesPerNode_;
        os << ", StartTime="; startTime_.out(os);
        os << ", EndTime="; endTime_.out(os);
        os << ", Filter="; filter_.out(os);
    }

}
