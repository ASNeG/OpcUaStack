/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_EventItem_h__
#define __OpcUaStackServer_EventItem_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/EventType/EventHandler.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackCore/ServiceSet/EventNotificationList.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef std::list<EventFieldList::SPtr> EventFieldListList;

	class EventItem
	: public Object
	{
	  public:
		typedef boost::shared_ptr<EventItem> SPtr;
		typedef std::map<uint32_t, EventItem::SPtr> Map;

		EventItem(void);
		~EventItem(void);

		void informationModel(InformationModel::SPtr& informationModel);

		OpcUaStatusCode receive(
			MonitoredItemCreateRequest::SPtr& monitoredItemCreateRequest,
			MonitoredItemCreateResult::SPtr& monitoredItemCreateResult
		);
		OpcUaStatusCode receive(EventFieldListArray::SPtr eventFieldListArray);

		uint32_t size(void);
		uint32_t eventItemId(void);

	  private:
		void clear(void);
		void fireEvent(EventBase::SPtr eventBase);

		OpcUaNodeId nodeId_;
		uint32_t eventItemId_;
		uint32_t clientHandle_;
		InformationModel::SPtr informationModel_;

		EventHandler::SPtr eventHandler_;
		EventFieldListList eventFieldListList_;
	};

}

#endif
