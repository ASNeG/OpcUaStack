#ifndef __OpcUaStackCore_AddNodesResponse_h__
#define __OpcUaStackCore_AddNodesResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/AddNodesResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AddNodesResponse : public  ObjectPool<AddNodesResponse>
	{
	  public:
		AddNodesResponse(void);
		virtual ~AddNodesResponse(void);

		void results(const AddNodesResultArray::SPtr addNodesResultArraySPtr);
		AddNodesResultArray::SPtr results() const;

		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfosSPtr);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;
	
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		  AddNodesResultArray::SPtr addNodesResultArraySPtr_;
		  OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

}

#endif
