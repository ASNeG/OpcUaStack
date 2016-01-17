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

#ifndef __OpcUaStackServer_ApplicationIf_h__
#define __OpcUaStackServer_ApplicationIf_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackServer/Application/ApplicationServiceIf.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationIf
	{
	  public:
		ApplicationIf(void)
	    : applicationServiceIf_(nullptr)
	  	, config_(nullptr)
	    {
	    }
		virtual ~ApplicationIf(void) {}

		virtual bool startup(void) = 0;
		virtual bool shutdown(void) = 0;
		virtual void receive(ServiceTransaction::SPtr serviceTransaction) {};

		void service(ApplicationServiceIf* applicationServiceIf) {
			applicationServiceIf_ = applicationServiceIf;
		}

		ApplicationServiceIf& service(void) {
			return *applicationServiceIf_;
		}

		void config(Config* config) {
			config_ = config;
		}

		Config* config(void) {
			return config_;
		}

	  private:
		ApplicationServiceIf* applicationServiceIf_;
		Config* config_;
	};

}

#endif
