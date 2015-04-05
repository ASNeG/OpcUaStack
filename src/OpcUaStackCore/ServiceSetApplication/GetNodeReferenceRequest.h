#ifndef __OpcUaStackCore_GetNodeReferenceRequest_h__
#define __OpcUaStackCore_GetNodeReferenceRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT GetNodeReferenceRequest : public  ObjectPool<GetNodeReferenceRequest>
	{
	  public:
		typedef boost::shared_ptr<GetNodeReferenceRequest> SPtr;

		GetNodeReferenceRequest(void);
		virtual ~GetNodeReferenceRequest(void);

		void nodes(const OpcUaNodeIdArray::SPtr nodes);
		OpcUaNodeIdArray::SPtr nodes(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeIdArray::SPtr nodes_;
	};

}

#endif
