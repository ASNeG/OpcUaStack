#ifndef __OpcUaStackClient_AttributeService_h__
#define __OpcUaStackClient_AttributeService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/Session.h"

namespace OpcUaStackClient
{

	class AttributeService
	{
	  public:
		AttributeService(void);
		~AttributeService(void);

		void session(Session::SPtr session);

	  private:
		Session::SPtr session_;
	};

}

#endif