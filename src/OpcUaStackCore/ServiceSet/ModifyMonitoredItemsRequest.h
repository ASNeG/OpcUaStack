/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ModifyMonitoredItemsRequest_h__
#define __OpcUaStackCore_ModifyMonitoredItemsRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/ServiceSet/MonitoredItemModifyRequest.h"
#include "OpcUaStackCore/ServiceSet/TimestampsToReturn.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ModifyMonitoredItemsRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<ModifyMonitoredItemsRequest> SPtr;

		ModifyMonitoredItemsRequest(void);
		virtual ~ModifyMonitoredItemsRequest(void);

		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void timestampsToReturn(const TimestampsToReturn timestampsToReturn);
		TimestampsToReturn timestampsToReturn(void);
		void itemsToModify(const MonitoredItemModifyRequestArray::SPtr itemsToModify);
		MonitoredItemModifyRequestArray::SPtr itemsToModify(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 subscriptionId_;
		TimestampsToReturn timestampsToReturn_;
		MonitoredItemModifyRequestArray::SPtr itemsToModifyArraySPtr_;
	};

}

#endif
