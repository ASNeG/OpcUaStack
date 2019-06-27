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

#ifndef __OpcUaStackCore_MonitoringParameters_h__
#define __OpcUaStackCore_MonitoringParameters_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT MonitoringParameters
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<MonitoringParameters> SPtr;

		MonitoringParameters(void);
		virtual ~MonitoringParameters(void);

		void clientHandle(const OpcUaUInt32& clientHandle);
		OpcUaUInt32 clientHandle(void) const;
		void samplingInterval(const OpcUaDouble& samplingInterval);
		OpcUaDouble samplingInterval(void) const;
		void filter(const ExtensibleParameter filter);
		ExtensibleParameter filter(void);
		void queueSize(const OpcUaUInt32 queueSize);
		OpcUaUInt32 queueSize(void) const;
		void discardOldest(const OpcUaBoolean discardOldest);
		OpcUaBoolean discardOldest(void) const;
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 clientHandle_;
		OpcUaDouble samplingInterval_;
		ExtensibleParameter filter_;
		OpcUaUInt32 queueSize_;
		OpcUaBoolean discardOldest_;
	};

}

#endif
