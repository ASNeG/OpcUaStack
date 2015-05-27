
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/InformationModel/Child.h"


using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	Child::Child(void)
	: informationModel_()
	{
	}

	Child::Child(InformationModel::SPtr informationModel)
	: informationModel_(informationModel)
	{
	}

	Child::~Child(void)
	{
	}

	void
	Child::informationModel(InformationModel::SPtr informationModel)
	{
		informationModel_ = informationModel;
	}

	bool
	Child::getChild(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec)
	{
		// FIXME: TODO
		return true;
	}

	bool
	Child::getChildHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec)
	{
		// FIXME: TODO
		return true;
	}

	bool getChildNonHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec)
	{
		// FIXME: TODO
		return true;
	}

}

