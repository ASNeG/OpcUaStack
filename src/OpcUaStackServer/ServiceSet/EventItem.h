/*
   Copyright 2017-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include <list>
#include "OpcUaStackCore/Base/UserContext.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/EventType/EventHandler.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemServiceTransaction.h"
#include "OpcUaStackCore/StandardDataTypes/EventNotificationList.h"
#include "OpcUaStackCore/StandardDataTypes/EventFieldList.h"
#include "OpcUaStackCore/Filter/FilterStack.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	typedef std::list<OpcUaStackCore::EventFieldList::SPtr> EventFieldListList;

	class DLLEXPORT EventItem
	: public OpcUaStackCore::Object
	, public OpcUaStackCore::SimpleAttributeIf
	{
	  public:
		typedef boost::shared_ptr<EventItem> SPtr;
		typedef std::map<uint32_t, EventItem::SPtr> Map;
		typedef std::map<uint32_t, EventItem::SPtr> MultiMap;

		EventItem(void);
		~EventItem(void);

		void informationModel(InformationModel::SPtr& informationModel);
		void browseName(OpcUaStackCore::OpcUaQualifiedName& browseName);

		OpcUaStackCore::OpcUaStatusCode receive(
			OpcUaStackCore::MonitoredItemCreateRequest::SPtr& monitoredItemCreateRequest,
			OpcUaStackCore::MonitoredItemCreateResult::SPtr& monitoredItemCreateResult
		);
		OpcUaStackCore::OpcUaStatusCode receive(
			OpcUaStackCore::EventFieldListArray& eventFieldListArray
		);

		void userContext(OpcUaStackCore::UserContext::SPtr& userContext);
		OpcUaStackCore::UserContext::SPtr& userContext(void);
		uint32_t size(void);
		uint32_t eventItemId(void);
		void erase(void);

		//- Interface SimpleAttributeIf ---------------------------------------
	    virtual bool getAttribute(
	    	OpcUaStackCore::OpcUaNodeId& typeId,
			std::list<OpcUaStackCore::OpcUaQualifiedName::SPtr>& browsePath,
			OpcUaStackCore::OpcUaUInt32 attributeId,
			OpcUaStackCore::OpcUaString& numericRange,
			OpcUaStackCore::OpcUaVariant& value
		);
		//- Interface SimpleAttributeIf ---------------------------------------

	  private:
		void clear(void);
		void fireEvent(OpcUaStackCore::EventBase::SPtr& eventBase);
		OpcUaStackCore::OpcUaStatusCode receive(OpcUaStackCore::SimpleAttributeOperandArray& selectClauses, OpcUaStackCore::OpcUaStatusArray& statusArray);

		OpcUaStackCore::OpcUaNodeId nodeId_;
		OpcUaStackCore::OpcUaQualifiedName browseName_;

		uint32_t eventItemId_;
		uint32_t clientHandle_;
		InformationModel::SPtr informationModel_;
		OpcUaStackCore::FilterStack::SPtr whereFilter_;
		OpcUaStackCore::SimpleAttributeOperandArray selectClauses_;

		OpcUaStackCore::EventHandler::SPtr eventHandler_;
		EventFieldListList eventFieldListList_;
		boost::mutex eventFieldListListMutex_;

		OpcUaStackCore::EventBase::SPtr eventBase_;
		OpcUaStackCore::UserContext::SPtr userContext_;
	};

}

#endif
