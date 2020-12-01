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

#include "OpcUaStackCore/SecureChannel/SecureChannelKeys.h"

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

	boost::posix_time::ptime&
	SecureChannelKey::createTime(void)
	{
		return createTime_;
	}

	void
	SecureChannelKey::expireTime(const boost::posix_time::ptime& expireTime)
	{
		expireTime_ = expireTime;
	}

	boost::posix_time::ptime&
	SecureChannelKey::expireTime(void)
	{
		return expireTime_;
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

}
