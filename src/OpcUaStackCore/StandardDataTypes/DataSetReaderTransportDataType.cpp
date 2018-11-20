/*
    DataTypeClass: DataSetReaderTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataSetReaderTransportDataType.h"

namespace OpcUaStackCore
{
    
    DataSetReaderTransportDataType::DataSetReaderTransportDataType(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    DataSetReaderTransportDataType::~DataSetReaderTransportDataType(void)
    {
    }
    
    bool
    DataSetReaderTransportDataType::operator==(const DataSetReaderTransportDataType& value)
    {
        DataSetReaderTransportDataType* dst = const_cast<DataSetReaderTransportDataType*>(&value);
        return true;
    }
    
    bool
    DataSetReaderTransportDataType::operator!=(const DataSetReaderTransportDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataSetReaderTransportDataType::copyTo(DataSetReaderTransportDataType& value)
    {
    }
    
    DataSetReaderTransportDataType&
    DataSetReaderTransportDataType::operator=(const DataSetReaderTransportDataType& value)
    {
        const_cast<DataSetReaderTransportDataType*>(&value)->copyTo(*this);
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
    DataSetReaderTransportDataType::factory(void)
    {
    	return constructSPtr<DataSetReaderTransportDataType>();
    }
    
    std::string
    DataSetReaderTransportDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataSetReaderTransportDataType::typeName(void)
    {
    	return "DataSetReaderTransportDataType";
    }
    
    OpcUaNodeId
    DataSetReaderTransportDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15628,0);
    }
    
    OpcUaNodeId
    DataSetReaderTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15705, 0);
    }
    
    OpcUaNodeId
    DataSetReaderTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16008, 0);
    }
    
    OpcUaNodeId
    DataSetReaderTransportDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16287, 0);
    }
    
    void
    DataSetReaderTransportDataType::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    DataSetReaderTransportDataType::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    DataSetReaderTransportDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    DataSetReaderTransportDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    DataSetReaderTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataSetReaderTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    DataSetReaderTransportDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataSetReaderTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    DataSetReaderTransportDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    DataSetReaderTransportDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    DataSetReaderTransportDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    DataSetReaderTransportDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    DataSetReaderTransportDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataSetReaderTransportDataType* dst = dynamic_cast<DataSetReaderTransportDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataSetReaderTransportDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataSetReaderTransportDataType* dst = dynamic_cast<DataSetReaderTransportDataType*>(&extensionObjectBase);
    	return *const_cast<DataSetReaderTransportDataType*>(this) == *dst;
    }
    
    void
    DataSetReaderTransportDataType::out(std::ostream& os)
    {
    }

}
