#include "OpcUaStackCore/Utility/Library.h"

namespace OpcUaStackCore
{

#if _WIN32

#include <Windows.h>

	class LibraryModul
	{
	  public:
		bool openLibrary(const std::string& libraryName) {

			if (libraryName.length() > 999) return false;

			handle_ = LoadLibrary(libraryName.c_str());
			if (handle_ == nullptr) return false;
			return true;
		}

		bool closeLibrary(void) {
			BOOL rc = FreeLibrary(handle_);
			return rc == TRUE;
		}

		bool getFunctionPtr(const std::string& functionName, void **ptr) {
			*ptr = GetProcAddress(handle_, functionName.c_str());
			if (*ptr == nullptr) return false;
			return true;
		}

	  private:
	    HMODULE handle_;
	};

#else

#include <dlfcn.h>

	class LibraryModul
	{
	  public:
		bool openLibrary(const std::string& libraryName) {

			if (libraryName.length() > 999) return false;
			handle_ = dlopen(libraryName.c_str(), RTLD_LAZY);
			if (handle_ == nullptr) return false;
			return true;
		}

		bool closeLibrary(void) {
			return true;
		}

		bool getFunctionPtr(const std::string& functionName, void **ptr) {
			*ptr = dlsym(handle_, functionName.c_str());
			if (*ptr == nullptr) return false;
			return true;
		}

	  private:
		void *handle_;
	};

#endif

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// Library
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	Library::Library(void)
	{
		libraryModul_ = new LibraryModul();
	}

	Library::~Library(void)
	{
		delete libraryModul_;
		libraryModul_ = nullptr;
	}

	bool 
	Library::openLibrary(const std::string& libraryName)
	{
		return libraryModul_->openLibrary(libraryName);
	}

	bool
	Library::closeLibrary(void)
	{
		return libraryModul_->closeLibrary();
	}

	bool 
	Library::getFunctionPtr(const std::string& functionName, void **ptr)
	{
		return libraryModul_->getFunctionPtr(functionName, ptr);
	}

}
