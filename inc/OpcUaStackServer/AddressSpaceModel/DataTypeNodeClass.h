#ifndef __OpcUaStackServer_DataTypeNodeClass_h__
#define __OpcUaStackServer_DataTypeNodeClass_h__

#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

namespace OpcUaStackServer
{

	class DataTypeNodeClass : public BaseNodeClass
	{
	  public:
		DataTypeNodeClass(void);
		~DataTypeNodeClass(void);

	  private:
		// attributes mandatory
		OpcUaBoolean isAbstract_;

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