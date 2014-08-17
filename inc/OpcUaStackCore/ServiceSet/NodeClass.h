#ifndef __OpcUaStackCore_NodeClass_h__
#define __OpcUaStackCore_NodeClass_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{
	typedef enum {
		NodeClassType_Unspecified = 0,
		NodeClassType_Object = 1,
		NodeClassType_Variable = 2,
		NodeClassType_Method = 4,
		NodeClassType_ObjectType = 8,
		NodeClassType_VariableType = 16,
		NodeClassType_ReferenceType = 32,
		NodeClassType_DataType = 64,
		NodeClassType_View = 128,
	} NodeClassType;


	class DLLEXPORT NodeClass : public  ObjectPool<NodeClass>
	{
	  public:
		NodeClass(void);
		virtual ~NodeClass(void);

		void nodeClassType(const NodeClassType nodeClassType);
		NodeClassType nodeClassType(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		
	  private:
		NodeClassType nodeClassType_;
	};

}

#endif
