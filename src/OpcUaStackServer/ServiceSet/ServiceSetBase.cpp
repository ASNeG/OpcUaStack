#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

namespace OpcUaStackServer
{

	ServiceSetBase::ServiceSetBase(void)
	: Component()
	, informationModel_()
	, namespaceArray_(NamespaceArray::construct())
	, serverArray_(ServerArray::construct())
	{
	}

	ServiceSetBase::~ServiceSetBase(void)
	{
	}

	void 
	ServiceSetBase::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
		namespaceArray_->informationModel(informationModel);
		serverArray_->informationModel(informationModel);
	}

	InformationModel::SPtr 
	ServiceSetBase::informationModel(void)
	{
		return informationModel_;
	}

	NamespaceArray::SPtr 
	ServiceSetBase::namespaceArray(void)
	{
		return namespaceArray_;
	}

	ServerArray::SPtr
	ServiceSetBase::serverArray(void)
	{
		return serverArray_;
	}

}