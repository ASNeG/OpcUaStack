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
#if WIN32

#include <Windows.h>

	class Lib
	{
	  public:
		bool open(const std::string& libraryName) {

			std::string libName = libraryName + std::string(".dll");
			if (libName.length() > 999) return false;

			handle_ = LoadLibrary(libName.c_str());
			if (handle_ == nullptr) return false;
			return true;
		}

		bool close(void) {
			BOOL rc = FreeLibrary(handle_);
			return rc == TRUE;
		}

		bool get(const std::string& functionName, void **ptr) {
			*ptr = GetProcAddress(handle_, functionName.c_str());
			if (*ptr == nullptr) return false;
			return true;
		}

		std::string errorString(void)
		{
			return "unknown";
		}

	  private:
	    HMODULE handle_;
	};

#else

#include <dlfcn.h>

	class Lib
	{
	  public:
		bool open(const std::string& libraryName) {

			errorString_ = "unknown";
			std::string libName = libraryName + std::string(".so");
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
		}
		return true;
	}

}
