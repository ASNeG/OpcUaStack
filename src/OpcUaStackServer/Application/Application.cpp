/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackServer/Application/Application.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	Application::Application(
		const std::string& serviceName,
		OpcUaStackCore::IOThread::SPtr& ioThread,
		OpcUaStackCore::MessageBus::SPtr& messageBus
	)
	: ServerServiceBase()
	, applicationIf_(nullptr)
	, reloadIf_(nullptr)
	, state_(ApplConstruct)
	, applicationName_("")
	{
		// set parameter in server service base
		serviceName_ = serviceName;
		ServerServiceBase::ioThread_ = ioThread.get();
		ioThread_ = ioThread;
		strand_ = ioThread->createStrand();
		messageBus_ = messageBus;

		// register message bus receiver
		MessageBusMemberConfig messageBusMemberConfig;
		messageBusMemberConfig.strand(strand_);
		messageBusMember_ = messageBus_->registerMember(serviceName_, messageBusMemberConfig);

		// activate receiver
		activateReceiver(
			[this](const OpcUaStackCore::MessageBusMember::WPtr& handleFrom, Message::SPtr& message){
				receive(handleFrom, message);
			}
		);
	}

	Application::~Application(void)
	{
		// deactivate receiver
		deactivateReceiver();
		messageBus_->deregisterMember(messageBusMember_);
	}

	void
	Application::applicationIf(ApplicationIf* applicationIf)
	{
		applicationIf_ = applicationIf;
		applicationIf_->service(this);

		applicationIf_->applicationData()->messageBusThreadPool(ioThread_);
		applicationIf_->applicationData()->messageBusStrand(strand_);
	}

	ApplicationIf*
	Application::applicationIf(void)
	{
		return applicationIf_;
	}

	void
	Application::reloadIf(ReloadIf* reloadIf)
	{
		reloadIf_ = reloadIf;
	}

	void
	Application::applicationName(const std::string& applicationName)
	{
		applicationName_ = applicationName;
	}

	bool
	Application::startup(void)
	{
		// get application service member
		messageBusMemberApplication_ = messageBus_->getMember("ApplicationServiceServer");
		if (!messageBusMemberApplication_.lock()) {
			Log(Error, "application service member do not exist")
				.parameter("Member", "ApplicationServiceServer");
			return false;
		}

		if (state_ != ApplConstruct) {
			Log(Error, "cannot startup application, because application is in invalid state")
			    .parameter("ApplicationName", applicationName_)
			    .parameter("State", state_);
			return false;
		}

		bool rc = applicationIf_->startup();
		if (!rc) {
			Log(Error, "startup application error")
			    .parameter("ApplicationName", applicationName_);
			return false;
		}

		state_ = ApplStartup;
		return true;
	}

	bool
	Application::shutdown(void)
	{
		if (state_ != ApplStartup) {
			Log(Error, "cannot startup application, because application is in invalid state")
			    .parameter("ApplicationName", applicationName_)
			    .parameter("State", state_);
			return false;
		}

		applicationIf_->shutdown();
		state_ = ApplShutdown;
		return true;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Component
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Application::receiveServiceTrx(
		const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
		Message::SPtr message
	)
	{
		// We have to remember the sender of the message. This enables us to
		// send a reply for the received message later
		auto serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);
		serviceTransaction->memberServiceSession(handleFrom);

		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->promise().set_value(true);
			return;
		}

		applicationIf_->receive(serviceTransaction);
	}

	void
	Application::receiveForwardTrx(
		const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
		Message::SPtr message
	)
	{
		auto forwardTransaction = boost::static_pointer_cast<ForwardTransaction>(message);
		forwardTransaction->messageBusMemberSource(handleFrom);

		applicationIf_->receiveForwardTrx(forwardTransaction);
	}

	void
	Application::receive(
		const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
		Message::SPtr message
	)
	{
		if (message->type_ == Message::ServiceTransaction) {
			receiveServiceTrx(handleFrom, message);
		}
		else {
			receiveForwardTrx(handleFrom, message);
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ApplicationServiceIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Application::send(
		ServiceTransaction::SPtr serviceTransaction
	)
	{
		updateServiceTransactionRequest(serviceTransaction);
		serviceTransaction->sync(false);
		messageBus_->messageSend(
			messageBusMember_,
			messageBusMemberApplication_,
			serviceTransaction
		);
	}

	void
	Application::sendForwardTrx(
		OpcUaStackServer::ForwardTransaction::SPtr forwardTransaction
	)
	{
		messageBus_->messageSend(
			messageBusMember_,
			forwardTransaction->messageBusMemberSource(),
			forwardTransaction
		);
	}

	void
	Application::sendSync(
		ServiceTransaction::SPtr serviceTransaction
	)
	{

		updateServiceTransactionRequest(serviceTransaction);
		serviceTransaction->sync(true);

		auto future = serviceTransaction->promise().get_future();
		messageBus_->messageSend(messageBusMember_, messageBusMemberApplication_, serviceTransaction);
		future.wait();
	}

	void
	Application::reload(void)
	{
		if (reloadIf_ != nullptr) {
			return reloadIf_->reload();
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// private function
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Application::updateServiceTransactionRequest(ServiceTransaction::SPtr serviceTransaction)
	{
		switch (serviceTransaction->nodeTypeRequest().nodeId<uint32_t>())
		{
			case OpcUaId_RegisterForwardNodeRequest_Encoding_DefaultBinary:
			case OpcUaId_RegisterForwardNodeAsyncRequest_Encoding_DefaultBinary:
			case OpcUaId_RegisterForwardMethodRequest_Encoding_DefaultBinary:
			case OpcUaId_RegisterForwardMethodAsyncRequest_Encoding_DefaultBinary:
			case OpcUaId_RegisterForwardGlobalRequest_Encoding_DefaultBinary:
			case OpcUaId_GetNodeReferenceRequest_Encoding_DefaultBinary:
			case OpcUaId_NamespaceInfoRequest_Encoding_DefaultBinary:
			case OpcUaId_FireEventRequest_Encoding_DefaultBinary:
			case OpcUaId_BrowsePathToNodeIdRequest_Encoding_DefaultBinary:
			case OpcUaId_CreateNodeInstanceRequest_Encoding_DefaultBinary:
			case OpcUaId_DelNodeInstanceRequest_Encoding_DefaultBinary:
			case OpcUaId_CreateVariableRequest_Encoding_DefaultBinary:
			case OpcUaId_CreateObjectRequest_Encoding_DefaultBinary:
			{
				serviceTransaction->memberServiceSession(messageBusMember_);
				break;
			}
			default:
			{
				// nothing to do
				Log(Warning, "application interface receive invalid messsage type")
				    .parameter("MessageType", serviceTransaction->nodeTypeRequest().nodeId<uint32_t>());
			}
		}
	}

}
