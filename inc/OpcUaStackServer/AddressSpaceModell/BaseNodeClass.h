#ifndef __OpcUaStackServer_BaseNodeClass_h__
#define __OpcUaStackServer_BaseNodeClass_h__

#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

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

	class BaseNodeClass
	{
	  public: 
		BaseNodeClass(void);
		~BaseNodeClass(void);

	  private:
		// attributes mandatorry
		OpcUaNodeId nodeId_;
		NodeClass nodeClass_;
		OpcUaQualifiedName browseName_;
		OpcUaLocalizedText displayName_;

		// attributes optional
		OpcUaLocalizedText description_;
		OpcUaUInt32 writeMask_;
		OpcUaUInt32 UserWriteMask_;
	};

}

#endif