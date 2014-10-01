#include "OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"

namespace OpcUaStackServer
{

	DataTypeNodeClass::DataTypeNodeClass(void)
	: BaseNodeClass(NodeClassType_DataType)
	, isAbstract_()
	, hasProperty_()
	, hasSubtype_()
	, hasEncoding_()
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
	DataTypeNodeClass::addReference(ReferenceType referenceType, ReferenceItem::SPtr referenceItem)
	{
		switch (referenceType)
		{
			case ReferenceType_HasProperty:
				hasProperty_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasSubtype:
				hasSubtype_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasEncoding:
				hasEncoding_.referenceItemList_.push_back(referenceItem);
				break;
		}
	}

	void
	DataTypeNodeClass::getReference(ReferenceList& list, ReferenceType referenceType)
	{
		switch (referenceType)
		{
			case ReferenceType_HasProperty:
				list = hasProperty_;
				break;
			case ReferenceType_HasSubtype:
				list = hasSubtype_;
				break;
			case ReferenceType_HasEncoding:
				list = hasEncoding_;
				break;
		}
	}

}