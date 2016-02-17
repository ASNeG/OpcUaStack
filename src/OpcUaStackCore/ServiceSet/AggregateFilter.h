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

#ifndef __OpcUaStackCore_AggregateFilter_h__
#define __OpcUaStackCore_AggregateFilter_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/AggregateConfiguration.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AggregateFilter
	: public Object
	, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<AggregateFilter> SPtr;

		AggregateFilter(void);
		virtual ~AggregateFilter(void);

		void startTime(const UtcTime& startTime);
		void startTime(const boost::posix_time::ptime& startTime);
		UtcTime startTime(void) const;
		void aggregateType(const OpcUaNodeId& aggregateType);
		OpcUaNodeId& aggregateType(void);
		void processingInterval(const OpcUaDouble& processingInterval);
		OpcUaDouble processingInterval(void);
		void aggregateConfiguration(const AggregateConfiguration& aggregateConfiguration);
		AggregateConfiguration& aggregateConfiguration(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::SPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		UtcTime startTime_;
		OpcUaNodeId aggregateType_;
		OpcUaDouble processingInterval_;
		AggregateConfiguration aggregateConfiguration_;
	};

}

#endif
