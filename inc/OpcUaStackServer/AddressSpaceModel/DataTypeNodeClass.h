#ifndef __OpcUaStackServer_DataTypeNodeClass_h__
#define __OpcUaStackServer_DataTypeNodeClass_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DLLEXPORT DataTypeNodeClass : public BaseNodeClass, public ObjectPool<DataTypeNodeClass>
	{
	  public:
		typedef boost::shared_ptr<DataTypeNodeClass> SPtr;

		DataTypeNodeClass(void);
		~DataTypeNodeClass(void);

		IsAbstractAttribute& isAbstract(void);

		Attribute* isAbstractAttribute(void);

	  private:
		// attributes mandatory
		IsAbstractAttribute isAbstract_;

		// references
		OpcUaNodeIdList hasProperty_;
		OpcUaNodeIdList hasSubtype_;
		OpcUaNodeIdList hasEncoding_;

		// standard properties - all optional
		OpcUaString nodeVersion_;  
		OpcUaLocalizedTextArray EnumStrings_;
	};

}

#endif