#ifndef __OpcUaStackCore_CancelRequest_h__
#define __OpcUaStackCore_CancelRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OPcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CancelRequest : public  ObjectPool<CancelRequest>
	{
	  public:
		CancelRequest(void);
		virtual ~CancelRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void requestHandle(const IntegerId requestHandle);
		IntegerId requestHandle(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		IntegerId requestHandle_;
	};

}

#endif