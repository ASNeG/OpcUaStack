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


#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionServiceConfig
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SessionServiceConfig::SessionServiceConfig(void)
	: mode_(Session::M_SecureChannelAndSession)
	, ioThreadName_("Session")
	, sessionIf_(nullptr)
	, secureChannelClient_(construct<SecureChannelClientConfig>().get())
	, session_(construct<SessionConfig>().get())
	{
	}

	SessionServiceConfig::~SessionServiceConfig(void)
	{
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ServiceSetManager
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ServiceSetManager::ServiceSetManager(void)
	: ioThreadMap_()
	{
	}

	ServiceSetManager::~ServiceSetManager(void)
	{
		while (ioThreadMap_.size() != 0) {
			destroyIOThread(ioThreadMap_.begin()->first);
		}
	}

	void
	ServiceSetManager::createIOThread(const std::string ioThreadName)
	{
		IOThread::SPtr ioThread = getIOThread(ioThreadName);
		if (ioThread.get() != nullptr) return;

		Log(Debug, "service set manager starts io thread")
		    .parameter("IOThreadName", ioThreadName);
		ioThread = construct<IOThread>();
		ioThread->startup();
	}

	void
	ServiceSetManager::destroyIOThread(const std::string ioThreadName)
	{
		IOThread::Map::iterator it;
		it = ioThreadMap_.find(ioThreadName);
		if (it == ioThreadMap_.end()) return;

		Log(Debug, "service set manager stops io thread")
		    .parameter("IOThreadName", ioThreadName);
		IOThread::SPtr ioThread = it->second;
		ioThread->shutdown();
		ioThreadMap_.erase(it);
	}

	IOThread::SPtr
	ServiceSetManager::getIOThread(const std::string ioThreadName)
	{
		IOThread::SPtr ioThread;
		IOThread::Map::iterator it;
		it = ioThreadMap_.find(ioThreadName);
		if (it != ioThreadMap_.end()) ioThread = it->second;
		return ioThread;
	}

	Session::SPtr
	ServiceSetManager::createSession(SessionServiceConfig& sessionServiceConfig)
	{
		// create new session
		createIOThread(sessionServiceConfig.ioThreadName_);
		IOThread::SPtr ioThread = getIOThread(sessionServiceConfig.ioThreadName_);
		Session::SPtr session = construct<Session>(ioThread.get());

		// set session configuration
		session->setConfiguration(
			sessionServiceConfig.mode_,
			sessionServiceConfig.sessionIf_,
			sessionServiceConfig.secureChannelClient_,
			sessionServiceConfig.session_
		);

		return session;
	}

}
