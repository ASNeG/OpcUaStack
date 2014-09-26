#ifndef __OpcUaStackCore_TranslateBrowsePathsToNodeIdsResponse_h__
#define __OpcUaStackCore_TranslateBrowsePathsToNodeIdsResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/BrowsePathResult.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT TranslateBrowsePathsToNodeIdsResponse : public ObjectPool<TranslateBrowsePathsToNodeIdsResponse>
	{
	  public:
	    TranslateBrowsePathsToNodeIdsResponse(void);
		virtual ~TranslateBrowsePathsToNodeIdsResponse(void);

		void results(const BrowsePathResultArray::SPtr results);
		BrowsePathResultArray::SPtr results(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		BrowsePathResultArray::SPtr resultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};
}

#endif