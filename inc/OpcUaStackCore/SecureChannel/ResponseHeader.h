#ifndef __OpcUaStackCore_ResponseHeader_h__
#define __OpcUaStackCore_ResponseHeader_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"


namespace OpcUaStackCore
{

	class DLLEXPORT ResponseHeader : public  ObjectPool<ResponseHeader>
	{
	  public:
		ResponseHeader(void);
		virtual ~ResponseHeader(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
	};

}

#endif