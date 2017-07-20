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

#ifndef __OpcUaStackCore_SessionSecurityDiagnosticsDataType_h__
#define __OpcUaStackCore_SessionSecurityDiagnosticsDataType_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/Xmlns.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SessionSecurityDiagnosticsDataType
	: public Object
	, public ExtensionObjectBase
	{
	  public:
		typedef boost::shared_ptr<SessionSecurityDiagnosticsDataType> SPtr;

		SessionSecurityDiagnosticsDataType(void);
		virtual ~SessionSecurityDiagnosticsDataType(void);

		OpcUaNodeId& sessionId(void);
		void sessionId(OpcUaNodeId sessionId);
		OpcUaString& clientUserIdOfSession(void);
		void clientUserIdOfSession(OpcUaString clientUserIdOfSession);
		OpcUaStringArray::SPtr clientUserIdHistory(void);
		void clientUserIdHistory(OpcUaStringArray::SPtr clientUserIdHistory);
		OpcUaString& authenticationMechanism(void);
		void authenticationMechanism(OpcUaString authenticationMechanism);
		OpcUaString& encoding(void);
		void encoding(OpcUaString encoding);
		OpcUaString& transportProtocol(void);
		void transportProtocol(OpcUaString transportProtocol);
		OpcUaUInt32& securityMode(void);
		void securityMode(OpcUaUInt32 securityMode);
		OpcUaString& securityPolicyUri(void);
		void securityPolicyUri(OpcUaString securityPolicyUri);
		OpcUaByteString& clientCertificate(void);
		void clientCertificate(OpcUaByteString clientCertificate);

		void copyTo(SessionSecurityDiagnosticsDataType& sessionSecurityDiagnosticsDataType);
		bool operator==(const SessionSecurityDiagnosticsDataType& sessionSecurityDiagnosticsDataType) const;

		//- ExtensionObjectBase -----------------------------------------------
		ExtensionObjectBase::SPtr factory(void);
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
		void copyTo(ExtensionObjectBase& extensionObjectBase);
		bool equal(ExtensionObjectBase& extensionObjectBase) const;
		void out(std::ostream& os);
		//- ExtensionObjectBase -----------------------------------------------

	  private:
		OpcUaNodeId sessionId_;
		OpcUaString clientUserIdOfSession_;
		OpcUaStringArray::SPtr clientUserIdHistory_;
		OpcUaString authenticationMechanism_;
		OpcUaString encoding_;
		OpcUaString transportProtocol_;
		OpcUaUInt32 securityMode_;
		OpcUaString securityPolicyUri_;
		OpcUaByteString clientCertificate_;
	};

}

#endif
