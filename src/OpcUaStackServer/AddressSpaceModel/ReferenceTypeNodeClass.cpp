#include "OpcUaStackServer/AddressSpaceModel/ReferenceTypeNodeClass.h"

namespace OpcUaStackServer
{

	ReferenceTypeNodeClass::ReferenceTypeNodeClass(void)
	: BaseNodeClass(NodeClass_ReferenceType)
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

	void 
	ReferenceTypeNodeClass::addReference(ReferenceType referenceType, OpcUaNodeId& opcUaNodeId)
	{
		switch (referenceType)
		{
			case ReferenceType_HasProperty:
				hasProperty_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasSubtype:
				hasSubtype_.push_back(opcUaNodeId);
				break;
		}
	}

	void
	ReferenceTypeNodeClass::getReference(OpcUaNodeIdList& list, ReferenceType referenceType)
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