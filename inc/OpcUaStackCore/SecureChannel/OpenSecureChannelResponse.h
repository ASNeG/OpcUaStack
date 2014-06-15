#ifndef __OpcUaStackCore_OpenSecureChannelResponse_h__
#define __OpcUaStackCore_OpenSecureChannelResponse_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"


namespace OpcUaStackCore
{

	class DLLEXPORT OpenSecureChannelResponse : public  ObjectPool<OpenSecureChannelResponse>
	{
	  public:
		OpenSecureChannelResponse(void);
		virtual ~OpenSecureChannelResponse(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
	};

}

#endif