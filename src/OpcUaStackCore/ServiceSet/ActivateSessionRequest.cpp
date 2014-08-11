#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"

namespace OpcUaStackCore
{

	ActivateSessionRequest::ActivateSessionRequest(void)
	: requestHeaderSPtr_(RequestHeader::construct())
	, clientSignature_(SignatureData::construct())
	, signedSoftwareCertificate_(SignedSoftwareCertificateArray::construct())
	, localeIds_(LocaleIdArray::construct())
	, userIdentityToken_()
	, userTokenSignature_(SignatureData::construct())
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
	ActivateSessionRequest::userIdentityToken(const UserIdentityToken::SPtr userIdentityToken)
	{
		userIdentityToken_ = userIdentityToken;
	}

	UserIdentityToken::SPtr 
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
		requestHeaderSPtr_->opcUaBinaryEncode(os);
		clientSignature_->opcUaBinaryEncode(os);
		signedSoftwareCertificate_->opcUaBinaryEncode(os);
		localeIds_->opcUaBinaryEncode(os);
		userIdentityToken_->opcUaBinaryEncode(os);
		userTokenSignature_->opcUaBinaryEncode(os);
	}

	void 
	ActivateSessionRequest::opcUaBinaryDecode(std::istream& is)
	{
		requestHeaderSPtr_->opcUaBinaryDecode(is);
		clientSignature_->opcUaBinaryDecode(is);
		signedSoftwareCertificate_->opcUaBinaryDecode(is);
		localeIds_->opcUaBinaryDecode(is);
		userIdentityToken_->opcUaBinaryDecode(is);
		userTokenSignature_->opcUaBinaryDecode(is);
	}

}