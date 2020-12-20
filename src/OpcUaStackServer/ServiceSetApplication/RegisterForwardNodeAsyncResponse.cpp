/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardNodeAsyncResponse.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterForwardNodeAsyncResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterForwardNodeAsyncResponse::RegisterForwardNodeAsyncResponse(void)
	: Object()
	, statusCodeArraySPtr_(boost::make_shared<OpcUaStatusCodeArray>())
	{
	}

	RegisterForwardNodeAsyncResponse::~RegisterForwardNodeAsyncResponse(void)
	{
	}

	void 
	RegisterForwardNodeAsyncResponse::statusCodeArray(const OpcUaStatusCodeArray::SPtr statusCodeArray)
	{
		statusCodeArraySPtr_ = statusCodeArray;
	}
	
	OpcUaStatusCodeArray::SPtr
	RegisterForwardNodeAsyncResponse::statusCodeArray(void) const
	{
		return statusCodeArraySPtr_;
	}

	bool
	RegisterForwardNodeAsyncResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		return statusCodeArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	RegisterForwardNodeAsyncResponse::opcUaBinaryDecode(std::istream& is)
	{
		return statusCodeArraySPtr_->opcUaBinaryDecode(is);
	}
}
