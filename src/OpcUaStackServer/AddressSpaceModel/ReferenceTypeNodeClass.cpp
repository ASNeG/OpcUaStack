#include "OpcUaStackServer/AddressSpaceModel/ReferenceTypeNodeClass.h"

namespace OpcUaStackServer
{

	ReferenceTypeNodeClass::ReferenceTypeNodeClass(void)
	: BaseNodeClass(NodeClass_ReferenceType)
	, isAbstract_()
	, symmetric_()
	, inverseName_()
	{
	}

	ReferenceTypeNodeClass::~ReferenceTypeNodeClass(void)
	{
	}

	IsAbstractAttribute& 
	ReferenceTypeNodeClass::isAbstract(void)
	{
		return isAbstract_;
	}

	SymmetricAttribute& 
	ReferenceTypeNodeClass::symmetric(void)
	{
		return symmetric_;
	}

	InverseNameAttribute& 
	ReferenceTypeNodeClass::inverseName(void)
	{
		return inverseName_;
	}

}