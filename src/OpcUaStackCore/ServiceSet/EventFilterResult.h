/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

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

	class DLLEXPORT EventFilterResult
	: public Object
	, public ExtensibleParameterBase
	{
	  public:
		typedef boost::shared_ptr<EventFilterResult> SPtr;

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
		virtual ExtensibleParameterBase::SPtr factory(void);
		//- ExtensibleParameterBase -------------------------------------------

	  private:
		OpcUaStatusCodeArray::SPtr selectClauseResultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr selectClauseDiagnosticInfoArraySPtr_;
		ContentFilterResult whereClauseResult_;
	};

}

#endif
