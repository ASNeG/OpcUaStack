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

#ifndef __OpcUaStackServer_AttributeBase_h__
#define __OpcUaStackServer_AttributeBase_h__

#include <boost/thread/shared_mutex.hpp>
#include "OpcUaStackServer/AddressSpaceModel/Attribute.h"

namespace OpcUaStackServer
{

	class DLLEXPORT AttributeBase
	{
	  public:
		typedef boost::shared_ptr<AttributeBase> SPtr;
		typedef boost::weak_ptr<AttributeBase> WPtr;

		AttributeBase(void);
		virtual ~AttributeBase(void);

		void lock(void);
		void unlock(void);
		boost::shared_mutex& mutex(void);

		Attribute* attribute(OpcUaStackCore::AttributeId attributeId);

		// global setter methods
		bool set(OpcUaStackCore::AttributeId attributeId, OpcUaStackCore::OpcUaDataValue::SPtr& dataValue);

		//
		// attribute node id
		//
		virtual Attribute* nodeIdAttribute(void);
		bool unsetNodeId(void);
		bool setNodeIdSync(const OpcUaStackCore::OpcUaNodeId& nodeId);
		bool setNodeId(const OpcUaStackCore::OpcUaNodeId& nodeId);
		bool getNodeIdSync(OpcUaStackCore::OpcUaNodeId& nodeId);
		bool getNodeId(OpcUaStackCore::OpcUaNodeId& nodeId);
		bool isPartNodeId(void);
		bool isNullNodeId(void);
		boost::optional<OpcUaStackCore::OpcUaNodeId&> getNodeId(void);

		//
		// attribute node class
		//
		virtual Attribute* nodeClassAttribute(void);
		bool unsetNodeClass(void);
		bool setNodeClassSync(const OpcUaStackCore::NodeClass::Enum& nodeClass);
		bool setNodeClass(const OpcUaStackCore::NodeClass::Enum& nodeClass);
		bool getNodeClassSync(OpcUaStackCore::NodeClass::Enum& nodeClass);
		bool getNodeClass(OpcUaStackCore::NodeClass::Enum& nodeClass);
		bool isPartNodeClass(void);
		bool isNullNodeClass(void);
		boost::optional<OpcUaStackCore::NodeClass::Enum&> getNodeClass(void);

		//
		// attribute browse name
		//
		virtual Attribute* browseNameAttribute(void);
		bool unsetBrowseName(void);
		bool setBrowseNameSync(const OpcUaStackCore::OpcUaQualifiedName& browseName);
		bool setBrowseName(const OpcUaStackCore::OpcUaQualifiedName& browseName);
		bool getBrowseNameSync(OpcUaStackCore::OpcUaQualifiedName& browseName);
		bool getBrowseName(OpcUaStackCore::OpcUaQualifiedName& browseName);
		bool isPartBrowseName(void);
		bool isNullBrowseName(void);
		boost::optional<OpcUaStackCore::OpcUaQualifiedName&> getBrowseName(void);

		//
		// display name
		//
		virtual Attribute* displayNameAttribute(void);
		bool unsetDisplayName(void);
		bool setDisplayNameSync(const OpcUaStackCore::OpcUaLocalizedText& displayName);
		bool setDisplayName(const OpcUaStackCore::OpcUaLocalizedText& displayName);
		bool getDisplayNameSync(OpcUaStackCore::OpcUaLocalizedText& displayName);
		bool getDisplayName(OpcUaStackCore::OpcUaLocalizedText& displayName);
		bool isPartDisplayName(void);
		bool isNullDisplayName(void);
		boost::optional<OpcUaStackCore::OpcUaLocalizedText&> getDisplayName(void);

		//
		// description
		//
		virtual Attribute* descriptionAttribute(void);
		bool unsetDescription(void);
		bool setDescriptionSync(const OpcUaStackCore::OpcUaLocalizedText& displayName);
		bool setDescription(const OpcUaStackCore::OpcUaLocalizedText& displayName);
		bool getDescriptionSync(OpcUaStackCore::OpcUaLocalizedText& displayName);
		bool getDescription(OpcUaStackCore::OpcUaLocalizedText& displayName);
		bool isPartDescription(void);
		bool isNullDescription(void);
		boost::optional<OpcUaStackCore::OpcUaLocalizedText&> getDescription(void);

