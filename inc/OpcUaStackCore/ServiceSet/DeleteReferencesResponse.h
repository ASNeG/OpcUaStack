#ifndef __OpcUaStackCore_DeleteReferencesResponse_h__
#define __OpcUaStackCore_DeleteReferencesResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/DeleteReferencesResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DeleteReferencesResponse : public  ObjectPool<DeleteReferencesResponse>
	{
	  public:
		DeleteReferencesResponse(void);
		virtual ~DeleteReferencesResponse(void);

		void results(const DeleteReferencesResultArray::SPtr deleteReferencesResultArraySPtr);
		DeleteReferencesResultArray::SPtr results() const;

		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfosSPtr);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;
	
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		  DeleteReferencesResultArray::SPtr deleteReferencesResultArraySPtr_;
		  OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

}

#endif
