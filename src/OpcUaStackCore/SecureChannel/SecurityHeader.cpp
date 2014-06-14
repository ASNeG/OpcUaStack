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

	OpcUaByteString& 
	SecurityHeader::securityPolicyUri(void)
	{
		return securityPolicyUri_;
	}
	
	OpcUaByteString& 
	SecurityHeader::senderCertificate(void)
	{
		return senderCertificate_;
	}
		
	OpcUaByteString& 
	SecurityHeader::receiverCertificateThumbprint(void)
	{
		return receiverCertificateThumbprint_;
	}

	void 
	SecurityHeader::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaStackCore::opcUaBinaryEncode(os, securityPolicyUri_);
		OpcUaStackCore::opcUaBinaryEncode(os, senderCertificate_);
		OpcUaStackCore::opcUaBinaryEncode(os, receiverCertificateThumbprint_);
	}

	void 
	SecurityHeader::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaStackCore::opcUaBinaryDecode(is, securityPolicyUri_);
		OpcUaStackCore::opcUaBinaryDecode(is, senderCertificate_);
		OpcUaStackCore::opcUaBinaryDecode(is, receiverCertificateThumbprint_);
	}

}	