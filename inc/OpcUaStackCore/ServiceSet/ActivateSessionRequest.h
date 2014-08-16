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

	class DLLEXPORT ActivateSessionRequest : public  ObjectPool<ActivateSessionRequest>
	{
	  public:
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
