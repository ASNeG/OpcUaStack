#ifndef __OpcUaStackServer_ViewServiceSet_h__
#define __OpcUaStackServer_ViewServiceSet_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransactionIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ViewServiceSet : public ServiceTransactionIf
	{
	  public:
		ViewServiceSet(void);
		~ViewServiceSet(void);

		//- ServiceTransactionIf ------------------------------------------------------
		void receive(OpcUaNodeId& typeId, ServiceTransaction::SPtr serviceTransaction);
		//- ServiceTransactionIf ------------------------------------------------------

	  private:
	};

}

#endif