#ifndef __OpcUaStackServer_ApplicationIf_h__
#define __OpcUaStackServer_ApplicationIf_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackServer/Application/ApplicationServiceIf.h"
#include "OpcUaStackClient/Client/Client.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationIf
	{
	  public:
		ApplicationIf(void)
	    : applicationServiceIf_(nullptr)
	  	, config_(nullptr)
	    , client_(nullptr)
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

		void client(OpcUaStackClient::Client* client) {
			client_ = client;
		}

		OpcUaStackClient::Client* client(void) {
			return client_;
		}

	  private:
		ApplicationServiceIf* applicationServiceIf_;
		Config* config_;
		OpcUaStackClient::Client* client_;
	};

}

#endif
