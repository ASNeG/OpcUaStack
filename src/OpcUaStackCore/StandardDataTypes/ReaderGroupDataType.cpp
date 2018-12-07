/*
    DataTypeClass: ReaderGroupDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ReaderGroupDataType.h"

namespace OpcUaStackCore
{
    
    ReaderGroupDataType::ReaderGroupDataType(void)
    : PubSubGroupDataType()
    , transportSettings_()
    , messageSettings_()
    , dataSetReaders_()
    {
    }
    
    ReaderGroupDataType::~ReaderGroupDataType(void)
    {
    }
    
    OpcUaExtensibleParameter&
    ReaderGroupDataType::transportSettings(void)
    {
        return transportSettings_;
    }
    
    OpcUaExtensibleParameter&
    ReaderGroupDataType::messageSettings(void)
    {
        return messageSettings_;
    }
    
    DataSetReaderDataTypeArray&
    ReaderGroupDataType::dataSetReaders(void)
    {
        return dataSetReaders_;
    }
    
    bool
    ReaderGroupDataType::operator==(const ReaderGroupDataType& value)
    {
        ReaderGroupDataType* dst = const_cast<ReaderGroupDataType*>(&value);
        if (transportSettings_ != dst->transportSettings()) return false;
        if (messageSettings_ != dst->messageSettings()) return false;
        if (dataSetReaders_ != dst->dataSetReaders()) return false;
        return true;
    }
    
    bool
    ReaderGroupDataType::operator!=(const ReaderGroupDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    ReaderGroupDataType::copyTo(ReaderGroupDataType& value)
    {
        transportSettings_.copyTo(value.transportSettings());
        messageSettings_.copyTo(value.messageSettings());
        dataSetReaders_.copyTo(value.dataSetReaders());
    }
    
    ReaderGroupDataType&
    ReaderGroupDataType::operator=(const ReaderGroupDataType& value)
    {
        const_cast<ReaderGroupDataType*>(&value)->copyTo(*this);
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
    ReaderGroupDataType::factory(void)
    {
    	return constructSPtr<ReaderGroupDataType>();
    }
    
    std::string
    ReaderGroupDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ReaderGroupDataType::typeName(void)
    {
    	return "ReaderGroupDataType";
    }
    
    OpcUaNodeId
    ReaderGroupDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15520,0);
    }
    
    OpcUaNodeId
    ReaderGroupDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21153, 0);
    }
    
    OpcUaNodeId
    ReaderGroupDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21177, 0);
    }
    
    OpcUaNodeId
    ReaderGroupDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)21201, 0);
    }
    
    void
    ReaderGroupDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        PubSubGroupDataType::opcUaBinaryEncode(os);
        transportSettings_.opcUaBinaryEncode(os);
        messageSettings_.opcUaBinaryEncode(os);
        dataSetReaders_.opcUaBinaryEncode(os);
    }
    
    void
    ReaderGroupDataType::opcUaBinaryDecode(std::istream& is)
    {
        PubSubGroupDataType::opcUaBinaryDecode(is);
        transportSettings_.opcUaBinaryDecode(is);
        messageSettings_.opcUaBinaryDecode(is);
        dataSetReaders_.opcUaBinaryDecode(is);
    }
    
    bool
    ReaderGroupDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    ReaderGroupDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    ReaderGroupDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ReaderGroupDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!transportSettings_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TransportSettings", elementTree));
    
        elementTree.clear();
        if (!messageSettings_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("MessageSettings", elementTree));
    
        elementTree.clear();
        if (!dataSetReaders_.xmlEncode(elementTree, "DataSetReaderDataType", xmlns)) return false;
        pt.push_back(std::make_pair("DataSetReaders", elementTree));
    
        return true;
    }
    
    bool
    ReaderGroupDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReaderGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ReaderGroupDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("TransportSettings");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReaderGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportSettings_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ReaderGroupDataType decode xml error - decode failed")
                .parameter("Element", "TransportSettings");
            return false;
        }
    
        elementName = xmlns.addPrefix("MessageSettings");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReaderGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!messageSettings_.xmlDecode(*tree, xmlns)) {
            Log(Error, "ReaderGroupDataType decode xml error - decode failed")
                .parameter("Element", "MessageSettings");
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetReaders");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ReaderGroupDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetReaders_.xmlDecode(*tree, "DataSetReaderDataType", xmlns)) {
            Log(Error, "ReaderGroupDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ReaderGroupDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    ReaderGroupDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    ReaderGroupDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    ReaderGroupDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    ReaderGroupDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ReaderGroupDataType* dst = dynamic_cast<ReaderGroupDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ReaderGroupDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ReaderGroupDataType* dst = dynamic_cast<ReaderGroupDataType*>(&extensionObjectBase);
    	return *const_cast<ReaderGroupDataType*>(this) == *dst;
    }
    
    void
    ReaderGroupDataType::out(std::ostream& os)
    {
        os << "TransportSettings="; transportSettings_.out(os);
        os << ", MessageSettings="; messageSettings_.out(os);
        os << ", DataSetReaders="; dataSetReaders_.out(os);
    }

}