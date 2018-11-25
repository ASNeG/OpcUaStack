/*
    DataTypeClass: VariableAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/VariableAttributes.h"

namespace OpcUaStackCore
{
    
    /**
     * The attributes for a variable node.
     */
    VariableAttributes::VariableAttributes(void)
    : NodeAttributes()
    , value_()
    , dataType_()
    , valueRank_()
    , arrayDimensions_()
    , accessLevel_()
    , userAccessLevel_()
    , minimumSamplingInterval_()
    , historizing_()
    {
    }
    
    VariableAttributes::~VariableAttributes(void)
    {
    }
    
    OpcUaVariant&
    VariableAttributes::value(void)
    {
        return value_;
    }
    
    OpcUaNodeId&
    VariableAttributes::dataType(void)
    {
        return dataType_;
    }
    
    OpcUaInt32&
    VariableAttributes::valueRank(void)
    {
        return valueRank_;
    }
    
    OpcUaUInt32Array&
    VariableAttributes::arrayDimensions(void)
    {
        return arrayDimensions_;
    }
    
    OpcUaByte&
    VariableAttributes::accessLevel(void)
    {
        return accessLevel_;
    }
    
    OpcUaByte&
    VariableAttributes::userAccessLevel(void)
    {
        return userAccessLevel_;
    }
    
    OpcUaDuration&
    VariableAttributes::minimumSamplingInterval(void)
    {
        return minimumSamplingInterval_;
    }
    
    OpcUaBoolean&
    VariableAttributes::historizing(void)
    {
        return historizing_;
    }
    
    bool
    VariableAttributes::operator==(const VariableAttributes& value)
    {
        VariableAttributes* dst = const_cast<VariableAttributes*>(&value);
        if (value_ != dst->value()) return false;
        if (dataType_ != dst->dataType()) return false;
        if (valueRank_ != dst->valueRank()) return false;
        if (arrayDimensions_ != dst->arrayDimensions()) return false;
        if (accessLevel_ != dst->accessLevel()) return false;
        if (userAccessLevel_ != dst->userAccessLevel()) return false;
        if (minimumSamplingInterval_ != dst->minimumSamplingInterval()) return false;
        if (historizing_ != dst->historizing()) return false;
        return true;
    }
    
    bool
    VariableAttributes::operator!=(const VariableAttributes& value)
    {
        return !this->operator==(value);
    }
    
    void
    VariableAttributes::copyTo(VariableAttributes& value)
    {
        value_.copyTo(value.value());
        dataType_.copyTo(value.dataType());
        value.valueRank_ = valueRank_;
        arrayDimensions_.copyTo(value.arrayDimensions());
        value.accessLevel_ = accessLevel_;
        value.userAccessLevel_ = userAccessLevel_;
        value.minimumSamplingInterval_ = minimumSamplingInterval_;
        value.historizing_ = historizing_;
    }
    
    VariableAttributes&
    VariableAttributes::operator=(const VariableAttributes& value)
    {
        const_cast<VariableAttributes*>(&value)->copyTo(*this);
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
    VariableAttributes::factory(void)
    {
    	return constructSPtr<VariableAttributes>();
    }
    
    std::string
    VariableAttributes::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    VariableAttributes::typeName(void)
    {
    	return "VariableAttributes";
    }
    
    OpcUaNodeId
    VariableAttributes::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)355,0);
    }
    
    OpcUaNodeId
    VariableAttributes::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)357, 0);
    }
    
    OpcUaNodeId
    VariableAttributes::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)356, 0);
    }
    
    OpcUaNodeId
    VariableAttributes::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15153, 0);
    }
    
    void
    VariableAttributes::opcUaBinaryEncode(std::ostream& os) const
    {
        NodeAttributes::opcUaBinaryEncode(os);
        value_.opcUaBinaryEncode(os);
        dataType_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,valueRank_);
        arrayDimensions_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,accessLevel_);
        OpcUaNumber::opcUaBinaryEncode(os,userAccessLevel_);
        OpcUaNumber::opcUaBinaryEncode(os,minimumSamplingInterval_);
        OpcUaNumber::opcUaBinaryEncode(os,historizing_);
    }
    
    void
    VariableAttributes::opcUaBinaryDecode(std::istream& is)
    {
        NodeAttributes::opcUaBinaryDecode(is);
        value_.opcUaBinaryDecode(is);
        dataType_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,valueRank_);
        arrayDimensions_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,accessLevel_);
        OpcUaNumber::opcUaBinaryDecode(is,userAccessLevel_);
        OpcUaNumber::opcUaBinaryDecode(is,minimumSamplingInterval_);
        OpcUaNumber::opcUaBinaryDecode(is,historizing_);
    }
    
    bool
    VariableAttributes::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    VariableAttributes::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    VariableAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    VariableAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!value_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Value", elementTree));
    
        elementTree.clear();
        if (!dataType_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DataType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, valueRank_)) return false;
        pt.push_back(std::make_pair("ValueRank", elementTree));
    
        elementTree.clear();
        if (!arrayDimensions_.xmlEncode(elementTree, "UInt32", xmlns)) return false;
        pt.push_back(std::make_pair("ArrayDimensions", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, accessLevel_)) return false;
        pt.push_back(std::make_pair("AccessLevel", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, userAccessLevel_)) return false;
        pt.push_back(std::make_pair("UserAccessLevel", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, minimumSamplingInterval_)) return false;
        pt.push_back(std::make_pair("MinimumSamplingInterval", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, historizing_)) return false;
        pt.push_back(std::make_pair("Historizing", elementTree));
    
        return true;
    }
    
    bool
    VariableAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    VariableAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("Value");
        if (!tree) return false;
        if (!value_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("DataType");
        if (!tree) return false;
        if (!dataType_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ValueRank");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, valueRank_)) return false;
    
        tree = pt.get_child_optional("ArrayDimensions");
        if (!tree) return false;
        if (!arrayDimensions_.xmlDecode(*tree, "UInt32", xmlns)) return false;
    
        tree = pt.get_child_optional("AccessLevel");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, accessLevel_)) return false;
    
        tree = pt.get_child_optional("UserAccessLevel");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, userAccessLevel_)) return false;
    
        tree = pt.get_child_optional("MinimumSamplingInterval");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, minimumSamplingInterval_)) return false;
    
        tree = pt.get_child_optional("Historizing");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, historizing_)) return false;
    
        return true;
    }
    
    bool
    VariableAttributes::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    VariableAttributes::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    VariableAttributes::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    VariableAttributes::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    VariableAttributes::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	VariableAttributes* dst = dynamic_cast<VariableAttributes*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    VariableAttributes::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	VariableAttributes* dst = dynamic_cast<VariableAttributes*>(&extensionObjectBase);
    	return *const_cast<VariableAttributes*>(this) == *dst;
    }
    
    void
    VariableAttributes::out(std::ostream& os)
    {
        os << "Value="; value_.out(os);
        os << ", DataType="; dataType_.out(os);
        os << ", ValueRank=" << valueRank_;
        os << ", ArrayDimensions="; arrayDimensions_.out(os);
        os << ", AccessLevel=" << accessLevel_;
        os << ", UserAccessLevel=" << userAccessLevel_;
        os << ", MinimumSamplingInterval=" << minimumSamplingInterval_;
        os << ", Historizing=" << historizing_;
    }

}
