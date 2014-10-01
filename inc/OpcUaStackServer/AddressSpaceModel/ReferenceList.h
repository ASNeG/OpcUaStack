#ifndef __OpcUaStackServer_ReferenceList_h__
#define __OpcUaStackServer_ReferenceList_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildinTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ReferenceItem : public ObjectPool<ReferenceItem>
	{
	  public:
		ReferenceItem(void);
		~ReferenceItem(void);

		OpcUaNodeId nodeId_;
		bool forward_;
		OpcUaNodeId referenceTypeId_;
	};

	typedef std::list<ReferenceItem::SPtr> ReferenceItemList;

	class DLLEXPORT ReferenceList : public ObjectPool<ReferenceList>
	{
	  public:
		ReferenceList(void);
		~ReferenceList(void);

		ReferenceItemList referenceItemList_;
	};

}

#endif