#ifndef __OpcUaStackCore_DeleteReferencesResult_h__
#define __OpcUaStackCore_DeleteReferencesResult_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


namespace OpcUaStackCore
{

	class DLLEXPORT DeleteReferencesResult : public ObjectPool<DeleteReferencesResult>
	{
	  public:
		typedef boost::shared_ptr<DeleteReferencesResult> SPtr;

	    DeleteReferencesResult(void);
		~DeleteReferencesResult(void);

		void statusCode(OpcUaStatusCode statusCode);
		OpcUaStatusCode statusCode(void) const;
				
		void opcUaBinaryEncode(std::ostream& os) const; 
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;			
	};

	class DeleteReferencesResultArray : public OpcUaArray<DeleteReferencesResult::SPtr, SPtrTypeCoder<DeleteReferencesResult> >, public ObjectPool<DeleteReferencesResultArray> 
	{
	  public:
		typedef boost::shared_ptr<DeleteReferencesResultArray> SPtr;
	};
}

#endif
