#include "OpcUaServer/ApplicationLibrary/ApplicationLibrary.h"

namespace OpcUaServer
{

	ApplicationLibrary::ApplicationLibrary(void)
	: moduleName_("")
	, dynamicLibrary_()
	, initFunction_(nullptr)
	{
	}

	ApplicationLibrary::~ApplicationLibrary(void)
	{
	}

	void
	ApplicationLibrary::moduleName(const std::string& moduleName)
	{
		moduleName_ = moduleName;
	}

	ApplicationLibrary::InitFunction*
	ApplicationLibrary::initFunction(void)
	{
		return initFunction_;
	}

	bool
	ApplicationLibrary::startup(void)
	{
		// load library
		if (!dynamicLibrary_.open(moduleName_)) {
			return false;
		}

		// load init function
		if (!dynamicLibrary_.get("init", (void**)&initFunction_)) {
			return false;
		}

		return true;
	}

	bool
	ApplicationLibrary::shutdown(void)
	{
		if (!dynamicLibrary_.close()) {
			return false;
		}
		return true;
	}

}
