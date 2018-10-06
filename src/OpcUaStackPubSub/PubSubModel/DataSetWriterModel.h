/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackPubSub_DataSetWriterModel_h__
#define __OpcUaStackPubSub_DataSetWriterModel_h__

#include <boost/shared_ptr.hpp>

#include <map>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

#include "OpcUaStackPubSub/PubSubModel/PubSubState.h"
#include "OpcUaStackPubSub/PubSubModel/KeyValuePair.h"
#include "OpcUaStackPubSub/PubSubModel/DataSetFieldContentMask.h"
#include "OpcUaStackPubSub/PubSubModel/DataSetWriterTransportModel.h"
#include "OpcUaStackPubSub/PubSubModel/DataSetWriterMessageModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * todo
	 */
	class DLLEXPORT DataSetWriterModel
	: public PubSubState
	{
	  public:
		typedef boost::shared_ptr<DataSetWriterModel> SPtr;
		typedef std::map<OpcUaNodeId, DataSetWriterModel::SPtr> Map;

		/**
		 * constructor
		 */
		DataSetWriterModel(void);

		/**
		 * destructor
		 */
		virtual ~DataSetWriterModel(void);

		/**
		 * setter method for variable name
		 *
		 * @param[in] name					name of the data set writer
		 */
		void name(const OpcUaString& name);

		/**
		 * getter method for variable name
		 *
		 * @return name of the data set writer
		 */
		OpcUaString& name(void);

		/**
		 * setter method for variable dataSetWriterId
		 *
		 * @param[in] dataSetWriterId		unique data set writer id
		 */
		void dataSetWriterId(uint16_t dataSetWriterId);

		/**
		 * getter method for variable dataSetWriterId
		 *
		 * @return data set writer id
		 */
		uint16_t dataSetWriterId(void);

		/**
		 * setter method for variable dataSetFieldContentMask
		 *
		 * @param[in] dataSetFieldContentMask	data set field content mask
		 */
		void dataSetFieldContentMask(DataSetFieldContentMask& dataSetFieldContentMask);

		/**
		 * getter method for variable dataSetFieldContentMask
		 *
		 * @return data set field content mask
		 */
		DataSetFieldContentMask& dataSetFieldContentMask(void);

		/**
		 * setter method for variable keyFrameCount
		 *
		 * @param[in] keyFrameCount	key frame count
		 */
		void keyFrameCount(uint32_t keyFrameCount);

		/**
		 * getter method for variable keyFrameCount
		 *
		 * @return key frame count
		 */
		uint32_t& keyFrameCount(void);

		/**
		 * setter method for variable dataSetName
		 *
		 * @param[in] dataSetName	name of data set
		 */
		void keyFrameCount(const OpcUaString& dataSetName);

		/**
		 * getter method for variable dataSetName
		 *
		 * @return name of data set
		 */
		OpcUaString& dataSetName(void);

		/**
		 * setter method for variable dataSetWriterProperties
		 *
		 * @param[in] dataSetWriterProperties		data set writer properties
		 */
		void dataSetWriterProperties(const KeyValuePair::Vec& dataSetWriterProperties);

		/**
		 * getter method for variable dataSetWriterProperties
		 *
		 * @return data set writer properties
		 */
		KeyValuePair::Vec& dataSetWriterProperties(void);

		/**
		 * setter method for variable transportSettings
		 *
		 * @param[in] transportSettings			transport mapping specific data set writer parameters
		 */
		void transportSettings(DataSetWriterTransportModel::SPtr& transportSettings);

		/**
		 * getter method for variable transportSettings
		 *
		 * @return transport mapping specific data set writer parameters
		 */
		DataSetWriterTransportModel::SPtr& transportSettings(void);

		/**
		 * setter method for variable messageSettings
		 *
		 * @param[in] messageSettings			message mapping specific data set writer parameters
		 */
		void messageSettings(DataSetWriterMessageModel::SPtr& messageSettings);

		/**
		 * getter method for variable messageSettings
		 *
		 * @return message mapping specific data set writer parameters
		 */
		DataSetWriterMessageModel::SPtr& messageSettings(void);


	  private:
		OpcUaString name_;					//!< name of writer group
		uint16_t dataSetWriterId_;			//!< unique identifier for data set writer
		DataSetFieldContentMask dataSetFieldContentMask_; //!< data set field content mask
		uint32_t keyFrameCount_;			//!< multiplier of the PublishingInterval that
											//!< defines the maximum number of times the PublishingInterval
											//!< expires before a key frame message with values for all
											//!< published Variables is sent
		OpcUaString dataSetName_;			//!< name of data set
		KeyValuePair::Vec dataSetWriterProperties_; //!< data set writer specific properties
		DataSetWriterTransportModel::SPtr transportSettings_; //!< transport mapping specific data set writer parameters
		DataSetWriterMessageModel::SPtr messageSettings_;	  //!< message mapping specific data set writer parameters
	};

}

#endif
