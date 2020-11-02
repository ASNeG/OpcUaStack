/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	BaseNodeClass::BaseNodeClass(void)
	: nodeId_()
	, nodeClass_()
	, browseName_()
	, displayName_()
	, description_()
	, writeMask_()
	, userWriteMask_()
	, forwardNodeSync_()
	, rolePermissionsAttribute_()
	, userRolePermissionsAttribute_()
	, accessRestrictionsAttribute_()
	{
	}

	BaseNodeClass::BaseNodeClass(NodeClass::Enum nodeClass)
	: nodeId_()
	, nodeClass_(nodeClass)
	, browseName_()
	, displayName_()
	, description_()
	, writeMask_()
	, userWriteMask_()
	, forwardNodeSync_()
	, rolePermissionsAttribute_()
	, userRolePermissionsAttribute_()
	, accessRestrictionsAttribute_()
	{
	}

	BaseNodeClass::BaseNodeClass(NodeClass::Enum nodeClass, OpcUaNodeId& nodeId, BaseNodeClass* baseNodeClass)
	: nodeId_(0)
	, nodeClass_(nodeClass)
	, browseName_()
	, displayName_()
	, description_()
	, writeMask_()
	, userWriteMask_()
	, forwardNodeSync_()
	, rolePermissionsAttribute_()
	, userRolePermissionsAttribute_()
	, accessRestrictionsAttribute_()
	{
		setNodeId(nodeId);

		OpcUaQualifiedName browseName;
		if (baseNodeClass->getBrowseName(browseName)) setBrowseName(browseName);

		OpcUaLocalizedText displayName;
		if (baseNodeClass->getDisplayName(displayName)) setDisplayName(displayName);

		OpcUaLocalizedText description;
		if (baseNodeClass->getDescription(description)) setDescription(description);

		OpcUaUInt32 writeMask;
		if (baseNodeClass->getWriteMask(writeMask)) setWriteMask(writeMask);

		OpcUaUInt32 userWriteMask;
		if (baseNodeClass->getUserWriteMask(userWriteMask)) setUserWriteMask(userWriteMask);

		RolePermissionTypeArray rolePermissionArray;
		if (baseNodeClass->getRolePermissions(rolePermissionArray)) setRolePermissions(rolePermissionArray);

		RolePermissionTypeArray userRolePermissionArray;
		if (baseNodeClass->getUserRolePermissions(userRolePermissionArray)) setUserRolePermissions(userRolePermissionArray);

		AccessLevelExType accessLevelEx;
		if (baseNodeClass->getAccessLevelEx(accessLevelEx)) setAccessLevelEx(accessLevelEx);
	}

	BaseNodeClass::~BaseNodeClass(void)
	{
	}

	NodeIdAttribute& 
	BaseNodeClass::nodeId(void)
	{
		return nodeId_;
	}

	NodeClassAttribute& 
	BaseNodeClass::nodeClass(void)
	{
		return nodeClass_;
	}
		
	BrowseNameAttribute& 
	BaseNodeClass::browseName(void)
	{
		return browseName_;
	}
		
	DisplayNameAttribute& 
	BaseNodeClass::displayName(void)
	{
		return displayName_;
	}
		
	DescriptionAttribute& 
	BaseNodeClass::description(void)
	{
		return description_;
	}
		
	WriteMaskAttribute& 
	BaseNodeClass::writeMask(void)
	{
		return writeMask_;
	}
		
	UserWriteMaskAttribute& 
	BaseNodeClass::userWriteMask(void)
	{
		return userWriteMask_;
	}

	RolePermissionsAttribute&
	BaseNodeClass::rolePermissions(void)
	{
		return rolePermissionsAttribute_;
	}

	UserRolePermissionsAttribute&
	BaseNodeClass::userRolePermissions(void)
	{
		return userRolePermissionsAttribute_;
	}

	AccessRestrictionsAttribute&
	BaseNodeClass::accessRestrictions(void)
	{
		return accessRestrictionsAttribute_;
	}

	Attribute* 
	BaseNodeClass::nodeIdAttribute(void)
	{
		return &nodeId_;
	}

	Attribute* 
	BaseNodeClass::nodeClassAttribute(void)
	{
		return &nodeClass_;
	}

	Attribute* 
	BaseNodeClass::browseNameAttribute(void)
	{
		return &browseName_;
	}

	Attribute* 
	BaseNodeClass::displayNameAttribute(void)
	{
		return &displayName_;
	}

	Attribute* 
	BaseNodeClass::descriptionAttribute(void)
	{
		return &description_;
	}

	Attribute* 
	BaseNodeClass::writeMaskAttribute(void)
	{
		return &writeMask_;
	}

	Attribute* 
	BaseNodeClass::userWriteMaskAttribute(void)
	{
		return &userWriteMask_;
	}

	Attribute*
	BaseNodeClass::rolePermissionsAttribute(void)
	{
		return &rolePermissionsAttribute_;
	}

	Attribute*
	BaseNodeClass::userRolePermissionsAttribute(void)
	{
		return &userRolePermissionsAttribute_;
	}

	Attribute*
	BaseNodeClass::accessRestrictionsAttribute(void)
	{
		return &accessRestrictionsAttribute_;
	}

	ReferenceItemMap& 
	BaseNodeClass::referenceItemMap(void)
	{
		return referenceItemMap_;
	}

	void
	BaseNodeClass::copyTo(BaseNodeClass::SPtr baseNodeClass)
	{
		copyTo(*baseNodeClass);
	}
	void
	BaseNodeClass::copyTo(BaseNodeClass& baseNodeClass)
	{
		nodeIdAttribute()->copyTo(baseNodeClass.nodeIdAttribute());
		nodeClassAttribute()->copyTo(baseNodeClass.nodeClassAttribute());
		browseNameAttribute()->copyTo(baseNodeClass.browseNameAttribute());
		displayNameAttribute()->copyTo(baseNodeClass.displayNameAttribute());
		descriptionAttribute()->copyTo(baseNodeClass.descriptionAttribute());
		writeMaskAttribute()->copyTo(baseNodeClass.writeMaskAttribute());
		userWriteMaskAttribute()->copyTo(baseNodeClass.userWriteMaskAttribute());
		rolePermissionsAttribute()->copyTo(baseNodeClass.rolePermissionsAttribute());
		userRolePermissionsAttribute()->copyTo(baseNodeClass.userRolePermissionsAttribute());
		accessRestrictionsAttribute()->copyTo(baseNodeClass.accessRestrictionsAttribute());

		referenceItemMap_.copyTo(baseNodeClass.referenceItemMap());
	}

	void
	BaseNodeClass::forwardNodeSync(ForwardNodeSync::SPtr forwardNodeSync)
	{
		forwardNodeSync_ = forwardNodeSync;
	}

	ForwardNodeSync::SPtr
	BaseNodeClass::forwardNodeSync(void)
	{
		return forwardNodeSync_;
	}

	void
	BaseNodeClass::forwardNodeAsync(ForwardNodeAsync::SPtr forwardNodeAsync)
	{
		forwardNodeAsync_ = forwardNodeAsync;
	}

	ForwardNodeAsync::SPtr
	BaseNodeClass::forwardNodeAsync(void)
	{
		return forwardNodeAsync_;
	}

}
