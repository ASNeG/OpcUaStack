#ifndef __OpcUaStackCore_ElementOperand_h__
#define __OpcUaStackCore_ElementOperand_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ElementOperand : public  ObjectPool<ElementOperand>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<ElementOperand> SPtr;

		ElementOperand(void);
		virtual ~ElementOperand(void);

		void index(const OpcUaUInt32& index);
		OpcUaUInt32 index(void) const;

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 index_;
	};

}

#endif