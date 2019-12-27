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

#include "OpcUaStackCore/ServiceSet/ActivateSessionRequest.h"

namespace OpcUaStackCore
{

	ActivateSessionRequest::ActivateSessionRequest(void)
	: requestHeaderSPtr_(boost::make_shared<RequestHeader>())
	, clientSignature_(boost::make_shared<SignatureData>())
	, signedSoftwareCertificate_(boost::make_shared<SignedSoftwareCertificateArray>())
	, localeIds_(boost::make_shared<OpcUaLocaleIdArray>())
	, userIdentityToken_(boost::make_shared<OpcUaExtensibleParameter>())
	, userTokenSignature_(boost::make_shared<SignatureData>())
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
	ActivateSessionRequest::localeIds(const OpcUaLocaleIdArray::SPtr localeIds)
	{
		localeIds_ = localeIds;
	}

	OpcUaLocaleIdArray::SPtr
	ActivateSessionRequest::localeIds(void) const
	{
		return localeIds_;
	}

	void 
	ActivateSessionRequest::userIdentityToken(const OpcUaExtensibleParameter::SPtr userIdentityToken)
	{
		userIdentityToken_ = userIdentityToken;
	}

	OpcUaExtensibleParameter::SPtr
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

	bool
	ActivateSessionRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= clientSignature_->opcUaBinaryEncode(os);
		rc &= signedSoftwareCertificate_->opcUaBinaryEncode(os);
		rc &= localeIds_->opcUaBinaryEncode(os);
		rc &= userIdentityToken_->opcUaBinaryEncode(os);
		rc &= userTokenSignature_->opcUaBinaryEncode(os);

		return rc;
	}

	bool
	ActivateSessionRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= clientSignature_->opcUaBinaryDecode(is);
		rc &= signedSoftwareCertificate_->opcUaBinaryDecode(is);
		rc &= localeIds_->opcUaBinaryDecode(is);
		rc &= userIdentityToken_->opcUaBinaryDecode(is);
		rc &= userTokenSignature_->opcUaBinaryDecode(is);

		return rc;
	}

}
