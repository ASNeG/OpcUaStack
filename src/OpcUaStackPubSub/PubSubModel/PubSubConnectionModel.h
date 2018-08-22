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
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackPubSub/PubSubModel/PubSubGroupModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	class DLLEXPORT PubSubConnectionModel
	{
	  public:
		typedef boost::shared_ptr<PubSubConnectionModel> SPtr;
		typedef std::map<OpcUaNodeId, PubSubConnectionModel::SPtr> Map;

		typedef enum {
			UadpConnectionType,
			BrokerConnectionType
		} Type;

		PubSubConnectionModel(Type type);
		virtual ~PubSubConnectionModel(void);

		Type type(void);
		void connectionName(const OpcUaString& connectionName);
		OpcUaString& connectionName(void);
		void address(const OpcUaString& address);
		OpcUaString& address(void);
		void publisherId(const OpcUaVariant& publisherId);
		OpcUaVariant& publisherId(void);
		void connectionId(const OpcUaNodeId& connectionId);
		OpcUaNodeId& connectionId(void);

		OpcUaStatusCode removeGroup(
			OpcUaNodeId& groupId
		);

	  protected:
		PubSubGroupModel::Map pubSubGroupModelMap_;

	  private:
		PubSubConnectionModel(void);

		Type type_;
		OpcUaString connectionName_;
		OpcUaString address_;
		OpcUaVariant publisherId_;
		OpcUaNodeId connectionId_;
	};

}

#endif

