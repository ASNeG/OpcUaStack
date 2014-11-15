#include "OPcUaServer/Raspberry/Raspberry.h"

namespace OpcUaServer
{

	Raspberry::Raspberry(void)
	{
	}

	Raspberry::~Raspberry(void)
	{
	}

	void 
	Raspberry::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	void 
	Raspberry::ioService(IOService& ioService)
	{
		ioService_ = &ioService;
	}

	void
	Raspberry::start(void)
	{
	}

}