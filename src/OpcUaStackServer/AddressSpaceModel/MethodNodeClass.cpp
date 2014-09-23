#include "OpcUaStackServer/AddressSpaceModel/MethodNodeClass.h"

namespace OpcUaStackServer
{

	MethodNodeClass::MethodNodeClass(void)
	: BaseNodeClass(NodeClass_Method)
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

	void 
	MethodNodeClass::addReference(ReferenceType referenceType, OpcUaNodeId& opcUaNodeId)
	{
		switch (referenceType)
		{
			case ReferenceType_HasProperty:
				hasProperty_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasModellingRule:
				hasModellingRule_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasModelParameter:
				hasModelParameter_.push_back(opcUaNodeId);
				break;
			case ReferenceType_GenerateEvents:
				generateEvents_.push_back(opcUaNodeId);
				break;
			case ReferenceType_AlwaysGeneratesEvent:
				alwaysGeneratesEvent_.push_back(opcUaNodeId);
				break;
		}
	}

	void 
	MethodNodeClass::getReference(OpcUaNodeIdList& list, ReferenceType referenceType)
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