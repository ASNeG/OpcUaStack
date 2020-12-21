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

#ifndef __OpcUaStackCore_ForwardGlobalSync_h__
#define __OpcUaStackCore_ForwardGlobalSync_h__

#include "OpcUaStackCore/Application/ApplicationCallback.h"
#include "OpcUaStackCore/Application/ApplicationRegisterServerContext.h"
#include "OpcUaStackCore/Application/ApplicationFindServerContext.h"
#include "OpcUaStackCore/Application/ApplicationEventItemStartContext.h"
#include "OpcUaStackCore/Application/ApplicationEventItemStopContext.h"
#include "OpcUaStackCore/Application/ApplicationAuthenticationContext.h"
#include "OpcUaStackCore/Application/ApplicationAutorizationContext.h"
#include "OpcUaStackCore/Application/ApplicationCloseSessionContext.h"
#include "OpcUaStackCore/Application/ApplicationNodeNewContext.h"
#include "OpcUaStackCore/Application/ApplicationNodeDeleteContext.h"
#include "OpcUaStackServer/ServiceSetApplication/ForwardSyncCallback.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ForwardGlobalSync
	: public OpcUaStackCore::Object
	{
	  public:
		using SPtr = boost::shared_ptr<ForwardGlobalSync>;

		ForwardGlobalSync(void);
		virtual ~ForwardGlobalSync(void);

		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::RegisterServer>& registerServerService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::FindServer>& findServersService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::EventItemStart>& eventItemStartService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::EventItemStop>& eventItemStopService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Authentication>& authenticationService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Autorization>& autorizationService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::CloseSession>& closeSessionService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::NodeNew>& nodeNewService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::NodeDelete>& nodeDeleteService(void);

		void updateFrom(ForwardGlobalSync& forwardGlobalSync);

	  private:
		// discovery service
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::RegisterServer> registerServerService_;
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::FindServer> findServersService_;

		// event service
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::EventItemStart> eventItemStartService_;
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::EventItemStop> eventItemStopService_;

		// authentication and authorization
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Authentication> authenticationService_;
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Autorization> autorizationService_;
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::CloseSession> closeSessionService_;

		// node service
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::NodeNew> nodeNewService_;
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::NodeDelete> nodeDeleteService_;
	};

}

#endif
