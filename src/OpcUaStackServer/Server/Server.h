#ifndef __OpcUaStackServer_Server_h__
#define __OpcUaStackServer_Server_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/Core/Core.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/ServiceSet/SessionManager.h"
#include "OpcUaStackServer/ServiceManager/ServiceManager.h"
#include "OpcUaStackServer/Application/ApplicationManager.h"

namespace OpcUaStackServer
{

	class DLLEXPORT Server 
	: public OpcUaStackCore::Core
	{
	  public:
	    Server(void);
	    ~Server(void);

		bool init(void);
		bool shutdown(void);
		bool start(void);
		void stop(void);

		InformationModel::SPtr getInformationModel(void);
		IOService* ioService(void);
		ApplicationManager& applicationManager(void);
		ServiceManager& serviceManager(void);

	  private:
		bool readInformationModel(void);
		bool writeInformationModel(const std::string& nodeSetFileName, std::vector<std::string>& namespaceUris);
		bool setInformationModel(void);
		bool initService(void);
		bool shutdownService(void);
		bool initSession(void);
		bool shutdownSession(void);

		IOService ioService_;
		InformationModel::SPtr informationModel_;
		SessionManager sessionManager_;
		ServiceManager serviceManager_;
		ApplicationManager applicationManager_;
	};

}

#endif
