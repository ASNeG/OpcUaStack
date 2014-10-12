#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

namespace OpcUaStackServer
{

	ServiceSetBase::ServiceSetBase(void)
	: informationModel_()
	, ioService_(nullptr)
	{
	}

	ServiceSetBase::~ServiceSetBase(void)
	{
	}

	void 
	ServiceSetBase::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	InformationModel::SPtr 
	ServiceSetBase::informationModel(void)
	{
		return informationModel_;
	}

	void 
	ServiceSetBase::ioService(IOService* ioService)
	{
		ioService_ = ioService;
	}
		
	IOService* 
	ServiceSetBase::ioService(void)
	{
		return ioService_;
	}


}