		//
		// write mask
		//
		virtual Attribute* writeMaskAttribute(void);
		bool unsetWriteMask(void);
		bool setWriteMaskSync(const OpcUaStackCore::OpcUaUInt32 writeMask);
		bool setWriteMask(const OpcUaStackCore::OpcUaUInt32 writeMask);
		bool getWriteMaskSync(OpcUaStackCore::OpcUaUInt32& writeMask);
		bool getWriteMask(OpcUaStackCore::OpcUaUInt32& writeMask);
		bool isPartWriteMask(void);
		bool isNullWriteMask(void);
		boost::optional<OpcUaStackCore::OpcUaUInt32&> getWriteMask(void);

		//
		// user write mask
		//
		virtual Attribute* userWriteMaskAttribute(void);
		bool unsetUserWriteMask(void);
		bool setUserWriteMaskSync(const OpcUaStackCore::OpcUaUInt32 writeMask);
		bool setUserWriteMask(const OpcUaStackCore::OpcUaUInt32 writeMask);
		bool getUserWriteMaskSync(OpcUaStackCore::OpcUaUInt32& writeMask);
		bool getUserWriteMask(OpcUaStackCore::OpcUaUInt32& writeMask);
		bool isPartUserWriteMask(void);
		bool isNullUserWriteMask(void);
		boost::optional<OpcUaStackCore::OpcUaUInt32&> getUserWriteMask(void);

		//
		// is abstract
		//
		virtual Attribute* isAbstractAttribute(void);
		bool unsetIsAbstract(void);
		bool setIsAbstractSync(const OpcUaStackCore::OpcUaBoolean& isAbstract);
		bool setIsAbstract(const OpcUaStackCore::OpcUaBoolean& isAbstract);
		bool getIsAbstractSync(OpcUaStackCore::OpcUaBoolean& isAbstract);
		bool getIsAbstract(OpcUaStackCore::OpcUaBoolean& isAbstract);
		bool isPartIsAbstract(void);
		bool isNullIsAbstract(void);
		boost::optional<OpcUaStackCore::OpcUaBoolean&> getIsAbstract(void);

		//
		// symmetric
		//
		virtual Attribute* symmetricAttribute(void);
		bool unsetSymmetric(void);
		bool setSymmetricSync(const OpcUaStackCore::OpcUaBoolean& isAbstract);
		bool setSymmetric(const OpcUaStackCore::OpcUaBoolean& isAbstract);
		bool getSymmetricSync(OpcUaStackCore::OpcUaBoolean& isAbstract);
		bool getSymmetric(OpcUaStackCore::OpcUaBoolean& isAbstract);
		bool isPartSymmetric(void);
		bool isNullSymmetric(void);
		boost::optional<OpcUaStackCore::OpcUaBoolean&> getSymmetric(void);

		//
		// inverse name
		//
		virtual Attribute* inverseNameAttribute(void);
		bool unsetInverseName(void);
		bool setInverseNameSync(const OpcUaStackCore::OpcUaLocalizedText& inverseName);
		bool setInverseName(const OpcUaStackCore::OpcUaLocalizedText& inverseName);
		bool getInverseNameSync(OpcUaStackCore::OpcUaLocalizedText& inverseName);
		bool getInverseName(OpcUaStackCore::OpcUaLocalizedText& inverseName);
		bool isPartInverseName(void);
		bool isNullInverseName(void);
		boost::optional<OpcUaStackCore::OpcUaLocalizedText&> getInverseName(void);

