/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSet/ChannelSessionHandle.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer 
{

	ChannelSessionHandle::ChannelSessionHandle(void)
	: secureChannelState_(SCS_Invalid)
	, secureChannel_(nullptr)
	, secureChannelServer_()
	, sessionState_(SS_Invalid)
	, session_()
	{
	}

	ChannelSessionHandle::~ChannelSessionHandle(void)
	{
	}

	ChannelSessionHandle::SecureChannelState
	ChannelSessionHandle::secureChannelState(void)
	{
		return secureChannelState_;
	}

	bool
	ChannelSessionHandle::secureChannelIsValid(void)
	{
		return secureChannelState_ == SCS_Valid;
	}

	void
	ChannelSessionHandle::secureChannel(SecureChannel* secureChannel)
	{
		secureChannel_ = secureChannel;
		if (secureChannel == nullptr) {
			secureChannelState_ = SCS_Invalid;
		}
		else {
			secureChannelState_ = SCS_Valid;
		}
	}

	SecureChannel*
	ChannelSessionHandle::secureChannel(void)
	{
		return secureChannel_;
	}

	void
	ChannelSessionHandle::secureChannelServer(SecureChannelServer::SPtr& secureChannelServer)
	{
		secureChannelServer_ = secureChannelServer;
	}

	SecureChannelServer::SPtr&
	ChannelSessionHandle::secureChannelServer(void)
	{
		return secureChannelServer_;
	}

	ChannelSessionHandle::SessionState
	ChannelSessionHandle::sessionState(void)
	{
		return sessionState_;
	}

	bool
	ChannelSessionHandle::sessionIsValid(void)
	{
		return sessionState_ == SS_Valid;
	}

	void
	ChannelSessionHandle::session(Session::SPtr& session)
	{
		session_ = session;
		if (session_.get() == nullptr) {
			sessionState_ = SS_Invalid;
		}
		else {
			sessionState_ = SS_Valid;
		}
	}

	Session::SPtr&
	ChannelSessionHandle::session(void)
	{
		return session_;
	}

}
