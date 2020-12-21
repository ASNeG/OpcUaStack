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

#include "OpcUaStackServer/ServiceSetApplication/ForwardGlobalSync.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	ForwardGlobalSync::ForwardGlobalSync(void)
	: registerServerService_()
	, findServersService_()
	, eventItemStartService_()
	, eventItemStopService_()
	, authenticationService_()
	, autorizationService_()
	, closeSessionService_()
	, nodeNewService_()
	, nodeDeleteService_()
	{
	}

	ForwardGlobalSync::~ForwardGlobalSync(void)
	{
	}

	ForwardSyncCallback<ApplicationCallback::RegisterServer>&
	ForwardGlobalSync::registerServerService(void)
	{
		return registerServerService_;
	}

	ForwardSyncCallback<ApplicationCallback::FindServer>&
	ForwardGlobalSync::findServersService(void)
	{
		return findServersService_;
	}

	ForwardSyncCallback<ApplicationCallback::EventItemStart>&
	ForwardGlobalSync::eventItemStartService(void)
	{
		return eventItemStartService_;
	}

	ForwardSyncCallback<ApplicationCallback::EventItemStop>&
	ForwardGlobalSync::eventItemStopService(void)
	{
		return eventItemStopService_;
	}

	ForwardSyncCallback<ApplicationCallback::Authentication>&
	ForwardGlobalSync::authenticationService(void)
	{
		return authenticationService_;
	}

	ForwardSyncCallback<ApplicationCallback::Autorization>&
	ForwardGlobalSync::autorizationService(void)
	{
		return autorizationService_;
	}

	ForwardSyncCallback<ApplicationCallback::CloseSession>&
	ForwardGlobalSync::closeSessionService(void)
	{
		return closeSessionService_;
	}

	ForwardSyncCallback<ApplicationCallback::NodeNew>&
	ForwardGlobalSync::nodeNewService(void)
	{
		return nodeNewService_;
	}

	ForwardSyncCallback<ApplicationCallback::NodeDelete>&
	ForwardGlobalSync::nodeDeleteService(void)
	{
		return nodeDeleteService_;
	}

	void
	ForwardGlobalSync::updateFrom(ForwardGlobalSync& forwardGlobalSync)
	{
		registerServerService_.updateFrom(forwardGlobalSync.registerServerService());
		findServersService_.updateFrom(forwardGlobalSync.findServersService());
		eventItemStartService_.updateFrom(forwardGlobalSync.eventItemStartService());
		eventItemStopService_.updateFrom(forwardGlobalSync.eventItemStopService());
		authenticationService_.updateFrom(forwardGlobalSync.authenticationService());
		autorizationService_.updateFrom(forwardGlobalSync.autorizationService());
		closeSessionService_.updateFrom(forwardGlobalSync.closeSessionService());
		nodeNewService_.updateFrom(forwardGlobalSync.nodeNewService());
		nodeDeleteService_.updateFrom(forwardGlobalSync.nodeDeleteService());
	}

}
