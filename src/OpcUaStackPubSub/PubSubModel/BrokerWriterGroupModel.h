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

#ifndef __OpcUaStackBroker_BrokerWriterGroupModel_h__
#define __OpcUaStackBroker_BrokerWriterGroupModel_h__

#include <boost/shared_ptr.hpp>
#include <map>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackPubSub/PubSubModel/PubSubWriterGroupModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	class DLLEXPORT BrokerWriterGroupModel
	: public PubSubWriterGroupModel
	{
	  public:
		typedef boost::shared_ptr<BrokerWriterGroupModel> SPtr;
		typedef std::map<OpcUaNodeId, BrokerWriterGroupModel::SPtr> Map;

		BrokerWriterGroupModel(void);
		virtual ~BrokerWriterGroupModel(void);

		void queueName(OpcUaString queueName);
		OpcUaString queueName(void);

	  private:
		OpcUaString queueName_;
	};

}

#endif

