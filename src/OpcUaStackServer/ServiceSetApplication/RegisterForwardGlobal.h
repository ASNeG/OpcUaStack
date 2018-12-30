/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_RegisterForwardGlobal_h__
#define __OpcUaStackServer_RegisterForwardGlobal_h__

#include <vector>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT RegisterForwardGlobal
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardGlobal> SPtr;

		RegisterForwardGlobal(void);
		virtual ~RegisterForwardGlobal(void);

#if 0
		ForwardCallback& registerServerService(void);
		ForwardCallback& findServersService(void);
		ForwardCallback& eventItemStartService(void);
		ForwardCallback& eventItemStopService(void);
		ForwardCallback& authenticationService(void);
		ForwardCallback& autorizationService(void);
		ForwardCallback& closeSessionService(void);
		ForwardCallback& nodeNewService(void);
		ForwardCallback& nodeDeleteService(void);
#endif

		void setRegisterServerCallback(Callback& callback);
		template<typename T>
		  void setRegisterServerCallback(T handler) {
			  Callback callback;
			  callback.reset(handler);
			  setRegisterServerCallback(callback);
		  }

		bool query(ApplicationServiceIf* applicationServiceIf);
		OpcUaStatusCode resultCode(void);


	  private:
		ForwardGlobalSync forwardGlobalSync_;
		OpcUaStatusCode resultCode_;
	};

}
#endif
