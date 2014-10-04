#ifndef __OpcUaStackCore_OpcUaNodeId_h__
#define __OpcUaStackCore_OpcUaNodeId_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeIdBase.h"
#include "OpcUaStackCore/Base/os.h"
#include <list>
#include <boost/shared_ptr.hpp>

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaNodeId : public ObjectPool<OpcUaNodeId>, public OpcUaNodeIdBase
	{
	  public:
	    OpcUaNodeId(void);
		virtual ~OpcUaNodeId(void);
	};

	class OpcUaNodeSPtrCompare
	{
	  public:
		bool operator()(const OpcUaNodeId::SPtr a, const OpcUaNodeId::SPtr b) {
			if (a.get() == nullptr && b.get() != nullptr) return true;
			if (a.get() != nullptr && b.get() == nullptr) return false;
			if (a.get() == nullptr && b.get() == nullptr) return false;
			return *a < *b;
		}
	};

	class OpcUaNodeIdArray : public OpcUaArray<OpcUaNodeId::SPtr, SPtrTypeCoder<OpcUaNodeId> >, public ObjectPool<OpcUaNodeIdArray> {};

	typedef std::list<OpcUaNodeId> OpcUaNodeIdList;

}

#endif
