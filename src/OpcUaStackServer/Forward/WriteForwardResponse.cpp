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

#include <boost/make_shared.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaStatus.h"
#include "OpcUaStackServer/Forward/WriteForwardResponse.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	WriteForwardResponse::WriteForwardResponse(void)
	: Object()
	{
	}

	WriteForwardResponse::~WriteForwardResponse(void)
	{
	}

	void 
	WriteForwardResponse::result(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaStatusCode
	WriteForwardResponse::result(void) const
	{
		return statusCode_;
	}
	
}
