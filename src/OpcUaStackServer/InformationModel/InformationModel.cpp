/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/AddressSpaceModel/AttributeAccess.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackServer
{

	InformationModel::InformationModel(void)
	: methodMap_()
	, eventHandlerMap_()
	, mutex_()
	{
	}

	InformationModel::~InformationModel(void)
	{
	}

	InformationModelMap& 
	InformationModel::informationModelMap(void)
	{
		return informationModelMap_;
	}

	MethodMap&
	InformationModel::methodMap(void)
	{
		return methodMap_;
	}

	EventHandlerMap&
	InformationModel::eventHandlerMap(void)
	{
		return eventHandlerMap_;
	}

	boost::mutex&
	InformationModel::mutex(void)
	{
		return mutex_;
	}

	void
	InformationModel::clear(void)
	{
		informationModelMap_.clear();
		methodMap_.clear();
		eventHandlerMap_.clear();
	}

	bool 
	InformationModel::insert(BaseNodeClass::SPtr baseNodeClass)
	{
		boost::mutex::scoped_lock lock(mutex_);

		std::pair<InformationModelMap::iterator, bool> insertResult;
		insertResult = informationModelMap_.insert(std::make_pair(baseNodeClass->nodeId().data(), baseNodeClass));
		return insertResult.second;
	}

	BaseNodeClass::SPtr 
	InformationModel::find(const OpcUaNodeId& opcUaNodeId)
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

	bool
	InformationModel::remove(const OpcUaNodeId& opcUaNodeId)
	{
	    boost::mutex::scoped_lock lock(mutex_);

		return informationModelMap_.erase(opcUaNodeId) > 0;
	}

	bool
	InformationModel::remove(OpcUaNodeId::SPtr opcUaNodeId)
	{
		return remove(*opcUaNodeId);
	}

	uint32_t
	InformationModel::size(void)
	{
		return informationModelMap_.size();
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
				if (referenceItem->isForward_) {
					BaseNodeClass::SPtr baseNodeClassTarget = find(referenceItem->nodeId_);
					if (baseNodeClassTarget.get() == nullptr) {
						Log(Warning, "target node reference do not exist")
							.parameter("NodeId", baseNodeClass->getNodeId()->toString())
							.parameter("TargetNodeId", referenceItem->nodeId_.toString());
						continue;
					}

					ReferenceItem::SPtr referenceItemForward = constructSPtr<ReferenceItem>();
					referenceItemForward->isForward_ = false;
					baseNodeClass->nodeId().data().copyTo(referenceItemForward->nodeId_);

					baseNodeClassTarget->referenceItemMap().add(referenceTypeNodeId, referenceItemForward);
				}
				else {
					BaseNodeClass::SPtr baseNodeClassTarget = find(referenceItem->nodeId_);
					if (baseNodeClassTarget.get() == nullptr) {
						Log(Warning, "target node reference do not exist")
							.parameter("NodeId", baseNodeClass->getNodeId()->toString())
							.parameter("TargetNodeId", referenceItem->nodeId_.toString());
						continue;
					}

					ReferenceItem::SPtr referenceItemForward = constructSPtr<ReferenceItem>();
					referenceItemForward->isForward_ = true;
					baseNodeClass->nodeId().data().copyTo(referenceItemForward->nodeId_);

					baseNodeClassTarget->referenceItemMap().add(referenceTypeNodeId, referenceItemForward);
				}
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
