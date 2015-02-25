#ifndef __OpcUaStackCore_ReadEventDetails_h__
#define __OpcUaStackCore_ReadEventDetails_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReadEventDetails : public  ObjectPool<ReadEventDetails>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<ReadEventDetails> SPtr;

		ReadEventDetails(void);
		virtual ~ReadEventDetails(void);

		void numValuesPerNode(const OpcUaUInt32& numValuesPerNode);
		OpcUaUInt32 numValuesPerNode(void) const;
		void startTime(const UtcTime& startTime);
		void startTime(const boost::posix_time::ptime& startTime);
		UtcTime& startTime(void);
		void endTime(const UtcTime& endTime);
		void endTime(const boost::posix_time::ptime& endTime);
		UtcTime& endTime(void);
		void filter(const ExtensibleParameter::SPtr filter);
		ExtensibleParameter::SPtr filter(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaUInt32 numValuesPerNode_;
		UtcTime startTime_;
		UtcTime endTime_;
		ExtensibleParameter::SPtr filterSPtr_;
	};

}

#endif