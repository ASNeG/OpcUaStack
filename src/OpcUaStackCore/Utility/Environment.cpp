#include <boost/filesystem.hpp>
#include "OpcUaStackCore/Utility/Environment.h"

namespace OpcUaStackCore
{

	Environment::Environment(void)
	{
	}

	Environment::~Environment(void)
	{
	}

	std::string
	Environment::getInstallationPath(const std::string& binaryDirectory)
	{
		std::string application = "";
#ifdef WIN32
		  char result[2048];
		  application = std::string( result, GetModuleFileName(NULL, result, 2048));
#else
		char result[2048];
		ssize_t count = readlink("/proc/self/exe", result, 2048);
		application = std::string( result, (count > 0) ? count : 0 );
#endif
		if (application == "") return "";

		boost::filesystem::path applicationPath(application);
		applicationPath = applicationPath.parent_path();

		boost::filesystem::path binaryPath(binaryDirectory);

		while (binaryPath.begin() != binaryPath.end()) {
			if (applicationPath.leaf() != binaryPath.leaf()) {
				applicationPath = "invalid_application_path";
				break;
			}
			applicationPath.remove_leaf();
			binaryPath.remove_leaf();
		}
		return applicationPath.string();
	}

	std::string 
	Environment::getCurrentPath(void)
	{
		return boost::filesystem::current_path().string();
	}
	
	void 
	Environment::setCurrentPath(const std::string& currentPath)
	{
		boost::filesystem::path path(currentPath);
		boost::filesystem::current_path(path);
	}

	std::string 
	Environment::getAbsolutePath(const std::string& relativePath)
	{
		boost::filesystem::path path(relativePath);
		return boost::filesystem::absolute(path).string();
	}

}
