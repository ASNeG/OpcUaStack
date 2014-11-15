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
		OpcUaNodeId nodeId;
		OpcUaString::SPtr nodeIdString;
		BaseNodeClass::SPtr baseNodeClass;

		nodeId.namespaceIndex(1);
		nodeIdString = OpcUaString::construct();
		nodeIdString->value("Raspberry.BinaryOutput");
		nodeId.nodeId(nodeIdString);
		baseNodeClass = informationModel_->find(nodeId);
		if (baseNodeClass.get() != nullptr) readValues(baseNodeClass, outputGpioBinaryItemVec_);

#if 0
		nodeId.namespaceIndex(1);
		nodeIdString = OpcUaString::construct();
		nodeIdString->value("Raspberry.BinaryInput");
		nodeId.nodeId(nodeIdString);
		baseNodeClass = informationModel_->find(nodeId);
		if (baseNodeClass.get() != nullptr) getConfigurationInput(baseNodeClass);
#endif
	}

	bool 
	Raspberry::readValues(BaseNodeClass::SPtr baseNodeClass, GpioBinaryItemVec& gpioBinaryItemVec)
	{
		std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> it;
		it = baseNodeClass->referenceItemMap().referenceItemMultiMap().equal_range(*ReferenceTypeMap::hasComponentTypeNodeId());

		ReferenceItemMultiMap::iterator itl;
		for (itl = it.first; itl != it.second; itl++) {
			ReferenceItem::SPtr referenceItem  = itl->second;

			BaseNodeClass::SPtr baseNodeClassTarget = informationModel_->find(referenceItem->nodeId_);
			if (baseNodeClassTarget.get() == nullptr) continue;

			GpioBinaryItem gpioBinaryItem;
			if (readPropertyPin(baseNodeClassTarget, gpioBinaryItem)) {
				gpioBinaryItemVec.push_back(gpioBinaryItem);
			}
		}
		
		return true;
	}

	bool
	Raspberry::readPropertyPin(BaseNodeClass::SPtr baseNodeClass, GpioBinaryItem& gpioBinaryItem)
	{
		std::pair<ReferenceItemMultiMap::iterator,ReferenceItemMultiMap::iterator> it;
		it = baseNodeClass->referenceItemMap().referenceItemMultiMap().equal_range(*ReferenceTypeMap::hasPropertyTypeNodeId());

		ReferenceItemMultiMap::iterator itl;
		for (itl = it.first; itl != it.second; itl++) {
			ReferenceItem::SPtr referenceItem  = itl->second;

			BaseNodeClass::SPtr baseNodeClassTarget = informationModel_->find(referenceItem->nodeId_);
			if (baseNodeClassTarget.get() == nullptr) continue;

			if (baseNodeClassTarget->browseName().data().name().value() == "Pin") {
				ValueAttribute *valueAttribute = reinterpret_cast<ValueAttribute*>(baseNodeClassTarget->valueAttribute());
				gpioBinaryItem.pin_ = valueAttribute->data().variant()->variant<OpcUaByte>();
				return true;
			}
		}

		return false;
	}

}