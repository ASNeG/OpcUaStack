#ifndef __OpcUaServer_Raspberry_h__
#define __OpcUaServer_Raspberry_h__

#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OPcUaStackCore/Base/IOService.h"

using namespace OpcUaStackServer;
using namespace OpcUaStackCore;

namespace OpcUaServer
{

	class GpioBinaryItem
	{
	  public:
		OpcUaNodeId nodeIdValue_;
		OpcUaByte pin_;
	};

	class Raspberry
	{
	  public:
		typedef std::vector<GpioBinaryItem> GpioBinaryItemVec;

		Raspberry(void);
		~Raspberry(void);

		void informationModel(InformationModel::SPtr informationModel);
		void ioService(IOService& ioService);
		void start(void);

	  private:
		bool readValues(BaseNodeClass::SPtr baseNodeClass, GpioBinaryItemVec& gpioBinaryItemVec);
		bool readPropertyPin(BaseNodeClass::SPtr baseNodeClass, GpioBinaryItem& gpioBinaryItem);

	    InformationModel::SPtr informationModel_;
		IOService* ioService_;

		GpioBinaryItemVec inputGpioBinaryItemVec_;
		GpioBinaryItemVec outputGpioBinaryItemVec_;
	};

}

#endif