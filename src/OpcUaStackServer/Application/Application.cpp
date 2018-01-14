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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSetApplication/ApplicationServiceTransaction.h"
#include "OpcUaStackServer/Application/Application.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	Application::Application(void)
	: applicationIf_(nullptr)
	, reloadIf_(nullptr)
	, state_(ApplConstruct)
	, applicationName_("")
	, serviceComponent_(nullptr)
	{
	}

	Application::~Application(void)
	{
	}

	void
	Application::applicationIf(ApplicationIf* applicationIf)
	{
		applicationIf_ = applicationIf;
		applicationIf_->service(this);
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

	void
	Application::serviceComponent(Component* serviceComponent)
	{
		serviceComponent_ = serviceComponent;
	}

	bool
	Application::startup(void)
	{
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
	Application::receive(Message::SPtr message)
	{
		ServiceTransaction::SPtr serviceTransaction = boost::static_pointer_cast<ServiceTransaction>(message);

		// check if transaction is synchron
		if (serviceTransaction->sync()) {
			serviceTransaction->conditionBool().conditionTrue();
			return;
		}

		applicationIf_->receive(serviceTransaction);
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ApplicationServiceIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	Application::send(ServiceTransaction::SPtr serviceTransaction)
	{
		updateServiceTransactionRequest(serviceTransaction);
		serviceTransaction->sync(false);
		serviceComponent_->send(serviceTransaction);
	}

	void
	Application::sendSync(ServiceTransaction::SPtr serviceTransaction)
	{

		updateServiceTransactionRequest(serviceTransaction);
		serviceTransaction->sync(true);

		serviceTransaction->conditionBool().conditionInit();
		serviceComponent_->send(serviceTransaction);
		serviceTransaction->conditionBool().waitForCondition();
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
			case OpcUaId_RegisterForwardMethodRequest_Encoding_DefaultBinary:
			case OpcUaId_RegisterForwardGlobalRequest_Encoding_DefaultBinary:
			case OpcUaId_GetNodeReferenceRequest_Encoding_DefaultBinary:
			case OpcUaId_NamespaceInfoRequest_Encoding_DefaultBinary:
			case OpcUaId_FireEventRequest_Encoding_DefaultBinary:
			case OpcUaId_BrowsePathToNodeIdRequest_Encoding_DefaultBinary:
			case OpcUaId_CreateNodeInstanceRequest_Encoding_DefaultBinary:
			case OpcUaId_DelNodeInstanceRequest_Encoding_DefaultBinary:
			{
				serviceTransaction->componentSession(this);
				break;
			}
			default:
			{
				// nothing to do
				Log(Warning, "receive invalid messsage type")
				    .parameter("MessageType", serviceTransaction->nodeTypeRequest().nodeId<uint32_t>());
			}
		}
	}

}
