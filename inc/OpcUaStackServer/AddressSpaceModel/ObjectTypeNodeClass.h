#ifndef __OpcUaStackServer_ObjectTypeNodeClass_h__
#define __OpcUaStackServer_ObjectTypeNodeClass_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ObjectTypeNodeClass : public BaseNodeClass, public ObjectPool<ObjectTypeNodeClass>
	{
	  public:
		typedef boost::shared_ptr<ObjectTypeNodeClass> SPtr;

		ObjectTypeNodeClass(void);
		~ObjectTypeNodeClass(void);

		IsAbstractAttribute& isAbstract(void);

		Attribute* isAbstractAttribute(void);

	  private:
		// attributes mandatory
		  IsAbstractAttribute isAbstract_;

		// standard properties
		OpcUaString::SPtr nodeVersion_;  // optional
		// FIXME: Image icon_;	// optional
	};

}

#endif