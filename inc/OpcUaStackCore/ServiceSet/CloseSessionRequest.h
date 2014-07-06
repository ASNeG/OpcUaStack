#ifndef __OpcUaStackCore_CloseSessionRequest_h__
#define __OpcUaStackCore_CloseSessionRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OPcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CloseSessionRequest : public  ObjectPool<CloseSessionRequest>
	{
	  public:
		CloseSessionRequest(void);
		virtual ~CloseSessionRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void deleteSubscriptions(const OpcUaBoolean& deleteSubscriptions);
		OpcUaBoolean deleteSubscriptions(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		OpcUaBoolean deleteSubscriptions_;
	};

}

#endif