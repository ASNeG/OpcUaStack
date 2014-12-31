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

	class DLLEXPORT AggregateFilter : public  ObjectPool<AggregateFilter>, public ExtensibleParameterBase
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
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		UtcTime startTime_;
		OpcUaNodeId aggregateType_;
		OpcUaDouble processingInterval_;
		AggregateConfiguration aggregateConfiguration_;
	};

}

#endif