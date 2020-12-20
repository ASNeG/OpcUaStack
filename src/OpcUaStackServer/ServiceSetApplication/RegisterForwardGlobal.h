/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Application/ApplicationCallback.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT RegisterForwardGlobal
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardGlobal> SPtr;

		RegisterForwardGlobal(void);
		virtual ~RegisterForwardGlobal(void);

		void setRegisterServerCallback(
			OpcUaStackCore::ApplicationCallback::RegisterServer callback
		);
		void setFindServersCallback(
			OpcUaStackCore::ApplicationCallback::FindServer callback
		);
		void setEventItemStartCallback(
			OpcUaStackCore::ApplicationCallback::EventItemStart callback
		);
		void setEventItemStopCallback(
			OpcUaStackCore::ApplicationCallback::EventItemStop callback
		);
		void setAuthenticationCallback(
			OpcUaStackCore::ApplicationCallback::Authentication callback
		);
		void setAutorizationCallback(
			OpcUaStackCore::ApplicationCallback::Autorization callback
		);
		void setCloseSessionCallback(
			OpcUaStackCore::ApplicationCallback::CloseSession callback
		);
		void setNodeNewCallback(
			OpcUaStackCore::ApplicationCallback::NodeNew callback
		);
		void setNodeDeleteCallback(
			OpcUaStackCore::ApplicationCallback::NodeDelete callback
		);

		bool query(ApplicationServiceIf* applicationServiceIf);
		OpcUaStackCore::OpcUaStatusCode resultCode(void);


	  private:
		ForwardGlobalSync forwardGlobalSync_;
		OpcUaStackCore::OpcUaStatusCode resultCode_;
	};

}
#endif
