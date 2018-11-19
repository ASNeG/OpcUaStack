/*
    DataTypeClass: IdentityMappingRuleType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/IdentityMappingRuleType.h"

namespace OpcUaStackCore
{
    
    IdentityMappingRuleType::IdentityMappingRuleType(void)
    : Object()
    , ExtensionObjectBase()
    , criteriaType_()
    , criteria_()
    {
    }
    
    IdentityMappingRuleType::~IdentityMappingRuleType(void)
    {
    }
    
    IdentityCriteriaType&
    IdentityMappingRuleType::criteriaType(void)
    {
        return criteriaType_;
    }
    
    OpcUaString&
    IdentityMappingRuleType::criteria(void)
    {
        return criteria_;
    }
    
    bool
    IdentityMappingRuleType::operator==(const IdentityMappingRuleType& value)
    {
        IdentityMappingRuleType* dst = const_cast<IdentityMappingRuleType*>(&value);
        if (criteriaType_ != dst->criteriaType()) return false;
        if (criteria_ != dst->criteria()) return false;
        return true;
    }
    
    bool
    IdentityMappingRuleType::operator!=(const IdentityMappingRuleType& value)
    {
        return !this->operator==(value);
    }
    
    void
    IdentityMappingRuleType::copyTo(IdentityMappingRuleType& value)
    {
        criteriaType_.copyTo(value.criteriaType());
        criteria_.copyTo(value.criteria());
    }
    
    IdentityMappingRuleType&
    IdentityMappingRuleType::operator=(const IdentityMappingRuleType& value)
    {
        const_cast<IdentityMappingRuleType*>(&value)->copyTo(*this);
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
    IdentityMappingRuleType::factory(void)
    {
    	return constructSPtr<IdentityMappingRuleType>();
    }
    
    std::string
    IdentityMappingRuleType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    IdentityMappingRuleType::typeName(void)
    {
    	return "IdentityMappingRuleType";
    }
    
    OpcUaNodeId
    IdentityMappingRuleType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15634,0);
    }
    
    OpcUaNodeId
    IdentityMappingRuleType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15736, 0);
    }
    
    OpcUaNodeId
    IdentityMappingRuleType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15728, 0);
    }
    
    OpcUaNodeId
    IdentityMappingRuleType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15042, 0);
    }
    
    void
    IdentityMappingRuleType::opcUaBinaryEncode(std::ostream& os) const
    {
        criteriaType_.opcUaBinaryEncode(os);
        criteria_.opcUaBinaryEncode(os);
    }
    
    void
    IdentityMappingRuleType::opcUaBinaryDecode(std::istream& is)
    {
        criteriaType_.opcUaBinaryDecode(is);
        criteria_.opcUaBinaryDecode(is);
    }
    
    bool
    IdentityMappingRuleType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    IdentityMappingRuleType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    IdentityMappingRuleType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    IdentityMappingRuleType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!criteriaType_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("CriteriaType", elementTree));
    
        elementTree.clear();
        if (!criteria_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Criteria", elementTree));
    
        return true;
    }
    
    bool
    IdentityMappingRuleType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    IdentityMappingRuleType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("CriteriaType");
        if (!tree) return false;
        if (!criteriaType_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Criteria");
        if (!tree) return false;
        if (!criteria_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    IdentityMappingRuleType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    IdentityMappingRuleType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    IdentityMappingRuleType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    IdentityMappingRuleType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    IdentityMappingRuleType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	IdentityMappingRuleType* dst = dynamic_cast<IdentityMappingRuleType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    IdentityMappingRuleType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	IdentityMappingRuleType* dst = dynamic_cast<IdentityMappingRuleType*>(&extensionObjectBase);
    	return *const_cast<IdentityMappingRuleType*>(this) == *dst;
    }
    
    void
    IdentityMappingRuleType::out(std::ostream& os)
    {
        os << "CriteriaType="; criteriaType_.out(os);
        os << ", Criteria="; criteria_.out(os);
    }

}
