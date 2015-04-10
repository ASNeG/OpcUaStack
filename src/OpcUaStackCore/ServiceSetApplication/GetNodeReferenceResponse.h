#ifndef __OpcUaStackCore_GetNodeReferenceResponse_h__
#define __OpcUaStackCore_GetNodeReferenceResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSetApplication/NodeReference.h"

namespace OpcUaStackCore
{

	class DLLEXPORT GetNodeReferenceResponse : public ObjectPool<GetNodeReferenceResponse>
	{
	  public:
		typedef boost::shared_ptr<GetNodeReferenceResponse> SPtr;

	    GetNodeReferenceResponse(void);
		virtual ~GetNodeReferenceResponse(void);

		void nodeReferenceArray(const NodeReferenceArray::SPtr nodeReferenceArray);
		NodeReferenceArray::SPtr nodeReferenceArray(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		NodeReferenceArray::SPtr nodeReferenceArray_;
	};
}

#endif
