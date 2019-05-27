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
    
    ReadEventDetails::ReadEventDetails(const ReadEventDetails& value)
    : HistoryReadDetails()
    , numValuesPerNode_()
    , startTime_()
    , endTime_()
    , filter_()
    {
        const_cast<ReadEventDetails*>(&value)->copyTo(*this);
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
    ReadEventDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReadEventDetails encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReadEventDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, numValuesPerNode_))
        {
            Log(Error, "ReadEventDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NumValuesPerNode", elementTree));
    
        elementTree.clear();
        if (!startTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReadEventDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!endTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReadEventDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EndTime", elementTree));
    
        elementTree.clear();
        if (!filter_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReadEventDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Filter", elementTree));
    
        return true;
    }
    
    bool
    ReadEventDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadEventDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReadEventDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("NumValuesPerNode");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadEventDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, numValuesPerNode_)) {
            Log(Error, "ReadEventDetails decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("StartTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadEventDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!startTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ReadEventDetails decode xml error - decode failed")
                .parameter("Element", "StartTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("EndTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadEventDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ReadEventDetails decode xml error - decode failed")
                .parameter("Element", "EndTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("Filter");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadEventDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!filter_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ReadEventDetails decode xml error - decode failed")
                .parameter("Element", "Filter");
            return false;
        }
    
        return true;
    }
    
    bool
    ReadEventDetails::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, numValuesPerNode_))
        {
    	     Log(Error, "ReadEventDetails json encoder error")
    		     .parameter("Element", "numValuesPerNode_");
           return false;
        }
        pt.push_back(std::make_pair("NumValuesPerNode", elementTree));
    
        elementTree.clear();
        if (!startTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ReadEventDetails json encoder error")
    		     .parameter("Element", "startTime_");
            return false;
        }
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!endTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ReadEventDetails json encoder error")
    		     .parameter("Element", "endTime_");
            return false;
        }
        pt.push_back(std::make_pair("EndTime", elementTree));
    
        elementTree.clear();
        if (!filter_.jsonEncode(elementTree))
        {
    	     Log(Error, "ReadEventDetails json encoder error")
    		     .parameter("Element", "filter_");
            return false;
        }
        pt.push_back(std::make_pair("Filter", elementTree));
    
        return true;
    }
    
    bool
    ReadEventDetails::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "NumValuesPerNode";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadEventDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, numValuesPerNode_)) {
            Log(Error, "ReadEventDetails decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "StartTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadEventDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!startTime_.jsonDecode(*tree)) {
            Log(Error, "ReadEventDetails decode json error - decode failed")
                .parameter("Element", "StartTime");
            return false;
        }
    
        elementName = "EndTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadEventDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endTime_.jsonDecode(*tree)) {
            Log(Error, "ReadEventDetails decode json error - decode failed")
                .parameter("Element", "EndTime");
            return false;
        }
    
        elementName = "Filter";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadEventDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!filter_.jsonDecode(*tree)) {
            Log(Error, "ReadEventDetails decode json error - decode failed")
                .parameter("Element", "Filter");
            return false;
        }
    
        return true;
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
