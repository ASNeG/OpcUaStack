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

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaServer_WindowsService_h__
#define __OpcUaServer_WindowsService_h__
#ifdef _WIN32

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaServer/Interface/ServerLoopIf.h"
#include <Windows.h>
#include <WinSvc.h>
#include <string>

namespace OpcUaServer
{

	class DLLEXPORT WindowsService
	{
	  public:
		static WindowsService* instance_;
		static WindowsService* instance(void);

		WindowsService(void);
		virtual ~WindowsService(void);

		void usage(void);
		void main(unsigned int argc, char** argv);
		void serviceMain();
		void serviceHandler(DWORD fdwControl);
		bool installService(const std::string& serviceName, const std::string& serviceDescription, const std::string& pathToConfiguration);
		bool uninstallService(const std::string& serviceName);
		bool startService(const std::string& serviceName, const std::string& pathToConfiguration);
		bool stopService(const std::string& serviceName);
		bool runService(unsigned int argc, char** argv);
		bool runConsole(const std::string& serviceName, unsigned int argc, char** argv);

		void programFileName(const std::string& programFileName);
		void log(const std::string& logLevel, const std::string& message);
		void eventLog(const std::string& logLevel, const std::string& message);

		void serverLoopIf(ServerLoopIf* serverLoopIf);

	  private:
		bool setServiceDescription(const std::string& serviceName, const std::string& serviceDescription);
		bool delServiceDescription(const std::string& serviceName);
		std::string getLastErrorMessage(int errorCode);
		bool restartAfterFailure(const std::string& serviceName, int restartAfterFailureTime);

		std::string programFileName_;
		CRITICAL_SECTION criticalSection_;
		SERVICE_STATUS serviceStatus_;
		SERVICE_STATUS_HANDLE ssHandle_;

		ServerLoopIf* serverLoopIf_;
	};
}

#endif
#endif
