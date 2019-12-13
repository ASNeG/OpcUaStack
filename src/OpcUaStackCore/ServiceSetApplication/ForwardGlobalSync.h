/*
   Copyright 2017-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/ForwardCallback.h"
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

		ForwardCallback<ApplicationCallback::RegisterServer>& registerServerService(void);
		ForwardCallback<ApplicationCallback::FindServer>& findServersService(void);
		ForwardCallback<ApplicationCallback::EventItemStart>& eventItemStartService(void);
		ForwardCallback<ApplicationCallback::EventItemStop>& eventItemStopService(void);
		ForwardCallback<ApplicationCallback::Authentication>& authenticationService(void);
		ForwardCallback<ApplicationCallback::Autorization>& autorizationService(void);
		ForwardCallback<ApplicationCallback::CloseSession>& closeSessionService(void);
		ForwardCallback<ApplicationCallback::NodeNew>& nodeNewService(void);
		ForwardCallback<ApplicationCallback::NodeDelete>& nodeDeleteService(void);

		void updateFrom(ForwardGlobalSync& forwardGlobalSync);

	  private:
		// discovery service
		ForwardCallback<ApplicationCallback::RegisterServer> registerServerService_;
		ForwardCallback<ApplicationCallback::FindServer> findServersService_;

		// event service
		ForwardCallback<ApplicationCallback::EventItemStart> eventItemStartService_;
		ForwardCallback<ApplicationCallback::EventItemStop> eventItemStopService_;

		// authentication and authorization
		ForwardCallback<ApplicationCallback::Authentication> authenticationService_;
		ForwardCallback<ApplicationCallback::Autorization> autorizationService_;
		ForwardCallback<ApplicationCallback::CloseSession> closeSessionService_;

		// node service
		ForwardCallback<ApplicationCallback::NodeNew> nodeNewService_;
		ForwardCallback<ApplicationCallback::NodeDelete> nodeDeleteService_;
	};

}

#endif
