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

#include <boost/thread/mutex.hpp>
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
		boost::mutex& mutex(void);

		Attribute* attribute(AttributeId attributeId);

		// global setter methods
		bool set(AttributeId attributeId, OpcUaDataValue::SPtr& dataValue);

		//
		// attribute node id
		//
		virtual Attribute* nodeIdAttribute(void);
		bool unsetNodeId(void);
		bool setNodeId(OpcUaNodeId& nodeId);
		bool getNodeId(OpcUaNodeId& nodeId);
		bool isPartNodeId(void);
		bool isNullNodeId(void);
		boost::optional<OpcUaNodeId&> getNodeId(void);

		//
		// attribute node class
		//
		virtual Attribute* nodeClassAttribute(void);
		bool unsetNodeClass(void);
		bool setNodeClass(NodeClassType& nodeClass);
		bool getNodeClass(NodeClassType& nodeClass);
		bool isPartNodeClass(void);
		bool isNullNodeClass(void);
		boost::optional<NodeClassType&> getNodeClass(void);

		//
		// attribute browse name
		//
		virtual Attribute* browseNameAttribute(void);
		bool unsetBrowseName(void);
		bool setBrowseName(OpcUaQualifiedName& browseName);
		bool getBrowseName(OpcUaQualifiedName& browseName);
		bool isPartBrowseName(void);
		bool isNullBrowseName(void);
		boost::optional<OpcUaQualifiedName&> getBrowseName(void);

		//
		// display name
		//
		virtual Attribute* displayNameAttribute(void);
		bool unsetDisplayName(void);
		bool setDisplayName(OpcUaLocalizedText& displayName);
		bool getDisplayName(OpcUaLocalizedText& displayName);
		bool isPartDisplayName(void);
		bool isNullDisplayName(void);
		boost::optional<OpcUaLocalizedText&> getDisplayName(void);

		//
		// description
		//
		virtual Attribute* descriptionAttribute(void);
		bool unsetDescription(void);
		bool setDescription(OpcUaLocalizedText& displayName);
		bool getDescription(OpcUaLocalizedText& displayName);
		bool isPartDescription(void);
		bool isNullDescription(void);
		boost::optional<OpcUaLocalizedText&> getDescription(void);

		//
		// write mask
		//
		virtual Attribute* writeMaskAttribute(void);
		bool unsetWriteMask(void);
		bool setWriteMask(OpcUaUInt32 writeMask);
		bool getWriteMask(OpcUaUInt32& writeMask);
		bool isPartWriteMask(void);
		bool isNullWriteMask(void);
		boost::optional<OpcUaUInt32&> getWriteMask(void);

		//
		// user write mask
		//
		virtual Attribute* userWriteMaskAttribute(void);
		bool unsetUserWriteMask(void);
		bool setUserWriteMask(OpcUaUInt32 writeMask);
		bool getUserWriteMask(OpcUaUInt32& writeMask);
		bool isPartUserWriteMask(void);
		bool isNullUserWriteMask(void);
		boost::optional<OpcUaUInt32&> getUserWriteMask(void);

		//
		// is abstract
		//
		virtual Attribute* isAbstractAttribute(void);
		bool unsetIsAbstract(void);
		bool setIsAbstract(OpcUaBoolean& isAbstract);
		bool getIsAbstract(OpcUaBoolean& isAbstract);
		bool isPartIsAbstract(void);
		bool isNullIsAbstract(void);
		boost::optional<OpcUaBoolean&> getIsAbstract(void);

		//
		// symmetric
		//
		virtual Attribute* symmetricAttribute(void);
		bool unsetSymmetric(void);
		bool setSymmetric(OpcUaBoolean& isAbstract);
		bool getSymmetric(OpcUaBoolean& isAbstract);
		bool isPartSymmetric(void);
		bool isNullSymmetric(void);
		boost::optional<OpcUaBoolean&> getSymmetric(void);

		//
		// inverse name
		//
		virtual Attribute* inverseNameAttribute(void);
		bool unsetInverseName(void);
		bool setInverseName(OpcUaLocalizedText& inverseName);
		bool getInverseName(OpcUaLocalizedText& inverseName);
		bool isPartInverseName(void);
		bool isNullInverseName(void);
		boost::optional<OpcUaLocalizedText&> getInverseName(void);

		//
		// contains no loops
		//
		virtual Attribute* containsNoLoopsAttribute(void);
		bool unsetContainsNoLoops(void);
		bool setContainsNoLoops(OpcUaBoolean& containsNoLoops);
		bool getContainsNoLoops(OpcUaBoolean& containsNoLoops);
		bool isPartContainsNoLoops(void);
		bool isNullContainsNoLoops(void);
		boost::optional<OpcUaBoolean&> getContainsNoLoops(void);

		//
		// event notifier
		//
		virtual Attribute* eventNotifierAttribute(void);
		bool unsetEventNotifier(void);
		bool setEventNotifier(OpcUaByte eventNotifier);
		bool getEventNotifier(OpcUaByte& eventNotifier);
		bool isPartEventNotifier(void);
		bool isNullEventNotifier(void);
		boost::optional<OpcUaByte&> getEventNotifier(void);

		//
		// value
		//
		virtual Attribute* valueAttribute(void);
		bool unsetValue(void);
		bool setValue(OpcUaDataValue& value);
		bool getValue(OpcUaDataValue& value);
		bool isPartValue(void);
		bool isNullValue(void);
		boost::optional<OpcUaDataValue&> getValue(void);

		//
		// dataType
		//
		virtual Attribute* dataTypeAttribute(void);
		bool unsetDataType(void);
		bool setDataType(OpcUaNodeId& dataType);
		bool getDataType(OpcUaNodeId& dataType);
		bool isPartDataType(void);
		bool isNullDataType(void);
		boost::optional<OpcUaNodeId&> getDataType(void);

		//
		// value rank
		//
		virtual Attribute* valueRankAttribute(void);
		bool unsetValueRank(void);
		bool setValueRank(OpcUaInt32& arrayDimensions);
		bool getValueRank(OpcUaInt32& arrayDimensions);
		bool isPartValueRank(void);
		bool isNullValueRank(void);
		boost::optional<OpcUaInt32&> getValueRank(void);

		//
		// array dimensions
		//
		virtual Attribute* arrayDimensionsAttribute(void);
		bool unsetArrayDimensions(void);
		bool setArrayDimensions(OpcUaUInt32Array& arrayDimensions);
		bool getArrayDimensions(OpcUaUInt32Array& arrayDimensions);
		bool isPartArrayDimensions(void);
		bool isNullArrayDimensions(void);
		boost::optional<OpcUaUInt32Array&> getArrayDimensions(void);

		//
		// access level
		//
		virtual Attribute* accessLevelAttribute(void);
		bool unsetAccessLevel(void);
		bool setAccessLevel(OpcUaByte& accessLevel);
		bool getAccessLevel(OpcUaByte& accessLevel);
		bool isPartAccessLevel(void);
		bool isNullAccessLevel(void);
		boost::optional<OpcUaByte&> getAccessLevel(void);

		//
		// user access level
		//
		virtual Attribute* userAccessLevelAttribute(void);
		bool unsetUserAccessLevel(void);
		bool setUserAccessLevel(OpcUaByte& userAccessLevel);
		bool getUserAccessLevel(OpcUaByte& userAccessLevel);
		bool isPartUserAccessLevel(void);
		bool isNullUserAccessLevel(void);
		boost::optional<OpcUaByte&> getUserAccessLevel(void);

		//
		// historizing
		//
		virtual Attribute* historizingAttribute(void);
		bool unsetHistorizing(void);
		bool setHistorizing(OpcUaBoolean& historizing);
		bool getHistorizing(OpcUaBoolean& historizing);
		bool isPartHistorizing(void);
		bool isNullHistorizing(void);
		boost::optional<OpcUaBoolean&> getHistorizing(void);

		//
		// executable
		//
		virtual Attribute* executableAttribute(void);
		bool unsetExecutable(void);
		bool setExecutable(OpcUaBoolean& executable);
		bool getExecutable(OpcUaBoolean& executable);
		bool isPartExecutable(void);
		bool isNullExecutable(void);
		boost::optional<OpcUaBoolean&> getExecutable(void);

		//
		// user executable
		//
		virtual Attribute* userExecutableAttribute(void);
		bool unsetUserExecutable(void);
		bool setUserExecutable(OpcUaBoolean& userExecutable);
		bool getUserExecutable(OpcUaBoolean& userExecutable);
		bool isPartUserExecutable(void);
		bool isNullUserExecutable(void);
		boost::optional<OpcUaBoolean&> getUserExecutable(void);

		//
		// minimum sampling interval
		//
		virtual Attribute* minimumSamplingIntervalAttribute(void);
		bool unsetMinimumSamplingInterval(void);
		bool setMinimumSamplingInterval(OpcUaDouble& minimumSamplingInterval);
		bool getMinimumSamplingInterval(OpcUaDouble& minimumSamplingInterval);
		bool isPartMinimumSamplingInterval(void);
		bool isNullMinimumSamplingInterval(void);
		boost::optional<OpcUaDouble&> getMinimumSamplingInterval(void);

	  private:
		boost::mutex mutex_;
	};

}

#endif
