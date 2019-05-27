/*
    DataTypeClass: ObjectTypeAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ObjectTypeAttributes.h"

namespace OpcUaStackCore
{
    
    /**
     * The attributes for an object type node.
     */
    ObjectTypeAttributes::ObjectTypeAttributes(void)
    : NodeAttributes()
    , isAbstract_()
    {
    }
    
    /**
     * The attributes for an object type node.
     */
    ObjectTypeAttributes::ObjectTypeAttributes(const ObjectTypeAttributes& value)
    : NodeAttributes()
    , isAbstract_()
    {
        const_cast<ObjectTypeAttributes*>(&value)->copyTo(*this);
    }
    
    ObjectTypeAttributes::~ObjectTypeAttributes(void)
    {
    }
    
    OpcUaBoolean&
    ObjectTypeAttributes::isAbstract(void)
    {
        return isAbstract_;
    }
    
    bool
    ObjectTypeAttributes::operator==(const ObjectTypeAttributes& value)
    {
        ObjectTypeAttributes* dst = const_cast<ObjectTypeAttributes*>(&value);
        if (isAbstract_ != dst->isAbstract()) return false;
        return true;
    }
    
    bool
    ObjectTypeAttributes::operator!=(const ObjectTypeAttributes& value)
    {
        return !this->operator==(value);
    }
    
    void
    ObjectTypeAttributes::copyTo(ObjectTypeAttributes& value)
    {
        value.isAbstract_ = isAbstract_;
    }
    
    ObjectTypeAttributes&
    ObjectTypeAttributes::operator=(const ObjectTypeAttributes& value)
    {
        const_cast<ObjectTypeAttributes*>(&value)->copyTo(*this);
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
    ObjectTypeAttributes::factory(void)
    {
    	return constructSPtr<ObjectTypeAttributes>();
    }
    
    std::string
    ObjectTypeAttributes::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ObjectTypeAttributes::typeName(void)
    {
    	return "ObjectTypeAttributes";
    }
    
    OpcUaNodeId
    ObjectTypeAttributes::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)361,0);
    }
    
    OpcUaNodeId
    ObjectTypeAttributes::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)363, 0);
    }
    
    OpcUaNodeId
    ObjectTypeAttributes::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)362, 0);
    }
    
    OpcUaNodeId
    ObjectTypeAttributes::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15158, 0);
    }
    
    void
    ObjectTypeAttributes::opcUaBinaryEncode(std::ostream& os) const
    {
        NodeAttributes::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,isAbstract_);
    }
    
    void
    ObjectTypeAttributes::opcUaBinaryDecode(std::istream& is)
    {
        NodeAttributes::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,isAbstract_);
    }
    
    bool
    ObjectTypeAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ObjectTypeAttributes encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ObjectTypeAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isAbstract_))
        {
            Log(Error, "ObjectTypeAttributes encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("IsAbstract", elementTree));
    
        return true;
    }
    
    bool
    ObjectTypeAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ObjectTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ObjectTypeAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("IsAbstract");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ObjectTypeAttributes decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, isAbstract_)) {
            Log(Error, "ObjectTypeAttributes decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ObjectTypeAttributes::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, isAbstract_))
        {
    	     Log(Error, "ObjectTypeAttributes json encoder error")
    		     .parameter("Element", "isAbstract_");
           return false;
        }
        pt.push_back(std::make_pair("IsAbstract", elementTree));
    
        return true;
    }
    
    bool
    ObjectTypeAttributes::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "IsAbstract";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ObjectTypeAttributes decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, isAbstract_)) {
            Log(Error, "ObjectTypeAttributes decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    ObjectTypeAttributes::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ObjectTypeAttributes* dst = dynamic_cast<ObjectTypeAttributes*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ObjectTypeAttributes::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ObjectTypeAttributes* dst = dynamic_cast<ObjectTypeAttributes*>(&extensionObjectBase);
    	return *const_cast<ObjectTypeAttributes*>(this) == *dst;
    }
    
    void
    ObjectTypeAttributes::out(std::ostream& os)
    {
        os << "IsAbstract=" << isAbstract_;
    }

}
