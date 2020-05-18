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

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaServer/Service/LinuxService.h"
#include <iostream>
#include <csignal>

using namespace std;

void signalHandler(int signum)
{
	OpcUaServer::LinuxService::instance()->stop();
}


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
	: serverLoopIf_(nullptr)
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
	LinuxService::main(unsigned int argc, char** argv)
	{
		if (argc != 2 && argc != 3) {
			usage();
			return;
		}

		std::string serviceName(argv[1]);

		serverLoopIf_->serviceCommandLine(serviceName, argc-1, &argv[1]);
		if (!serverLoopIf_->startup()) return;

		signal(SIGINT, signalHandler);

		if (!serverLoopIf_->loop()) return;
		serverLoopIf_->shutdown();
		return;
	}

	void
	LinuxService::serverLoopIf(ServerLoopIf* serverLoopIf)
	{
		serverLoopIf_ = serverLoopIf;
	}

	void
	LinuxService::stop(void)
	{
		serverLoopIf_->stopLoop();
	}

}
