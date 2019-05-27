/*
    DataTypeClass: ReadRawModifiedDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ReadRawModifiedDetails.h"

namespace OpcUaStackCore
{
    
    ReadRawModifiedDetails::ReadRawModifiedDetails(void)
    : HistoryReadDetails()
    , isReadModified_()
    , startTime_()
    , endTime_()
    , numValuesPerNode_()
    , returnBounds_()
    {
    }
    
    ReadRawModifiedDetails::ReadRawModifiedDetails(const ReadRawModifiedDetails& value)
    : HistoryReadDetails()
    , isReadModified_()
    , startTime_()
    , endTime_()
    , numValuesPerNode_()
    , returnBounds_()
    {
        const_cast<ReadRawModifiedDetails*>(&value)->copyTo(*this);
    }
    
    ReadRawModifiedDetails::~ReadRawModifiedDetails(void)
    {
    }
    
    OpcUaBoolean&
    ReadRawModifiedDetails::isReadModified(void)
    {
        return isReadModified_;
    }
    
    OpcUaUtcTime&
    ReadRawModifiedDetails::startTime(void)
    {
        return startTime_;
    }
    
    OpcUaUtcTime&
    ReadRawModifiedDetails::endTime(void)
    {
        return endTime_;
    }
    
    OpcUaCounter&
    ReadRawModifiedDetails::numValuesPerNode(void)
    {
        return numValuesPerNode_;
    }
    
    OpcUaBoolean&
    ReadRawModifiedDetails::returnBounds(void)
    {
        return returnBounds_;
    }
    
    bool
    ReadRawModifiedDetails::operator==(const ReadRawModifiedDetails& value)
    {
        ReadRawModifiedDetails* dst = const_cast<ReadRawModifiedDetails*>(&value);
        if (isReadModified_ != dst->isReadModified()) return false;
        if (startTime_ != dst->startTime()) return false;
        if (endTime_ != dst->endTime()) return false;
        if (numValuesPerNode_ != dst->numValuesPerNode()) return false;
        if (returnBounds_ != dst->returnBounds()) return false;
        return true;
    }
    
    bool
    ReadRawModifiedDetails::operator!=(const ReadRawModifiedDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    ReadRawModifiedDetails::copyTo(ReadRawModifiedDetails& value)
    {
        value.isReadModified_ = isReadModified_;
        startTime_.copyTo(value.startTime());
        endTime_.copyTo(value.endTime());
        value.numValuesPerNode_ = numValuesPerNode_;
        value.returnBounds_ = returnBounds_;
    }
    
    ReadRawModifiedDetails&
    ReadRawModifiedDetails::operator=(const ReadRawModifiedDetails& value)
    {
        const_cast<ReadRawModifiedDetails*>(&value)->copyTo(*this);
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
    ReadRawModifiedDetails::factory(void)
    {
    	return constructSPtr<ReadRawModifiedDetails>();
    }
    
    std::string
    ReadRawModifiedDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ReadRawModifiedDetails::typeName(void)
    {
    	return "ReadRawModifiedDetails";
    }
    
    OpcUaNodeId
    ReadRawModifiedDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)647,0);
    }
    
    OpcUaNodeId
    ReadRawModifiedDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)649, 0);
    }
    
    OpcUaNodeId
    ReadRawModifiedDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)648, 0);
    }
    
    OpcUaNodeId
    ReadRawModifiedDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15263, 0);
    }
    
    void
    ReadRawModifiedDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryReadDetails::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,isReadModified_);
        startTime_.opcUaBinaryEncode(os);
        endTime_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,numValuesPerNode_);
        OpcUaNumber::opcUaBinaryEncode(os,returnBounds_);
    }
    
    void
    ReadRawModifiedDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryReadDetails::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,isReadModified_);
        startTime_.opcUaBinaryDecode(is);
        endTime_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,numValuesPerNode_);
        OpcUaNumber::opcUaBinaryDecode(is,returnBounds_);
    }
    
    bool
    ReadRawModifiedDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReadRawModifiedDetails encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReadRawModifiedDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isReadModified_))
        {
            Log(Error, "ReadRawModifiedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IsReadModified", elementTree));
    
        elementTree.clear();
        if (!startTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReadRawModifiedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!endTime_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReadRawModifiedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("EndTime", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, numValuesPerNode_))
        {
            Log(Error, "ReadRawModifiedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NumValuesPerNode", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, returnBounds_))
        {
            Log(Error, "ReadRawModifiedDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ReturnBounds", elementTree));
    
        return true;
    }
    
    bool
    ReadRawModifiedDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadRawModifiedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReadRawModifiedDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("IsReadModified");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadRawModifiedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, isReadModified_)) {
            Log(Error, "ReadRawModifiedDetails decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("StartTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadRawModifiedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!startTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ReadRawModifiedDetails decode xml error - decode failed")
                .parameter("Element", "StartTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("EndTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadRawModifiedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endTime_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ReadRawModifiedDetails decode xml error - decode failed")
                .parameter("Element", "EndTime");
            return false;
        }
    
        elementName = xmlns.addPrefix("NumValuesPerNode");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadRawModifiedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, numValuesPerNode_)) {
            Log(Error, "ReadRawModifiedDetails decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ReturnBounds");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadRawModifiedDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, returnBounds_)) {
            Log(Error, "ReadRawModifiedDetails decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ReadRawModifiedDetails::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, isReadModified_))
        {
    	     Log(Error, "ReadRawModifiedDetails json encoder error")
    		     .parameter("Element", "isReadModified_");
           return false;
        }
        pt.push_back(std::make_pair("IsReadModified", elementTree));
    
        elementTree.clear();
        if (!startTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ReadRawModifiedDetails json encoder error")
    		     .parameter("Element", "startTime_");
            return false;
        }
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!endTime_.jsonEncode(elementTree))
        {
    	     Log(Error, "ReadRawModifiedDetails json encoder error")
    		     .parameter("Element", "endTime_");
            return false;
        }
        pt.push_back(std::make_pair("EndTime", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, numValuesPerNode_))
        {
    	     Log(Error, "ReadRawModifiedDetails json encoder error")
    		     .parameter("Element", "numValuesPerNode_");
           return false;
        }
        pt.push_back(std::make_pair("NumValuesPerNode", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, returnBounds_))
        {
    	     Log(Error, "ReadRawModifiedDetails json encoder error")
    		     .parameter("Element", "returnBounds_");
           return false;
        }
        pt.push_back(std::make_pair("ReturnBounds", elementTree));
    
        return true;
    }
    
    bool
    ReadRawModifiedDetails::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "IsReadModified";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadRawModifiedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, isReadModified_)) {
            Log(Error, "ReadRawModifiedDetails decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "StartTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadRawModifiedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!startTime_.jsonDecode(*tree)) {
            Log(Error, "ReadRawModifiedDetails decode json error - decode failed")
                .parameter("Element", "StartTime");
            return false;
        }
    
        elementName = "EndTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadRawModifiedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!endTime_.jsonDecode(*tree)) {
            Log(Error, "ReadRawModifiedDetails decode json error - decode failed")
                .parameter("Element", "EndTime");
            return false;
        }
    
        elementName = "NumValuesPerNode";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadRawModifiedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, numValuesPerNode_)) {
            Log(Error, "ReadRawModifiedDetails decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ReturnBounds";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadRawModifiedDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, returnBounds_)) {
            Log(Error, "ReadRawModifiedDetails decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    ReadRawModifiedDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ReadRawModifiedDetails* dst = dynamic_cast<ReadRawModifiedDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ReadRawModifiedDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ReadRawModifiedDetails* dst = dynamic_cast<ReadRawModifiedDetails*>(&extensionObjectBase);
    	return *const_cast<ReadRawModifiedDetails*>(this) == *dst;
    }
    
    void
    ReadRawModifiedDetails::out(std::ostream& os)
    {
        os << "IsReadModified=" << isReadModified_;
        os << ", StartTime="; startTime_.out(os);
        os << ", EndTime="; endTime_.out(os);
        os << ", NumValuesPerNode=" << numValuesPerNode_;
        os << ", ReturnBounds=" << returnBounds_;
    }

}
