/*
    DataTypeClass: WriterGroupTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/WriterGroupTransportDataType.h"

namespace OpcUaStackCore
{
    
    WriterGroupTransportDataType::WriterGroupTransportDataType(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    WriterGroupTransportDataType::WriterGroupTransportDataType(const WriterGroupTransportDataType& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<WriterGroupTransportDataType*>(&value)->copyTo(*this);
    }
    
    WriterGroupTransportDataType::~WriterGroupTransportDataType(void)
    {
    }
    
    bool
    WriterGroupTransportDataType::operator==(const WriterGroupTransportDataType& value)
    {
        WriterGroupTransportDataType* dst = const_cast<WriterGroupTransportDataType*>(&value);
        return true;
    }
    
    bool
    WriterGroupTransportDataType::operator!=(const WriterGroupTransportDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    WriterGroupTransportDataType::copyTo(WriterGroupTransportDataType& value)
    {
    }
    
    WriterGroupTransportDataType&
    WriterGroupTransportDataType::operator=(const WriterGroupTransportDataType& value)
    {
        const_cast<WriterGroupTransportDataType*>(&value)->copyTo(*this);
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
    WriterGroupTransportDataType::factory(void)
    {
    	return constructSPtr<WriterGroupTransportDataType>();
    }
    
    std::string
    WriterGroupTransportDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    WriterGroupTransportDataType::typeName(void)
    {
    	return "WriterGroupTransportDataType";
    }
    
    OpcUaNodeId
    WriterGroupTransportDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15611,0);
    }
    
    OpcUaNodeId
    WriterGroupTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15691, 0);
    }
    
    OpcUaNodeId
    WriterGroupTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15990, 0);
    }
    
    OpcUaNodeId
    WriterGroupTransportDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16161, 0);
    }
    
    void
    WriterGroupTransportDataType::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    WriterGroupTransportDataType::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    WriterGroupTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "WriterGroupTransportDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    WriterGroupTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    WriterGroupTransportDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "WriterGroupTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    WriterGroupTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    WriterGroupTransportDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    WriterGroupTransportDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    WriterGroupTransportDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	WriterGroupTransportDataType* dst = dynamic_cast<WriterGroupTransportDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    WriterGroupTransportDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	WriterGroupTransportDataType* dst = dynamic_cast<WriterGroupTransportDataType*>(&extensionObjectBase);
    	return *const_cast<WriterGroupTransportDataType*>(this) == *dst;
    }
    
    void
    WriterGroupTransportDataType::out(std::ostream& os)
    {
    }

}
