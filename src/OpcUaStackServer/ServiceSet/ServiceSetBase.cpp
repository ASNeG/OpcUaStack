#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"

namespace OpcUaStackServer
{

	ServiceSetBase::ServiceSetBase(void)
	: Component()
	, informationModel_()
	, namespaceArray_(NamespaceArray::construct())
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

}