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

#ifndef __OpcUaStackServer_BaseNodeClass_h__
#define __OpcUaStackServer_BaseNodeClass_h__

#include <boost/weak_ptr.hpp>
#include <vector>
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/ServiceSetApplication/ForwardNodeSync.h"
#include "OpcUaStackServer/ServiceSetApplication/ForwardNodeAsync.h"
#include "OpcUaStackServer/AddressSpaceModel/Attribute.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceType.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeBase.h"
#include "OpcUaStackServer/AddressSpaceModel/ReferenceItemMap.h"

namespace OpcUaStackServer
{

	class DLLEXPORT BaseNodeClass
	: public OpcUaStackCore::Object
	, public AttributeBase
	{
	  public: 
		typedef boost::shared_ptr<BaseNodeClass> SPtr;
		typedef boost::weak_ptr<BaseNodeClass> WPtr;
		typedef std::vector<BaseNodeClass::SPtr> Vec;

		BaseNodeClass(void);
		BaseNodeClass(OpcUaStackCore::NodeClass::Enum nodeClass);
		BaseNodeClass(OpcUaStackCore::NodeClass::Enum nodeClass, OpcUaStackCore::OpcUaNodeId& nodeId, BaseNodeClass* baseNodeClass);
		virtual ~BaseNodeClass(void);

		NodeIdAttribute& nodeId(void);
		NodeClassAttribute& nodeClass(void);
		BrowseNameAttribute& browseName(void);
		DisplayNameAttribute& displayName(void);
		DescriptionAttribute& description(void);
		WriteMaskAttribute& writeMask(void);
		UserWriteMaskAttribute& userWriteMask(void);
		RolePermissionsAttribute& rolePermissions(void);
		UserRolePermissionsAttribute& userRolePermissions(void);
		AccessRestrictionsAttribute& accessRestrictions(void);

		Attribute* nodeIdAttribute(void); 
		Attribute* nodeClassAttribute(void); 
		Attribute* browseNameAttribute(void); 
		Attribute* displayNameAttribute(void); 
		Attribute* descriptionAttribute(void); 
		Attribute* writeMaskAttribute(void); 
		Attribute* userWriteMaskAttribute(void); 
		Attribute* rolePermissionsAttribute(void);
		Attribute* userRolePermissionsAttribute(void);
		Attribute* accessRestrictionsAttribute(void);

		ReferenceItemMap& referenceItemMap(void);

		void copyTo(BaseNodeClass::SPtr baseNodeClass);
		void copyTo(BaseNodeClass& baseNodeClass);
		virtual BaseNodeClass::SPtr clone(void) = 0;

		void forwardNodeSync(ForwardNodeSync::SPtr forwardInfo);
		ForwardNodeSync::SPtr forwardNodeSync(void);
		void forwardNodeAsync(ForwardNodeAsync::SPtr forwardInfo);
		ForwardNodeAsync::SPtr forwardNodeAsync(void);

	  private:
		NodeIdAttribute nodeId_;
		NodeClassAttribute nodeClass_;
		BrowseNameAttribute browseName_;
		DisplayNameAttribute displayName_;
		DescriptionAttribute description_;
		WriteMaskAttribute writeMask_;
		UserWriteMaskAttribute userWriteMask_;
		RolePermissionsAttribute rolePermissionsAttribute_;
		UserRolePermissionsAttribute userRolePermissionsAttribute_;
		AccessRestrictionsAttribute accessRestrictionsAttribute_;

		ReferenceItemMap referenceItemMap_;

		ForwardNodeSync::SPtr forwardNodeSync_;
		ForwardNodeAsync::SPtr forwardNodeAsync_;
	};

}

#endif
