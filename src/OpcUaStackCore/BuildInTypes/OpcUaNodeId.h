#ifndef __OpcUaStackCore_OpcUaNodeId_h__
#define __OpcUaStackCore_OpcUaNodeId_h__

#include <boost/shared_ptr.hpp>
#include <boost/optional/optional.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeIdBase.h"
#include "OpcUaStackCore/Base/os.h"
#include <list>
#include <vector>

namespace OpcUaStackCore
{

	class DLLEXPORT OpcUaNodeId : public ObjectPool<OpcUaNodeId>, public OpcUaNodeIdBase
	{
	  public:
		typedef boost::optional<OpcUaNodeId&> Opt;
		typedef boost::shared_ptr<OpcUaNodeId> SPtr;
		typedef std::vector<OpcUaNodeId::SPtr> Vec;

	    OpcUaNodeId(void);
		virtual ~OpcUaNodeId(void);
	};

	class OpcUaNodeSPtrLess
	{
	  public:
		bool operator()(const OpcUaNodeId::SPtr a, const OpcUaNodeId::SPtr b) {
			if (a.get() == nullptr && b.get() != nullptr) return true;
			if (a.get() != nullptr && b.get() == nullptr) return false;
			if (a.get() == nullptr && b.get() == nullptr) return false;
			return *a < *b;
		}
	};

	class OpcUaNodeIdArray : public OpcUaArray<OpcUaNodeId::SPtr, SPtrTypeCoder<OpcUaNodeId> >, public ObjectPool<OpcUaNodeIdArray> 
	{
	  public:
		typedef boost::shared_ptr<OpcUaNodeIdArray> SPtr;
	};

	typedef std::list<OpcUaNodeId> OpcUaNodeIdList;

}

#endif
