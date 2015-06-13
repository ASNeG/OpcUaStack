#ifndef __OpcUaStackCore_RegisterForwardRequest_h__
#define __OpcUaStackCore_RegisterForwardRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSetApplication/ForwardInfoSync.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RegisterForwardRequest : public  ObjectPool<RegisterForwardRequest>
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardRequest> SPtr;

		RegisterForwardRequest(void);
		virtual ~RegisterForwardRequest(void);

		void nodesToRegister(const OpcUaNodeIdArray::SPtr nodesToRegister);
		OpcUaNodeIdArray::SPtr nodesToRegister(void) const;
		void forwardInfoSync(ForwardInfoSync::SPtr forwardInfo);
		ForwardInfoSync::SPtr forwardInfoSync(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ForwardInfoSync::SPtr forwardInfoSync_;
		OpcUaNodeIdArray::SPtr nodesToRegisterArraySPtr_;
	};

}

#endif
