/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSetApplication/RegisterForwardNodeResponse.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa RegisterForwardNodeResponse
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	RegisterForwardNodeResponse::RegisterForwardNodeResponse(void)
	: Object()
	, statusCodeArraySPtr_(boost::make_shared<OpcUaStatusCodeArray>())
	{
	}

	RegisterForwardNodeResponse::~RegisterForwardNodeResponse(void)
	{
	}

	void 
	RegisterForwardNodeResponse::statusCodeArray(const OpcUaStatusCodeArray::SPtr statusCodeArray)
	{
		statusCodeArraySPtr_ = statusCodeArray;
	}
	
	OpcUaStatusCodeArray::SPtr
	RegisterForwardNodeResponse::statusCodeArray(void) const
	{
		return statusCodeArraySPtr_;
	}

	bool
	RegisterForwardNodeResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		return statusCodeArraySPtr_->opcUaBinaryEncode(os);
	}
	
	bool
	RegisterForwardNodeResponse::opcUaBinaryDecode(std::istream& is)
	{
		return statusCodeArraySPtr_->opcUaBinaryDecode(is);
	}
}
