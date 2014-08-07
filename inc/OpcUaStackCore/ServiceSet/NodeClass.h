#ifndef __OpcUaStackCore_NodeClass_h__
#define __OpcUaStackCore_NodeClass_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"


namespace OpcUaStackCore
{
	typedef enum {
		NodeClass_Object = 1,
		NodeClass_Variable = 2,
		NodeClass_Method = 4,
		NodeClass_ObjectType = 8,
		NodeClass_VariableType = 16,
		NodeClass_ReferenceType = 32,
		NodeClass_DataType = 64,
		NodeClass_View = 128,
	} NodeClassType;


	class DLLEXPORT NodeClass : public  ObjectPool<NodeClass>
	{
	  public:
		NodeClass(void);
		virtual ~NodeClass(void);

		void nodeClassType(NodeClassType nodeClassType);
		NodeClassType nodeClassType(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		
	  private:
		NodeClassType nodeClassType_;
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const NodeClass& value);
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const NodeClass::SPtr& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, NodeClass& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, NodeClass::SPtr& value);
}

#endif
