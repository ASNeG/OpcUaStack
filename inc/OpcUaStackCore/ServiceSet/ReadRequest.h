#ifndef __OpcUaStackCore_ReadRequest_h__
#define __OpcUaStackCore_ReadRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/ReadValueId.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ReadRequest : public  ObjectPool<ReadRequest>
	{
	  public:
		ReadRequest(void);
		virtual ~ReadRequest(void);

		void maxAge(const OpcUaDouble& maxAge);
		OpcUaDouble maxAge(void) const;
		void timestampsToReturn(const OpcUaInt32& timestampsToReturn);
		OpcUaInt32 timestampsToReturn(void) const;
		void readValueIdArray(const ReadValueIdArray::SPtr readValueIdArray);
		ReadValueIdArray::SPtr readValueIdArray(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaDouble maxAge_;
		OpcUaInt32 timestampsToReturn_;
		ReadValueIdArray::SPtr readValueIdArraySPtr_;
	};

}

#endif