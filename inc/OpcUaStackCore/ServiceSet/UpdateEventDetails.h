#ifndef __OpcUaStackCore_UpdateEventDetails_h__
#define __OpcUaStackCore_UpdateEventDetails_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"
#include "OpcUaStackCore/ServiceSet/EventFilter.h"
#include "OpcUaStackCore/ServiceSet/EventFieldList.h"
#include "OpcUaStackCore/ServiceSet/PerformUpdateEnumeration.h"

namespace OpcUaStackCore
{

	class DLLEXPORT UpdateEventDetails : public  ObjectPool<UpdateEventDetails>, public ExtensibleParameterBase
	{
	  public:
		UpdateEventDetails(void);
		virtual ~UpdateEventDetails(void);

		void nodeId(const OpcUaNodeId& nodeId);
		OpcUaNodeId& nodeId(void);
		void performInsertReplace(const PerformUpdateEnumeration performInsertReplace);
		PerformUpdateEnumeration performInsertReplace(void);
		void filter(const EventFilter& filter);
		EventFilter& filter(void);
		void eventData(const EventFieldListArray::SPtr eventData);
		EventFieldListArray::SPtr eventData(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaNodeId nodeId_;
		PerformUpdateEnumeration performInsertReplace_;
		EventFilter filter_;
		EventFieldListArray::SPtr eventDataArraySPtr_; // TODO Check Type.
	};

}

#endif