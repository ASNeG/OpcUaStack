#ifndef __OpcUaStackCore_GetNodeReferenceResponse_h__
#define __OpcUaStackCore_GetNodeReferenceResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	class DLLEXPORT GetNodeReferenceResponse : public ObjectPool<GetNodeReferenceResponse>
	{
	  public:
		typedef boost::shared_ptr<GetNodeReferenceResponse> SPtr;

	    GetNodeReferenceResponse(void);
		virtual ~GetNodeReferenceResponse(void);

		void statusCodeArray(const OpcUaStatusCodeArray::SPtr statusCodeArray);
		OpcUaStatusCodeArray::SPtr statusCodeArray(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCodeArray::SPtr statusCodeArraySPtr_;
	};
}

#endif
