#ifndef __OpcUaStackCore_GetEndpointsResponse_h__
#define __OpcUaStackCore_GetEndpointsResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"

namespace OpcUaStackCore
{

	class DLLEXPORT GetEndpointsResponse : public  ObjectPool<GetEndpointsResponse>
	{
	  public:
		typedef boost::shared_ptr<GetEndpointsResponse> SPtr;

		GetEndpointsResponse(void);
		virtual ~GetEndpointsResponse(void);

		void endpoints(const EndpointDescriptionArray::SPtr endpoints);
		EndpointDescriptionArray::SPtr endpoints(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		EndpointDescriptionArray::SPtr endpointArraySPtr_;
	};

}

#endif