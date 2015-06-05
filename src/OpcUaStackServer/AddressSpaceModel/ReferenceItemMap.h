#ifndef __OpcUaStackServer_ReferenceItemMap_h__
#define __OpcUaStackServer_ReferenceItemMap_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceType.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceItem.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef std::multimap<OpcUaNodeId, ReferenceItem::SPtr> ReferenceItemMultiMap;

	class DLLEXPORT ReferenceItemMap : public ObjectPool<ReferenceItemMap>
	{
	  public:
		typedef boost::shared_ptr<ReferenceItemMap> SPtr;

		ReferenceItemMap(void);
		~ReferenceItemMap(void);

		bool add(ReferenceType referenceType, ReferenceItem::SPtr referenceItem);
		bool add(ReferenceType referenceType, bool isForward, OpcUaNodeId& nodeId);
		bool add(OpcUaNodeId& referenceTypeNodeId, ReferenceItem::SPtr referenceItem);
		bool add(OpcUaNodeId& referenceTypeNodeId, bool isForward, OpcUaNodeId& nodeId);

		bool remove(OpcUaNodeId& referenceTypeNodeId, ReferenceItem::SPtr referenceItem);
		bool remove(OpcUaNodeId& referenceTypeNodeId, OpcUaNodeId& nodeId);

		ReferenceItemMultiMap& referenceItemMultiMap(void);

		void copyTo(ReferenceItemMap::SPtr referenceItemMap);
		void copyTo(ReferenceItemMap& referenceItemMap);

	  private:
		ReferenceItemMultiMap referenceItemMultiMap_;
	};

}

#endif
