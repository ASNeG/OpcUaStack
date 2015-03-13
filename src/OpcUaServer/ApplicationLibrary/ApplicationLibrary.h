#ifndef __OpcUaServer_ApplicationLibrary_h__
#define __OpcUaServer_ApplicationLibrary_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaServer/ApplicationLibrary/DynamicLibrary.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaServer
{

	class ApplicationLibrary
	: public  ObjectPool<ApplicationLibrary>
	{
	  public:
		typedef boost::shared_ptr<ApplicationLibrary> SPtr;
		typedef ApplicationIf* InitFunction(void);

		ApplicationLibrary(void);
		~ApplicationLibrary(void);

		void moduleName(const std::string& moduleName);
		InitFunction* initFunction(void);

		bool startup(void);
		bool shutdown(void);

	  private:
		InitFunction* initFunction_;
		std::string moduleName_;
		DynamicLibrary dynamicLibrary_;
	};

}

#endif
