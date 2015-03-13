#ifndef __OpcUaServer_DynamicLibrary_h__
#define __OpcUaServer_DynamicLibrary_h__

#include "OpcUaStackCore/Base/os.h"
#include <string>

namespace OpcUaServer
{

	class Lib;
	class DynamicLibrary
	{
	  public:


		DynamicLibrary(void);
		~DynamicLibrary(void);

		bool isOpen(void);
		bool open(const std::string& moduleName);
		bool close(void);

		bool get(const std::string& functionName, void **ptr);

	  private:
		std::string moduleName_;
		Lib* lib_;
	};

}

#endif
