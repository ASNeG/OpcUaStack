#include "OpcUaStackServer/AddressSpaceModel/ReferenceTypeNodeClass.h"

namespace OpcUaStackServer
{

	ReferenceTypeNodeClass::ReferenceTypeNodeClass(void)
	: BaseNodeClass(NodeClassType_ReferenceType)
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

	Attribute* 
	ReferenceTypeNodeClass::isAbstractAttribute(void)
	{
		return &isAbstract_;
	}

	Attribute* 
	ReferenceTypeNodeClass::symmetricAttribute(void)
	{
		return &symmetric_;
	}

	Attribute* 
	ReferenceTypeNodeClass::inverseNameAttribute(void)
	{
		return &inverseName_;
	}

	void
	ReferenceTypeNodeClass::copyTo(ReferenceTypeNodeClass::SPtr referenceTypeNodeClass)
	{
		copyTo(*referenceTypeNodeClass);
	}

	void
	ReferenceTypeNodeClass::copyTo(ReferenceTypeNodeClass& referenceTypeNodeClass)
	{
		BaseNodeClass::copyTo(referenceTypeNodeClass);
		isAbstractAttribute()->copyTo(referenceTypeNodeClass.isAbstractAttribute());
		symmetricAttribute()->copyTo(referenceTypeNodeClass.symmetricAttribute());
		inverseNameAttribute()->copyTo(referenceTypeNodeClass.inverseNameAttribute());
	}

	BaseNodeClass::SPtr
	ReferenceTypeNodeClass::clone(void)
	{
		ReferenceTypeNodeClass::SPtr referenceTypeNodeClass = ReferenceTypeNodeClass::construct();
		copyTo(referenceTypeNodeClass);
		return referenceTypeNodeClass;
	}

}
