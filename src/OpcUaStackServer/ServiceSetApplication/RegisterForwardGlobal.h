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
#include "OpcUaStackServer/Application/ApplicationIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT RegisterForwardGlobal
	{
	  public:
		typedef boost::shared_ptr<RegisterForwardGlobal> SPtr;

		RegisterForwardGlobal(void);
		virtual ~RegisterForwardGlobal(void);

		void setRegisterServerCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setRegisterServerCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setRegisterServerCallback(callback);
		  }
		void setFindServersCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setFindServersCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setFindServersCallback(callback);
		  }
		void setEventItemStartCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setEventItemStartCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setEventItemStartCallback(callback);
		  }

		void setEventItemStopCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setEventItemStopCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setEventItemStopCallback(callback);
		  }

		void setAuthenticationCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setAuthenticationCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setAuthenticationCallback(callback);
		  }

		void setAutorizationCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setAutorizationCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setAutorizationCallback(callback);
		  }

		void setCloseSessionCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setCloseSessionCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setCloseSessionCallback(callback);
		  }

		void setNodeNewCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setNodeNewCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setNodeNewCallback(callback);
		  }

		void setNodeDeleteCallback(OpcUaStackCore::Callback& callback);
		template<typename T>
		  void setNodeDeleteCallback(T handler) {
			  OpcUaStackCore::Callback callback;
			  callback.reset(handler);
			  setNodeDeleteCallback(callback);
		  }

		bool query(ApplicationServiceIf* applicationServiceIf);
		OpcUaStackCore::OpcUaStatusCode resultCode(void);


	  private:
		OpcUaStackCore::ForwardGlobalSync forwardGlobalSync_;
		OpcUaStackCore::OpcUaStatusCode resultCode_;
	};

}
#endif
