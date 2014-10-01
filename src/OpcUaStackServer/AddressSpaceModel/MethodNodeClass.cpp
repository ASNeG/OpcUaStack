#include "OpcUaStackServer/AddressSpaceModel/MethodNodeClass.h"

namespace OpcUaStackServer
{

	MethodNodeClass::MethodNodeClass(void)
	: BaseNodeClass(NodeClassType_Method)
	, executable_()
	, userExecutable_()
	, hasProperty_()
	, hasModellingRule_()
	, hasModelParameter_()
	, generateEvents_()
	, alwaysGeneratesEvent_()
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

	void 
	MethodNodeClass::addReference(ReferenceType referenceType, ReferenceItem::SPtr referenceItem)
	{
		switch (referenceType)
		{
			case ReferenceType_HasProperty:
				hasProperty_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasModellingRule:
				hasModellingRule_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_HasModelParameter:
				hasModelParameter_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_GenerateEvents:
				generateEvents_.referenceItemList_.push_back(referenceItem);
				break;
			case ReferenceType_AlwaysGeneratesEvent:
				alwaysGeneratesEvent_.referenceItemList_.push_back(referenceItem);
				break;
		}
	}

	void 
	MethodNodeClass::getReference(ReferenceList& list, ReferenceType referenceType)
	{
		switch (referenceType)
		{
			case ReferenceType_HasProperty:
				list = hasProperty_;
				break;
			case ReferenceType_HasModellingRule:
				list = hasModellingRule_;
				break;
			case ReferenceType_HasModelParameter:
				list = hasModelParameter_;
				break;
			case ReferenceType_GenerateEvents:
				list = generateEvents_;
				break;
			case ReferenceType_AlwaysGeneratesEvent:
				list = alwaysGeneratesEvent_;
				break;
		}
	}

}