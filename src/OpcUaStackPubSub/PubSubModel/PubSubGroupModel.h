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

#ifndef __OpcUaStackBroker_PubSubGroupModel_h__
#define __OpcUaStackBroker_PubSubGroupModel_h__

#include <boost/shared_ptr.hpp>
#include <map>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

	class DLLEXPORT PubSubGroupModel
	{
	  public:
		typedef boost::shared_ptr<PubSubGroupModel> SPtr;
		typedef std::map<OpcUaNodeId, PubSubGroupModel::SPtr> Map;

		typedef enum {
			UadpReaderGroupType,
			UadpWriterGroupType,
			BrokerReaderGroupType,
			BrokerWriteGroupType
		} Type;

		PubSubGroupModel(Type type);
		virtual ~PubSubGroupModel(void);

		Type type(void);
		void groupName(OpcUaString& groupName);
		OpcUaString& groupName(void);
		void securityMode(OpcUaUInt32 securityMode);
		OpcUaUInt32 securityMode(void);
		void securityGroupId(OpcUaString& securityGroupId);
		OpcUaString& securityGroupId(void);

	  private:
		PubSubGroupModel(void);

		Type type_;
		OpcUaString groupName_;
		OpcUaUInt32 securityMode_;
		OpcUaString securityGroupId_;

	};

}

#endif

