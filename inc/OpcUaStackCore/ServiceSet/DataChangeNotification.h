#ifndef __OpcUaStackCore_DataChangeNotification_h__
#define __OpcUaStackCore_DataChangeNotification_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemNotification.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DataChangeNotification : public  ObjectPool<DataChangeNotification>, public ExtensibleParameterBase
	{
	  public:
		DataChangeNotification(void);
		virtual ~DataChangeNotification(void);

		void monitoredItems(const MonitoredItemNotificationArray::SPtr monitoredItems);
		MonitoredItemNotificationArray::SPtr monitoredItems(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		MonitoredItemNotificationArray::SPtr monitoredItemNotificationArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};
}

#endif