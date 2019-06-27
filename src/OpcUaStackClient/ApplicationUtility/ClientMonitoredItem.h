/*
   Copyright 2016-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/shared_ptr.hpp>
#include <map>
#include <set>
#include <vector>
#include <stdint.h>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/BuildInTypes/DataChangeTrigger.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;

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
		DataChangeTrigger dataChangeFilter(void);
		void dataChangeFilter(DataChangeTrigger dataChangeFilter);
		OpcUaNodeId& nodeId(void);
		void nodeId(OpcUaNodeId& nodeId);
		void clientHandle(uint32_t clientHandle);
		uint32_t clientHandle(void);

		void state(State state);
		State state(void);
		void reconnectTime(boost::posix_time::ptime reconnectTime);
		boost::posix_time::ptime reconnectTime(void);
		void monitoredItemId(uint32_t monitoredItemId);
		uint32_t monitoredItemId(void);
		void context(Object::SPtr& context);
		Object::SPtr& context(void);

	  private:

	    // configuration data
		uint32_t samplingInterval_;
		uint32_t queueSize_;
		OpcUaNodeId nodeId_;
		DataChangeTrigger dataChangeFilter_;
		uint32_t clientHandle_;

		// runtime data
		State state_;
		boost::posix_time::ptime reconnectTime_;
		uint32_t monitoredItemId_;
		Object::SPtr context_;
	};

}

#endif
