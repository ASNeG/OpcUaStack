#ifndef __OpcUaStackCore_EventFilter_h__
#define __OpcUaStackCore_EventFilter_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/SimpleAttributeOperand.h"
#include "OpcUaStackCore/ServiceSet/ContentFilter.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EventFilter : public  ObjectPool<EventFilter>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<EventFilter> SPtr;

		EventFilter(void);
		virtual ~EventFilter(void);

		void selectClauses(const SimpleAttributeOperandArray::SPtr selectClauses);
		SimpleAttributeOperandArray::SPtr selectClauses(void) const;
		void whereClause(const ContentFilter& whereClause);
		ContentFilter& whereClause(void);
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		SimpleAttributeOperandArray::SPtr selectClausesArraySPtr_;
		ContentFilter whereClause_;
	};

}

#endif