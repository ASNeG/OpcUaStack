/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_ChannelSessionHandleMap_h__
#define __OpcUaStackServer_ChannelSessionHandleMap_h__

#include "OpcUaStackServer/ServiceSet/ChannelSessionHandle.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ChannelSessionHandleMap
	{
	  public:

		typedef boost::shared_ptr<ChannelSessionHandleMap> SPtr;

		ChannelSessionHandleMap(void);
		~ChannelSessionHandleMap(void);

		ChannelSessionHandle::SPtr createSecureChannel(
			SecureChannelServer::SPtr& secureChannelServer,
			SecureChannel* secureChannel
		);
		void deleteSecureChannel(SecureChannel* secureChannel);
		void getSecureChannelList(std::vector<SecureChannel*>& secureChannelList);
		uint32_t secureChannelSize(void);

		ChannelSessionHandle::SPtr createSession(Session::SPtr& session, SecureChannel* secureChannel);
		void deleteSession(Session::SPtr& session);
		void deleteSession(uint32_t authenticationToken);
		uint32_t sessionSize(void);

	  private:
		ChannelSessionHandle::Map channelIdMap_;
		ChannelSessionHandle::Map sessionMap_;
	};

}

#endif
