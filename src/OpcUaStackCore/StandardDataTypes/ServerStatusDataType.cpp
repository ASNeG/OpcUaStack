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

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/StandardDataTypes/ServerStatusDataType.h"

namespace OpcUaStackCore
{

	ServerStatusDataType::ServerStatusDataType(void)
	: ObjectPool<ServerStatusDataType>()
	, startTime_()
	, currentTime_()
	, serverState_()
	, buildInfo_()
	, secondsTillShutdown_()
	, shutdownReason_()
	{
	}

	ServerStatusDataType::~ServerStatusDataType(void)
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

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::BSPtr
	ServerStatusDataType::ServerStatusDataType::factory(void)
	{
		return ServerStatusDataType::construct();
	}

	void
	ServerStatusDataType::opcUaBinaryEncode(std::ostream& os) const
	{
		startTime_.opcUaBinaryEncode(os);
		currentTime_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, serverState_);
		//buildInfo_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, secondsTillShutdown_);
		shutdownReason_.opcUaBinaryEncode(os);
	}

	void
	ServerStatusDataType::opcUaBinaryDecode(std::istream& is)
	{
		startTime_.opcUaBinaryDecode(is);
		currentTime_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, serverState_);
		//buildInfo_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, secondsTillShutdown_);
		shutdownReason_.opcUaBinaryDecode(is);
	}

	void
	ServerStatusDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		ServerStatusDataType* dst = dynamic_cast<ServerStatusDataType*>(&extensionObjectBase);
		startTime_.copyTo(dst->startTime_);
		currentTime_.copyTo(dst->currentTime_);
		dst->serverState_ = serverState_;
		//buildInfo.copyTo(dst->buildInfo_);
		dst->secondsTillShutdown_ = secondsTillShutdown_;
		shutdownReason_.copyTo(dst->shutdownReason_);
	}

}


