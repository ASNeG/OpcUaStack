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
#include "OpcUaStackServer/InformationModel/ObjectInstanceBuilder.h"
#include "OpcUaStackServer/InformationModel/InformationModelManager.h"

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
				addSessionRequest(serviceTransaction);
				break;
			case OpcUaId_DelSessionRequest_Encoding_DefaultBinary:
				delSessionRequest(serviceTransaction);
				break;
			case OpcUaId_UpdSessionRequest_Encoding_DefaultBinary:
				updSessionRequest(serviceTransaction);
				break;
			default:
				Log(Error, "server info service received unknown message type")
					.parameter("TypeId", serviceTransaction->nodeTypeRequest());
		}
	}

	void
	ServerInfoService::addSessionRequest(ServiceTransaction::SPtr& serviceTransaction)
	{
		auto trx = boost::static_pointer_cast<ServiceTransactionAddSession>(serviceTransaction);
		auto req = trx->request();

		// check parameter
		if (req->sessionName().empty()) {
			req->sessionName("Unknown");
		}

		// check if session already exist in object map
		if (sessionInfoMap_.find(req->sessionId()) != sessionInfoMap_.end()) {
			return;
		}

		// create session info object
		auto sessionInfo = boost::make_shared<SessionInfo>();

		// create new object in the information model
		ObjectInstanceBuilder objectInstanceBuilder;
		OpcUaStatusCode result = objectInstanceBuilder.createObjectInstance(
			informationModel_,
			sessionInfo->objectTypeNamespaceName(),
			OpcUaLocalizedText("de", req->sessionName()),
			OpcUaNodeId("Sessions", 1),
			OpcUaNodeId(OpcUaId_Organizes),
			sessionInfo
		);

		// set object variables
		sessionInfo->sessionId_Variable()->setDataValue(OpcUaDataValue(req->sessionId()));
		sessionInfo->sessionTimeout_Variable()->setDataValue(OpcUaDataValue(req->sessionTimeout()));
		sessionInfo->startTime_Variable()->setDataValue(OpcUaDataValue(OpcUaDateTime(req->startTime())));
		sessionInfo->sessionState_Variable()->setDataValue((OpcUaUInt32)0);
		sessionInfo->endpointUrl_Variable()->setDataValue(OpcUaDataValue(OpcUaString(req->endpointUrl())));
		sessionInfo->clientAddress_Variable()->setDataValue(OpcUaDataValue(OpcUaString(req->partnerAddress())));

		// add new object to map
		sessionInfoMap_.insert(std::make_pair(req->sessionId(), sessionInfo));
	}

	void
	ServerInfoService::delSessionRequest(ServiceTransaction::SPtr& serviceTransaction)
	{
		auto trx = boost::static_pointer_cast<ServiceTransactionDelSession>(serviceTransaction);
		auto req = trx->request();

		// get session info from session info map
		auto it = sessionInfoMap_.find(req->sessionId());
		if (it == sessionInfoMap_.end()) {
			return;
		}
		auto sessionInfo = it->second;

		// delete session info object from information model
		InformationModelManager imm(informationModel_);
		imm.delNode(sessionInfo->nodeId());

		// delete session info from session info map
		sessionInfoMap_.erase(it);
	}

	void
	ServerInfoService::updSessionRequest(ServiceTransaction::SPtr& serviceTransaction)
	{
		auto trx = boost::static_pointer_cast<ServiceTransactionUpdSession>(serviceTransaction);
		auto req = trx->request();

		// get session info from session info map
		auto it = sessionInfoMap_.find(req->sessionId());
		if (it == sessionInfoMap_.end()) {
			return;
		}
		auto sessionInfo = it->second;

		// set object variables
		sessionInfo->sessionState_Variable()->setDataValue((OpcUaUInt32)1);
	}

}
