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

#ifndef __OpcUaStackPubSub_PublishSubscribeModel_h__
#define __OpcUaStackPubSub_PublishSubscribeModel_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

#include "OpcUaStackPubSub/PubSubModel/PubSubConnectionModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	/**
	 * This class represents the root Object for all PubSub related configuration
	 * and metadata Objects
	 */
	class DLLEXPORT PublishSubscribeModel
	{
	  public:
		typedef boost::shared_ptr<PublishSubscribeModel> SPtr;

		/**
		 * constructor
		 */
		PublishSubscribeModel(void);

		/**
		 * destructor
		 */
		virtual ~PublishSubscribeModel(void);

		/**
		 * This method is used to push the security keys for a SecurityGroup into
		 * a publisher or subscriber.
		 *
		 * @param[in] securityGroupId 		The identifier for the SecurityGroup.
		 * @param[in] securityPolicyUri 	The URI for the set of algorithms and key lengths used to secure the messages
		 * @param[in] currentTokenId		The SecurityTokenId that appears in the header of messages secured with the
		 *									CurrentKey.
		 * @param[in] currentKey			The current key used to secure the messages.
		 * @param[in] furureKeys			An ordered list of future keys that are used when the KeyLifetime elapses.
		 * @param[in] timeToNextKey			The time, in milliseconds, before the CurrentKey is expected to expire.
		 * @param[in] keyLifetime			The lifetime of a key in milliseconds.
		 * @return opc ua status code
		 */
		OpcUaStatusCode
		setSecurityKeys(
			const OpcUaString& securityGroupId,
			const OpcUaString& securityPolicyUri,
			IntegerId currentTokenId,
			const OpcUaString& currentKey,
			const OpcUaByteStringArray& furureKeys,
			Duration timeToNextKey,
			Duration keyLifetime
		);

		/**
		 * This Method is used to add a new PubSubConnection Object to the PublishSubscribe Object.
		 *
		 * @param[in] configuration			Configuration parameters for the PubSubConnection.
		 * @param[out] connectionId			The NodeId of the new connection.
		 * @return opc ua status code
		 */
		OpcUaStatusCode
		addConnection(
		    PubSubConnectionModel::SPtr& configuration,
			OpcUaNodeId& connectionId
		);

		/**
		 * This Method is used to remove a PubSubConnection Object from the PublishSubscribe Object.
		 *
		 * @param[in] connectionId	 		The NodeId of the new connection.
		 * @return opc ua status code
		 */
		OpcUaStatusCode
		removeConnection(
			const OpcUaNodeId& connectionId
		);
	};

}

#endif
