#ifndef __OpcUaStackCore_CloseSessionResponse_h__
#define __OpcUaStackCore_CloseSessionResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OPcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CloseSessionResponse : public  ObjectPool<CloseSessionResponse>
	{
	  public:
		CloseSessionResponse(void);
		virtual ~CloseSessionResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeader_;
	};

}

#endif