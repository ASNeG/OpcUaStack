#ifndef __OpcUaStackCore_GetEndpointsRequest_h__
#define __OpcUaStackCore_GetEndpointsRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	class DLLEXPORT GetEndpointsRequest : public  ObjectPool<GetEndpointsRequest>
	{
	  public:
		typedef boost::shared_ptr<GetEndpointsRequest> SPtr;

		GetEndpointsRequest(void);
		virtual ~GetEndpointsRequest(void);

		void endpointUrl(const OpcUaString& endpointUrl);
		void endpointUrl(const std::string& endpointUrl);
		OpcUaString& endpointUrl(void);
		void localeIds(const OpcUaStringArray::SPtr localIds);
		OpcUaStringArray::SPtr localeIds(void) const;
		void profileUris(const OpcUaStringArray::SPtr profileUris);
		OpcUaStringArray::SPtr profileUris(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaString endpointUrl_;
		OpcUaStringArray::SPtr localeIdArraySPtr_;
		OpcUaStringArray::SPtr profileUriArraySPtr_;
	};

}

#endif