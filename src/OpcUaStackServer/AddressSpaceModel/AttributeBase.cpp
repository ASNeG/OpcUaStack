#include "OpcUaStackServer/AddressSpaceModel/AttributeBase.h"

namespace OpcUaStackServer
{

	AttributeBase::AttributeBase(void)
	{
	}

	AttributeBase::~AttributeBase(void)
	{
	}

	Attribute* 
	AttributeBase::attribute(AttributeId attributeId)
	{
		switch (attributeId)
		{
			case AttributeId_NodeId: return nodeIdAttribute();
			case AttributeId_NodeClass: return nodeClassAttribute();
			case AttributeId_BrowseName: return browseNameAttribute();
			case AttributeId_DisplayName: return displayNameAttribute();
			case AttributeId_Description: return descriptionAttribute();
			case AttributeId_WriteMask: return writeMaskAttribute();
			case AttributeId_UserWriteMask: return userWriteMaskAttribute();
			case AttributeId_IsAbstract: return isAbstractAttribute();
			case AttributeId_Symmetric: return symmetricAttribute();
			case AttributeId_InverseName: return inverseNameAttribute();
			case AttributeId_ContainsNoLoops: return containsNoLoopsAttribute();
			case AttributeId_EventNotifier: return eventNotifierAttribute();
			case AttributeId_Value: return valueAttribute();
			case AttributeId_DataType: return dataTypeAttribute();
			case AttributeId_ValueRank: return valueRankAttribute();
			case AttributeId_ArrayDimensions: return arrayDimensionsAttribute();
			case AttributeId_AccessLevel: return accessLevelAttribute();
			case AttributeId_UserAccessLevel: return userAccessLevelAttribute();
			case AttributeId_MinimumSamplingInterval: minimumSamplingIntervalAttribute();
			case AttributeId_Historizing: return historizingAttribute();
			case AttributeId_Executable: return executableAttribute();
			case AttributeId_UserExecutable: return userExecutableAttribute();
		    default: return nullptr;
		}
	}

	Attribute* 
	AttributeBase::nodeIdAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::nodeClassAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::browseNameAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::displayNameAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::descriptionAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::writeMaskAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::userWriteMaskAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::isAbstractAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::symmetricAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::inverseNameAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::containsNoLoopsAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::eventNotifierAttribute(void)
	{
		return nullptr;
	}

	Attribute* valueAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::dataTypeAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::valueRankAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::arrayDimensionsAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::accessLevelAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::userAccessLevelAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::historizingAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::executableAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::userExecutableAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::minimumSamplingIntervalAttribute(void)
	{
		return nullptr;
	}

	Attribute* 
	AttributeBase::valueAttribute(void)
	{
		return nullptr;
	}

}