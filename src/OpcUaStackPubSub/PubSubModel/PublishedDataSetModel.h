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

#ifndef __OpcUaStackPubSub_PublishedDataSetModel_h__
#define __OpcUaStackPubSub_PublishedDataSetModel_h__

#include <boost/shared_ptr.hpp>

#include <map>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

#include "OpcUaStackPubSub/PubSubModel/KeyValuePair.h"
#include "OpcUaStackPubSub/PubSubModel/DataSetMetaDataModel.h"
#include "OpcUaStackPubSub/PubSubModel/PublishedDataSetSourceModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * This class represents the published data set parameters.
	 */
	class DLLEXPORT PublishedDataSetModel
	{
	  public:
		typedef boost::shared_ptr<PublishedDataSetModel> SPtr;
		typedef std::map<OpcUaNodeId, PublishedDataSetModel::SPtr> Map;

		/**
		 * constructor
		 */
		PublishedDataSetModel(void);

		/**
		 * destructor
		 */
		virtual ~PublishedDataSetModel(void);

		/**
		 * setter method for variable name
		 *
		 * @param[in] name					name of the published data set
		 */
		void name(const OpcUaString& name);

		/**
		 * getter method for variable name
		 *
		 * @return name of the published data set
		 */
		OpcUaString& name(void);

		/**
		 * setter method for variable dataSetFolder
		 *
		 * @param[in] dataSetFolder		data set folder
		 */
		void dataSetFolder(OpcUaStringArray::SPtr& dataSetFolder);

		/**
		 * getter method for variable dataSetFolder
		 *
		 * @return data set folder
		 */
		OpcUaStringArray::SPtr& dataSetFolder(void);

		/**
		 * setter method for variable dataSetMetaData
		 *
		 * @param[in] dataSetMetaData	data set meta data
		 */
		void dataSetMetaData(DataSetMetaDataModel::SPtr& dataSetMetaData);

		/**
		 * getter method for variable dataSetMetaData
		 *
		 * @return data set meta data
		 */
		DataSetMetaDataModel::SPtr& dataSetMetaData(void);

		/**
		 * setter method for variable extensionFields
		 *
		 * @param[in] extensionFields		extension fields
		 */
		void extensionFields(const KeyValuePair::Vec& extensionFields);

		/**
		 * getter method for variable extensionFields
		 *
		 * @return extension fields
		 */
		KeyValuePair::Vec& extensionFields(void);

		/**
		 * setter method for variable dataSetSource
		 *
		 * @param[in] dataSetSource		data set source
		 */
		void dataSetSource(PublishedDataSetSourceModel::SPtr& dataSetSource);

		/**
		 * getter method for variable dataSetSource
		 *
		 * @return data set source
		 */
		PublishedDataSetSourceModel::SPtr& dataSetSource(void);


	  private:
		OpcUaString name_;					//!< name of published data set
		OpcUaStringArray::SPtr dataSetFolder_;//!< Optional path of the DataSet folder used to group
											//!< PublishedDataSets where each entry in the String
											//!< array represents one level in a DataSet folder hierarchy.
		DataSetMetaDataModel::SPtr dataSetMetaData_; //!< subtype of DataTypeSchemaHeader and is used to
											//!< provide the metadata for a DataSet
		KeyValuePair::Vec extensionFields_; //!< The ExtensionFields parameter allows the configuration of
											//!< fields with values to be included in the DataSet when the
											//!< existing AddressSpace of the Publisher does not provide the
											//!< necessary information.
		PublishedDataSetSourceModel::SPtr dataSetSource_; //!< definition of the PublishedDataSet source

	};

}

#endif
