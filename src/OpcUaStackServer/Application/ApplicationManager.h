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

#ifndef __OpcUaStackServer_ApplicationManager_h__
#define __OpcUaStackServer_ApplicationManager_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaStackServer/Application/Application.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationManager 
	{
	  public:
		ApplicationManager(void);
		~ApplicationManager(void);

		bool registerApplication(
			const std::string& applicationName,
			ApplicationIf* applicationIf
		);
		bool deregisterApplication(const std::string& applicationName);
		void serviceComponent(Component* serviceComponent);

		bool startup(void);
		bool shutdown(void);

	  private:
		Application::Map applicationMap_;
		Component* serviceComponent_;
	};

}

#endif
