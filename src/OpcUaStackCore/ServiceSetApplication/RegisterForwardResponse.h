#ifndef __OpcUaStackCore_RegisterForwardResponse_h__
#define __OpcUaStackCore_RegisterForwardResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/BrowseResult.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RegisterForwardResponse : public ObjectPool<RegisterForwardResponse>
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardResponse> SPtr;

	    RegisterForwardResponse(void);
		virtual ~RegisterForwardResponse(void);

		void statusCodeArray(const OpcUaStatusCodeArray::SPtr statusCodeArray);
		OpcUaStatusCodeArray::SPtr statusCodeArray(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCodeArray::SPtr statusCodeArraySPtr_;
	};
}

#endif
