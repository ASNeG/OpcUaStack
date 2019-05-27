/*
    DataTypeClass: StructureDescription

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/StructureDescription.h"

namespace OpcUaStackCore
{
    
    StructureDescription::StructureDescription(void)
    : DataTypeDescription()
    , structureDefinition_()
    {
    }
    
    StructureDescription::StructureDescription(const StructureDescription& value)
    : DataTypeDescription()
    , structureDefinition_()
    {
        const_cast<StructureDescription*>(&value)->copyTo(*this);
    }
    
    StructureDescription::~StructureDescription(void)
    {
    }
    
    StructureDefinition&
    StructureDescription::structureDefinition(void)
    {
        return structureDefinition_;
    }
    
    bool
    StructureDescription::operator==(const StructureDescription& value)
    {
        StructureDescription* dst = const_cast<StructureDescription*>(&value);
        if (structureDefinition_ != dst->structureDefinition()) return false;
        return true;
    }
    
    bool
    StructureDescription::operator!=(const StructureDescription& value)
    {
        return !this->operator==(value);
    }
    
    void
    StructureDescription::copyTo(StructureDescription& value)
    {
        structureDefinition_.copyTo(value.structureDefinition());
    }
    
    StructureDescription&
    StructureDescription::operator=(const StructureDescription& value)
    {
        const_cast<StructureDescription*>(&value)->copyTo(*this);
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
    StructureDescription::factory(void)
    {
    	return constructSPtr<StructureDescription>();
    }
    
    std::string
    StructureDescription::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    StructureDescription::typeName(void)
    {
    	return "StructureDescription";
    }
    
    OpcUaNodeId
    StructureDescription::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15487,0);
    }
    
    OpcUaNodeId
    StructureDescription::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)126, 0);
    }
    
    OpcUaNodeId
    StructureDescription::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15589, 0);
    }
    
    OpcUaNodeId
    StructureDescription::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15058, 0);
    }
    
    void
    StructureDescription::opcUaBinaryEncode(std::ostream& os) const
    {
        DataTypeDescription::opcUaBinaryEncode(os);
        structureDefinition_.opcUaBinaryEncode(os);
    }
    
    void
    StructureDescription::opcUaBinaryDecode(std::istream& is)
    {
        DataTypeDescription::opcUaBinaryDecode(is);
        structureDefinition_.opcUaBinaryDecode(is);
    }
    
    bool
    StructureDescription::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "StructureDescription encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    StructureDescription::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!structureDefinition_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "StructureDescription encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("StructureDefinition", elementTree));
    
        return true;
    }
    
    bool
    StructureDescription::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    StructureDescription::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("StructureDefinition");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureDescription decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!structureDefinition_.xmlDecode(*tree, xmlns)) {
            Log(Error, "StructureDescription decode xml error - decode failed")
                .parameter("Element", "StructureDefinition");
            return false;
        }
    
        return true;
    }
    
    bool
    StructureDescription::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!structureDefinition_.jsonEncode(elementTree))
        {
    	     Log(Error, "StructureDescription json encoder error")
    		     .parameter("Element", "structureDefinition_");
            return false;
        }
        pt.push_back(std::make_pair("StructureDefinition", elementTree));
    
        return true;
    }
    
    bool
    StructureDescription::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "StructureDefinition";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "StructureDescription decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!structureDefinition_.jsonDecode(*tree)) {
            Log(Error, "StructureDescription decode json error - decode failed")
                .parameter("Element", "StructureDefinition");
            return false;
        }
    
        return true;
    }
    
    void
    StructureDescription::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	StructureDescription* dst = dynamic_cast<StructureDescription*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    StructureDescription::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	StructureDescription* dst = dynamic_cast<StructureDescription*>(&extensionObjectBase);
    	return *const_cast<StructureDescription*>(this) == *dst;
    }
    
    void
    StructureDescription::out(std::ostream& os)
    {
        os << "StructureDefinition="; structureDefinition_.out(os);
    }

}
