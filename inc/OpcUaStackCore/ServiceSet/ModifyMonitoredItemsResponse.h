#ifndef __OpcUaStackCore_ModifyMonitoredItemsResponse_h__
#define __OpcUaStackCore_ModifyMonitoredItemsResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemModifyResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ModifyMonitoredItemsResponse : public  ObjectPool<ModifyMonitoredItemsResponse>
	{
	  public:
		ModifyMonitoredItemsResponse(void);
		virtual ~ModifyMonitoredItemsResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void) const;
		void results(const MonitoredItemModifyResultArray::SPtr results);
		MonitoredItemModifyResultArray::SPtr results(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeaderSPtr_;
		MonitoredItemModifyResultArray::SPtr resultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

}

#endif