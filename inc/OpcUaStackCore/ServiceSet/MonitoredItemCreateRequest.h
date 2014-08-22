#ifndef __OpcUaStackCore_MonitoredItemCreateRequest_h__
#define __OpcUaStackCore_MonitoredItemCreateRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ReadValueId.h"
#include "OpcUaStackCore/ServiceSet/MonitoringParameters.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	typedef enum {
		MonitoringMode_Disabled = 0,
		MonitoringMode_Sampling = 1,
		MonitoringMode_Reporting = 2
	} MonitoringMode;

	class DLLEXPORT MonitoredItemCreateRequest : public  ObjectPool<MonitoredItemCreateRequest>
	{
	  public:
		MonitoredItemCreateRequest(void);
		virtual ~MonitoredItemCreateRequest(void);

		void itemToMonitor(const ReadValueId& itemToMonitor);
		ReadValueId& itemToMonitor(void);
		void monitoringMode(const MonitoringMode& monitoringMode);
		MonitoringMode& monitoringMode(void);
		void requestedParameters(const MonitoringParameters& requestedParameters);
		MonitoringParameters& requestedParameters(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ReadValueId itemToMonitor_;
		MonitoringMode monitoringMode_;
		MonitoringParameters requestedParameters_;
	};

	class MonitoredItemCreateRequestArray : public OpcUaArray<MonitoredItemCreateRequest::SPtr, SPtrTypeCoder<MonitoredItemCreateRequest> >, public ObjectPool<MonitoredItemCreateRequestArray> {};

}

#endif