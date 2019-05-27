/*
    DataTypeClass: UadpDataSetWriterMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/UadpDataSetWriterMessageDataType.h"

namespace OpcUaStackCore
{
    
    UadpDataSetWriterMessageDataType::UadpDataSetWriterMessageDataType(void)
    : DataSetWriterMessageDataType()
    , dataSetMessageContentMask_()
    , configuredSize_()
    , networkMessageNumber_()
    , dataSetOffset_()
    {
    }
    
    UadpDataSetWriterMessageDataType::UadpDataSetWriterMessageDataType(const UadpDataSetWriterMessageDataType& value)
    : DataSetWriterMessageDataType()
    , dataSetMessageContentMask_()
    , configuredSize_()
    , networkMessageNumber_()
    , dataSetOffset_()
    {
        const_cast<UadpDataSetWriterMessageDataType*>(&value)->copyTo(*this);
    }
    
    UadpDataSetWriterMessageDataType::~UadpDataSetWriterMessageDataType(void)
    {
    }
    
    OpcUaUadpDataSetMessageContentMask&
    UadpDataSetWriterMessageDataType::dataSetMessageContentMask(void)
    {
        return dataSetMessageContentMask_;
    }
    
    OpcUaUInt16&
    UadpDataSetWriterMessageDataType::configuredSize(void)
    {
        return configuredSize_;
    }
    
    OpcUaUInt16&
    UadpDataSetWriterMessageDataType::networkMessageNumber(void)
    {
        return networkMessageNumber_;
    }
    
    OpcUaUInt16&
    UadpDataSetWriterMessageDataType::dataSetOffset(void)
    {
        return dataSetOffset_;
    }
    
    bool
    UadpDataSetWriterMessageDataType::operator==(const UadpDataSetWriterMessageDataType& value)
    {
        UadpDataSetWriterMessageDataType* dst = const_cast<UadpDataSetWriterMessageDataType*>(&value);
        if (dataSetMessageContentMask_ != dst->dataSetMessageContentMask()) return false;
        if (configuredSize_ != dst->configuredSize()) return false;
        if (networkMessageNumber_ != dst->networkMessageNumber()) return false;
        if (dataSetOffset_ != dst->dataSetOffset()) return false;
        return true;
    }
    
    bool
    UadpDataSetWriterMessageDataType::operator!=(const UadpDataSetWriterMessageDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    UadpDataSetWriterMessageDataType::copyTo(UadpDataSetWriterMessageDataType& value)
    {
        value.dataSetMessageContentMask_ = dataSetMessageContentMask_;
        value.configuredSize_ = configuredSize_;
        value.networkMessageNumber_ = networkMessageNumber_;
        value.dataSetOffset_ = dataSetOffset_;
    }
    
    UadpDataSetWriterMessageDataType&
    UadpDataSetWriterMessageDataType::operator=(const UadpDataSetWriterMessageDataType& value)
    {
        const_cast<UadpDataSetWriterMessageDataType*>(&value)->copyTo(*this);
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
    UadpDataSetWriterMessageDataType::factory(void)
    {
    	return constructSPtr<UadpDataSetWriterMessageDataType>();
    }
    
    std::string
    UadpDataSetWriterMessageDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    UadpDataSetWriterMessageDataType::typeName(void)
    {
    	return "UadpDataSetWriterMessageDataType";
    }
    
    OpcUaNodeId
    UadpDataSetWriterMessageDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15652,0);
    }
    
    OpcUaNodeId
    UadpDataSetWriterMessageDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15717, 0);
    }
    
    OpcUaNodeId
    UadpDataSetWriterMessageDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16015, 0);
    }
    
    OpcUaNodeId
    UadpDataSetWriterMessageDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16391, 0);
    }
    
    void
    UadpDataSetWriterMessageDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        DataSetWriterMessageDataType::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetMessageContentMask_);
        OpcUaNumber::opcUaBinaryEncode(os,configuredSize_);
        OpcUaNumber::opcUaBinaryEncode(os,networkMessageNumber_);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetOffset_);
    }
    
    void
    UadpDataSetWriterMessageDataType::opcUaBinaryDecode(std::istream& is)
    {
        DataSetWriterMessageDataType::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetMessageContentMask_);
        OpcUaNumber::opcUaBinaryDecode(is,configuredSize_);
        OpcUaNumber::opcUaBinaryDecode(is,networkMessageNumber_);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetOffset_);
    }
    
    bool
    UadpDataSetWriterMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "UadpDataSetWriterMessageDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UadpDataSetWriterMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetMessageContentMask_))
        {
            Log(Error, "UadpDataSetWriterMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetMessageContentMask", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, configuredSize_))
        {
            Log(Error, "UadpDataSetWriterMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ConfiguredSize", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, networkMessageNumber_))
        {
            Log(Error, "UadpDataSetWriterMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NetworkMessageNumber", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetOffset_))
        {
            Log(Error, "UadpDataSetWriterMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetOffset", elementTree));
    
        return true;
    }
    
    bool
    UadpDataSetWriterMessageDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetWriterMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UadpDataSetWriterMessageDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("DataSetMessageContentMask");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetWriterMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, dataSetMessageContentMask_)) {
            Log(Error, "UadpDataSetWriterMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ConfiguredSize");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetWriterMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, configuredSize_)) {
            Log(Error, "UadpDataSetWriterMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("NetworkMessageNumber");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetWriterMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, networkMessageNumber_)) {
            Log(Error, "UadpDataSetWriterMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetOffset");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetWriterMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, dataSetOffset_)) {
            Log(Error, "UadpDataSetWriterMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    UadpDataSetWriterMessageDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, dataSetMessageContentMask_))
        {
    	     Log(Error, "UadpDataSetWriterMessageDataType json encoder error")
    		     .parameter("Element", "dataSetMessageContentMask_");
           return false;
        }
        pt.push_back(std::make_pair("DataSetMessageContentMask", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, configuredSize_))
        {
    	     Log(Error, "UadpDataSetWriterMessageDataType json encoder error")
    		     .parameter("Element", "configuredSize_");
           return false;
        }
        pt.push_back(std::make_pair("ConfiguredSize", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, networkMessageNumber_))
        {
    	     Log(Error, "UadpDataSetWriterMessageDataType json encoder error")
    		     .parameter("Element", "networkMessageNumber_");
           return false;
        }
        pt.push_back(std::make_pair("NetworkMessageNumber", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, dataSetOffset_))
        {
    	     Log(Error, "UadpDataSetWriterMessageDataType json encoder error")
    		     .parameter("Element", "dataSetOffset_");
           return false;
        }
        pt.push_back(std::make_pair("DataSetOffset", elementTree));
    
        return true;
    }
    
    bool
    UadpDataSetWriterMessageDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "DataSetMessageContentMask";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetWriterMessageDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, dataSetMessageContentMask_)) {
            Log(Error, "UadpDataSetWriterMessageDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "ConfiguredSize";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetWriterMessageDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, configuredSize_)) {
            Log(Error, "UadpDataSetWriterMessageDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "NetworkMessageNumber";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetWriterMessageDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, networkMessageNumber_)) {
            Log(Error, "UadpDataSetWriterMessageDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DataSetOffset";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetWriterMessageDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, dataSetOffset_)) {
            Log(Error, "UadpDataSetWriterMessageDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    UadpDataSetWriterMessageDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	UadpDataSetWriterMessageDataType* dst = dynamic_cast<UadpDataSetWriterMessageDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    UadpDataSetWriterMessageDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	UadpDataSetWriterMessageDataType* dst = dynamic_cast<UadpDataSetWriterMessageDataType*>(&extensionObjectBase);
    	return *const_cast<UadpDataSetWriterMessageDataType*>(this) == *dst;
    }
    
    void
    UadpDataSetWriterMessageDataType::out(std::ostream& os)
    {
        os << "DataSetMessageContentMask=" << dataSetMessageContentMask_;
        os << ", ConfiguredSize=" << configuredSize_;
        os << ", NetworkMessageNumber=" << networkMessageNumber_;
        os << ", DataSetOffset=" << dataSetOffset_;
    }

}
