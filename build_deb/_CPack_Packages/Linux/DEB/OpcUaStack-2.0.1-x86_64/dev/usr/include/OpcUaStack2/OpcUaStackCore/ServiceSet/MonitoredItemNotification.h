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

#ifndef __OpcUaStackCore_MonitorItemNotification_h__
#define __OpcUaStackCore_MonitorItemNotification_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT MonitoredItemNotification
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<MonitoredItemNotification> SPtr;

		MonitoredItemNotification(void);
		virtual ~MonitoredItemNotification(void);

		void clientHandle(const OpcUaUInt32& clientHandle);
		OpcUaUInt32 clientHandle(void) const;
		void dataValue(const OpcUaDataValue& dataValue);
		OpcUaDataValue& dataValue(void);
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 clientHandle_;
		OpcUaDataValue dataValue_;
	};

	class MonitoredItemNotificationArray
	: public OpcUaArray<MonitoredItemNotification::SPtr, SPtrTypeCoder<MonitoredItemNotification> >
	, public Object
	{
 	  public:
		typedef boost::shared_ptr<MonitoredItemNotificationArray> SPtr;
	};

}

#endif
