#ifndef __OpcUaStackServer_NodeClass_h__
#define __OpcUaStackServer_NodeClass_h__

namespace OpcUaStackServer
{
	
	typedef enum
	{
		NodeClass_Object = 1,
		NodeClass_Variable = 2,
		NodeClass_Method = 4,
		NodeClass_ObjectType = 8,
		NodeClass_VariableType = 16,
		NodeClass_ReferenceType = 32,
		NodeClass_DataType = 64,
		NodeClass_View = 128
	} NodeClass;

}

#endif