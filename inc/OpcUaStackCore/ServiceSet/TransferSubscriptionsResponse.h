#ifndef __OpcUaStackCore_TransferSubscriptionsResponse_h__
#define __OpcUaStackCore_TransferSubscriptionsResponse_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/TransferResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT TransferSubscriptionsResponse : public ObjectPool<TransferSubscriptionsResponse>
	{
	  public:
	    TransferSubscriptionsResponse(void);
		~TransferSubscriptionsResponse(void);

		void results(const TransferResultArray::SPtr results);
		TransferResultArray::SPtr results(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		TransferResultArray::SPtr transferResultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};
}

#endif