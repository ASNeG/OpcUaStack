#ifndef __OpcUaStackCore_CreateMonitoredItemsResponse_h__
#define __OpcUaStackCore_CreateMonitoredItemsResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemCreateResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CreateMonitoredItemsResponse : public  ObjectPool<CreateMonitoredItemsResponse>
	{
	  public:
		CreateMonitoredItemsResponse(void);
		virtual ~CreateMonitoredItemsResponse(void);

		void results(const MonitoredItemCreateResultArray::SPtr results);
		MonitoredItemCreateResultArray::SPtr results(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		MonitoredItemCreateResultArray::SPtr resultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

}

#endif