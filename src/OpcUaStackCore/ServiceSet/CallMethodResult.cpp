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

#include <boost/make_shared.hpp>
#include "OpcUaStackCore/BuildInTypes/OpcUaStatus.h"
#include "OpcUaStackCore/ServiceSet/CallMethodResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa CallMethodResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	CallMethodResult::CallMethodResult(void)
	: Object()
	, statusCode_()
	, inputArgumentResultArraySPtr_(boost::make_shared<OpcUaStatusCodeArray>())
	, inputArgumentDiagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	, outputArgumentArraySPtr_(boost::make_shared<OpcUaVariantArray>())
	{
	}

	CallMethodResult::~CallMethodResult(void)
	{
	}

	void 
	CallMethodResult::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}
	
	OpcUaStatusCode 
	CallMethodResult::statusCode(void) const
	{
		return statusCode_;
	}
	
	void 
	CallMethodResult::inputArgumentResults(const OpcUaStatusCodeArray::SPtr inputArgumentResults)
	{
		inputArgumentResultArraySPtr_ = inputArgumentResults;
	}
	
	OpcUaStatusCodeArray::SPtr 
	CallMethodResult::inputArgumentResults(void) const
	{
		return inputArgumentResultArraySPtr_;
	}
	
	void 
	CallMethodResult::inputArgumentDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr inputArgumentDiagnosticInfos)
	{
		inputArgumentDiagnosticInfoArraySPtr_ = inputArgumentDiagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	CallMethodResult::inputArgumentDiagnosticInfos(void) const
	{
		return inputArgumentDiagnosticInfoArraySPtr_;
	}

	void 
	CallMethodResult::outputArguments(const OpcUaVariantArray::SPtr outputArguments)
	{
		outputArgumentArraySPtr_ = outputArguments;
	}
	
	OpcUaVariantArray::SPtr 
	CallMethodResult::outputArguments(void) const
	{
		return outputArgumentArraySPtr_;
	}

	void
	CallMethodResult::copyTo(CallMethodResult& callMethodResult)
	{
		callMethodResult.statusCode(statusCode_);
		inputArgumentResultArraySPtr_->copyTo(*callMethodResult.inputArgumentResults().get());
		inputArgumentDiagnosticInfoArraySPtr_->copyTo(*callMethodResult.inputArgumentDiagnosticInfos().get());
		outputArgumentArraySPtr_->copyTo(*callMethodResult.outputArguments().get());
	}

	bool
	CallMethodResult::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		rc &= inputArgumentResultArraySPtr_->opcUaBinaryEncode(os);
		rc &= inputArgumentDiagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		rc &= outputArgumentArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	CallMethodResult::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaInt32 tmp;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		rc &= inputArgumentResultArraySPtr_->opcUaBinaryDecode(is);
		rc &= inputArgumentDiagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		rc &= outputArgumentArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}

	bool
	CallMethodResult::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc = true;
		rc = rc & jsonNumberEncode(pt, (uint32_t)statusCode_, "StatusCode");
		rc = rc & jsonArraySPtrEncode(pt, inputArgumentResultArraySPtr_, "InputArgumentResults", true);
		rc = rc & jsonArraySPtrEncode(pt, outputArgumentArraySPtr_, "OutputArguments", true);
		return rc;
	}

	bool
	CallMethodResult::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		bool rc = true;
		rc = rc & jsonNumberDecode(pt, *(uint32_t*)&statusCode_, "StatusCode");
		rc = rc & jsonArraySPtrDecode(pt, inputArgumentResultArraySPtr_, "InputArgumentResults", true);
		rc = rc & jsonArraySPtrDecode(pt, outputArgumentArraySPtr_, "OutputArguments", true);
		return rc;
	}

}
