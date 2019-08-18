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

#include "OpcUaStackCore/ServiceSet/AddNodesResponse.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddNodesResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddNodesResponse::AddNodesResponse(void)
	: addNodesResultArraySPtr_(boost::make_shared<AddNodesResultArray>())
	, diagnosticInfoArraySPtr_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	AddNodesResponse::~AddNodesResponse(void)
	{
	}

	void
	AddNodesResponse::results(const AddNodesResultArray::SPtr addNodesResultArraySPtr)
	{
		addNodesResultArraySPtr_ = addNodesResultArraySPtr;
	}

	AddNodesResultArray::SPtr
	AddNodesResponse::results() const
	{
		return addNodesResultArraySPtr_;
	}


	void
	AddNodesResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfosSPtr)
	{
		diagnosticInfoArraySPtr_ = diagnosticInfosSPtr;
	}

	OpcUaDiagnosticInfoArray::SPtr
	AddNodesResponse::diagnosticInfos(void) const
	{
		return diagnosticInfoArraySPtr_;
	}
		

	void 
	AddNodesResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		addNodesResultArraySPtr_->opcUaBinaryEncode(os);
		diagnosticInfoArraySPtr_->opcUaBinaryEncode(os);
	}
	
	void 
	AddNodesResponse::opcUaBinaryDecode(std::istream& is)
	{
		addNodesResultArraySPtr_->opcUaBinaryDecode(is);
		diagnosticInfoArraySPtr_->opcUaBinaryDecode(is);
	}

}
