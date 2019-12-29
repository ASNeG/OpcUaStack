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

#ifndef __OpcUaStackCore_CallMethodResult_h__
#define __OpcUaStackCore_CallMethodResult_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/OpcUaVariant.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CallMethodResult
	: public Object
	, public JsonFormatter
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

		void copyTo(CallMethodResult& callMethodResult);
		void out(std::ostream& os) const {};

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);
		bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns) { return false; }
		bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns) { return false; }

	  protected:
	    bool jsonEncodeImpl(boost::property_tree::ptree &pt) const override;
	    bool jsonDecodeImpl(const boost::property_tree::ptree &pt) override;

	  private:
		 OpcUaStatusCode statusCode_;
		 OpcUaStatusCodeArray::SPtr inputArgumentResultArraySPtr_;
		 OpcUaDiagnosticInfoArray::SPtr inputArgumentDiagnosticInfoArraySPtr_;
		 OpcUaVariantArray::SPtr outputArgumentArraySPtr_;
	};

	class DLLEXPORT CallMethodResultArray
	: public OpcUaArray<CallMethodResult::SPtr, SPtrTypeCoder<CallMethodResult> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<CallMethodResultArray> SPtr;
	};

}

#endif
