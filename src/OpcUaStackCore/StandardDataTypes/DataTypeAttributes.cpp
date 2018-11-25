/*
    DataTypeClass: DataTypeAttributes

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataTypeAttributes.h"

namespace OpcUaStackCore
{
    
    /**
     * The attributes for a data type node.
     */
    DataTypeAttributes::DataTypeAttributes(void)
    : NodeAttributes()
    , isAbstract_()
    {
    }
    
    DataTypeAttributes::~DataTypeAttributes(void)
    {
    }
    
    OpcUaBoolean&
    DataTypeAttributes::isAbstract(void)
    {
        return isAbstract_;
    }
    
    bool
    DataTypeAttributes::operator==(const DataTypeAttributes& value)
    {
        DataTypeAttributes* dst = const_cast<DataTypeAttributes*>(&value);
        if (isAbstract_ != dst->isAbstract()) return false;
        return true;
    }
    
    bool
    DataTypeAttributes::operator!=(const DataTypeAttributes& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataTypeAttributes::copyTo(DataTypeAttributes& value)
    {
        value.isAbstract_ = isAbstract_;
    }
    
    DataTypeAttributes&
    DataTypeAttributes::operator=(const DataTypeAttributes& value)
    {
        const_cast<DataTypeAttributes*>(&value)->copyTo(*this);
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
    DataTypeAttributes::factory(void)
    {
    	return constructSPtr<DataTypeAttributes>();
    }
    
    std::string
    DataTypeAttributes::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataTypeAttributes::typeName(void)
    {
    	return "DataTypeAttributes";
    }
    
    OpcUaNodeId
    DataTypeAttributes::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)370,0);
    }
    
    OpcUaNodeId
    DataTypeAttributes::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)372, 0);
    }
    
    OpcUaNodeId
    DataTypeAttributes::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)371, 0);
    }
    
    OpcUaNodeId
    DataTypeAttributes::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15161, 0);
    }
    
    void
    DataTypeAttributes::opcUaBinaryEncode(std::ostream& os) const
    {
        NodeAttributes::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,isAbstract_);
    }
    
    void
    DataTypeAttributes::opcUaBinaryDecode(std::istream& is)
    {
        NodeAttributes::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,isAbstract_);
    }
    
    bool
    DataTypeAttributes::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    DataTypeAttributes::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DataTypeAttributes::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataTypeAttributes::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, isAbstract_)) return false;
        pt.push_back(std::make_pair("IsAbstract", elementTree));
    
        return true;
    }
    
    bool
    DataTypeAttributes::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataTypeAttributes::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("IsAbstract");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, isAbstract_)) return false;
    
        return true;
    }
    
    bool
    DataTypeAttributes::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    DataTypeAttributes::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    DataTypeAttributes::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    DataTypeAttributes::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    DataTypeAttributes::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataTypeAttributes* dst = dynamic_cast<DataTypeAttributes*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataTypeAttributes::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataTypeAttributes* dst = dynamic_cast<DataTypeAttributes*>(&extensionObjectBase);
    	return *const_cast<DataTypeAttributes*>(this) == *dst;
    }
    
    void
    DataTypeAttributes::out(std::ostream& os)
    {
        os << "IsAbstract=" << isAbstract_;
    }

}
