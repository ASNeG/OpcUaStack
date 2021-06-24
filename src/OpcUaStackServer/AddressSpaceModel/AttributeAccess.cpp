/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/ServiceSet/DataValueTrigger.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	bool 
	AttributeAccess::copy(Attribute& attribute, OpcUaVariant& variant)
	{
		switch (attribute.id())
		{
			case AttributeId_NodeId:
			{
				OpcUaNodeId::SPtr nodeId = boost::make_shared<OpcUaNodeId>();
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
				OpcUaQualifiedName::SPtr browseName = boost::make_shared<OpcUaQualifiedName>();
				BrowseNameAttribute* browseNameAttribute = reinterpret_cast<BrowseNameAttribute*>(&attribute);
				browseNameAttribute->data().copyTo(*browseName);
				variant.variant(browseName);
				break;
			}
			case AttributeId_DisplayName:
			{
				OpcUaLocalizedText::SPtr displayName = boost::make_shared<OpcUaLocalizedText>();
				DisplayNameAttribute* displayNameAttribute = reinterpret_cast<DisplayNameAttribute*>(&attribute);
				displayNameAttribute->data().copyTo(*displayName);
				variant.variant(displayName);
				break;
			}
			case AttributeId_Description:
			{
				OpcUaLocalizedText::SPtr description = boost::make_shared<OpcUaLocalizedText>();
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
				OpcUaLocalizedText::SPtr inverseName = boost::make_shared<OpcUaLocalizedText>();
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
				OpcUaNodeId::SPtr nodeId = boost::make_shared<OpcUaNodeId>();
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
				ArrayDimensionsAttribute* arrayDimensionsAttribute = reinterpret_cast<ArrayDimensionsAttribute*>(&attribute);
				for (uint32_t idx=0; idx<arrayDimensionsAttribute->data().size(); idx++) {
					uint32_t value;
					arrayDimensionsAttribute->data().get(idx, value);
					variant.pushBack(value);
				}
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
			case AttributeId_DataTypeDefinition:
			{
				auto dataTypeDefinitionAttribute = reinterpret_cast<DataTypeDefinitionAttribute*>(&attribute);
				auto extensionObject = boost::make_shared<OpcUaExtensionObject>();
				dataTypeDefinitionAttribute->data().copyTo(*extensionObject->parameter<DataTypeDefinition>(OpcUaId_OpcUa_BinarySchema_DataTypeDefinitionType).get());
				variant.variant(extensionObject);
				break;
			}
			case AttributeId_RolePermissions:
			{
				auto rolePermissionsAttribute = reinterpret_cast<RolePermissionsAttribute*>(&attribute);
				RolePermissionType x;
				for (auto rolePermission : rolePermissionsAttribute->data()) {
					auto extensionObject = boost::make_shared<OpcUaExtensionObject>();
					rolePermission->copyTo(*extensionObject->parameter<RolePermissionType>(OpcUaId_OpcUa_BinarySchema_RolePermissionType).get());
					variant.pushBack(extensionObject);
				}
				break;
			}
			case AttributeId_UserRolePermissions:
			{
				auto userRolePermissionsAttribute = reinterpret_cast<UserRolePermissionsAttribute*>(&attribute);
				for (auto userRolePermission : userRolePermissionsAttribute->data()) {
					auto extensionObject = boost::make_shared<OpcUaExtensionObject>();
					userRolePermission->copyTo(*extensionObject->parameter<RolePermissionType>(OpcUaId_OpcUa_BinarySchema_RolePermissionType).get());
					variant.pushBack(extensionObject);
				}
				break;
			}
			case AttributeId_AccessRestrictions:
			{
				AccessRestrictionsAttribute* accessRestrictionsAttribute = reinterpret_cast<AccessRestrictionsAttribute*>(&attribute);
				variant.variant(accessRestrictionsAttribute->data());
				break;
			}
			case AttributeId_AccessLevelEx:
			{
				AccessLevelExAttribute* accessLevelExAttribute = reinterpret_cast<AccessLevelExAttribute*>(&attribute);
				variant.variant(accessLevelExAttribute->data());
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
				nodeClassAttribute->data((NodeClass::Enum)variant.variant<OpcUaUInt32>());
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
			case AttributeId_DataTypeDefinition:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaExtensionObject) return false;
				auto dataTypeDefinitionAttribut = reinterpret_cast<DataTypeDefinitionAttribute*>(&attribute);

				auto extensionObject = variant.variantSPtr<OpcUaExtensionObject>();
				if (extensionObject->typeId() != OpcUaNodeId(OpcUaId_OpcUa_BinarySchema_DataTypeDefinitionType)) {
					return false;
				}
				auto dataTypeDefinition = extensionObject->parameter<DataTypeDefinition>();

				dataTypeDefinitionAttribut->data(*dataTypeDefinition);
				break;
			}
			case AttributeId_RolePermissions:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaExtensionObject) return false;
				auto rolePermissionsAttribut = reinterpret_cast<RolePermissionsAttribute*>(&attribute);

				for (uint32_t idx=0; idx < variant.arrayLength(); idx++) {
					auto extensionObject = variant.variantSPtr<OpcUaExtensionObject>(idx);
					if (extensionObject->typeId() != OpcUaNodeId(OpcUaId_OpcUa_BinarySchema_RolePermissionType)) {
						return false;
					}
					auto rolePermission = extensionObject->parameter<RolePermissionType>();

					rolePermissionsAttribut->data().push_back(rolePermission);
				}
				break;
			}
			case AttributeId_UserRolePermissions:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaExtensionObject) return false;
				auto userRolePermissionsAttribut = reinterpret_cast<UserRolePermissionsAttribute*>(&attribute);

				for (uint32_t idx=0; idx < variant.arrayLength(); idx++) {
					auto extensionObject = variant.variantSPtr<OpcUaExtensionObject>(idx);
					if (extensionObject->typeId() != OpcUaNodeId(OpcUaId_OpcUa_BinarySchema_RolePermissionType)) {
						return false;
					}
					auto rolePermission = extensionObject->parameter<RolePermissionType>();

					userRolePermissionsAttribut->data().push_back(rolePermission);
				}
				break;
			}
			case AttributeId_AccessRestrictions:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaUInt16) return false;
				auto accessRestrictionsAttribute = reinterpret_cast<AccessRestrictionsAttribute*>(&attribute);
				accessRestrictionsAttribute->data(variant.variant<OpcUaUInt16>());
				break;
			}
			case AttributeId_AccessLevelEx:
			{
				if (variant.variantType() != OpcUaBuildInType_OpcUaUInt32) return false;
				auto accessLevelExAttribute = reinterpret_cast<AccessLevelExAttribute*>(&attribute);
				accessLevelExAttribute->data(variant.variant<OpcUaUInt32>());
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

	bool 
	AttributeAccess::trigger(
		OpcUaDataValue& dataValue,
		Attribute& attribute,
		DataChangeTrigger::Enum dataChangeTrigger
	)
	{
		if (attribute.id() == AttributeId_Value) {
			auto valueAttribute = reinterpret_cast<ValueAttribute*>(&attribute);
			return DataValueTrigger::run(valueAttribute->data(), dataValue, dataChangeTrigger);
		}
		
		auto variant = dataValue.variant();
		switch (attribute.id())
		{
			case AttributeId_NodeId:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaNodeId) return true;
				NodeIdAttribute* nodeIdAttribute = reinterpret_cast<NodeIdAttribute*>(&attribute);
				OpcUaNodeId::SPtr nodeId = variant->variantSPtr<OpcUaNodeId>();
				return *nodeId == nodeIdAttribute->data();
			}
			case AttributeId_NodeClass:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaUInt32) return true;
				NodeClassAttribute* nodeClassAttribute = reinterpret_cast<NodeClassAttribute*>(&attribute);
				OpcUaUInt32 nodeClass = variant->variant<OpcUaUInt32>();
				return nodeClass == nodeClassAttribute->data();
			}
			case AttributeId_BrowseName:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaQualifiedName) return true;
				BrowseNameAttribute* browseNameAttribute = reinterpret_cast<BrowseNameAttribute*>(&attribute);
				OpcUaQualifiedName::SPtr browseName = variant->variantSPtr<OpcUaQualifiedName>();
				return *browseName == browseNameAttribute->data();
			}
			case AttributeId_DisplayName:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaLocalizedText) return true;
				DisplayNameAttribute* displayNameAttribute = reinterpret_cast<DisplayNameAttribute*>(&attribute);
				OpcUaLocalizedText::SPtr displayName = variant->variantSPtr<OpcUaLocalizedText>();
				return *displayName == displayNameAttribute->data();
			}
			case AttributeId_Description:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaLocalizedText) return true;
				DescriptionAttribute* descriptionAttribute = reinterpret_cast<DescriptionAttribute*>(&attribute);
				OpcUaLocalizedText::SPtr description = variant->variantSPtr<OpcUaLocalizedText>();
				return *description == descriptionAttribute->data();
			}
			case AttributeId_WriteMask:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaUInt32) return true;
				WriteMaskAttribute* writeMaskAttribute = reinterpret_cast<WriteMaskAttribute*>(&attribute);
				OpcUaUInt32 writeMask = variant->variant<OpcUaUInt32>();
				return writeMask == writeMaskAttribute->data();
			}
			case AttributeId_UserWriteMask:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaUInt32) return true;
				UserWriteMaskAttribute* userWriteMaskAttribute = reinterpret_cast<UserWriteMaskAttribute*>(&attribute);
				OpcUaUInt32 userWriteMask = variant->variant<OpcUaUInt32>();
				return userWriteMask == userWriteMaskAttribute->data();
			}
			case AttributeId_IsAbstract:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaBoolean) return true;
				IsAbstractAttribute* isAbstractAttribute = reinterpret_cast<IsAbstractAttribute*>(&attribute);
				OpcUaBoolean isAbstract = variant->variant<OpcUaBoolean>();
				return isAbstract == isAbstractAttribute->data();
			}
			case AttributeId_Symmetric:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaBoolean) return true;
				SymmetricAttribute* symmetricAttribute = reinterpret_cast<SymmetricAttribute*>(&attribute);
				OpcUaBoolean symmetric = variant->variant<OpcUaBoolean>();
				return symmetric == symmetricAttribute->data();
			}
			case AttributeId_InverseName:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaLocalizedText) return true;
				InverseNameAttribute* inverseNameAttribute = reinterpret_cast<InverseNameAttribute*>(&attribute);
				OpcUaLocalizedText::SPtr inverseName = variant->variantSPtr<OpcUaLocalizedText>();
				return *inverseName == inverseNameAttribute->data();
			}
			case AttributeId_ContainsNoLoops:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaBoolean) return true;
				ContainsNoLoopsAttribute* containsNoLoopsAttribute = reinterpret_cast<ContainsNoLoopsAttribute*>(&attribute);
				OpcUaBoolean containsNoLoops = variant->variant<OpcUaBoolean>();
				return containsNoLoops == containsNoLoopsAttribute->data();
			}
			case AttributeId_EventNotifier:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaByte) return true;
				EventNotifierAttribute* eventNotifierAttribute = reinterpret_cast<EventNotifierAttribute*>(&attribute);
				OpcUaByte eventNotifier = variant->variant<OpcUaByte>();
				return eventNotifier == eventNotifierAttribute->data();
			}
			case AttributeId_DataType:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaNodeId) return true;
 				DataTypeAttribute* dataTypeAttribute = reinterpret_cast<DataTypeAttribute*>(&attribute);
				OpcUaNodeId::SPtr dataType = variant->variantSPtr<OpcUaNodeId>();
				return *dataType == dataTypeAttribute->data();
			}
			case AttributeId_ValueRank:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaUInt32) return true;
				ValueRankAttribute* valueRankAttribute = reinterpret_cast<ValueRankAttribute*>(&attribute);
				OpcUaUInt32 valueRank = variant->variant<OpcUaUInt32>();
				return valueRank == valueRankAttribute->data();
			}
			case AttributeId_ArrayDimensions:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaUInt32) return true;
				ArrayDimensionsAttribute* arrayDimensionsAttribute = reinterpret_cast<ArrayDimensionsAttribute*>(&attribute);
				OpcUaUInt32Array::SPtr arrayDimensions = variant->variantSPtr<OpcUaUInt32Array>();
				return *arrayDimensions == arrayDimensionsAttribute->data();
				return true;
			}
			case AttributeId_AccessLevel:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaByte) return true;
				AccessLevelAttribute* accessLevelAttribute = reinterpret_cast<AccessLevelAttribute*>(&attribute);
				OpcUaByte accessLevel = variant->variant<OpcUaByte>();
				return accessLevel == accessLevelAttribute->data();
	 		}
			case AttributeId_UserAccessLevel:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaByte) return true;
				UserAccessLevelAttribute* userAccessLevelAttribute = reinterpret_cast<UserAccessLevelAttribute*>(&attribute);
				OpcUaByte userAccessLevel = variant->variant<OpcUaByte>();
				return userAccessLevel == userAccessLevelAttribute->data();
			}
			case AttributeId_MinimumSamplingInterval:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaDouble) return true;
				MinimumSamplingIntervalAttribute* minimumSamplingIntervalAttribute = reinterpret_cast<MinimumSamplingIntervalAttribute*>(&attribute);
				OpcUaDouble minimumSamplingInterval = variant->variant<OpcUaDouble>();
				return minimumSamplingInterval == minimumSamplingIntervalAttribute->data();
			}
			case AttributeId_Historizing:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaBoolean) return true;
				HistorizingAttribute* historizingAttribute = reinterpret_cast<HistorizingAttribute*>(&attribute);
				OpcUaBoolean historizing = variant->variant<OpcUaBoolean>();
				return historizing == historizingAttribute->data();
			}
			case AttributeId_Executable:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaBoolean) return true;
				ExecutableAttribute* executableAttribute = reinterpret_cast<ExecutableAttribute*>(&attribute);
				OpcUaBoolean executable = variant->variant<OpcUaBoolean>();
				return executable == executableAttribute->data();
			}
			case AttributeId_UserExecutable:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaBoolean) return true;
				UserExecutableAttribute* userExecutableAttribute = reinterpret_cast<UserExecutableAttribute*>(&attribute);
				OpcUaBoolean userExecutable = variant->variant<OpcUaBoolean>();
				return userExecutable == userExecutableAttribute->data();
			}
			case AttributeId_DataTypeDefinition:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaExtensionObject) return true;
				auto dataTypeDefinitionAttribut = reinterpret_cast<DataTypeDefinitionAttribute*>(&attribute);

				auto extensionObject = variant->variantSPtr<OpcUaExtensionObject>();
				if (extensionObject->typeId() != OpcUaNodeId(OpcUaId_OpcUa_BinarySchema_DataTypeDefinitionType)) {
					return true;
				}
				auto dataTypeDefinition = extensionObject->parameter<DataTypeDefinition>();

				return *dataTypeDefinition == dataTypeDefinitionAttribut->data();
			}
			case AttributeId_RolePermissions:
			{
				RolePermissionTypeArray rolePermissions;

				if (variant->variantType() != OpcUaBuildInType_OpcUaExtensionObject) return true;
				auto rolePermissionsAttribut = reinterpret_cast<RolePermissionsAttribute*>(&attribute);

				for (uint32_t idx=0; idx < variant->arrayLength(); idx++) {
					auto extensionObject = variant->variantSPtr<OpcUaExtensionObject>(idx);
					if (extensionObject->typeId() != OpcUaNodeId(OpcUaId_OpcUa_BinarySchema_RolePermissionType)) {
						return true;
					}
					auto rolePermission = extensionObject->parameter<RolePermissionType>();

					rolePermissions.push_back(rolePermission);
				}

				return rolePermissions == rolePermissionsAttribut->data();
			}
			case AttributeId_UserRolePermissions:
			{
				RolePermissionTypeArray userRolePermissions;

				if (variant->variantType() != OpcUaBuildInType_OpcUaExtensionObject) return true;
				auto userRolePermissionsAttribut = reinterpret_cast<UserRolePermissionsAttribute*>(&attribute);

				for (uint32_t idx=0; idx < variant->arrayLength(); idx++) {
					auto extensionObject = variant->variantSPtr<OpcUaExtensionObject>(idx);
					if (extensionObject->typeId() != OpcUaNodeId(OpcUaId_OpcUa_BinarySchema_RolePermissionType)) {
						return true;
					}
					auto userRolePermission = extensionObject->parameter<RolePermissionType>();

					userRolePermissions.push_back(userRolePermission);
				}

				return userRolePermissions == userRolePermissionsAttribut->data();
			}
			case AttributeId_AccessRestrictions:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaUInt16) return true;
				auto accessRestrictionsAttribute = reinterpret_cast<AccessRestrictionsAttribute*>(&attribute);
				auto accessRestrictions = variant->variant<OpcUaUInt16>();
				return accessRestrictions == accessRestrictionsAttribute->data();
			}
			case AttributeId_AccessLevelEx:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaUInt32) return true;
				auto accessLevelExAttribute = reinterpret_cast<AccessLevelExAttribute*>(&attribute);
				auto accessLevelEx = variant->variant<OpcUaUInt32>();
				return accessLevelEx == accessLevelExAttribute->data();
			}
			default:
			{
				return false;
			}
		}
	}

}
