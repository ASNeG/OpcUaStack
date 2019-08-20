/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>
#include "OpcUaClient/ClientService/ClientServiceDelay.h"
#include "OpcUaClient/ClientCommand/CommandDelay.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	ClientServiceDelay::ClientServiceDelay(void)
	: ClientServiceBase()
	{
	}

	ClientServiceDelay::~ClientServiceDelay(void)
	{
	}

	ClientServiceBase::SPtr
	ClientServiceDelay::createClientService(void)
	{
		return boost::make_shared<ClientServiceDelay>();
	}

	bool
	ClientServiceDelay::run(ClientServiceManager& clientServiceManager, CommandBase::SPtr& commandBase)
	{
		CommandDelay::SPtr commandDelay = boost::static_pointer_cast<CommandDelay>(commandBase);

		boost::this_thread::sleep(boost::posix_time::milliseconds(commandDelay->timeout()));

		return true;
	}

}

