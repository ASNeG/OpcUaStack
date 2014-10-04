#ifndef __OpcUaStackServer_DummyNodeClass_h__
#define __OpcUaStackServer_DummyNodeClass_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT DummyNodeClass : public BaseNodeClass, public ObjectPool<DummyNodeClass>
	{
	  public:
		typedef boost::shared_ptr<DummyNodeClass> SPtr;

		DummyNodeClass(void);
		~DummyNodeClass(void);
	};

}

#endif