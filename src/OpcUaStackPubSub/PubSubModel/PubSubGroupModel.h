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

#ifndef __OpcUaStackPubSub_PubSubGroupModel_h__
#define __OpcUaStackPubSub_PubSubGroupModel_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/MessageSecurityMode.h"
#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"
#include "OpcUaStackCore/StandardDataTypes/MessageSecurityMode.h"

#include "OpcUaStackPubSub/PubSubModel/PubSubState.h"
#include "OpcUaStackPubSub/PubSubModel/KeyValuePair.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * This class is used to represent the configuration parameters for WriterGroups.
	 */
	class DLLEXPORT PubSubGroupModel
	: public PubSubState
	{
	  public:
		typedef boost::shared_ptr<PubSubGroupModel> SPtr;
		typedef std::map<OpcUaNodeId, PubSubGroupModel::SPtr> Map;

		/**
		 * constructor
		 */
		PubSubGroupModel(void);

		/**
		 * destructor
		 */
		virtual ~PubSubGroupModel(void);

		/**
		 * setter method for variable name
		 *
		 * @param[in] name					name of the writer group
		 */
		void name(const OpcUaString& name);

		/**
		 * getter method for variable name
		 *
		 * @return writer group name
		 */
		OpcUaString& name(void);

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
		 * setter method for variable maxNetworkMessageSize
		 *
		 * @param[in] maxNetworkMessageSize_	maximal message size
		 */
		void maxNetworkMessageSize(uint32_t maxNetworkMessageSize);

		/**
		 * getter method for variable maxNetworkMessageSize
		 *
		 * @return maxNetworkMessageSize
		 */
		uint32_t maxNetworkMessageSize(void);

		/**
		 * setter method for variable groupProperties
		 *
		 * @param[in] groupProperties		connection properties
		 */
		void groupProperties(const KeyValuePair::Vec& groupProperties);

		/**
		 * getter method for variable groupProperties
		 *
		 * @return groupProperties
		 */
		KeyValuePair::Vec& groupProperties(void);

	  private:
		OpcUaString name_;					//!< name of writer group
		MessageSecurityMode securityMode_;  //!< Indicates the level of security to the network message
		OpcUaString securityGroupId_;		//!< Identifier for the security group in the Security Key Server
		EndpointDescriptionArray::SPtr securityKeyService_; //!< Defines one or more endpoints of Security KeyServers
		uint32_t maxNetworkMessageSize_;	//!< maximal size of bytes for network messages
		KeyValuePair::Vec groupProperties_; //!< group specific properties
	};

}

#endif
