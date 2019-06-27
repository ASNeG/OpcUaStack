/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/thread.hpp>
#include <boost/thread/shared_mutex.hpp>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeBase.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	AttributeBase::AttributeBase(void)
	: mutex_()
	{
	}

	AttributeBase::~AttributeBase(void)
	{
	}

	void
	AttributeBase::lock(void)
	{
		mutex_.lock();
	}

	void
	AttributeBase::unlock(void)
	{
		mutex_.unlock();
	}

	boost::shared_mutex&
	AttributeBase::mutex(void)
	{
		return mutex_;
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
			case AttributeId_MinimumSamplingInterval: return minimumSamplingIntervalAttribute();
			case AttributeId_Historizing: return historizingAttribute();
			case AttributeId_Executable: return executableAttribute();
			case AttributeId_UserExecutable: return userExecutableAttribute();
		    default: return nullptr;
		}
	}

	bool
	AttributeBase::set(AttributeId attributeId, OpcUaDataValue::SPtr& dataValue)
	{
		if (dataValue.get() == nullptr) return false;
		OpcUaVariant::SPtr variant = dataValue->variant();
		if (variant.get() == nullptr) return false;
		if (variant->variantType() == 0) return false;

		//std::cout << "Type=" << variant->variantType() << std::endl;
		//std::cout << "AttributeId=" << attributeId << std::endl;
		//std::cout << "DataValue="; dataValue->out(std::cout); std::cout << std::endl;

		switch (attributeId)
		{
			case AttributeId_NodeId:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaNodeId) {
					Log(Error, "data type error")
						.parameter("Attribute", "NodeId")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaNodeId));
					return false;
				}

				if (!isPartNodeId()) return false;
				OpcUaNodeId::SPtr nodeId = variant->variantSPtr<OpcUaNodeId>();
				return setNodeId(*nodeId);
			}
			case AttributeId_NodeClass:
			{
				if (!isPartNodeClass()) return false;
			    NodeClassType nodeClassType = variant->variantSPtr<NodeClass>()->nodeClassType();
				return setNodeClass(nodeClassType);
			}
			case AttributeId_BrowseName:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaQualifiedName) {
					Log(Error, "data type error")
						.parameter("Attribute", "BrowseName")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaQualifiedName));
					return false;
				}

				if (!isPartBrowseName()) return false;
				OpcUaQualifiedName::SPtr browseName = variant->variantSPtr<OpcUaQualifiedName>();
				return setBrowseName(*browseName);
			}
			case AttributeId_DisplayName:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaLocalizedText) {
					Log(Error, "data type error")
						.parameter("Attribute", "DisplayName")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaLocalizedText));
					return false;
				}

				if (!isPartDisplayName()) return false;
				OpcUaLocalizedText::SPtr displayName = variant->variantSPtr<OpcUaLocalizedText>();
				return setDisplayName(*displayName);
			}
			case AttributeId_Description:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaLocalizedText) {
					Log(Error, "data type error")
						.parameter("Attribute", "Description")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaLocalizedText));
					return false;
				}

				if (!isPartDescription()) return false;
				OpcUaLocalizedText::SPtr description = variant->variantSPtr<OpcUaLocalizedText>();
				return setDescription(*description);
			}
			case AttributeId_WriteMask:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaUInt32) {
					Log(Error, "data type error")
						.parameter("Attribute", "WriteMask")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaUInt32));
					return false;
				}

				if (!isPartWriteMask()) return false;
				OpcUaUInt32 writeMask = variant->variant<OpcUaUInt32>();
				return setWriteMask(writeMask);
			}
			case AttributeId_UserWriteMask:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaUInt32) {
					Log(Error, "data type error")
						.parameter("Attribute", "UserWriteMask")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaUInt32));
					return false;
				}

				if (!isPartUserWriteMask()) return false;
				OpcUaUInt32 userWriteMask = variant->variant<OpcUaUInt32>();
				return setUserWriteMask(userWriteMask);
			}
			case AttributeId_IsAbstract:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaBoolean) {
					Log(Error, "data type error")
						.parameter("Attribute", "IsAbstract")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaBoolean));
					return false;
				}

				if (!isPartIsAbstract()) return false;
				OpcUaBoolean isAbstract = variant->variant<OpcUaBoolean>();
				return setIsAbstract(isAbstract);
			}
			case AttributeId_Symmetric:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaBoolean) {
					Log(Error, "data type error")
						.parameter("Attribute", "Symmetric")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaBoolean));
					return false;
				}

				if (!isPartSymmetric()) return false;
				OpcUaBoolean symmetric = variant->variant<OpcUaBoolean>();
				return setSymmetric(symmetric);
			}
			case AttributeId_InverseName:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaLocalizedText) {
					Log(Error, "data type error")
						.parameter("Attribute", "InverseName")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaLocalizedText));
					return false;
				}

				if (!isPartInverseName()) return false;
				OpcUaLocalizedText::SPtr inverseName = variant->variantSPtr<OpcUaLocalizedText>();
				return setInverseName(*inverseName);
			}
			case AttributeId_ContainsNoLoops:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaBoolean) {
					Log(Error, "data type error")
						.parameter("Attribute", "ContainsNoLoops")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaBoolean));
					return false;
				}

				if (!isPartContainsNoLoops()) return false;
				OpcUaBoolean containsNoLoops = variant->variant<OpcUaBoolean>();
				return setContainsNoLoops(containsNoLoops);
			}
			case AttributeId_EventNotifier:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaByte) {
					Log(Error, "data type error")
						.parameter("Attribute", "EventNotifier")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaByte));
					return false;
				}

				if (!isPartEventNotifier()) return false;
				OpcUaByte eventNotifier = variant->variant<OpcUaByte>();
				return setEventNotifier(eventNotifier);
			}
			case AttributeId_Value:
			{
				if (!isPartValue()) return false;
				return setValue(*dataValue);
			}
			case AttributeId_DataType:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaNodeId) {
					Log(Error, "data type error")
						.parameter("Attribute", "DataType")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaNodeId));
					return false;
				}

				if (!isPartDataType()) return false;
				OpcUaNodeId::SPtr dataType = variant->variantSPtr<OpcUaNodeId>();
				return setDataType(*dataType);
			}
			case AttributeId_ValueRank:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaInt32) {
					Log(Error, "data type error")
						.parameter("Attribute", "ValueRank")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaInt32));
					return false;
				}

				if (!isPartValueRank()) return false;
				OpcUaInt32 valueRank = variant->variant<OpcUaInt32>();
				return setValueRank(valueRank);
			}
			case AttributeId_ArrayDimensions:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaUInt32) {
					Log(Error, "data type error")
						.parameter("Attribute", "ArrayDimensions")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaUInt32));
					return false;
				}

				if (!isPartArrayDimensions()) return false;
				OpcUaUInt32Array::SPtr arrayDimensions = constructSPtr<OpcUaUInt32Array>();
				arrayDimensions->resize(variant->arrayLength());
				for (uint32_t idx = 0; idx < variant->arrayLength(); idx++) {
					OpcUaUInt32 arrayDimension = variant->get<OpcUaUInt32>(idx);
					arrayDimensions->push_back(arrayDimension);
				}
				return setArrayDimensions(*arrayDimensions);
			}
			case AttributeId_AccessLevel:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaByte) {
					Log(Error, "data type error")
						.parameter("Attribute", "AccessLevel")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaByte));
					return false;
				}

				if (!isPartAccessLevel()) return false;
				OpcUaByte accessLevel = variant->variant<OpcUaByte>();
				return setAccessLevel(accessLevel);
			}
			case AttributeId_UserAccessLevel:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaByte) {
					Log(Error, "data type error")
						.parameter("Attribute", "UserAccessLevel")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaByte));
					return false;
				}

				if (!isPartUserAccessLevel()) return false;
				OpcUaByte userAccessLevel = variant->variant<OpcUaByte>();
				return setUserAccessLevel(userAccessLevel);
			}
			case AttributeId_MinimumSamplingInterval:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaDouble) {
					Log(Error, "data type error")
						.parameter("Attribute", "SamplingInterval")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaDouble));
					return false;
				}

				if (!isPartMinimumSamplingInterval()) return false;
				OpcUaDouble minimumSamplingInterval = variant->variant<OpcUaDouble>();
				return setMinimumSamplingInterval(minimumSamplingInterval);
			}
			case AttributeId_Historizing:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaBoolean) {
					Log(Error, "data type error")
						.parameter("Attribute", "Historizing")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaBoolean));
					return false;
				}

				if (!isPartHistorizing()) return false;
				OpcUaBoolean historizing = variant->variant<OpcUaBoolean>();
				return setHistorizing(historizing);
			}
			case AttributeId_Executable:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaBoolean) {
					Log(Error, "data type error")
						.parameter("Attribute", "Executable")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaBoolean));
					return false;
				}

				if (!isPartExecutable()) return false;
				OpcUaBoolean executable = variant->variant<OpcUaBoolean>();
				return setExecutable(executable);
			}
			case AttributeId_UserExecutable:
			{
				if (variant->variantType() != OpcUaBuildInType_OpcUaBoolean) {
					Log(Error, "data type error")
						.parameter("Attribute", "UserExecutable")
						.parameter("ActualType", OpcUaBuildInTypeMap::buildInType2String(variant->variantType()))
						.parameter("ExpectedType", OpcUaBuildInTypeMap::buildInType2String(OpcUaBuildInType_OpcUaBoolean));
					return false;
				}

				if (!isPartUserExecutable()) return false;
				OpcUaBoolean userExecutable = variant->variant<OpcUaBoolean>();
				return setUserExecutable(userExecutable);
			}
		    default: return false;
		}

		return false;
	}

	//
	// node id
	//
	Attribute* 
	AttributeBase::nodeIdAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetNodeId(void)
	{
		if (!isPartNodeId()) return false;
		NodeIdAttribute* attr = reinterpret_cast<NodeIdAttribute*>(nodeIdAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setNodeIdSync(OpcUaNodeId& nodeId)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setNodeId(nodeId);
	}

	bool
	AttributeBase::setNodeId(OpcUaNodeId& nodeId)
	{
		if (!isPartNodeId()) return false;
		NodeIdAttribute* attr = reinterpret_cast<NodeIdAttribute*>(nodeIdAttribute());
		nodeId.copyTo(attr->data());
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getNodeIdSync(OpcUaNodeId& nodeId)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getNodeId(nodeId);
	}

	bool
	AttributeBase::getNodeId(OpcUaNodeId& nodeId)
	{
		if (!isPartNodeId()) return false;

		NodeIdAttribute* attr = reinterpret_cast<NodeIdAttribute*>(nodeIdAttribute());
		if (!attr->exist()) return false;
		attr->data().copyTo(nodeId);
		return true;
	}

	bool
	AttributeBase::isNullNodeId(void)
	{
		if (!isPartNodeId()) return false;
		NodeIdAttribute* attr = reinterpret_cast<NodeIdAttribute*>(nodeIdAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartNodeId(void)
	{
		return (nodeIdAttribute() != nullptr);
	}

	boost::optional<OpcUaNodeId&>
	AttributeBase::getNodeId(void)
	{
		if (isNullNodeId()) return boost::none;
		NodeIdAttribute* attr = reinterpret_cast<NodeIdAttribute*>(nodeIdAttribute());
		return attr->data();
	}

	//
	// node class
	//
	Attribute* 
	AttributeBase::nodeClassAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetNodeClass(void)
	{
		if (!isPartNodeClass()) return false;
		NodeClassAttribute* attr = reinterpret_cast<NodeClassAttribute*>(nodeClassAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setNodeClassSync(NodeClassType& nodeClass)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setNodeClass(nodeClass);
	}

	bool
	AttributeBase::setNodeClass(NodeClassType& nodeClass)
	{
		if (!isPartNodeClass()) return false;
		NodeClassAttribute* attr = reinterpret_cast<NodeClassAttribute*>(nodeClassAttribute());
		attr->data(nodeClass);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getNodeClassSync(NodeClassType& nodeClass)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getNodeClass(nodeClass);
	}

	bool
	AttributeBase::getNodeClass(NodeClassType& nodeClass)
	{
		if (!isPartNodeClass()) return false;

		NodeClassAttribute* attr = reinterpret_cast<NodeClassAttribute*>(nodeClassAttribute());
		if (!attr->exist()) return false;
		nodeClass = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullNodeClass(void)
	{
		if (!isPartNodeClass()) return false;
		NodeClassAttribute* attr = reinterpret_cast<NodeClassAttribute*>(nodeClassAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartNodeClass(void)
	{
		return (nodeClassAttribute() != nullptr);
	}

	boost::optional<NodeClassType&>
	AttributeBase::getNodeClass(void)
	{
		if (isNullNodeClass()) return boost::none;
		NodeClassAttribute* attr = reinterpret_cast<NodeClassAttribute*>(nodeClassAttribute());
		return attr->data();
	}

	//
	// browse name
	//
	Attribute* 
	AttributeBase::browseNameAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetBrowseName(void)
	{
		if (!isPartBrowseName()) return false;
		BrowseNameAttribute* attr = reinterpret_cast<BrowseNameAttribute*>(browseNameAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setBrowseNameSync(OpcUaQualifiedName& browseName)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setBrowseName(browseName);
	}

	bool
	AttributeBase::setBrowseName(OpcUaQualifiedName& browseName)
	{
		if (!isPartBrowseName()) return false;
		BrowseNameAttribute* attr = reinterpret_cast<BrowseNameAttribute*>(browseNameAttribute());
		browseName.copyTo(attr->data());
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getBrowseNameSync(OpcUaQualifiedName& browseName)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getBrowseName(browseName);
	}

	bool
	AttributeBase::getBrowseName(OpcUaQualifiedName& browseName)
	{
		if (!isPartBrowseName()) return false;

		BrowseNameAttribute* attr = reinterpret_cast<BrowseNameAttribute*>(browseNameAttribute());
		if (!attr->exist()) return false;
		attr->data().copyTo(browseName);
		return true;
	}

	bool
	AttributeBase::isNullBrowseName(void)
	{
		if (!isPartBrowseName()) return false;
		BrowseNameAttribute* attr = reinterpret_cast<BrowseNameAttribute*>(browseNameAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartBrowseName(void)
	{
		return (browseNameAttribute() != nullptr);
	}

	boost::optional<OpcUaQualifiedName&>
	AttributeBase::getBrowseName(void)
	{
		if (isNullBrowseName()) return boost::none;
		BrowseNameAttribute* attr = reinterpret_cast<BrowseNameAttribute*>(browseNameAttribute());
		return attr->data();
	}

	//
	// display name
	//
	Attribute* 
	AttributeBase::displayNameAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetDisplayName(void)
	{
		if (!isPartDisplayName()) return false;
		DisplayNameAttribute* attr = reinterpret_cast<DisplayNameAttribute*>(displayNameAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setDisplayNameSync(OpcUaLocalizedText& displayName)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setDisplayName(displayName);
	}

	bool
	AttributeBase::setDisplayName(OpcUaLocalizedText& displayName)
	{
		if (!isPartDisplayName()) return false;
		DisplayNameAttribute* attr = reinterpret_cast<DisplayNameAttribute*>(displayNameAttribute());
		displayName.copyTo(attr->data());
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getDisplayNameSync(OpcUaLocalizedText& displayName)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getDisplayName(displayName);
	}

	bool
	AttributeBase::getDisplayName(OpcUaLocalizedText& displayName)
	{
		if (!isPartDisplayName()) return false;

		DisplayNameAttribute* attr = reinterpret_cast<DisplayNameAttribute*>(displayNameAttribute());
		if (!attr->exist()) return false;
		attr->data().copyTo(displayName);
		return true;
	}

	bool
	AttributeBase::isNullDisplayName(void)
	{
		if (!isPartDisplayName()) return false;
		DisplayNameAttribute* attr = reinterpret_cast<DisplayNameAttribute*>(displayNameAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartDisplayName(void)
	{
		return (displayNameAttribute() != nullptr);
	}

	boost::optional<OpcUaLocalizedText&>
	AttributeBase::getDisplayName(void)
	{
		if (isNullDisplayName()) return boost::none;
		DisplayNameAttribute* attr = reinterpret_cast<DisplayNameAttribute*>(displayNameAttribute());
		return attr->data();
	}

	//
	// description
	//
	Attribute* 
	AttributeBase::descriptionAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetDescription(void)
	{
		if (!isPartDescription()) return false;
		DescriptionAttribute* attr = reinterpret_cast<DescriptionAttribute*>(descriptionAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setDescriptionSync(OpcUaLocalizedText& description)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setDescription(description);
	}

	bool
	AttributeBase::setDescription(OpcUaLocalizedText& description)
	{
		if (!isPartDescription()) return false;
		DescriptionAttribute* attr = reinterpret_cast<DescriptionAttribute*>(descriptionAttribute());
		description.copyTo(attr->data());
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getDescriptionSync(OpcUaLocalizedText& description)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getDescription(description);
	}

	bool
	AttributeBase::getDescription(OpcUaLocalizedText& description)
	{
		if (!isPartDescription()) return false;

		DescriptionAttribute* attr = reinterpret_cast<DescriptionAttribute*>(descriptionAttribute());
		if (!attr->exist()) return false;
		attr->data().copyTo(description);
		return true;
	}

	bool
	AttributeBase::isNullDescription(void)
	{
		if (!isPartDescription()) return false;
		DescriptionAttribute* attr = reinterpret_cast<DescriptionAttribute*>(descriptionAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartDescription(void)
	{
		return (descriptionAttribute() != nullptr);
	}

	boost::optional<OpcUaLocalizedText&>
	AttributeBase::getDescription(void)
	{
		if (isNullDescription()) return boost::none;
		DescriptionAttribute* attr = reinterpret_cast<DescriptionAttribute*>(descriptionAttribute());
		return attr->data();
	}

	//
	// write mask
	//
	Attribute* 
	AttributeBase::writeMaskAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetWriteMask(void)
	{
		if (!isPartWriteMask()) return false;
		WriteMaskAttribute* attr = reinterpret_cast<WriteMaskAttribute*>(writeMaskAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setWriteMaskSync(OpcUaUInt32 writeMask)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setWriteMask(writeMask);
	}

	bool
	AttributeBase::setWriteMask(OpcUaUInt32 writeMask)
	{
		if (!isPartWriteMask()) return false;
		WriteMaskAttribute* attr = reinterpret_cast<WriteMaskAttribute*>(writeMaskAttribute());
		attr->data(writeMask);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getWriteMaskSync(OpcUaUInt32& writeMask)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getWriteMask(writeMask);
	}

	bool
	AttributeBase::getWriteMask(OpcUaUInt32& writeMask)
	{
		if (!isPartWriteMask()) return false;

		WriteMaskAttribute* attr = reinterpret_cast<WriteMaskAttribute*>(writeMaskAttribute());
		if (!attr->exist()) return false;
		writeMask = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullWriteMask(void)
	{
		if (!isPartWriteMask()) return false;
		WriteMaskAttribute* attr = reinterpret_cast<WriteMaskAttribute*>(writeMaskAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartWriteMask(void)
	{
		return (writeMaskAttribute() != nullptr);
	}

	boost::optional<OpcUaUInt32&>
	AttributeBase::getWriteMask(void)
	{
		if (isNullWriteMask()) return boost::none;
		WriteMaskAttribute* attr = reinterpret_cast<WriteMaskAttribute*>(writeMaskAttribute());
		return attr->data();
	}

	//
	// user write mask
	//
	Attribute* 
	AttributeBase::userWriteMaskAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetUserWriteMask(void)
	{
		if (!isPartUserWriteMask()) return false;
		UserWriteMaskAttribute* attr = reinterpret_cast<UserWriteMaskAttribute*>(userWriteMaskAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setUserWriteMaskSync(OpcUaUInt32 userWriteMask)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setUserWriteMask(userWriteMask);
	}

	bool
	AttributeBase::setUserWriteMask(OpcUaUInt32 userWriteMask)
	{
		if (!isPartUserWriteMask()) return false;
		UserWriteMaskAttribute* attr = reinterpret_cast<UserWriteMaskAttribute*>(userWriteMaskAttribute());
		attr->data(userWriteMask);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getUserWriteMaskSync(OpcUaUInt32& userWriteMask)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getUserWriteMask(userWriteMask);
	}

	bool
	AttributeBase::getUserWriteMask(OpcUaUInt32& userWriteMask)
	{
		if (!isPartUserWriteMask()) return false;

		UserWriteMaskAttribute* attr = reinterpret_cast<UserWriteMaskAttribute*>(userWriteMaskAttribute());
		if (!attr->exist()) return false;
		userWriteMask = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullUserWriteMask(void)
	{
		if (!isPartUserWriteMask()) return false;
		UserWriteMaskAttribute* attr = reinterpret_cast<UserWriteMaskAttribute*>(userWriteMaskAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartUserWriteMask(void)
	{
		return (userWriteMaskAttribute() != nullptr);
	}

	boost::optional<OpcUaUInt32&>
	AttributeBase::getUserWriteMask(void)
	{
		if (isNullUserWriteMask()) return boost::none;
		UserWriteMaskAttribute* attr = reinterpret_cast<UserWriteMaskAttribute*>(userWriteMaskAttribute());
		return attr->data();
	}

	//
	// is abstract
	//
	Attribute* 
	AttributeBase::isAbstractAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetIsAbstract(void)
	{
		if (!isPartIsAbstract()) return false;
		IsAbstractAttribute* attr = reinterpret_cast<IsAbstractAttribute*>(isAbstractAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setIsAbstractSync(OpcUaBoolean& isAbstract)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setIsAbstract(isAbstract);
	}

	bool
	AttributeBase::setIsAbstract(OpcUaBoolean& isAbstract)
	{
		if (!isPartIsAbstract()) return false;
		IsAbstractAttribute* attr = reinterpret_cast<IsAbstractAttribute*>(isAbstractAttribute());
		attr->data(isAbstract);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getIsAbstractSync(OpcUaBoolean& isAbstract)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getIsAbstract(isAbstract);
	}

	bool
	AttributeBase::getIsAbstract(OpcUaBoolean& isAbstract)
	{
		if (!isPartIsAbstract()) return false;

		IsAbstractAttribute* attr = reinterpret_cast<IsAbstractAttribute*>(isAbstractAttribute());
		if (!attr->exist()) return false;
		isAbstract = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullIsAbstract(void)
	{
		if (!isPartIsAbstract()) return false;
		IsAbstractAttribute* attr = reinterpret_cast<IsAbstractAttribute*>(isAbstractAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartIsAbstract(void)
	{
		return (isAbstractAttribute() != nullptr);
	}

	boost::optional<OpcUaBoolean&>
	AttributeBase::getIsAbstract(void)
	{
		if (isNullIsAbstract()) return boost::none;
		IsAbstractAttribute* attr = reinterpret_cast<IsAbstractAttribute*>(isAbstractAttribute());
		return attr->data();
	}

	//
	// symmetric
	//
	Attribute* 
	AttributeBase::symmetricAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetSymmetric(void)
	{
		if (!isPartSymmetric()) return false;
		SymmetricAttribute* attr = reinterpret_cast<SymmetricAttribute*>(symmetricAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setSymmetricSync(OpcUaBoolean& symmetric)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setSymmetric(symmetric);
	}

	bool
	AttributeBase::setSymmetric(OpcUaBoolean& symmetric)
	{
		if (!isPartSymmetric()) return false;
		SymmetricAttribute* attr = reinterpret_cast<SymmetricAttribute*>(symmetricAttribute());
		attr->data(symmetric);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getSymmetricSync(OpcUaBoolean& symmetric)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getSymmetric(symmetric);
	}

	bool
	AttributeBase::getSymmetric(OpcUaBoolean& symmetric)
	{
		if (!isPartSymmetric()) return false;

		SymmetricAttribute* attr = reinterpret_cast<SymmetricAttribute*>(symmetricAttribute());
		if (!attr->exist()) return false;
		symmetric = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullSymmetric(void)
	{
		if (!isPartSymmetric()) return false;
		SymmetricAttribute* attr = reinterpret_cast<SymmetricAttribute*>(symmetricAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartSymmetric(void)
	{
		return (symmetricAttribute() != nullptr);
	}

	boost::optional<OpcUaBoolean&>
	AttributeBase::getSymmetric(void)
	{
		if (isNullSymmetric()) return boost::none;
		SymmetricAttribute* attr = reinterpret_cast<SymmetricAttribute*>(symmetricAttribute());
		return attr->data();
	}


	//
	// inverse name
	//
	Attribute* 
	AttributeBase::inverseNameAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetInverseName(void)
	{
		if (!isPartInverseName()) return false;
		InverseNameAttribute* attr = reinterpret_cast<InverseNameAttribute*>(inverseNameAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setInverseNameSync(OpcUaLocalizedText& inverseName)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setInverseName(inverseName);
	}

	bool
	AttributeBase::setInverseName(OpcUaLocalizedText& inverseName)
	{
		if (!isPartInverseName()) return false;
		InverseNameAttribute* attr = reinterpret_cast<InverseNameAttribute*>(inverseNameAttribute());
		inverseName.copyTo(attr->data());
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getInverseNameSync(OpcUaLocalizedText& inverseName)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getInverseName(inverseName);
	}

	bool
	AttributeBase::getInverseName(OpcUaLocalizedText& inverseName)
	{
		if (!isPartInverseName()) return false;

		InverseNameAttribute* attr = reinterpret_cast<InverseNameAttribute*>(inverseNameAttribute());
		if (!attr->exist()) return false;
		attr->data().copyTo(inverseName);
		return true;
	}

	bool
	AttributeBase::isNullInverseName(void)
	{
		if (!isPartInverseName()) return false;
		InverseNameAttribute* attr = reinterpret_cast<InverseNameAttribute*>(inverseNameAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartInverseName(void)
	{
		return (inverseNameAttribute() != nullptr);
	}

	boost::optional<OpcUaLocalizedText&>
	AttributeBase::getInverseName(void)
	{
		if (isNullInverseName()) return boost::none;
		InverseNameAttribute* attr = reinterpret_cast<InverseNameAttribute*>(inverseNameAttribute());
		return attr->data();
	}


	//
	// contains no loops
	//
	Attribute* 
	AttributeBase::containsNoLoopsAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetContainsNoLoops(void)
	{
		if (!isPartContainsNoLoops()) return false;
		ContainsNoLoopsAttribute* attr = reinterpret_cast<ContainsNoLoopsAttribute*>(containsNoLoopsAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setContainsNoLoopsSync(OpcUaBoolean& containsNoLoops)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setContainsNoLoops(containsNoLoops);
	}

	bool
	AttributeBase::setContainsNoLoops(OpcUaBoolean& containsNoLoops)
	{
		if (!isPartContainsNoLoops()) return false;
		ContainsNoLoopsAttribute* attr = reinterpret_cast<ContainsNoLoopsAttribute*>(containsNoLoopsAttribute());
		attr->data(containsNoLoops);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getContainsNoLoopsSync(OpcUaBoolean& containsNoLoops)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getContainsNoLoops(containsNoLoops);
	}

	bool
	AttributeBase::getContainsNoLoops(OpcUaBoolean& containsNoLoops)
	{
		if (!isPartContainsNoLoops()) return false;

		ContainsNoLoopsAttribute* attr = reinterpret_cast<ContainsNoLoopsAttribute*>(containsNoLoopsAttribute());
		if (!attr->exist()) return false;
		containsNoLoops = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullContainsNoLoops(void)
	{
		if (!isPartContainsNoLoops()) return false;
		ContainsNoLoopsAttribute* attr = reinterpret_cast<ContainsNoLoopsAttribute*>(containsNoLoopsAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartContainsNoLoops(void)
	{
		return (containsNoLoopsAttribute() != nullptr);
	}

	boost::optional<OpcUaBoolean&>
	AttributeBase::getContainsNoLoops(void)
	{
		if (isNullContainsNoLoops()) return boost::none;
		ContainsNoLoopsAttribute* attr = reinterpret_cast<ContainsNoLoopsAttribute*>(containsNoLoopsAttribute());
		return attr->data();
	}

	//
	// event notifier
	//
	Attribute* 
	AttributeBase::eventNotifierAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetEventNotifier(void)
	{
		if (!isPartEventNotifier()) return false;
		EventNotifierAttribute* attr = reinterpret_cast<EventNotifierAttribute*>(eventNotifierAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setEventNotifierSync(OpcUaByte eventNotifier)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setEventNotifier(eventNotifier);
	}

	bool
	AttributeBase::setEventNotifier(OpcUaByte eventNotifier)
	{
		if (!isPartEventNotifier()) return false;
		EventNotifierAttribute* attr = reinterpret_cast<EventNotifierAttribute*>(eventNotifierAttribute());
		attr->data(eventNotifier);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getEventNotifierSync(OpcUaByte& eventNotifier)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getEventNotifier(eventNotifier);
	}

	bool
	AttributeBase::getEventNotifier(OpcUaByte& eventNotifier)
	{
		if (!isPartEventNotifier()) return false;

		EventNotifierAttribute* attr = reinterpret_cast<EventNotifierAttribute*>(eventNotifierAttribute());
		if (!attr->exist()) return false;
		eventNotifier = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullEventNotifier(void)
	{
		if (!isPartEventNotifier()) return false;
		EventNotifierAttribute* attr = reinterpret_cast<EventNotifierAttribute*>(eventNotifierAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartEventNotifier(void)
	{
		return (eventNotifierAttribute() != nullptr);
	}

	boost::optional<OpcUaByte&>
	AttributeBase::getEventNotifier(void)
	{
		if (isNullEventNotifier()) return boost::none;
		EventNotifierAttribute* attr = reinterpret_cast<EventNotifierAttribute*>(eventNotifierAttribute());
		return attr->data();
	}

	//
	// value
	//
	Attribute*
	AttributeBase::valueAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetValue(void)
	{
		if (!isPartValue()) return false;
		ValueAttribute* attr = reinterpret_cast<ValueAttribute*>(valueAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setValueSync(const OpcUaDataValue& value)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setValue(value);
	}

	bool
	AttributeBase::setValue(const OpcUaDataValue& value)
	{
		if (!isPartValue()) return false;
		ValueAttribute* attr = reinterpret_cast<ValueAttribute*>(valueAttribute());
		const_cast<OpcUaDataValue*>(&value)->copyTo(attr->data());
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getValueSync(OpcUaDataValue& value)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getValue(value);
	}

	bool
	AttributeBase::getValue(OpcUaDataValue& value)
	{
		if (!isPartValue()) return false;

		ValueAttribute* attr = reinterpret_cast<ValueAttribute*>(valueAttribute());
		if (!attr->exist()) return false;
		attr->data().copyTo(value);
		return true;
	}

	bool
	AttributeBase::isNullValue(void)
	{
		if (!isPartValue()) return false;  // FIXME: wrong result ...
		ValueAttribute* attr = reinterpret_cast<ValueAttribute*>(valueAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartValue(void)
	{
		return (valueAttribute() != nullptr);
	}

	boost::optional<OpcUaDataValue&>
	AttributeBase::getValue(void)
	{
		if (isNullValue()) return boost::none;
		ValueAttribute* attr = reinterpret_cast<ValueAttribute*>(valueAttribute());
		return attr->data();
	}


	//
	// datat type
	//
	Attribute* 
	AttributeBase::dataTypeAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetDataType(void)
	{
		if (!isPartDataType()) return false;
		DataTypeAttribute* attr = reinterpret_cast<DataTypeAttribute*>(dataTypeAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setDataTypeSync(OpcUaNodeId& dataType)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setDataType(dataType);
	}

	bool
	AttributeBase::setDataType(OpcUaNodeId& dataType)
	{
		if (!isPartDataType()) return false;
		DataTypeAttribute* attr = reinterpret_cast<DataTypeAttribute*>(dataTypeAttribute());
		dataType.copyTo(attr->data());
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getDataTypeSync(OpcUaNodeId& dataType)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getDataType(dataType);
	}

	bool
	AttributeBase::getDataType(OpcUaNodeId& dataType)
	{
		if (!isPartDataType()) return false;

		DataTypeAttribute* attr = reinterpret_cast<DataTypeAttribute*>(dataTypeAttribute());
		if (!attr->exist()) return false;
		attr->data().copyTo(dataType);
		return true;
	}

	bool
	AttributeBase::isNullDataType(void)
	{
		if (!isPartDataType()) return false;
		DataTypeAttribute* attr = reinterpret_cast<DataTypeAttribute*>(dataTypeAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartDataType(void)
	{
		return (dataTypeAttribute() != nullptr);
	}

	boost::optional<OpcUaNodeId&>
	AttributeBase::getDataType(void)
	{
		if (isNullDataType()) return boost::none;
		DataTypeAttribute* attr = reinterpret_cast<DataTypeAttribute*>(dataTypeAttribute());
		return attr->data();
	}

	//
	// value rank
	//
	Attribute* 
	AttributeBase::valueRankAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetValueRank(void)
	{
		if (!isPartValueRank()) return false;
		ValueRankAttribute* attr = reinterpret_cast<ValueRankAttribute*>(valueRankAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setValueRankSync(OpcUaInt32& valueRank)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setValueRank(valueRank);
	}

	bool
	AttributeBase::setValueRank(OpcUaInt32& valueRank)
	{
		if (!isPartValueRank()) return false;
		ValueRankAttribute* attr = reinterpret_cast<ValueRankAttribute*>(valueRankAttribute());
		attr->data(valueRank);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getValueRankSync(OpcUaInt32& valueRank)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getValueRank(valueRank);
	}

	bool
	AttributeBase::getValueRank(OpcUaInt32& valueRank)
	{
		if (!isPartValueRank()) return false;

		ValueRankAttribute* attr = reinterpret_cast<ValueRankAttribute*>(valueRankAttribute());
		if (!attr->exist()) return false;
		valueRank = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullValueRank(void)
	{
		if (!isPartValueRank()) return false;
		ValueRankAttribute* attr = reinterpret_cast<ValueRankAttribute*>(valueRankAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartValueRank(void)
	{
		return (valueRankAttribute() != nullptr);
	}

	boost::optional<OpcUaInt32&>
	AttributeBase::getValueRank(void)
	{
		if (isNullValueRank()) return boost::none;
		ValueRankAttribute* attr = reinterpret_cast<ValueRankAttribute*>(valueRankAttribute());
		return attr->data();
	}

	//
	// array dimensions
	//
	Attribute* 
	AttributeBase::arrayDimensionsAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetArrayDimensions(void)
	{
		if (!isPartArrayDimensions()) return false;
		ArrayDimensionsAttribute* attr = reinterpret_cast<ArrayDimensionsAttribute*>(arrayDimensionsAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setArrayDimensionsSync(OpcUaUInt32Array& arrayDimensions)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setArrayDimensions(arrayDimensions);
	}

	bool
	AttributeBase::setArrayDimensions(OpcUaUInt32Array& arrayDimensions)
	{
		if (!isPartArrayDimensions()) return false;
		ArrayDimensionsAttribute* attr = reinterpret_cast<ArrayDimensionsAttribute*>(arrayDimensionsAttribute());
		arrayDimensions.copyTo(attr->data());
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getArrayDimensionsSync(OpcUaUInt32Array& arrayDimensions)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getArrayDimensions(arrayDimensions);
	}

	bool
	AttributeBase::getArrayDimensions(OpcUaUInt32Array& arrayDimensions)
	{
		if (!isPartArrayDimensions()) return false;

		ArrayDimensionsAttribute* attr = reinterpret_cast<ArrayDimensionsAttribute*>(arrayDimensionsAttribute());
		if (!attr->exist()) return false;
		attr->data().copyTo(arrayDimensions);
		return true;
	}

	bool
	AttributeBase::isNullArrayDimensions(void)
	{
		if (!isPartArrayDimensions()) return false;
		ArrayDimensionsAttribute* attr = reinterpret_cast<ArrayDimensionsAttribute*>(arrayDimensionsAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartArrayDimensions(void)
	{
		return (arrayDimensionsAttribute() != nullptr);
	}

	boost::optional<OpcUaUInt32Array&>
	AttributeBase::getArrayDimensions(void)
	{
		if (isNullArrayDimensions()) return boost::none;
		ArrayDimensionsAttribute* attr = reinterpret_cast<ArrayDimensionsAttribute*>(arrayDimensionsAttribute());
		return attr->data();
	}

	//
	// access level
	//
	Attribute* 
	AttributeBase::accessLevelAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetAccessLevel(void)
	{
		if (!isPartAccessLevel()) return false;
		AccessLevelAttribute* attr = reinterpret_cast<AccessLevelAttribute*>(accessLevelAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setAccessLevelSync(OpcUaByte& accessLevel)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setAccessLevel(accessLevel);
	}

	bool
	AttributeBase::setAccessLevel(OpcUaByte& accessLevel)
	{
		if (!isPartAccessLevel()) return false;
		AccessLevelAttribute* attr = reinterpret_cast<AccessLevelAttribute*>(accessLevelAttribute());
		attr->data(accessLevel);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getAccessLevelSync(OpcUaByte& accessLevel)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getAccessLevel(accessLevel);
	}

	bool
	AttributeBase::getAccessLevel(OpcUaByte& accessLevel)
	{
		if (!isPartAccessLevel()) return false;

		AccessLevelAttribute* attr = reinterpret_cast<AccessLevelAttribute*>(accessLevelAttribute());
		if (!attr->exist()) return false;
		accessLevel = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullAccessLevel(void)
	{
		if (!isPartAccessLevel()) return false;
		AccessLevelAttribute* attr = reinterpret_cast<AccessLevelAttribute*>(accessLevelAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartAccessLevel(void)
	{
		return (arrayDimensionsAttribute() != nullptr);
	}

	boost::optional<OpcUaByte&>
	AttributeBase::getAccessLevel(void)
	{
		if (isNullAccessLevel()) return boost::none;
		AccessLevelAttribute* attr = reinterpret_cast<AccessLevelAttribute*>(accessLevelAttribute());
		return attr->data();
	}

	//
	// user access level
	//
	Attribute*
	AttributeBase::userAccessLevelAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetUserAccessLevel(void)
	{
		if (!isPartUserAccessLevel()) return false;
		UserAccessLevelAttribute* attr = reinterpret_cast<UserAccessLevelAttribute*>(userAccessLevelAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setUserAccessLevelSync(OpcUaByte& userAccessLevel)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setUserAccessLevel(userAccessLevel);
	}

	bool
	AttributeBase::setUserAccessLevel(OpcUaByte& userAccessLevel)
	{
		if (!isPartUserAccessLevel()) return false;
		UserAccessLevelAttribute* attr = reinterpret_cast<UserAccessLevelAttribute*>(userAccessLevelAttribute());
		attr->data(userAccessLevel);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getUserAccessLevelSync(OpcUaByte& userAccessLevel)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getUserAccessLevel(userAccessLevel);
	}

	bool
	AttributeBase::getUserAccessLevel(OpcUaByte& userAccessLevel)
	{
		if (!isPartUserAccessLevel()) return false;

		UserAccessLevelAttribute* attr = reinterpret_cast<UserAccessLevelAttribute*>(userAccessLevelAttribute());
		if (!attr->exist()) return false;
		userAccessLevel = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullUserAccessLevel(void)
	{
		if (!isPartUserAccessLevel()) return false;
		UserAccessLevelAttribute* attr = reinterpret_cast<UserAccessLevelAttribute*>(userAccessLevelAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartUserAccessLevel(void)
	{
		return (arrayDimensionsAttribute() != nullptr);
	}

	boost::optional<OpcUaByte&>
	AttributeBase::getUserAccessLevel(void)
	{
		if (isNullUserAccessLevel()) return boost::none;
		UserAccessLevelAttribute* attr = reinterpret_cast<UserAccessLevelAttribute*>(userAccessLevelAttribute());
		return attr->data();
	}

	//
	// historizing
	//
	Attribute* 
	AttributeBase::historizingAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetHistorizing(void)
	{
		if (!isPartHistorizing()) return false;
		HistorizingAttribute* attr = reinterpret_cast<HistorizingAttribute*>(historizingAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setHistorizingSync(OpcUaBoolean& historizing)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setHistorizing(historizing);
	}

	bool
	AttributeBase::setHistorizing(OpcUaBoolean& historizing)
	{
		if (!isPartHistorizing()) return false;
		HistorizingAttribute* attr = reinterpret_cast<HistorizingAttribute*>(historizingAttribute());
		attr->data(historizing);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getHistorizingSync(OpcUaBoolean& historizing)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getHistorizing(historizing);
	}

	bool
	AttributeBase::getHistorizing(OpcUaBoolean& historizing)
	{
		if (!isPartHistorizing()) return false;

		HistorizingAttribute* attr = reinterpret_cast<HistorizingAttribute*>(historizingAttribute());
		if (!attr->exist()) return false;
		historizing = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullHistorizing(void)
	{
		if (!isPartHistorizing()) return false;
		HistorizingAttribute* attr = reinterpret_cast<HistorizingAttribute*>(historizingAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartHistorizing(void)
	{
		return (arrayDimensionsAttribute() != nullptr);
	}

	boost::optional<OpcUaBoolean&>
	AttributeBase::getHistorizing(void)
	{
		if (isNullHistorizing()) return boost::none;
		HistorizingAttribute* attr = reinterpret_cast<HistorizingAttribute*>(historizingAttribute());
		return attr->data();
	}

	//
	// executable
	//
	Attribute* 
	AttributeBase::executableAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetExecutable(void)
	{
		if (!isPartExecutable()) return false;
		ExecutableAttribute* attr = reinterpret_cast<ExecutableAttribute*>(executableAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setExecutableSync(OpcUaBoolean& executable)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setExecutable(executable);
	}

	bool
	AttributeBase::setExecutable(OpcUaBoolean& executable)
	{
		if (!isPartExecutable()) return false;
		ExecutableAttribute* attr = reinterpret_cast<ExecutableAttribute*>(executableAttribute());
		attr->data(executable);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getExecutableSync(OpcUaBoolean& executable)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getExecutable(executable);
	}

	bool
	AttributeBase::getExecutable(OpcUaBoolean& executable)
	{
		if (!isPartExecutable()) return false;

		ExecutableAttribute* attr = reinterpret_cast<ExecutableAttribute*>(executableAttribute());
		if (!attr->exist()) return false;
		executable = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullExecutable(void)
	{
		if (!isPartExecutable()) return false;
		ExecutableAttribute* attr = reinterpret_cast<ExecutableAttribute*>(executableAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartExecutable(void)
	{
		return (executableAttribute() != nullptr);
	}

	boost::optional<OpcUaBoolean&>
	AttributeBase::getExecutable(void)
	{
		if (isNullExecutable()) return boost::none;
		ExecutableAttribute* attr = reinterpret_cast<ExecutableAttribute*>(executableAttribute());
		return attr->data();
	}

	//
	// user executable
	//
	Attribute* 
	AttributeBase::userExecutableAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetUserExecutable(void)
	{
		if (!isPartUserExecutable()) return false;
		UserExecutableAttribute* attr = reinterpret_cast<UserExecutableAttribute*>(userExecutableAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setUserExecutableSync(OpcUaBoolean& userExecutable)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setUserExecutable(userExecutable);
	}

	bool
	AttributeBase::setUserExecutable(OpcUaBoolean& userExecutable)
	{
		if (!isPartUserExecutable()) return false;
		UserExecutableAttribute* attr = reinterpret_cast<UserExecutableAttribute*>(userExecutableAttribute());
		attr->data(userExecutable);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getUserExecutableSync(OpcUaBoolean& userExecutable)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getUserExecutable(userExecutable);
	}

	bool
	AttributeBase::getUserExecutable(OpcUaBoolean& userExecutable)
	{
		if (!isPartUserExecutable()) return false;

		UserExecutableAttribute* attr = reinterpret_cast<UserExecutableAttribute*>(userExecutableAttribute());
		if (!attr->exist()) return false;
		userExecutable = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullUserExecutable(void)
	{
		if (!isPartUserExecutable()) return false;
		UserExecutableAttribute* attr = reinterpret_cast<UserExecutableAttribute*>(userExecutableAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartUserExecutable(void)
	{
		return (userExecutableAttribute() != nullptr);
	}

	boost::optional<OpcUaBoolean&>
	AttributeBase::getUserExecutable(void)
	{
		if (isNullUserExecutable()) return boost::none;
		UserExecutableAttribute* attr = reinterpret_cast<UserExecutableAttribute*>(userExecutableAttribute());
		return attr->data();
	}

	//
	// minimum sminimumSamplingIntervalal
	//
	Attribute* 
	AttributeBase::minimumSamplingIntervalAttribute(void)
	{
		return nullptr;
	}

	bool
	AttributeBase::unsetMinimumSamplingInterval(void)
	{
		if (!isPartMinimumSamplingInterval()) return false;
		MinimumSamplingIntervalAttribute* attr = reinterpret_cast<MinimumSamplingIntervalAttribute*>(minimumSamplingIntervalAttribute());
		attr->exist(false);
		return true;
	}

	bool
	AttributeBase::setMinimumSamplingIntervalSync(OpcUaDouble& minimumSamplingInterval)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return setMinimumSamplingInterval(minimumSamplingInterval);
	}

	bool
	AttributeBase::setMinimumSamplingInterval(OpcUaDouble& minimumSamplingInterval)
	{
		if (!isPartMinimumSamplingInterval()) return false;
		MinimumSamplingIntervalAttribute* attr = reinterpret_cast<MinimumSamplingIntervalAttribute*>(minimumSamplingIntervalAttribute());
		attr->data(minimumSamplingInterval);
		attr->exist(true);
		return true;
	}

	bool
	AttributeBase::getMinimumSamplingIntervalSync(OpcUaDouble& minimumSamplingInterval)
	{
		boost::unique_lock<boost::shared_mutex> lock(mutex_);
		return getMinimumSamplingInterval(minimumSamplingInterval);
	}

	bool
	AttributeBase::getMinimumSamplingInterval(OpcUaDouble& minimumSamplingInterval)
	{
		if (!isPartMinimumSamplingInterval()) return false;

		MinimumSamplingIntervalAttribute* attr = reinterpret_cast<MinimumSamplingIntervalAttribute*>(minimumSamplingIntervalAttribute());
		if (!attr->exist()) return false;
		minimumSamplingInterval = attr->data();
		return true;
	}

	bool
	AttributeBase::isNullMinimumSamplingInterval(void)
	{
		if (!isPartMinimumSamplingInterval()) return false;
		MinimumSamplingIntervalAttribute* attr = reinterpret_cast<MinimumSamplingIntervalAttribute*>(minimumSamplingIntervalAttribute());
		return !attr->exist();
	}

	bool
	AttributeBase::isPartMinimumSamplingInterval(void)
	{
		return (arrayDimensionsAttribute() != nullptr);
	}

	boost::optional<OpcUaDouble&>
	AttributeBase::getMinimumSamplingInterval(void)
	{
		if (isNullMinimumSamplingInterval()) return boost::none;
		MinimumSamplingIntervalAttribute* attr = reinterpret_cast<MinimumSamplingIntervalAttribute*>(minimumSamplingIntervalAttribute());
		return attr->data();
	}

}
