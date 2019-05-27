/*
    DataTypeClass: BrokerDataSetWriterTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/BrokerDataSetWriterTransportDataType.h"

namespace OpcUaStackCore
{
    
    BrokerDataSetWriterTransportDataType::BrokerDataSetWriterTransportDataType(void)
    : DataSetWriterTransportDataType()
    , queueName_()
    , resourceUri_()
    , authenticationProfileUri_()
    , requestedDeliveryGuarantee_()
    , metaDataQueueName_()
    , metaDataUpdateTime_()
    {
    }
    
    BrokerDataSetWriterTransportDataType::BrokerDataSetWriterTransportDataType(const BrokerDataSetWriterTransportDataType& value)
    : DataSetWriterTransportDataType()
    , queueName_()
    , resourceUri_()
    , authenticationProfileUri_()
    , requestedDeliveryGuarantee_()
    , metaDataQueueName_()
    , metaDataUpdateTime_()
    {
        const_cast<BrokerDataSetWriterTransportDataType*>(&value)->copyTo(*this);
    }
    
    BrokerDataSetWriterTransportDataType::~BrokerDataSetWriterTransportDataType(void)
    {
    }
    
    OpcUaString&
    BrokerDataSetWriterTransportDataType::queueName(void)
    {
        return queueName_;
    }
    
    OpcUaString&
    BrokerDataSetWriterTransportDataType::resourceUri(void)
    {
        return resourceUri_;
    }
    
    OpcUaString&
    BrokerDataSetWriterTransportDataType::authenticationProfileUri(void)
    {
        return authenticationProfileUri_;
    }
    
    BrokerTransportQualityOfService&
    BrokerDataSetWriterTransportDataType::requestedDeliveryGuarantee(void)
    {
        return requestedDeliveryGuarantee_;
    }
    
    OpcUaString&
    BrokerDataSetWriterTransportDataType::metaDataQueueName(void)
    {
        return metaDataQueueName_;
    }
    
    OpcUaDuration&
    BrokerDataSetWriterTransportDataType::metaDataUpdateTime(void)
    {
        return metaDataUpdateTime_;
    }
    
    bool
    BrokerDataSetWriterTransportDataType::operator==(const BrokerDataSetWriterTransportDataType& value)
    {
        BrokerDataSetWriterTransportDataType* dst = const_cast<BrokerDataSetWriterTransportDataType*>(&value);
        if (queueName_ != dst->queueName()) return false;
        if (resourceUri_ != dst->resourceUri()) return false;
        if (authenticationProfileUri_ != dst->authenticationProfileUri()) return false;
        if (requestedDeliveryGuarantee_ != dst->requestedDeliveryGuarantee()) return false;
        if (metaDataQueueName_ != dst->metaDataQueueName()) return false;
        if (metaDataUpdateTime_ != dst->metaDataUpdateTime()) return false;
        return true;
    }
    
    bool
    BrokerDataSetWriterTransportDataType::operator!=(const BrokerDataSetWriterTransportDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    BrokerDataSetWriterTransportDataType::copyTo(BrokerDataSetWriterTransportDataType& value)
    {
        queueName_.copyTo(value.queueName());
        resourceUri_.copyTo(value.resourceUri());
        authenticationProfileUri_.copyTo(value.authenticationProfileUri());
        requestedDeliveryGuarantee_.copyTo(value.requestedDeliveryGuarantee());
        metaDataQueueName_.copyTo(value.metaDataQueueName());
        value.metaDataUpdateTime_ = metaDataUpdateTime_;
    }
    
    BrokerDataSetWriterTransportDataType&
    BrokerDataSetWriterTransportDataType::operator=(const BrokerDataSetWriterTransportDataType& value)
    {
        const_cast<BrokerDataSetWriterTransportDataType*>(&value)->copyTo(*this);
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
    BrokerDataSetWriterTransportDataType::factory(void)
    {
    	return constructSPtr<BrokerDataSetWriterTransportDataType>();
    }
    
    std::string
    BrokerDataSetWriterTransportDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    BrokerDataSetWriterTransportDataType::typeName(void)
    {
    	return "BrokerDataSetWriterTransportDataType";
    }
    
    OpcUaNodeId
    BrokerDataSetWriterTransportDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15669,0);
    }
    
    OpcUaNodeId
    BrokerDataSetWriterTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15729, 0);
    }
    
    OpcUaNodeId
    BrokerDataSetWriterTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16022, 0);
    }
    
    OpcUaNodeId
    BrokerDataSetWriterTransportDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16525, 0);
    }
    
    void
    BrokerDataSetWriterTransportDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        DataSetWriterTransportDataType::opcUaBinaryEncode(os);
        queueName_.opcUaBinaryEncode(os);
        resourceUri_.opcUaBinaryEncode(os);
        authenticationProfileUri_.opcUaBinaryEncode(os);
        requestedDeliveryGuarantee_.opcUaBinaryEncode(os);
        metaDataQueueName_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,metaDataUpdateTime_);
    }
    
    void
    BrokerDataSetWriterTransportDataType::opcUaBinaryDecode(std::istream& is)
    {
        DataSetWriterTransportDataType::opcUaBinaryDecode(is);
        queueName_.opcUaBinaryDecode(is);
        resourceUri_.opcUaBinaryDecode(is);
        authenticationProfileUri_.opcUaBinaryDecode(is);
        requestedDeliveryGuarantee_.opcUaBinaryDecode(is);
        metaDataQueueName_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,metaDataUpdateTime_);
    }
    
    bool
    BrokerDataSetWriterTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "BrokerDataSetWriterTransportDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    BrokerDataSetWriterTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!queueName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "BrokerDataSetWriterTransportDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("QueueName", elementTree));
    
        elementTree.clear();
        if (!resourceUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "BrokerDataSetWriterTransportDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ResourceUri", elementTree));
    
        elementTree.clear();
        if (!authenticationProfileUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "BrokerDataSetWriterTransportDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AuthenticationProfileUri", elementTree));
    
        elementTree.clear();
        if (!requestedDeliveryGuarantee_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "BrokerDataSetWriterTransportDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RequestedDeliveryGuarantee", elementTree));
    
        elementTree.clear();
        if (!metaDataQueueName_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "BrokerDataSetWriterTransportDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MetaDataQueueName", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, metaDataUpdateTime_))
        {
            Log(Error, "BrokerDataSetWriterTransportDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("MetaDataUpdateTime", elementTree));
    
        return true;
    }
    
    bool
    BrokerDataSetWriterTransportDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    BrokerDataSetWriterTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("QueueName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!queueName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - decode failed")
                .parameter("Element", "QueueName");
            return false;
        }
    
        elementName = xmlns.addPrefix("ResourceUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!resourceUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - decode failed")
                .parameter("Element", "ResourceUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("AuthenticationProfileUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!authenticationProfileUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - decode failed")
                .parameter("Element", "AuthenticationProfileUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("RequestedDeliveryGuarantee");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!requestedDeliveryGuarantee_.xmlDecode(*tree, xmlns)) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - decode failed")
                .parameter("Element", "RequestedDeliveryGuarantee");
            return false;
        }
    
        elementName = xmlns.addPrefix("MetaDataQueueName");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!metaDataQueueName_.xmlDecode(*tree, xmlns)) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - decode failed")
                .parameter("Element", "MetaDataQueueName");
            return false;
        }
    
        elementName = xmlns.addPrefix("MetaDataUpdateTime");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, metaDataUpdateTime_)) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    BrokerDataSetWriterTransportDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!queueName_.jsonEncode(elementTree))
        {
    	     Log(Error, "BrokerDataSetWriterTransportDataType json encoder error")
    		     .parameter("Element", "queueName_");
            return false;
        }
        pt.push_back(std::make_pair("QueueName", elementTree));
    
        elementTree.clear();
        if (!resourceUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "BrokerDataSetWriterTransportDataType json encoder error")
    		     .parameter("Element", "resourceUri_");
            return false;
        }
        pt.push_back(std::make_pair("ResourceUri", elementTree));
    
        elementTree.clear();
        if (!authenticationProfileUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "BrokerDataSetWriterTransportDataType json encoder error")
    		     .parameter("Element", "authenticationProfileUri_");
            return false;
        }
        pt.push_back(std::make_pair("AuthenticationProfileUri", elementTree));
    
        elementTree.clear();
        if (!requestedDeliveryGuarantee_.jsonEncode(elementTree))
        {
    	     Log(Error, "BrokerDataSetWriterTransportDataType json encoder error")
    		     .parameter("Element", "requestedDeliveryGuarantee_");
            return false;
        }
        pt.push_back(std::make_pair("RequestedDeliveryGuarantee", elementTree));
    
        elementTree.clear();
        if (!metaDataQueueName_.jsonEncode(elementTree))
        {
    	     Log(Error, "BrokerDataSetWriterTransportDataType json encoder error")
    		     .parameter("Element", "metaDataQueueName_");
            return false;
        }
        pt.push_back(std::make_pair("MetaDataQueueName", elementTree));
    
        elementTree.clear();
        if(!JsonNumber::jsonEncode(elementTree, metaDataUpdateTime_))
        {
    	     Log(Error, "BrokerDataSetWriterTransportDataType json encoder error")
    		     .parameter("Element", "metaDataUpdateTime_");
           return false;
        }
        pt.push_back(std::make_pair("MetaDataUpdateTime", elementTree));
    
        return true;
    }
    
    bool
    BrokerDataSetWriterTransportDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "QueueName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!queueName_.jsonDecode(*tree)) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode json error - decode failed")
                .parameter("Element", "QueueName");
            return false;
        }
    
        elementName = "ResourceUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!resourceUri_.jsonDecode(*tree)) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode json error - decode failed")
                .parameter("Element", "ResourceUri");
            return false;
        }
    
        elementName = "AuthenticationProfileUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!authenticationProfileUri_.jsonDecode(*tree)) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode json error - decode failed")
                .parameter("Element", "AuthenticationProfileUri");
            return false;
        }
    
        elementName = "RequestedDeliveryGuarantee";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!requestedDeliveryGuarantee_.jsonDecode(*tree)) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode json error - decode failed")
                .parameter("Element", "RequestedDeliveryGuarantee");
            return false;
        }
    
        elementName = "MetaDataQueueName";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!metaDataQueueName_.jsonDecode(*tree)) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode json error - decode failed")
                .parameter("Element", "MetaDataQueueName");
            return false;
        }
    
        elementName = "MetaDataUpdateTime";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!JsonNumber::jsonDecode(*tree, metaDataUpdateTime_)) {
            Log(Error, "BrokerDataSetWriterTransportDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    void
    BrokerDataSetWriterTransportDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	BrokerDataSetWriterTransportDataType* dst = dynamic_cast<BrokerDataSetWriterTransportDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    BrokerDataSetWriterTransportDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	BrokerDataSetWriterTransportDataType* dst = dynamic_cast<BrokerDataSetWriterTransportDataType*>(&extensionObjectBase);
    	return *const_cast<BrokerDataSetWriterTransportDataType*>(this) == *dst;
    }
    
    void
    BrokerDataSetWriterTransportDataType::out(std::ostream& os)
    {
        os << "QueueName="; queueName_.out(os);
        os << ", ResourceUri="; resourceUri_.out(os);
        os << ", AuthenticationProfileUri="; authenticationProfileUri_.out(os);
        os << ", RequestedDeliveryGuarantee="; requestedDeliveryGuarantee_.out(os);
        os << ", MetaDataQueueName="; metaDataQueueName_.out(os);
        os << ", MetaDataUpdateTime=" << metaDataUpdateTime_;
    }

}
