#ifndef __OpcUaStackCore_RegisterServerResponse_h__
#define __OpcUaStackCore_RegisterServerResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RegisterServerResponse : public  ObjectPool<RegisterServerResponse>
	{
	  public:
		typedef boost::shared_ptr<RegisterServerResponse> SPtr;

		RegisterServerResponse(void);
		virtual ~RegisterServerResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeaderSPtr);
		ResponseHeader::SPtr responseHeader(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeaderSPtr_;
	};

}

#endif