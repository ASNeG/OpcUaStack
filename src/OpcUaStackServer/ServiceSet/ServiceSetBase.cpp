#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

namespace OpcUaStackServer
{

	ServiceSetBase::ServiceSetBase(void)
	: informationModel_()
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


}