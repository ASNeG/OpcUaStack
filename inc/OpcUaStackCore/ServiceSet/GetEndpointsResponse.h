#ifndef __OpcUaStackCore_GetEndpointsResponse_h__
#define __OpcUaStackCore_GetEndpointsResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"

namespace OpcUaStackCore
{

	class DLLEXPORT GetEndpointsResponse : public  ObjectPool<GetEndpointsResponse>
	{
	  public:
		GetEndpointsResponse(void);
		virtual ~GetEndpointsResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeaderSPtr);
		ResponseHeader::SPtr responseHeader(void) const;
		void endpoints(const EndpointDescriptionArray::SPtr endpoints);
		EndpointDescriptionArray::SPtr endpoints(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeaderSPtr_;
		EndpointDescriptionArray::SPtr endpointArraySPtr_;
	};

}

#endif