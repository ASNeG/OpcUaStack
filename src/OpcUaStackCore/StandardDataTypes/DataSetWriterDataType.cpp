/*
    DataTypeClass: DataSetWriterDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/DataSetWriterDataType.h"

namespace OpcUaStackCore
{
    
    DataSetWriterDataType::DataSetWriterDataType(void)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , enabled_()
    , dataSetWriterId_()
    , dataSetFieldContentMask_()
    , keyFrameCount_()
    , dataSetName_()
    , dataSetWriterProperties_()
    , transportSettings_()
    , messageSettings_()
    {
    }
    
    DataSetWriterDataType::DataSetWriterDataType(const DataSetWriterDataType& value)
    : Object()
    , ExtensionObjectBase()
    , name_()
    , enabled_()
    , dataSetWriterId_()
    , dataSetFieldContentMask_()
    , keyFrameCount_()
    , dataSetName_()
    , dataSetWriterProperties_()
    , transportSettings_()
    , messageSettings_()
    {
        const_cast<DataSetWriterDataType*>(&value)->copyTo(*this);
    }
    
    DataSetWriterDataType::~DataSetWriterDataType(void)
    {
    }
    
    OpcUaString&
    DataSetWriterDataType::name(void)
    {
        return name_;
    }
    
    OpcUaBoolean&
    DataSetWriterDataType::enabled(void)
    {
        return enabled_;
    }
    
    OpcUaUInt16&
    DataSetWriterDataType::dataSetWriterId(void)
    {
        return dataSetWriterId_;
    }
    
    OpcUaDataSetFieldContentMask&
    DataSetWriterDataType::dataSetFieldContentMask(void)
    {
        return dataSetFieldContentMask_;
    }
    
    OpcUaUInt32&
    DataSetWriterDataType::keyFrameCount(void)
    {
        return keyFrameCount_;
    }
    
    OpcUaString&
    DataSetWriterDataType::dataSetName(void)
    {
        return dataSetName_;
    }
    
    KeyValuePairArray&
    DataSetWriterDataType::dataSetWriterProperties(void)
    {
        return dataSetWriterProperties_;
    }
    
    OpcUaExtensibleParameter&
    DataSetWriterDataType::transportSettings(void)
    {
        return transportSettings_;
    }
    
    OpcUaExtensibleParameter&
    DataSetWriterDataType::messageSettings(void)
    {
        return messageSettings_;
    }
    
    bool
    DataSetWriterDataType::operator==(const DataSetWriterDataType& value)
    {
        DataSetWriterDataType* dst = const_cast<DataSetWriterDataType*>(&value);
        if (name_ != dst->name()) return false;
        if (enabled_ != dst->enabled()) return false;
        if (dataSetWriterId_ != dst->dataSetWriterId()) return false;
        if (dataSetFieldContentMask_ != dst->dataSetFieldContentMask()) return false;
        if (keyFrameCount_ != dst->keyFrameCount()) return false;
        if (dataSetName_ != dst->dataSetName()) return false;
        if (dataSetWriterProperties_ != dst->dataSetWriterProperties()) return false;
        if (transportSettings_ != dst->transportSettings()) return false;
        if (messageSettings_ != dst->messageSettings()) return false;
        return true;
    }
    
    bool
    DataSetWriterDataType::operator!=(const DataSetWriterDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    DataSetWriterDataType::copyTo(DataSetWriterDataType& value)
    {
        name_.copyTo(value.name());
        value.enabled_ = enabled_;
        value.dataSetWriterId_ = dataSetWriterId_;
        value.dataSetFieldContentMask_ = dataSetFieldContentMask_;
        value.keyFrameCount_ = keyFrameCount_;
        dataSetName_.copyTo(value.dataSetName());
        dataSetWriterProperties_.copyTo(value.dataSetWriterProperties());
        transportSettings_.copyTo(value.transportSettings());
        messageSettings_.copyTo(value.messageSettings());
    }
    
    DataSetWriterDataType&
    DataSetWriterDataType::operator=(const DataSetWriterDataType& value)
    {
        const_cast<DataSetWriterDataType*>(&value)->copyTo(*this);
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
    DataSetWriterDataType::factory(void)
    {
    	return constructSPtr<DataSetWriterDataType>();
    }
    
    std::string
    DataSetWriterDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    DataSetWriterDataType::typeName(void)
    {
    	return "DataSetWriterDataType";
    }
    
    OpcUaNodeId
    DataSetWriterDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15597,0);
    }
    
    OpcUaNodeId
    DataSetWriterDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15682, 0);
    }
    
    OpcUaNodeId
    DataSetWriterDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15955, 0);
    }
    
    OpcUaNodeId
    DataSetWriterDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16156, 0);
    }
    
    void
    DataSetWriterDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        name_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,enabled_);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetWriterId_);
        OpcUaNumber::opcUaBinaryEncode(os,dataSetFieldContentMask_);
        OpcUaNumber::opcUaBinaryEncode(os,keyFrameCount_);
        dataSetName_.opcUaBinaryEncode(os);
        dataSetWriterProperties_.opcUaBinaryEncode(os);
        transportSettings_.opcUaBinaryEncode(os);
        messageSettings_.opcUaBinaryEncode(os);
    }
    
    void
    DataSetWriterDataType::opcUaBinaryDecode(std::istream& is)
    {
        name_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,enabled_);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetWriterId_);
        OpcUaNumber::opcUaBinaryDecode(is,dataSetFieldContentMask_);
        OpcUaNumber::opcUaBinaryDecode(is,keyFrameCount_);
        dataSetName_.opcUaBinaryDecode(is);
        dataSetWriterProperties_.opcUaBinaryDecode(is);
        transportSettings_.opcUaBinaryDecode(is);
        messageSettings_.opcUaBinaryDecode(is);
    }
    
    bool
    DataSetWriterDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetWriterDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    DataSetWriterDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetWriterDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, enabled_))
        {
            Log(Error, "DataSetWriterDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Enabled", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetWriterId_))
        {
            Log(Error, "DataSetWriterDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetWriterId", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, dataSetFieldContentMask_))
        {
            Log(Error, "DataSetWriterDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetFieldContentMask", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, keyFrameCount_))
        {
            Log(Error, "DataSetWriterDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("KeyFrameCount", elementTree));
    
        elementTree.clear();
        if (!dataSetName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetWriterDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetName", elementTree));
    
        elementTree.clear();
        if (!dataSetWriterProperties_.xmlEncode(elementTree, "KeyValuePair", xmlns)) {
            Log(Error, "DataSetWriterDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("DataSetWriterProperties", elementTree));
    
        elementTree.clear();
        if (!transportSettings_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetWriterDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TransportSettings", elementTree));
    
        elementTree.clear();
        if (!messageSettings_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "DataSetWriterDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MessageSettings", elementTree));
    
        return true;
    }
    
    bool
    DataSetWriterDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    DataSetWriterDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("Name");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataSetWriterDataType decode xml error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        elementName = xmlns.addPrefix("Enabled");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, enabled_)) {
            Log(Error, "DataSetWriterDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetWriterId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, dataSetWriterId_)) {
            Log(Error, "DataSetWriterDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetFieldContentMask");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, dataSetFieldContentMask_)) {
            Log(Error, "DataSetWriterDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("KeyFrameCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, keyFrameCount_)) {
            Log(Error, "DataSetWriterDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataSetWriterDataType decode xml error - decode failed")
                .parameter("Element", "DataSetName");
            return false;
        }
    
        elementName = xmlns.addPrefix("DataSetWriterProperties");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetWriterProperties_.xmlDecode(*tree, "KeyValuePair", xmlns)) {
            Log(Error, "DataSetWriterDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("TransportSettings");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportSettings_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataSetWriterDataType decode xml error - decode failed")
                .parameter("Element", "TransportSettings");
            return false;
        }
    
        elementName = xmlns.addPrefix("MessageSettings");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!messageSettings_.xmlDecode(*tree, xmlns)) {
            Log(Error, "DataSetWriterDataType decode xml error - decode failed")
                .parameter("Element", "MessageSettings");
            return false;
        }
    
        return true;
    }
    
    bool
    DataSetWriterDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!name_.jsonEncode(elementTree))
        {
    	     Log(Error, "DataSetWriterDataType json encoder error")
    		     .parameter("Element", "name_");
            return false;
        }
        pt.push_back(std::make_pair("Name", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, enabled_))
        {
    	     Log(Error, "DataSetWriterDataType json encoder error")
    		     .parameter("Element", "enabled_");
           return false;
        }
        pt.push_back(std::make_pair("Enabled", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, dataSetWriterId_))
        {
    	     Log(Error, "DataSetWriterDataType json encoder error")
    		     .parameter("Element", "dataSetWriterId_");
           return false;
        }
        pt.push_back(std::make_pair("DataSetWriterId", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, dataSetFieldContentMask_))
        {
    	     Log(Error, "DataSetWriterDataType json encoder error")
    		     .parameter("Element", "dataSetFieldContentMask_");
           return false;
        }
        pt.push_back(std::make_pair("DataSetFieldContentMask", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, keyFrameCount_))
        {
    	     Log(Error, "DataSetWriterDataType json encoder error")
    		     .parameter("Element", "keyFrameCount_");
           return false;
        }
        pt.push_back(std::make_pair("KeyFrameCount", elementTree));
    
        elementTree.clear();
        if (!dataSetName_.jsonEncode(elementTree))
        {
    	     Log(Error, "DataSetWriterDataType json encoder error")
    		     .parameter("Element", "dataSetName_");
            return false;
        }
        pt.push_back(std::make_pair("DataSetName", elementTree));
    
        elementTree.clear();
        if (!dataSetWriterProperties_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "DataSetWriterDataType json encoder error")
    		     .parameter("Element", "dataSetWriterProperties_");
            return false;
        }
        pt.push_back(std::make_pair("DataSetWriterProperties", elementTree));
    
        elementTree.clear();
        if (!transportSettings_.jsonEncode(elementTree))
        {
    	     Log(Error, "DataSetWriterDataType json encoder error")
    		     .parameter("Element", "transportSettings_");
            return false;
        }
        pt.push_back(std::make_pair("TransportSettings", elementTree));
    
        elementTree.clear();
        if (!messageSettings_.jsonEncode(elementTree))
        {
    	     Log(Error, "DataSetWriterDataType json encoder error")
    		     .parameter("Element", "messageSettings_");
            return false;
        }
        pt.push_back(std::make_pair("MessageSettings", elementTree));
    
        return true;
    }
    
    bool
    DataSetWriterDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "Name";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!name_.jsonDecode(*tree)) {
            Log(Error, "DataSetWriterDataType decode json error - decode failed")
                .parameter("Element", "Name");
            return false;
        }
    
        elementName = "Enabled";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, enabled_)) {
            Log(Error, "DataSetWriterDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DataSetWriterId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, dataSetWriterId_)) {
            Log(Error, "DataSetWriterDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DataSetFieldContentMask";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, dataSetFieldContentMask_)) {
            Log(Error, "DataSetWriterDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "KeyFrameCount";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, keyFrameCount_)) {
            Log(Error, "DataSetWriterDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "DataSetName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetName_.jsonDecode(*tree)) {
            Log(Error, "DataSetWriterDataType decode json error - decode failed")
                .parameter("Element", "DataSetName");
            return false;
        }
    
        elementName = "DataSetWriterProperties";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!dataSetWriterProperties_.jsonDecode(*tree, "")) {
            Log(Error, "DataSetWriterDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "TransportSettings";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportSettings_.jsonDecode(*tree)) {
            Log(Error, "DataSetWriterDataType decode json error - decode failed")
                .parameter("Element", "TransportSettings");
            return false;
        }
    
        elementName = "MessageSettings";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "DataSetWriterDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!messageSettings_.jsonDecode(*tree)) {
            Log(Error, "DataSetWriterDataType decode json error - decode failed")
                .parameter("Element", "MessageSettings");
            return false;
        }
    
        return true;
    }
    
    void
    DataSetWriterDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	DataSetWriterDataType* dst = dynamic_cast<DataSetWriterDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    DataSetWriterDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	DataSetWriterDataType* dst = dynamic_cast<DataSetWriterDataType*>(&extensionObjectBase);
    	return *const_cast<DataSetWriterDataType*>(this) == *dst;
    }
    
    void
    DataSetWriterDataType::out(std::ostream& os)
    {
        os << "Name="; name_.out(os);
        os << ", Enabled=" << enabled_;
        os << ", DataSetWriterId=" << dataSetWriterId_;
        os << ", DataSetFieldContentMask=" << dataSetFieldContentMask_;
        os << ", KeyFrameCount=" << keyFrameCount_;
        os << ", DataSetName="; dataSetName_.out(os);
        os << ", DataSetWriterProperties="; dataSetWriterProperties_.out(os);
        os << ", TransportSettings="; transportSettings_.out(os);
        os << ", MessageSettings="; messageSettings_.out(os);
    }

}
