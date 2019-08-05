/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <stdint.h>
#include <sstream>
#include <winreg.h>
#include <boost/format.hpp>

class UpdateRegistry
{
  public:
	int start(int argc, char**argv) 
	{
		std::stringstream ss;
		ss << "Main: " << std::endl;
		for (uint32_t idx=0; idx<(uint32_t)argc; idx++) {
			ss << "P[" << idx << "] = " << argv[idx] << std::endl;
		}
		eventLog("Info", ss.str());

		if (argc != 6) {
			usage();
			return 1;
		}

		// check key
		if (std::string(argv[2]) == "HKCU") primaryKey_ = HKEY_CURRENT_USER;
		else if (std::string(argv[2]) == "HKLM") primaryKey_ = HKEY_LOCAL_MACHINE;
		else {
			usage();
			return 1;
		}

		if (std::string(argv[1]) == "addPath") {
			if (!getValue(std::string(argv[3]), std::string(argv[4]))) {
				value_[0] = 0x00;
			}

			{
				std::stringstream ss;
				ss << "ActualValue=" << value_ << std::endl;
				eventLog("Info", ss.str());
			}

			std::string value(value_);
			value = stringAdd(value_, std::string(argv[5]));
			if (value_ == value) return 0;
		
			if (!createRegistry(std::string(argv[3]))) {
				closeRegistry();
				return 1;
			}

			{
				std::stringstream ss;
				ss << "NewValue=" << value << std::endl;
				eventLog("Info", ss.str());
			}

			if (!setValue(std::string(argv[4]), value)) {
				closeRegistry();
				usage();
				return 1;
			}

			if (!closeRegistry()) {
				return 1;
			}
		}

		else if (std::string(argv[1]) == "removePath") {
			if (!getValue(std::string(argv[3]), std::string(argv[4]))) {
				usage();
				return 1;
			}

			std::string value(value_);
			value = stringRemove(value_, std::string(argv[5]));
			if (value_ == value) return 0;
		
			{
				std::stringstream ss;
				ss << "ActualValue=" << value_ << std::endl;
				eventLog("Info", ss.str());
			}

			if (!createRegistry(std::string(argv[3]))) {
				closeRegistry();
				return 1;
			}

			{
				std::stringstream ss;
				ss << "NewValue=" << value << std::endl;
				eventLog("Info", ss.str());
			}

			if (!setValue(std::string(argv[4]), value)) {
				closeRegistry();
				usage();
				return 1;
			}

			if (!closeRegistry()) {
				return 1;
			}
		}

		else {
			usage();
			return 1;
		}

		return 0;
	}

	void usage(void)
	{
		std::cout 
			<< "usage: UpdateRegistry <Cmd> <Key> <Path> <Parameter> <Value>" << std::endl << std::endl
 			<< "  <Key>" << std::endl
			<< "    HKCU - current user" << std::endl 
			<< "    HKLM - local machine" << std::endl
		<< std::endl;
	}

	bool openRegistry(const std::string& parameter)
	{
		if (RegOpenKey(primaryKey_, parameter.c_str(), &accessKey_) != 0) {
			eventLog("Error", "cannot open registry");
			return false;
		}
		return true;
	}

	bool createRegistry(const std::string& parameter)
	{
		if (RegCreateKey(primaryKey_, parameter.c_str(), &accessKey_) != 0) {
			eventLog("Error", "cannot create registry");
			return false;
		}
		return true;
	}

	bool closeRegistry(void)
	{
		RegCloseKey(accessKey_);
		return true;
	}

	bool getValue(const std::string& path, const std::string& parameter)
	{
		valueLen_ = 1024;
		value_[0] = 0x00;
		if (RegGetValue(primaryKey_, path.c_str(), parameter.c_str(), RRF_RT_ANY, NULL, (PVOID)&value_, &valueLen_) != 0) {
			eventLog("Error", "get value error");
			return false;
		}
		return true;
	}

	bool setValue(const std::string& parameter, const std::string& value)
	{
		if (RegSetValueEx(accessKey_, parameter.c_str(), 0, REG_EXPAND_SZ, (BYTE*)value.c_str(), value.length()) != 0) {
			eventLog("Error", "set value error");
			return false;
		}
		return true;
	}

	std::string stringAdd(const std::string& value, const std::string& addValue)
	{
		std::size_t pos = value.find(addValue);
		if (pos != std::string::npos) {
			eventLog("Error", "value exist...");
			return value;
		}
		std::string val = value;
		if (val.length() == 0) val = addValue;
		else val = val + std::string(";") + addValue;
		return val;
	}

