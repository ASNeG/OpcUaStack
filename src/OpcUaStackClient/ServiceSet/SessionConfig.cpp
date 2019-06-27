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


#include "OpcUaStackClient/ServiceSet/SessionConfig.h"


namespace OpcUaStackClient
{

	SessionConfig::SessionConfig(void)
	: applicationDescription_(constructSPtr<ApplicationDescription>())
	, sessionName_("urn:127.0.0.1:ASNeG.de:ASNeG-Client")
	, sessionTimeout_(3600000)
	, reconnectTimeout_(5000)
	, maxResponseMessageSize_(16777216)
	, requestTimeout_(3000)
	, policyId_("Anonymous_Policy")
	{
		applicationDescription_->applicationType(AT_Client);
	}

	SessionConfig::~SessionConfig(void)
	{
	}

	void
	SessionConfig::applicationDescription(ApplicationDescription::SPtr& applicationDescription)
	{
		applicationDescription_ = applicationDescription;
	}

	ApplicationDescription::SPtr&
	SessionConfig::applicationDescription(void)
	{
		return applicationDescription_;
	}

	void
	SessionConfig::sessionName(const std::string& sessionName)
	{
		sessionName_ = sessionName;
	}

	std::string&
	SessionConfig::sessionName(void)
	{
		return sessionName_;
	}

	void
	SessionConfig::requestTimeout(uint32_t requestTimeout)
	{
		requestTimeout_ = requestTimeout;
	}

	uint32_t
	SessionConfig::requestTimeout(void)
	{
		return requestTimeout_;
	}

	void
	SessionConfig::sessionTimeout(uint32_t sessionTimeout)
	{
		sessionTimeout_ = sessionTimeout;
	}

	uint32_t
	SessionConfig::sessionTimeout(void)
	{
		return sessionTimeout_;
	}

	void
	SessionConfig::reconnectTimeout(uint32_t reconnectTimeout)
	{
		reconnectTimeout_ = reconnectTimeout;
	}

	uint32_t
	SessionConfig::reconnectTimeout(void)
	{
		return reconnectTimeout_;
	}

	void
	SessionConfig::maxResponseMessageSize(uint32_t maxResponseMessageSize)
	{
		maxResponseMessageSize_ = maxResponseMessageSize;
	}

	uint32_t
	SessionConfig::maxResponseMessageSize(void)
	{
		return maxResponseMessageSize_;
	}

	void
	SessionConfig::policyId(const std::string& policyId)
	{
		policyId_ = policyId;
	}

	std::string&
	SessionConfig::policyId(void)
	{
		return policyId_;
	}

}
