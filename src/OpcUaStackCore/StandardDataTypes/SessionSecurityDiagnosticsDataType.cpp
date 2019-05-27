/*
    DataTypeClass: SessionSecurityDiagnosticsDataType

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

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
    	return constructSPtr<SessionSecurityDiagnosticsDataType>();
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
    
    void
    SessionSecurityDiagnosticsDataType::opcUaBinaryEncode(std::ostream& os) const
    {
        sessionId_.opcUaBinaryEncode(os);
        clientUserIdOfSession_.opcUaBinaryEncode(os);
        clientUserIdHistory_.opcUaBinaryEncode(os);
        authenticationMechanism_.opcUaBinaryEncode(os);
        encoding_.opcUaBinaryEncode(os);
        transportProtocol_.opcUaBinaryEncode(os);
        securityMode_.opcUaBinaryEncode(os);
        securityPolicyUri_.opcUaBinaryEncode(os);
        clientCertificate_.opcUaBinaryEncode(os);
    }
    
    void
    SessionSecurityDiagnosticsDataType::opcUaBinaryDecode(std::istream& is)
    {
        sessionId_.opcUaBinaryDecode(is);
        clientUserIdOfSession_.opcUaBinaryDecode(is);
        clientUserIdHistory_.opcUaBinaryDecode(is);
        authenticationMechanism_.opcUaBinaryDecode(is);
        encoding_.opcUaBinaryDecode(is);
        transportProtocol_.opcUaBinaryDecode(is);
        securityMode_.opcUaBinaryDecode(is);
        securityPolicyUri_.opcUaBinaryDecode(is);
        clientCertificate_.opcUaBinaryDecode(is);
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
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!sessionId_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionSecurityDiagnosticsDataType json encoder error")
    		     .parameter("Element", "sessionId_");
            return false;
        }
        pt.push_back(std::make_pair("SessionId", elementTree));
    
        elementTree.clear();
        if (!clientUserIdOfSession_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionSecurityDiagnosticsDataType json encoder error")
    		     .parameter("Element", "clientUserIdOfSession_");
            return false;
        }
        pt.push_back(std::make_pair("ClientUserIdOfSession", elementTree));
    
        elementTree.clear();
        if (!clientUserIdHistory_.jsonEncode(elementTree, ""))
        {
    	     Log(Error, "SessionSecurityDiagnosticsDataType json encoder error")
    		     .parameter("Element", "clientUserIdHistory_");
            return false;
        }
        pt.push_back(std::make_pair("ClientUserIdHistory", elementTree));
    
        elementTree.clear();
        if (!authenticationMechanism_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionSecurityDiagnosticsDataType json encoder error")
    		     .parameter("Element", "authenticationMechanism_");
            return false;
        }
        pt.push_back(std::make_pair("AuthenticationMechanism", elementTree));
    
        elementTree.clear();
        if (!encoding_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionSecurityDiagnosticsDataType json encoder error")
    		     .parameter("Element", "encoding_");
            return false;
        }
        pt.push_back(std::make_pair("Encoding", elementTree));
    
        elementTree.clear();
        if (!transportProtocol_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionSecurityDiagnosticsDataType json encoder error")
    		     .parameter("Element", "transportProtocol_");
            return false;
        }
        pt.push_back(std::make_pair("TransportProtocol", elementTree));
    
        elementTree.clear();
        if (!securityMode_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionSecurityDiagnosticsDataType json encoder error")
    		     .parameter("Element", "securityMode_");
            return false;
        }
        pt.push_back(std::make_pair("SecurityMode", elementTree));
    
        elementTree.clear();
        if (!securityPolicyUri_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionSecurityDiagnosticsDataType json encoder error")
    		     .parameter("Element", "securityPolicyUri_");
            return false;
        }
        pt.push_back(std::make_pair("SecurityPolicyUri", elementTree));
    
        elementTree.clear();
        if (!clientCertificate_.jsonEncode(elementTree))
        {
    	     Log(Error, "SessionSecurityDiagnosticsDataType json encoder error")
    		     .parameter("Element", "clientCertificate_");
            return false;
        }
        pt.push_back(std::make_pair("ClientCertificate", elementTree));
    
        return true;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::jsonDecodeImpl(const boost::property_tree::ptree& pt)
    {
        std::string elementName;
        boost::optional<const boost::property_tree::ptree&> tree;
    
        elementName = "SessionId";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!sessionId_.jsonDecode(*tree)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "SessionId");
            return false;
        }
    
        elementName = "ClientUserIdOfSession";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!clientUserIdOfSession_.jsonDecode(*tree)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "ClientUserIdOfSession");
            return false;
        }
    
        elementName = "ClientUserIdHistory";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!clientUserIdHistory_.jsonDecode(*tree, "")) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", elementName);
            return false;
        }
    
        elementName = "AuthenticationMechanism";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!authenticationMechanism_.jsonDecode(*tree)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "AuthenticationMechanism");
            return false;
        }
    
        elementName = "Encoding";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!encoding_.jsonDecode(*tree)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "Encoding");
            return false;
        }
    
        elementName = "TransportProtocol";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!transportProtocol_.jsonDecode(*tree)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "TransportProtocol");
            return false;
        }
    
        elementName = "SecurityMode";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityMode_.jsonDecode(*tree)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "SecurityMode");
            return false;
        }
    
        elementName = "SecurityPolicyUri";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!securityPolicyUri_.jsonDecode(*tree)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "SecurityPolicyUri");
            return false;
        }
    
        elementName = "ClientCertificate";
        tree = pt.get_child_optional(elementName);
        if (!tree) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - element not found")
                .parameter("Element", elementName);
            return false;
        }
        if (!clientCertificate_.jsonDecode(*tree)) {
            Log(Error, "SessionSecurityDiagnosticsDataType decode json error - decode failed")
                .parameter("Element", "ClientCertificate");
            return false;
        }
    
        return true;
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
