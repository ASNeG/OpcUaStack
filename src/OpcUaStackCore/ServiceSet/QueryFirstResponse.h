/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_QueryFirstResponse_h__
#define __OpcUaStackCore_QueryFirstResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/ServiceSet/QueryDataSet.h"
#include "OpcUaStackCore/ServiceSet/ParsingResult.h"
#include "OpcUaStackCore/StandardDataTypes/ContentFilterResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT QueryFirstResponse
	: public  Object
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

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		QueryDataSetArray::SPtr queryDataSetArraySPtr_;
		OpcUaByteString continuationPoint_;
		ParsingResultArray::SPtr parsingResultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
		ContentFilterResult filterResult_;
	};

}

#endif
