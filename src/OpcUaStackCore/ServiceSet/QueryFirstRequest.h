#ifndef __OpcUaStackCore_QueryFirstRequest_h__
#define __OpcUaStackCore_QueryFirstRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/NodeTypeDescription.h"
#include "OpcUaStackCore/ServiceSet/ViewDescription.h"
#include "OpcUaStackCore/ServiceSet/ContentFilter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT QueryFirstRequest : public  ObjectPool<QueryFirstRequest>
	{
	  public:
		typedef boost::shared_ptr<QueryFirstRequest> SPtr;

		QueryFirstRequest(void);
		virtual ~QueryFirstRequest(void);

		void view(const ViewDescription& view);
		ViewDescription& view(void);
		void nodeTypes(const NodeTypeDescriptionArray::SPtr nodeTypes);
		NodeTypeDescriptionArray::SPtr nodeTypes(void) const;
		void filter(const ContentFilter& filter);
		ContentFilter& filter(void);
		void maxDataSetsToReturn(const OpcUaUInt32& maxDataSetsToReturn);
		OpcUaUInt32 maxDataSetsToReturn(void);
		void maxReferencesToReturn(const OpcUaUInt32& maxReferencesToReturn);
		OpcUaUInt32 maxReferencesToReturn(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ViewDescription view_;
		NodeTypeDescriptionArray::SPtr nodeTypeArraySPtr_;
		ContentFilter filter_;
		OpcUaUInt32 maxDataSetsToReturn_;
		OpcUaUInt32 maxReferencesToReturn_;
	};

}

#endif