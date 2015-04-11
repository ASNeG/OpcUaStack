#include "OpcUaServer/Server/Server.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Utility/Environment.h"
#include "BuildConfig.h"
#include <iostream>

#include "OpcUaServer/Server/ServerApplication.h"
#include "OpcUaServer/Service/WindowsService.h"
#include "OpcUaServer/Service/LinuxService.h"

using namespace OpcUaStackCore;

int main(int argc, char** argv)
{
	OpcUaServer::ServerApplication serverApplication;
#if WIN32
	OpcUaServer::WindowsService* ws = OpcUaServer::WindowsService::instance();
#else
	OpcUaServer::LinuxService* ws = OpcUaServer::LinuxService::instance();
#endif
	ws->serverApplicationIf(&serverApplication);
	ws->main("OpcUaServer", argc, argv);
}
