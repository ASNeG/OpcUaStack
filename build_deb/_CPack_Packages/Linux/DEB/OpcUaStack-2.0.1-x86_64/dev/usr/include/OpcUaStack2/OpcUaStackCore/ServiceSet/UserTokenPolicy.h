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

	class DLLEXPORT UserTokenPolicy
	: public  Object
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

	class UserTokenPolicyArray
	: public OpcUaArray<UserTokenPolicy::SPtr, SPtrTypeCoder<UserTokenPolicy> >
	, public Object
	{
	  public:
		  typedef boost::shared_ptr<UserTokenPolicyArray> SPtr;
	};

}

#endif
