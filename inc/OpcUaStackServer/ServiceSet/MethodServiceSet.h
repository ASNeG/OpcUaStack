#ifndef __OpcUaStackServer_MethodServiceSet_h__
#define __OpcUaStackServer_MethodServiceSet_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT MethodServiceSet : public ServiceTransactionIf
	{
	  public:
		MethodServiceSet(void);
		~MethodServiceSet(void);

		//- ServiceTransactionIf ------------------------------------------------------
		void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceTransactionIf ------------------------------------------------------

	  private:
	};

}

#endif