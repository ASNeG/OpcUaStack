#ifndef __OpcUaStackCore_CallRequest_h__
#define __OpcUaStackCore_CallRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/CallMethodRequest.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CallRequest : public  ObjectPool<CallRequest>
	{
	  public:
		typedef boost::shared_ptr<CallRequest> SPtr;

		CallRequest(void);
		virtual ~CallRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeader);
		RequestHeader::SPtr requestHeader(void) const;
		void methodsToCall(const CallMethodRequestArray::SPtr methodsToCall);
		CallMethodRequestArray::SPtr methodsToCall(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		CallMethodRequestArray::SPtr callMethodRequestArraySPtr_;
	};

}

#endif