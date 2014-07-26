#ifndef __OpcUaStackCore_SecurityHeader_h__
#define __OpcUaStackCore_SecurityHeader_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecurityHeader : public  ObjectPool<SecurityHeader>
	{
	  public:
		SecurityHeader(void);
		virtual ~SecurityHeader(void);

		void securityPolicyUri(OpcUaByte *buf, OpcUaInt32 bufLen);
		void securityPolicyUri(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void senderCertificate(OpcUaByte *buf, OpcUaInt32 bufLen);
		void senderCertificate(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void receiverCertificateThumbprint(OpcUaByte *buf, OpcUaInt32 bufLen);
		void receiverCertificateThumbprint(OpcUaByte **buf, OpcUaInt32* bufLen) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaByteString securityPolicyUri_;
		OpcUaByteString senderCertificate_;
		OpcUaByteString receiverCertificateThumbprint_;
	};

}

#endif