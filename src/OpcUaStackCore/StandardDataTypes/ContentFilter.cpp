/*
    DataTypeClass: ContentFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ContentFilter.h"

namespace OpcUaStackCore
{
    
    ContentFilter::ContentFilter(void)
    : Object()
    , ExtensionObjectBase()
    , elements_()
    {
    }
    
    ContentFilter::ContentFilter(const ContentFilter& value)
    : Object()
    , ExtensionObjectBase()
    , elements_()
    {
        const_cast<ContentFilter*>(&value)->copyTo(*this);
    }
    
    ContentFilter::~ContentFilter(void)
    {
    }
    
    ContentFilterElementArray&
    ContentFilter::elements(void)
    {
        return elements_;
    }
    
    bool
    ContentFilter::operator==(const ContentFilter& value)
    {
        ContentFilter* dst = const_cast<ContentFilter*>(&value);
        if (elements_ != dst->elements()) return false;
        return true;
    }
    
    bool
    ContentFilter::operator!=(const ContentFilter& value)
    {
        return !this->operator==(value);
    }
    
    void
    ContentFilter::copyTo(ContentFilter& value)
    {
        elements_.copyTo(value.elements());
    }
    
    ContentFilter&
    ContentFilter::operator=(const ContentFilter& value)
    {
        const_cast<ContentFilter*>(&value)->copyTo(*this);
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
    ContentFilter::factory(void)
    {
    	return constructSPtr<ContentFilter>();
    }
    
    std::string
    ContentFilter::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ContentFilter::typeName(void)
    {
    	return "ContentFilter";
    }
    
    OpcUaNodeId
    ContentFilter::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)586,0);
    }
    
    OpcUaNodeId
    ContentFilter::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)588, 0);
    }
    
    OpcUaNodeId
    ContentFilter::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)587, 0);
    }
    
    OpcUaNodeId
    ContentFilter::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15205, 0);
    }
    
    void
    ContentFilter::opcUaBinaryEncode(std::ostream& os) const
    {
        elements_.opcUaBinaryEncode(os);
    }
    
    void
    ContentFilter::opcUaBinaryDecode(std::istream& is)
    {
        elements_.opcUaBinaryDecode(is);
    }
    
    bool
    ContentFilter::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ContentFilter encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ContentFilter::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!elements_.xmlEncode(elementTree, "ContentFilterElement", xmlns)) {
            Log(Error, "ContentFilter encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Elements", elementTree));
    
        return true;
    }
    
    bool
    ContentFilter::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ContentFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ContentFilter::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Elements");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ContentFilter decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!elements_.xmlDecode(*tree, "ContentFilterElement", xmlns)) {
            Log(Error, "ContentFilter decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ContentFilter::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!elements_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "ContentFilter json encoder error")
    		     .parameter("Element", "elements_");
            return false;
        }
        pt.push_back(std::make_pair("Elements", elementTree));
    
        return true;
    }
    
    bool
    ContentFilter::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Elements";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ContentFilter decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!elements_.jsonDecode(*tree, "")) {
            Log(Error, "ContentFilter decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    ContentFilter::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ContentFilter* dst = dynamic_cast<ContentFilter*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ContentFilter::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ContentFilter* dst = dynamic_cast<ContentFilter*>(&extensionObjectBase);
    	return *const_cast<ContentFilter*>(this) == *dst;
    }
    
    void
    ContentFilter::out(std::ostream& os)
    {
        os << "Elements="; elements_.out(os);
    }

}
