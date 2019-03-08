/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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


#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/SessionServiceStateDisconnecting.h"
#include "OpcUaStackClient/ServiceSet/SessionService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	SessionServiceStateDisconnecting::SessionServiceStateDisconnecting(void)
	: SessionServiceStateIf("Disconnecting", SessionServiceStateId::Disconnecting)
	{
	}

	SessionServiceStateDisconnecting::~SessionServiceStateDisconnecting(void)
	{
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::asyncConnect(void)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::asyncDisconnect(bool deleteSubscriptions)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::asyncCancel(uint32_t requestHandle)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::handleConnect(SecureChannel* secureChannel)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::handleDisconnect(SecureChannel* secureChannel)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::handleCreateSessionResponse(
		SecureChannel* secureChannel,
		ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::handleActivateSessionResponse(
		SecureChannel* secureChannel,
		ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::recvCloseSessionResponse(
		SecureChannel* secureChannel,
		ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::handleMessageResponse(
		SecureChannel* secureChannel,
		ResponseHeader::SPtr& responseHeader
	)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::sendMessageRequest(Message::SPtr message)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::reconnectTimeout(void)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

	SessionServiceStateId
	SessionServiceStateDisconnecting::pendingQueueTimeout(Object::SPtr& object)
	{
		// FIXME: todo
		return SessionServiceStateId::Disconnecting;
	}

}
