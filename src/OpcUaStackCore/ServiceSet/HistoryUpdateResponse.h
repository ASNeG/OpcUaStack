#ifndef __OpcUaStackCore_HistoryUpdateResponse_h__
#define __OpcUaStackCore_HistoryUpdateResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/HistoryUpdateResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryUpdateResponse : public  ObjectPool<HistoryUpdateResponse>
	{
	  public:
		typedef boost::shared_ptr<HistoryUpdateResponse> SPtr;

		HistoryUpdateResponse(void);
		virtual ~HistoryUpdateResponse(void);

		void results(const HistoryUpdateResultArray::SPtr results);
		HistoryUpdateResultArray::SPtr results(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeaderSPtr_;
		HistoryUpdateResultArray::SPtr resultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

}

#endif