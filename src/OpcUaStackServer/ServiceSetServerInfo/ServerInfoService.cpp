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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSetServerInfo/ServerInfoServiceTransaction.h"
#include "OpcUaStackServer/ServiceSetServerInfo/ServerInfoService.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ServerInfoService::ServerInfoService(
		const std::string& serviceName,
		OpcUaStackCore::IOThread::SPtr& ioThread,
		OpcUaStackCore::MessageBus::SPtr& messageBus
	)
	: ServerServiceBase()
	{
		// set parameter in server service base
		serviceName_ = serviceName;
		ServerServiceBase::ioThread_ = ioThread.get();
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// activate receiver
		activateReceiver(
			[this](const MessageBusMember::WPtr& handleFrom, Message::SPtr& message){
				receive(handleFrom, message);
			}
		);
	}

	ServerInfoService::~ServerInfoService(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	void 
	ServerInfoService::receive(
		const MessageBusMember::WPtr& handleFrom,
		Message::SPtr& message
	)
	{
		// We have to remember the sender of the message. This enables us to
		// send a reply for the received message later
		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		serviceTransaction->memberServiceSession(handleFrom);

		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>()) 
		{
			case OpcUaId_AddSessionRequest_Encoding_DefaultBinary:
				break;
			case OpcUaId_DelSessionRequest_Encoding_DefaultBinary:
				break;
			case OpcUaId_UpdSessionRequest_Encoding_DefaultBinary:
				break;
			default:
				Log(Error, "server info service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

}
