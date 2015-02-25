#ifndef __OpcUaStackCore_AggregateFilterConfiguration_h__
#define __OpcUaStackCore_AggregateFilterConfiguration_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT AggregateConfiguration : public  ObjectPool<AggregateConfiguration>
	{
	  public:
		typedef boost::shared_ptr<AggregateConfiguration> SPtr;

		AggregateConfiguration(void);
		virtual ~AggregateConfiguration(void);

		void useServerCapabilitiesDefaults(const OpcUaBoolean& useServerCapabilitiesDefaults);
		OpcUaBoolean useServerCapabilitiesDefaults(void);
		void  treatUncertainAsBad(const OpcUaBoolean& treatUncertainAsBad);
		OpcUaBoolean treatUncertainAsBad(void); 
		void percentDataBad(const OpcUaByte& percentDataBad);
		OpcUaByte percentDataBad(void);
		void percentDataGood(const OpcUaByte& percentDataGood);
		OpcUaByte percentDataGood(void);
		void steppedSlopedExtrapolation(const OpcUaBoolean& steppedSlopedExtrapolation);
		OpcUaByte steppedSlopedExtrapolation(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaBoolean useServerCapabilitiesDefaults_;
		OpcUaBoolean treatUncertainAsBad_;
		OpcUaByte percentDataBad_;
		OpcUaByte percentDataGood_;
		OpcUaBoolean steppedSlopedExtrapolation_;
	};

}

#endif