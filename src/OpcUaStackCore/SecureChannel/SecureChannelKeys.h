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

#ifndef __OpcUaStackCore_SecureChannelKeys_h__
#define __OpcUaStackCore_SecureChannelKeys_h__

#include <boost/asio.hpp>

#include <map>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Certificate/SecurityKeySet.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelKey
	{
	  public:
		using SPtr = std::shared_ptr<SecureChannelKey>();
		using Map = std::map<uint32_t, SPtr>;

		SecureChannelKey(void);
		~SecureChannelKey(void);

		void ownSecurityKeySet(const SecurityKeySet& ownSecurityKeySet);
		SecurityKeySet& ownSecurityKeySet(void);
		void partnerSecurityKeySet(const SecurityKeySet& partnerSecurityKeySet);
		SecurityKeySet& partnerSecurityKeySet(void);
		void securityToken(uint32_t securityToken);
		uint32_t securityToken(void);
		void createTime(const boost::posix_time::ptime& createTime);
		boost::posix_time::ptime& createTime(void);
		void expireTime(const boost::posix_time::ptime& expireTime);
		boost::posix_time::ptime& expireTime(void);

	  private:
		SecurityKeySet ownSecurityKeySet_;
		SecurityKeySet partnerSecurityKeySet_;
		uint32_t securityToken_ = 0;
		boost::posix_time::ptime createTime_;
		boost::posix_time::ptime expireTime_;
	};



	class DLLEXPORT SecureChannelKeys
	{
	  public:
		using SPtr = std::shared_ptr<SecureChannelKeys>;

		SecureChannelKeys(void);
		~SecureChannelKeys(void);

	  private:
	};

}

#endif
