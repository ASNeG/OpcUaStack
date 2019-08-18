/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/HistoryUpdateRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa HistoryUpdateRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	HistoryUpdateRequest::HistoryUpdateRequest(void)
	: Object()
	, historyUpdateDetailsSPtr_(boost::make_shared<OpcUaExtensibleParameterArray>())
	{
	}

	HistoryUpdateRequest::~HistoryUpdateRequest(void)
	{
	}

	OpcUaExtensibleParameterArray::SPtr&
	HistoryUpdateRequest::historyUpdateDetails(void)
	{
		return historyUpdateDetailsSPtr_;
	}

	bool 
	HistoryUpdateRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		historyUpdateDetailsSPtr_->opcUaBinaryEncode(os);
		return true;
	}
	
	bool 
	HistoryUpdateRequest::opcUaBinaryDecode(std::istream& is)
	{
		historyUpdateDetailsSPtr_->opcUaBinaryDecode(is);
		return true;
	}

}
