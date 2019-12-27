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

#include "OpcUaStackCore/ServiceSet/SetTriggeringResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa SetTriggeringResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	SetTriggeringResponse::SetTriggeringResponse(void)
	: Object()
	, addResultArraySPtr_(boost::make_shared<OpcUaStatusCodeArray>())
	, addDiagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	, removeResultArraySPtr_(boost::make_shared<OpcUaStatusCodeArray>())
	, removeDiagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	SetTriggeringResponse::~SetTriggeringResponse(void)
	{
	}

	void 
	SetTriggeringResponse::addResults(const OpcUaStatusCodeArray::SPtr results)
	{
		addResultArraySPtr_ = results;
	}
	
	OpcUaStatusCodeArray::SPtr
	SetTriggeringResponse::addResults(void) const
	{
		return addResultArraySPtr_;
	}	
	
	void 
	SetTriggeringResponse::addDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		addDiagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	SetTriggeringResponse::addDiagnosticInfos(void) const
	{
		return addDiagnosticInfoArraySPtr_;
	}

	void 
	SetTriggeringResponse::removeResults(const OpcUaStatusCodeArray::SPtr results)
	{
		removeResultArraySPtr_ = results;
	}
	
	OpcUaStatusCodeArray::SPtr
	SetTriggeringResponse::removeResults(void) const
	{
		return removeResultArraySPtr_;
	}	
	
	void 
	SetTriggeringResponse::removeDiagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		removeDiagnosticInfoArraySPtr_ = diagnosticInfos;
	}
	
	OpcUaDiagnosticInfoArray::SPtr 
	SetTriggeringResponse::removeDiagnosticInfos(void) const
	{
		return removeDiagnosticInfoArraySPtr_;
	}

	bool
	SetTriggeringResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= addResultArraySPtr_->opcUaBinaryEncode(os);
		rc &= addDiagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
		rc &= removeResultArraySPtr_->opcUaBinaryEncode(os);
		rc &= removeDiagnosticInfoArraySPtr_->opcUaBinaryEncode(os);

		return rc;
	}
	
	bool
	SetTriggeringResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= addResultArraySPtr_->opcUaBinaryDecode(is);
		rc &= addDiagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
		rc &= removeResultArraySPtr_->opcUaBinaryDecode(is);
		rc &= removeDiagnosticInfoArraySPtr_->opcUaBinaryDecode(is);

		return rc;
	}
}
