#ifndef __OpcUaStackCore_NodeClass_h__
#define __OpcUaStackCore_NodeClass_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"


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
	} NodeClass;

}

#endif
