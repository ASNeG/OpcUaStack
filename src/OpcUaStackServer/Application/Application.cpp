#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/Application/Application.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	Application::Application(void)
	: applicationIf_(nullptr)
	, state_(ApplConstruct)
	, applicationName_("")
	{
	}

	Application::~Application(void)
	{
	}

	void
	Application::receive(Message::SPtr message)
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

}
