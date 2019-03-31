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

#ifndef __OpcUaStackServer_AttributeBase_h__
#define __OpcUaStackServer_AttributeBase_h__

#include <boost/thread/shared_mutex.hpp>
#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
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

		Attribute* attribute(AttributeId attributeId);

		// global setter methods
		bool set(AttributeId attributeId, OpcUaDataValue::SPtr& dataValue);

		//
		// attribute node id
		//
		virtual Attribute* nodeIdAttribute(void);
		bool unsetNodeId(void);
		bool setNodeIdSync(OpcUaNodeId& nodeId);
		bool setNodeId(OpcUaNodeId& nodeId);
		bool getNodeIdSync(OpcUaNodeId& nodeId);
		bool getNodeId(OpcUaNodeId& nodeId);
		bool isPartNodeId(void);
		bool isNullNodeId(void);
		boost::optional<OpcUaNodeId&> getNodeId(void);

		//
		// attribute node class
		//
		virtual Attribute* nodeClassAttribute(void);
		bool unsetNodeClass(void);
		bool setNodeClassSync(NodeClassType& nodeClass);
		bool setNodeClass(NodeClassType& nodeClass);
		bool getNodeClassSync(NodeClassType& nodeClass);
		bool getNodeClass(NodeClassType& nodeClass);
		bool isPartNodeClass(void);
		bool isNullNodeClass(void);
		boost::optional<NodeClassType&> getNodeClass(void);

		//
		// attribute browse name
		//
		virtual Attribute* browseNameAttribute(void);
		bool unsetBrowseName(void);
		bool setBrowseNameSync(OpcUaQualifiedName& browseName);
		bool setBrowseName(OpcUaQualifiedName& browseName);
		bool getBrowseNameSync(OpcUaQualifiedName& browseName);
		bool getBrowseName(OpcUaQualifiedName& browseName);
		bool isPartBrowseName(void);
		bool isNullBrowseName(void);
		boost::optional<OpcUaQualifiedName&> getBrowseName(void);

		//
		// display name
		//
		virtual Attribute* displayNameAttribute(void);
		bool unsetDisplayName(void);
		bool setDisplayNameSync(OpcUaLocalizedText& displayName);
		bool setDisplayName(OpcUaLocalizedText& displayName);
		bool getDisplayNameSync(OpcUaLocalizedText& displayName);
		bool getDisplayName(OpcUaLocalizedText& displayName);
		bool isPartDisplayName(void);
		bool isNullDisplayName(void);
		boost::optional<OpcUaLocalizedText&> getDisplayName(void);

		//
		// description
		//
		virtual Attribute* descriptionAttribute(void);
		bool unsetDescription(void);
		bool setDescriptionSync(OpcUaLocalizedText& displayName);
		bool setDescription(OpcUaLocalizedText& displayName);
		bool getDescriptionSync(OpcUaLocalizedText& displayName);
		bool getDescription(OpcUaLocalizedText& displayName);
		bool isPartDescription(void);
		bool isNullDescription(void);
		boost::optional<OpcUaLocalizedText&> getDescription(void);

		//
		// write mask
		//
		virtual Attribute* writeMaskAttribute(void);
		bool unsetWriteMask(void);
		bool setWriteMaskSync(OpcUaUInt32 writeMask);
		bool setWriteMask(OpcUaUInt32 writeMask);
		bool getWriteMaskSync(OpcUaUInt32& writeMask);
		bool getWriteMask(OpcUaUInt32& writeMask);
		bool isPartWriteMask(void);
		bool isNullWriteMask(void);
		boost::optional<OpcUaUInt32&> getWriteMask(void);

		//
		// user write mask
		//
		virtual Attribute* userWriteMaskAttribute(void);
		bool unsetUserWriteMask(void);
		bool setUserWriteMaskSync(OpcUaUInt32 writeMask);
		bool setUserWriteMask(OpcUaUInt32 writeMask);
		bool getUserWriteMaskSync(OpcUaUInt32& writeMask);
		bool getUserWriteMask(OpcUaUInt32& writeMask);
		bool isPartUserWriteMask(void);
		bool isNullUserWriteMask(void);
		boost::optional<OpcUaUInt32&> getUserWriteMask(void);

		//
		// is abstract
		//
		virtual Attribute* isAbstractAttribute(void);
		bool unsetIsAbstract(void);
		bool setIsAbstractSync(OpcUaBoolean& isAbstract);
		bool setIsAbstract(OpcUaBoolean& isAbstract);
		bool getIsAbstractSync(OpcUaBoolean& isAbstract);
		bool getIsAbstract(OpcUaBoolean& isAbstract);
		bool isPartIsAbstract(void);
		bool isNullIsAbstract(void);
		boost::optional<OpcUaBoolean&> getIsAbstract(void);

		//
		// symmetric
		//
		virtual Attribute* symmetricAttribute(void);
		bool unsetSymmetric(void);
		bool setSymmetricSync(OpcUaBoolean& isAbstract);
		bool setSymmetric(OpcUaBoolean& isAbstract);
		bool getSymmetricSync(OpcUaBoolean& isAbstract);
		bool getSymmetric(OpcUaBoolean& isAbstract);
		bool isPartSymmetric(void);
		bool isNullSymmetric(void);
		boost::optional<OpcUaBoolean&> getSymmetric(void);

		//
		// inverse name
		//
		virtual Attribute* inverseNameAttribute(void);
		bool unsetInverseName(void);
		bool setInverseNameSync(OpcUaLocalizedText& inverseName);
		bool setInverseName(OpcUaLocalizedText& inverseName);
		bool getInverseNameSync(OpcUaLocalizedText& inverseName);
		bool getInverseName(OpcUaLocalizedText& inverseName);
		bool isPartInverseName(void);
		bool isNullInverseName(void);
		boost::optional<OpcUaLocalizedText&> getInverseName(void);

		//
		// contains no loops
		//
		virtual Attribute* containsNoLoopsAttribute(void);
		bool unsetContainsNoLoops(void);
		bool setContainsNoLoopsSync(OpcUaBoolean& containsNoLoops);
		bool setContainsNoLoops(OpcUaBoolean& containsNoLoops);
		bool getContainsNoLoopsSync(OpcUaBoolean& containsNoLoops);
		bool getContainsNoLoops(OpcUaBoolean& containsNoLoops);
		bool isPartContainsNoLoops(void);
		bool isNullContainsNoLoops(void);
		boost::optional<OpcUaBoolean&> getContainsNoLoops(void);

		//
		// event notifier
		//
		virtual Attribute* eventNotifierAttribute(void);
		bool unsetEventNotifier(void);
		bool setEventNotifierSync(OpcUaByte eventNotifier);
		bool setEventNotifier(OpcUaByte eventNotifier);
		bool getEventNotifierSync(OpcUaByte& eventNotifier);
		bool getEventNotifier(OpcUaByte& eventNotifier);
		bool isPartEventNotifier(void);
		bool isNullEventNotifier(void);
		boost::optional<OpcUaByte&> getEventNotifier(void);

		//
		// value
		//
		virtual Attribute* valueAttribute(void);
		bool unsetValue(void);
		bool setValueSync(const OpcUaDataValue& value);
		bool setValue(const OpcUaDataValue& value);
		bool getValueSync(OpcUaDataValue& value);
		bool getValue(OpcUaDataValue& value);
		bool isPartValue(void);
		bool isNullValue(void);
		boost::optional<OpcUaDataValue&> getValue(void);

		//
		// dataType
		//
		virtual Attribute* dataTypeAttribute(void);
		bool unsetDataType(void);
		bool setDataTypeSync(OpcUaNodeId& dataType);
		bool setDataType(OpcUaNodeId& dataType);
		bool getDataTypeSync(OpcUaNodeId& dataType);
		bool getDataType(OpcUaNodeId& dataType);
		bool isPartDataType(void);
		bool isNullDataType(void);
		boost::optional<OpcUaNodeId&> getDataType(void);

		//
		// value rank
		//
		virtual Attribute* valueRankAttribute(void);
		bool unsetValueRank(void);
		bool setValueRankSync(OpcUaInt32& arrayDimensions);
		bool setValueRank(OpcUaInt32& arrayDimensions);
		bool getValueRankSync(OpcUaInt32& arrayDimensions);
		bool getValueRank(OpcUaInt32& arrayDimensions);
		bool isPartValueRank(void);
		bool isNullValueRank(void);
		boost::optional<OpcUaInt32&> getValueRank(void);

		//
		// array dimensions
		//
		virtual Attribute* arrayDimensionsAttribute(void);
		bool unsetArrayDimensions(void);
		bool setArrayDimensionsSync(OpcUaUInt32Array& arrayDimensions);
		bool setArrayDimensions(OpcUaUInt32Array& arrayDimensions);
		bool getArrayDimensionsSync(OpcUaUInt32Array& arrayDimensions);
		bool getArrayDimensions(OpcUaUInt32Array& arrayDimensions);
		bool isPartArrayDimensions(void);
		bool isNullArrayDimensions(void);
		boost::optional<OpcUaUInt32Array&> getArrayDimensions(void);

		//
		// access level
		//
		virtual Attribute* accessLevelAttribute(void);
		bool unsetAccessLevel(void);
		bool setAccessLevelSync(OpcUaByte& accessLevel);
		bool setAccessLevel(OpcUaByte& accessLevel);
		bool getAccessLevelSync(OpcUaByte& accessLevel);
		bool getAccessLevel(OpcUaByte& accessLevel);
		bool isPartAccessLevel(void);
		bool isNullAccessLevel(void);
		boost::optional<OpcUaByte&> getAccessLevel(void);

		//
		// user access level
		//
		virtual Attribute* userAccessLevelAttribute(void);
		bool unsetUserAccessLevel(void);
		bool setUserAccessLevelSync(OpcUaByte& userAccessLevel);
		bool setUserAccessLevel(OpcUaByte& userAccessLevel);
		bool getUserAccessLevelSync(OpcUaByte& userAccessLevel);
		bool getUserAccessLevel(OpcUaByte& userAccessLevel);
		bool isPartUserAccessLevel(void);
		bool isNullUserAccessLevel(void);
		boost::optional<OpcUaByte&> getUserAccessLevel(void);

		//
		// historizing
		//
		virtual Attribute* historizingAttribute(void);
		bool unsetHistorizing(void);
		bool setHistorizingSync(OpcUaBoolean& historizing);
		bool setHistorizing(OpcUaBoolean& historizing);
		bool getHistorizingSync(OpcUaBoolean& historizing);
		bool getHistorizing(OpcUaBoolean& historizing);
		bool isPartHistorizing(void);
		bool isNullHistorizing(void);
		boost::optional<OpcUaBoolean&> getHistorizing(void);

		//
		// executable
		//
		virtual Attribute* executableAttribute(void);
		bool unsetExecutable(void);
		bool setExecutableSync(OpcUaBoolean& executable);
		bool setExecutable(OpcUaBoolean& executable);
		bool getExecutableSync(OpcUaBoolean& executable);
		bool getExecutable(OpcUaBoolean& executable);
		bool isPartExecutable(void);
		bool isNullExecutable(void);
		boost::optional<OpcUaBoolean&> getExecutable(void);

		//
		// user executable
		//
		virtual Attribute* userExecutableAttribute(void);
		bool unsetUserExecutable(void);
		bool setUserExecutableSync(OpcUaBoolean& userExecutable);
		bool setUserExecutable(OpcUaBoolean& userExecutable);
		bool getUserExecutableSync(OpcUaBoolean& userExecutable);
		bool getUserExecutable(OpcUaBoolean& userExecutable);
		bool isPartUserExecutable(void);
		bool isNullUserExecutable(void);
		boost::optional<OpcUaBoolean&> getUserExecutable(void);

		//
		// minimum sampling interval
		//
		virtual Attribute* minimumSamplingIntervalAttribute(void);
		bool unsetMinimumSamplingInterval(void);
		bool setMinimumSamplingIntervalSync(OpcUaDouble& minimumSamplingInterval);
		bool setMinimumSamplingInterval(OpcUaDouble& minimumSamplingInterval);
		bool getMinimumSamplingIntervalSync(OpcUaDouble& minimumSamplingInterval);
		bool getMinimumSamplingInterval(OpcUaDouble& minimumSamplingInterval);
		bool isPartMinimumSamplingInterval(void);
		bool isNullMinimumSamplingInterval(void);
		boost::optional<OpcUaDouble&> getMinimumSamplingInterval(void);

	  private:
		boost::shared_mutex mutex_;
	};

}

#endif
