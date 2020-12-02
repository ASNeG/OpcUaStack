/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

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

#include "boost/date_time/posix_time/posix_time.hpp"

#include "OpcUaStackCore/SecureChannel/SecureChannelKeys.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelKey
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelKey::SecureChannelKey(void)
	{
	}

	SecureChannelKey::~SecureChannelKey(void)
	{
	}

	void
	SecureChannelKey::ownSecurityKeySet(const SecurityKeySet& ownSecurityKeySet)
	{
		ownSecurityKeySet_ = ownSecurityKeySet;
	}

	SecurityKeySet&
	SecureChannelKey::ownSecurityKeySet(void)
	{
		return ownSecurityKeySet_;
	}

	void
	SecureChannelKey::partnerSecurityKeySet(const SecurityKeySet& partnerSecurityKeySet)
	{
		partnerSecurityKeySet_ = partnerSecurityKeySet;
	}

	SecurityKeySet&
	SecureChannelKey::partnerSecurityKeySet(void)
	{
		return partnerSecurityKeySet_;
	}

	void
	SecureChannelKey::securityToken(uint32_t securityToken)
	{
		securityToken_ = securityToken;
	}

	uint32_t
	SecureChannelKey::securityToken(void)
	{
		return securityToken_;
	}

	void
	SecureChannelKey::createTime(const boost::posix_time::ptime& createTime)
	{
		createTime_ = createTime;
	}

	boost::posix_time::ptime
	SecureChannelKey::createTime(void)
	{
		return createTime_;
	}

	void
	SecureChannelKey::expireTime(const boost::posix_time::ptime& expireTime)
	{
		expireTime_ = expireTime;
	}

	boost::posix_time::ptime
	SecureChannelKey::expireTime(void)
	{
		return expireTime_;
	}

	bool
	SecureChannelKey::isExpiredSecurechannelKey(void)
	{
		return boost::posix_time::microsec_clock::universal_time() > expireTime_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelKeys
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelKeys::SecureChannelKeys(void)
	{
	}

	SecureChannelKeys::~SecureChannelKeys(void)
	{
	}

	uint32_t
	SecureChannelKeys::actSecurityToken(void)
	{
		return actSecurityToken_;
	}

	SecureChannelKey::SPtr
	SecureChannelKeys::createSecureChannelKey(uint32_t liveTime, uint32_t securityToken)
	{
		// create new secure channel key
		auto secureChannelKey = std::make_shared<SecureChannelKey>();
		secureChannelKey->createTime(boost::posix_time::microsec_clock::universal_time());
		secureChannelKey->expireTime(secureChannelKey->createTime() + boost::posix_time::millisec(liveTime));

		// create unique security token
		if (securityToken != 0) {
			// we use an existing security token
			secureChannelKey->securityToken(securityToken);
		}
		else {
			// we must generate a new global unique security token
			while (1) {
				secureChannelKey->securityToken(std::rand());
				auto it = secureChannelKeyMap_.find(secureChannelKey->securityToken());
				if (it == secureChannelKeyMap_.end()) {
					break;
				}
			}
		}

		// insert new secure channel key to security channel key map
		actSecurityToken_ = secureChannelKey->securityToken();
		secureChannelKeyMap_.insert(std::make_pair(secureChannelKey->securityToken(), secureChannelKey));

		Log(Debug, "create secure channel key")
			.parameter("SecurityToken", secureChannelKey->securityToken())
			.parameter("ExpireTime", secureChannelKey->expireTime());
		return secureChannelKey;
	}

	SecureChannelKey::SPtr
	SecureChannelKeys::getSecureChannelKey(uint32_t securityToken)
	{
		// find secure channel key
		auto it = secureChannelKeyMap_.find(securityToken);
		if (it != secureChannelKeyMap_.end()) {
			return it->second;
		}

		return nullptr;
	}

	bool
	SecureChannelKeys::delSecureChannelKey(uint32_t securityToken)
	{
		// find secure channel key
		auto it = secureChannelKeyMap_.find(securityToken);
		if (it == secureChannelKeyMap_.end()) {
			return false;
		}

		Log(Debug, "remove secure channel key")
			.parameter("SecurityToken", it->second->securityToken())
			.parameter("ExpireTime", it->second->expireTime());

		// remove secure channel key from secure channel key map
		secureChannelKeyMap_.erase(it);

		return true;
	}

	bool
	SecureChannelKeys::existSecureChannelKey(uint32_t securityToken)
	{
		// find secure channel key
		auto it = secureChannelKeyMap_.find(securityToken);
		if (it == secureChannelKeyMap_.end()) {
			return false;
		}

		return true;
	}

	void
	SecureChannelKeys::removeExpiredSecureChannelKeys(void)
	{
		// find expired secure channel keys
		std::vector<uint32_t> securityTokens;
 		for (auto it : secureChannelKeyMap_) {
			if (it.second->isExpiredSecurechannelKey()) {
				Log(Debug, "create secure channel key")
					.parameter("SecurityToken", it.second->securityToken())
					.parameter("ExpireTime", it.second->expireTime());

				securityTokens.push_back(it.first);
			}
		}

 		// remove expired secure channel keys
 		for (auto securityToken : securityTokens) {
 			secureChannelKeyMap_.erase(securityToken);
 		}
	}

}
