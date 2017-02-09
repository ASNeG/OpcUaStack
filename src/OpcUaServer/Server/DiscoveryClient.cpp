/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaServer/Server/DiscoveryClient.h"

using namespace OpcUaStackCore;

namespace OpcUaServer
{

	DiscoveryClient::DiscoveryClient(void)
	: config_(nullptr)
	, discoveryClient_()
	{
	}

	DiscoveryClient::~DiscoveryClient(void)
	{
	}

	bool
	DiscoveryClient::startup(Config& config)
	{
		config_ = &config;

		// FIXME: todo

#if 0
	    void ioThread(IOThread::SPtr& ioThread);
	    void loopTime(uint32_t loopTime);
	    void discoveryUri(const std::string& discoveryUri);
#endif

		return true;
	}

	void 
	DiscoveryClient::shutdown(void)
	{
		// FIXME: todo
	}

}
