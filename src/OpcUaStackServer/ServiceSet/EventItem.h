/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/Filter/FilterStack.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	typedef std::list<EventFieldList::SPtr> EventFieldListList;

	class EventItem
	: public Object
	, public SimpleAttributeIf
	{
	  public:
		typedef boost::shared_ptr<EventItem> SPtr;
		typedef std::map<uint32_t, EventItem::SPtr> Map;
		typedef std::map<uint32_t, EventItem::SPtr> MultiMap;

		EventItem(void);
		~EventItem(void);

		void informationModel(InformationModel::SPtr& informationModel);
		void browseName(OpcUaQualifiedName& browseName);

		OpcUaStatusCode receive(
			MonitoredItemCreateRequest::SPtr& monitoredItemCreateRequest,
			MonitoredItemCreateResult::SPtr& monitoredItemCreateResult
		);
		OpcUaStatusCode receive(
			EventFieldListArray::SPtr eventFieldListArray
		);

		uint32_t size(void);
		uint32_t eventItemId(void);
		void erase(void);

		//- Interface SimpleAttributeIf ---------------------------------------
	    virtual bool getAttribute(
	        OpcUaNodeId& typeId,
			std::list<OpcUaQualifiedName::SPtr>& browsePath,
			OpcUaUInt32 attributeId,
			OpcUaString& numericRange,
			OpcUaVariant& value
		);
		//- Interface SimpleAttributeIf ---------------------------------------

	  private:
		void clear(void);
		void fireEvent(EventBase::SPtr eventBase);
		OpcUaStatusCode receive(SimpleAttributeOperandArray::SPtr& selectClauses, OpcUaStatusCodeArray::SPtr& statusCodeArray);

		OpcUaNodeId nodeId_;
		OpcUaQualifiedName browseName_;

		uint32_t eventItemId_;
		uint32_t clientHandle_;
		InformationModel::SPtr informationModel_;
		FilterStack::SPtr whereFilter_;
		SimpleAttributeOperandArray::SPtr selectClauses_;

		EventHandler::SPtr eventHandler_;
		EventFieldListList eventFieldListList_;
		boost::mutex eventFieldListListMutex_;

		EventBase::SPtr eventBase_;
	};

}

#endif
