/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */
#ifndef __OpcUaStackClient_SessionConfig_h__
#define __OpcUaStackClient_SessionConfig_h__

#include "OpcUaStackCore/StandardDataTypes/ApplicationDescription.h"
#include "OpcUaStackCore/Certificate/Certificate.h"

namespace OpcUaStackClient
{

	enum class DLLEXPORT UserAuthenticationType
	{
		Anonymous,
		UserName,
		X509,
		Issued
	};

	class DLLEXPORT UserAuthentication
	{
	  public:
		typedef boost::shared_ptr<UserAuthentication> SPtr;

		UserAuthentication(UserAuthenticationType userAuthenticationType);
		virtual ~UserAuthentication(void);

		UserAuthenticationType userAuthenticationType(void);
		std::string& policyId(void);

	  private:
		UserAuthentication(void);

	  protected:
		UserAuthenticationType userAuthenticationType_;
		std::string policyId_;
	};


	class DLLEXPORT AnonymousAuthentication
	: public UserAuthentication
	{
	  public:
		typedef boost::shared_ptr<AnonymousAuthentication> SPtr;

		AnonymousAuthentication(const std::string& policyId);
		virtual ~AnonymousAuthentication(void);

	  private:
		 AnonymousAuthentication(void);
	};


	class DLLEXPORT UserNameAuthentication
	: public UserAuthentication
	{
	  public:
		typedef boost::shared_ptr<UserNameAuthentication> SPtr;

		UserNameAuthentication(
			const std::string& policyId,
			const std::string& userName,
			const std::string& password,
			const std::string& encryptionAlgorithm,
			const std::string& securityPolicyUri
		);
		~UserNameAuthentication(void);

		std::string& userName(void);
		std::string& password(void);
		std::string& encryptionAlgorithm(void);
		std::string& securityPolicyUri(void);

	  private:
		UserNameAuthentication(void);

		std::string userName_;
		std::string password_;
		std::string encryptionAlgorithm_;
		std::string securityPolicyUri_;
	};


	class DLLEXPORT X509Authentication
	: public UserAuthentication
	{
	  public:
		typedef boost::shared_ptr<X509Authentication> SPtr;

		X509Authentication(
			const std::string& policyId,
			OpcUaStackCore::Certificate::SPtr& certificate,
			OpcUaStackCore::PrivateKey::SPtr& provateKey,
			const std::string& securityPolicyUri
		);
		~X509Authentication(void);

		OpcUaStackCore::Certificate::SPtr& certificate(void);
		OpcUaStackCore::PrivateKey::SPtr& privateKey(void);
		std::string& securityPolicyUri(void);

	  private:
		X509Authentication(void);

		OpcUaStackCore::Certificate::SPtr certificate_;
		OpcUaStackCore::PrivateKey::SPtr privateKey_;
		std::string securityPolicyUri_;
	};


	class DLLEXPORT IssuedAuthentication
	: public UserAuthentication
	{
	  public:
		typedef boost::shared_ptr<IssuedAuthentication> SPtr;

		IssuedAuthentication(
			const std::string& policyId,
			const std::string& tokenData,
			const std::string& encryptionAlgorithm,
			const std::string& securityPolicyUri
		);
		~IssuedAuthentication(void);

		std::string& tokenData(void);
		std::string& encryptionAlgorithm(void);
		std::string& securityPolicyUri(void);

	  private:
		IssuedAuthentication(void);

		std::string tokenData_;
		std::string encryptionAlgorithm_;
		std::string securityPolicyUri_;
	};


	class DLLEXPORT SessionConfig
	{
	  public:
		typedef boost::shared_ptr<SessionConfig> SPtr;

		SessionConfig(void);
		~SessionConfig(void);

		void applicationDescription(OpcUaStackCore::ApplicationDescription::SPtr& applicationDescription);
		OpcUaStackCore::ApplicationDescription::SPtr& applicationDescription(void);
		void sessionName(const std::string& sessionName);
		std::string& sessionName(void);
		void requestTimeout(uint32_t requestTimeout);
		uint32_t requestTimeout(void);
		void sessionTimeout(uint32_t sessionTimeout);
		uint32_t sessionTimeout(void);
		void reconnectTimeout(uint32_t sessionTimeout);
		uint32_t reconnectTimeout(void);
		void maxResponseMessageSize(uint32_t maxResponseMessageSize);
		uint32_t maxResponseMessageSize(void);
		UserAuthentication::SPtr& userAuthentication(void);

		void authenticationAnonymous(
			const std::string& policyId
		);
		void authenticationAnonymous(void);

		void authenticationUserName(
			const std::string& policyId,
			const std::string& userName,
			const std::string& password,
			const std::string& securityPolicyUri,
			const std::string& encryptionAlgorithm = "http://www.w3.org/2001/04/xmlenc#rsa-oaep"
		);
		void authenticationUserName(
			const std::string& userName,
			const std::string& password,
			const std::string& securityPolicyUri
		);

		void authenticationX509(
			const std::string& policyId,
			OpcUaStackCore::Certificate::SPtr& certificate,
			OpcUaStackCore::PrivateKey::SPtr& privateKey,
			const std::string& securityPolicyUri
		);
		void authenticationX509(
			OpcUaStackCore::Certificate::SPtr& certificate,
			OpcUaStackCore::PrivateKey::SPtr& privateKey,
			const std::string& securityPolicyUri
		);

		void authenticationIssued(
			const std::string& policyId,
			const std::string& tokenData,
			const std::string& securityPolicyUri,
			const std::string& encryptionAlgorithm = "http://www.w3.org/2001/04/xmlenc#rsa-oaep"
		);
		void authenticationIssued(
			const std::string& tokenData,
			const std::string& securityPolicyUri
		);


	  private:
		OpcUaStackCore::ApplicationDescription::SPtr applicationDescription_;
		std::string sessionName_;
		uint32_t requestTimeout_;
		uint32_t sessionTimeout_;
		uint32_t reconnectTimeout_;
		uint32_t maxResponseMessageSize_;
		UserAuthentication::SPtr userAuthentication_;

	};

}

#endif
