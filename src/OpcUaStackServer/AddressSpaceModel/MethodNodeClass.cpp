#include "OpcUaStackServer/AddressSpaceModel/MethodNodeClass.h"

namespace OpcUaStackServer
{

	MethodNodeClass::MethodNodeClass(void)
	: BaseNodeClass(NodeClassType_Method)
	, executable_()
	, userExecutable_()
	{
	}

	MethodNodeClass::~MethodNodeClass(void)
	{
	}

	ExecutableAttribute& 
	MethodNodeClass::executable(void)
	{
		return executable_;
	}
	
	UserExecutableAttribute& 
	MethodNodeClass::userExecutable(void)
	{
		return userExecutable_;
	}

	Attribute* 
	MethodNodeClass::executableAttribute(void)
	{
		return & executable_;
	}
		
	Attribute* 
	MethodNodeClass::userExecutableAttribute(void)
	{
		return &userExecutable_;
	}

}