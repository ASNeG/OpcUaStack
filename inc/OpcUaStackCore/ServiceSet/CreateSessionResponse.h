#ifndef __OpcUaStackCore_CreateSessionResponse_h__
#define __OpcUaStackCore_CreateSessionResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OPcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/SecureChannel/ApplicationInstanceCertificate.h"
#include "OpcUaStackCore/SecureChannel/SessionAuthenticationToken.h"
#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"
#include "OpcUaStackCore/ServiceSet/SignatureData.h"
#include "OpcUaStackCore/ServiceSet/SignedSoftwareCertificate.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CreateSessionResponse : public  ObjectPool<CreateSessionResponse>
	{
	  public:
		CreateSessionResponse(void);
		virtual ~CreateSessionResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void) const;
		void sessionId(const OpcUaNodeId::SPtr sessionId);
		OpcUaNodeId::SPtr sessionId(void) const;
		void authenticationToken(const SessionAuthenticationToken::SPtr authenticationToken);
		SessionAuthenticationToken::SPtr authenticationToken(void) const;
		void receivedSessionTimeout(const Duration receivedSessionTimeout);
		Duration receivedSessionTimeout(void) const;
		void serverNonce(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void serverNonce(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void serverCertificate(const ApplicationInstanceCertificate::SPtr serverCertificate);
		ApplicationInstanceCertificate::SPtr serverCertificate(void) const;
		void serverEndpoints(const EndpointDescriptionArray::SPtr serverEndpoints);
		EndpointDescriptionArray::SPtr serverEndpoints(void) const;
		void serverSoftwareCertificate(const SignedSoftwareCertificateArray::SPtr serverSoftwareCertificate);
		SignedSoftwareCertificateArray::SPtr serverSoftwareCertificate(void) const;
		void signatureData(const SignatureData::SPtr signatureData);
		SignatureData::SPtr signatureData(void) const;
		void maxRequestMessageSize(const OpcUaUInt32 maxRequestMessageSize);
		OpcUaUInt32 maxRequestMessageSize(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeader_;
		OpcUaNodeId::SPtr sessionId_;
		SessionAuthenticationToken::SPtr authenticationToken_;
		Duration receivedSessionTimeout_;
		OpcUaByteString serverNonce_;
		ApplicationInstanceCertificate::SPtr serverCertificate_;
		EndpointDescriptionArray::SPtr serverEndpoints_;
		SignedSoftwareCertificateArray::SPtr serverSoftwareCertificate_;
		SignatureData::SPtr signatureData_;
		OpcUaUInt32 maxRequestMessageSize_;
		
	};

}

#endif