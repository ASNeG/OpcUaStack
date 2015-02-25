#ifndef __OpcUaStackCore_HistoryUpdateResult_h__
#define __OpcUaStackCore_HistoryUpdateResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT HistoryUpdateResult : public  ObjectPool<HistoryUpdateResult>
	{
	  public:
		typedef boost::shared_ptr<HistoryUpdateResult> SPtr;

		HistoryUpdateResult(void);
		virtual ~HistoryUpdateResult(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode& statusCode(void);
		void operationResults(const OpcUaStatusCodeArray::SPtr operationResults);
		OpcUaStatusCodeArray::SPtr operationResults(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCode statusCode_;
		OpcUaStatusCodeArray::SPtr operationResultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};

	class HistoryUpdateResultArray : public OpcUaArray<HistoryUpdateResult::SPtr, SPtrTypeCoder<HistoryUpdateResult> >, public ObjectPool<HistoryUpdateResultArray> 
	{
	  public:
		typedef boost::shared_ptr<HistoryUpdateResultArray> SPtr;
	};

}

#endif