/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetServerInfo/AddSessionRequest.h"

namespace OpcUaStackCore
{

	AddSessionRequest::AddSessionRequest(void)
	{
	}

	AddSessionRequest::~AddSessionRequest(void)
	{
	}

	void
	AddSessionRequest::sessionId(uint32_t sessionId)
	{
		sessionId_ = sessionId;
	}

	uint32_t
	AddSessionRequest::sessionId(void)
	{
		return sessionId_;
	}

	void
	AddSessionRequest::sessionName(const std::string& sessionName)
	{
		sessionName_ = sessionName;
	}

	const std::string&
	AddSessionRequest::sessionName(void)
	{
		return sessionName_;
	}

	void
	AddSessionRequest::sessionTimeout(uint32_t sessionTimeout)
	{
		sessionTimeout_ = sessionTimeout;
	}

	uint32_t
	AddSessionRequest::sessionTimeout(void)
	{
		return sessionTimeout_;
	}

	void
	AddSessionRequest::endpointUrl(const std::string& endpointUrl)
	{
		endpointUrl_ = endpointUrl;
	}

	const std::string&
	AddSessionRequest::endpointUrl(void)
	{
		return endpointUrl_;
	}

	void
	AddSessionRequest::partnerAddress(const std::string& partnerAddress)
	{
		partnerAddress_ = partnerAddress;
	}

	const std::string&
	AddSessionRequest::partnerAddress(void)
	{
		return partnerAddress_;
	}

	void
	AddSessionRequest::startTime(const boost::posix_time::ptime& startTime)
	{
		startTime_ = startTime;
	}

	const boost::posix_time::ptime&
	AddSessionRequest::startTime(void)
	{
		return startTime_;
	}

	bool
	AddSessionRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return true;
	}

	bool
	AddSessionRequest::opcUaBinaryDecode(std::istream& is)
	{
		return true;
	}

}
