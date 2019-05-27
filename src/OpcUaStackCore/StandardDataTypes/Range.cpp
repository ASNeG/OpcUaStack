/*
    DataTypeClass: Range

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/Range.h"

namespace OpcUaStackCore
{
    
    Range::Range(void)
    : Object()
    , ExtensionObjectBase()
    , low_()
    , high_()
    {
    }
    
    Range::Range(const Range& value)
    : Object()
    , ExtensionObjectBase()
    , low_()
    , high_()
    {
        const_cast<Range*>(&value)->copyTo(*this);
    }
    
    Range::~Range(void)
    {
    }
    
    OpcUaDouble&
    Range::low(void)
    {
        return low_;
    }
    
    OpcUaDouble&
    Range::high(void)
    {
        return high_;
    }
    
    bool
    Range::operator==(const Range& value)
    {
        Range* dst = const_cast<Range*>(&value);
        if (low_ != dst->low()) return false;
        if (high_ != dst->high()) return false;
        return true;
    }
    
    bool
    Range::operator!=(const Range& value)
    {
        return !this->operator==(value);
    }
    
    void
    Range::copyTo(Range& value)
    {
        value.low_ = low_;
        value.high_ = high_;
    }
    
    Range&
    Range::operator=(const Range& value)
    {
        const_cast<Range*>(&value)->copyTo(*this);
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
    Range::factory(void)
    {
    	return constructSPtr<Range>();
    }
    
    std::string
    Range::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    Range::typeName(void)
    {
    	return "Range";
    }
    
    OpcUaNodeId
    Range::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)884,0);
    }
    
    OpcUaNodeId
    Range::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)886, 0);
    }
    
    OpcUaNodeId
    Range::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)885, 0);
    }
    
    OpcUaNodeId
    Range::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15375, 0);
    }
    
    void
    Range::opcUaBinaryEncode(std::ostream& os) const
    {
        OpcUaNumber::opcUaBinaryEncode(os,low_);
        OpcUaNumber::opcUaBinaryEncode(os,high_);
    }
    
    void
    Range::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,low_);
        OpcUaNumber::opcUaBinaryDecode(is,high_);
    }
    
    bool
    Range::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "Range encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    Range::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, low_))
        {
            Log(Error, "Range encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Low", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, high_))
        {
            Log(Error, "Range encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("High", elementTree));
    
        return true;
    }
    
    bool
    Range::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Range decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    Range::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Low");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Range decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, low_)) {
            Log(Error, "Range decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("High");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Range decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, high_)) {
            Log(Error, "Range decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    Range::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, low_))
        {
    	     Log(Error, "Range json encoder error")
    		     .parameter("Element", "low_");
           return false;
        }
        pt.push_back(std::make_pair("Low", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, high_))
        {
    	     Log(Error, "Range json encoder error")
    		     .parameter("Element", "high_");
           return false;
        }
        pt.push_back(std::make_pair("High", elementTree));
    
        return true;
    }
    
    bool
    Range::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Low";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Range decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, low_)) {
            Log(Error, "Range decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "High";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Range decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, high_)) {
            Log(Error, "Range decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    Range::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	Range* dst = dynamic_cast<Range*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    Range::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	Range* dst = dynamic_cast<Range*>(&extensionObjectBase);
    	return *const_cast<Range*>(this) == *dst;
    }
    
    void
    Range::out(std::ostream& os)
    {
        os << "Low=" << low_;
        os << ", High=" << high_;
    }

}
