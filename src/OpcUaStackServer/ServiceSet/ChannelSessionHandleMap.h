/*
   Copyright 2017-2020 Kai Huebl (kai@huebl-sgh.de)

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
			OpcUaStackCore::SecureChannelServer::SPtr& secureChannelServer,
			OpcUaStackCore::SecureChannel* secureChannel
		);
		void deleteSecureChannel(OpcUaStackCore::SecureChannel* secureChannel);
		void getSecureChannelList(std::vector<OpcUaStackCore::SecureChannel*>& secureChannelList);
		uint32_t secureChannelSize(void);

		ChannelSessionHandle::SPtr createSession(Session::SPtr& session, OpcUaStackCore::SecureChannel* secureChannel);
		void deleteSession(void);
		void deleteSession(Session::SPtr& session);
		void deleteSession(uint32_t authenticationToken);
		uint32_t sessionSize(void);

	  private:
		ChannelSessionHandle::Map channelIdMap_;	// All secure channels identified by the channel id
		ChannelSessionHandle::Map sessionMap_;
	};

}

#endif
