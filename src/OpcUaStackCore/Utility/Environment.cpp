
/*
   Copyright 2015-2016 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include "OpcUaStackCore/Utility/Environment.h"

#ifdef _WIN32
#include <Windows.h>
#endif

namespace OpcUaStackCore
{

	std::string Environment::confDir_ = "";

	Environment::Environment(void)
	{
	}

	Environment::~Environment(void)
	{
	}

	std::string
	Environment::hostname(void)
	{
		return boost::asio::ip::host_name();
	}

	std::vector<boost::asio::ip::address>
	Environment::ips(void)
	{
		std::vector<boost::asio::ip::address> ipVec;

		boost::asio::io_service io_service;
		boost::asio::ip::tcp::resolver resolver(io_service);
		boost::asio::ip::tcp::resolver::query query(boost::asio::ip::host_name(), "");
		boost::asio::ip::tcp::resolver::iterator iter = resolver.resolve(query);
		boost::asio::ip::tcp::resolver::iterator end;
		while (iter != end)
		{
			boost::asio::ip::tcp::endpoint ep = *iter++;
			ipVec.push_back(ep.address());
		}
		return ipVec;
	}

	std::string
	Environment::getApplicationPathAbsolute(void)
	{
 		std::string application = "";
#ifdef _WIN32
		  char result[2048];
		  application = std::string( result, GetModuleFileName(NULL, result, 2048));
#else
		char result[2048];
		ssize_t count = readlink("/proc/self/exe", result, 2048);
		application = std::string( result, (count > 0) ? count : 0 );
#endif
		if (application == "") return "";
		return application;
	}

	std::string
	Environment::getInstallationPathRelative(
		const std::string& binaryDirectory
	)
	{
		std::string application = "";
#ifdef _WIN32
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
	Environment::confDir(const std::string& confDir)
	{
		confDir_ = confDir;
	}

	std::string&
	Environment::confDir(void)
	{
		return confDir_;
	}


	std::string
	Environment::subst(const std::string& string)
	{
		std::string str = string;
		boost::replace_all(str, "@CONF_DIR@", confDir_);
		return str;
	}

}
