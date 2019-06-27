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

#ifndef __OpcUaStackCore_MonitoredItemModifyResult_h__
#define __OpcUaStackCore_MonitoredItemModifyResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT MonitoredItemModifyResult
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<MonitoredItemModifyResult> SPtr;

		MonitoredItemModifyResult(void);
		virtual ~MonitoredItemModifyResult(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode statusCode(void) const;
		void monitoredItemId(const OpcUaUInt32& monitoredItemId);
		OpcUaUInt32 monitoredItemId(void) const;
		void revisedSamplingInterval(const OpcUaDouble& revisedSamplingInterval);
		OpcUaDouble revisedSamplingInterval(void) const;
		void revisedQueueSize(const OpcUaUInt32& revisedQueueSize);
		OpcUaUInt32 revisedQueueSize(void) const;
		void filterResult(const ExtensibleParameter& filterResult);
		ExtensibleParameter& filterResult(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;
		OpcUaDouble revisedSamplingInterval_;
		OpcUaUInt32 revisedQueueSize_;
		ExtensibleParameter filterResult_;
	};

	class MonitoredItemModifyResultArray
	: public OpcUaArray<MonitoredItemModifyResult::SPtr, SPtrTypeCoder<MonitoredItemModifyResult> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<MonitoredItemModifyResultArray> SPtr;
	};

}

#endif
