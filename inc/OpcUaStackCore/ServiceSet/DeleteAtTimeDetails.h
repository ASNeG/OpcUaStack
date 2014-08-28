#ifndef __OpcUaStackCore_DeleteAtTimeDetails_h__
#define __OpcUaStackCore_DeleteAtTimeDetails_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DeleteAtTimeDetails : public  ObjectPool<DeleteAtTimeDetails>, public ExtensibleParameterBase
	{
	  public:
		DeleteAtTimeDetails(void);
		virtual ~DeleteAtTimeDetails(void);

		void nodeId(const OpcUaNodeId& nodeId);
		OpcUaNodeId& nodeId(void);
		void reqTimes(const UtcTimeArray::SPtr reqTime);
		UtcTimeArray::SPtr reqTimes(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaNodeId nodeId_;
		UtcTimeArray::SPtr reqTimeArraySPtr_;
	};

}

#endif