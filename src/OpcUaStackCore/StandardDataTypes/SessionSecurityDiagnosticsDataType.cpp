/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Samuel Huebl (samuel.huebl@asneg.de)
 */

#include "OpcUaStackCore/StandardDataTypes/SessionSecurityDiagnosticsDataType.h"

namespace OpcUaStackCore
{

	SessionSecurityDiagnosticsDataType::SessionSecurityDiagnosticsDataType(void)
	: Object()
	, sessionId_()
	, clientUserIdOfSession_()
	, clientUserIdHistory_(constructSPtr<OpcUaStringArray>())
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

	void
	SessionSecurityDiagnosticsDataType::sessionId(OpcUaNodeId sessionId)
	{
		sessionId_ = sessionId;
	}

	OpcUaString&
	SessionSecurityDiagnosticsDataType::clientUserIdOfSession(void)
	{
		return clientUserIdOfSession_;
	}

	void
	SessionSecurityDiagnosticsDataType::clientUserIdOfSession(OpcUaString clientUserIdOfSession)
	{
		clientUserIdOfSession_ = clientUserIdOfSession;
	}

	OpcUaStringArray::SPtr
	SessionSecurityDiagnosticsDataType::clientUserIdHistory(void)
	{
		return clientUserIdHistory_;
	}

	void
	SessionSecurityDiagnosticsDataType::clientUserIdHistory(OpcUaStringArray::SPtr clientUserIdHistory)
	{
		clientUserIdHistory_ = clientUserIdHistory;
	}

	OpcUaString&
	SessionSecurityDiagnosticsDataType::authenticationMechanism(void)
	{
		return authenticationMechanism_;
	}

	void
	SessionSecurityDiagnosticsDataType::authenticationMechanism(OpcUaString authenticationMechanism)
	{
		authenticationMechanism_ = authenticationMechanism;
	}

	OpcUaString&
	SessionSecurityDiagnosticsDataType::encoding(void)
	{
		return encoding_;
	}

	void
	SessionSecurityDiagnosticsDataType::encoding(OpcUaString encoding)
	{
		encoding_ = encoding;
	}

	OpcUaString&
	SessionSecurityDiagnosticsDataType::transportProtocol(void)
	{
		return transportProtocol_;
	}

	void
	SessionSecurityDiagnosticsDataType::transportProtocol(OpcUaString transportProtocol)
	{
		transportProtocol_ = transportProtocol;
	}

	OpcUaUInt32&
	SessionSecurityDiagnosticsDataType::securityMode(void)
	{
		return securityMode_;
	}

	void
	SessionSecurityDiagnosticsDataType::securityMode(OpcUaUInt32 securityMode)
	{
		securityMode_ = securityMode;
	}

	OpcUaString&
	SessionSecurityDiagnosticsDataType::securityPolicyUri(void)
	{
		return securityPolicyUri_;
	}

	void
	SessionSecurityDiagnosticsDataType::securityPolicyUri(OpcUaString securityPolicyUri)
	{
		securityPolicyUri_ = securityPolicyUri;
	}

	OpcUaByteString&
	SessionSecurityDiagnosticsDataType::clientCertificate(void)
	{
		return clientCertificate_;
	}

	void
	SessionSecurityDiagnosticsDataType::clientCertificate(OpcUaByteString clientCertificate)
	{
		clientCertificate_ = clientCertificate;
	}

	void
	SessionSecurityDiagnosticsDataType::copyTo(SessionSecurityDiagnosticsDataType& sessionSecurityDiagnosticsDataType)
	{
		sessionId_.copyTo(sessionSecurityDiagnosticsDataType.sessionId());
		clientUserIdOfSession_.copyTo(sessionSecurityDiagnosticsDataType.clientUserIdOfSession());
		clientUserIdHistory_->copyTo(*sessionSecurityDiagnosticsDataType.clientUserIdHistory());
		authenticationMechanism_.copyTo(sessionSecurityDiagnosticsDataType.authenticationMechanism());
		encoding_.copyTo(sessionSecurityDiagnosticsDataType.encoding());
		transportProtocol_.copyTo(sessionSecurityDiagnosticsDataType.transportProtocol());
		sessionSecurityDiagnosticsDataType.securityMode(securityMode_);
		securityPolicyUri_.copyTo(sessionSecurityDiagnosticsDataType.securityPolicyUri());
		clientCertificate_.copyTo(sessionSecurityDiagnosticsDataType.clientCertificate());
	}

	bool
	SessionSecurityDiagnosticsDataType::operator==(const SessionSecurityDiagnosticsDataType& sessionSecurityDiagnosticsDataType) const
	{
		SessionSecurityDiagnosticsDataType* dst = const_cast<SessionSecurityDiagnosticsDataType*>(&sessionSecurityDiagnosticsDataType);
		return
			sessionId_ == dst->sessionId() &&
			clientUserIdOfSession_ == dst->clientUserIdOfSession() &&
			// FIXME: equals by Array - clientUserIdHistory_ == dst->clientUserIdHistory() &&
			authenticationMechanism_ == dst->authenticationMechanism() &&
			encoding_ == dst->encoding() &&
			transportProtocol_ == dst->transportProtocol() &&
			securityMode_ == dst->securityMode() &&
			securityPolicyUri_ == dst->securityPolicyUri() &&
			clientCertificate_ == dst->clientCertificate();
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

	void
	SessionSecurityDiagnosticsDataType::opcUaBinaryEncode(std::ostream& os) const
	{
		sessionId_.opcUaBinaryEncode(os);
		clientUserIdOfSession_.opcUaBinaryEncode(os);
		clientUserIdHistory_->opcUaBinaryEncode(os);
		authenticationMechanism_.opcUaBinaryEncode(os);
		encoding_.opcUaBinaryEncode(os);
		transportProtocol_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, securityMode_);
		securityPolicyUri_.opcUaBinaryEncode(os);
		clientCertificate_.opcUaBinaryEncode(os);
	}

	void
	SessionSecurityDiagnosticsDataType::opcUaBinaryDecode(std::istream& is)
	{
		sessionId_.opcUaBinaryDecode(is);
		clientUserIdOfSession_.opcUaBinaryDecode(is);
		clientUserIdHistory_->opcUaBinaryDecode(is);
		authenticationMechanism_.opcUaBinaryDecode(is);
		encoding_.opcUaBinaryDecode(is);
		transportProtocol_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, securityMode_);
		securityPolicyUri_.opcUaBinaryDecode(is);
		clientCertificate_.opcUaBinaryDecode(is);
	}

	bool
	SessionSecurityDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	SessionSecurityDiagnosticsDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	SessionSecurityDiagnosticsDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
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
		return *this == *dst;
	}

	void
	SessionSecurityDiagnosticsDataType::out(std::ostream& os)
	{
		os << "SessionId=" << sessionId_;
		os << ", ClientUserIdOfSession="; clientUserIdOfSession_.out(os);
		os << ", ClientUserIdHistory="; clientUserIdHistory_->out(os);
		os << ", AuthenticationMechanism="; authenticationMechanism_.out(os);
		os << ", Encoding="; encoding_.out(os);
		os << ", TransportProtocol="; transportProtocol_.out(os);
		os << ", SecurityMode=" << securityMode_;
		os << ", SecurityPolicyUri="; securityPolicyUri_.out(os);
		os << ", ClientCertificate="; clientCertificate_.out(os);
	}

}

