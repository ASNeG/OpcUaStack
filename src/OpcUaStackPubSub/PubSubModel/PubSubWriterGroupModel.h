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

#ifndef __OpcUaStackPubSub_PubSubWriterGroupModel_h__
#define __OpcUaStackPubSub_PubSubWriterGroupModel_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

#include "OpcUaStackPubSub/PubSubModel/PubSubGroupModel.h"
#include "OpcUaStackPubSub/PubSubModel/WriterGroupTransportModel.h"
#include "OpcUaStackPubSub/PubSubModel/WriterGroupMessageModel.h"
#include "OpcUaStackPubSub/PubSubModel/DataSetWriterModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * This class is used to represent the configuration parameters for WriterGroups.
	 */
	class DLLEXPORT PubSubWriterGroupModel
	: public PubSubGroupModel
	{
	  public:
		typedef boost::shared_ptr<PubSubWriterGroupModel> SPtr;
		typedef std::map<OpcUaNodeId, PubSubWriterGroupModel::SPtr> Map;

		/**
		 * constructor
		 */
		PubSubWriterGroupModel(void);

		/**
		 * destructor
		 */
		virtual ~PubSubWriterGroupModel(void);

		/**
		 * This Method is used to add a new DataSetWriter Object to the WriterGroup Object.
		 *
		 * @param[in] configuration			Configuration parameters for the DataSetWriter.
		 * @param[out] dataSetWriterId		The NodeId of the new DataSetWriter.
		 * @return opc ua status code
		 */
		OpcUaStatusCode
		addDataSetWriter(
		    DataSetWriterModel::SPtr& configuration,
			OpcUaNodeId& dataSetWriterId
		);

		/**
		 * This Method is used to find an existing data set writer.
		 *
		 * @param[in] dataSetWriterId		The NodeId of the data set writer.
		 * @return pointer to the data set writer
		 */
		DataSetWriterModel::SPtr
		getDataSetWriter(
			const OpcUaNodeId& dataSetWriterId
		);

		/**
		 * This Method is used to remove a DataSetWriter Object from the WriterGroup Object.
		 *
		 * @param[in] dataSetWriterId	 	The NodeId of the data set writer.
		 * @return opc ua status code
		 */
		OpcUaStatusCode
		removeDataSetWriter(
			const OpcUaNodeId& dataSetWriter
		);

		/**
		 * setter method for variable writerGroupId
		 *
		 * @param[in] writerGroupId				unique writer group id
		 */
		void writerGroupId(uint16_t writerGroupId);

		/**
		 * getter method for variable writerGroupId
		 *
		 * @return writer group id
		 */
		uint16_t writerGroupId(void);

		/**
		 * setter method for variable publishingInterval
		 *
		 * @param[in] publishingInterval			publishing interval in milliseconds
		 */
		void publishingInterval(OpcUaDuration publishingInterval);

		/**
		 * getter method for variable publishingInterval
		 *
		 * @return publishing interval in milliseconds
		 */
		OpcUaDuration publishingInterval(void);

		/**
		 * setter method for variable keepAliveTime
		 *
		 * @param[in] keepAliveTime				keep alive time in milliseconds
		 */
		void keepAliveTime(OpcUaDuration keepAliveTime);

		/**
		 * getter method for variable keepAliveTime
		 *
		 * @return keep alive time in milliseconds
		 */
		OpcUaDuration keepAliveTime(void);

		/**
		 * setter method for variable priority
		 *
		 * @param[in] priority				priority of the writer group
		 */
		void priority(OpcUaByte priority);

		/**
		 * getter method for variable priority
		 *
		 * @return priority of the writer group
		 */
		OpcUaByte priority(void);

		/**
		 * setter method for variable localeIds
		 *
		 * @param[in] localeIds				defines a list of locale ids
		 */
		void localeIds(OpcUaStringArray::SPtr& localeIds);

		/**
		 * getter method for variable localeIds
		 *
		 * @return list of locale ids
		 */
		OpcUaStringArray::SPtr& localeIds(void);

		/**
		 * setter method for variable transportSettings
		 *
		 * @param[in] transportSettings			transport mapping specific writer group parameters
		 */
		void transportSettings(WriterGroupTransportModel::SPtr& transportSettings);

		/**
		 * getter method for variable transportSettings
		 *
		 * @return transport mapping specific writer group parameters
		 */
		WriterGroupTransportModel::SPtr& transportSettings(void);

		/**
		 * setter method for variable messageSettings
		 *
		 * @param[in] messageSettings			message mapping specific writer group parameters
		 */
		void messageSettings(WriterGroupMessageModel::SPtr& messageSettings);

		/**
		 * getter method for variable messageSettings
		 *
		 * @return message mapping specific writer group parameters
		 */
		WriterGroupMessageModel::SPtr& messageSettings(void);


	  private:
		/**
		 * This method is a virtual method and is called if the state of the
		 * component has changed
		 *
		 *  @param[in] state 				new state of the component
		 */
		virtual void handleStateChange(State state);

		uint16_t writerGroupId_;				//!< unique identifier for writer group
		OpcUaDuration publishingInterval_;		//!< defines the interval in milliseconds for publishing network
												//!< messages
		OpcUaDuration keepAliveTime_;			//!< defines the keep alive time in milliseconds
		OpcUaByte priority_;					//!< defines the priority of the writer group
		OpcUaStringArray::SPtr localeIds_;		//!< defines a list of locale ids in priority order for localized
												//!< strings for all data set writers in the writer group
		WriterGroupTransportModel::SPtr transportSettings_; //!< transport mapping specific writer group parameters
		WriterGroupMessageModel::SPtr messageSettings_;		//!< message mapping specific writer group parameters
		DataSetWriterModel::Map dataSetWriters_;//!< data set writers contained in the writer group
		std::set<std::string> dataSetWriterNames_;//!< set of data set writer names
	};

}

#endif
