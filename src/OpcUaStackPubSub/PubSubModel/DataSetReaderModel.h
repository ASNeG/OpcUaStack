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

#ifndef __OpcUaStackPubSub_DataSetReaderModel_h__
#define __OpcUaStackPubSub_DataSetReaderModel_h__

#include <boost/shared_ptr.hpp>

#include <map>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/MessageSecurityMode.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"

#include "OpcUaStackPubSub/PubSubModel/PubSubState.h"
#include "OpcUaStackPubSub/PubSubModel/DataSetMetaDataModel.h"
#include "OpcUaStackPubSub/PubSubModel/DataSetFieldContentMask.h"
#include "OpcUaStackPubSub/PubSubModel/KeyValuePair.h"
#include "OpcUaStackPubSub/PubSubModel/DataSetReaderTransportModel.h"
#include "OpcUaStackPubSub/PubSubModel/DataSetReaderMessageModel.h"
#include "OpcUaStackPubSub/PubSubModel/SubscribedDataSetModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * todo
	 */
	class DLLEXPORT DataSetReaderModel
	: public PubSubState
	{
	  public:
		typedef boost::shared_ptr<DataSetReaderModel> SPtr;
		typedef std::map<OpcUaNodeId, DataSetReaderModel::SPtr> Map;

		/**
		 * constructor
		 */
		DataSetReaderModel(void);

		/**
		 * destructor
		 */
		virtual ~DataSetReaderModel(void);

		/**
		 * setter method for variable name
		 *
		 * @param[in] name					name of the data set reader
		 */
		void name(const OpcUaString& name);

		/**
		 * getter method for variable name
		 *
		 * @return name of the data set reader
		 */
		OpcUaString& name(void);

		/**
		 * setter method for variable publisherId
		 *
		 * @param[in] publisherId			publisher identifier
		 */
		void publisherId(const OpcUaString& publisherId);

		/**
		 * setter method for variable publisherId
		 *
		 * @param[in] publisherId			publisher identifier
		 */
		void publisherId(uint32_t publisherId);

		/**
		 * getter method for variable publisherId
		 *
		 * @return publisherId
		 */
		OpcUaVariant& publisherId(void);

		/**
		 * setter method for variable writerGroupId
		 *
		 * @param[in] writerGroupId			writer group identifier
		 */
		void writerGroupId(uint16_t writerGroupId);

		/**
		 * getter method for variable writerGroupId
		 *
		 * @return writer group identifier
		 */
		uint16_t writerGroupId(void);

		/**
		 * setter method for variable dataSetWriterId
		 *
		 * @param[in] dataSetWriterId		data set writer identifier
		 */
		void dataSetWriterId(uint16_t dataSetWriterId);

		/**
		 * getter method for variable dataSetWriterId
		 *
		 * @return data set writer identifier
		 */
		uint16_t dataSetWriterId(void);

		/**
		 * setter method for variable dataSetMetaData
		 *
		 * @param[in] dataSetMetaData		data set meta data
		 */
		void dataSetMetaData(DataSetMetaDataModel::SPtr& dataSetMetaData);

		/**
		 * getter method for variable dataSetMetaData
		 *
		 * @return data set meta data
		 */
		DataSetMetaDataModel::SPtr& dataSetMetaData(void);

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
		 * setter method for variable messageReceiveTimeout
		 *
		 * @param[in] messageReceiveTimeout		message receive timeout
		 */
		void messageReceiveTimeout(Duration messageReceiveTimeout);

		/**
		 * getter method for variable messageReceiveTimeout
		 *
		 * @return message receive timeout
		 */
		Duration messageReceiveTimeout(void);

		/**
		 * setter method for variable securityMode
		 *
		 * @param[in] securityMode			security mode
		 */
		void securityMode(MessageSecurityMode securityMode);

		/**
		 * getter method for variable securityMode
		 *
		 * @return securityMode
		 */
		MessageSecurityMode securityMode(void);

		/**
		 * setter method for variable securityGroupId
		 *
		 * @param[in] securityGroupId			security group id
		 */
		void securityGroupId(const OpcUaString& securityGroupId);

		/**
		 * getter method for variable securityGroupId
		 *
		 * @return securityGroupId
		 */
		OpcUaString& securityGroupId(void);

		/**
		 * setter method for variable securityKeyService
		 *
		 * @param[in] securityKeyService	endpoints of Security KeyServers
		 */
		void securityKeyService(const EndpointDescriptionArray::SPtr& securityKeyService);

		/**
		 * getter method for variable securityKeyService
		 *
		 * @return securityKeyService
		 */
		EndpointDescriptionArray::SPtr& securityKeyService(void);

		/**
		 * setter method for variable dataSetReaderProperties
		 *
		 * @param[in] dataSetReaderProperties		data set reader properties
		 */
		void dataSetReaderProperties(const KeyValuePair::Vec& dataSetReaderProperties);

		/**
		 * getter method for variable dataSetReaderProperties
		 *
		 * @return data set reader properties
		 */
		KeyValuePair::Vec& dataSetReaderProperties(void);

		/**
		 * setter method for variable transportSettings
		 *
		 * @param[in] transportSettings			transport mapping specific data set reader parameters
		 */
		void transportSettings(DataSetReaderTransportModel::SPtr& transportSettings);

		/**
		 * getter method for variable transportSettings
		 *
		 * @return transport mapping specific data set reader parameters
		 */
		DataSetReaderTransportModel::SPtr& transportSettings(void);

		/**
		 * setter method for variable messageSettings
		 *
		 * @param[in] messageSettings			message mapping specific data set reader parameters
		 */
		void messageSettings(DataSetReaderMessageModel::SPtr& messageSettings);

		/**
		 * getter method for variable messageSettings
		 *
		 * @return message mapping specific data set reader parameters
		 */
		DataSetReaderMessageModel::SPtr& messageSettings(void);

		/**
		 * setter method for variable subscribedDataSet_
		 *
		 * @param[in] subscribedDataSet_			SubscribedDataSet specific parameters
		 */
		void subscribedDataSet(SubscribedDataSetModel::SPtr& subscribedDataSet);

		/**
		 * getter method for variable subscribedDataSet_
		 *
		 * @return SubscribedDataSet specific parameters
		 */
		SubscribedDataSetModel::SPtr& subscribedDataSet(void);

	  private:
		OpcUaString name_;					//!< name of reader group
		OpcUaVariant publisherId_;			//!< The PublisherId is a unique identifier for a Publisher
				 							//!< within a Message Oriented Middleware
		uint16_t writerGroupId_;			//!< The parameter WriterGroupId with DataType UInt16 defines the
											//!< identifier of the corresponding WriterGroup.
		uint16_t dataSetWriterId_;			//!< The parameter DataSetWriterId with DataType UInt16 defines the
											//!< DataSet selected in the Publisher for the DataSetReader.
		DataSetMetaDataModel::SPtr dataSetMetaData_; //!< The parameter DataSetMetaData provides the information
											//!< necessary to decode DataSetMessages from the Publisher.
		DataSetFieldContentMask dataSetFieldContentMask_; //!< data set field content mask
		Duration messageReceiveTimeout_;	//!< The parameter MessageReceiveTimeout is the maximum acceptable
											//!< time between two DataSetMessages.
		MessageSecurityMode securityMode_;  //!< Indicates the level of security to the network message
		OpcUaString securityGroupId_;		//!< Identifier for the security group in the Security Key Server
		EndpointDescriptionArray::SPtr securityKeyService_; //!< Defines one or more endpoints of Security KeyServers
		KeyValuePair::Vec dataSetReaderProperties_; //!< data set reader specific properties
		DataSetReaderTransportModel::SPtr transportSettings_; //!< transport mapping specific data set reader parameters
		DataSetReaderMessageModel::SPtr messageSettings_;	  //!< message mapping specific data set reader parameters
		SubscribedDataSetModel::SPtr subscribedDataSet_;	  //!< The SubscribedDataSet specific parameters.

	};

}

#endif
