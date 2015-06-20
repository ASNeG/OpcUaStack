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
