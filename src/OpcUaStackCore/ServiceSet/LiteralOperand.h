#ifndef __OpcUaStackCore_LiteralOperand_h__
#define __OpcUaStackCore_LiteralOperand_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT LiteralOperand : public  ObjectPool<LiteralOperand>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<LiteralOperand> SPtr;

		LiteralOperand(void);
		virtual ~LiteralOperand(void);

		void value(const OpcUaVariant& value);
		OpcUaVariant& value(void);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaVariant variant_;
	};

}

#endif