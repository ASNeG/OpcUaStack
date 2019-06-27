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

#ifndef __OpcUaStackCore_MonitoredItemCreateRequest_h__
#define __OpcUaStackCore_MonitoredItemCreateRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ReadValueId.h"
#include "OpcUaStackCore/ServiceSet/MonitoringParameters.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/MonitoringMode.h"

namespace OpcUaStackCore
{

	class DLLEXPORT MonitoredItemCreateRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<MonitoredItemCreateRequest> SPtr;

		MonitoredItemCreateRequest(void);
		virtual ~MonitoredItemCreateRequest(void);

		void itemToMonitor(const ReadValueId& itemToMonitor);
		ReadValueId& itemToMonitor(void);
		void monitoringMode(const MonitoringMode& monitoringMode);
		MonitoringMode& monitoringMode(void);
		void requestedParameters(const MonitoringParameters& requestedParameters);
		MonitoringParameters& requestedParameters(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ReadValueId itemToMonitor_;
		MonitoringMode monitoringMode_;
		MonitoringParameters requestedParameters_;
	};

	class MonitoredItemCreateRequestArray
	: public OpcUaArray<MonitoredItemCreateRequest::SPtr, SPtrTypeCoder<MonitoredItemCreateRequest> >
	, public Object
	{
  	  public:
		typedef boost::shared_ptr<MonitoredItemCreateRequestArray> SPtr;
	};

}

#endif