	std::string stringRemove(const std::string& value, const std::string& removeValue)
	{
		std::size_t pos = value.find(removeValue);
		if (pos == std::string::npos) {
			eventLog("Error", "value not exist...");
			return value;
		}

		std::string val = value;
		if (pos == 0) val = val.replace(0, removeValue.length()+1, "");
		else val = val.replace(pos-1, removeValue.length()+1, "");
		return val;
	}

	void
	log(const std::string& logLevel, const std::string& message)
	{
		try
		{
			SYSTEMTIME oT;
			::GetLocalTime(&oT);
			std::ofstream logFile("C:\\OpcUaServer.trc", std::ios_base::app);

			logFile << boost::format("%s - %02d/%02d/%04d, %02d:%02d:%02d\n    %s\n")
					   % logLevel % oT.wMonth % oT.wDay % oT.wYear % oT.wHour % oT.wMinute % oT.wSecond % message;

		} catch(...) {}
	}

	void 
	eventLog(const std::string& logLevel, const std::string& message)
	{
		log(logLevel, message);
		return;
	}

  private:
	HKEY primaryKey_;
	HKEY accessKey_;

	char value_[1024];
	DWORD valueLen_;
};


#if 0


bool
WindowsService::setServiceDescription(void) 
{
	bool rc = true;

	char regKey[512];
	memset(&regKey, 0, sizeof(regKey));
	strcpy_s(regKey, _countof(regKey), "SYSTEM");

	char regBaseFolder[512];
	memset(&regBaseFolder, 0, sizeof(regBaseFolder));
	sprintf_s(regBaseFolder, _countof(regBaseFolder), "CurrentControlSet\\Services\\%s", serviceName_.c_str() );

	HKEY hSecKey = NULL;
	HKEY hSoftKey = NULL;
	DWORD dwCount;
	
	long rVal = 0;
	if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, regKey, 0, KEY_READ, &hSoftKey)) {
		rVal = RegCreateKeyEx(hSoftKey, regBaseFolder, 0, REG_NONE,REG_OPTION_NON_VOLATILE, KEY_READ|KEY_WRITE, NULL, &hSecKey, &dwCount);
		if (rVal == 5) {
			rc = false;
			log("No permissions to access registry in mode KEY_WRITE");
		} else if (rVal == 0) {
			RegSetValueEx(hSecKey, TEXT("Description"), 0, REG_SZ, (const BYTE*)serviceDescription_.c_str(), serviceDescription_.length());
		}
	}
	if (NULL != hSoftKey) {
		RegCloseKey(hSoftKey);
	}
	return rc;
}

bool 
WindowsService::delServiceDescription( void  ) {
	bool rc = true;
	
	char regKey[512];
	memset(&regKey, 0, sizeof(regKey));
	strcpy_s(regKey, _countof(regKey), "SYSTEM");
	char regBaseFolder[512];
	memset(&regBaseFolder, 0, sizeof(regBaseFolder));
	sprintf_s(regBaseFolder, _countof(regBaseFolder), "CurrentControlSet\\Services\\%s", serviceName_.c_str() );

	HKEY hSecKey = NULL;
	HKEY hSoftKey = NULL;
	DWORD dwCount;

	long rVal = 0;
	if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, regKey, 0, KEY_READ, &hSoftKey)) {
		rVal = RegCreateKeyEx(hSoftKey, regBaseFolder, 0, REG_NONE,REG_OPTION_NON_VOLATILE, KEY_READ|KEY_WRITE, NULL, &hSecKey, &dwCount);
		if (rVal == 5) {
			rc = false;
			log("No permissions to access registry in mode KEY_WRITE");
		} else if (rVal == 0) {
			
			typedef LONG (WINAPI * PFN_RegDeleteKeyEx)(HKEY hKey , LPCTSTR lpSubKey , REGSAM samDesired , DWORD Reserved );
			HMODULE hAdvAPI32 = LoadLibrary("AdvAPI32.dll");
			PFN_RegDeleteKeyEx _RegDeleteKeyEx = (PFN_RegDeleteKeyEx)GetProcAddress(hAdvAPI32 , "RegDeleteKeyEx");

			if (_RegDeleteKeyEx != NULL) {
				_RegDeleteKeyEx(hSecKey, TEXT("Description"), KEY_WOW64_RES, 0);
			}
			//else {
				//RegDeleteKeyEx(hSecKey, TEXT("Description"), KEY_WOW64_RES, 0);
			//}

			FreeLibrary(hAdvAPI32);
		}
	}
	if (NULL != hSoftKey) {
		RegCloseKey(hSoftKey);
	}

	return rc;
}

#endif

int main(int argc, char** argv)
{
	UpdateRegistry updateRegistry;
	return updateRegistry.start(argc, argv);
}


