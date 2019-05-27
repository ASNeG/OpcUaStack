/*
    DataTypeClass: DataSetReaderMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataSetReaderMessageDataType.h"

namespace OpcUaStackCore
{
    
    DataSetReaderMessageDataType::DataSetReaderMessageDataType(void)
    : Object()
    , ExtensionObjectBase()
    {
    }
    
    DataSetReaderMessageDataType::DataSetReaderMessageDataType(const DataSetReaderMessageDataType& value)
    : Object()
    , ExtensionObjectBase()
    {
        const_cast<DataSetReaderMessageDataType*>(&value)->copyTo(*this);
    }
    
    DataSetReaderMessageDataType::~DataSetReaderMessageDataType(void)
    {
    }
    
    bool
    DataSetReaderMessageDataType::operator==(const DataSetReaderMessageDataType& value)
    {
        DataSetReaderMessageDataType* dst = const_cast<DataSetReaderMessageDataType*>(&value);
        return true;
    }
    
    bool
    DataSetReaderMessageDataType::operator!=(const DataSetReaderMessageDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataSetReaderMessageDataType::copyTo(DataSetReaderMessageDataType& value)
    {
    }
    
    DataSetReaderMessageDataType&
    DataSetReaderMessageDataType::operator=(const DataSetReaderMessageDataType& value)
    {
        const_cast<DataSetReaderMessageDataType*>(&value)->copyTo(*this);
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
    DataSetReaderMessageDataType::factory(void)
    {
    	return constructSPtr<DataSetReaderMessageDataType>();
    }
    
    std::string
    DataSetReaderMessageDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataSetReaderMessageDataType::typeName(void)
    {
    	return "DataSetReaderMessageDataType";
    }
    
    OpcUaNodeId
    DataSetReaderMessageDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15629,0);
    }
    
    OpcUaNodeId
    DataSetReaderMessageDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15706, 0);
    }
    
    OpcUaNodeId
    DataSetReaderMessageDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16009, 0);
    }
    
    OpcUaNodeId
    DataSetReaderMessageDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16288, 0);
    }
    
    void
    DataSetReaderMessageDataType::opcUaBinaryEncode(std::ostream& os) const
    {
    }
    
    void
    DataSetReaderMessageDataType::opcUaBinaryDecode(std::istream& is)
    {
    }
    
    bool
    DataSetReaderMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetReaderMessageDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataSetReaderMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    DataSetReaderMessageDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataSetReaderMessageDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    bool
    DataSetReaderMessageDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        return true;
    }
    
    bool
    DataSetReaderMessageDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        return true;
    }
    
    void
    DataSetReaderMessageDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataSetReaderMessageDataType* dst = dynamic_cast<DataSetReaderMessageDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataSetReaderMessageDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataSetReaderMessageDataType* dst = dynamic_cast<DataSetReaderMessageDataType*>(&extensionObjectBase);
    	return *const_cast<DataSetReaderMessageDataType*>(this) == *dst;
    }
    
    void
    DataSetReaderMessageDataType::out(std::ostream& os)
    {
    }

}
