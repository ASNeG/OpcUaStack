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

#ifndef __OpcUaStackUadp_UadpConnectionModel_h__
#define __OpcUaStackUadp_UadpConnectionModel_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackPubSub/PubSubModel/PubSubConnectionModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	class DLLEXPORT UadpConnectionModel
	: public PubSubConnectionModel
	{
	  public:
		typedef boost::shared_ptr<UadpConnectionModel> SPtr;
		typedef std::map<OpcUaNodeId, UadpConnectionModel::SPtr> Map;

		UadpConnectionModel(void);
		virtual ~UadpConnectionModel(void);

		OpcUaStatusCode addWriterGroup(
			OpcUaString& groupName,
			Duration publishingInterval,
			Duration publishingOffset,
			Duration keepAliveTime,
			OpcUaByte priority,
			OpcUaUInt32 securityMode,
			OpcUaString& securityGroupId,
			OpcUaUInt16 maxNetworkMessageSize,
			OpcUaUInt32 networkMessageContentMask,
			OpcUaNodeId& groupId
		);

		OpcUaStatusCode addReaderGroup(
			OpcUaString& groupName,
			OpcUaUInt32 securityMode,
			OpcUaString& securityGroupId,
			OpcUaNodeId& groupId
		);

	  private:

	};

}

#endif

