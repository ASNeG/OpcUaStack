/*
    DataTypeClass: SubscribedDataSetDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/SubscribedDataSetDataType.h"

namespace OpcUaStackCore
{
    
    SubscribedDataSetDataType::SubscribedDataSetDataType(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    SubscribedDataSetDataType::~SubscribedDataSetDataType(void)
    {
    }
    
    bool
    SubscribedDataSetDataType::operator==(const SubscribedDataSetDataType& value)
    {
        SubscribedDataSetDataType* dst = const_cast<SubscribedDataSetDataType*>(&value);
        return true;
    }
    
    bool
    SubscribedDataSetDataType::operator!=(const SubscribedDataSetDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    SubscribedDataSetDataType::copyTo(SubscribedDataSetDataType& value)
    {
    }
    
    SubscribedDataSetDataType&
    SubscribedDataSetDataType::operator=(const SubscribedDataSetDataType& value)
    {
        const_cast<SubscribedDataSetDataType*>(&value)->copyTo(*this);
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
    SubscribedDataSetDataType::factory(void)
    {
    	return constructSPtr<SubscribedDataSetDataType>();
    }
    
    std::string
    SubscribedDataSetDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    SubscribedDataSetDataType::typeName(void)
    {
    	return "SubscribedDataSetDataType";
    }
    
    OpcUaNodeId
    SubscribedDataSetDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15630,0);
    }
    
    OpcUaNodeId
    SubscribedDataSetDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15707, 0);
    }
    
    OpcUaNodeId
    SubscribedDataSetDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16010, 0);
    }
    
    OpcUaNodeId
    SubscribedDataSetDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16308, 0);
    }
    
    void
    SubscribedDataSetDataType::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    SubscribedDataSetDataType::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    SubscribedDataSetDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    SubscribedDataSetDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    SubscribedDataSetDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    SubscribedDataSetDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    SubscribedDataSetDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SubscribedDataSetDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    SubscribedDataSetDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    SubscribedDataSetDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    SubscribedDataSetDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    SubscribedDataSetDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    SubscribedDataSetDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	SubscribedDataSetDataType* dst = dynamic_cast<SubscribedDataSetDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    SubscribedDataSetDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	SubscribedDataSetDataType* dst = dynamic_cast<SubscribedDataSetDataType*>(&extensionObjectBase);
    	return *const_cast<SubscribedDataSetDataType*>(this) == *dst;
    }
    
    void
    SubscribedDataSetDataType::out(std::ostream& os)
    {
    }

}