		//
		// contains no loops
		//
		virtual Attribute* containsNoLoopsAttribute(void);
		bool unsetContainsNoLoops(void);
		bool setContainsNoLoopsSync(const OpcUaStackCore::OpcUaBoolean& containsNoLoops);
		bool setContainsNoLoops(const OpcUaStackCore::OpcUaBoolean& containsNoLoops);
		bool getContainsNoLoopsSync(OpcUaStackCore::OpcUaBoolean& containsNoLoops);
		bool getContainsNoLoops(OpcUaStackCore::OpcUaBoolean& containsNoLoops);
		bool isPartContainsNoLoops(void);
		bool isNullContainsNoLoops(void);
		boost::optional<OpcUaStackCore::OpcUaBoolean&> getContainsNoLoops(void);

		//
		// event notifier
		//
		virtual Attribute* eventNotifierAttribute(void);
		bool unsetEventNotifier(void);
		bool setEventNotifierSync(const OpcUaStackCore::OpcUaByte eventNotifier);
		bool setEventNotifier(const OpcUaStackCore::OpcUaByte eventNotifier);
		bool getEventNotifierSync(OpcUaStackCore::OpcUaByte& eventNotifier);
		bool getEventNotifier(OpcUaStackCore::OpcUaByte& eventNotifier);
		bool isPartEventNotifier(void);
		bool isNullEventNotifier(void);
		boost::optional<OpcUaStackCore::OpcUaByte&> getEventNotifier(void);

		//
		// value
		//
		virtual Attribute* valueAttribute(void);
		bool unsetValue(void);
		bool setValueSync(const OpcUaStackCore::OpcUaDataValue& value);
		bool setValue(const OpcUaStackCore::OpcUaDataValue& value);
		bool getValueSync(OpcUaStackCore::OpcUaDataValue& value);
		bool getValue(OpcUaStackCore::OpcUaDataValue& value);
		bool isPartValue(void);
		bool isNullValue(void);
		boost::optional<OpcUaStackCore::OpcUaDataValue&> getValue(void);

		//
		// dataType
		//
		virtual Attribute* dataTypeAttribute(void);
		bool unsetDataType(void);
		bool setDataTypeSync(const OpcUaStackCore::OpcUaNodeId& dataType);
		bool setDataType(const OpcUaStackCore::OpcUaNodeId& dataType);
		bool getDataTypeSync(OpcUaStackCore::OpcUaNodeId& dataType);
		bool getDataType(OpcUaStackCore::OpcUaNodeId& dataType);
		bool isPartDataType(void);
		bool isNullDataType(void);
		boost::optional<OpcUaStackCore::OpcUaNodeId&> getDataType(void);

		//
		// value rank
		//
		virtual Attribute* valueRankAttribute(void);
		bool unsetValueRank(void);
		bool setValueRankSync(const OpcUaStackCore::OpcUaInt32& arrayDimensions);
		bool setValueRank(const OpcUaStackCore::OpcUaInt32& arrayDimensions);
		bool getValueRankSync(OpcUaStackCore::OpcUaInt32& arrayDimensions);
		bool getValueRank(OpcUaStackCore::OpcUaInt32& arrayDimensions);
		bool isPartValueRank(void);
		bool isNullValueRank(void);
		boost::optional<OpcUaStackCore::OpcUaInt32&> getValueRank(void);

		//
		// array dimensions
		//
		virtual Attribute* arrayDimensionsAttribute(void);
		bool unsetArrayDimensions(void);
		bool setArrayDimensionsSync(const OpcUaStackCore::OpcUaUInt32Array& arrayDimensions);
		bool setArrayDimensions(const OpcUaStackCore::OpcUaUInt32Array& arrayDimensions);
		bool getArrayDimensionsSync(OpcUaStackCore::OpcUaUInt32Array& arrayDimensions);
		bool getArrayDimensions(OpcUaStackCore::OpcUaUInt32Array& arrayDimensions);
		bool isPartArrayDimensions(void);
		bool isNullArrayDimensions(void);
		boost::optional<OpcUaStackCore::OpcUaUInt32Array&> getArrayDimensions(void);

