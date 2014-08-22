#ifndef __OpcUaStackCore_ContentFilterElement_h__
#define __OpcUaStackCore_ContentFilterElement_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

namespace OpcUaStackCore
{

	typedef enum {
		BasicFilterOperator_Anonymous = -1,
		BasicFilterOperator_Equals = 0,
		BasicFilterOperator_IsNull = 1,
		BasicFilterOperator_GreaterThan = 2,
		BasicFilterOperator_LessThan = 3,
		BasicFilterOperator_GreaterThanOrEqual = 4,
		BasicFilterOperator_LassThanOrEqual = 5,
		BasicFilterOperator_Like = 6,
		BasicFilterOperator_Not = 7,
		BasicFilterOperator_Between = 8,
		BasicFilterOperator_InList = 9,
		BasicFilterOperator_And = 10,
		BasicFilterOperator_Or = 11,
		BasicFilterOperator_Cast = 12,
		BasicFilterOperator_BitwiseAnd = 16,
		BasicFilterOperator_BitwiseOr = 17
	} BasicFilterOperator;

	class DLLEXPORT ContentFilterElement : public  ObjectPool<ContentFilterElement>
	{
	  public:
		ContentFilterElement(void);
		virtual ~ContentFilterElement(void);

		void filterOperator(const BasicFilterOperator filterOperator);
		BasicFilterOperator filterOperator(void);
		void filterOperands(const ExtensibleParameterArray::SPtr filterOperands);
		ExtensibleParameterArray::SPtr filterOperands(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		BasicFilterOperator filterOperator_;
		ExtensibleParameterArray::SPtr filterOperandsArraySPtr_;
	};

	class ContentFilterElementArray : public OpcUaArray<ContentFilterElement::SPtr, SPtrTypeCoder<ContentFilterElement> >, public ObjectPool<ContentFilterElementArray> {};

}

#endif