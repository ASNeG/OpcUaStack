#ifndef __OpcUaStackCore_BrowsePathResult_h__
#define __OpcUaStackCore_BrowsePathResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/RelativePath.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT BrowsePathResult : public  ObjectPool<BrowsePathResult>
	{
	  public:
		BrowsePathResult(void);
		virtual ~BrowsePathResult(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode& statusCode(void);
		void targets(const RelativePathElementArray::SPtr targets);
		RelativePathElementArray::SPtr targets(void) const;
		void tragetId(const OpcUaExpandedNodeId::SPtr targetId);
		OpcUaExpandedNodeId::SPtr targetId(void);
		void remainingPathIndex(const OpcUaUInt32& remainingPathIndex);
		OpcUaUInt32 remainingPathIndex(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;
		RelativePathElementArray::SPtr targetArraySPtr_;
		OpcUaExpandedNodeId::SPtr targetIdSPtr_;
		OpcUaUInt32 remainingPathIndex_;
	};

	class BrowsePathResultArray : public OpcUaArray<BrowsePathResult::SPtr, SPtrTypeCoder<BrowsePathResult> >, public ObjectPool<BrowsePathResultArray> {};

}

#endif