		//
		// access level
		//
		virtual Attribute* accessLevelAttribute(void);
		bool unsetAccessLevel(void);
		bool setAccessLevelSync(const OpcUaStackCore::OpcUaByte& accessLevel);
		bool setAccessLevel(const OpcUaStackCore::OpcUaByte& accessLevel);
		bool getAccessLevelSync(OpcUaStackCore::OpcUaByte& accessLevel);
		bool getAccessLevel(OpcUaStackCore::OpcUaByte& accessLevel);
		bool isPartAccessLevel(void);
		bool isNullAccessLevel(void);
		boost::optional<OpcUaStackCore::OpcUaByte&> getAccessLevel(void);

		//
		// user access level
		//
		virtual Attribute* userAccessLevelAttribute(void);
		bool unsetUserAccessLevel(void);
		bool setUserAccessLevelSync(const OpcUaStackCore::OpcUaByte& userAccessLevel);
		bool setUserAccessLevel(const OpcUaStackCore::OpcUaByte& userAccessLevel);
		bool getUserAccessLevelSync(OpcUaStackCore::OpcUaByte& userAccessLevel);
		bool getUserAccessLevel(OpcUaStackCore::OpcUaByte& userAccessLevel);
		bool isPartUserAccessLevel(void);
		bool isNullUserAccessLevel(void);
		boost::optional<OpcUaStackCore::OpcUaByte&> getUserAccessLevel(void);

		//
		// historizing
		//
		virtual Attribute* historizingAttribute(void);
		bool unsetHistorizing(void);
		bool setHistorizingSync(const OpcUaStackCore::OpcUaBoolean& historizing);
		bool setHistorizing(const OpcUaStackCore::OpcUaBoolean& historizing);
		bool getHistorizingSync(OpcUaStackCore::OpcUaBoolean& historizing);
		bool getHistorizing(OpcUaStackCore::OpcUaBoolean& historizing);
		bool isPartHistorizing(void);
		bool isNullHistorizing(void);
		boost::optional<OpcUaStackCore::OpcUaBoolean&> getHistorizing(void);

		//
		// executable
		//
		virtual Attribute* executableAttribute(void);
		bool unsetExecutable(void);
		bool setExecutableSync(const OpcUaStackCore::OpcUaBoolean& executable);
		bool setExecutable(const OpcUaStackCore::OpcUaBoolean& executable);
		bool getExecutableSync(OpcUaStackCore::OpcUaBoolean& executable);
		bool getExecutable(OpcUaStackCore::OpcUaBoolean& executable);
		bool isPartExecutable(void);
		bool isNullExecutable(void);
		boost::optional<OpcUaStackCore::OpcUaBoolean&> getExecutable(void);

		//
		// user executable
		//
		virtual Attribute* userExecutableAttribute(void);
		bool unsetUserExecutable(void);
		bool setUserExecutableSync(const OpcUaStackCore::OpcUaBoolean& userExecutable);
		bool setUserExecutable(const OpcUaStackCore::OpcUaBoolean& userExecutable);
		bool getUserExecutableSync(OpcUaStackCore::OpcUaBoolean& userExecutable);
		bool getUserExecutable(OpcUaStackCore::OpcUaBoolean& userExecutable);
		bool isPartUserExecutable(void);
		bool isNullUserExecutable(void);
		boost::optional<OpcUaStackCore::OpcUaBoolean&> getUserExecutable(void);

		//
		// minimum sampling interval
		//
		virtual Attribute* minimumSamplingIntervalAttribute(void);
		bool unsetMinimumSamplingInterval(void);
		bool setMinimumSamplingIntervalSync(const OpcUaStackCore::OpcUaDouble& minimumSamplingInterval);
		bool setMinimumSamplingInterval(const OpcUaStackCore::OpcUaDouble& minimumSamplingInterval);
		bool getMinimumSamplingIntervalSync(OpcUaStackCore::OpcUaDouble& minimumSamplingInterval);
		bool getMinimumSamplingInterval(OpcUaStackCore::OpcUaDouble& minimumSamplingInterval);
		bool isPartMinimumSamplingInterval(void);
		bool isNullMinimumSamplingInterval(void);
		boost::optional<OpcUaStackCore::OpcUaDouble&> getMinimumSamplingInterval(void);

