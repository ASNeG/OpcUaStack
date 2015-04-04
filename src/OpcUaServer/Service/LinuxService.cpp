#include "OpcUaStackCore/Base/os.h"
#include "OpcUaServer/Service/LinuxService.h"
#include <iostream>

namespace OpcUaServer
{

	LinuxService* LinuxService::instance_ = nullptr;

	LinuxService*
	LinuxService::instance(void)
	{
		if (instance_ == nullptr) {
			instance_ = new LinuxService();
		}
		return instance_;
	}

	LinuxService::LinuxService(void)
	: serverApplicationIf_(nullptr)
	{
	}

	LinuxService::~LinuxService(void)
	{
	}

	void
	LinuxService::usage(void)
	{
		std::cout
			<< "usage:\n\n"
			<< "OpcUaServer <ServiceName> [ConfigFile]\n\n";
	}

	void
	LinuxService::main(const std::string& applicationName, unsigned int argc, char** argv)
	{
		if (argc != 2 && argc != 3) {
			usage();
			return;
		}

		std::string serviceName(argv[1]);

		serverApplicationIf_->serviceName(serviceName, argc-1, &argv[1]);
		if (!serverApplicationIf_->startup()) return;
		if (!serverApplicationIf_->run()) return;
		serverApplicationIf_->shutdown();
		return;
	}

	void
	LinuxService::serverApplicationIf(ServerApplicationIf* serverApplicationIf)
	{
		serverApplicationIf_ = serverApplicationIf;
	}

}
