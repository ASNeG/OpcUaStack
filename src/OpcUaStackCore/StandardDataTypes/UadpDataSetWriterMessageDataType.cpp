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
        OpcUaNumber::opcUaBinaryEncode(os,dataSetMessageContentMask_);
        OpcUaNumber::opcUaBinaryEncode(os,configuredSize_);
        OpcUaNumber::opcUaBinaryEncode(os,networkMessageNumber_);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetOffset_);
    }
    
    void
    UadpDataSetWriterMessageDataType::opcUaBinaryDecode(std::istream& is)
    {
        OpcUaNumber::opcUaBinaryDecode(is,dataSetMessageContentMask_);
        OpcUaNumber::opcUaBinaryDecode(is,configuredSize_);
        OpcUaNumber::opcUaBinaryDecode(is,networkMessageNumber_);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetOffset_);
    }
    
    bool
    UadpDataSetWriterMessageDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    UadpDataSetWriterMessageDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    UadpDataSetWriterMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UadpDataSetWriterMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetMessageContentMask_)) return false;
        pt.push_back(std::make_pair("DataSetMessageContentMask", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, configuredSize_)) return false;
        pt.push_back(std::make_pair("ConfiguredSize", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, networkMessageNumber_)) return false;
        pt.push_back(std::make_pair("NetworkMessageNumber", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetOffset_)) return false;
        pt.push_back(std::make_pair("DataSetOffset", elementTree));
    
        return true;
    }
    
    bool
    UadpDataSetWriterMessageDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UadpDataSetWriterMessageDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("DataSetMessageContentMask");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, dataSetMessageContentMask_)) return false;
    
        tree = pt.get_child_optional("ConfiguredSize");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, configuredSize_)) return false;
    
        tree = pt.get_child_optional("NetworkMessageNumber");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, networkMessageNumber_)) return false;
    
        tree = pt.get_child_optional("DataSetOffset");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, dataSetOffset_)) return false;
    
        return true;
    }
    
    bool
    UadpDataSetWriterMessageDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    UadpDataSetWriterMessageDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    UadpDataSetWriterMessageDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    UadpDataSetWriterMessageDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
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
