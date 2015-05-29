#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/InformationModel/Parent.h"


using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	Parent::Parent(void)
	: informationModel_()
	{
	}

	Parent::Parent(InformationModel::SPtr informationModel)
	: informationModel_(informationModel)
	{
	}

	Parent::~Parent(void)
	{
	}

	void
	Parent::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	bool
	Parent::getParent(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& parentBaseNodeClassVec)
	{
		// FIXME: TODO
		return true;
	}

	bool
	Parent::getParentHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::SPtr& parentBaseNodeClass)
	{
		// FIXME: TODO
		return true;
	}

	bool
	Parent::getParentHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& parentBaseNodeClassVec)
	{
		// FIXME: TODO
		return true;
	}

	bool getParentNonHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::SPtr& parentBaseNodeClass)
	{
		// FIXME: TODO
		return true;
	}

	bool getParentNonHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& parentBaseNodeClassVec)
	{
		// FIXME: TODO
		return true;
	}

}

