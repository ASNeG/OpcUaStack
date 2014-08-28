#ifndef __OpcUaStackServer_ObjectTypeNodeClass_h__
#define __OpcUaStackServer_ObjectTypeNodeClass_h__

#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class ObjectTypeNodeClass : public BaseNodeClass
	{
	  public:
		ObjectTypeNodeClass(void);
		~ObjectTypeNodeClass(void);

		IsAbstractAttribute& isAbstract(void);

		OpcUaNodeIdList& hasComponent(void);
		OpcUaNodeIdList& hasProperty(void);
		OpcUaNodeIdList& hasSubtypes(void);
		OpcUaNodeIdList& generatesEvents(void);

	  private:
		// attributes mandatory
		  IsAbstractAttribute isAbstract_;

		// references
		OpcUaNodeIdList hasComponent_;
		OpcUaNodeIdList hasProperty_;
		OpcUaNodeIdList hasSubtypes_;
		OpcUaNodeIdList generatesEvents_;

		// standard properties
		OpcUaString::SPtr nodeVersion_;  // optional
		// FIXME: Image icon_;	// optional
	};

}

#endif