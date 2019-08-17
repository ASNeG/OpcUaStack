/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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
		bool setNodeIdSync(OpcUaStackCore::OpcUaNodeId& nodeId);
		bool setNodeId(OpcUaStackCore::OpcUaNodeId& nodeId);
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
		bool setNodeClassSync(OpcUaStackCore::NodeClass::Enum& nodeClass);
		bool setNodeClass(OpcUaStackCore::NodeClass::Enum& nodeClass);
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
		bool setBrowseNameSync(OpcUaStackCore::OpcUaQualifiedName& browseName);
		bool setBrowseName(OpcUaStackCore::OpcUaQualifiedName& browseName);
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
		bool setDescriptionSync(OpcUaStackCore::OpcUaLocalizedText& displayName);
		bool setDescription(OpcUaStackCore::OpcUaLocalizedText& displayName);
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
		bool setWriteMaskSync(OpcUaStackCore::OpcUaUInt32 writeMask);
		bool setWriteMask(OpcUaStackCore::OpcUaUInt32 writeMask);
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
		bool setUserWriteMaskSync(OpcUaStackCore::OpcUaUInt32 writeMask);
		bool setUserWriteMask(OpcUaStackCore::OpcUaUInt32 writeMask);
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
		bool setIsAbstractSync(OpcUaStackCore::OpcUaBoolean& isAbstract);
		bool setIsAbstract(OpcUaStackCore::OpcUaBoolean& isAbstract);
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
		bool setSymmetricSync(OpcUaStackCore::OpcUaBoolean& isAbstract);
		bool setSymmetric(OpcUaStackCore::OpcUaBoolean& isAbstract);
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
		bool setInverseNameSync(OpcUaStackCore::OpcUaLocalizedText& inverseName);
		bool setInverseName(OpcUaStackCore::OpcUaLocalizedText& inverseName);
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
		bool setContainsNoLoopsSync(OpcUaStackCore::OpcUaBoolean& containsNoLoops);
		bool setContainsNoLoops(OpcUaStackCore::OpcUaBoolean& containsNoLoops);
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
		bool setEventNotifierSync(OpcUaStackCore::OpcUaByte eventNotifier);
		bool setEventNotifier(OpcUaStackCore::OpcUaByte eventNotifier);
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
		bool setDataTypeSync(OpcUaStackCore::OpcUaNodeId& dataType);
		bool setDataType(OpcUaStackCore::OpcUaNodeId& dataType);
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
		bool setValueRankSync(OpcUaStackCore::OpcUaInt32& arrayDimensions);
		bool setValueRank(OpcUaStackCore::OpcUaInt32& arrayDimensions);
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
		bool setArrayDimensionsSync(OpcUaStackCore::OpcUaUInt32Array& arrayDimensions);
		bool setArrayDimensions(OpcUaStackCore::OpcUaUInt32Array& arrayDimensions);
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
		bool setAccessLevelSync(OpcUaStackCore::OpcUaByte& accessLevel);
		bool setAccessLevel(OpcUaStackCore::OpcUaByte& accessLevel);
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
		bool setUserAccessLevelSync(OpcUaStackCore::OpcUaByte& userAccessLevel);
		bool setUserAccessLevel(OpcUaStackCore::OpcUaByte& userAccessLevel);
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
		bool setHistorizingSync(OpcUaStackCore::OpcUaBoolean& historizing);
		bool setHistorizing(OpcUaStackCore::OpcUaBoolean& historizing);
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
		bool setExecutableSync(OpcUaStackCore::OpcUaBoolean& executable);
		bool setExecutable(OpcUaStackCore::OpcUaBoolean& executable);
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
		bool setUserExecutableSync(OpcUaStackCore::OpcUaBoolean& userExecutable);
		bool setUserExecutable(OpcUaStackCore::OpcUaBoolean& userExecutable);
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
		bool setMinimumSamplingIntervalSync(OpcUaStackCore::OpcUaDouble& minimumSamplingInterval);
		bool setMinimumSamplingInterval(OpcUaStackCore::OpcUaDouble& minimumSamplingInterval);
		bool getMinimumSamplingIntervalSync(OpcUaStackCore::OpcUaDouble& minimumSamplingInterval);
		bool getMinimumSamplingInterval(OpcUaStackCore::OpcUaDouble& minimumSamplingInterval);
		bool isPartMinimumSamplingInterval(void);
		bool isNullMinimumSamplingInterval(void);
		boost::optional<OpcUaStackCore::OpcUaDouble&> getMinimumSamplingInterval(void);

		//
		// data type definition
		//
		// FIXME: todo

		//
		// role permissions
		//
		// FIXME: todo

		//
		// user role permissions
		//
		// FIXME: todo

		//
		// access restrictions
		//
		// FIXME: todo

		//
		// access level ex
		//
		// FIXME: todo

	  private:
		boost::shared_mutex mutex_;
	};

}

#endif
