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

#include "OpcUaStackServer/ServiceSet/ChannelSessionHandleMap.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer 
{

	ChannelSessionHandleMap::ChannelSessionHandleMap(void)
	: channelIdMap_()
	, sessionMap_()
	{
	}

	ChannelSessionHandleMap::~ChannelSessionHandleMap(void)
	{
	}

	ChannelSessionHandle::SPtr
	ChannelSessionHandleMap::createSecureChannel(
		SecureChannelServer::SPtr& secureChannelServer,
		SecureChannel* secureChannel)
	{
		// create new channel session handle
		auto channelSessionHandle = boost::make_shared<ChannelSessionHandle>();
		channelSessionHandle->secureChannel(secureChannel);
		channelSessionHandle->secureChannelServer(secureChannelServer);

		// added new channel session handle to channel map
		channelIdMap_.insert(std::make_pair(secureChannel->channelId_, channelSessionHandle));

		return channelSessionHandle;
	}

	void
	ChannelSessionHandleMap::deleteSecureChannel(SecureChannel* secureChannel)
	{
		// find secure channel
		auto it = channelIdMap_.find(secureChannel->channelId_);
		if (it == channelIdMap_.end()) {
			return;
		}
		auto channelSessionHandle = it->second;
		channelSessionHandle->secureChannel(nullptr);

		// delete element from map
		channelIdMap_.erase(it);
	}

	void
	ChannelSessionHandleMap::getSecureChannelList(std::vector<SecureChannel*>& secureChannelList)
	{
		// get all secure channel
		for (auto it = channelIdMap_.begin(); it != channelIdMap_.end(); it++) {
			if (it->second->secureChannelState() == ChannelSessionHandle::SCS_Valid) {
				secureChannelList.push_back(it->second->secureChannel());
			}
		}
	}

	uint32_t
	ChannelSessionHandleMap::secureChannelSize(void)
	{
		return channelIdMap_.size();
	}

	ChannelSessionHandle::SPtr
	ChannelSessionHandleMap::createSession(Session::SPtr& session, SecureChannel* secureChannel)
	{
		ChannelSessionHandle::SPtr channelSessionHandle;

		// find secure channel
		auto it = channelIdMap_.find(secureChannel->channelId_);
		if (it == channelIdMap_.end()) {
			return nullptr;
		}
		channelSessionHandle = it->second;

		// set session and add session to session map
		channelSessionHandle->session(session);
		sessionMap_.insert(std::make_pair(session->authenticationToken(), channelSessionHandle));

		return channelSessionHandle;
	}

	void
	ChannelSessionHandleMap::deleteSession(void)
	{
		sessionMap_.clear();
	}

	void
	ChannelSessionHandleMap::deleteSession(Session::SPtr& session)
	{
		deleteSession(session->authenticationToken());
	}

	void
	ChannelSessionHandleMap::deleteSession(uint32_t authenticationToken)
	{
		// find session
		auto it = sessionMap_.find(authenticationToken);
		if (it == sessionMap_.end()) {
			return;
		}
		Session::SPtr tmpSession;
		ChannelSessionHandle::SPtr channelSessionHandle = it->second;
		channelSessionHandle->session(tmpSession);

		// delete element from map
		sessionMap_.erase(it);
	}

	uint32_t
	ChannelSessionHandleMap::sessionSize(void)
	{
		return sessionMap_.size();
	}

}
