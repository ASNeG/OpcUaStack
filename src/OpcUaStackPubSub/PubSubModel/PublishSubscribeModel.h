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

	class DLLEXPORT PublishSubscribeModel
	{
	  public:
		typedef boost::shared_ptr<PublishSubscribeModel> SPtr;

		PublishSubscribeModel(void);
		virtual ~PublishSubscribeModel(void);

		OpcUaStatusCode removeConnection(
			OpcUaNodeId& connectionId
		);

		PubSubConnectionModel::SPtr getConnection(
			const OpcUaNodeId& connectionId
		);

		OpcUaStatusCode addUadpConnection(
			const OpcUaString& connectionName,	// in
			const OpcUaString& address,			// in
			const OpcUaVariant& publisherId,	// in
			OpcUaNodeId& connectionId			// out
		);

		OpcUaStatusCode addBrokerConnection(
			const OpcUaString& connectionName,	// in
			const OpcUaString& address,			// in
			const OpcUaVariant& publisherId,	// in
			OpcUaNodeId& connectionId			// out
		);

	  private:
		PubSubConnectionModel::Map pubSubConnectionModelMap_;
	};

}

#endif

