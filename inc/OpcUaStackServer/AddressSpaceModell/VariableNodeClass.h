#ifndef __OpcUaStackServer_VariableNodeClass_h__
#define __OpcUaStackServer_VariableNodeClass_h__

#include "OpcUaStackServer/AddressSpaceModell/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class VariableNodeClass : public BaseNodeClass
	{
	  public:
		VariableNodeClass(void);
		~VariableNodeClass(void);

	  private:
		// attributes mandatory
		OpcUaDataValue value_;
		OpcUaNodeId dataType_;
		OpcUaInt32 valueRank_;
		OpcUaByte accessLevel_;
		OpcUaByte userAccessLevel_;
		OpcUaBoolean historizing_;

		// attributes optional
		OpcUaUInt32Array arrayDimension_;
		Duration minimumSamplingInterval_;

		// references
		OpcUaNodeIdList hasModellingRule_; 
		OpcUaNodeIdList hasProperty_;
		OpcUaNodeIdList hasComponent_;
		OpcUaNodeIdList hasTypeDefinition_;
		OpcUaNodeIdList hasModelParameter_;

		// standard properties - all optional
		OpcUaString nodeVersion_;  
		//TimeZoneDataType localTime_;
		OpcUaString dataTypeVersion_;
		OpcUaByteString dictionaryFragment_;
		OpcUaBoolean allowNulls_;

	};

}

#endif