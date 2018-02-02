/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/ForwardGlobalSync.h"

namespace OpcUaStackCore
{

	ForwardGlobalSync::ForwardGlobalSync(void)
	: registerServerService_()
	, findServersService_()
	, eventItemStartService_()
	, eventItemStopService_()
	, authenticationService_()
	, authorizationService_()
	{
	}

	ForwardGlobalSync::~ForwardGlobalSync(void)
	{
	}

	ForwardCallback&
	ForwardGlobalSync::registerServerService(void)
	{
		return registerServerService_;
	}

	ForwardCallback&
	ForwardGlobalSync::findServersService(void)
	{
		return findServersService_;
	}

	ForwardCallback&
	ForwardGlobalSync::eventItemStartService(void)
	{
		return eventItemStartService_;
	}

	ForwardCallback&
	ForwardGlobalSync::eventItemStopService(void)
	{
		return eventItemStopService_;
	}

	ForwardCallback&
	ForwardGlobalSync::authenticationService(void)
	{
		return authenticationService_;
	}

	ForwardCallback&
	ForwardGlobalSync::authorizationService(void)
	{
		return authorizationService_;
	}

	void
	ForwardGlobalSync::updateFrom(ForwardGlobalSync& forwardGlobalSync)
	{
		registerServerService_.updateFrom(forwardGlobalSync.registerServerService());
		findServersService_.updateFrom(forwardGlobalSync.findServersService());
		eventItemStartService_.updateFrom(forwardGlobalSync.eventItemStartService());
		eventItemStopService_.updateFrom(forwardGlobalSync.eventItemStopService());
		authenticationService_.updateFrom(forwardGlobalSync.authenticationService());
		authorizationService_.updateFrom(forwardGlobalSync.authorizationService());

	}

}
