#ifndef __OpcUaStackCore_QueryNextRequest_h__
#define __OpcUaStackCore_QueryNextRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT QueryNextRequest : public  ObjectPool<QueryNextRequest>
	{
	  public:
		QueryNextRequest(void);
		virtual ~QueryNextRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeader);
		RequestHeader::SPtr requestHeader(void) const;
		void releaseContinuationPoint(const OpcUaBoolean& releaseContinuationPoint);
		OpcUaBoolean releaseContinuationPoint(void);
		void continuationPoint(const OpcUaByteString& continuationPoint);
		OpcUaByteString& continuationPoint(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		OpcUaBoolean releaseContinuationPoint_;
		OpcUaByteString continuationPoint_;
	};

}

#endif