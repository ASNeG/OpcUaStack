#ifndef __OpcUaStackCore_HistoryReadResponse_h__
#define __OpcUaStackCore_HistoryReadResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/HistoryReadResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryReadResponse : public  ObjectPool<HistoryReadResponse>
	{
	  public:
		HistoryReadResponse(void);
		virtual ~HistoryReadResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeaderSPtr);
		ResponseHeader::SPtr responseHeader(void) const;
		void results(const HistoryReadResultArray::SPtr results);
		HistoryReadResultArray::SPtr results(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeaderSPtr_;
		HistoryReadResultArray::SPtr resultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

}

#endif