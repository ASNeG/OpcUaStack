#ifndef __OpcUaStackCore_AddReferencesResult_h__
#define __OpcUaStackCore_AddReferencesResult_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"


namespace OpcUaStackCore
{

	class DLLEXPORT AddReferencesResult : public ObjectPool<AddReferencesResult>
	{
	  public:
	    AddReferencesResult(void);
		~AddReferencesResult(void);

		void statusCode(OpcUaStatusCode statusCode);
		OpcUaStatusCode statusCode(void) const;
				
		void opcUaBinaryEncode(std::ostream& os) const; 
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;			
	};

	class AddReferencesResultArray : public OpcUaArray<AddReferencesResult::SPtr, SPtrTypeCoder<AddReferencesResult> >, public ObjectPool<AddReferencesResultArray> {};
}

#endif
