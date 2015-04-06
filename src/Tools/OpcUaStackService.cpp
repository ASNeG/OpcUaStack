#include <Windows.h>
#include <iostream>
#include "OpcUaServer/Service/WindowsService.h"

int main(int argc, char** argv)
{
	char moduleFileName[2048];
	DWORD moduleFileNameLen = GetModuleFileName(NULL, moduleFileName, 2048);
	std::string programFileName(moduleFileName, moduleFileNameLen);

	programFileName = programFileName.substr(0, programFileName.find_last_of('\\')+1);
	programFileName.append("OpcUaServer.exe");

	OpcUaServer::WindowsService* ws = OpcUaServer::WindowsService::instance();
	ws->programFileName(programFileName);
	ws->main("OpcUaServer", argc, argv);
}


