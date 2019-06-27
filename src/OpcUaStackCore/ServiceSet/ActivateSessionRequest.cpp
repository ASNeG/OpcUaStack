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

#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"

namespace OpcUaStackCore
{

	ActivateSessionRequest::ActivateSessionRequest(void)
	: requestHeaderSPtr_(constructSPtr<RequestHeader>())
	, clientSignature_(constructSPtr<SignatureData>())
	, signedSoftwareCertificate_(constructSPtr<SignedSoftwareCertificateArray>())
	, localeIds_(constructSPtr<LocaleIdArray>())
	, userIdentityToken_(constructSPtr<ExtensibleParameter>())
	, userTokenSignature_(constructSPtr<SignatureData>())
	{
	}

	ActivateSessionRequest::~ActivateSessionRequest(void)
	{
	}

	void 
	ActivateSessionRequest::requestHeader(const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeaderSPtr_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr 
	ActivateSessionRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	ActivateSessionRequest::clientSignature(const SignatureData::SPtr clientSignature)
	{
		clientSignature_ = clientSignature;
	}

	SignatureData::SPtr 
	ActivateSessionRequest::clientSignature(void) const
	{
		return clientSignature_;
	}

	void 
	ActivateSessionRequest::signedSoftwareCertificate(const SignedSoftwareCertificateArray::SPtr signedSoftwareCertificate)
	{
		signedSoftwareCertificate_ = signedSoftwareCertificate;
	}

	SignedSoftwareCertificateArray::SPtr 
	ActivateSessionRequest::signedSoftwareCertificate(void) const
	{
		return signedSoftwareCertificate_;
	}

	void 
	ActivateSessionRequest::localeIds(const LocaleIdArray::SPtr localeIds)
	{
		localeIds_ = localeIds;
	}

	LocaleIdArray::SPtr 
	ActivateSessionRequest::localeIds(void) const
	{
		return localeIds_;
	}

	void 
	ActivateSessionRequest::userIdentityToken(const ExtensibleParameter::SPtr userIdentityToken)
	{
		userIdentityToken_ = userIdentityToken;
	}

	ExtensibleParameter::SPtr 
	ActivateSessionRequest::userIdentityToken(void) const
	{
		return userIdentityToken_;
	}

	void 
	ActivateSessionRequest::userTokenSignature(SignatureData::SPtr userTokenSignature)
	{
		userTokenSignature_ = userTokenSignature;
	}

	SignatureData::SPtr 
	ActivateSessionRequest::userTokenSignature(void) const
	{
		return userTokenSignature_;
	}

	void 
	ActivateSessionRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		//requestHeaderSPtr_->opcUaBinaryEncode(os);
		clientSignature_->opcUaBinaryEncode(os);
		signedSoftwareCertificate_->opcUaBinaryEncode(os);
		localeIds_->opcUaBinaryEncode(os);
		userIdentityToken_->opcUaBinaryEncode(os);
		userTokenSignature_->opcUaBinaryEncode(os);
	}

	void 
	ActivateSessionRequest::opcUaBinaryDecode(std::istream& is)
	{
		//requestHeaderSPtr_->opcUaBinaryDecode(is);
		clientSignature_->opcUaBinaryDecode(is);
		signedSoftwareCertificate_->opcUaBinaryDecode(is);
		localeIds_->opcUaBinaryDecode(is);
		userIdentityToken_->opcUaBinaryDecode(is);
		userTokenSignature_->opcUaBinaryDecode(is);
	}

}
