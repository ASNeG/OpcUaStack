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
    FilterOperand::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    FilterOperand::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    FilterOperand::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
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
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    FilterOperand::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    FilterOperand::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    FilterOperand::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    FilterOperand::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    FilterOperand::jsonDecode(boost::property_tree::ptree& pt)
    {
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
