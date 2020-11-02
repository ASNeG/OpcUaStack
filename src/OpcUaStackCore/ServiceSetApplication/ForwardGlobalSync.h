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

#include <OpcUaStackCore/ServiceSetApplication/ForwardSyncCallback.h>
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

namespace OpcUaStackCore
{

	class DLLEXPORT ForwardGlobalSync
	: public Object
	{
	  public:
		using SPtr = boost::shared_ptr<ForwardGlobalSync>;

		ForwardGlobalSync(void);
		virtual ~ForwardGlobalSync(void);

		ForwardSyncCallback<ApplicationCallback::RegisterServer>& registerServerService(void);
		ForwardSyncCallback<ApplicationCallback::FindServer>& findServersService(void);
		ForwardSyncCallback<ApplicationCallback::EventItemStart>& eventItemStartService(void);
		ForwardSyncCallback<ApplicationCallback::EventItemStop>& eventItemStopService(void);
		ForwardSyncCallback<ApplicationCallback::Authentication>& authenticationService(void);
		ForwardSyncCallback<ApplicationCallback::Autorization>& autorizationService(void);
		ForwardSyncCallback<ApplicationCallback::CloseSession>& closeSessionService(void);
		ForwardSyncCallback<ApplicationCallback::NodeNew>& nodeNewService(void);
		ForwardSyncCallback<ApplicationCallback::NodeDelete>& nodeDeleteService(void);

		void updateFrom(ForwardGlobalSync& forwardGlobalSync);

	  private:
		// discovery service
		ForwardSyncCallback<ApplicationCallback::RegisterServer> registerServerService_;
		ForwardSyncCallback<ApplicationCallback::FindServer> findServersService_;

		// event service
		ForwardSyncCallback<ApplicationCallback::EventItemStart> eventItemStartService_;
		ForwardSyncCallback<ApplicationCallback::EventItemStop> eventItemStopService_;

		// authentication and authorization
		ForwardSyncCallback<ApplicationCallback::Authentication> authenticationService_;
		ForwardSyncCallback<ApplicationCallback::Autorization> autorizationService_;
		ForwardSyncCallback<ApplicationCallback::CloseSession> closeSessionService_;

		// node service
		ForwardSyncCallback<ApplicationCallback::NodeNew> nodeNewService_;
		ForwardSyncCallback<ApplicationCallback::NodeDelete> nodeDeleteService_;
	};

}

#endif
