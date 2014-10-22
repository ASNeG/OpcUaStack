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