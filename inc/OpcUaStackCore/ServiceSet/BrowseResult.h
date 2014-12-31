#ifndef __OpcUaStackCore_BrowseResult_h__
#define __OpcUaStackCore_BrowseResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/ReferenceDescription.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{
   
	class DLLEXPORT BrowseResult : public  ObjectPool<BrowseResult>
	{
	  public:
		typedef boost::shared_ptr<BrowseResult> SPtr;

		BrowseResult(void);
		virtual ~BrowseResult(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode& statusCode(void);
		void continuationPoint(const OpcUaByteString& continuationPoint);
		OpcUaByteString& continuationPoint(void);
		void references(const ReferenceDescriptionArray::SPtr references);
		ReferenceDescriptionArray::SPtr references(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;
		OpcUaByteString continuationPoint_;
		ReferenceDescriptionArray::SPtr referenceArraySPtr_;
	};

	class BrowseResultArray : public OpcUaArray<BrowseResult::SPtr, SPtrTypeCoder<BrowseResult> >, public ObjectPool<BrowseResultArray> 
	{
	  public:
		typedef boost::shared_ptr<BrowseResultArray> SPtr;
	};

}

#endif