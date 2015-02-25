#ifndef __OpcUaStackCore_MonitoredItemModifyRequest_h__
#define __OpcUaStackCore_MonitoredItemModifyRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/MonitoringParameters.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT MonitoredItemModifyRequest : public  ObjectPool<MonitoredItemModifyRequest>
	{
	  public:
		typedef boost::shared_ptr<MonitoredItemModifyRequest> SPtr;

		MonitoredItemModifyRequest(void);
		virtual ~MonitoredItemModifyRequest(void);

		void monitoredItemId(const OpcUaUInt32& monitoredItemId);
		OpcUaUInt32 monitoredItemId(void) const;
		void requestedParameters(const MonitoringParameters& requestedParameters);
		MonitoringParameters& requestedParameters(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 monitoredItemId_;
		MonitoringParameters requestedParameters_;
	};

	class MonitoredItemModifyRequestArray : public OpcUaArray<MonitoredItemModifyRequest::SPtr, SPtrTypeCoder<MonitoredItemModifyRequest> >, public ObjectPool<MonitoredItemModifyRequestArray> 
	{
	  public:
		typedef boost::shared_ptr<MonitoredItemModifyRequestArray> SPtr;
	};

}

#endif