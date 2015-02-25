#ifndef __OpcUaStackCore_FindServersResponse_h__
#define __OpcUaStackCore_FindServersResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/ApplicationDescription.h"

namespace OpcUaStackCore
{

	class DLLEXPORT FindServersResponse : public  ObjectPool<FindServersResponse>
	{
	  public:
		typedef boost::shared_ptr<FindServersResponse> SPtr;

		FindServersResponse(void);
		virtual ~FindServersResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeaderSPtr);
		ResponseHeader::SPtr responseHeader(void) const;
		void servers(const ApplicationDescriptionArray::SPtr servers);
		ApplicationDescriptionArray::SPtr servers(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeaderSPtr_;
		ApplicationDescriptionArray::SPtr serverArraySPtr_;
	};

}

#endif