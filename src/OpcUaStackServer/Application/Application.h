/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_Application_h__
#define __OpcUaStackServer_Application_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackServer/Application/ApplicationBase.h"
#include "OpcUaStackServer/Application/ApplicationServiceIf.h"
#include "OpcUaStackServer/Application/ReloadIf.h"
#include <map>

namespace OpcUaStackServer
{

	class DLLEXPORT Application
	: public ApplicationBase
	, public Object
	, public ApplicationServiceIf
	{
	  public:
		typedef boost::shared_ptr<Application> SPtr;
		typedef std::map<std::string, Application::SPtr> Map;

		typedef enum
		{
			ApplConstruct,
			ApplStartup,
			ApplShutdown
		} State;

		Application(void);
		~Application(void);

		void applicationIf(ApplicationIf* applicationIf);
		ApplicationIf* applicationIf(void);
		void reloadIf(ReloadIf* reloadIf);
		void applicationName(const std::string& applicationName);
		void serviceComponent(Component* serviceComponent);

		bool startup(void);
		bool shutdown(void);

		//- Component -----------------------------------------------------------------
		virtual void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

		//- ApplicationServiceIf ------------------------------------------------------
		virtual void send(ServiceTransaction::SPtr serviceTransaction);
		virtual void sendSync(ServiceTransaction::SPtr serviceTransaction);
		virtual void reload(void);
		//- ApplicationServiceIf ------------------------------------------------------

	  private:
		void updateServiceTransactionRequest(ServiceTransaction::SPtr serviceTransaction);

		State state_;
		ApplicationIf* applicationIf_;
		ReloadIf* reloadIf_;
		std::string applicationName_;
		Component* serviceComponent_;
	};

}

#endif
