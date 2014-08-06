#ifndef __OpcUaStackCore_EndpointDescription_h__
#define __OpcUaStackCore_EndpointDescription_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ApplicationInstanceCertificate.h"
#include "OpcUaStackCore/ServiceSet/ApplicationDescription.h"
#include "OpcUaStackCore/ServiceSet/UserTokenPolicy.h"

namespace OpcUaStackCore
{

	typedef enum {
		MessageSecurityMode_None = 0
	} MessageSecurityMode;

	class DLLEXPORT EndpointDescription : public  ObjectPool<EndpointDescription>
	{
	  public:
		EndpointDescription(void);
		virtual ~EndpointDescription(void);

		void endpointUrl(const std::string& endpointUrl);
		std::string endpointUrl(void) const;
		void applicationDescription(const ApplicationDescription::SPtr applicationDescription);
		ApplicationDescription::SPtr applicationDescription(void) const;
		void serverCertificate(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void serverCertificate(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void messageSecurityMode(const MessageSecurityMode messageSecurityMode);
		MessageSecurityMode messageSecurityMode(void) const;
		void securityPolicyUri(const std::string& securityPolicyUri);
		std::string securityPolicyUri(void) const;



		void userIdentityTokens(const UserTokenPolicyArray::SPtr userIdentityTokens);
		UserTokenPolicyArray::SPtr userIdentityTokens(void) const;
		void transportProfileUri(const std::string& transportProfileUri);
		std::string transportProfileUri(void) const;
		void securityLevel(const OpcUaByte securityLevel);
		OpcUaByte securityLevel(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaString endpointUrl_;
		ApplicationDescription::SPtr applicationDescription_;
		OpcUaByteString serverCertificate_;

		MessageSecurityMode messageSecurityMode_;
		OpcUaString securityPolicyUri_;
		UserTokenPolicyArray::SPtr userIdentityTokens_;
		OpcUaString transportProfileUri_;
		OpcUaByte securityLevel_;
	};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const EndpointDescription& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, EndpointDescription& value);



	class EndpointDescriptionArray : public OpcUaArray<EndpointDescription::SPtr>, public ObjectPool<EndpointDescriptionArray> {};

	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const EndpointDescriptionArray& value);
	DLLEXPORT void opcUaBinaryEncode(std::ostream& os, const EndpointDescriptionArray::SPtr& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, EndpointDescriptionArray& value);
	DLLEXPORT void opcUaBinaryDecode(std::istream& is, EndpointDescriptionArray::SPtr& value);

}

#endif
