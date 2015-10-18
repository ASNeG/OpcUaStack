/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/StandardDataTypes/ServerStatusDataType.h"

namespace OpcUaStackCore
{

	ServerStatusDataType::ServerStatusDataType(void)
	: startTime_()
	, currentTime_()
	, serverState_()
	, buildInfo_()
	, secondsTillShutdown_()
	, shutdownReason_()
	{
	}

	OpcUaDateTime&
	ServerStatusDataType::startTime(void)
	{
		return startTime_;
	}

	OpcUaDateTime&
	ServerStatusDataType::currentTime(void)
	{
		return currentTime_;
	}

	OpcUaInt32&
	ServerStatusDataType::serverState(void)
	{
		return serverState_;
	}

	BuildInfo&
	ServerStatusDataType::buildInfo(void)
	{
		return buildInfo_;
	}

	OpcUaUInt32&
	ServerStatusDataType::secondsTillShutdown(void)
	{
		return secondsTillShutdown_;
	}

	OpcUaLocalizedText&
	ServerStatusDataType::shutdownReason(void)
	{
		return shutdownReason_;
	}

}


