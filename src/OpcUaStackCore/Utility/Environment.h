#ifndef __OpcUaStackCore_Environment_h__
#define __OpcUaStackCore_Environment_h__

#include "OpcUaStackCore/Base/os.h"
#include <string>

namespace OpcUaStackCore
{

	class DLLEXPORT Environment
	{
	  public:
		Environment(void);
		~Environment(void);

		static std::string installDir_;
		static std::string binDir_;
		static std::string confDir_;
		static std::string logDir_;

		static std::string getInstallationPath(const std::string& binaryDirectory);
		static std::string getCurrentPath(void);
		static void setCurrentPath(const std::string& currentPath);
		static std::string getAbsolutePath(const std::string& relativePath);

		static void installDir(const std::string& installDir);
		static std::string& installDir(void);
		static void binDir(const std::string& binDir);
		static std::string& binDir(void);
		static void confDir(const std::string& confDir);
		static std::string& confDir(void);
		static void logDir(const std::string& logDir);
		static std::string& logDir(void);
	};

}

#endif
