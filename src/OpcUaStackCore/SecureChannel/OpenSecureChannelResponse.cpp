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

#include "OpcUaStackCore/SecureChannel/OpenSecureChannelResponse.h"

namespace OpcUaStackCore
{

	OpenSecureChannelResponse::OpenSecureChannelResponse(void)
	: Object()
	, responseHeaderSPtr_(boost::make_shared<ResponseHeader>())
	, serverProtocolVersion_(0)
	, securityTokenSPtr_(boost::make_shared<SecurityToken>())
	, serverNonce_()
	{
	}
		
	OpenSecureChannelResponse::~OpenSecureChannelResponse(void)
	{
	}

	void 
	OpenSecureChannelResponse::responseHeader(const ResponseHeader::SPtr responseHeaderSPtr)
	{
		responseHeaderSPtr_ = responseHeaderSPtr;
	}

	ResponseHeader::SPtr  
	OpenSecureChannelResponse::responseHeader(void) const
	{
		return responseHeaderSPtr_;
	}

	void 
	OpenSecureChannelResponse::serverProtocolVersion(const OpcUaInt32& serverProtocolVersion)
	{
		serverProtocolVersion_ = serverProtocolVersion;
	}
		
	OpcUaInt32 
	OpenSecureChannelResponse::serverProtocolVersion(void) const
	{
		return serverProtocolVersion_;
	}

	void  
	OpenSecureChannelResponse::securityToken(const SecurityToken::SPtr securityToken)
	{
		securityTokenSPtr_ = securityToken;
	}

	SecurityToken::SPtr  
	OpenSecureChannelResponse::securityToken(void)
	{
		return securityTokenSPtr_;
	}

	void 
	OpenSecureChannelResponse::serverNonce(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		serverNonce_.value(buf, bufLen);
	}

	void 
	OpenSecureChannelResponse::serverNonce(OpcUaByte** buf, OpcUaInt32 *bufLen) const
	{
		serverNonce_.value(buf, bufLen);
	}

	void
	OpenSecureChannelResponse::serverNonce(OpcUaByteString& serverNonce)
	{
		serverNonce_ = serverNonce;
	}

	bool
	OpenSecureChannelResponse::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= responseHeaderSPtr_->opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, serverProtocolVersion_);
		rc &= securityTokenSPtr_->opcUaBinaryEncode(os);
		rc &= serverNonce_.opcUaBinaryEncode(os);

		return rc;
	}

	bool
	OpenSecureChannelResponse::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= responseHeaderSPtr_->opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, serverProtocolVersion_);
		rc &= securityTokenSPtr_->opcUaBinaryDecode(is);
		rc &= serverNonce_.opcUaBinaryDecode(is);

		return rc;
	}

}
