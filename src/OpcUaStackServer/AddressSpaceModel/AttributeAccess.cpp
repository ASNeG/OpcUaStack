#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"

namespace OpcUaStackServer
{

	bool 
	AttributeAccess::copy(Attribute& attribute, OpcUaVariant& variant)
	{
		switch (attribute.id())
		{
			case AttributeId_NodeId:
			{
				OpcUaNodeId::SPtr nodeId = OpcUaNodeId::construct();
				NodeIdAttribute* nodeIdAttribute = reinterpret_cast<NodeIdAttribute*>(&attribute);
				nodeIdAttribute->data().copyTo(*nodeId);
				variant.variant(nodeId);
				break;
			}
			case AttributeId_NodeClass:
			{
				NodeClassAttribute* nodeClassAttribute = reinterpret_cast<NodeClassAttribute*>(&attribute);
				variant.variant(nodeClassAttribute->data());
				break;
			}
			case AttributeId_BrowseName:
			{
				OpcUaQualifiedName::SPtr browseName = OpcUaQualifiedName::construct();
				BrowseNameAttribute* browseNameAttribute = reinterpret_cast<BrowseNameAttribute*>(&attribute);
				browseNameAttribute->data().copyTo(*browseName);
				variant.variant(browseName);
				break;
			}
			case AttributeId_DisplayName:
			{
				OpcUaLocalizedText::SPtr displayName = OpcUaLocalizedText::construct();
				DisplayNameAttribute* displayNameAttribute = reinterpret_cast<DisplayNameAttribute*>(&attribute);
				displayNameAttribute->data().copyTo(*displayName);
				variant.variant(displayName);
				break;
			}
			case AttributeId_Description:
			{
				OpcUaLocalizedText::SPtr description = OpcUaLocalizedText::construct();
				DescriptionAttribute* descriptionAttribute = reinterpret_cast<DescriptionAttribute*>(&attribute);
				descriptionAttribute->data().copyTo(*description);
				variant.variant(description);
				break;
			}
			case AttributeId_WriteMask:
			{
				WriteMaskAttribute* writeMaskAttribute = reinterpret_cast<WriteMaskAttribute*>(&attribute);
				variant.variant(writeMaskAttribute->data());
				break;
			}
			case AttributeId_UserWriteMask:
			{
				UserWriteMaskAttribute* userWriteMaskAttribute = reinterpret_cast<UserWriteMaskAttribute*>(&attribute);
				variant.variant(userWriteMaskAttribute->data());
				break;
			}
			case AttributeId_IsAbstract:
			{
				IsAbstractAttribute* isAbstractAttribute = reinterpret_cast<IsAbstractAttribute*>(&attribute);
				variant.variant(isAbstractAttribute->data());
				break;
			}
			case AttributeId_Symmetric:
			{
				SymmetricAttribute* symmetricAttribute = reinterpret_cast<SymmetricAttribute*>(&attribute);
				variant.variant(symmetricAttribute->data());
				break;
			}
			case AttributeId_InverseName:
			{
				OpcUaLocalizedText::SPtr inverseName = OpcUaLocalizedText::construct();
				InverseNameAttribute* inverseNameAttribute = reinterpret_cast<InverseNameAttribute*>(&attribute);
				inverseNameAttribute->data().copyTo(*inverseName);
				variant.variant(inverseName);
				break;
			}
			case AttributeId_ContainsNoLoops:
			{
				ContainsNoLoopsAttribute* containsNoLoopsAttribute = reinterpret_cast<ContainsNoLoopsAttribute*>(&attribute);
				variant.variant(containsNoLoopsAttribute->data());
				break;
			}
			case AttributeId_EventNotifier:
			{
				EventNotifierAttribute* eventNotifierAttribute = reinterpret_cast<EventNotifierAttribute*>(&attribute);
				variant.variant(eventNotifierAttribute->data());
				break;
			}
			case AttributeId_Value:
			{
				ValueAttribute* valueAttribute = reinterpret_cast<ValueAttribute*>(&attribute);
				variant.copyTo(*valueAttribute->data().variant());
				break;
			}
			case AttributeId_DataType:
			{
				OpcUaNodeId::SPtr nodeId = OpcUaNodeId::construct();
 				DataTypeAttribute* dataTypeAttribute = reinterpret_cast<DataTypeAttribute*>(&attribute);
				dataTypeAttribute->data().copyTo(*nodeId);
				variant.variant(nodeId);
				break;
			}
			case AttributeId_ValueRank:
			{
				ValueRankAttribute* valueRankAttribute = reinterpret_cast<ValueRankAttribute*>(&attribute);
				variant.variant(valueRankAttribute->data());
				break;
			}
			case AttributeId_ArrayDimensions:
			{
				OpcUaUInt32Array::SPtr arrayDimensions = OpcUaUInt32Array::construct();
				ArrayDimensionsAttribute* arrayDimensionsAttribute = reinterpret_cast<ArrayDimensionsAttribute*>(&attribute);
				arrayDimensionsAttribute->data().copyTo(*arrayDimensions);
				variant.variant(arrayDimensions);
				break;
			}
			case AttributeId_AccessLevel:
			{
				AccessLevelAttribute* accessLevelAttribute = reinterpret_cast<AccessLevelAttribute*>(&attribute);
				variant.variant(accessLevelAttribute->data());
				break;
			}
			case AttributeId_UserAccessLevel:
			{
				UserAccessLevelAttribute* userAccessLevelAttribute = reinterpret_cast<UserAccessLevelAttribute*>(&attribute);
				variant.variant(userAccessLevelAttribute->data());
				break;
			}
			case AttributeId_MinimumSamplingInterval:
			{
				MinimumSamplingIntervalAttribute* minimumSamplingIntervalAttribute = reinterpret_cast<MinimumSamplingIntervalAttribute*>(&attribute);
				variant.variant(minimumSamplingIntervalAttribute->data());
				break;
			}
			case AttributeId_Historizing:
			{
				HistorizingAttribute* historizingAttribute = reinterpret_cast<HistorizingAttribute*>(&attribute);
				variant.variant(historizingAttribute->data());
				break;
			}
			case AttributeId_Executable:
			{
				ExecutableAttribute* executableAttribute = reinterpret_cast<ExecutableAttribute*>(&attribute);
				variant.variant(executableAttribute->data());
				break;
			}
			case AttributeId_UserExecutable:
			{
				UserExecutableAttribute* userExecutableAttribute = reinterpret_cast<UserExecutableAttribute*>(&attribute);
				variant.variant(userExecutableAttribute->data());
				break;
			}
			default:
			{
				return false;
			}
		}
		return true;
	}

