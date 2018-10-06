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

#ifndef __OpcUaStackPubSub_PubSubReaderGroupModel_h__
#define __OpcUaStackPubSub_PubSubReaderGroupModel_h__

#include <boost/shared_ptr.hpp>

#include <map>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

#include "OpcUaStackPubSub/PubSubModel/PubSubGroupModel.h"
#include "OpcUaStackPubSub/PubSubModel/ReaderGroupTransportModel.h"
#include "OpcUaStackPubSub/PubSubModel/ReaderGroupMessageModel.h"
#include "OpcUaStackPubSub/PubSubModel/DataSetReaderModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * This class is used to represent the configuration parameters for ReaderGroups.
	 */
	class DLLEXPORT PubSubReaderGroupModel
	: public PubSubGroupModel
	{
	  public:
		typedef boost::shared_ptr<PubSubReaderGroupModel> SPtr;
		typedef std::map<OpcUaNodeId, PubSubReaderGroupModel::SPtr> Map;

		/**
		 * constructor
		 */
		PubSubReaderGroupModel(void);

		/**
		 * destructor
		 */
		virtual ~PubSubReaderGroupModel(void);

		/**
		 * This Method is used to add a new DataSetReader Object to the ReaderGroup Object.
		 *
		 * @param[in] configuration			Configuration parameters for the DataSetReader.
		 * @param[out] dataSetReaderId		The NodeId of the new DataSetReader.
		 * @return opc ua status code
		 */
		OpcUaStatusCode
		addDataSetReader(
		    DataSetReaderModel::SPtr& configuration,
			OpcUaNodeId& dataSetReaderId
		);

		/**
		 * This Method is used to find an existing data set reader.
		 *
		 * @param[in] dataSetReaderId		The NodeId of the data set reader.
		 * @return pointer to the data set reader
		 */
		DataSetReaderModel::SPtr
		getDataSetReader(
			const OpcUaNodeId& dataSetReaderId
		);

		/**
		 * This Method is used to remove a DataSetReader Object from the ReaderGroup Object.
		 *
		 * @param[in] dataSetReaderId	 	The NodeId of the data set reader.
		 * @return opc ua status code
		 */
		OpcUaStatusCode
		removeDataSetReader(
			const OpcUaNodeId& dataSetReader
		);

		/**
		 * setter method for variable transportSettings
		 *
		 * @param[in] transportSettings			transport mapping specific reader group parameters
		 */
		void transportSettings(ReaderGroupTransportModel::SPtr& transportSettings);

		/**
		 * getter method for variable transportSettings
		 *
		 * @return transport mapping specific reader group parameters
		 */
		ReaderGroupTransportModel::SPtr& transportSettings(void);

		/**
		 * setter method for variable messageSettings
		 *
		 * @param[in] messageSettings			message mapping specific reader group parameters
		 */
		void messageSettings(ReaderGroupMessageModel::SPtr& messageSettings);

		/**
		 * getter method for variable messageSettings
		 *
		 * @return message mapping specific reader group parameters
		 */
		ReaderGroupMessageModel::SPtr& messageSettings(void);

	  private:
		/**
		 * This method is a virtual method and is called if the state of the
		 * component has changed
		 *
		 *  @param[in] state 				new state of the component
		 */
		virtual void handleStateChange(State state);

		ReaderGroupTransportModel::SPtr transportSettings_; //!< transport mapping specific reader group parameters
		ReaderGroupMessageModel::SPtr messageSettings_;		//!< message mapping specific reader group parameters
		DataSetReaderModel::Map dataSetReaders_;	//!< data set readers contained in the reader group
		std::set<std::string> dataSetReaderNames_;	//!< set of data set reader names

	};

}

#endif
