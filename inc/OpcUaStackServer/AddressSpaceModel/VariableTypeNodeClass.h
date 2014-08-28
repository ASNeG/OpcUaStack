#ifndef __OpcUaStackServer_VariableTypeNodeClass_h__
#define __OpcUaStackServer_VariableTypeNodeClass_h__

#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class VariableTypeNodeClass : public BaseNodeClass
	{
	  public:
		VariableTypeNodeClass(void);
		~VariableTypeNodeClass(void);

		DataTypeAttribute& dataType(void);
		ValueRanklAttribute& valueRank(void);
		IsAbstractAttribute& isAbstract(void);
		ValueAttribute& value(void);
		ArrayDimensionsAttribute& arrayDimensions(void);

	  private:
		// attributes mandatory
		DataTypeAttribute dataType_;
		ValueRanklAttribute valueRank_;
		IsAbstractAttribute isAbstract_;

		// attributes optional
		ValueAttribute value_;
		ArrayDimensionsAttribute arrayDimensions_;

		// references
	
		OpcUaNodeIdList hasProperty_;
		OpcUaNodeIdList hasComponent_;
		OpcUaNodeIdList hasSubtype_;
		OpcUaNodeIdList GeneratesEvent_;

		// standard properties - all optional
		OpcUaString nodeVersion_;  
	};

}

#endif