#ifndef __OpcUaStackCore_CancelResponse_h__
#define __OpcUaStackCore_CancelResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CancelResponse : public  ObjectPool<CancelResponse>
	{
	  public:
		typedef boost::shared_ptr<CancelResponse> SPtr;

		CancelResponse(void);
		virtual ~CancelResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void) const;
		void cancelCount(const OpcUaInt32& cancelCount);
		OpcUaInt32 cancelCount(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeader_;
		OpcUaInt32 cancelCount_;
	};

}

#endif
