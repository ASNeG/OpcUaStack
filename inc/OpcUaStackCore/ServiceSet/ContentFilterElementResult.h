#ifndef __OpcUaStackCore_ContentFilterElementResult_h__
#define __OpcUaStackCore_ContentFilterElementResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ContentFilterElementResult : public  ObjectPool<ContentFilterElementResult>
	{
	  public:
		ContentFilterElementResult(void);
		virtual ~ContentFilterElementResult(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode statusCode(void) const;
		void operandStatusCodes(const OpcUaStatusCodeArray::SPtr operandStatusCodes);
		OpcUaStatusCodeArray::SPtr operandStatusCodes(void) const;
		void operandDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr  operandDiagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr  operandDiagnosticInfos(void) const;
		void elementDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr elementDiagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr elementDiagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;
		OpcUaStatusCodeArray::SPtr operandStatusCodeArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr operandDiagnosticInfoArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr elementDiagnosticInfoArraySPtr_;
	};

	class ContentFilterElementResultArray : public OpcUaArray<ContentFilterElementResult::SPtr, SPtrTypeCoder<ContentFilterElementResult> >, public ObjectPool<ContentFilterElementResultArray> {};

}

#endif