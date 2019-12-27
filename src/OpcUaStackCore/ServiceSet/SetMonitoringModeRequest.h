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

#ifndef __OpcUaStackCore_SetMonitoringModeRequest_h__
#define __OpcUaStackCore_SetMonitoringModeRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/ServiceSet/MonitoringMode.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SetMonitoringModeRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<SetMonitoringModeRequest> SPtr;

		SetMonitoringModeRequest(void);
		virtual ~SetMonitoringModeRequest(void);

		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void monitoringMode(const MonitoringMode monitoringMode);
		MonitoringMode monitoringMode(void) const;
		void monitoredItemIds(const OpcUaUInt32Array::SPtr monitordItemIds);
		OpcUaUInt32Array::SPtr monitoredItemIds(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 subscriptionId_;
		MonitoringMode monitoringMode_;
		OpcUaUInt32Array::SPtr monitoredItemIdArraySPtr_;
	};

}

#endif
