#ifndef __OpcUaServer_WindowsService_h__
#define __OpcUaServer_WindowsService_h__
#ifdef WIN32

#include "OpcUaServer/Interface/ServerApplicationIf.h"
#include <Windows.h>
#include <WinSvc.h>
#include <string>

namespace OpcUaServer
{

	class WindowsService
	{
	  public:
		static WindowsService* instance_;
		static WindowsService* instance(void);

		WindowsService(void);
		virtual ~WindowsService(void);

		void usage(void);
		void main(const std::string& applicationName, unsigned int argc, char** argv);
		void serviceMain(unsigned int argc, char** argv);
		void serviceHandler(DWORD fdwControl);
		bool installService(const std::string& serviceName, const std::string& serviceDescription);
		bool uninstallService(const std::string& serviceName);
		bool startService(const std::string& serviceName);
		bool stopService(const std::string& serviceName);
		bool runService(unsigned int argc, char** argv);
		bool runConsole(const std::string& serviceName, unsigned int argc, char** argv);

		void programFileName(const std::string& programFileName);
		void log(const std::string& logLevel, const std::string& message);
		void eventLog(const std::string& logLevel, const std::string& message);

		void serverApplicationIf(ServerApplicationIf* serverApplicationIf);

	  private:
		bool setServiceDescription(const std::string& serviceName, const std::string& serviceDescription);
		bool delServiceDescription(const std::string& serviceName);
		std::string getLastErrorMessage(int errorCode);
		bool restartAfterFailure(const std::string& serviceName, int restartAfterFailureTime);

		std::string programFileName_;
		CRITICAL_SECTION criticalSection_;
		SERVICE_STATUS serviceStatus_;
		SERVICE_STATUS_HANDLE ssHandle_;

		ServerApplicationIf* serverApplicationIf_;
	};
}

#endif
#endif