
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
		ReferenceItemMultiMap::iterator it;
		for (
			it = baseNodeClass->referenceItemMap().referenceItemMultiMap().begin();
			it != baseNodeClass->referenceItemMap().referenceItemMultiMap().end();
			it++
		)
		{
			ReferenceItem::SPtr referenceItem = it->second;
			if (!referenceItem->isForward_) continue;
			BaseNodeClass::SPtr childBaseNodeClass = informationModel_->find(referenceItem->nodeId_);
			if (childBaseNodeClass.get() == nullptr) continue;
			childBaseNodeClassVec.push_back(childBaseNodeClass);
		}
		return true;
	}

	bool
	Child::getChildHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec)
	{
		ReferenceItemMultiMap::iterator it;
		for (
			it = baseNodeClass->referenceItemMap().referenceItemMultiMap().begin();
			it != baseNodeClass->referenceItemMap().referenceItemMultiMap().end();
			it++
		)
		{
			ReferenceItem::SPtr referenceItem = it->second;
			if (!referenceItem->isForward_) continue;
			BaseNodeClass::SPtr childBaseNodeClass = informationModel_->find(referenceItem->nodeId_);
			if (childBaseNodeClass.get() == nullptr) continue;

			childBaseNodeClassVec.push_back(childBaseNodeClass);
		}
		return true;
	}

	bool
	Child::getChildNonHierarchically(BaseNodeClass::SPtr baseNodeClass, BaseNodeClass::Vec& childBaseNodeClassVec)
	{
		ReferenceItemMultiMap::iterator it;
		for (
			it = baseNodeClass->referenceItemMap().referenceItemMultiMap().begin();
			it != baseNodeClass->referenceItemMap().referenceItemMultiMap().end();
			it++
		)
		{
			ReferenceItem::SPtr referenceItem = it->second;
			if (!referenceItem->isForward_) continue;
			BaseNodeClass::SPtr childBaseNodeClass = informationModel_->find(referenceItem->nodeId_);
			if (childBaseNodeClass.get() == nullptr) continue;

			childBaseNodeClassVec.push_back(childBaseNodeClass);
		}
		return true;
	}

}

