#ifndef __OpcUaStackServer_ApplicationServiceIf_h__
#define __OpcUaStackServer_ApplicationServiceIf_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Callback.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationServiceIf
	{
	  public:
		ApplicationServiceIf(void) {}
		virtual ~ApplicationServiceIf(void) {}

		virtual void send(ServiceTransaction::SPtr serviceTransaction) = 0;
		virtual void sendSync(ServiceTransaction::SPtr serviceTransaction) = 0;
	};

}

#endif
