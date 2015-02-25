#ifndef __OpcUaStackCore_UserTokenPolicy_h__
#define __OpcUaStackCore_UserTokenPolicy_h__

#include <stdint.h>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"

namespace OpcUaStackCore
{

	typedef enum {
		UserIdentityTokenType_Anonymous = 0,
		UserIdentityTokenType_Username = 1,
		UserIdentityTokenType_Certificate = 2,
		UserIdentityTokenType_IssuedToken = 3
	} UserIdentityTokenType;

	class DLLEXPORT UserTokenPolicy : public  ObjectPool<UserTokenPolicy>
	{
	  public:
		typedef boost::shared_ptr<UserTokenPolicy> SPtr;

		UserTokenPolicy(void);
		virtual ~UserTokenPolicy(void);

		void policyId(const std::string& policyId);
		std::string policyId(void) const;
		void tokenType(const UserIdentityTokenType tokenType);
		UserIdentityTokenType tokenType(void) const;
		void issuedTokenType(const std::string& issuedTokenType);
		std::string issuedTokenType(void) const;
		void issuerEndpointUrl(const std::string& issuerEndpointUrl);
		std::string issuerEndpointUrl(void) const;
		void securityPolicyUri(const std::string& securityPolicyUri);
		std::string securityPolicyUri(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaString policyId_;
		UserIdentityTokenType tokenType_;
		OpcUaString issuedTokenType_;
		OpcUaString issuerEndpointUrl_;
		OpcUaString securityPolicyUri_;
	};

	class UserTokenPolicyArray : public OpcUaArray<UserTokenPolicy::SPtr, SPtrTypeCoder<UserTokenPolicy> >, public ObjectPool<UserTokenPolicyArray> 
	{
	  public:
		  typedef boost::shared_ptr<UserTokenPolicyArray> SPtr;
	};

}

#endif
