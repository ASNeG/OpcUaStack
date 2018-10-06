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

#ifndef __OpcUaStackPubSub_PubSubConnectionModel_h__
#define __OpcUaStackPubSub_PubSubConnectionModel_h__

#include <boost/shared_ptr.hpp>

#include <map>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

#include "OpcUaStackPubSub/PubSubModel/PubSubState.h"
#include "OpcUaStackPubSub/PubSubModel/PubSubWriterGroupModel.h"
#include "OpcUaStackPubSub/PubSubModel/PubSubReaderGroupModel.h"
#include "OpcUaStackPubSub/PubSubModel/KeyValuePair.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * This class is used to represent the configuration parameters for PubSubConnections.
	 */
	class DLLEXPORT PubSubConnectionModel
	: public PubSubState
	{
	  public:
		typedef boost::shared_ptr<PubSubConnectionModel> SPtr;
		typedef std::map<OpcUaNodeId, PubSubConnectionModel::SPtr> Map;

		/**
		 * constructor
		 */
		PubSubConnectionModel(void);

		/**
		 * destructor
		 */
		virtual ~PubSubConnectionModel(void);

		/**
		 * This method is used to add a new writer group to a connection
		 *
		 * @param[in] configuration			Configuration parameters for the writer group.
		 * @param[out] groupId				The NodeId of the new writer group
		 * @return opc ua status code
		 */
		OpcUaStatusCode addWriterGroup(
			PubSubWriterGroupModel::SPtr& configuration,
			OpcUaNodeId& groupId
		);

		/**
		 * This method is used to add a new reader group to a connection
		 *
		 * @param[in] configuration			Configuration parameters for the reader group.
		 * @param[out] groupId				The NodeId of the new reader group.
		 * @return opc ua status code
		 */
		OpcUaStatusCode addReaderGroup(
			PubSubReaderGroupModel::SPtr& configuration,
			OpcUaNodeId& groupId
		);

		/**
		 * This Method is used to find an existing writer group.
		 *
		 * @param[in] groupId			The NodeId of the writer group.
		 * @return pointer to the writer group
		 */
		PubSubWriterGroupModel::SPtr
		getWriterGroup(
			const OpcUaNodeId& groupId
		);

		/**
		 * This Method is used to find an existing reader group.
		 *
		 * @param[in] groupId			The NodeId of the reader group.
		 * @return pointer to the reader group
		 */
		PubSubReaderGroupModel::SPtr
		getReaderGroup(
			const OpcUaNodeId& groupId
		);

		/**
		 * This method is used to remove an existing writer group or reader group
		 *
		 * @param[out] groupId				The NodeId of the writer group or reader group to delete.
		 * @return opc ua status code
		 */
		OpcUaStatusCode removeGroup(
			OpcUaNodeId& groupId
		);

		/**
		 * setter method for variable name
		 *
		 * @param[in] name					name of the connection
		 */
		void name(const OpcUaString& name);

		/**
		 * getter method for variable name
		 *
		 * @return connection name
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
		 * setter method for variable transportProfileUri
		 *
		 * @param[in] transportProfileUri	transport profile uri
		 */
		void transportProfileUri(const OpcUaString& transportProfileUri);

		/**
		 * getter method for variable transportProfileUri
		 *
		 * @return transportProfileUri
		 */
		OpcUaString& transportProfileUri(void);

		/**
		 * setter method for variable address
		 *
		 * @param[in] address		network address
		 */
		void address(const OpcUaString& address);

		/**
		 * getter method for variable address
		 *
		 * @return address
		 */
		OpcUaString& address(void);

		/**
		 * setter method for variable connectionProperties
		 *
		 * @param[in] connectionProperties		connection properties
		 */
		void connectionProperties(const KeyValuePair::Vec& connectionProperties);

		/**
		 * getter method for variable connectionProperties
		 *
		 * @return connectionProperties
		 */
		KeyValuePair::Vec& connectionProperties(void);

	  private:
		/**
		 * This method is a virtual method and is called if the state of the
		 * component has changed
		 *
		 *  @param[in] state 				new state of the component
		 */
		virtual void handleStateChange(State state);


		OpcUaString name_;					//!< name of connection
		OpcUaVariant publisherId_;			//!< The PublisherId is a unique identifier for a Publisher
		 									//!< within a Message Oriented Middleware
		OpcUaString transportProfileUri_;	//!< Used transport protocol mapping
		OpcUaString address_;				//!< network address
		KeyValuePair::Vec connectionProperties_; //!< Transport mapping specific connection parameters
		PubSubWriterGroupModel::Map writerGroups_;//!< writer groups contained in the connection
		PubSubReaderGroupModel::Map readerGroups_;//!< reader groups contained in the connection
		std::set<std::string> groupNames_;	//!< set of writer and reader group names

	};

}

#endif
