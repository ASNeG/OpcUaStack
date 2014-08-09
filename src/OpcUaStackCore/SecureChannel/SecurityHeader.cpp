#include "OpcUaStackCore/SecureChannel/SecurityHeader.h"
#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"

namespace OpcUaStackCore
{

	SecurityHeader::SecurityHeader(void)
	: securityPolicyUri_()
	, senderCertificate_()
	, receiverCertificateThumbprint_()
	{
	}
		
	SecurityHeader::~SecurityHeader(void)
	{
	}

	void 
	SecurityHeader::securityPolicyUri(OpcUaByte *buf, OpcUaInt32 bufLen)
	{
		securityPolicyUri_.value(buf, bufLen);
	}

	void 
	SecurityHeader::securityPolicyUri(OpcUaByte **buf, OpcUaInt32* bufLen) const
	{
		securityPolicyUri_.value(buf, bufLen);
	}

	void 
	SecurityHeader::senderCertificate(OpcUaByte *buf, OpcUaInt32 bufLen)
	{
		senderCertificate_.value(buf, bufLen);
	}

	void 
	SecurityHeader::senderCertificate(OpcUaByte **buf, OpcUaInt32* bufLen) const
	{
		senderCertificate_.value(buf, bufLen);
	}

	void 
	SecurityHeader::receiverCertificateThumbprint(OpcUaByte *buf, OpcUaInt32 bufLen)
	{
		receiverCertificateThumbprint_.value(buf, bufLen);
	}

	void 
	SecurityHeader::receiverCertificateThumbprint(OpcUaByte **buf, OpcUaInt32* bufLen) const
	{
		receiverCertificateThumbprint_.value(buf, bufLen);
	}

	void 
	SecurityHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		securityPolicyUri_.opcUaBinaryEncode(os);
		senderCertificate_.opcUaBinaryEncode(os);
		receiverCertificateThumbprint_.opcUaBinaryEncode(os);
	}

	void 
	SecurityHeader::opcUaBinaryDecode(std::istream& is)
	{
		securityPolicyUri_.opcUaBinaryDecode(is);
		senderCertificate_.opcUaBinaryDecode(is);
		receiverCertificateThumbprint_.opcUaBinaryDecode(is);
	}

}	