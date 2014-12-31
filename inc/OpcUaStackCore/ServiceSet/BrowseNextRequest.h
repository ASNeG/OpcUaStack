#ifndef __OpcUaStackCore_BrowseNextRequest_h__
#define __OpcUaStackCore_BrowseNextRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BrowseNextRequest : public  ObjectPool<BrowseNextRequest>
	{
	  public:
		typedef boost::shared_ptr<BrowseNextRequest> SPtr;

		BrowseNextRequest(void);
		virtual ~BrowseNextRequest(void);

		void releaseContinuationPoints(const OpcUaBoolean& releaseContinuationPoints);
		OpcUaBoolean releaseContinuationPoints(void);
		void continuationPoints(const OpcUaByteStringArray::SPtr continuationPoints);
		OpcUaByteStringArray::SPtr continuationPoints(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaBoolean releaseContinuationPoints_;
		OpcUaByteStringArray::SPtr continuationPointArraySPtr_;
	};

}

#endif