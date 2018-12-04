/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <Windows.h>
#include <iostream>
#include "OpcUaServer/Service/WindowsService.h"
#include "BuildConfig.h"

int main(int argc, char** argv)
{
	char moduleFileName[2048];
	DWORD moduleFileNameLen = GetModuleFileName(NULL, moduleFileName, 2048);
	std::string programFileName(moduleFileName, moduleFileNameLen);

	programFileName = programFileName.substr(0, programFileName.find_last_of('\\')+1);
	programFileName.append("OpcUaServer" + std::string(VERSION_MAJOR) + ".exe");

	OpcUaServer::WindowsService* ws = OpcUaServer::WindowsService::instance();
	ws->programFileName(programFileName);
	ws->main(argc, argv);
}


