#ifndef __OpcUaStackCore_EventNotificationList_h__
#define __OpcUaStackCore_EventNotificationList_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/EventFieldList.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EventNotificationList : public  ObjectPool<EventNotificationList>, public ExtensibleParameterBase
	{
	  public:
		EventNotificationList(void);
		virtual ~EventNotificationList(void);

		void events(const EventFieldListArray::SPtr events);
		EventFieldListArray::SPtr events(void) const;
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		EventFieldListArray::SPtr eventFieldListArraySPtr_;
	};

}

#endif