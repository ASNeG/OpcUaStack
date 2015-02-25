#ifndef __OpcUaStackCore_HistoryEvent_h__
#define __OpcUaStackCore_HistoryEventh__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"
#include "OpcUaStackCore/ServiceSet/HistoryEventFieldList.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryEvent : public  ObjectPool<HistoryEvent>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<HistoryEvent> SPtr;

		HistoryEvent(void);
		virtual ~HistoryEvent(void);

		void events(const HistoryEventFieldListArray::SPtr events);
		HistoryEventFieldListArray::SPtr events(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		HistoryEventFieldListArray::SPtr eventArraySPtr_;
	};

}

#endif