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

#include <OpcUaServer/Server/ServerLoop.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaServer/Server/Server.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Utility/Environment.h"
#include "BuildConfig.h"
#include <iostream>

#include "OpcUaServer/Service/WindowsService.h"
#include "OpcUaServer/Service/LinuxService.h"

using namespace OpcUaStackCore;

int main(int argc, char** argv)
{
	OpcUaServer::ServerLoop serverLoop;
#if _WIN32
	OpcUaServer::WindowsService* service = OpcUaServer::WindowsService::instance();
#else
	OpcUaServer::LinuxService* service = OpcUaServer::LinuxService::instance();
#endif
	service->serverLoopIf(&serverLoop);
	service->main(argc, argv);
}
