#ifndef __OpcUaStackCore_Library_h__
#define __OpcUaStackCore_Library_h__

#include "OpcUaStackCore/Base/os.h"
#include <string>

namespace OpcUaStackCore
{

	class LibraryModul;
	class DLLEXPORT Library
	{
	  public:
		Library(void);
		~Library(void);

		bool openLibrary(const std::string& libraryName);
		bool closeLibrary(void);
		bool getFunctionPtr(const std::string& functionName, void **ptr);

	  private:
		LibraryModul *libraryModul_;
	};

}

#endif