#ifndef __OpcUaStackClient_Client_h__
#define __OpcUaStackClient_Client_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Core/Core.h"

namespace OpcUaStackClient
{

	class DLLEXPORT Client
	: public OpcUaStackCore::Core
	{
		Client(void);
	    ~Client(void);

		bool init(void);
		void cleanup(void);
		bool start(void);
		void stop(void);
	};

}

#endif