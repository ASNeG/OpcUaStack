#ifndef __OpcUaStackCore_DeleteNodesResponse_h__
#define __OpcUaStackCore_DeleteNodesResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/DeleteNodesResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DeleteNodesResponse : public  ObjectPool<DeleteNodesResponse>
	{
	  public:
		DeleteNodesResponse(void);
		virtual ~DeleteNodesResponse(void);

		void results(const DeleteNodesResultArray::SPtr deleteNodesResultArraySPtr);
		DeleteNodesResultArray::SPtr results() const;

		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfosSPtr);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;
	
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		  DeleteNodesResultArray::SPtr deleteNodesResultArraySPtr_;
		  OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

}

#endif
