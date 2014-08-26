#ifndef __OpcUaStackServer_ReferenceTypeNodeClass_h__
#define __OpcUaStackServer_ReferenceTypeNodeClass_h__

#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class ReferenceTypeNodeClass : public BaseNodeClass
	{
	  public:
		ReferenceTypeNodeClass(void);
		~ReferenceTypeNodeClass(void);

	  private:
		// attributes mandatory
		OpcUaBoolean isAbstract_;
		OpcUaBoolean symmetric_;

		// attributes optional
		OpcUaLocalizedText inverseName_;

		// references
		OpcUaNodeIdList hasProperty_;
		OpcUaNodeIdList hasSubtype_;

		// standard properties
		OpcUaString nodeVersion_;  // optional
	};

}

#endif