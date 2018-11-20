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
        queueName_.opcUaBinaryDecode(is);
        resourceUri_.opcUaBinaryDecode(is);
        authenticationProfileUri_.opcUaBinaryDecode(is);
        requestedDeliveryGuarantee_.opcUaBinaryDecode(is);
        metaDataQueueName_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,metaDataUpdateTime_);
    }
    
    bool
    BrokerDataSetWriterTransportDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    BrokerDataSetWriterTransportDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    BrokerDataSetWriterTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    BrokerDataSetWriterTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!queueName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("QueueName", elementTree));
    
        elementTree.clear();
        if (!resourceUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ResourceUri", elementTree));
    
        elementTree.clear();
        if (!authenticationProfileUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("AuthenticationProfileUri", elementTree));
    
        elementTree.clear();
        if (!requestedDeliveryGuarantee_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("RequestedDeliveryGuarantee", elementTree));
    
        elementTree.clear();
        if (!metaDataQueueName_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("MetaDataQueueName", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, metaDataUpdateTime_)) return false;
        pt.push_back(std::make_pair("MetaDataUpdateTime", elementTree));
    
        return true;
    }
    
    bool
    BrokerDataSetWriterTransportDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    BrokerDataSetWriterTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("QueueName");
        if (!tree) return false;
        if (!queueName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ResourceUri");
        if (!tree) return false;
        if (!resourceUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("AuthenticationProfileUri");
        if (!tree) return false;
        if (!authenticationProfileUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("RequestedDeliveryGuarantee");
        if (!tree) return false;
        if (!requestedDeliveryGuarantee_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("MetaDataQueueName");
        if (!tree) return false;
        if (!metaDataQueueName_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("MetaDataUpdateTime");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, metaDataUpdateTime_)) return false;
    
        return true;
    }
    
    bool
    BrokerDataSetWriterTransportDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    BrokerDataSetWriterTransportDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    BrokerDataSetWriterTransportDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    BrokerDataSetWriterTransportDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
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
