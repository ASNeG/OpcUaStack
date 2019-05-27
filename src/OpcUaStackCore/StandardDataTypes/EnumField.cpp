/*
    DataTypeClass: EnumField

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/EnumField.h"

namespace OpcUaStackCore
{
    
    EnumField::EnumField(void)
    : EnumValueType()
    , name_()
    {
    }
    
    EnumField::EnumField(const EnumField& value)
    : EnumValueType()
    , name_()
    {
        const_cast<EnumField*>(&value)->copyTo(*this);
    }
    
    EnumField::~EnumField(void)
    {
    }
    
    OpcUaString&
    EnumField::name(void)
    {
        return name_;
    }
    
    bool
    EnumField::operator==(const EnumField& value)
    {
        EnumField* dst = const_cast<EnumField*>(&value);
        if (name_ != dst->name()) return false;
        return true;
    }
    
    bool
    EnumField::operator!=(const EnumField& value)
    {
        return !this->operator==(value);
    }
    
    void
    EnumField::copyTo(EnumField& value)
    {
        name_.copyTo(value.name());
    }
    
    EnumField&
    EnumField::operator=(const EnumField& value)
    {
        const_cast<EnumField*>(&value)->copyTo(*this);
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
    EnumField::factory(void)
    {
    	return constructSPtr<EnumField>();
    }
    
    std::string
    EnumField::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    EnumField::typeName(void)
    {
    	return "EnumField";
    }
    
    OpcUaNodeId
    EnumField::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)102,0);
    }
    
    OpcUaNodeId
    EnumField::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14845, 0);
    }
    
    OpcUaNodeId
    EnumField::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)14801, 0);
    }
    
    OpcUaNodeId
    EnumField::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15083, 0);
    }
    
    void
    EnumField::opcUaBinaryEncode(std::ostream& os) const
    {
        EnumValueType::opcUaBinaryEncode(os);
        name_.opcUaBinaryEncode(os);
    }
    
    void
    EnumField::opcUaBinaryDecode(std::istream& is)
    {
        EnumValueType::opcUaBinaryDecode(is);
        name_.opcUaBinaryDecode(is);
    }
    
    bool
    EnumField::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "EnumField encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    EnumField::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "EnumField encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        return true;
    }
    
    bool
    EnumField::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumField decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    EnumField::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Name");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumField decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.xmlDecode(*tree, xmlns)) {
            Log(Error, "EnumField decode xml error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        return true;
    }
    
    bool
    EnumField::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.jsonEncode(elementTree))
        {
    	     Log(Error, "EnumField json encoder error")
    		     .parameter("Element", "name_");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        return true;
    }
    
    bool
    EnumField::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Name";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "EnumField decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.jsonDecode(*tree)) {
            Log(Error, "EnumField decode json error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        return true;
    }
    
    void
    EnumField::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	EnumField* dst = dynamic_cast<EnumField*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    EnumField::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	EnumField* dst = dynamic_cast<EnumField*>(&extensionObjectBase);
    	return *const_cast<EnumField*>(this) == *dst;
    }
    
    void
    EnumField::out(std::ostream& os)
    {
        os << "Name="; name_.out(os);
    }

}
