#include "OpcUaStackServer/AddressSpaceModel/DataTypeNodeClass.h"

namespace OpcUaStackServer
{

	DataTypeNodeClass::DataTypeNodeClass(void)
	: BaseNodeClass(NodeClass_DataType)
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
	DataTypeNodeClass::addReference(ReferenceType referenceType, OpcUaNodeId& opcUaNodeId)
	{
		switch (referenceType)
		{
			case ReferenceType_HasProperty:
				hasProperty_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasSubtype:
				hasSubtype_.push_back(opcUaNodeId);
				break;
			case ReferenceType_HasEncoding:
				hasEncoding_.push_back(opcUaNodeId);
				break;
		}
	}

	void
	DataTypeNodeClass::getReference(OpcUaNodeIdList& list, ReferenceType referenceType)
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