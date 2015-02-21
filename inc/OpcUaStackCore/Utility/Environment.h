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

		static std::string getInstallationPath(const std::string& binaryDirectory);
		static std::string getCurrentPath(void);
		static void setCurrentPath(const std::string& currentPath);
		static std::string getAbsolutePath(const std::string& relativePath);
	};

}

#endif
