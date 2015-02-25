#ifndef __OpcUaStackCore_EventField_h__
#define __OpcUaStackCore_EventField_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EventField : public  ObjectPool<EventField>
	{
	  public:
		typedef boost::shared_ptr<EventField> SPtr;

		EventField(void);
		virtual ~EventField(void);

		void variant(const OpcUaVariant::SPtr variant);
		OpcUaVariant::SPtr variant(void) const;
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		  OpcUaVariant::SPtr variantSPtr_;
	};

	class EventFieldArray : public OpcUaArray<EventField::SPtr, SPtrTypeCoder<EventField> >, public ObjectPool<EventFieldArray> 
	{
  	  public:
		typedef boost::shared_ptr<EventFieldArray> SPtr;
	};

}

#endif