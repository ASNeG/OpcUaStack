#include "OpcUaStackServer/AddressSpaceModel/AttributeBase.h"

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

	boost::mutex&
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
			case AttributeId_MinimumSamplingInterval: minimumSamplingIntervalAttribute();
			case AttributeId_Historizing: return historizingAttribute();
			case AttributeId_Executable: return executableAttribute();
			case AttributeId_UserExecutable: return userExecutableAttribute();
		    default: return nullptr;
		}
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
	AttributeBase::setNodeId(OpcUaNodeId& nodeId)
	{
		if (!isPartNodeId()) return false;
		NodeIdAttribute* attr = reinterpret_cast<NodeIdAttribute*>(nodeIdAttribute());
		nodeId.copyTo(attr->data());
		attr->exist(true);
		return true;
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
		if (isNullNodeId()) return nullptr;
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
	AttributeBase::setNodeClass(NodeClassType& nodeClass)
	{
		if (!isPartNodeClass()) return false;
		NodeClassAttribute* attr = reinterpret_cast<NodeClassAttribute*>(nodeClassAttribute());
		attr->data(nodeClass);
		attr->exist(true);
		return true;
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
		if (isNullNodeClass()) return nullptr;
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
	AttributeBase::setBrowseName(OpcUaQualifiedName& browseName)
	{
		if (!isPartBrowseName()) return false;
		BrowseNameAttribute* attr = reinterpret_cast<BrowseNameAttribute*>(browseNameAttribute());
		browseName.copyTo(attr->data());
		attr->exist(true);
		return true;
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
		if (isNullBrowseName()) return nullptr;
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
	AttributeBase::setDisplayName(OpcUaLocalizedText& displayName)
	{
		if (!isPartDisplayName()) return false;
		DisplayNameAttribute* attr = reinterpret_cast<DisplayNameAttribute*>(displayNameAttribute());
		displayName.copyTo(attr->data());
		attr->exist(true);
		return true;
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
		if (isNullDisplayName()) return nullptr;
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
	AttributeBase::setDescription(OpcUaLocalizedText& description)
	{
		if (!isPartDescription()) return false;
		DescriptionAttribute* attr = reinterpret_cast<DescriptionAttribute*>(descriptionAttribute());
		description.copyTo(attr->data());
		attr->exist(true);
		return true;
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
		if (isNullDescription()) return nullptr;
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
	AttributeBase::setWriteMask(OpcUaUInt32& writeMask)
	{
		if (!isPartWriteMask()) return false;
		WriteMaskAttribute* attr = reinterpret_cast<WriteMaskAttribute*>(writeMaskAttribute());
		attr->data(writeMask);
		attr->exist(true);
		return true;
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
		if (isNullWriteMask()) return nullptr;
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
	AttributeBase::setUserWriteMask(OpcUaUInt32& userWriteMask)
	{
		if (!isPartUserWriteMask()) return false;
		UserWriteMaskAttribute* attr = reinterpret_cast<UserWriteMaskAttribute*>(userWriteMaskAttribute());
		attr->data(userWriteMask);
		attr->exist(true);
		return true;
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
		if (isNullUserWriteMask()) return nullptr;
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
	AttributeBase::setIsAbstract(OpcUaBoolean& isAbstract)
	{
		if (!isPartIsAbstract()) return false;
		IsAbstractAttribute* attr = reinterpret_cast<IsAbstractAttribute*>(isAbstractAttribute());
		attr->data(isAbstract);
		attr->exist(true);
		return true;
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
		if (isNullIsAbstract()) return nullptr;
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
	AttributeBase::setSymmetric(OpcUaBoolean& symmetric)
	{
		if (!isPartSymmetric()) return false;
		SymmetricAttribute* attr = reinterpret_cast<SymmetricAttribute*>(symmetricAttribute());
		attr->data(symmetric);
		attr->exist(true);
		return true;
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
		if (isNullSymmetric()) return nullptr;
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
	AttributeBase::setInverseName(OpcUaLocalizedText& inverseName)
	{
		if (!isPartInverseName()) return false;
		InverseNameAttribute* attr = reinterpret_cast<InverseNameAttribute*>(inverseNameAttribute());
		inverseName.copyTo(attr->data());
		attr->exist(true);
		return true;
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
		if (isNullInverseName()) return nullptr;
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
	AttributeBase::setContainsNoLoops(OpcUaBoolean& containsNoLoops)
	{
		if (!isPartContainsNoLoops()) return false;
		ContainsNoLoopsAttribute* attr = reinterpret_cast<ContainsNoLoopsAttribute*>(containsNoLoopsAttribute());
		attr->data(containsNoLoops);
		attr->exist(true);
		return true;
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
		if (isNullContainsNoLoops()) return nullptr;
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
	AttributeBase::setEventNotifier(OpcUaByte& eventNotifier)
	{
		if (!isPartEventNotifier()) return false;
		EventNotifierAttribute* attr = reinterpret_cast<EventNotifierAttribute*>(eventNotifierAttribute());
		attr->data(eventNotifier);
		attr->exist(true);
		return true;
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
		if (isNullEventNotifier()) return nullptr;
		EventNotifierAttribute* attr = reinterpret_cast<EventNotifierAttribute*>(eventNotifierAttribute());
		return attr->data();
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
