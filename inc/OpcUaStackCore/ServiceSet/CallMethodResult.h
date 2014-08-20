#ifndef __OpcUaStackCore_CallMethodResult_h__
#define __OpcUaStackCore_CallMethodResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CallMethodResult : public  ObjectPool<CallMethodResult>
	{
	  public:
		CallMethodResult(void);
		virtual ~CallMethodResult(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode statusCode(void) const;
		void inputArgumentResults(const OpcUaStatusCodeArray::SPtr inputArgumentResults);
		OpcUaStatusCodeArray::SPtr inputArgumentResults(void) const;
		void inputArgumentDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr inputArgumentDiagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr inputArgumentDiagnosticInfos(void) const;
		void outputArguments(const OpcUaVariantArray::SPtr outputArguments);
		OpcUaVariantArray::SPtr outputArguments(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		 OpcUaStatusCode statusCode_;
		 OpcUaStatusCodeArray::SPtr inputArgumentResultArraySPtr_;
		 OpcUaDiagnosticInfoArray::SPtr inputArgumentDiagnosticInfoArraySPtr_;
		 OpcUaVariantArray::SPtr outputArgumentArraySPtr_;
	};

	class CallMethodResultArray : public OpcUaArray<CallMethodResult::SPtr, SPtrTypeCoder<CallMethodResult> >, public ObjectPool<CallMethodResultArray> {};

}

#endif