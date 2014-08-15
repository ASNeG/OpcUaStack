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

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void maxAge(const OpcUaDouble& maxAge);
		OpcUaDouble maxAge(void) const;
		void timestampsToReturn(const OpcUaInt32& timestampsToReturn);
		OpcUaInt32 timestampsToReturn(void) const;
		void readValueIdArray(const ReadValueIdArray::SPtr readValueIdArray);
		ReadValueIdArray::SPtr readValueIdArray(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		OpcUaDouble maxAge_;
		OpcUaInt32 timestampsToReturn_;
		ReadValueIdArray::SPtr readValueIdArraySPtr_;

	};

}

#endif