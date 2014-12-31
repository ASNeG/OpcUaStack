#ifndef __OpcUaStackCore_AggregateFilterResult_h__
#define __OpcUaStackCore_AggregateFilterResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AggregateFilterResult : public  ObjectPool<AggregateFilterResult>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<AggregateFilterResult> SPtr;

		AggregateFilterResult(void);
		virtual ~AggregateFilterResult(void);

		void revisedStartTime(const UtcTime& time);
		void revisedStartTime(const boost::posix_time::ptime& time);
		UtcTime revisedStartTime(void) const;
		void revisedProcessingInterval(const OpcUaDouble& revisedProcessingInterval);
		OpcUaDouble revisedProcessingInterval(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		UtcTime revisedStartTime_;
		OpcUaDouble revisedProcessingInterval_;
	};

}

#endif