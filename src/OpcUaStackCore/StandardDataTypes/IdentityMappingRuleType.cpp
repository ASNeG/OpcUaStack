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
    
    IdentityMappingRuleType::IdentityMappingRuleType(const IdentityMappingRuleType& value)
    : Object()
    , ExtensionObjectBase()
    , criteriaType_()
    , criteria_()
    {
        const_cast<IdentityMappingRuleType*>(&value)->copyTo(*this);
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
    IdentityMappingRuleType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "IdentityMappingRuleType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    IdentityMappingRuleType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!criteriaType_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "IdentityMappingRuleType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CriteriaType", elementTree));
    
        elementTree.clear();
        if (!criteria_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "IdentityMappingRuleType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Criteria", elementTree));
    
        return true;
    }
    
    bool
    IdentityMappingRuleType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "IdentityMappingRuleType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    IdentityMappingRuleType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("CriteriaType");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "IdentityMappingRuleType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!criteriaType_.xmlDecode(*tree, xmlns)) {
            Log(Error, "IdentityMappingRuleType decode xml error - decode failed")
                .parameter("Element", "CriteriaType");
            return false;
        }
    
        elementName = xmlns.addPrefix("Criteria");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "IdentityMappingRuleType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!criteria_.xmlDecode(*tree, xmlns)) {
            Log(Error, "IdentityMappingRuleType decode xml error - decode failed")
                .parameter("Element", "Criteria");
            return false;
        }
    
        return true;
    }
    
    bool
    IdentityMappingRuleType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!criteriaType_.jsonEncode(elementTree))
        {
    	     Log(Error, "IdentityMappingRuleType json encoder error")
    		     .parameter("Element", "criteriaType_");
            return false;
        }
        pt.push_back(std::make_pair("CriteriaType", elementTree));
    
        elementTree.clear();
        if (!criteria_.jsonEncode(elementTree))
        {
    	     Log(Error, "IdentityMappingRuleType json encoder error")
    		     .parameter("Element", "criteria_");
            return false;
        }
        pt.push_back(std::make_pair("Criteria", elementTree));
    
        return true;
    }
    
    bool
    IdentityMappingRuleType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "CriteriaType";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "IdentityMappingRuleType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!criteriaType_.jsonDecode(*tree)) {
            Log(Error, "IdentityMappingRuleType decode json error - decode failed")
                .parameter("Element", "CriteriaType");
            return false;
        }
    
        elementName = "Criteria";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "IdentityMappingRuleType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!criteria_.jsonDecode(*tree)) {
            Log(Error, "IdentityMappingRuleType decode json error - decode failed")
                .parameter("Element", "Criteria");
            return false;
        }
    
        return true;
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
