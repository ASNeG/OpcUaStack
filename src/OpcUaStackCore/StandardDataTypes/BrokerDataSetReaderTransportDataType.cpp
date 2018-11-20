/*
    DataTypeClass: BrokerDataSetReaderTransportDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/BrokerDataSetReaderTransportDataType.h"

namespace OpcUaStackCore
{
    
    BrokerDataSetReaderTransportDataType::BrokerDataSetReaderTransportDataType(void)
    : DataSetReaderTransportDataType()
    , queueName_()
    , resourceUri_()
    , authenticationProfileUri_()
    , requestedDeliveryGuarantee_()
    , metaDataQueueName_()
    {
    }
    
    BrokerDataSetReaderTransportDataType::~BrokerDataSetReaderTransportDataType(void)
    {
    }
    
    OpcUaString&
    BrokerDataSetReaderTransportDataType::queueName(void)
    {
        return queueName_;
    }
    
    OpcUaString&
    BrokerDataSetReaderTransportDataType::resourceUri(void)
    {
        return resourceUri_;
    }
    
    OpcUaString&
    BrokerDataSetReaderTransportDataType::authenticationProfileUri(void)
    {
        return authenticationProfileUri_;
    }
    
    BrokerTransportQualityOfService&
    BrokerDataSetReaderTransportDataType::requestedDeliveryGuarantee(void)
    {
        return requestedDeliveryGuarantee_;
    }
    
    OpcUaString&
    BrokerDataSetReaderTransportDataType::metaDataQueueName(void)
    {
        return metaDataQueueName_;
    }
    
    bool
    BrokerDataSetReaderTransportDataType::operator==(const BrokerDataSetReaderTransportDataType& value)
    {
        BrokerDataSetReaderTransportDataType* dst = const_cast<BrokerDataSetReaderTransportDataType*>(&value);
        if (queueName_ != dst->queueName()) return false;
        if (resourceUri_ != dst->resourceUri()) return false;
        if (authenticationProfileUri_ != dst->authenticationProfileUri()) return false;
        if (requestedDeliveryGuarantee_ != dst->requestedDeliveryGuarantee()) return false;
        if (metaDataQueueName_ != dst->metaDataQueueName()) return false;
        return true;
    }
    
    bool
    BrokerDataSetReaderTransportDataType::operator!=(const BrokerDataSetReaderTransportDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    BrokerDataSetReaderTransportDataType::copyTo(BrokerDataSetReaderTransportDataType& value)
    {
        queueName_.copyTo(value.queueName());
        resourceUri_.copyTo(value.resourceUri());
        authenticationProfileUri_.copyTo(value.authenticationProfileUri());
        requestedDeliveryGuarantee_.copyTo(value.requestedDeliveryGuarantee());
        metaDataQueueName_.copyTo(value.metaDataQueueName());
    }
    
    BrokerDataSetReaderTransportDataType&
    BrokerDataSetReaderTransportDataType::operator=(const BrokerDataSetReaderTransportDataType& value)
    {
        const_cast<BrokerDataSetReaderTransportDataType*>(&value)->copyTo(*this);
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
    BrokerDataSetReaderTransportDataType::factory(void)
    {
    	return constructSPtr<BrokerDataSetReaderTransportDataType>();
    }
    
    std::string
    BrokerDataSetReaderTransportDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    BrokerDataSetReaderTransportDataType::typeName(void)
    {
    	return "BrokerDataSetReaderTransportDataType";
    }
    
    OpcUaNodeId
    BrokerDataSetReaderTransportDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15670,0);
    }
    
    OpcUaNodeId
    BrokerDataSetReaderTransportDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15733, 0);
    }
    
    OpcUaNodeId
    BrokerDataSetReaderTransportDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16023, 0);
    }
    
    OpcUaNodeId
    BrokerDataSetReaderTransportDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)16526, 0);
    }
    
    void
    BrokerDataSetReaderTransportDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        queueName_.opcUaBinaryEncode(os);
        resourceUri_.opcUaBinaryEncode(os);
        authenticationProfileUri_.opcUaBinaryEncode(os);
        requestedDeliveryGuarantee_.opcUaBinaryEncode(os);
        metaDataQueueName_.opcUaBinaryEncode(os);
    }
    
    void
    BrokerDataSetReaderTransportDataType::opcUaBinaryDecode(std::istream& is)
    {
        queueName_.opcUaBinaryDecode(is);
        resourceUri_.opcUaBinaryDecode(is);
        authenticationProfileUri_.opcUaBinaryDecode(is);
        requestedDeliveryGuarantee_.opcUaBinaryDecode(is);
        metaDataQueueName_.opcUaBinaryDecode(is);
    }
    
    bool
    BrokerDataSetReaderTransportDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    BrokerDataSetReaderTransportDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    BrokerDataSetReaderTransportDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    BrokerDataSetReaderTransportDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
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
    
        return true;
    }
    
    bool
    BrokerDataSetReaderTransportDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    BrokerDataSetReaderTransportDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
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
    
        return true;
    }
    
    bool
    BrokerDataSetReaderTransportDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    BrokerDataSetReaderTransportDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    BrokerDataSetReaderTransportDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    BrokerDataSetReaderTransportDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    BrokerDataSetReaderTransportDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	BrokerDataSetReaderTransportDataType* dst = dynamic_cast<BrokerDataSetReaderTransportDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    BrokerDataSetReaderTransportDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	BrokerDataSetReaderTransportDataType* dst = dynamic_cast<BrokerDataSetReaderTransportDataType*>(&extensionObjectBase);
    	return *const_cast<BrokerDataSetReaderTransportDataType*>(this) == *dst;
    }
    
    void
    BrokerDataSetReaderTransportDataType::out(std::ostream& os)
    {
        os << "QueueName="; queueName_.out(os);
        os << ", ResourceUri="; resourceUri_.out(os);
        os << ", AuthenticationProfileUri="; authenticationProfileUri_.out(os);
        os << ", RequestedDeliveryGuarantee="; requestedDeliveryGuarantee_.out(os);
        os << ", MetaDataQueueName="; metaDataQueueName_.out(os);
    }

}
