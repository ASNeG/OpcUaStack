#ifndef __OpcUaStackCore_RegisterNodesResponse_h__
#define __OpcUaStackCore_RegisterNodesResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/BrowseResult.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT RegisterNodesResponse : public ObjectPool<RegisterNodesResponse>
	{
	  public:
		typedef boost::shared_ptr<RegisterNodesResponse> SPtr;

	    RegisterNodesResponse(void);
		virtual ~RegisterNodesResponse(void);

		void registeredNodeIds(const OpcUaNodeIdArray::SPtr registeredNodeIds);
		OpcUaNodeIdArray::SPtr registeredNodeIds(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaNodeIdArray::SPtr registeredNodeIdArraySPtr_;
	};
}

#endif