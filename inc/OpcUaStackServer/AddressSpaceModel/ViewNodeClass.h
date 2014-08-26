#ifndef __OpcUaStackServer_ViewNodeClass_h__
#define __OpcUaStackServer_ViewNodeClass_h__

#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class ViewNodeClass : public BaseNodeClass
	{
	  public:
		ViewNodeClass(void);
		~ViewNodeClass(void);

	  private:
		// attributes mandatory
		OpcUaBoolean containsNoLoops_;
		OpcUaByte eventNotifier_;

		// references
		OpcUaNodeIdList hierarchicalReferences_;
		OpcUaNodeIdList hasProperty_;

		// standard properties
		OpcUaString nodeVersion_;  // optional
		OpcUaUInt32 viewVersion_; // optional
	};

}

#endif