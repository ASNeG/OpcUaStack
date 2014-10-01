#include "OpcUaStackServer/AddressSpaceModel/ReferenceTypeNodeClass.h"

namespace OpcUaStackServer
{

	ReferenceTypeNodeClass::ReferenceTypeNodeClass(void)
	: BaseNodeClass(NodeClassType_ReferenceType)
	, isAbstract_()
	, symmetric_()
	, inverseName_()
	, hasProperty_()
	, hasSubtype_()
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
	ReferenceTypeNodeClass::addReference(ReferenceType referenceType, ReferenceItem::SPtr referenceItem)
	{
		switch (referenceType)
		{
			case ReferenceType_HasProperty:
				hasProperty_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasSubtype:
				hasSubtype_.referenceItemList_.push_back(referenceItem);
				break;
		}
	}

	void
	ReferenceTypeNodeClass::getReference(ReferenceList& list, ReferenceType referenceType)
	{
		switch (referenceType)
		{
			case ReferenceType_HasProperty:
				list = hasProperty_;
				break;
			case ReferenceType_HasSubtype:
				list = hasSubtype_;
				break;
		}
	}

}