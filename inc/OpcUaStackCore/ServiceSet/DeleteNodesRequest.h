#ifndef __OpcUaStackCore_DeleteNodesRequest_h__
#define __OpcUaStackCore_DeleteNodesRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/DeleteNodesItem.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DeleteNodesRequest : public  ObjectPool<DeleteNodesRequest>
	{
	  public:
		DeleteNodesRequest(void);
		virtual ~DeleteNodesRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void nodesToDelete(const DeleteNodesItemArray::SPtr deleteNodesItemArraySPtr);
		DeleteNodesItemArray::SPtr nodesToDelete() const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		DeleteNodesItemArray::SPtr deleteNodesItemArraySPtr_;
	};

}

#endif
