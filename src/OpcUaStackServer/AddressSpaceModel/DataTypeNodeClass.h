#ifndef __OpcUaStackServer_DataTypeNodeClass_h__
#define __OpcUaStackServer_DataTypeNodeClass_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;

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

		void copyTo(DataTypeNodeClass::SPtr dataTypeNodeClass);
		void copyTo(DataTypeNodeClass& dataTypeNodeClass);

	  private:
		// attributes mandatory
		IsAbstractAttribute isAbstract_;

		// standard properties - all optional
		OpcUaString nodeVersion_;  
		OpcUaLocalizedTextArray EnumStrings_;
	};

}

#endif
