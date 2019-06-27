/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_NotificationData_h__
#define __OpcUaStackCore_NotificationData_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/DataChangeNotification.h"
#include "OpcUaStackCore/ServiceSet/StatusChangeNotification.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackCore
{

	class DLLEXPORT NotificationData
	: public  Object
	{
	  public:
		NotificationData(void);
		virtual ~NotificationData(void);

		void typeId(const OpcUaNodeId& typeId);
		OpcUaNodeId& typeId(void);
		void encodingMask(const OpcUaByte& encodingMask);
		OpcUaByte& encodingMask(void);
		void dataChangeNotification(const DataChangeNotification::SPtr dataChangeNotification);
		DataChangeNotification::SPtr dataChangeNotification(void) const;
		void statusChangeNotification(const StatusChangeNotification::SPtr statusChangeNotification);
		StatusChangeNotification::SPtr statusChangeNotification(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		  OpcUaNodeId typeId_;
		  OpcUaByte encodingMask_;
		  DataChangeNotification::SPtr dataChangeNotificationSPtr_;
		  StatusChangeNotification::SPtr statusChangeNotificationSPtr_;

		  // TODO: EventNotificationList
	};

	class NotificationDataArray
	: public OpcUaArray<NotificationData::SPtr, SPtrTypeCoder<NotificationData> >
	, public Object
	{
	};

}

#endif
