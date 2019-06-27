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

#ifndef __OpcUaStackCore_CallMethodResult_h__
#define __OpcUaStackCore_CallMethodResult_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaArray.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CallMethodResult
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<CallMethodResult> SPtr;

		CallMethodResult(void);
		virtual ~CallMethodResult(void);

		void statusCode(const OpcUaStatusCode& statusCode);
		OpcUaStatusCode statusCode(void) const;
		void inputArgumentResults(const OpcUaStatusCodeArray::SPtr inputArgumentResults);
		OpcUaStatusCodeArray::SPtr inputArgumentResults(void) const;
		void inputArgumentDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr inputArgumentDiagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr inputArgumentDiagnosticInfos(void) const;
		void outputArguments(const OpcUaVariantArray::SPtr outputArguments);
		OpcUaVariantArray::SPtr outputArguments(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		 OpcUaStatusCode statusCode_;
		 OpcUaStatusCodeArray::SPtr inputArgumentResultArraySPtr_;
		 OpcUaDiagnosticInfoArray::SPtr inputArgumentDiagnosticInfoArraySPtr_;
		 OpcUaVariantArray::SPtr outputArgumentArraySPtr_;
	};

	class CallMethodResultArray
	: public OpcUaArray<CallMethodResult::SPtr, SPtrTypeCoder<CallMethodResult> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<CallMethodResultArray> SPtr;
	};

}

#endif
