#ifndef __OpcUaStackCore_QueryFirstResponse_h__
#define __OpcUaStackCore_QueryFirstResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/ServiceSet/QueryDataSet.h"
#include "OpcUaStackCore/ServiceSet/ParsingResult.h"
#include "OpcUaStackCore/ServiceSet/ContentFilterResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT QueryFirstResponse : public  ObjectPool<QueryFirstResponse>
	{
	  public:
		typedef boost::shared_ptr<QueryFirstResponse> SPtr;

		QueryFirstResponse(void);
		virtual ~QueryFirstResponse(void);

		void queryDataSets(const QueryDataSetArray::SPtr queryDataSets);
		QueryDataSetArray::SPtr queryDataSets(void) const;
		void continuationPoint(const OpcUaByteString& continuationPoint);
		OpcUaByteString& continuationPoint(void);
		void parsingResults(const ParsingResultArray::SPtr parsingResults);
		ParsingResultArray::SPtr parsingResults(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;
		void filterResult(const ContentFilterResult& filterResult);
		ContentFilterResult& filterResult(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		QueryDataSetArray::SPtr queryDataSetArraySPtr_;
		OpcUaByteString continuationPoint_;
		ParsingResultArray::SPtr parsingResultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
		ContentFilterResult filterResult_;
	};

}

#endif