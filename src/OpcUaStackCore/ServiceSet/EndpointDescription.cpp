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

#include "OpcUaStackCore/ServiceSet/EndpointDescription.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// EndpointDescription
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	EndpointDescription::EndpointDescription(void)
	: endpointUrl_()
	, applicationDescription_(constructSPtr<ApplicationDescription>())
	, serverCertificate_()
	, messageSecurityMode_()
	, securityPolicyUri_()
	, userIdentityTokens_(constructSPtr<UserTokenPolicyArray>())
	, transportProfileUri_()
	, securityLevel_()
	{
	}

	EndpointDescription::EndpointDescription(const EndpointDescription& endpointDescription)
	: endpointUrl_(endpointDescription.endpointUrl_)
	, applicationDescription_(endpointDescription.applicationDescription_)
	, serverCertificate_(endpointDescription.serverCertificate_)
	, messageSecurityMode_(endpointDescription.messageSecurityMode_)
	, securityPolicyUri_(endpointDescription.securityPolicyUri_)
	, userIdentityTokens_(endpointDescription.userIdentityTokens_)
	, transportProfileUri_(endpointDescription.transportProfileUri_)
	, securityLevel_(endpointDescription.securityLevel_)
	{
	}

	EndpointDescription::~EndpointDescription(void)
	{
	}

	void 
	EndpointDescription::endpointUrl(const std::string& endpointUrl)
	{
		endpointUrl_ = endpointUrl;
	}

	std::string 
	EndpointDescription::endpointUrl(void) const
	{
		return endpointUrl_.value();
	}

	void 
	EndpointDescription::applicationDescription(const ApplicationDescription::SPtr applicationDescription)
	{
		applicationDescription_ = applicationDescription;
	}

	ApplicationDescription::SPtr 
	EndpointDescription::applicationDescription(void) const
	{
		return applicationDescription_;
	}

	void 
	EndpointDescription::serverCertificate(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		serverCertificate_.value(buf, bufLen);
	}

	void 
	EndpointDescription::serverCertificate(OpcUaByte** buf, OpcUaInt32* bufLen) const
	{
		serverCertificate_.value(buf, bufLen);
	}

	void 
	EndpointDescription::messageSecurityMode(const SecurityMode messageSecurityMode)
	{
		messageSecurityMode_ = messageSecurityMode;
	}

	SecurityMode
	EndpointDescription::messageSecurityMode(void) const
	{
		return messageSecurityMode_;
	}

	void 
	EndpointDescription::securityPolicyUri(const std::string& securityPolicyUri)
	{
		securityPolicyUri_ = securityPolicyUri;
	}

	std::string 
	EndpointDescription::securityPolicyUri(void) const
	{
		return securityPolicyUri_.value();
	}

	void
	EndpointDescription::securityPolicy(const SecurityPolicy securityPolicy)
	{
		switch (securityPolicy)
		{
			case SP_None:
			{
				securityPolicyUri_.value("http://opcfoundation.org/UA/SecurityPolicy#None");
				break;
			}
			case SP_Basic128Rsa15:
			{
				securityPolicyUri_.value("http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15");
				break;
			}
			case SP_Basic256:
			{
				securityPolicyUri_.value("http://opcfoundation.org/UA/SecurityPolicy#Basic256");
				break;
			}
			case SP_Basic256Sha256:
			{
				securityPolicyUri_.value("http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256");
				break;
			}
			default:
			{
				securityPolicyUri_.value("http://opcfoundation.org/UA/SecurityPolicy#None");
				break;
			}
		}
	}

	SecurityPolicy
	EndpointDescription::securityPolicy(void) const
	{
		if (securityPolicyUri_.toStdString() == "http://opcfoundation.org/UA/SecurityPolicy#None") {
			return SP_None;
		}
		if (securityPolicyUri_.toStdString() == "http://opcfoundation.org/UA/SecurityPolicy#Basic128Rsa15") {
			return SP_Basic128Rsa15;
		}
		if (securityPolicyUri_.toStdString() == "http://opcfoundation.org/UA/SecurityPolicy#Basic256") {
			return SP_Basic256;
		}
		if (securityPolicyUri_.toStdString() == "http://opcfoundation.org/UA/SecurityPolicy#Basic256Sha256") {
			return SP_Basic256Sha256;
		}
		return SP_None;
	}

	void 
	EndpointDescription::userIdentityTokens(const UserTokenPolicyArray::SPtr userIdentityTokens)
	{
		userIdentityTokens_ = userIdentityTokens;
	}

	UserTokenPolicyArray::SPtr 
	EndpointDescription::userIdentityTokens(void) const
	{
		return userIdentityTokens_;
	}

	void 
	EndpointDescription::transportProfileUri(const std::string& transportProfileUri)
	{
		transportProfileUri_ = transportProfileUri;
	}

	std::string 
	EndpointDescription::transportProfileUri(void) const
	{
		return transportProfileUri_.value();
	}

	void 
	EndpointDescription::securityLevel(const OpcUaByte securityLevel)
	{
		securityLevel_ = securityLevel;
	}

	OpcUaByte 
	EndpointDescription::securityLevel(void) const
	{
		return securityLevel_;
	}

	bool
	EndpointDescription::needSecurity(void)
	{
		// FIXME: todo
		return true;
	}

	void 
	EndpointDescription::opcUaBinaryEncode(std::ostream& os) const
	{
		endpointUrl_.opcUaBinaryEncode(os);
		applicationDescription_->opcUaBinaryEncode(os);
		serverCertificate_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)messageSecurityMode_);
		securityPolicyUri_.opcUaBinaryEncode(os);
		userIdentityTokens_->opcUaBinaryEncode(os);
		transportProfileUri_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, securityLevel_);
	}
	
	void 
	EndpointDescription::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaUInt32 messageSecurityMode;
		endpointUrl_.opcUaBinaryDecode(is);
		applicationDescription_->opcUaBinaryDecode(is);
		serverCertificate_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, messageSecurityMode);
		securityPolicyUri_.opcUaBinaryDecode(is);
		userIdentityTokens_->opcUaBinaryDecode(is);
		transportProfileUri_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, securityLevel_);
		messageSecurityMode_ = (SecurityMode)messageSecurityMode;
	}

	void
	EndpointDescription::out(std::ostream& os)
	{
		os << "EndpointUrl="; endpointUrl_.out(os);
		os << ", ApplicationDescription={";  applicationDescription_->out(os); os << "}";
		os << ", ServerCertificate="; serverCertificate_.out(os);
		os << ", MessageSecurityMode=" << (uint32_t)messageSecurityMode_;
		os << ", SecurityPolicy="; securityPolicyUri_.out(os);
		//os << ", UserIdentityTokens=[" << *userIdentityTokens_ << "]";
		os << ", TransportProfileUri="; transportProfileUri_.out(os);
		os << ", SecurityLevel=" << (uint32_t)securityLevel_;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// EndpointDescriptionSet
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	EndpointDescriptionSet::EndpointDescriptionSet(void)
	: endpointDescriptionMap_()
	{
	}

	EndpointDescriptionSet::~EndpointDescriptionSet(void)
	{
	}

	void
	EndpointDescriptionSet::addEndpoint(const std::string& endpointUrl, EndpointDescription::SPtr& endpointDescription)
	{
		endpointDescriptionMap_.insert(std::make_pair(endpointUrl, endpointDescription));
	}

	void
	EndpointDescriptionSet::getEndpoints(const std::string& endpointUrl, EndpointDescriptionArray::SPtr& endpointDescriptionArray)
	{
		EndpointDescription::Multimap::iterator it;
		std::pair<EndpointDescription::Multimap::iterator, EndpointDescription::Multimap::iterator> ret;

		ret = endpointDescriptionMap_.equal_range(endpointUrl);

		uint32_t count = endpointDescriptionMap_.count(endpointUrl);
		if (count == 0) return;

		endpointDescriptionArray->resize(count);
		for (it = ret.first; it != ret.second; it++) {
			endpointDescriptionArray->push_back(it->second);
		}
	}

	void
	EndpointDescriptionSet::getEndpoints(EndpointDescriptionArray::SPtr& endpointDescriptionArray)
	{
		EndpointDescription::Multimap::iterator it;

		endpointDescriptionArray->resize(endpointDescriptionMap_.size());

		for (it = endpointDescriptionMap_.begin(); it != endpointDescriptionMap_.end(); it++) {
			endpointDescriptionArray->push_back(it->second);
		}
	}

	void
	EndpointDescriptionSet::getEndpointUrls(std::vector<std::string>& endpointUrls)
	{
		EndpointDescription::Multimap::iterator it;
		std::set<std::string> endpointSet;

		for (it = endpointDescriptionMap_.begin(); it != endpointDescriptionMap_.end(); it++) {
			if (endpointSet.insert(it->first).second) {
				endpointUrls.push_back(it->first);
			}
		}
	}

}
