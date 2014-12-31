#ifndef __OpcUaStackCore_ParsingResult_h__
#define __OpcUaStackCore_ParsingResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ParsingResult : public  ObjectPool<ParsingResult>
	{
	  public:
		typedef boost::shared_ptr<ParsingResult> SPtr;

		ParsingResult(void);
		virtual ~ParsingResult(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode& statusCode(void);
		void dataStatusCodes(const OpcUaStatusCodeArray::SPtr dataStatusCodes);
		OpcUaStatusCodeArray::SPtr dataStatusCodes(void) const;
		void dataDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr dataDiagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr dataDiagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;
		OpcUaStatusCodeArray::SPtr dataStatusCodeArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr dataDiagnosticInfoArraySPtr_;
	};

	class ParsingResultArray : public OpcUaArray<ParsingResult::SPtr, SPtrTypeCoder<ParsingResult> >, public ObjectPool<ParsingResultArray> 
	{
	  public:
		typedef boost::shared_ptr<ParsingResultArray> SPtr;
	};

}

#endif