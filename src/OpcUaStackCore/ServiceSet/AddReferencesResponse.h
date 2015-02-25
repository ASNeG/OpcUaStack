#ifndef __OpcUaStackCore_AddReferencesResponse_h__
#define __OpcUaStackCore_AddReferencesResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/AddReferencesResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AddReferencesResponse : public  ObjectPool<AddReferencesResponse>
	{
	  public:
		typedef boost::shared_ptr<AddReferencesResponse> SPtr;

		AddReferencesResponse(void);
		virtual ~AddReferencesResponse(void);

		void results(const AddReferencesResultArray::SPtr addReferencesResultArraySPtr);
		AddReferencesResultArray::SPtr results() const;

		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfosSPtr);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;
	
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		  AddReferencesResultArray::SPtr addReferencesResultArraySPtr_;
		  OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

}

#endif
