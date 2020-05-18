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

#ifdef _WIN32

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaServer/Service/WindowsService.h"
#include <stdint.h>
#include <sstream>
#include <lmerr.h>
#include <fstream>
#include <winreg.h>
#include <boost/format.hpp>



// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
//
// global functions
//
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR *lpszArgv)
{
	// 
	// argument list:
	// lpszArgv[0] - name of the service to start
	// lpszArgv[1] - path and name of the configuration file
	//

	OpcUaServer::WindowsService* windowsService = OpcUaServer::WindowsService::instance();
	windowsService->eventLog("Info", "Global ServiceMain");
	windowsService->serviceMain();
}

VOID WINAPI ServiceHandler(DWORD fdwControl)
{
	OpcUaServer::WindowsService* windowsService = OpcUaServer::WindowsService::instance();
	windowsService->eventLog("Info", "Global ServiceHandler");
	windowsService->serviceHandler(fdwControl);
}

namespace OpcUaServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// WindowsService
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	WindowsService* WindowsService::instance_ = nullptr;

	WindowsService*
	WindowsService::instance(void) 
	{
		if (instance_ == nullptr) {
			instance_ = new WindowsService();
		}
		return instance_;
	}

	WindowsService::WindowsService(void)
	: programFileName_("")
	, criticalSection_()		
	, serviceStatus_()
	, ssHandle_()
	, serverLoopIf_(nullptr)
	{
		::InitializeCriticalSection(&criticalSection_);
	}

	WindowsService::~WindowsService(void)
	{
		::DeleteCriticalSection(&criticalSection_);
	}

	void 
	WindowsService::serverLoopIf(ServerLoopIf* serverLoopIf)
	{
		serverLoopIf_ = serverLoopIf;
	}

	void
	WindowsService::usage(void)
	{
		std::stringstream ss;
		ss << "usage:\n\n"
			<< "OpcUaServer\n" 
			<< "OpcUaServer INSTALL <ServiceName> <Description>\n" 
			<< "OpcUaServer UNINSTALL <ServiceName>\n" 
			<< "OpcUaServer START <ServiceName> <ConfigFileName>\n" 
			<< "OpcUaServer STOP <ServiceName>\n"
			<< "OpcUaServer CONSOLE <ServiceName> [<ConfigFileName>]\n\n"; 

		eventLog("Error", ss.str());
	}

	void 
	WindowsService::main(unsigned int argc, char** argv)
	{
		std::string applicationName = "OpcUaServer";

		// write function parameter into event log
		std::stringstream ss;
		ss << "Main: " << applicationName << std::endl;
		for (uint32_t idx=0; idx<argc; idx++) {
			ss << "P[" << idx << "] = " << argv[idx] << std::endl;
		}
		eventLog("Info", ss.str());

		// if no function parameter exist, use command SERVICE as default
		std::string command("SERVICE");
		if (argc > 1) command = argv[1];

		// process install
		if (command == "INSTALL") {
			if (argc != 5) {
				usage();
				return;
			}

			std::string serviceName(argv[2]);
			std::string serviceDescription(argv[3]);
            std::string pathToConfiguration(argv[4]);
			if (!installService(serviceName, serviceDescription, pathToConfiguration)) {
				usage();
			}
			return;
		}

		// handle uninstall
		else if (command == "UNINSTALL") {
			if (argc != 3) {
				usage();
				return;
			}

			std::string serviceName(argv[2]);
			if (!uninstallService(serviceName)) {
				usage();
			}
			return;
		}

		// handle start
		else if (command == "START") {
			if (argc != 4) {
				usage();
				return;
			}

			std::string serviceName(argv[2]);
			std::string pathToConfiguration(argv[3]);
			if (!startService(serviceName, pathToConfiguration)) {
				usage();
			}
			return;
		}

		// handle stop
		else if (command == "STOP") {
			if (argc != 3) {
				usage();
				return;
			}

			std::string serviceName(argv[2]);
			if (!stopService(serviceName)) {
				usage();
			}
			return;
		}

		// handle console
		else if (command == "CONSOLE") {
			if (argc != 3 && argc!= 4) {
				usage();
				return;
			}

			std::string serviceName(argv[2]);
			runConsole(serviceName, argc-2, &argv[2]);
			return;
		}
		
		// handle service
		else if (command == "SERVICE") {
			runService(argc, argv);
			return;
		}

		usage();
		return;
	}

	bool 
	WindowsService::runService(unsigned int argc, char** argv)
	{
		//
		// This function does not return until all services in the process
		// have terminated. The main thread in this function creates a 
		// thread for each service.
		//	
		eventLog("Info", "register table entry");
		SERVICE_TABLE_ENTRY	serviceTableEntry[] = 
		{
			{"", ServiceMain},
			{NULL, NULL}
		};

		StartServiceCtrlDispatcher(serviceTableEntry);
		return true;
	}

	bool 
	WindowsService::runConsole(const std::string& serviceName, unsigned int argc, char** argv)
	{
		serverLoopIf_->serviceCommandLine(serviceName, argc, argv);
		if (!serverLoopIf_->startup()) return false;
		if (!serverLoopIf_->loop()) return false;
		serverLoopIf_->shutdown();
		return true;
	}


	/**
	 * @param[in]		ServiceName
	 * @param[in]		ConfigurationFile
	 */
	bool 
	WindowsService::installService(const std::string& serviceName, const std::string& serviceDescription, const std::string& pathToConfiguration)
	{		
        std::string programFileName;
		if (!programFileName_.empty()) {
			programFileName = programFileName_;
        }
        else {
            char moduleFileName[2048];
            DWORD moduleFileNameLen = GetModuleFileName(NULL, moduleFileName, 2048);
            programFileName = std::string(moduleFileName, moduleFileNameLen);
        }

        const std::string serviceBinary = programFileName + " SERVICE " + serviceName + " \"" + pathToConfiguration + "\"";

		SC_HANDLE scManager = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE); 
		if (scManager==0) 
		{
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "OpenSCManager failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));
			return false;
		}

		SC_HANDLE scService = CreateService( 
			scManager,												/* SCManager database      */ 
			serviceName.c_str(),									/* name of service         */ 
			serviceName.c_str(),									/* service name to display */ 
			SERVICE_ALL_ACCESS,										/* desired access          */ 
			SERVICE_WIN32_OWN_PROCESS|SERVICE_INTERACTIVE_PROCESS , /* service type            */ 
			SERVICE_AUTO_START,										/* start type              */ 
			SERVICE_ERROR_NORMAL,									/* error control type      */ 
            serviceBinary.c_str(),								    /* service's binary        */
			NULL,													/* no load ordering group  */ 
			NULL,													/* no tag identifier       */ 
			NULL,													/* no dependencies         */ 
			NULL,													/* LocalSystem account     */ 
			NULL													/* no password             */ 
		);
		if (scService==0) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "CreateService failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			CloseServiceHandle(scManager);
			return false;
		}

		if (!setServiceDescription(serviceName, serviceDescription)) {
			CloseServiceHandle(scService); 
			CloseServiceHandle(scManager);
			return false;
		}
		startService(serviceName, pathToConfiguration);

		std::stringstream ss;
		ss << "Service " << serviceName << " installed";
		eventLog("Info", ss.str());

		CloseServiceHandle(scService); 
		CloseServiceHandle(scManager);

		return true;
	}

	bool 
	WindowsService::uninstallService(const std::string& serviceName)
	{

		stopService(serviceName);
		if (!delServiceDescription(serviceName)) {
			return false;
		}

		SC_HANDLE scManager = OpenSCManager( NULL, NULL, SC_MANAGER_ALL_ACCESS); 
		if (scManager==0) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "OpenSCManager failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));
			return false;
		}

		SC_HANDLE scService = OpenService(scManager, serviceName.c_str(), SERVICE_ALL_ACCESS);
		if (scService==0) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "OpenService failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			CloseServiceHandle(scManager);
			return false;
		}

		if(!DeleteService(scService)) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "DeleteService failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			CloseServiceHandle(scService); 
			CloseServiceHandle(scManager);
			return false;
		}

		std::stringstream ss;
		ss << "Service " << serviceName << " uninstalled";
		eventLog("Info", ss.str());

		CloseServiceHandle(scService); 
		CloseServiceHandle(scManager);
		return true;
	}

	bool 
	WindowsService::startService(const std::string& serviceName, const std::string& pathToConfiguration)
	{
		SC_HANDLE scManager = OpenSCManager( NULL, NULL, SC_MANAGER_ALL_ACCESS); 
		if (scManager==0)  {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "OpenSCManager failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			return false;
		}

		SC_HANDLE scService = OpenService(scManager, serviceName.c_str(), SERVICE_ALL_ACCESS);
		if (scService==0) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "OpenService failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			CloseServiceHandle(scManager); 
			return false;
		}
	
		LPCSTR lpServiceArgVectors[1] = { pathToConfiguration.c_str() };
		if(!StartService(scService, 1, lpServiceArgVectors)) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "StartService failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			CloseServiceHandle(scService);
			CloseServiceHandle(scManager);
			return false;
		}

		std::stringstream ss;
		ss << "Service " << serviceName << " start";
		eventLog("Info", ss.str());

		CloseServiceHandle(scService);
		CloseServiceHandle(scManager);

		restartAfterFailure(serviceName, 2);
		return true;
	}

	bool 
	WindowsService::stopService(const std::string& serviceName)
	{
		SC_HANDLE scManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS); 
		if (scManager==0) 
		{
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "OpenSCManager failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			return false;
		}

		SC_HANDLE scService = OpenService(scManager, serviceName.c_str(), SERVICE_ALL_ACCESS);
		if (scService==0) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "OpenService failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			CloseServiceHandle(scManager); 
			return false;
		}

		SERVICE_STATUS status;
		if(!ControlService(scService,SERVICE_CONTROL_STOP,&status)) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "StopService failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			CloseServiceHandle(scService);
			CloseServiceHandle(scManager);
			return false;
		}

		std::stringstream ss;
		ss << "Service " << serviceName << " stop";
		eventLog("Info", ss.str());

		CloseServiceHandle(scService);
		CloseServiceHandle(scManager);
		return true;
	}


	bool
	WindowsService::restartAfterFailure(const std::string& serviceName, int restartAfterFailureTime)
	{
		SC_HANDLE scManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS); 
		if (scManager==0) 
		{
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "OpenSCManager failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			return false;
		}

		SC_HANDLE scService = OpenService(scManager, serviceName.c_str(), SERVICE_ALL_ACCESS);
		if (scService==0) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "OpenService failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			CloseServiceHandle(scManager); 
		}

		SERVICE_FAILURE_ACTIONS sfa;
		SC_ACTION actions;

		sfa.dwResetPeriod = INFINITE;
		sfa.lpCommand = NULL;
		sfa.lpRebootMsg = NULL;
		sfa.cActions = 1;
		sfa.lpsaActions = &actions;

		sfa.lpsaActions[0].Type = SC_ACTION_RESTART;
		sfa.lpsaActions[0].Delay = restartAfterFailureTime; 

		ChangeServiceConfig2(scService, SERVICE_CONFIG_FAILURE_ACTIONS, &sfa);

		std::stringstream ss;
		ss << "Service " << serviceName << " set to restart on failure";
		eventLog("Info", ss.str());

		CloseServiceHandle(scService);
		CloseServiceHandle(scManager);
		return true;
	}


	void 
	WindowsService::serviceMain()
	{		
		std::string commandLine(GetCommandLine());
		eventLog("Debug", "Parse the command line of the process: " + commandLine);

		int argc;
		LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);
		if (argc != 4) {
			eventLog("Error", "Wrong number of parameters. Should be 3 instead of " + std::to_string(argc - 1));
			return;
		}

		auto wcharToSting = [](const wchar_t* wstr) {
			std::wstring ws(wstr);
			std::string str(ws.begin(), ws.end());
			return str;
		};

		std::stringstream ss;
		ss << "ServiceMain:" << std::endl;
		for (uint32_t idx=0; idx< argc; idx++) {
			ss << "P[" << idx << "] = " << wcharToSting(argv[idx]) << std::endl;
		}
	
		eventLog("Info", ss.str());

		std::string serviceName = wcharToSting(argv[2]);
		std::string pathToConfiguration = wcharToSting(argv[3]);

		//
		// This function does not return until the service has stopped. 
		// 
		serviceStatus_.dwServiceType			 = SERVICE_WIN32; 
		serviceStatus_.dwCurrentState			 = SERVICE_STOPPED; 
		serviceStatus_.dwControlsAccepted		 = 0; 
		serviceStatus_.dwWin32ExitCode			 = NO_ERROR; 
		serviceStatus_.dwServiceSpecificExitCode = NO_ERROR; 
		serviceStatus_.dwCheckPoint				 = 0; 
		serviceStatus_.dwWaitHint				 = 0; 
	
		ssHandle_ = RegisterServiceCtrlHandler(serviceName.c_str(), ServiceHandler); 
		if (ssHandle_==0) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "RegisterServiceCtrlHandler failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));
			return; 
		} 

		serverLoopIf_->serviceCommandLine(pathToConfiguration, 0, NULL);

		// startup service
		serviceStatus_.dwCurrentState		= SERVICE_START_PENDING;
		SetServiceStatus(ssHandle_, &serviceStatus_);
		bool rc = serverLoopIf_->startup();
		if (!rc) {
			serviceStatus_.dwCurrentState		= SERVICE_STOPPED;
			serviceStatus_.dwControlsAccepted	= 0;
			SetServiceStatus(ssHandle_, &serviceStatus_);

			std::string message = "Service startup function failed";
			eventLog("Error", message);
			return; 
		}

		// run service
		serviceStatus_.dwCurrentState		= SERVICE_RUNNING; 
		serviceStatus_.dwControlsAccepted	= SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
		serviceStatus_.dwCheckPoint			= 0; 
		serviceStatus_.dwWaitHint			= 0;  
		SetServiceStatus(ssHandle_, &serviceStatus_);
		rc = serverLoopIf_->loop();
		if (!rc) {
			serviceStatus_.dwCurrentState		= SERVICE_STOPPED;
			serviceStatus_.dwControlsAccepted	= 0;
			SetServiceStatus(ssHandle_, &serviceStatus_);

			std::string message = "Service run function failed";
			eventLog("Error", message);
			return; 
		}
   
		// service shutdown
		serviceStatus_.dwCurrentState		= SERVICE_STOP_PENDING;
		serviceStatus_.dwControlsAccepted	= SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
		SetServiceStatus(ssHandle_, &serviceStatus_);
		serverLoopIf_->shutdown();

		serviceStatus_.dwCurrentState		= SERVICE_STOPPED;
		serviceStatus_.dwControlsAccepted	= 0;
		SetServiceStatus(ssHandle_, &serviceStatus_);
	}

	void 
	WindowsService::serviceHandler(DWORD fdwControl)
	{
		switch(fdwControl) 
		{
			case SERVICE_CONTROL_STOP:
			case SERVICE_CONTROL_SHUTDOWN:
			{
				serviceStatus_.dwCurrentState		= SERVICE_STOP_PENDING;
				serviceStatus_.dwControlsAccepted	= SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
				SetServiceStatus(ssHandle_, &serviceStatus_);
				serverLoopIf_->stopLoop();
				break; 
			}
		}
	}

	void 
	WindowsService::programFileName(const std::string& programFileName)
	{
		programFileName_ = programFileName;
	}

	std::string 
	WindowsService::getLastErrorMessage(int errorCode)
	{
		HMODULE hModule = NULL; 
		LPSTR MessageBuffer;
		DWORD dwBufferLength;

		DWORD dwFormatFlags = FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM ;

		//
		// If dwLastError is in the network range, load the message source.
		//
		if(errorCode >= NERR_BASE && errorCode <= MAX_NERR) {
			hModule = LoadLibraryEx(TEXT("netmsg.dll"), NULL, LOAD_LIBRARY_AS_DATAFILE);
			if(hModule != NULL) {
				dwFormatFlags |= FORMAT_MESSAGE_FROM_HMODULE;
			}
		}

		//
		// Call FormatMessage() to allow for message 
		//  text to be acquired from the system 
		//  or from the supplied module handle.
		//
		bool success = false;
		if((dwBufferLength = FormatMessageA(
			dwFormatFlags,
			hModule, // module to get message from (NULL == system)
			errorCode,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // default language
			(LPSTR) &MessageBuffer,
			0,
			NULL
		)) > 0)
		{
			success = true;
		}

		//
		// If we loaded a message source, unload it.
		//
		if(hModule != NULL) {
			FreeLibrary(hModule);
		}

		if (!success) return "error unknown";
		return MessageBuffer;
	}

	bool 
	WindowsService::setServiceDescription(const std::string& serviceName, const std::string& serviceDescription)
	{
		HKEY hSecKey = NULL;
		HKEY hSoftKey = NULL;
		DWORD dwCount;
	
		if (ERROR_SUCCESS != RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM", 0, KEY_READ, &hSoftKey)) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "RegOpenKeyEx (SYSTEM) failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));
			return false;
		}

		bool success = true;
		std::string regBaseFolder = "CurrentControlSet\\Services\\" + serviceName;
		long rVal = RegCreateKeyEx(hSoftKey, regBaseFolder.c_str(), 0, REG_NONE,REG_OPTION_NON_VOLATILE, KEY_READ|KEY_WRITE, NULL, &hSecKey, &dwCount);
		if (rVal == 5) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "RegCreateKeyEx (SYSTEM, " << regBaseFolder << ")failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			success = false;
		} 
		else if (rVal == 0) {
			RegSetValueEx(hSecKey, TEXT("Description"), 0, REG_SZ, (const BYTE*)serviceDescription.c_str(), serviceDescription.length());
		}

		if (NULL != hSoftKey) {
			RegCloseKey(hSoftKey);
		}
		return success;
	}

	bool 
	WindowsService::delServiceDescription(const std::string& serviceName)
	{
		HKEY hSecKey = NULL;
		HKEY hSoftKey = NULL;
		DWORD dwCount;
	
		if (ERROR_SUCCESS != RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SYSTEM", 0, KEY_READ, &hSoftKey)) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "RegOpenKeyEx (SYSTEM) failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));
			return false;
		}

		bool success = true;
		std::string regBaseFolder = "CurrentControlSet\\Services\\" + serviceName;
		long rVal = RegCreateKeyEx(hSoftKey, regBaseFolder.c_str(), 0, REG_NONE,REG_OPTION_NON_VOLATILE, KEY_READ|KEY_WRITE, NULL, &hSecKey, &dwCount);
		if (rVal == 5) {
			std::stringstream ss;
			int errorCode = GetLastError();
			ss << "RegCreateKeyEx (SYSTEM, " << regBaseFolder << ")failed, error code =" << errorCode;
			eventLog("Error", ss.str());
			eventLog("Error", getLastErrorMessage(errorCode));

			success = false;
		} else if (rVal == 0) {
			RegDeleteKeyEx(hSecKey, TEXT("Description"), KEY_WOW64_32KEY | KEY_WOW64_64KEY, 0);
		}
	
		if (NULL != hSoftKey) {
			RegCloseKey(hSoftKey);
		}

		return success;
	}

	void 
	WindowsService::log(const std::string& logLevel, const std::string& message)
	{
		::EnterCriticalSection(&criticalSection_);
		try
		{
			SYSTEMTIME oT;
			::GetLocalTime(&oT);
			std::ofstream logFile("C:\\OpcUaServer.trc", std::ios_base::app);

			logFile << boost::format("%s - %02d/%02d/%04d, %02d:%02d:%02d\n    %s\n")
				% logLevel % oT.wMonth % oT.wDay % oT.wYear % oT.wHour % oT.wMinute % oT.wSecond % message;

		} catch(...) {}
		::LeaveCriticalSection(&criticalSection_);
	}

	void 
	WindowsService::eventLog(const std::string& logLevel, const std::string& message)
	{
		log(logLevel, message);
		return;
	}

}

#endif
