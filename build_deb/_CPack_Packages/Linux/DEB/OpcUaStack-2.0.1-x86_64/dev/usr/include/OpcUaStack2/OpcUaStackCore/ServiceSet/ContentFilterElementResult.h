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

#ifndef __OpcUaStackCore_ContentFilterElementResult_h__
#define __OpcUaStackCore_ContentFilterElementResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ContentFilterElementResult
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<ContentFilterElementResult> SPtr;

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

	class ContentFilterElementResultArray
	: public OpcUaArray<ContentFilterElementResult::SPtr, SPtrTypeCoder<ContentFilterElementResult> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<ContentFilterElementResultArray> SPtr;
	};

}

#endif
