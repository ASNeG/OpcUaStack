#include "OpcUaStackServer/AddressSpaceModel/MethodNodeClass.h"

namespace OpcUaStackServer
{

	MethodNodeClass::MethodNodeClass(void)
	: BaseNodeClass(NodeClass_Method)
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

}