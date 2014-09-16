#ifndef __OpcUaStackCore_DeleteNodesResult_h__
#define __OpcUaStackCore_DeleteNodesResult_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


namespace OpcUaStackCore
{

	class DLLEXPORT DeleteNodesResult : public ObjectPool<DeleteNodesResult>
	{
	  public:
	    DeleteNodesResult(void);
		~DeleteNodesResult(void);

		void statusCode(OpcUaStatusCode statusCode);
		OpcUaStatusCode statusCode(void) const;
				
		void opcUaBinaryEncode(std::ostream& os) const; 
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;			
	};

	class DeleteNodesResultArray : public OpcUaArray<DeleteNodesResult::SPtr, SPtrTypeCoder<DeleteNodesResult> >, public ObjectPool<DeleteNodesResultArray> {};
}

#endif
