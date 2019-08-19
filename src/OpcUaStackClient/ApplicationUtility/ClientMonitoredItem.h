/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackClient_ClientMonitoredItem_h__
#define __OpcUaStackClient_ClientMonitoredItem_h__

#include <map>
#include <set>
#include <vector>
#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/StandardDataTypes/DataChangeTrigger.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

namespace OpcUaStackClient
{

	class DLLEXPORT ClientMonitoredItem
	{
	  public:
		typedef boost::shared_ptr<ClientMonitoredItem> SPtr;
		typedef std::map<std::string, ClientMonitoredItem::SPtr> Map;
		typedef std::map<uint32_t, ClientMonitoredItem::SPtr> IdMap;
		typedef std::set<ClientMonitoredItem::SPtr> Set;
		typedef std::vector<ClientMonitoredItem::SPtr> Vec;

		typedef enum {
			S_Close,
			S_Open
		} State;

		ClientMonitoredItem(void);
		~ClientMonitoredItem(void);

		uint32_t samplingInterval(void);
		void samplingInterval(uint32_t samplingInterval);
		uint32_t queueSize(void);
		void queueSize(uint32_t queueSize);
		OpcUaStackCore::DataChangeTrigger dataChangeFilter(void);
		void dataChangeFilter(OpcUaStackCore::DataChangeTrigger dataChangeFilter);
		OpcUaStackCore::OpcUaNodeId& nodeId(void);
		void nodeId(OpcUaStackCore::OpcUaNodeId& nodeId);
		void clientHandle(uint32_t clientHandle);
		uint32_t clientHandle(void);

		void state(State state);
		State state(void);
		void reconnectTime(boost::posix_time::ptime reconnectTime);
		boost::posix_time::ptime reconnectTime(void);
		void monitoredItemId(uint32_t monitoredItemId);
		uint32_t monitoredItemId(void);
		void context(OpcUaStackCore::Object::SPtr& context);
		OpcUaStackCore::Object::SPtr& context(void);

	  private:

	    // configuration data
		uint32_t samplingInterval_;
		uint32_t queueSize_;
		OpcUaStackCore::OpcUaNodeId nodeId_;
		OpcUaStackCore::DataChangeTrigger dataChangeFilter_;
		uint32_t clientHandle_;

		// runtime data
		State state_;
		boost::posix_time::ptime reconnectTime_;
		uint32_t monitoredItemId_;
		OpcUaStackCore::Object::SPtr context_;
	};

}

#endif
