/*
    DataTypeClass: SessionSecurityDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.0.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/SessionSecurityDiagnosticsDataType.h"

namespace OpcUaStackCore
{
    
    SessionSecurityDiagnosticsDataType::SessionSecurityDiagnosticsDataType(void)
    : Object()
    , ExtensionObjectBase()
    , sessionId_()
    , clientUserIdOfSession_()
    , clientUserIdHistory_()
    , authenticationMechanism_()
    , encoding_()
    , transportProtocol_()
    , securityMode_()
    , securityPolicyUri_()
    , clientCertificate_()
    {
    }
    
    SessionSecurityDiagnosticsDataType::SessionSecurityDiagnosticsDataType(const SessionSecurityDiagnosticsDataType& value)
    : Object()
    , ExtensionObjectBase()
    , sessionId_()
    , clientUserIdOfSession_()
    , clientUserIdHistory_()
    , authenticationMechanism_()
    , encoding_()
    , transportProtocol_()
    , securityMode_()
    , securityPolicyUri_()
    , clientCertificate_()
    {
        const_cast<SessionSecurityDiagnosticsDataType*>(&value)->copyTo(*this);
    }
    
    SessionSecurityDiagnosticsDataType::~SessionSecurityDiagnosticsDataType(void)
    {
    }
    
    OpcUaNodeId&
    SessionSecurityDiagnosticsDataType::sessionId(void)
    {
        return sessionId_;
    }
    
    OpcUaString&
    SessionSecurityDiagnosticsDataType::clientUserIdOfSession(void)
    {
        return clientUserIdOfSession_;
    }
    
    OpcUaStringArray&
    SessionSecurityDiagnosticsDataType::clientUserIdHistory(void)
    {
        return clientUserIdHistory_;
    }
    
    OpcUaString&
    SessionSecurityDiagnosticsDataType::authenticationMechanism(void)
    {
        return authenticationMechanism_;
    }
    
    OpcUaString&
    SessionSecurityDiagnosticsDataType::encoding(void)
    {
        return encoding_;
    }
    
    OpcUaString&
    SessionSecurityDiagnosticsDataType::transportProtocol(void)
    {
        return transportProtocol_;
    }
    
    MessageSecurityMode&
    SessionSecurityDiagnosticsDataType::securityMode(void)
    {
        return securityMode_;
    }
    
    OpcUaString&
    SessionSecurityDiagnosticsDataType::securityPolicyUri(void)
    {
        return securityPolicyUri_;
    }
    
    OpcUaByteString&
    SessionSecurityDiagnosticsDataType::clientCertificate(void)
    {
        return clientCertificate_;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::operator==(const SessionSecurityDiagnosticsDataType& value)
    {
        SessionSecurityDiagnosticsDataType* dst = const_cast<SessionSecurityDiagnosticsDataType*>(&value);
        if (sessionId_ != dst->sessionId()) return false;
        if (clientUserIdOfSession_ != dst->clientUserIdOfSession()) return false;
        if (clientUserIdHistory_ != dst->clientUserIdHistory()) return false;
        if (authenticationMechanism_ != dst->authenticationMechanism()) return false;
        if (encoding_ != dst->encoding()) return false;
        if (transportProtocol_ != dst->transportProtocol()) return false;
        if (securityMode_ != dst->securityMode()) return false;
        if (securityPolicyUri_ != dst->securityPolicyUri()) return false;
        if (clientCertificate_ != dst->clientCertificate()) return false;
        return true;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::operator!=(const SessionSecurityDiagnosticsDataType& value)
    {
        return !this->operator==(value);
    }
    
    void
    SessionSecurityDiagnosticsDataType::copyTo(SessionSecurityDiagnosticsDataType& value)
    {
        sessionId_.copyTo(value.sessionId());
        clientUserIdOfSession_.copyTo(value.clientUserIdOfSession());
        clientUserIdHistory_.copyTo(value.clientUserIdHistory());
        authenticationMechanism_.copyTo(value.authenticationMechanism());
        encoding_.copyTo(value.encoding());
        transportProtocol_.copyTo(value.transportProtocol());
        securityMode_.copyTo(value.securityMode());
        securityPolicyUri_.copyTo(value.securityPolicyUri());
        clientCertificate_.copyTo(value.clientCertificate());
    }
    
    SessionSecurityDiagnosticsDataType&
    SessionSecurityDiagnosticsDataType::operator=(const SessionSecurityDiagnosticsDataType& value)
    {
        const_cast<SessionSecurityDiagnosticsDataType*>(&value)->copyTo(*this);
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
    SessionSecurityDiagnosticsDataType::factory(void)
    {
    	return boost::make_shared<SessionSecurityDiagnosticsDataType>();
    }
    
    std::string
    SessionSecurityDiagnosticsDataType::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    SessionSecurityDiagnosticsDataType::typeName(void)
    {
    	return "SessionSecurityDiagnosticsDataType";
    }
    
    OpcUaNodeId
    SessionSecurityDiagnosticsDataType::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)868,0);
    }
    
    OpcUaNodeId
    SessionSecurityDiagnosticsDataType::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)870, 0);
    }
    
    OpcUaNodeId
    SessionSecurityDiagnosticsDataType::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)869, 0);
    }
    
    OpcUaNodeId
    SessionSecurityDiagnosticsDataType::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15369, 0);
    }
    
    bool
    SessionSecurityDiagnosticsDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        bool rc = true;
    
        rc &= sessionId_.opcUaBinaryEncode(os);
        rc &= clientUserIdOfSession_.opcUaBinaryEncode(os);
        rc &= clientUserIdHistory_.opcUaBinaryEncode(os);
        rc &= authenticationMechanism_.opcUaBinaryEncode(os);
        rc &= encoding_.opcUaBinaryEncode(os);
        rc &= transportProtocol_.opcUaBinaryEncode(os);
        rc &= securityMode_.opcUaBinaryEncode(os);
        rc &= securityPolicyUri_.opcUaBinaryEncode(os);
        rc &= clientCertificate_.opcUaBinaryEncode(os);
        return rc;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::opcUaBinaryDecode(std::istream& is)
    {
        bool rc = true;
    
        rc &= sessionId_.opcUaBinaryDecode(is);
        rc &= clientUserIdOfSession_.opcUaBinaryDecode(is);
        rc &= clientUserIdHistory_.opcUaBinaryDecode(is);
        rc &= authenticationMechanism_.opcUaBinaryDecode(is);
        rc &= encoding_.opcUaBinaryDecode(is);
        rc &= transportProtocol_.opcUaBinaryDecode(is);
        rc &= securityMode_.opcUaBinaryDecode(is);
        rc &= securityPolicyUri_.opcUaBinaryDecode(is);
        rc &= clientCertificate_.opcUaBinaryDecode(is);
        return rc;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType encode xml error")
                .parameter("Element", element);
            return false;
        }
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!sessionId_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SessionId", elementTree));
    
        elementTree.clear();
        if (!clientUserIdOfSession_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ClientUserIdOfSession", elementTree));
    
        elementTree.clear();
        if (!clientUserIdHistory_.xmlEncode(elementTree, "String", xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ClientUserIdHistory", elementTree));
    
        elementTree.clear();
        if (!authenticationMechanism_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("AuthenticationMechanism", elementTree));
    
        elementTree.clear();
        if (!encoding_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("Encoding", elementTree));
    
        elementTree.clear();
        if (!transportProtocol_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("TransportProtocol", elementTree));
    
        elementTree.clear();
        if (!securityMode_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityMode", elementTree));
    
        elementTree.clear();
        if (!securityPolicyUri_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("SecurityPolicyUri", elementTree));
    
        elementTree.clear();
        if (!clientCertificate_.xmlEncode(elementTree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType encode xml error");
            return false;
        }
        pt.push_back(std::make_pair("ClientCertificate", elementTree));
    
        return true;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        std::string elementName = xmlns.addPrefix(element);
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false; 
        }
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SessionSecurityDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        std::string elementName;
        boost::optional<boost::property_tree::ptree&> tree;
    
        elementName = xmlns.addPrefix("SessionId");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!sessionId_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "SessionId");
            return false;
        }
    
        elementName = xmlns.addPrefix("ClientUserIdOfSession");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!clientUserIdOfSession_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "ClientUserIdOfSession");
            return false;
        }
    
        elementName = xmlns.addPrefix("ClientUserIdHistory");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!clientUserIdHistory_.xmlDecode(*tree, "String", xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = xmlns.addPrefix("AuthenticationMechanism");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!authenticationMechanism_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "AuthenticationMechanism");
            return false;
        }
    
        elementName = xmlns.addPrefix("Encoding");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!encoding_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "Encoding");
            return false;
        }
    
        elementName = xmlns.addPrefix("TransportProtocol");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportProtocol_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "TransportProtocol");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityMode");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityMode_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "SecurityMode");
            return false;
        }
    
        elementName = xmlns.addPrefix("SecurityPolicyUri");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityPolicyUri_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "SecurityPolicyUri");
            return false;
        }
    
        elementName = xmlns.addPrefix("ClientCertificate");
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!clientCertificate_.xmlDecode(*tree, xmlns)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode xml error - decode failed")
                .parameter("Element", "ClientCertificate");
            return false;
        }
    
        return true;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::jsonEncodeImpl(boost::property_tree::ptree& pt) const
    {
        bool rc = true;
    
        rc = rc & jsonObjectEncode(pt, sessionId_, "SessionId", true);
        rc = rc & jsonObjectEncode(pt, clientUserIdOfSession_, "ClientUserIdOfSession", true);
        rc = rc & jsonArrayEncode(pt, clientUserIdHistory_, "ClientUserIdHistory", true);
        rc = rc & jsonObjectEncode(pt, authenticationMechanism_, "AuthenticationMechanism", true);
        rc = rc & jsonObjectEncode(pt, encoding_, "Encoding", true);
        rc = rc & jsonObjectEncode(pt, transportProtocol_, "TransportProtocol", true);
        rc = rc & jsonObjectEncode(pt, securityMode_, "SecurityMode", true);
        rc = rc & jsonObjectEncode(pt, securityPolicyUri_, "SecurityPolicyUri", true);
        rc = rc & jsonObjectEncode(pt, clientCertificate_, "ClientCertificate", true);
    
        return rc;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        bool rc = true;
    
        rc = rc & jsonObjectDecode(pt, sessionId_, "SessionId", true);
        rc = rc & jsonObjectDecode(pt, clientUserIdOfSession_, "ClientUserIdOfSession", true);
        rc = rc & jsonArrayDecode(pt, clientUserIdHistory_, "ClientUserIdHistory", true);
        rc = rc & jsonObjectDecode(pt, authenticationMechanism_, "AuthenticationMechanism", true);
        rc = rc & jsonObjectDecode(pt, encoding_, "Encoding", true);
        rc = rc & jsonObjectDecode(pt, transportProtocol_, "TransportProtocol", true);
        rc = rc & jsonObjectDecode(pt, securityMode_, "SecurityMode", true);
        rc = rc & jsonObjectDecode(pt, securityPolicyUri_, "SecurityPolicyUri", true);
        rc = rc & jsonObjectDecode(pt, clientCertificate_, "ClientCertificate", true);
    
        return rc;
    }
    
    void
    SessionSecurityDiagnosticsDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	SessionSecurityDiagnosticsDataType* dst = dynamic_cast<SessionSecurityDiagnosticsDataType*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    SessionSecurityDiagnosticsDataType::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	SessionSecurityDiagnosticsDataType* dst = dynamic_cast<SessionSecurityDiagnosticsDataType*>(&extensionObjectBase);
    	return *const_cast<SessionSecurityDiagnosticsDataType*>(this) == *dst;
    }
    
    void
    SessionSecurityDiagnosticsDataType::out(std::ostream& os)
    {
        os << "SessionId="; sessionId_.out(os);
        os << ", ClientUserIdOfSession="; clientUserIdOfSession_.out(os);
        os << ", ClientUserIdHistory="; clientUserIdHistory_.out(os);
        os << ", AuthenticationMechanism="; authenticationMechanism_.out(os);
        os << ", Encoding="; encoding_.out(os);
        os << ", TransportProtocol="; transportProtocol_.out(os);
        os << ", SecurityMode="; securityMode_.out(os);
        os << ", SecurityPolicyUri="; securityPolicyUri_.out(os);
        os << ", ClientCertificate="; clientCertificate_.out(os);
    }

}
