#ifndef __OpcUaStackCore_BrowseRequest_h__
#define __OpcUaStackCore_BrowseRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/ViewDescription.h"
#include "OpcUaStackCore/ServiceSet/BrowseDescription.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BrowseRequest : public  ObjectPool<BrowseRequest>
	{
	  public:
		typedef boost::shared_ptr<BrowseRequest> SPtr;

		BrowseRequest(void);
		virtual ~BrowseRequest(void);

		void view(const ViewDescription& view);
		ViewDescription& view(void);
		void requestMaxReferencesPerNode(const OpcUaUInt32& requestMaxReferencesPerNode);
		OpcUaUInt32 requestMaxReferencesPerNode(void);
		void nodesToBrowse(const BrowseDescriptionArray::SPtr nodesToBrowse);
		BrowseDescriptionArray::SPtr nodesToBrowse(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ViewDescription view_;
		OpcUaUInt32 requestMaxReferencesPerNode_;
		BrowseDescriptionArray::SPtr nodesToBrowseArraySPtr_;
	};

}

#endif