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

		ContainsNoLoopsAttribute& containsNoLoops(void);
		EventNotifierAttribute& eventNotifier(void);

	  private:
		// attributes mandatory
		ContainsNoLoopsAttribute containsNoLoops_;
		EventNotifierAttribute eventNotifier_;

		// references
		OpcUaNodeIdList hierarchicalReferences_;
		OpcUaNodeIdList hasProperty_;

		// standard properties
		OpcUaString nodeVersion_;  // optional
		OpcUaUInt32 viewVersion_; // optional
	};

}

#endif