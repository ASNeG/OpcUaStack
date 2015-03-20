#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/Application/Application.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	Application::Application(void)
	: applicationIf_(nullptr)
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
		serviceTransaction->sync(false);
		serviceTransaction->componentSession(this);
		serviceComponent_->send(serviceTransaction);
	}

	void
	Application::sendSync(ServiceTransaction::SPtr serviceTransaction)
	{
		serviceTransaction->sync(true);
		serviceTransaction->componentSession(this);

		serviceTransaction->conditionBool().conditionInit();
		serviceComponent_->sendAsync(serviceTransaction);
		serviceTransaction->conditionBool().waitForCondition();
	}

}
