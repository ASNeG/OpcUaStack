/*
    DataTypeClass: ServerDiagnosticsSummaryDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/ServerDiagnosticsSummaryDataType.h"

namespace OpcUaStackCore
{
    
    ServerDiagnosticsSummaryDataType::ServerDiagnosticsSummaryDataType(void)
    : Object()
    , ExtensionObjectBase()
    , serverViewCount_()
    , currentSessionCount_()
    , cumulatedSessionCount_()
    , securityRejectedSessionCount_()
    , rejectedSessionCount_()
    , sessionTimeoutCount_()
    , sessionAbortCount_()
    , currentSubscriptionCount_()
    , cumulatedSubscriptionCount_()
    , publishingIntervalCount_()
    , securityRejectedRequestsCount_()
    , rejectedRequestsCount_()
    {
    }
    
    ServerDiagnosticsSummaryDataType::ServerDiagnosticsSummaryDataType(const ServerDiagnosticsSummaryDataType& value)
    : Object()
    , ExtensionObjectBase()
    , serverViewCount_()
    , currentSessionCount_()
    , cumulatedSessionCount_()
    , securityRejectedSessionCount_()
    , rejectedSessionCount_()
    , sessionTimeoutCount_()
    , sessionAbortCount_()
    , currentSubscriptionCount_()
    , cumulatedSubscriptionCount_()
    , publishingIntervalCount_()
    , securityRejectedRequestsCount_()
    , rejectedRequestsCount_()
    {
        const_cast<ServerDiagnosticsSummaryDataType*>(&value)->copyTo(*this);
    }
    
    ServerDiagnosticsSummaryDataType::~ServerDiagnosticsSummaryDataType(void)
    {
    }
    
    OpcUaUInt32&
    ServerDiagnosticsSummaryDataType::serverViewCount(void)
    {
        return serverViewCount_;
    }
    
    OpcUaUInt32&
    ServerDiagnosticsSummaryDataType::currentSessionCount(void)
    {
        return currentSessionCount_;
    }
    
    OpcUaUInt32&
    ServerDiagnosticsSummaryDataType::cumulatedSessionCount(void)
    {
        return cumulatedSessionCount_;
    }
    
    OpcUaUInt32&
    ServerDiagnosticsSummaryDataType::securityRejectedSessionCount(void)
    {
        return securityRejectedSessionCount_;
    }
    
    OpcUaUInt32&
    ServerDiagnosticsSummaryDataType::rejectedSessionCount(void)
    {
        return rejectedSessionCount_;
    }
    
    OpcUaUInt32&
    ServerDiagnosticsSummaryDataType::sessionTimeoutCount(void)
    {
        return sessionTimeoutCount_;
    }
    
    OpcUaUInt32&
    ServerDiagnosticsSummaryDataType::sessionAbortCount(void)
    {
        return sessionAbortCount_;
    }
    
    OpcUaUInt32&
    ServerDiagnosticsSummaryDataType::currentSubscriptionCount(void)
    {
        return currentSubscriptionCount_;
    }
    
    OpcUaUInt32&
    ServerDiagnosticsSummaryDataType::cumulatedSubscriptionCount(void)
    {
        return cumulatedSubscriptionCount_;
    }
    
    OpcUaUInt32&
    ServerDiagnosticsSummaryDataType::publishingIntervalCount(void)
    {
        return publishingIntervalCount_;
    }
    
    OpcUaUInt32&
    ServerDiagnosticsSummaryDataType::securityRejectedRequestsCount(void)
    {
        return securityRejectedRequestsCount_;
    }
    
    OpcUaUInt32&
    ServerDiagnosticsSummaryDataType::rejectedRequestsCount(void)
    {
        return rejectedRequestsCount_;
    }
    
    bool
    ServerDiagnosticsSummaryDataType::operator==(const ServerDiagnosticsSummaryDataType& value)
    {
        ServerDiagnosticsSummaryDataType* dst = const_cast<ServerDiagnosticsSummaryDataType*>(&value);
        if (serverViewCount_ != dst->serverViewCount()) return false;
        if (currentSessionCount_ != dst->currentSessionCount()) return false;
        if (cumulatedSessionCount_ != dst->cumulatedSessionCount()) return false;
        if (securityRejectedSessionCount_ != dst->securityRejectedSessionCount()) return false;
        if (rejectedSessionCount_ != dst->rejectedSessionCount()) return false;
        if (sessionTimeoutCount_ != dst->sessionTimeoutCount()) return false;
        if (sessionAbortCount_ != dst->sessionAbortCount()) return false;
        if (currentSubscriptionCount_ != dst->currentSubscriptionCount()) return false;
        if (cumulatedSubscriptionCount_ != dst->cumulatedSubscriptionCount()) return false;
        if (publishingIntervalCount_ != dst->publishingIntervalCount()) return false;
        if (securityRejectedRequestsCount_ != dst->securityRejectedRequestsCount()) return false;
        if (rejectedRequestsCount_ != dst->rejectedRequestsCount()) return false;
        return true;
    }
    
    bool
    ServerDiagnosticsSummaryDataType::operator!=(const ServerDiagnosticsSummaryDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    ServerDiagnosticsSummaryDataType::copyTo(ServerDiagnosticsSummaryDataType& value)
    {
        value.serverViewCount_ = serverViewCount_;
        value.currentSessionCount_ = currentSessionCount_;
        value.cumulatedSessionCount_ = cumulatedSessionCount_;
        value.securityRejectedSessionCount_ = securityRejectedSessionCount_;
        value.rejectedSessionCount_ = rejectedSessionCount_;
        value.sessionTimeoutCount_ = sessionTimeoutCount_;
        value.sessionAbortCount_ = sessionAbortCount_;
        value.currentSubscriptionCount_ = currentSubscriptionCount_;
        value.cumulatedSubscriptionCount_ = cumulatedSubscriptionCount_;
        value.publishingIntervalCount_ = publishingIntervalCount_;
        value.securityRejectedRequestsCount_ = securityRejectedRequestsCount_;
        value.rejectedRequestsCount_ = rejectedRequestsCount_;
    }
    
    ServerDiagnosticsSummaryDataType&
    ServerDiagnosticsSummaryDataType::operator=(const ServerDiagnosticsSummaryDataType& value)
    {
        const_cast<ServerDiagnosticsSummaryDataType*>(&value)->copyTo(*this);
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
    ServerDiagnosticsSummaryDataType::factory(void)
    {
    	return boost::make_shared<ServerDiagnosticsSummaryDataType>();
    }
    
    std::string
    ServerDiagnosticsSummaryDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    ServerDiagnosticsSummaryDataType::typeName(void)
    {
    	return "ServerDiagnosticsSummaryDataType";
    }
    
    OpcUaNodeId
    ServerDiagnosticsSummaryDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)859,0);
    }
    
    OpcUaNodeId
    ServerDiagnosticsSummaryDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)861, 0);
    }
    
    OpcUaNodeId
    ServerDiagnosticsSummaryDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)860, 0);
    }
    
    OpcUaNodeId
    ServerDiagnosticsSummaryDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15366, 0);
    }
    
    bool
    ServerDiagnosticsSummaryDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= OpcUaNumber::opcUaBinaryEncode(os,serverViewCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,currentSessionCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,cumulatedSessionCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,securityRejectedSessionCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,rejectedSessionCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,sessionTimeoutCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,sessionAbortCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,currentSubscriptionCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,cumulatedSubscriptionCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,publishingIntervalCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,securityRejectedRequestsCount_);
        rc &= OpcUaNumber::opcUaBinaryEncode(os,rejectedRequestsCount_);
        return rc;
    }
    
    bool
    ServerDiagnosticsSummaryDataType::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= OpcUaNumber::opcUaBinaryDecode(is,serverViewCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,currentSessionCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,cumulatedSessionCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,securityRejectedSessionCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,rejectedSessionCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,sessionTimeoutCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,sessionAbortCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,currentSubscriptionCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,cumulatedSubscriptionCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,publishingIntervalCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,securityRejectedRequestsCount_);
        rc &= OpcUaNumber::opcUaBinaryDecode(is,rejectedRequestsCount_);
        return rc;
    }
    
    bool
    ServerDiagnosticsSummaryDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    ServerDiagnosticsSummaryDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, serverViewCount_))
        {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ServerViewCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, currentSessionCount_))
        {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CurrentSessionCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, cumulatedSessionCount_))
        {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CumulatedSessionCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, securityRejectedSessionCount_))
        {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityRejectedSessionCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, rejectedSessionCount_))
        {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RejectedSessionCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, sessionTimeoutCount_))
        {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SessionTimeoutCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, sessionAbortCount_))
        {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SessionAbortCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, currentSubscriptionCount_))
        {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CurrentSubscriptionCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, cumulatedSubscriptionCount_))
        {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("CumulatedSubscriptionCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, publishingIntervalCount_))
        {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("PublishingIntervalCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, securityRejectedRequestsCount_))
        {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityRejectedRequestsCount", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, rejectedRequestsCount_))
        {
            Log(Error, "ServerDiagnosticsSummaryDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("RejectedRequestsCount", elementTree));
    
        return true;
    }
    
    bool
    ServerDiagnosticsSummaryDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    ServerDiagnosticsSummaryDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("ServerViewCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, serverViewCount_)) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("CurrentSessionCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, currentSessionCount_)) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("CumulatedSessionCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, cumulatedSessionCount_)) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityRejectedSessionCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, securityRejectedSessionCount_)) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("RejectedSessionCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, rejectedSessionCount_)) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("SessionTimeoutCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, sessionTimeoutCount_)) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("SessionAbortCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, sessionAbortCount_)) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("CurrentSubscriptionCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, currentSubscriptionCount_)) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("CumulatedSubscriptionCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, cumulatedSubscriptionCount_)) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("PublishingIntervalCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, publishingIntervalCount_)) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityRejectedRequestsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, securityRejectedRequestsCount_)) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("RejectedRequestsCount");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if(!XmlNumber::xmlDecode(*tree, rejectedRequestsCount_)) {
            Log(Error, "ServerDiagnosticsSummaryDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        return true;
    }
    
    bool
    ServerDiagnosticsSummaryDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonNumberEncode(pt, serverViewCount_, "ServerViewCount");
        rc = rc & jsonNumberEncode(pt, currentSessionCount_, "CurrentSessionCount");
        rc = rc & jsonNumberEncode(pt, cumulatedSessionCount_, "CumulatedSessionCount");
        rc = rc & jsonNumberEncode(pt, securityRejectedSessionCount_, "SecurityRejectedSessionCount");
        rc = rc & jsonNumberEncode(pt, rejectedSessionCount_, "RejectedSessionCount");
        rc = rc & jsonNumberEncode(pt, sessionTimeoutCount_, "SessionTimeoutCount");
        rc = rc & jsonNumberEncode(pt, sessionAbortCount_, "SessionAbortCount");
        rc = rc & jsonNumberEncode(pt, currentSubscriptionCount_, "CurrentSubscriptionCount");
        rc = rc & jsonNumberEncode(pt, cumulatedSubscriptionCount_, "CumulatedSubscriptionCount");
        rc = rc & jsonNumberEncode(pt, publishingIntervalCount_, "PublishingIntervalCount");
        rc = rc & jsonNumberEncode(pt, securityRejectedRequestsCount_, "SecurityRejectedRequestsCount");
        rc = rc & jsonNumberEncode(pt, rejectedRequestsCount_, "RejectedRequestsCount");
    
        return rc;
    }
    
    bool
    ServerDiagnosticsSummaryDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonNumberDecode(pt, serverViewCount_, "ServerViewCount");
        rc = rc & jsonNumberDecode(pt, currentSessionCount_, "CurrentSessionCount");
        rc = rc & jsonNumberDecode(pt, cumulatedSessionCount_, "CumulatedSessionCount");
        rc = rc & jsonNumberDecode(pt, securityRejectedSessionCount_, "SecurityRejectedSessionCount");
        rc = rc & jsonNumberDecode(pt, rejectedSessionCount_, "RejectedSessionCount");
        rc = rc & jsonNumberDecode(pt, sessionTimeoutCount_, "SessionTimeoutCount");
        rc = rc & jsonNumberDecode(pt, sessionAbortCount_, "SessionAbortCount");
        rc = rc & jsonNumberDecode(pt, currentSubscriptionCount_, "CurrentSubscriptionCount");
        rc = rc & jsonNumberDecode(pt, cumulatedSubscriptionCount_, "CumulatedSubscriptionCount");
        rc = rc & jsonNumberDecode(pt, publishingIntervalCount_, "PublishingIntervalCount");
        rc = rc & jsonNumberDecode(pt, securityRejectedRequestsCount_, "SecurityRejectedRequestsCount");
        rc = rc & jsonNumberDecode(pt, rejectedRequestsCount_, "RejectedRequestsCount");
    
        return rc;
    }
    
    void
    ServerDiagnosticsSummaryDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	ServerDiagnosticsSummaryDataType* dst = dynamic_cast<ServerDiagnosticsSummaryDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    ServerDiagnosticsSummaryDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	ServerDiagnosticsSummaryDataType* dst = dynamic_cast<ServerDiagnosticsSummaryDataType*>(&extensionObjectBase);
    	return *const_cast<ServerDiagnosticsSummaryDataType*>(this) == *dst;
    }
    
    void
    ServerDiagnosticsSummaryDataType::out(std::ostream& os)
    {
        os << "ServerViewCount=" << serverViewCount_;
        os << ", CurrentSessionCount=" << currentSessionCount_;
        os << ", CumulatedSessionCount=" << cumulatedSessionCount_;
        os << ", SecurityRejectedSessionCount=" << securityRejectedSessionCount_;
        os << ", RejectedSessionCount=" << rejectedSessionCount_;
        os << ", SessionTimeoutCount=" << sessionTimeoutCount_;
        os << ", SessionAbortCount=" << sessionAbortCount_;
        os << ", CurrentSubscriptionCount=" << currentSubscriptionCount_;
        os << ", CumulatedSubscriptionCount=" << cumulatedSubscriptionCount_;
        os << ", PublishingIntervalCount=" << publishingIntervalCount_;
        os << ", SecurityRejectedRequestsCount=" << securityRejectedRequestsCount_;
        os << ", RejectedRequestsCount=" << rejectedRequestsCount_;
    }

}
