/*
    DataTypeClass: DataSetWriterMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataSetWriterMessageDataType.h"

namespace OpcUaStackCore
{
    
    DataSetWriterMessageDataType::DataSetWriterMessageDataType(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    DataSetWriterMessageDataType::DataSetWriterMessageDataType(const DataSetWriterMessageDataType& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<DataSetWriterMessageDataType*>(&value)->copyTo(*this);
    }
    
    DataSetWriterMessageDataType::~DataSetWriterMessageDataType(void)
    {
    }
    
    bool
    DataSetWriterMessageDataType::operator==(const DataSetWriterMessageDataType& value)
    {
        DataSetWriterMessageDataType* dst = const_cast<DataSetWriterMessageDataType*>(&value);
        return true;
    }
    
    bool
    DataSetWriterMessageDataType::operator!=(const DataSetWriterMessageDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataSetWriterMessageDataType::copyTo(DataSetWriterMessageDataType& value)
    {
    }
    
    DataSetWriterMessageDataType&
    DataSetWriterMessageDataType::operator=(const DataSetWriterMessageDataType& value)
    {
        const_cast<DataSetWriterMessageDataType*>(&value)->copyTo(*this);
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
    DataSetWriterMessageDataType::factory(void)
    {
    	return constructSPtr<DataSetWriterMessageDataType>();
    }
    
    std::string
    DataSetWriterMessageDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataSetWriterMessageDataType::typeName(void)
    {
    	return "DataSetWriterMessageDataType";
    }
    
    OpcUaNodeId
    DataSetWriterMessageDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15605,0);
    }
    
    OpcUaNodeId
    DataSetWriterMessageDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15688, 0);
    }
    
    OpcUaNodeId
    DataSetWriterMessageDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15987, 0);
    }
    
    OpcUaNodeId
    DataSetWriterMessageDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16158, 0);
    }
    
    void
    DataSetWriterMessageDataType::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    DataSetWriterMessageDataType::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    DataSetWriterMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetWriterMessageDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataSetWriterMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    DataSetWriterMessageDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataSetWriterMessageDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    DataSetWriterMessageDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    DataSetWriterMessageDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    DataSetWriterMessageDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataSetWriterMessageDataType* dst = dynamic_cast<DataSetWriterMessageDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataSetWriterMessageDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataSetWriterMessageDataType* dst = dynamic_cast<DataSetWriterMessageDataType*>(&extensionObjectBase);
    	return *const_cast<DataSetWriterMessageDataType*>(this) == *dst;
    }
    
    void
    DataSetWriterMessageDataType::out(std::ostream& os)
    {
    }

}
