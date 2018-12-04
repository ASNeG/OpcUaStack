/*
    DataTypeClass: UadpWriterGroupMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/UadpWriterGroupMessageDataType.h"

namespace OpcUaStackCore
{
    
    UadpWriterGroupMessageDataType::UadpWriterGroupMessageDataType(void)
    : WriterGroupMessageDataType()
    , groupVersion_()
    , dataSetOrdering_()
    , networkMessageContentMask_()
    , samplingOffset_()
    , publishingOffset_()
    {
    }
    
    UadpWriterGroupMessageDataType::~UadpWriterGroupMessageDataType(void)
    {
    }
    
    OpcUaUInt32&
    UadpWriterGroupMessageDataType::groupVersion(void)
    {
        return groupVersion_;
    }
    
    DataSetOrderingType&
    UadpWriterGroupMessageDataType::dataSetOrdering(void)
    {
        return dataSetOrdering_;
    }
    
    OpcUaUadpNetworkMessageContentMask&
    UadpWriterGroupMessageDataType::networkMessageContentMask(void)
    {
        return networkMessageContentMask_;
    }
    
    OpcUaDuration&
    UadpWriterGroupMessageDataType::samplingOffset(void)
    {
        return samplingOffset_;
    }
    
    OpcUaDurationArray&
    UadpWriterGroupMessageDataType::publishingOffset(void)
    {
        return publishingOffset_;
    }
    
    bool
    UadpWriterGroupMessageDataType::operator==(const UadpWriterGroupMessageDataType& value)
    {
        UadpWriterGroupMessageDataType* dst = const_cast<UadpWriterGroupMessageDataType*>(&value);
        if (groupVersion_ != dst->groupVersion()) return false;
        if (dataSetOrdering_ != dst->dataSetOrdering()) return false;
        if (networkMessageContentMask_ != dst->networkMessageContentMask()) return false;
        if (samplingOffset_ != dst->samplingOffset()) return false;
        if (publishingOffset_ != dst->publishingOffset()) return false;
        return true;
    }
    
    bool
    UadpWriterGroupMessageDataType::operator!=(const UadpWriterGroupMessageDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    UadpWriterGroupMessageDataType::copyTo(UadpWriterGroupMessageDataType& value)
    {
        value.groupVersion_ = groupVersion_;
        dataSetOrdering_.copyTo(value.dataSetOrdering());
        value.networkMessageContentMask_ = networkMessageContentMask_;
        value.samplingOffset_ = samplingOffset_;
        publishingOffset_.copyTo(value.publishingOffset());
    }
    
    UadpWriterGroupMessageDataType&
    UadpWriterGroupMessageDataType::operator=(const UadpWriterGroupMessageDataType& value)
    {
        const_cast<UadpWriterGroupMessageDataType*>(&value)->copyTo(*this);
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
    UadpWriterGroupMessageDataType::factory(void)
    {
    	return constructSPtr<UadpWriterGroupMessageDataType>();
    }
    
    std::string
    UadpWriterGroupMessageDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    UadpWriterGroupMessageDataType::typeName(void)
    {
    	return "UadpWriterGroupMessageDataType";
    }
    
    OpcUaNodeId
    UadpWriterGroupMessageDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15645,0);
    }
    
    OpcUaNodeId
    UadpWriterGroupMessageDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15715, 0);
    }
    
    OpcUaNodeId
    UadpWriterGroupMessageDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16014, 0);
    }
    
    OpcUaNodeId
    UadpWriterGroupMessageDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16323, 0);
    }
    
    void
    UadpWriterGroupMessageDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        WriterGroupMessageDataType::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,groupVersion_);
        dataSetOrdering_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,networkMessageContentMask_);
        OpcUaNumber::opcUaBinaryEncode(os,samplingOffset_);
        publishingOffset_.opcUaBinaryEncode(os);
    }
    
    void
    UadpWriterGroupMessageDataType::opcUaBinaryDecode(std::istream& is)
    {
        WriterGroupMessageDataType::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,groupVersion_);
        dataSetOrdering_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,networkMessageContentMask_);
        OpcUaNumber::opcUaBinaryDecode(is,samplingOffset_);
        publishingOffset_.opcUaBinaryDecode(is);
    }
    
    bool
    UadpWriterGroupMessageDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    UadpWriterGroupMessageDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    UadpWriterGroupMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UadpWriterGroupMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, groupVersion_)) return false;
        pt.push_back(std::make_pair("GroupVersion", elementTree));
    
        elementTree.clear();
        if (!dataSetOrdering_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("DataSetOrdering", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, networkMessageContentMask_)) return false;
        pt.push_back(std::make_pair("NetworkMessageContentMask", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, samplingOffset_)) return false;
        pt.push_back(std::make_pair("SamplingOffset", elementTree));
    
        elementTree.clear();
        if (!publishingOffset_.xmlEncode(elementTree, "Duration", xmlns)) return false;
        pt.push_back(std::make_pair("PublishingOffset", elementTree));
    
        return true;
    }
    
    bool
    UadpWriterGroupMessageDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpWriterGroupMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UadpWriterGroupMessageDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("GroupVersion");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpWriterGroupMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, groupVersion_)) {
            Log(Error, "UadpWriterGroupMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetOrdering");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpWriterGroupMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetOrdering_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UadpWriterGroupMessageDataType decode xml error - decode failed")
                .parameter("Element", "DataSetOrdering");
            return false;
        }
    
        elementName = xmlns.addPrefix("NetworkMessageContentMask");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpWriterGroupMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, networkMessageContentMask_)) {
            Log(Error, "UadpWriterGroupMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("SamplingOffset");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpWriterGroupMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, samplingOffset_)) {
            Log(Error, "UadpWriterGroupMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("PublishingOffset");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpWriterGroupMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!publishingOffset_.xmlDecode(*tree, "Duration", xmlns)) {
            Log(Error, "UadpWriterGroupMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    UadpWriterGroupMessageDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    UadpWriterGroupMessageDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    UadpWriterGroupMessageDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    UadpWriterGroupMessageDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    UadpWriterGroupMessageDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	UadpWriterGroupMessageDataType* dst = dynamic_cast<UadpWriterGroupMessageDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    UadpWriterGroupMessageDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	UadpWriterGroupMessageDataType* dst = dynamic_cast<UadpWriterGroupMessageDataType*>(&extensionObjectBase);
    	return *const_cast<UadpWriterGroupMessageDataType*>(this) == *dst;
    }
    
    void
    UadpWriterGroupMessageDataType::out(std::ostream& os)
    {
        os << "GroupVersion=" << groupVersion_;
        os << ", DataSetOrdering="; dataSetOrdering_.out(os);
        os << ", NetworkMessageContentMask=" << networkMessageContentMask_;
        os << ", SamplingOffset=" << samplingOffset_;
        os << ", PublishingOffset="; publishingOffset_.out(os);
    }

}
