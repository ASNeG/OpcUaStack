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
    SessionSecurityDiagnosticsDataType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    SessionSecurityDiagnosticsDataType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    SessionSecurityDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!sessionId_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SessionId", elementTree));
    
        elementTree.clear();
        if (!clientUserIdOfSession_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ClientUserIdOfSession", elementTree));
    
        elementTree.clear();
        if (!clientUserIdHistory_.xmlEncode(elementTree, "String", xmlns)) return false;
        pt.push_back(std::make_pair("ClientUserIdHistory", elementTree));
    
        elementTree.clear();
        if (!authenticationMechanism_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("AuthenticationMechanism", elementTree));
    
        elementTree.clear();
        if (!encoding_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("Encoding", elementTree));
    
        elementTree.clear();
        if (!transportProtocol_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("TransportProtocol", elementTree));
    
        elementTree.clear();
        if (!securityMode_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SecurityMode", elementTree));
    
        elementTree.clear();
        if (!securityPolicyUri_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("SecurityPolicyUri", elementTree));
    
        elementTree.clear();
        if (!clientCertificate_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("ClientCertificate", elementTree));
    
        return true;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    SessionSecurityDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("SessionId");
        if (!tree) return false;
        if (!sessionId_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ClientUserIdOfSession");
        if (!tree) return false;
        if (!clientUserIdOfSession_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ClientUserIdHistory");
        if (!tree) return false;
        if (!clientUserIdHistory_.xmlDecode(*tree, "String", xmlns)) return false;
    
        tree = pt.get_child_optional("AuthenticationMechanism");
        if (!tree) return false;
        if (!authenticationMechanism_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("Encoding");
        if (!tree) return false;
        if (!encoding_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("TransportProtocol");
        if (!tree) return false;
        if (!transportProtocol_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SecurityMode");
        if (!tree) return false;
        if (!securityMode_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("SecurityPolicyUri");
        if (!tree) return false;
        if (!securityPolicyUri_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ClientCertificate");
        if (!tree) return false;
        if (!clientCertificate_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    SessionSecurityDiagnosticsDataType::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    SessionSecurityDiagnosticsDataType::jsonDecode(boost::property_tree::ptree& pt)
    {
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
