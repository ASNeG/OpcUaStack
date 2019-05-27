/*
    DataTypeClass: ReadAtTimeDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ReadAtTimeDetails.h"

namespace OpcUaStackCore
{
    
    ReadAtTimeDetails::ReadAtTimeDetails(void)
    : HistoryReadDetails()
    , reqTimes_()
    , useSimpleBounds_()
    {
    }
    
    ReadAtTimeDetails::ReadAtTimeDetails(const ReadAtTimeDetails& value)
    : HistoryReadDetails()
    , reqTimes_()
    , useSimpleBounds_()
    {
        const_cast<ReadAtTimeDetails*>(&value)->copyTo(*this);
    }
    
    ReadAtTimeDetails::~ReadAtTimeDetails(void)
    {
    }
    
    OpcUaUtcTimeArray&
    ReadAtTimeDetails::reqTimes(void)
    {
        return reqTimes_;
    }
    
    OpcUaBoolean&
    ReadAtTimeDetails::useSimpleBounds(void)
    {
        return useSimpleBounds_;
    }
    
    bool
    ReadAtTimeDetails::operator==(const ReadAtTimeDetails& value)
    {
        ReadAtTimeDetails* dst = const_cast<ReadAtTimeDetails*>(&value);
        if (reqTimes_ != dst->reqTimes()) return false;
        if (useSimpleBounds_ != dst->useSimpleBounds()) return false;
        return true;
    }
    
    bool
    ReadAtTimeDetails::operator!=(const ReadAtTimeDetails& value)
    {
        return !this->operator==(value);
    }
    
    void
    ReadAtTimeDetails::copyTo(ReadAtTimeDetails& value)
    {
        reqTimes_.copyTo(value.reqTimes());
        value.useSimpleBounds_ = useSimpleBounds_;
    }
    
    ReadAtTimeDetails&
    ReadAtTimeDetails::operator=(const ReadAtTimeDetails& value)
    {
        const_cast<ReadAtTimeDetails*>(&value)->copyTo(*this);
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
    ReadAtTimeDetails::factory(void)
    {
    	return constructSPtr<ReadAtTimeDetails>();
    }
    
    std::string
    ReadAtTimeDetails::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ReadAtTimeDetails::typeName(void)
    {
    	return "ReadAtTimeDetails";
    }
    
    OpcUaNodeId
    ReadAtTimeDetails::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)653,0);
    }
    
    OpcUaNodeId
    ReadAtTimeDetails::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)655, 0);
    }
    
    OpcUaNodeId
    ReadAtTimeDetails::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)654, 0);
    }
    
    OpcUaNodeId
    ReadAtTimeDetails::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15269, 0);
    }
    
    void
    ReadAtTimeDetails::opcUaBinaryEncode(std::ostream& os) const
    {
        HistoryReadDetails::opcUaBinaryEncode(os);
        reqTimes_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,useSimpleBounds_);
    }
    
    void
    ReadAtTimeDetails::opcUaBinaryDecode(std::istream& is)
    {
        HistoryReadDetails::opcUaBinaryDecode(is);
        reqTimes_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,useSimpleBounds_);
    }
    
    bool
    ReadAtTimeDetails::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ReadAtTimeDetails encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReadAtTimeDetails::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!reqTimes_.xmlEncode(elementTree, "UtcTime", xmlns)) {
            Log(Error, "ReadAtTimeDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ReqTimes", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, useSimpleBounds_))
        {
            Log(Error, "ReadAtTimeDetails encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("UseSimpleBounds", elementTree));
    
        return true;
    }
    
    bool
    ReadAtTimeDetails::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadAtTimeDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReadAtTimeDetails::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ReqTimes");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadAtTimeDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!reqTimes_.xmlDecode(*tree, "UtcTime", xmlns)) {
            Log(Error, "ReadAtTimeDetails decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("UseSimpleBounds");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadAtTimeDetails decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, useSimpleBounds_)) {
            Log(Error, "ReadAtTimeDetails decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ReadAtTimeDetails::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!reqTimes_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ReadAtTimeDetails json encoder error")
    		     .parameter("Element", "reqTimes_");
            return false;
        }
        pt.push_back(std::make_pair("ReqTimes", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, useSimpleBounds_))
        {
    	     Log(Error, "ReadAtTimeDetails json encoder error")
    		     .parameter("Element", "useSimpleBounds_");
           return false;
        }
        pt.push_back(std::make_pair("UseSimpleBounds", elementTree));
    
        return true;
    }
    
    bool
    ReadAtTimeDetails::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "ReqTimes";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadAtTimeDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!reqTimes_.jsonDecode(*tree, "")) {
            Log(Error, "ReadAtTimeDetails decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "UseSimpleBounds";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReadAtTimeDetails decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, useSimpleBounds_)) {
            Log(Error, "ReadAtTimeDetails decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    ReadAtTimeDetails::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ReadAtTimeDetails* dst = dynamic_cast<ReadAtTimeDetails*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ReadAtTimeDetails::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ReadAtTimeDetails* dst = dynamic_cast<ReadAtTimeDetails*>(&extensionObjectBase);
    	return *const_cast<ReadAtTimeDetails*>(this) == *dst;
    }
    
    void
    ReadAtTimeDetails::out(std::ostream& os)
    {
        os << "ReqTimes="; reqTimes_.out(os);
        os << ", UseSimpleBounds=" << useSimpleBounds_;
    }

}
