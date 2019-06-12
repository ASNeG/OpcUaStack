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
	, inputArgumentResultArraySPtr_(constructSPtr<OpcUaStatusCodeArray>())
	, inputArgumentDiagnosticInfoArraySPtr_(constructSPtr<OpcUaDiagnosticInfoArray>())
	, outputArgumentArraySPtr_(constructSPtr<OpcUaVariantArray>())
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

	void 
	CallMethodResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		inputArgumentResultArraySPtr_->opcUaBinaryEncode(os);
		inputArgumentDiagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		outputArgumentArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	CallMethodResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		inputArgumentResultArraySPtr_->opcUaBinaryDecode(is);
		inputArgumentDiagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		outputArgumentArraySPtr_->opcUaBinaryDecode(is);
	}

	bool
	CallMethodResult::jsonEncodeImpl(boost::property_tree::ptree &pt) const
	{
		bool rc = true;
		rc = rc & jsonNumberEncode(pt, (uint32_t)statusCode_, "StatusCode", false, (uint32_t)0);
		rc = rc & jsonArraySPtrEncode(pt, inputArgumentResultArraySPtr_, "InputArgumentResults", true);

#if 0
		OpcUaStatusArray statusArray;
		statusArray.resize(inputArgumentResultArraySPtr_->size());
		for (uint32_t idx = 0; idx < inputArgumentResultArraySPtr_->size(); idx++) {
			OpcUaStatusCode statusCode;
			inputArgumentResultArraySPtr_->get(idx, statusCode);

			auto status = boost::make_shared<OpcUaStatus>(statusCode);
			statusArray.push_back(status);
		}

		// encode input argument results
		if (statusArray.size() > 0) {
			if (!statusArray.jsonEncode(pt, "InputArgumentResults")) {
				Log(Error, "CallMethodResult json encode error")
					.parameter("Element", "InputArgumentResults");
				return false;
			}
		}
#endif

		// encode output argument array
		if (outputArgumentArraySPtr_->size() > 0) {
			if (!outputArgumentArraySPtr_->jsonEncode(pt, "OutputArguments")) {
				Log(Error, "CallMethodResult json encode error")
			    	.parameter("Element", "OutputArguments");
				return false;
			}
		}

		return rc;
	}

	bool
	CallMethodResult::jsonDecodeImpl(const boost::property_tree::ptree &pt)
	{
		boost::optional<const boost::property_tree::ptree&> tmpTree;

		// get status code
		OpcUaStatus status(Success);
		tmpTree = pt.get_child_optional("StatusCode");
		if (tmpTree) {
			if (!status.jsonDecode(pt, "StatusCode")) {
				Log(Error, "CallMethodResult json decode error")
		        	.parameter("Element", "Status");
				return false;
			}
		}
		statusCode_ = status.enumeration();

		// decode input arguments result
		OpcUaStatusArray statusArray;
		if (!statusArray.jsonDecode(pt, "InputArgumentResults")) {
			Log(Error, "CallMethodResult json decode error")
			    .parameter("Element", "Results");
			return false;
		}
		inputArgumentResultArraySPtr_->resize(statusArray.size());
		for (uint32_t idx = 0; idx < statusArray.size(); idx++) {
			OpcUaStatus::SPtr status;
			statusArray.get(idx, status);
			inputArgumentResultArraySPtr_->push_back(status->enumeration());
		}

		// decode output argument array
		if (!outputArgumentArraySPtr_->jsonDecode(pt, "OutputArguments")) {
			Log(Error, "CallMethodResult json decode error")
			    .parameter("Element", "OutputArguments");
			return false;
		}

		return true;
	}

}
