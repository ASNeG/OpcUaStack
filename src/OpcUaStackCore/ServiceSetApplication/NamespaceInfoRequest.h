#ifndef __OpcUaStackCore_RegisterForwardRequest_h__
#define __OpcUaStackCore_RegisterForwardRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT NamespaceInfoRequest : public  ObjectPool<NamespaceInfoRequest>
	{
	  public:
		typedef boost::shared_ptr<NamespaceInfoRequest> SPtr;

		NamespaceInfoRequest(void);
		virtual ~NamespaceInfoRequest(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
	};

}

#endif
