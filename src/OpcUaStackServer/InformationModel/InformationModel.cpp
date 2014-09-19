#include "OpcUaStackServer/InformationModel/InformationModel.h"

namespace OpcUaStackServer
{

	InformationModel::InformationModel(void)
	{
	}

	InformationModel::~InformationModel(void)
	{
	}

	bool 
	InformationModel::insert(BaseNodeClass::SPtr baseNodeClass)
	{
		boost::mutex::scoped_lock lock(mutex_);
		InformationModelMap::iterator it;
		it = informationModelMap_.find(baseNodeClass->nodeId().data());
		if (it != informationModelMap_.end()) {
			return false;
		}

		informationModelMap_.insert(std::make_pair(baseNodeClass->nodeId().data(), baseNodeClass));
		return true;
	}

	BaseNodeClass::SPtr 
	InformationModel::find(OpcUaNodeId& opcUaNodeId)
	{
		boost::mutex::scoped_lock lock(mutex_);
		InformationModelMap::iterator it;
		it = informationModelMap_.find(opcUaNodeId);
		if (it == informationModelMap_.end()) {
			BaseNodeClass::SPtr baseNodeClass;
			return baseNodeClass;
		}
		return it->second;
	}

	BaseNodeClass::SPtr 
	InformationModel::find(OpcUaNodeId::SPtr opcUaNodeId)
	{
		return find(*opcUaNodeId);
	}

}