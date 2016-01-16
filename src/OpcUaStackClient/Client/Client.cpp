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
#include "OpcUaStackClient/Client/Client.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{
		
	Client::Client(void)
	: Core()
	, serviceSetManager_()
	{
	}

	Client::~Client(void)
	{
	}

	bool 
	Client::startup(void)
	{
		bool rc = true;

		Log(Info, "init opc ua core stack");
		rc = rc && Core::init();

		return rc;
	}

	void 
	Client::shutdown(void)
	{
		Core::cleanup();
	}

	bool 
	Client::start(void)
	{
		serviceSetManager_.start();
		return true;
	}

	void 
	Client::stop(void)
	{
		serviceSetManager_.stop();
	}

	ServiceSetManager&
	Client::serviceSetManager(void)
	{
		return serviceSetManager_;
	}

}
