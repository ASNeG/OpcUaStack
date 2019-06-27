/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_EndpointDescription_h__
#define __OpcUaStackCore_EndpointDescription_h__

#include <stdint.h>
#include <map>
#include <vector>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaBaseEnums.h"
#include "OpcUaStackCore/SecureChannel/ApplicationInstanceCertificate.h"
#include "OpcUaStackCore/ServiceSet/ApplicationDescription.h"
#include "OpcUaStackCore/ServiceSet/UserTokenPolicy.h"

namespace OpcUaStackCore
{

	class DLLEXPORT EndpointDescription
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<EndpointDescription> SPtr;
		typedef std::multimap<std::string, EndpointDescription::SPtr> Multimap;
		typedef std::vector<EndpointDescription::SPtr> Vec;

		EndpointDescription(void);
		EndpointDescription(const EndpointDescription& endpointDescription);
		virtual ~EndpointDescription(void);

		void endpointUrl(const std::string& endpointUrl);
		std::string endpointUrl(void) const;
		void applicationDescription(const ApplicationDescription::SPtr applicationDescription);
		ApplicationDescription::SPtr applicationDescription(void) const;
		void serverCertificate(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void serverCertificate(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void messageSecurityMode(const SecurityMode securityMode);
		SecurityMode messageSecurityMode(void) const;
		void securityPolicyUri(const std::string& securityPolicyUri);
		std::string securityPolicyUri(void) const;
		void securityPolicy(const SecurityPolicy securityPolicy);
		SecurityPolicy securityPolicy(void) const;
		void userIdentityTokens(const UserTokenPolicyArray::SPtr userIdentityTokens);
		UserTokenPolicyArray::SPtr userIdentityTokens(void) const;
		void transportProfileUri(const std::string& transportProfileUri);
		std::string transportProfileUri(void) const;
		void securityLevel(const OpcUaByte securityLevel);
		OpcUaByte securityLevel(void) const;

		bool needSecurity(void);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);
		void out(std::ostream& os);

	  private:
		OpcUaString endpointUrl_;
		ApplicationDescription::SPtr applicationDescription_;
		OpcUaByteString serverCertificate_;
		SecurityMode messageSecurityMode_;
		OpcUaString securityPolicyUri_;
		UserTokenPolicyArray::SPtr userIdentityTokens_;
		OpcUaString transportProfileUri_;
		OpcUaByte securityLevel_;
	};


	class EndpointDescriptionArray
	: public OpcUaArray<EndpointDescription::SPtr, SPtrTypeCoder<EndpointDescription> >
	, public Object
	{
	  public:
		typedef boost::shared_ptr<EndpointDescriptionArray> SPtr;
	};


	class DLLEXPORT EndpointDescriptionSet
	{
	  public:
		typedef boost::shared_ptr<EndpointDescriptionSet> SPtr;

		EndpointDescriptionSet(void);
		~EndpointDescriptionSet(void);

		void addEndpoint(const std::string& endpointUrl, EndpointDescription::SPtr& endpointDescription);
		void getEndpoints(const std::string& endpointUrl, EndpointDescriptionArray::SPtr& endpointDescriptionArray);
		void getEndpoints(EndpointDescriptionArray::SPtr& endpointDescriptionArray);
		void getEndpointUrls(std::vector<std::string>& endpointUrls);

	  private:
		EndpointDescription::Multimap endpointDescriptionMap_;
	};

}

#endif
