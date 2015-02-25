#ifndef __OpcUaStackCore_RegisterServerRequest_h__
#define __OpcUaStackCore_RegisterServerRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/RegisteredServer.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RegisterServerRequest : public  ObjectPool<RegisterServerRequest>
	{
	  public:
		typedef boost::shared_ptr<RegisterServerRequest> SPtr;

		RegisterServerRequest(void);
		virtual ~RegisterServerRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void server(const RegisteredServer& server);
		RegisteredServer& server(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		RegisteredServer server_;
	};

}

#endif