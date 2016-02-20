#include <boost/filesystem.hpp>
#include "OpcUaStackCore/Utility/Environment.h"

#ifdef WIN32
#include <Windows.h>
#endif

namespace OpcUaStackCore
{

	std::string Environment::installDir_ = "";
	std::string Environment::binDir_ = "";
	std::string Environment::confDir_ = "";
	std::string Environment::logDir_ = "";

	Environment::Environment(void)
	{
	}

	Environment::~Environment(void)
	{
	}

	std::string
	Environment::getInstallationPathRelative(
		const std::string& binaryDirectory
	)
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
				applicationPath = "invalid_installation_path";
				break;
			}
			applicationPath.remove_leaf();
			binaryPath.remove_leaf();
		}
		return applicationPath.string();
	}

	std::string
	Environment::getInstallationPathAbsolute(
		const std::string& serviceName,
		const std::string& configFileName,
		const std::string& confDirectory
	)
	{
		boost::filesystem::path confFilePath(configFileName);
		boost::filesystem::path confPath(confDirectory);

		confFilePath = confFilePath.branch_path();

		if (confFilePath.leaf().string() != serviceName) {
			return std::string("invalid_installation_path_1");
		}
		confFilePath.remove_leaf();

		while (confPath.begin() != confPath.end()) {
			if (confFilePath.leaf() != confPath.leaf()) {
				return "invalid_installation_path_2";
			}
			confFilePath.remove_leaf();
			confPath.remove_leaf();
		}

		return confFilePath.string();
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

	void
	Environment::installDir(const std::string& installDir)
	{
		installDir_ = installDir;
	}

	std::string&
	Environment::installDir(void)
	{
		return installDir_;
	}

	void
	Environment::binDir(const std::string& binDir)
	{
		binDir_ = binDir;
	}

	std::string&
	Environment::binDir(void)
	{
		return binDir_;
	}

	void
	Environment::confDir(const std::string& confDir)
	{
		confDir_ = confDir;
	}

	std::string&
	Environment::confDir(void)
	{
		return confDir_;
	}

	void
	Environment::logDir(const std::string& logDir)
	{
		logDir_ = logDir;
	}

	std::string&
	Environment::logDir(void)
	{
		return logDir_;
	}

}
