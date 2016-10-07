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

#include "OpcUaStackCore/ServiceSet/StatusChangeNotification.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUa DataChangeNotification
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------

	StatusChangeNotification::StatusChangeNotification(void)
	: Object()
	, ExtensibleParameterBase()
	, statusCode_()
	, diagnosticInfo_()
	{
	}

	StatusChangeNotification::~StatusChangeNotification(void)
	{
	}

	void 
	StatusChangeNotification::statusCode(const OpcUaStatusCode& statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaStatusCode& 
	StatusChangeNotification::statusCode(void)
	{
		return statusCode_;
	}
	
	void 
	StatusChangeNotification::diagnosticInfo(const OpcUaDiagnosticInfo& diagnosticInfo)
	{
		diagnosticInfo_ = diagnosticInfo;
	}
	
	OpcUaDiagnosticInfo& 
	StatusChangeNotification::diagnosticInfo(void)
	{
		return diagnosticInfo_;
	}

	ExtensibleParameterBase::SPtr
	StatusChangeNotification::factory(void)
	{
		return constructSPtr<StatusChangeNotification>();
	}

	void 
	StatusChangeNotification::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		diagnosticInfo_.opcUaBinaryEncode(os);
	}
	
	void 
	StatusChangeNotification::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaInt32 tmp;
		OpcUaNumber::opcUaBinaryDecode(is, tmp);
		statusCode_ = (OpcUaStatusCode)tmp;
		diagnosticInfo_.opcUaBinaryDecode(is);
	}
}
