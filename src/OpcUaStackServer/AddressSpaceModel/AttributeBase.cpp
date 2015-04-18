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