	bool 
	AttributeAccess::copy(OpcUaVariant& variant, Attribute& attribute)
	{
		switch (attribute.id())
		{
			case AttributeId_NodeId:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaNodeId) return false;
				NodeIdAttribute* nodeIdAttribute = reinterpret_cast<NodeIdAttribute*>(&attribute);
				OpcUaNodeId::SPtr nodeId = variant.variantSPtr<OpcUaNodeId>();
				nodeId->copyTo(nodeIdAttribute->data());
				nodeIdAttribute->exist(true);
				break;
			}
			case AttributeId_NodeClass:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaUInt32) return false;
				NodeClassAttribute* nodeClassAttribute = reinterpret_cast<NodeClassAttribute*>(&attribute);
				nodeClassAttribute->data((NodeClass)variant.variant<OpcUaUInt32>());
				break;
			}
			case AttributeId_BrowseName:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaQualifiedName) return false;
				BrowseNameAttribute* browseNameAttribute = reinterpret_cast<BrowseNameAttribute*>(&attribute);
				OpcUaQualifiedName::SPtr browseName = variant.variantSPtr<OpcUaQualifiedName>();
				browseName->copyTo(browseNameAttribute->data());
				browseNameAttribute->exist(true);
				break;
			}
			case AttributeId_DisplayName:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaLocalizedText) return false;
				DisplayNameAttribute* displayNameAttribute = reinterpret_cast<DisplayNameAttribute*>(&attribute);
				OpcUaLocalizedText::SPtr displayName = variant.variantSPtr<OpcUaLocalizedText>();
				displayName->copyTo(displayNameAttribute->data());
				displayNameAttribute->exist(true);
				break;
			}
			case AttributeId_Description:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaLocalizedText) return false;
				DescriptionAttribute* descriptionAttribute = reinterpret_cast<DescriptionAttribute*>(&attribute);
				OpcUaLocalizedText::SPtr description = variant.variantSPtr<OpcUaLocalizedText>();
				description->copyTo(descriptionAttribute->data());
				descriptionAttribute->exist(true);
				break;
			}
			case AttributeId_WriteMask:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaUInt32) return false;
				WriteMaskAttribute* writeMaskAttribute = reinterpret_cast<WriteMaskAttribute*>(&attribute);
				writeMaskAttribute->data(variant.variant<OpcUaUInt32>());
				break;
			}
			case AttributeId_UserWriteMask:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaUInt32) return false;
				UserWriteMaskAttribute* userWriteMaskAttribute = reinterpret_cast<UserWriteMaskAttribute*>(&attribute);
				userWriteMaskAttribute->data(variant.variant<OpcUaUInt32>());
				break;
			}
			case AttributeId_IsAbstract:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaBoolean) return false;
				IsAbstractAttribute* isAbstractAttribute = reinterpret_cast<IsAbstractAttribute*>(&attribute);
				isAbstractAttribute->data(variant.variant<OpcUaBoolean>());
				break;
			}
			case AttributeId_Symmetric:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaBoolean) return false;
				SymmetricAttribute* symmetricAttribute = reinterpret_cast<SymmetricAttribute*>(&attribute);
				symmetricAttribute->data(variant.variant<OpcUaBoolean>());
				break;
			}
			case AttributeId_InverseName:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaLocalizedText) return false;
				InverseNameAttribute* inverseNameAttribute = reinterpret_cast<InverseNameAttribute*>(&attribute);
				OpcUaLocalizedText::SPtr inverseName = variant.variantSPtr<OpcUaLocalizedText>();
				inverseName->copyTo(inverseNameAttribute->data());
				inverseNameAttribute->exist();
				break;
			}
			case AttributeId_ContainsNoLoops:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaBoolean) return false;
				ContainsNoLoopsAttribute* containsNoLoopsAttribute = reinterpret_cast<ContainsNoLoopsAttribute*>(&attribute);
				containsNoLoopsAttribute->data(variant.variant<OpcUaBoolean>());
				break;
			}
			case AttributeId_EventNotifier:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaByte) return false;
				EventNotifierAttribute* eventNotifierAttribute = reinterpret_cast<EventNotifierAttribute*>(&attribute);
				eventNotifierAttribute->data(variant.variant<OpcUaByte>());
				break;
			}
			case AttributeId_Value:
			{
				//if (variant.variantType() != OpcUaBuildInType_OpcUaDataValue) return false;
				ValueAttribute* valueAttribute = reinterpret_cast<ValueAttribute*>(&attribute);
				variant.copyTo(*valueAttribute->data().variant());
				valueAttribute->exist(true);
				break;
			}
			case AttributeId_DataType:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaNodeId) return false;
				DataTypeAttribute* dataTypeAttribute = reinterpret_cast<DataTypeAttribute*>(&attribute);
				OpcUaNodeId::SPtr dataType = variant.variantSPtr<OpcUaNodeId>();
				dataType->copyTo(dataTypeAttribute->data());
				dataTypeAttribute->exist();
				break;
			}
			case AttributeId_ValueRank:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaUInt32) return false;
				ValueRankAttribute* valueRankAttribute = reinterpret_cast<ValueRankAttribute*>(&attribute);
				valueRankAttribute->data(variant.variant<OpcUaUInt32>());
				break;
			}
			case AttributeId_ArrayDimensions:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaUInt32) return false;
				ArrayDimensionsAttribute* arrayDimensionsAttribute = reinterpret_cast<ArrayDimensionsAttribute*>(&attribute);
				OpcUaUInt32Array::SPtr arrayDimensions = variant.variantSPtr<OpcUaUInt32Array>();
				arrayDimensions->copyTo(arrayDimensionsAttribute->data());
				arrayDimensionsAttribute->exist();
				break;
			}
			case AttributeId_AccessLevel:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaUInt32) return false;
				AccessLevelAttribute* accessLevelAttribute = reinterpret_cast<AccessLevelAttribute*>(&attribute);
				accessLevelAttribute->data(variant.variant<OpcUaUInt32>());
				break;
			}
			case AttributeId_UserAccessLevel:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaUInt32) return false;
				UserAccessLevelAttribute* userAccessLevelAttribute = reinterpret_cast<UserAccessLevelAttribute*>(&attribute);
				userAccessLevelAttribute->data(variant.variant<OpcUaUInt32>());
				break;
			}

			case AttributeId_MinimumSamplingInterval:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaDouble) return false;
				MinimumSamplingIntervalAttribute* minimumSamplingIntervalAttribute = reinterpret_cast<MinimumSamplingIntervalAttribute*>(&attribute);
				minimumSamplingIntervalAttribute->data(variant.variant<OpcUaDouble>());
				break;
			}
			case AttributeId_Historizing:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaBoolean) return false;
				HistorizingAttribute* historizingAttribute = reinterpret_cast<HistorizingAttribute*>(&attribute);
				historizingAttribute->data(variant.variant<OpcUaBoolean>());
				break;
			}
			case AttributeId_Executable:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaBoolean) return false;
				ExecutableAttribute* executableAttribute = reinterpret_cast<ExecutableAttribute*>(&attribute);
				executableAttribute->data(variant.variant<OpcUaBoolean>());
				break;
			}
			case AttributeId_UserExecutable:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaBoolean) return false;
				UserExecutableAttribute* userExecutableAttribute = reinterpret_cast<UserExecutableAttribute*>(&attribute);
				userExecutableAttribute->data(variant.variant<OpcUaBoolean>());
				break;
			}
			default:
			{
				return false;
			}
		}
		return true;
	}

	bool 
	AttributeAccess::copy(OpcUaDataValue& dataValue, Attribute& attribute)
	{
		if (attribute.id() == AttributeId_Value) {
			ValueAttribute* valueAttribute = reinterpret_cast<ValueAttribute*>(&attribute);
			dataValue.copyTo(valueAttribute->data());
			valueAttribute->exist(true);
		}
		else {
			return copy(*dataValue.variant(), attribute);
		}
		return true;
	}


	bool 
	AttributeAccess::copy(Attribute& attribute, OpcUaDataValue& dataValue)
	{
		if (attribute.id() == AttributeId_Value) {
			ValueAttribute* valueAttribute = reinterpret_cast<ValueAttribute*>(&attribute);
			valueAttribute->data().copyTo(dataValue);
		}
		else {
			return copy(attribute, *dataValue.variant());
		}
		return true;
	}

}