#ifndef __OpcUaStackServer_ViewNodeClass_h__
#define __OpcUaStackServer_ViewNodeClass_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ViewNodeClass : public BaseNodeClass, public ObjectPool<ViewNodeClass>
	{
	  public:
		typedef boost::shared_ptr<ViewNodeClass> SPtr;

		ViewNodeClass(void);
		~ViewNodeClass(void);

		ContainsNoLoopsAttribute& containsNoLoops(void);
		EventNotifierAttribute& eventNotifier(void);

		Attribute* containsNoLoopsAttribute(void);
		Attribute* eventNotifierAttribute(void);

		void addReference(ReferenceType referenceType, OpcUaNodeId& opcUaNodeId);
		void getReference(OpcUaNodeIdList& list, ReferenceType referenceType);

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