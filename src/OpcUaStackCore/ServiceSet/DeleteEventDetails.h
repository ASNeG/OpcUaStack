#ifndef __OpcUaStackCore_DeleteEventDetails_h__
#define __OpcUaStackCore_DeleteEventDetails_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT DeleteEventDetails : public  ObjectPool<DeleteEventDetails>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<DeleteEventDetails> SPtr;

		DeleteEventDetails(void);
		virtual ~DeleteEventDetails(void);

		void nodeId(const OpcUaNodeId& nodeId);
		OpcUaNodeId& nodeId(void);
		void eventId(const OpcUaByteStringArray::SPtr eventId);
		OpcUaByteStringArray::SPtr eventId(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaNodeId nodeId_;
		OpcUaByteStringArray::SPtr eventIdArraySPtr_;
	};

}

#endif