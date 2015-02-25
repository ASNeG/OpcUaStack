#ifndef __OpcUaStackCore_CreateSessionResponse_h__
#define __OpcUaStackCore_CreateSessionResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
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
		typedef boost::shared_ptr<CreateSessionResponse> SPtr;

		CreateSessionResponse(void);
		virtual ~CreateSessionResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void) const;
		OpcUaNodeId& sessionId(void);
		OpcUaNodeId& authenticationToken(void);
		void receivedSessionTimeout(const Duration receivedSessionTimeout);
		Duration receivedSessionTimeout(void) const;
		void serverNonce(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void serverNonce(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void serverCertificate(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void serverCertificate(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void serverEndpoints(const EndpointDescriptionArray::SPtr serverEndpoints);
		EndpointDescriptionArray::SPtr serverEndpoints(void) const;
		void serverSoftwareCertificate(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void serverSoftwareCertificate(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void signatureData(const SignatureData::SPtr signatureData);
		SignatureData::SPtr signatureData(void) const;
		void maxRequestMessageSize(const OpcUaUInt32 maxRequestMessageSize);
		OpcUaUInt32 maxRequestMessageSize(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeader_;
		OpcUaNodeId sessionId_;
		OpcUaNodeId authenticationToken_;
		Duration receivedSessionTimeout_;
		OpcUaByteString serverNonce_;
		OpcUaByteString serverCertificate_;
		EndpointDescriptionArray::SPtr serverEndpoints_;
		OpcUaByteString serverSoftwareCertificate_;
		SignatureData::SPtr signatureData_;
		OpcUaUInt32 maxRequestMessageSize_;
		
	};

}

#endif
