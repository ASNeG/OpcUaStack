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

#include "OpcUaStackCore/ServiceSetServerInfo/UpdSessionRequest.h"

namespace OpcUaStackCore
{

	UpdSessionRequest::UpdSessionRequest(void)
	{
	}

	UpdSessionRequest::~UpdSessionRequest(void)
	{
	}

	void
	UpdSessionRequest::sessionId(uint32_t sessionId)
	{
		sessionId_ = sessionId;
	}

	uint32_t
	UpdSessionRequest::sessionId(void)
	{
		return sessionId_;
	}

	bool
	UpdSessionRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		return true;
	}

	bool
	UpdSessionRequest::opcUaBinaryDecode(std::istream& is)
	{
		return true;
	}

}
