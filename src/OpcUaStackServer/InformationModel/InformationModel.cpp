#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"
#include "OpcUaStackCore/Base/Log.h"

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

	void 
	InformationModel::checkForwardReferences(void)
	{
		InformationModelMap::iterator it;
		for (it = informationModelMap_.begin(); it != informationModelMap_.end(); it++) {
			BaseNodeClass::SPtr baseNodeClass = it->second;

			ReferenceItemMultiMap::iterator itr;
			for (itr = baseNodeClass->referenceItemMap().referenceItemMultiMap().begin(); itr != baseNodeClass->referenceItemMap().referenceItemMultiMap().end(); itr++) {
				OpcUaNodeId referenceTypeNodeId = itr->first;
				ReferenceItem::SPtr referenceItem = itr->second;
				if (referenceItem->isForward_) continue;

				BaseNodeClass::SPtr baseNodeClassTarget = find(referenceItem->nodeId_);
				if (baseNodeClassTarget.get() == nullptr) continue;

				ReferenceItem::SPtr referenceItemForward = ReferenceItem::construct();
				referenceItemForward->isForward_ = true;
				baseNodeClass->nodeId().data().copyTo(referenceItemForward->nodeId_);

				baseNodeClassTarget->referenceItemMap().add(referenceTypeNodeId, referenceItemForward);
			}
		}
	}

	bool 
	InformationModel::setValue(OpcUaUInt32 nodeId, AttributeId attributeId, OpcUaDataValue& dataValue)
	{
		OpcUaNodeId opcUaNodeId;
		opcUaNodeId.nodeId(nodeId);
		return setValue(opcUaNodeId, attributeId, dataValue);
	}

	bool 
	InformationModel::setValue(OpcUaUInt32 nodeId, AttributeId attributeId, OpcUaVariant& variant)
	{
		OpcUaNodeId opcUaNodeId;
		opcUaNodeId.nodeId(nodeId);
		return setValue(opcUaNodeId, attributeId, variant);
	}

	bool 
	InformationModel::getValue(OpcUaUInt32 nodeId, AttributeId attributeId, OpcUaDataValue& dataValue)
	{
		OpcUaNodeId opcUaNodeId;
		opcUaNodeId.nodeId(nodeId);
		return getValue(opcUaNodeId, attributeId, dataValue);
	}

	bool 
	InformationModel::getValue(OpcUaUInt32 nodeId, AttributeId attributeId, OpcUaVariant& variant)
	{
		OpcUaNodeId opcUaNodeId;
		opcUaNodeId.nodeId(nodeId);
		return getValue(opcUaNodeId, attributeId, variant);
	}

	bool 
	InformationModel::setValue(OpcUaNodeId& opcUaNodeId, AttributeId attributeId, OpcUaDataValue& dataValue)
	{
		BaseNodeClass::SPtr baseNodeClass = InformationModel::find(opcUaNodeId);
		if (baseNodeClass.get() == nullptr) {
			Log(Error, "cannot set data value, because node not exist in information model")
				.parameter("NodeId", opcUaNodeId)
				.parameter("AttributeId", attributeId);
			return false;
		}
	
		Attribute* attribute = baseNodeClass->attribute(attributeId);
		if (attribute == nullptr) {
			Log(Error, "cannot set data value, because attribute not exist in node")
				.parameter("NodeId", opcUaNodeId)
				.parameter("AttributeId", attributeId);
			return false;
		}

		if (!AttributeAccess::copy(dataValue, *attribute)) {
			Log(Error, "cannot set data value, because attribute error")
				.parameter("NodeId", opcUaNodeId)
				.parameter("AttributeId", attributeId);
			return false;
		}

		return true;
	}

	bool 
	InformationModel::setValue(OpcUaNodeId& opcUaNodeId, AttributeId attributeId, OpcUaVariant& variant)
	{
		BaseNodeClass::SPtr baseNodeClass = InformationModel::find(opcUaNodeId);
		if (baseNodeClass.get() == nullptr) {
			Log(Error, "cannot set variant value, because node not exist in information model")
				.parameter("NodeId", opcUaNodeId)
				.parameter("AttributeId", attributeId);
			return false;
		}
	
		Attribute* attribute = baseNodeClass->attribute(attributeId);
		if (attribute == nullptr) {
			Log(Error, "cannot set variant value, because attribute not exist in node")
				.parameter("NodeId", opcUaNodeId)
				.parameter("AttributeId", attributeId);
			return false;
		}

		if (!AttributeAccess::copy(variant, *attribute)) {
			Log(Error, "cannot set variant value, because attribute error")
				.parameter("NodeId", opcUaNodeId)
				.parameter("AttributeId", attributeId);
			return false;
		}
		return true;
	}
	
	bool 
	InformationModel::getValue(OpcUaNodeId& opcUaNodeId, AttributeId attributeId, OpcUaDataValue& dataValue)
	{
		BaseNodeClass::SPtr baseNodeClass = InformationModel::find(opcUaNodeId);
		if (baseNodeClass.get() == nullptr) {
			Log(Error, "cannot get data value, because node not exist in information model")
				.parameter("NodeId", opcUaNodeId)
				.parameter("AttributeId", attributeId);
			return false;
		}
	
		Attribute* attribute = baseNodeClass->attribute(attributeId);
		if (attribute == nullptr) {
			Log(Error, "cannot get data value, because attribute not exist in node")
				.parameter("NodeId", opcUaNodeId)
				.parameter("AttributeId", attributeId);
			return false;
		}

		if (!AttributeAccess::copy(*attribute, dataValue)) {
			Log(Error, "cannot get data value, because attribute error")
				.parameter("NodeId", opcUaNodeId)
				.parameter("AttributeId", attributeId);
			return false;
		}

		return true;
	}

	bool 
	InformationModel::getValue(OpcUaNodeId& opcUaNodeId, AttributeId attributeId, OpcUaVariant& variant)
	{
		BaseNodeClass::SPtr baseNodeClass = InformationModel::find(opcUaNodeId);
		if (baseNodeClass.get() == nullptr) {
			Log(Error, "cannot get variant value, because node not exist in information model")
				.parameter("NodeId", opcUaNodeId)
				.parameter("AttributeId", attributeId);
			return false;
		}
	
		Attribute* attribute = baseNodeClass->attribute(attributeId);
		if (attribute == nullptr) {
			Log(Error, "cannot get variant value, because attribute not exist in node")
				.parameter("NodeId", opcUaNodeId)
				.parameter("AttributeId", attributeId);
			return false;
		}

		if (!AttributeAccess::copy(*attribute, variant)) {
			Log(Error, "cannot get variant value, because attribute error")
				.parameter("NodeId", opcUaNodeId)
				.parameter("AttributeId", attributeId);
			return false;
		}

		return true;
	}

}