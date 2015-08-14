#ifndef __OpcUaStackClient_Client_h__
#define __OpcUaStackClient_Client_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackClient/ServiceSet/SessionManager.h"

namespace OpcUaStackClient
{

	class DLLEXPORT Client
	: public OpcUaStackCore::Core
	{
	  public:
		Client(void);
	    ~Client(void);

		bool init(void);
		void shutdown(void);
		bool start(void);
		void stop(void);

		SessionManager& sessionManager(void);

	  public:
		SessionManager sessionManager_;
	};

}

#endif
