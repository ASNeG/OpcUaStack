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

#include "OpcUaStackCore/ServiceSet/ActivateSessionResponse.h"

namespace OpcUaStackCore
{

	ActivateSessionResponse::ActivateSessionResponse(void)
	: Object()
	, responseHeader_(boost::make_shared<ResponseHeader>())
	, serverNonce_()
	, results_(boost::make_shared<OpcUaStatusCodeArray>())
	, diagnosticInfos_(boost::make_shared<OpcUaDiagnosticInfoArray>())
	{
	}

	ActivateSessionResponse::~ActivateSessionResponse(void)
	{
	}

	void 
	ActivateSessionResponse::responseHeader(const ResponseHeader::SPtr requestHeader)
	{
		responseHeader_ = requestHeader;
	}

	ResponseHeader::SPtr 
	ActivateSessionResponse::responseHeader(void) const
	{
		return responseHeader_;
	}

	void 
	ActivateSessionResponse::serverNonce(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		serverNonce_.value(buf, bufLen);
	}

	void 
	ActivateSessionResponse::serverNonce(OpcUaByte** buf, OpcUaInt32* bufLen)
	{
		serverNonce_.value(buf, bufLen);
	}

	void 
	ActivateSessionResponse::results(const OpcUaStatusCodeArray::SPtr results)
	{
		results_ = results;
	}

	OpcUaStatusCodeArray::SPtr 
	ActivateSessionResponse::results(void) const
	{
		return results_;
	}

	void 
	ActivateSessionResponse::diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos)
	{
		diagnosticInfos_ = diagnosticInfos;
	}

	OpcUaDiagnosticInfoArray::SPtr 
	ActivateSessionResponse::diagnosticInfos(void) const
	{
		return diagnosticInfos_;
	}

	void 
	ActivateSessionResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		//responseHeader_->opcUaBinaryEncode(os);
		serverNonce_.opcUaBinaryEncode(os);
		results_->opcUaBinaryEncode(os);
		diagnosticInfos_->opcUaBinaryEncode(os);
	}

	void 
	ActivateSessionResponse::opcUaBinaryDecode(std::istream& is)
	{
		//responseHeader_->opcUaBinaryDecode(is);
		serverNonce_.opcUaBinaryDecode(is);
		results_->opcUaBinaryDecode(is);
		diagnosticInfos_->opcUaBinaryDecode(is);
	}

}
