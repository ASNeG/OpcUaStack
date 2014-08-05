#ifndef __OpcUaStackCore_CreateSessionRequest_h__
#define __OpcUaStackCore_CreateSessionRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ApplicationInstanceCertificate.h"
#include "OpcUaStackCore/ServiceSet/ApplicationDescription.h"


namespace OpcUaStackCore
{

	class DLLEXPORT CreateSessionRequest : public  ObjectPool<CreateSessionRequest>
	{
	  public:
		CreateSessionRequest(void);
		virtual ~CreateSessionRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void clientDescription(const ApplicationDescription::SPtr clientDescriptionSPtr);
		ApplicationDescription::SPtr clientDescription(void) const;
		void serverUri(const std::string& serverUri);
		std::string serverUri(void) const;
		void endpointUrl(const std::string& endpointUrl);
		std::string endpointUrl(void) const;
		void sessionName(const std::string& sessionName);
		std::string sessionName(void) const;
		void clientNonce(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void clientNonce(const OpcUaByte *buf, OpcUaInt32 bufLen);
		void clientCertificate(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void clientCertificate(const OpcUaByte *buf, OpcUaInt32 bufLen);
		void requestSessionTimeout(const Duration requestSessionTimeout);
		Duration requestSessionTimeout(void) const;
		void maxResponseMessageSize(const OpcUaUInt32& maxResponseMessageSize);
		OpcUaUInt32 maxResponseMessageSize(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		ApplicationDescription::SPtr clientDescriptionSPtr_;
		OpcUaString serverUri_;
		OpcUaString endpointUrl_;
		OpcUaString sessionName_;
		OpcUaByteString clientNonce_;
		OpcUaByteString clientCertificate_;
		Duration requestSessionTimeout_;
		OpcUaUInt32 maxResponseMessageSize_;
	};

}

#endif
