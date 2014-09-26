#ifndef __OpcUaStackCore_TranslateBrowsePathsToNodeIdsRequest_h__
#define __OpcUaStackCore_TranslateBrowsePathsToNodeIdsRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/BrowsePath.h"

namespace OpcUaStackCore
{

	class DLLEXPORT TranslateBrowsePathsToNodeIdsRequest : public  ObjectPool<TranslateBrowsePathsToNodeIdsRequest>
	{
	  public:
		TranslateBrowsePathsToNodeIdsRequest(void);
		virtual ~TranslateBrowsePathsToNodeIdsRequest(void);

		void browsePaths(const BrowsePathArray::SPtr browsePaths);
		BrowsePathArray::SPtr browsePaths(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		BrowsePathArray::SPtr browsePathArraySPtr_;
	};

}

#endif