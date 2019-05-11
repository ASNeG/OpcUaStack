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

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	enum class UserAuthenticationType
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
	};


	class DLLEXPORT SessionConfig
	{
	  public:
		typedef boost::shared_ptr<SessionConfig> SPtr;

		SessionConfig(void);
		~SessionConfig(void);

		void applicationDescription(ApplicationDescription::SPtr& applicationDescription);
		ApplicationDescription::SPtr& applicationDescription(void);
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
		void policyId(const std::string& policyId);
		std::string& policyId(void);

		void authenticationAnonymous(
			const std::string& policyId
		);
		void authenticationUserName(
			const std::string& policyId,
			const std::string& userName,
			const std::string& password,
			const std::string& encryptionAlgorithm
		);
		void authenticationX509(
			const std::string& policyId,
			Certificate& certificate
		);
		void authenticationIssued(
			const std::string& policyId,
			const std::string& tokenData,
			const std::string& encryptionAlgorithm
		);


	  //private:
		ApplicationDescription::SPtr applicationDescription_;
		std::string sessionName_;
		uint32_t requestTimeout_;
		uint32_t sessionTimeout_;
		uint32_t reconnectTimeout_;
		uint32_t maxResponseMessageSize_;
		std::string policyId_;

	};

}

#endif
