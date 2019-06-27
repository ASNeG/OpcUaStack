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

#include "OpcUaStackCore/ServiceSet/AddReferencesResult.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AddNodesResult
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AddReferencesResult::AddReferencesResult(void)
	: statusCode_()
	{
	}

	AddReferencesResult::~AddReferencesResult(void)
	{
	}

	void
	AddReferencesResult::statusCode(OpcUaStatusCode statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaStatusCode
	AddReferencesResult::statusCode(void) const
	{
		return statusCode_;
	}


	void 
	AddReferencesResult::opcUaBinaryEncode(
		std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)statusCode_);
	}
	
	void 
	AddReferencesResult::opcUaBinaryDecode(
		std::istream& is)
	{
		OpcUaUInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
	}

}
