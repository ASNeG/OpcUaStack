/*
    DataTypeClass: DataSetWriterTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataSetWriterTransportDataType.h"

namespace OpcUaStackCore
{
    
    DataSetWriterTransportDataType::DataSetWriterTransportDataType(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    DataSetWriterTransportDataType::DataSetWriterTransportDataType(const DataSetWriterTransportDataType& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<DataSetWriterTransportDataType*>(&value)->copyTo(*this);
    }
    
    DataSetWriterTransportDataType::~DataSetWriterTransportDataType(void)
    {
    }
    
    bool
    DataSetWriterTransportDataType::operator==(const DataSetWriterTransportDataType& value)
    {
        DataSetWriterTransportDataType* dst = const_cast<DataSetWriterTransportDataType*>(&value);
        return true;
    }
    
    bool
    DataSetWriterTransportDataType::operator!=(const DataSetWriterTransportDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataSetWriterTransportDataType::copyTo(DataSetWriterTransportDataType& value)
    {
    }
    
    DataSetWriterTransportDataType&
    DataSetWriterTransportDataType::operator=(const DataSetWriterTransportDataType& value)
    {
        const_cast<DataSetWriterTransportDataType*>(&value)->copyTo(*this);
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
    DataSetWriterTransportDataType::factory(void)
    {
    	return constructSPtr<DataSetWriterTransportDataType>();
    }
    
    std::string
    DataSetWriterTransportDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataSetWriterTransportDataType::typeName(void)
    {
    	return "DataSetWriterTransportDataType";
    }
    
    OpcUaNodeId
    DataSetWriterTransportDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15598,0);
    }
    
    OpcUaNodeId
    DataSetWriterTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15683, 0);
    }
    
    OpcUaNodeId
    DataSetWriterTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15956, 0);
    }
    
    OpcUaNodeId
    DataSetWriterTransportDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16157, 0);
    }
    
    void
    DataSetWriterTransportDataType::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    DataSetWriterTransportDataType::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    DataSetWriterTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetWriterTransportDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataSetWriterTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    DataSetWriterTransportDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataSetWriterTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    DataSetWriterTransportDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    DataSetWriterTransportDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    DataSetWriterTransportDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataSetWriterTransportDataType* dst = dynamic_cast<DataSetWriterTransportDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataSetWriterTransportDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataSetWriterTransportDataType* dst = dynamic_cast<DataSetWriterTransportDataType*>(&extensionObjectBase);
    	return *const_cast<DataSetWriterTransportDataType*>(this) == *dst;
    }
    
    void
    DataSetWriterTransportDataType::out(std::ostream& os)
    {
    }

}
