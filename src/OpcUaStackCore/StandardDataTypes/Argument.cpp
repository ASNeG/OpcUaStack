/*
    DataTypeClass: Argument

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/Argument.h"

namespace OpcUaStackCore
{
    
    /**
     * An argument for a method.
     */
    Argument::Argument(void)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , dataType_()
    , valueRank_()
    , arrayDimensions_()
    , description_()
    {
    }
    
    /**
     * An argument for a method.
     */
    Argument::Argument(const Argument& value)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , dataType_()
    , valueRank_()
    , arrayDimensions_()
    , description_()
    {
        const_cast<Argument*>(&value)->copyTo(*this);
    }
    
    Argument::~Argument(void)
    {
    }
    
    OpcUaString&
    Argument::name(void)
    {
        return name_;
    }
    
    OpcUaNodeId&
    Argument::dataType(void)
    {
        return dataType_;
    }
    
    OpcUaInt32&
    Argument::valueRank(void)
    {
        return valueRank_;
    }
    
    OpcUaUInt32Array&
    Argument::arrayDimensions(void)
    {
        return arrayDimensions_;
    }
    
    OpcUaLocalizedText&
    Argument::description(void)
    {
        return description_;
    }
    
    bool
    Argument::operator==(const Argument& value)
    {
        Argument* dst = const_cast<Argument*>(&value);
        if (name_ != dst->name()) return false;
        if (dataType_ != dst->dataType()) return false;
        if (valueRank_ != dst->valueRank()) return false;
        if (arrayDimensions_ != dst->arrayDimensions()) return false;
        if (description_ != dst->description()) return false;
        return true;
    }
    
    bool
    Argument::operator!=(const Argument& value)
    {
        return !this->operator==(value);
    }
    
    void
    Argument::copyTo(Argument& value)
    {
        name_.copyTo(value.name());
        dataType_.copyTo(value.dataType());
        value.valueRank_ = valueRank_;
        arrayDimensions_.copyTo(value.arrayDimensions());
        description_.copyTo(value.description());
    }
    
    Argument&
    Argument::operator=(const Argument& value)
    {
        const_cast<Argument*>(&value)->copyTo(*this);
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
    Argument::factory(void)
    {
    	return boost::make_shared<Argument>();
    }
    
    std::string
    Argument::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    Argument::typeName(void)
    {
    	return "Argument";
    }
    
    OpcUaNodeId
    Argument::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)296,0);
    }
    
    OpcUaNodeId
    Argument::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)298, 0);
    }
    
    OpcUaNodeId
    Argument::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)297, 0);
    }
    
    OpcUaNodeId
    Argument::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15081, 0);
    }
    
    bool
    Argument::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= name_.opcUaBinaryEncode(os);
        rc &= dataType_.opcUaBinaryEncode(os);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,valueRank_);
        rc &= arrayDimensions_.opcUaBinaryEncode(os);
        rc &= description_.opcUaBinaryEncode(os);
        return rc;
    }
    
    bool
    Argument::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= name_.opcUaBinaryDecode(is);
        rc &= dataType_.opcUaBinaryDecode(is);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,valueRank_);
        rc &= arrayDimensions_.opcUaBinaryDecode(is);
        rc &= description_.opcUaBinaryDecode(is);
        return rc;
    }
    
    bool
    Argument::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "Argument encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    Argument::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "Argument encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if (!dataType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "Argument encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, valueRank_))
        {
            Log(Error, "Argument encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ValueRank", elementTree));
    
        elementTree.clear();
        if (!arrayDimensions_.xmlEncode(elementTree, "UInt32", xmlns)) {
            Log(Error, "Argument encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ArrayDimensions", elementTree));
    
        elementTree.clear();
        if (!description_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "Argument encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Description", elementTree));
    
        return true;
    }
    
    bool
    Argument::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Argument decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    Argument::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Name");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Argument decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.xmlDecode(*tree, xmlns)) {
            Log(Error, "Argument decode xml error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        elementName = xmlns.addPrefix("DataType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Argument decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "Argument decode xml error - decode failed")
                .parameter("Element", "DataType");
            return false;
        }
    
        elementName = xmlns.addPrefix("ValueRank");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Argument decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, valueRank_)) {
            Log(Error, "Argument decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ArrayDimensions");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Argument decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!arrayDimensions_.xmlDecode(*tree, "UInt32", xmlns)) {
            Log(Error, "Argument decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("Description");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "Argument decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!description_.xmlDecode(*tree, xmlns)) {
            Log(Error, "Argument decode xml error - decode failed")
                .parameter("Element", "Description");
            return false;
        }
    
        return true;
    }
    
    bool
    Argument::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, name_, "Name", true);
        rc = rc & jsonObjectEncode(pt, dataType_, "DataType", true);
        rc = rc & jsonNumberEncode(pt, valueRank_, "ValueRank");
        rc = rc & jsonArrayEncode(pt, arrayDimensions_, "ArrayDimensions", true);
        rc = rc & jsonObjectEncode(pt, description_, "Description", true);
    
        return rc;
    }
    
    bool
    Argument::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, name_, "Name", true);
        rc = rc & jsonObjectDecode(pt, dataType_, "DataType", true);
        rc = rc & jsonNumberDecode(pt, valueRank_, "ValueRank");
        rc = rc & jsonArrayDecode(pt, arrayDimensions_, "ArrayDimensions", true);
        rc = rc & jsonObjectDecode(pt, description_, "Description", true);
    
        return rc;
    }
    
    void
    Argument::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	Argument* dst = dynamic_cast<Argument*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    Argument::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	Argument* dst = dynamic_cast<Argument*>(&extensionObjectBase);
    	return *const_cast<Argument*>(this) == *dst;
    }
    
    void
    Argument::out(std::ostream& os)
    {
        os << "Name="; name_.out(os);
        os << ", DataType="; dataType_.out(os);
        os << ", ValueRank=" << valueRank_;
        os << ", ArrayDimensions="; arrayDimensions_.out(os);
        os << ", Description="; description_.out(os);
    }

}
