/*
    DataTypeClass: TargetVariablesDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/TargetVariablesDataType.h"

namespace OpcUaStackCore
{
    
    TargetVariablesDataType::TargetVariablesDataType(void)
    : SubscribedDataSetDataType()
    , targetVariables_()
    {
    }
    
    TargetVariablesDataType::~TargetVariablesDataType(void)
    {
    }
    
    FieldTargetDataTypeArray&
    TargetVariablesDataType::targetVariables(void)
    {
        return targetVariables_;
    }
    
    bool
    TargetVariablesDataType::operator==(const TargetVariablesDataType& value)
    {
        TargetVariablesDataType* dst = const_cast<TargetVariablesDataType*>(&value);
        if (targetVariables_ != dst->targetVariables()) return false;
        return true;
    }
    
    bool
    TargetVariablesDataType::operator!=(const TargetVariablesDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    TargetVariablesDataType::copyTo(TargetVariablesDataType& value)
    {
        targetVariables_.copyTo(value.targetVariables());
    }
    
    TargetVariablesDataType&
    TargetVariablesDataType::operator=(const TargetVariablesDataType& value)
    {
        const_cast<TargetVariablesDataType*>(&value)->copyTo(*this);
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
    TargetVariablesDataType::factory(void)
    {
    	return constructSPtr<TargetVariablesDataType>();
    }
    
    std::string
    TargetVariablesDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    TargetVariablesDataType::typeName(void)
    {
    	return "TargetVariablesDataType";
    }
    
    OpcUaNodeId
    TargetVariablesDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15631,0);
    }
    
    OpcUaNodeId
    TargetVariablesDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15712, 0);
    }
    
    OpcUaNodeId
    TargetVariablesDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16011, 0);
    }
    
    OpcUaNodeId
    TargetVariablesDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16310, 0);
    }
    
    void
    TargetVariablesDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        targetVariables_.opcUaBinaryEncode(os);
    }
    
    void
    TargetVariablesDataType::opcUaBinaryDecode(std::istream& is)
    {
        targetVariables_.opcUaBinaryDecode(is);
    }
    
    bool
    TargetVariablesDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    TargetVariablesDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    TargetVariablesDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    TargetVariablesDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!targetVariables_.xmlEncode(elementTree, "FieldTargetDataType", xmlns)) return false;
        pt.push_back(std::make_pair("TargetVariables", elementTree));
    
        return true;
    }
    
    bool
    TargetVariablesDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    TargetVariablesDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("TargetVariables");
        if (!tree) return false;
        if (!targetVariables_.xmlDecode(*tree, "FieldTargetDataType", xmlns)) return false;
    
        return true;
    }
    
    bool
    TargetVariablesDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    TargetVariablesDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    TargetVariablesDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    TargetVariablesDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    TargetVariablesDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	TargetVariablesDataType* dst = dynamic_cast<TargetVariablesDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    TargetVariablesDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	TargetVariablesDataType* dst = dynamic_cast<TargetVariablesDataType*>(&extensionObjectBase);
    	return *const_cast<TargetVariablesDataType*>(this) == *dst;
    }
    
    void
    TargetVariablesDataType::out(std::ostream& os)
    {
        os << "TargetVariables="; targetVariables_.out(os);
    }

}