		//
		// data type definition
		//
		virtual Attribute* dataTypeDefinitionAttribute(void);
		bool unsetDataTypeDefinition(void);
		bool setDataTypeDefinitionSync(const OpcUaStackCore::DataTypeDefinition& dataTypeDefinition);
		bool setDataTypeDefinition(const OpcUaStackCore::DataTypeDefinition& dataTypeDefinition);
		bool getDataTypeDefinitionSync(OpcUaStackCore::DataTypeDefinition& dataTypeDefinition);
		bool getDataTypeDefinition(OpcUaStackCore::DataTypeDefinition& dataTypeDefinition);
		bool isPartDataTypeDefinition(void);
		bool isNullDataTypeDefinition(void);
		boost::optional<OpcUaStackCore::DataTypeDefinition&> getDataTypeDefinition(void);

		//
		// role permissions
		//
		virtual Attribute* rolePermissionsAttribute(void);
		bool unsetRolePermissions(void);
		bool setRolePermissionsSync(const OpcUaStackCore::RolePermissionTypeArray& rolePermissions);
		bool setRolePermissions(const OpcUaStackCore::RolePermissionTypeArray& rolePermissions);
		bool getRolePermissionsSync(OpcUaStackCore::RolePermissionTypeArray& rolePermissions);
		bool getRolePermissions(OpcUaStackCore::RolePermissionTypeArray& rolePermissions);
		bool isPartRolePermissions(void);
		bool isNullRolePermissions(void);
		boost::optional<OpcUaStackCore::RolePermissionTypeArray&> getRolePermissions(void);

		//
		// user role permissions
		//
		virtual Attribute* userRolePermissionsAttribute(void);
		bool unsetUserRolePermissions(void);
		bool setUserRolePermissionsSync(const OpcUaStackCore::RolePermissionTypeArray& userRolePermissions);
		bool setUserRolePermissions(const OpcUaStackCore::RolePermissionTypeArray& userRolePermissions);
		bool getUserRolePermissionsSync(OpcUaStackCore::RolePermissionTypeArray& userRolePermissions);
		bool getUserRolePermissions(OpcUaStackCore::RolePermissionTypeArray& userRolePermissions);
		bool isPartUserRolePermissions(void);
		bool isNullUserRolePermissions(void);
		boost::optional<OpcUaStackCore::RolePermissionTypeArray&> getUserRolePermissions(void);

		//
		// access restrictions
		//
		virtual Attribute* accessRestrictionsAttribute(void);
		bool unsetAccessRestrictions(void);
		bool setAccessRestrictionsSync(const OpcUaStackCore::AccessRestrictionType& accessRestrictions);
		bool setAccessRestrictions(const OpcUaStackCore::AccessRestrictionType& accessRestrictions);
		bool getAccessRestrictionsSync(OpcUaStackCore::AccessRestrictionType& accessRestrictions);
		bool getAccessRestrictions(OpcUaStackCore::AccessRestrictionType& accessRestrictions);
		bool isPartAccessRestrictions(void);
		bool isNullAccessRestrictions(void);
		boost::optional<OpcUaStackCore::AccessRestrictionType&> getAccessRestrictions(void);

		//
		// access level ex
		//
		virtual Attribute* accessLevelExAttribute(void);
		bool unsetAccessLevelEx(void);
		bool setAccessLevelExSync(const OpcUaStackCore::AccessLevelExType& accessLevelEx);
		bool setAccessLevelEx(const OpcUaStackCore::AccessLevelExType& accessLevelEx);
		bool getAccessLevelExSync(OpcUaStackCore::AccessLevelExType& accessLevelEx);
		bool getAccessLevelEx(OpcUaStackCore::AccessLevelExType& accessLevelEx);
		bool isPartAccessLevelEx(void);
		bool isNullAccessLevelEx(void);
		boost::optional<OpcUaStackCore::AccessLevelExType&> getAccessLevelEx(void);

	  private:
		boost::shared_mutex mutex_;
	};

}

#endif
