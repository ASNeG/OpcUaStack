/*
    DataTypeClass: RelativePath

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/RelativePath.h"

namespace OpcUaStackCore
{
    
    /**
     * A relative path constructed from reference types and browse names.
     */
    RelativePath::RelativePath(void)
    : Object()
    , ExtensionObjectBase()
    , elements_()
    {
    }
    
    /**
     * A relative path constructed from reference types and browse names.
     */
    RelativePath::RelativePath(const RelativePath& value)
    : Object()
    , ExtensionObjectBase()
    , elements_()
    {
        const_cast<RelativePath*>(&value)->copyTo(*this);
    }
    
    RelativePath::~RelativePath(void)
    {
    }
    
    RelativePathElementArray&
    RelativePath::elements(void)
    {
        return elements_;
    }
    
    bool
    RelativePath::operator==(const RelativePath& value)
    {
        RelativePath* dst = const_cast<RelativePath*>(&value);
        if (elements_ != dst->elements()) return false;
        return true;
    }
    
    bool
    RelativePath::operator!=(const RelativePath& value)
    {
        return !this->operator==(value);
    }
    
    void
    RelativePath::copyTo(RelativePath& value)
    {
        elements_.copyTo(value.elements());
    }
    
    RelativePath&
    RelativePath::operator=(const RelativePath& value)
    {
        const_cast<RelativePath*>(&value)->copyTo(*this);
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
    RelativePath::factory(void)
    {
    	return constructSPtr<RelativePath>();
    }
    
    std::string
    RelativePath::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    RelativePath::typeName(void)
    {
    	return "RelativePath";
    }
    
    OpcUaNodeId
    RelativePath::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)540,0);
    }
    
    OpcUaNodeId
    RelativePath::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)542, 0);
    }
    
    OpcUaNodeId
    RelativePath::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)541, 0);
    }
    
    OpcUaNodeId
    RelativePath::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15189, 0);
    }
    
    void
    RelativePath::opcUaBinaryEncode(std::ostream& os) const
    {
        elements_.opcUaBinaryEncode(os);
    }
    
    void
    RelativePath::opcUaBinaryDecode(std::istream& is)
    {
        elements_.opcUaBinaryDecode(is);
    }
    
    bool
    RelativePath::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "RelativePath encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    RelativePath::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!elements_.xmlEncode(elementTree, "RelativePathElement", xmlns)) {
            Log(Error, "RelativePath encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Elements", elementTree));
    
        return true;
    }
    
    bool
    RelativePath::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RelativePath decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    RelativePath::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Elements");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RelativePath decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!elements_.xmlDecode(*tree, "RelativePathElement", xmlns)) {
            Log(Error, "RelativePath decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    RelativePath::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!elements_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "RelativePath json encoder error")
    		     .parameter("Element", "elements_");
            return false;
        }
        pt.push_back(std::make_pair("Elements", elementTree));
    
        return true;
    }
    
    bool
    RelativePath::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Elements";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "RelativePath decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!elements_.jsonDecode(*tree, "")) {
            Log(Error, "RelativePath decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    RelativePath::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	RelativePath* dst = dynamic_cast<RelativePath*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    RelativePath::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	RelativePath* dst = dynamic_cast<RelativePath*>(&extensionObjectBase);
    	return *const_cast<RelativePath*>(this) == *dst;
    }
    
    void
    RelativePath::out(std::ostream& os)
    {
        os << "Elements="; elements_.out(os);
    }

}
