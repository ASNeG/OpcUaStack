#ifndef __OpcUaServer_Raspberry_h__
#define __OpcUaServer_Raspberry_h__

#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OPcUaStackCore/Base/IOService.h"

using namespace OpcUaStackServer;
using namespace OpcUaStackCore;

namespace OpcUaServer
{

	class Raspberry
	{
	  public:
		Raspberry(void);
		~Raspberry(void);

		void informationModel(InformationModel::SPtr informationModel);
		void ioService(IOService& ioService);
		void start(void);

	  private:
	    InformationModel::SPtr informationModel_;
		IOService* ioService_;
	};

}

#endif