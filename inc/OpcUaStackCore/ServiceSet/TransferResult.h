#ifndef __OpcUaStackCore_TransferResult_h__
#define __OpcUaStackCore_TransferResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT TransferResult : public  ObjectPool<TransferResult>
	{
	  public:
		TransferResult(void);
		virtual ~TransferResult(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode statusCode(void) const;
		void availableSequenceNumbers(const OpcUaUInt32Array::SPtr availableSequenceNumbers);
		OpcUaUInt32Array::SPtr availableSequenceNumbers(void) const;
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		  OpcUaStatusCode statusCode_;
		  OpcUaUInt32Array::SPtr availableSequenceNumberArraySPtr_;
	};

	class TransferResultArray : public OpcUaArray<TransferResult::SPtr, SPtrTypeCoder<TransferResult> >, public ObjectPool<TransferResultArray> {};

}

#endif