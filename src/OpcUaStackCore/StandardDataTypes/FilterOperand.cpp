/*
    DataTypeClass: FilterOperand

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/FilterOperand.h"

namespace OpcUaStackCore
{
    
    FilterOperand::FilterOperand(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    FilterOperand::FilterOperand(const FilterOperand& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<FilterOperand*>(&value)->copyTo(*this);
    }
    
    FilterOperand::~FilterOperand(void)
    {
    }
    
    bool
    FilterOperand::operator==(const FilterOperand& value)
    {
        FilterOperand* dst = const_cast<FilterOperand*>(&value);
        return true;
    }
    
    bool
    FilterOperand::operator!=(const FilterOperand& value)
    {
        return !this->operator==(value);
    }
    
    void
    FilterOperand::copyTo(FilterOperand& value)
    {
    }
    
    FilterOperand&
    FilterOperand::operator=(const FilterOperand& value)
    {
        const_cast<FilterOperand*>(&value)->copyTo(*this);
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
    FilterOperand::factory(void)
    {
    	return constructSPtr<FilterOperand>();
    }
    
    std::string
    FilterOperand::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    FilterOperand::typeName(void)
    {
    	return "FilterOperand";
    }
    
    OpcUaNodeId
    FilterOperand::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)589,0);
    }
    
    OpcUaNodeId
    FilterOperand::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)591, 0);
    }
    
    OpcUaNodeId
    FilterOperand::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)590, 0);
    }
    
    OpcUaNodeId
    FilterOperand::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15206, 0);
    }
    
    void
    FilterOperand::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    FilterOperand::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    FilterOperand::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "FilterOperand encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    FilterOperand::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    FilterOperand::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "FilterOperand decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    FilterOperand::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    FilterOperand::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    FilterOperand::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    FilterOperand::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	FilterOperand* dst = dynamic_cast<FilterOperand*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    FilterOperand::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	FilterOperand* dst = dynamic_cast<FilterOperand*>(&extensionObjectBase);
    	return *const_cast<FilterOperand*>(this) == *dst;
    }
    
    void
    FilterOperand::out(std::ostream& os)
    {
    }

}
