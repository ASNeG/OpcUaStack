#include "OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"

namespace OpcUaStackServer
{

	DataTypeNodeClass::DataTypeNodeClass(void)
	: BaseNodeClass(NodeClassType_DataType)
	, isAbstract_()
	{
	}

	DataTypeNodeClass::~DataTypeNodeClass(void)
	{
	}

	IsAbstractAttribute& 
	DataTypeNodeClass::isAbstract(void)
	{
		return isAbstract_;
	}

	Attribute* 
	DataTypeNodeClass::isAbstractAttribute(void)
	{
		return &isAbstract_;
	}

	void
	DataTypeNodeClass::copyTo(DataTypeNodeClass::SPtr dataTypeNodeClass)
	{
		copyTo(*dataTypeNodeClass);
	}

	void
	DataTypeNodeClass::copyTo(DataTypeNodeClass& dataTypeNodeClass)
	{
		BaseNodeClass::copyTo(dataTypeNodeClass);
		isAbstractAttribute()->copyTo(dataTypeNodeClass.isAbstractAttribute());
	}
}
