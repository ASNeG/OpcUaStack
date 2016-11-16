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

#ifndef __OpcUaStackCore_ActivateSessionRequest_h__
#define __OpcUaStackCore_ActivateSessionRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/ServiceSet/SignatureData.h"
#include "OpcUaStackCore/ServiceSet/SignedSoftwareCertificate.h"
#include "OpcUaStackCore/ServiceSet/UserIdentityToken.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ActivateSessionRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<ActivateSessionRequest> SPtr;

		ActivateSessionRequest(void);
		virtual ~ActivateSessionRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void clientSignature(const SignatureData::SPtr clientSignature);
		SignatureData::SPtr clientSignature(void) const;
		void signedSoftwareCertificate(const SignedSoftwareCertificateArray::SPtr signedSoftwareCertificate);
		SignedSoftwareCertificateArray::SPtr signedSoftwareCertificate(void) const;
		void localeIds(const LocaleIdArray::SPtr localeIds);
		LocaleIdArray::SPtr localeIds(void) const;
		void userIdentityToken(const ExtensibleParameter::SPtr userIdentityToken);
		ExtensibleParameter::SPtr userIdentityToken(void) const;
		void userTokenSignature(SignatureData::SPtr userTokenSignature);
		SignatureData::SPtr userTokenSignature(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		SignatureData::SPtr clientSignature_;
		SignedSoftwareCertificateArray::SPtr signedSoftwareCertificate_;
		LocaleIdArray::SPtr localeIds_;
		ExtensibleParameter::SPtr userIdentityToken_;
		SignatureData::SPtr userTokenSignature_;
	};

}

#endif
