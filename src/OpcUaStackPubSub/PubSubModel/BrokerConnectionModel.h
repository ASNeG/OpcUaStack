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

#ifndef __OpcUaStackBroker_BrokerConnectionModel_h__
#define __OpcUaStackBroker_BrokerConnectionModel_h__

#include <boost/shared_ptr.hpp>
#include <map>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackPubSub/PubSubModel/PubSubConnectionModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	class DLLEXPORT BrokerConnectionModel
	: public PubSubConnectionModel
	{
	  public:
		typedef boost::shared_ptr<BrokerConnectionModel> SPtr;
		typedef std::map<OpcUaNodeId, BrokerConnectionModel::SPtr> Map;

		BrokerConnectionModel(void);
		virtual ~BrokerConnectionModel(void);

		OpcUaStatusCode addWriterGroup(
			const OpcUaString& groupName,			// in
			const Duration publishingInterval,		// in
			const Duration keepAliveTime,			// in
			const OpcUaByte priority,				// in
			const OpcUaString& encodingMimeType,	// in
			const OpcUaUInt32 securityMode,			// in
			const OpcUaString& securityGroupId,		// in
			const OpcUaString& queueName,			// in
			OpcUaNodeId& groupId					// out
		);

		OpcUaStatusCode addReaderGroup(
			const OpcUaString& groupName,			// in
			const OpcUaUInt32 securityMode,			// in
			const OpcUaString& securityGroupId,		// in
			const OpcUaString& queueName,			// in
			OpcUaNodeId& groupId					// out
		);

	  private:
	};

}

#endif

