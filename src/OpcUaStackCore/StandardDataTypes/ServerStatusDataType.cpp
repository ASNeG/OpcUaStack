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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/StandardDataTypes/ServerStatusDataType.h"

namespace OpcUaStackCore
{

	ServerStatusDataType::ServerStatusDataType(void)
	: Object()
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

	void
	ServerStatusDataType::startTime(OpcUaDateTime startTime)
	{
		startTime_ = startTime;
	}

	OpcUaDateTime&
	ServerStatusDataType::currentTime(void)
	{
		return currentTime_;
	}

	void
	ServerStatusDataType::currentTime(OpcUaDateTime currentTime)
	{
		currentTime_ = currentTime;
	}

	OpcUaUInt32&
	ServerStatusDataType::serverState(void)
	{
		return serverState_;
	}

	void
	ServerStatusDataType::serverState(OpcUaUInt32 serverState)
	{
		serverState_ = serverState;
	}

	BuildInfo&
	ServerStatusDataType::buildInfo(void)
	{
		return buildInfo_;
	}

	void
	ServerStatusDataType::buildInfo(BuildInfo buildInfo)
	{
		buildInfo_ = buildInfo;
	}

	OpcUaUInt32&
	ServerStatusDataType::secondsTillShutdown(void)
	{
		return secondsTillShutdown_;
	}

	void
	ServerStatusDataType::secondsTillShutdown(OpcUaUInt32 secondsTillShutdown)
	{
		secondsTillShutdown_ = secondsTillShutdown;
	}

	OpcUaLocalizedText&
	ServerStatusDataType::shutdownReason(void)
	{
		return shutdownReason_;
	}

	void
	ServerStatusDataType::shutdownReason(OpcUaLocalizedText shutdownReason)
	{
		shutdownReason_ = shutdownReason;
	}

	void
	ServerStatusDataType::copyTo(ServerStatusDataType& serverStatusDataType)
	{
		startTime_.copyTo(serverStatusDataType.startTime_);
		currentTime_.copyTo(serverStatusDataType.currentTime_);
		serverStatusDataType.serverState_ = serverState_;
		buildInfo_.copyTo(serverStatusDataType.buildInfo());
		serverStatusDataType.secondsTillShutdown_ = secondsTillShutdown_;
		shutdownReason_.copyTo(serverStatusDataType.shutdownReason_);
	}

	bool
	ServerStatusDataType::operator==(const ServerStatusDataType& serverStatusDataType) const
	{
		ServerStatusDataType* dst = const_cast<ServerStatusDataType*>(&serverStatusDataType);
		return
			startTime_ == dst->startTime() &&
			currentTime_ == dst->currentTime() &&
			serverState_ == dst->serverState() &&
			buildInfo_ == dst->buildInfo() &&
			secondsTillShutdown_ == dst->secondsTillShutdown() &&
			shutdownReason_ == dst->shutdownReason();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	ServerStatusDataType::factory(void)
	{
		return constructSPtr<ServerStatusDataType>();
	}

	void
	ServerStatusDataType::opcUaBinaryEncode(std::ostream& os) const
	{
		startTime_.opcUaBinaryEncode(os);
		currentTime_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, serverState_);
		buildInfo_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, secondsTillShutdown_);
		shutdownReason_.opcUaBinaryEncode(os);
	}

	void
	ServerStatusDataType::opcUaBinaryDecode(std::istream& is)
	{
		startTime_.opcUaBinaryDecode(is);
		currentTime_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, serverState_);
		buildInfo_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, secondsTillShutdown_);
		shutdownReason_.opcUaBinaryDecode(is);
	}

	bool
	ServerStatusDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	ServerStatusDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	ServerStatusDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	void
	ServerStatusDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		ServerStatusDataType* dst = dynamic_cast<ServerStatusDataType*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	ServerStatusDataType::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		ServerStatusDataType* dst = dynamic_cast<ServerStatusDataType*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	ServerStatusDataType::out(std::ostream& os)
	{
		os << "StartTime="; startTime_.out(os);
		os << ", CurrentTime="; currentTime_.out(os);
		os << ", ServerState=" << serverState_;
		os << ", BuildInfo={"; buildInfo_.out(os); os << "}";
		os << ", SecondsTillShutdown="; os << secondsTillShutdown_;
		os << ", ShutdownReason="; shutdownReason_.out(os);
	}

}


