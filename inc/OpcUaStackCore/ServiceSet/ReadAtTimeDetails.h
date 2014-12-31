#ifndef __OpcUaStackCore_ReadAtTimeDetails_h__
#define __OpcUaStackCore_ReadAtTimeDetails_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReadAtTimeDetails : public  ObjectPool<ReadAtTimeDetails>, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<ReadAtTimeDetails> SPtr;

		ReadAtTimeDetails(void);
		virtual ~ReadAtTimeDetails(void);

		void reqTimes(const UtcTimeArray::SPtr reqTime);
		UtcTimeArray::SPtr reqTimes(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		UtcTimeArray::SPtr reqTimeArraySPtr_;
	};

}

#endif