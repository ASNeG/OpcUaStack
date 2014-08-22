#ifndef __OpcUaStackCore_EventFilterResult_h__
#define __OpcUaStackCore_EventFilterResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/ServiceSet/SimpleAttributeOperand.h"
#include "OpcUaStackCore/ServiceSet/ContentFilterResult.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameterBase.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EventFilterResult : public  ObjectPool<EventFilterResult>, public ExtensibleParameterBase
	{
	  public:
		EventFilterResult(void);
		virtual ~EventFilterResult(void);

		void selectClauseResults(const OpcUaStatusCodeArray::SPtr selectClauseResults);
		OpcUaStatusCodeArray::SPtr selectClauseResults(void) const;
		void selectClauseDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr selectClauseDiagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr selectClauseDiagnosticInfos(void) const;
		void whereClauseResult(const ContentFilterResult& whereClause);
		ContentFilterResult& whereClauseResult(void);
		
		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

		//- ExtensibleParameterBase -------------------------------------------
		virtual ExtensibleParameterBase::BSPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaStatusCodeArray::SPtr selectClauseResultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr selectClauseDiagnosticInfoArraySPtr_;
		ContentFilterResult whereClauseResult_;
	};

}

#endif