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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaServer/ApplicationLibrary/DynamicLibrary.h"

using namespace OpcUaStackCore;

namespace OpcUaServer
{


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Lib
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
#if _WIN32

#include <Windows.h>

	class Lib
	{
	  public:
		bool open(const std::string& libraryName) {

			message_ = "";

			std::string libName = libraryName + std::string(".dll");
			if (libName.length() > 999) return false;

			handle_ = LoadLibrary(libName.c_str());
			if (handle_ == nullptr) {
				int errorCode = GetLastError();
				message_ = getLastErrorMessage(errorCode);
				return false;
			}
			return true;
		}

		bool close(void) {
			message_ = "";

			BOOL rc = FreeLibrary(handle_);
			return rc == TRUE;
		}

		bool get(const std::string& functionName, void **ptr) {
			message_ = "";

			*ptr = reinterpret_cast<void*>(GetProcAddress(handle_, functionName.c_str()));
			if (*ptr == nullptr) {
				int errorCode = GetLastError();
				message_ = getLastErrorMessage(errorCode);
				return false;
			}
			return true;
		}

		std::string errorString(void)
		{
			return message_;
		}

		std::string 
		getLastErrorMessage(int errorCode)
		{
			HMODULE hModule = NULL; 
			LPSTR MessageBuffer;
			DWORD dwBufferLength;

			DWORD dwFormatFlags = FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM ;

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

			if (!success) return "error unknown";
			return MessageBuffer;
	}

	  private:
		std::string message_;
	    HMODULE handle_;
	};

#else

#include <dlfcn.h>

	class Lib
	{
	  public:
		bool open(const std::string& libraryName) {

			errorString_ = "unknown";
			std::string libName = std::string("lib") + libraryName + std::string(".so");
			if (libName.length() > 999) return false;
			handle_ = dlopen(libName.c_str(), RTLD_LAZY);
			if (handle_ == NULL) {
				char* err = dlerror();
				if (err != NULL) errorString_ = std::string(err);
				return false;
			}
			return true;
		}

		bool close(void) {
			dlclose(&handle_);
			return true;
		}

		bool get(const std::string& functionName, void **ptr) {
			errorString_ = "unknown";
			*ptr = dlsym(handle_, functionName.c_str());
			if (*ptr == NULL) {
				char *err = dlerror();
				if (err != NULL) errorString_ = std::string(err);
				return false;
			}
			return true;
		}

		std::string errorString(void)
		{
			return errorString_;
		}

	  private:
		std::string errorString_;
		void *handle_;
	};

#endif



	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ApplicationLibrary
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DynamicLibrary::DynamicLibrary(void)
	: moduleName_("")
	, lib_()
	{
	}

	DynamicLibrary::~DynamicLibrary(void)
	{
		if (lib_ != nullptr) {
			close();
		}
	}

	bool
	DynamicLibrary::isOpen(void)
	{
		return lib_ != nullptr;
	}

	bool
	DynamicLibrary::open(const std::string& moduleName)
	{
		moduleName_ = moduleName;
		if (lib_ != nullptr) {
			Log(Error, "cannot open dynamic library, because library already loaded")
				.parameter("ModuleName", moduleName);
			return false;
		}

		lib_ = new Lib();
		bool rc = lib_->open(moduleName);
		if (!rc) {
			Log(Error, "cannot open dynamic library")
				.parameter("ModuleName", moduleName)
				.parameter("Reason", lib_->errorString());
			close();
			return false;
		}

		return true;
	}

	bool
	DynamicLibrary::close(void)
	{
		if (lib_ == nullptr) return true;
		delete lib_;
		lib_ = nullptr;
		return false;
	}

	bool
	DynamicLibrary::get(const std::string& functionName, void **ptr)
	{
		if (lib_ == nullptr) {
			Log(Error, "cannot load library function, because library is not open")
				.parameter("ModulName", moduleName_)
				.parameter("FunctionName", functionName);
			return false;
		}

		bool rc = lib_->get(functionName, ptr);
		if (!rc) {
			Log(Error, "load library function error")
			.parameter("FunctionName", functionName)
			.parameter("ErrorString", lib_->errorString());
			return false;
		}

		return true;
	}

}
