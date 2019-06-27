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

#ifndef __OpcUaStackCore_TranslateBrowsePathsToNodeIdsResponse_h__
#define __OpcUaStackCore_TranslateBrowsePathsToNodeIdsResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaDiagnosticInfo.h"
#include "OpcUaStackCore/ServiceSet/BrowsePathResult.h"

namespace OpcUaStackCore
{

	class DLLEXPORT TranslateBrowsePathsToNodeIdsResponse
	: public Object
	{
	  public:
		typedef boost::shared_ptr<TranslateBrowsePathsToNodeIdsResponse> SPtr;

	    TranslateBrowsePathsToNodeIdsResponse(void);
		virtual ~TranslateBrowsePathsToNodeIdsResponse(void);

		void results(const BrowsePathResultArray::SPtr results);
		BrowsePathResultArray::SPtr results(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		BrowsePathResultArray::SPtr resultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};
}

#endif
