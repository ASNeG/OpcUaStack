#ifndef __OpcUaStackCore_Core_h__
#define __OpcUaStackCore_Core_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"

namespace OpcUaStackCore
{

	class DLLEXPORT Core
	{
	  public:
		Core(void);
		~Core(void);

		void config(Config& config);
		Config& config(void);

		bool init(void);
		void cleanup(void);

	  private:
		void initExtensibleParameter(void);
		void cleanupExtensibleParameter(void);

		Config* config_;
	};

}

#endif