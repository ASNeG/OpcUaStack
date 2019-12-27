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

#ifndef __OpcUaStackCore_SetTriggeringResponse_h__
#define __OpcUaStackCore_SetTriggeringResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDiagnosticInfo.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SetTriggeringResponse
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<SetTriggeringResponse> SPtr;

		SetTriggeringResponse(void);
		virtual ~SetTriggeringResponse(void);

		void addResults(const OpcUaStatusCodeArray::SPtr addResults);
		OpcUaStatusCodeArray::SPtr addResults(void) const;
		void addDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr addDiagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr addDiagnosticInfos(void) const;
		void removeResults(const OpcUaStatusCodeArray::SPtr removeResults);
		OpcUaStatusCodeArray::SPtr removeResults(void) const;
		void removeDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr removeDiagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr removeDiagnosticInfos(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaStatusCodeArray::SPtr addResultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr addDiagnosticInfoArraySPtr_;
		OpcUaStatusCodeArray::SPtr removeResultArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr removeDiagnosticInfoArraySPtr_;
	};

}

#endif
