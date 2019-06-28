/*
    DataTypeClass: UadpDataSetReaderMessageDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/UadpDataSetReaderMessageDataType.h"

namespace OpcUaStackCore
{
    
    UadpDataSetReaderMessageDataType::UadpDataSetReaderMessageDataType(void)
    : DataSetReaderMessageDataType()
    , groupVersion_()
    , networkMessageNumber_()
    , dataSetOffset_()
    , dataSetClassId_()
    , networkMessageContentMask_()
    , dataSetMessageContentMask_()
    , publishingInterval_()
    , receiveOffset_()
    , processingOffset_()
    {
    }
    
    UadpDataSetReaderMessageDataType::UadpDataSetReaderMessageDataType(const UadpDataSetReaderMessageDataType& value)
    : DataSetReaderMessageDataType()
    , groupVersion_()
    , networkMessageNumber_()
    , dataSetOffset_()
    , dataSetClassId_()
    , networkMessageContentMask_()
    , dataSetMessageContentMask_()
    , publishingInterval_()
    , receiveOffset_()
    , processingOffset_()
    {
        const_cast<UadpDataSetReaderMessageDataType*>(&value)->copyTo(*this);
    }
    
    UadpDataSetReaderMessageDataType::~UadpDataSetReaderMessageDataType(void)
    {
    }
    
    OpcUaVersionTime&
    UadpDataSetReaderMessageDataType::groupVersion(void)
    {
        return groupVersion_;
    }
    
    OpcUaUInt16&
    UadpDataSetReaderMessageDataType::networkMessageNumber(void)
    {
        return networkMessageNumber_;
    }
    
    OpcUaUInt16&
    UadpDataSetReaderMessageDataType::dataSetOffset(void)
    {
        return dataSetOffset_;
    }
    
    OpcUaGuid&
    UadpDataSetReaderMessageDataType::dataSetClassId(void)
    {
        return dataSetClassId_;
    }
    
    OpcUaUadpNetworkMessageContentMask&
    UadpDataSetReaderMessageDataType::networkMessageContentMask(void)
    {
        return networkMessageContentMask_;
    }
    
    OpcUaUadpDataSetMessageContentMask&
    UadpDataSetReaderMessageDataType::dataSetMessageContentMask(void)
    {
        return dataSetMessageContentMask_;
    }
    
    OpcUaDuration&
    UadpDataSetReaderMessageDataType::publishingInterval(void)
    {
        return publishingInterval_;
    }
    
    OpcUaDuration&
    UadpDataSetReaderMessageDataType::receiveOffset(void)
    {
        return receiveOffset_;
    }
    
    OpcUaDuration&
    UadpDataSetReaderMessageDataType::processingOffset(void)
    {
        return processingOffset_;
    }
    
    bool
    UadpDataSetReaderMessageDataType::operator==(const UadpDataSetReaderMessageDataType& value)
    {
        UadpDataSetReaderMessageDataType* dst = const_cast<UadpDataSetReaderMessageDataType*>(&value);
        if (groupVersion_ != dst->groupVersion()) return false;
        if (networkMessageNumber_ != dst->networkMessageNumber()) return false;
        if (dataSetOffset_ != dst->dataSetOffset()) return false;
        if (dataSetClassId_ != dst->dataSetClassId()) return false;
        if (networkMessageContentMask_ != dst->networkMessageContentMask()) return false;
        if (dataSetMessageContentMask_ != dst->dataSetMessageContentMask()) return false;
        if (publishingInterval_ != dst->publishingInterval()) return false;
        if (receiveOffset_ != dst->receiveOffset()) return false;
        if (processingOffset_ != dst->processingOffset()) return false;
        return true;
    }
    
    bool
    UadpDataSetReaderMessageDataType::operator!=(const UadpDataSetReaderMessageDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    UadpDataSetReaderMessageDataType::copyTo(UadpDataSetReaderMessageDataType& value)
    {
        value.groupVersion_ = groupVersion_;
        value.networkMessageNumber_ = networkMessageNumber_;
        value.dataSetOffset_ = dataSetOffset_;
        dataSetClassId_.copyTo(value.dataSetClassId());
        value.networkMessageContentMask_ = networkMessageContentMask_;
        value.dataSetMessageContentMask_ = dataSetMessageContentMask_;
        value.publishingInterval_ = publishingInterval_;
        value.receiveOffset_ = receiveOffset_;
        value.processingOffset_ = processingOffset_;
    }
    
    UadpDataSetReaderMessageDataType&
    UadpDataSetReaderMessageDataType::operator=(const UadpDataSetReaderMessageDataType& value)
    {
        const_cast<UadpDataSetReaderMessageDataType*>(&value)->copyTo(*this);
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
    UadpDataSetReaderMessageDataType::factory(void)
    {
    	return constructSPtr<UadpDataSetReaderMessageDataType>();
    }
    
    std::string
    UadpDataSetReaderMessageDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    UadpDataSetReaderMessageDataType::typeName(void)
    {
    	return "UadpDataSetReaderMessageDataType";
    }
    
    OpcUaNodeId
    UadpDataSetReaderMessageDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15653,0);
    }
    
    OpcUaNodeId
    UadpDataSetReaderMessageDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15718, 0);
    }
    
    OpcUaNodeId
    UadpDataSetReaderMessageDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16016, 0);
    }
    
    OpcUaNodeId
    UadpDataSetReaderMessageDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16392, 0);
    }
    
    void
    UadpDataSetReaderMessageDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        DataSetReaderMessageDataType::opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,groupVersion_);
        OpcUaNumber::opcUaBinaryEncode(os,networkMessageNumber_);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetOffset_);
        dataSetClassId_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,networkMessageContentMask_);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetMessageContentMask_);
        OpcUaNumber::opcUaBinaryEncode(os,publishingInterval_);
        OpcUaNumber::opcUaBinaryEncode(os,receiveOffset_);
        OpcUaNumber::opcUaBinaryEncode(os,processingOffset_);
    }
    
    void
    UadpDataSetReaderMessageDataType::opcUaBinaryDecode(std::istream& is)
    {
        DataSetReaderMessageDataType::opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,groupVersion_);
        OpcUaNumber::opcUaBinaryDecode(is,networkMessageNumber_);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetOffset_);
        dataSetClassId_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,networkMessageContentMask_);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetMessageContentMask_);
        OpcUaNumber::opcUaBinaryDecode(is,publishingInterval_);
        OpcUaNumber::opcUaBinaryDecode(is,receiveOffset_);
        OpcUaNumber::opcUaBinaryDecode(is,processingOffset_);
    }
    
    bool
    UadpDataSetReaderMessageDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "UadpDataSetReaderMessageDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    UadpDataSetReaderMessageDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, groupVersion_))
        {
            Log(Error, "UadpDataSetReaderMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("GroupVersion", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, networkMessageNumber_))
        {
            Log(Error, "UadpDataSetReaderMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NetworkMessageNumber", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetOffset_))
        {
            Log(Error, "UadpDataSetReaderMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetOffset", elementTree));
    
        elementTree.clear();
        if (!dataSetClassId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "UadpDataSetReaderMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetClassId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, networkMessageContentMask_))
        {
            Log(Error, "UadpDataSetReaderMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("NetworkMessageContentMask", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetMessageContentMask_))
        {
            Log(Error, "UadpDataSetReaderMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetMessageContentMask", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, publishingInterval_))
        {
            Log(Error, "UadpDataSetReaderMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublishingInterval", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, receiveOffset_))
        {
            Log(Error, "UadpDataSetReaderMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ReceiveOffset", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, processingOffset_))
        {
            Log(Error, "UadpDataSetReaderMessageDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ProcessingOffset", elementTree));
    
        return true;
    }
    
    bool
    UadpDataSetReaderMessageDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    UadpDataSetReaderMessageDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("GroupVersion");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, groupVersion_)) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("NetworkMessageNumber");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, networkMessageNumber_)) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetOffset");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, dataSetOffset_)) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetClassId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetClassId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - decode failed")
                .parameter("Element", "DataSetClassId");
            return false;
        }
    
        elementName = xmlns.addPrefix("NetworkMessageContentMask");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, networkMessageContentMask_)) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetMessageContentMask");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, dataSetMessageContentMask_)) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("PublishingInterval");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, publishingInterval_)) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ReceiveOffset");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, receiveOffset_)) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("ProcessingOffset");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, processingOffset_)) {
            Log(Error, "UadpDataSetReaderMessageDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    UadpDataSetReaderMessageDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonNumberEncode(pt, groupVersion_, "GroupVersion");
        rc = rc & jsonNumberEncode(pt, networkMessageNumber_, "NetworkMessageNumber");
        rc = rc & jsonNumberEncode(pt, dataSetOffset_, "DataSetOffset");
        rc = rc & jsonObjectEncode(pt, dataSetClassId_, "DataSetClassId", true);
        rc = rc & jsonNumberEncode(pt, networkMessageContentMask_, "NetworkMessageContentMask");
        rc = rc & jsonNumberEncode(pt, dataSetMessageContentMask_, "DataSetMessageContentMask");
        rc = rc & jsonNumberEncode(pt, publishingInterval_, "PublishingInterval");
        rc = rc & jsonNumberEncode(pt, receiveOffset_, "ReceiveOffset");
        rc = rc & jsonNumberEncode(pt, processingOffset_, "ProcessingOffset");
    
        return rc;
    }
    
    bool
    UadpDataSetReaderMessageDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonNumberDecode(pt, groupVersion_, "GroupVersion");
        rc = rc & jsonNumberDecode(pt, networkMessageNumber_, "NetworkMessageNumber");
        rc = rc & jsonNumberDecode(pt, dataSetOffset_, "DataSetOffset");
        rc = rc & jsonObjectDecode(pt, dataSetClassId_, "DataSetClassId", true);
        rc = rc & jsonNumberDecode(pt, networkMessageContentMask_, "NetworkMessageContentMask");
        rc = rc & jsonNumberDecode(pt, dataSetMessageContentMask_, "DataSetMessageContentMask");
        rc = rc & jsonNumberDecode(pt, publishingInterval_, "PublishingInterval");
        rc = rc & jsonNumberDecode(pt, receiveOffset_, "ReceiveOffset");
        rc = rc & jsonNumberDecode(pt, processingOffset_, "ProcessingOffset");
    
        return rc;
    }
    
    void
    UadpDataSetReaderMessageDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	UadpDataSetReaderMessageDataType* dst = dynamic_cast<UadpDataSetReaderMessageDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    UadpDataSetReaderMessageDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	UadpDataSetReaderMessageDataType* dst = dynamic_cast<UadpDataSetReaderMessageDataType*>(&extensionObjectBase);
    	return *const_cast<UadpDataSetReaderMessageDataType*>(this) == *dst;
    }
    
    void
    UadpDataSetReaderMessageDataType::out(std::ostream& os)
    {
        os << "GroupVersion=" << groupVersion_;
        os << ", NetworkMessageNumber=" << networkMessageNumber_;
        os << ", DataSetOffset=" << dataSetOffset_;
        os << ", DataSetClassId="; dataSetClassId_.out(os);
        os << ", NetworkMessageContentMask=" << networkMessageContentMask_;
        os << ", DataSetMessageContentMask=" << dataSetMessageContentMask_;
        os << ", PublishingInterval=" << publishingInterval_;
        os << ", ReceiveOffset=" << receiveOffset_;
        os << ", ProcessingOffset=" << processingOffset_;
    }

}
