/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ComplexDataTypes/ComplexDataType.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ComplexDataTypeItem
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ComplexDataTypeItem::ComplexDataTypeItem(void)
	: itemName_("")
	, itemType_(OpcUaBuildInType_Unknown)
	, mandatory_(true)
	{
	}

	ComplexDataTypeItem::ComplexDataTypeItem(const std::string& itemName, OpcUaBuildInType itemType)
	: itemName_(itemName)
	, itemType_(itemType)
	, mandatory_(true)
	{
	}

	ComplexDataTypeItem::~ComplexDataTypeItem(void)
	{
	}

	ComplexDataTypeItem::SPtr
	ComplexDataTypeItem::make(const std::string& itemName, OpcUaBuildInType itemType)
	{
		return constructSPtr<ComplexDataTypeItem>(itemName, itemType);
	}

	void
	ComplexDataTypeItem::itemName(const std::string& itemName)
	{
		itemName_ = itemName;
	}

	std::string&
	ComplexDataTypeItem::itemName(void)
	{
		return itemName_;
	}

	void
	ComplexDataTypeItem::itemType(OpcUaBuildInType itemType)
	{
		itemType_ = itemType;
	}

	OpcUaBuildInType
	ComplexDataTypeItem::itemType(void)
	{
		return itemType_;
	}

	void
	ComplexDataTypeItem::mandatory(bool mandatory)
	{
		mandatory_ = mandatory;
	}

	bool
	ComplexDataTypeItem::mandatory(void)
	{
		return mandatory_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ComplexDataType
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ComplexDataType::ComplexDataType(void)
	: complexDataTypeItemVec_()
	, binaryTypeId_()
	, xmlTypeId_()
	, nameIndexMap_()
	, name_("")
	, supertype_("")
	{
	}

	ComplexDataType::ComplexDataType(const std::string& name, ComplexDataTypeItem::Vec& complexDataTypeItemVec)
	: complexDataTypeItemVec_(complexDataTypeItemVec)
	, binaryTypeId_()
	, xmlTypeId_()
	, nameIndexMap_()
	, name_(name)
	, supertype_("")
	{
		uint32_t idx = 0;
		ComplexDataTypeItem::Vec::iterator it;
		for (it = complexDataTypeItemVec_.begin(); it != complexDataTypeItemVec_.end(); it++) {
			ComplexDataTypeItem::SPtr complexDataTypeItem = *it;
			nameIndexMap_.insert(std::make_pair(complexDataTypeItem->itemName(), idx));
			idx++;
		}
	}

	ComplexDataType::~ComplexDataType(void)
	{
	}

	void
	ComplexDataType::complexDataTypeItemVec(ComplexDataTypeItem::Vec& complexDataTypeItemVec)
	{
		complexDataTypeItemVec_ = complexDataTypeItemVec;
		nameIndexMap_.clear();

		uint32_t idx = 0;
		ComplexDataTypeItem::Vec::iterator it;
		for (it = complexDataTypeItemVec_.begin(); it != complexDataTypeItemVec_.end(); it++) {
			ComplexDataTypeItem::SPtr complexDataTypeItem = *it;
			nameIndexMap_.insert(std::make_pair(complexDataTypeItem->itemName(), idx));
			idx++;
		}
	}

	void
	ComplexDataType::addComplexDataTypeItem(ComplexDataTypeItem::SPtr& complexDataTypeItem)
	{
		nameIndexMap_.insert(std::make_pair(complexDataTypeItem->itemName(), complexDataTypeItemVec_.size()));
		complexDataTypeItemVec_.push_back(complexDataTypeItem);
	}

	ComplexDataTypeItem::Vec&
	ComplexDataType::complexDataTypeItemVec(void)
	{
		return complexDataTypeItemVec_;
	}

	ComplexDataTypeItem::SPtr
	ComplexDataType::complexDataTypeItem(const std::string& name)
	{
		ComplexDataTypeItem::SPtr typeItem;
		int32_t index = name2Index(name);
		if (index == -1) {
			return typeItem;
		}
#if 0
		// FIXME: todo
		return complexDataTypeItemVec_[(uint32_t)index];
#endif
	}

	ComplexDataTypeItem::SPtr
	ComplexDataType::complexDataTypeItem(uint32_t index)
	{
		ComplexDataTypeItem::SPtr typeItem;
		if (index >= complexDataTypeItemVec_.size()) {
			return typeItem;
		}
#if 0
		// FIXME: todo
		return complexDataTypeItemVec_[index];
#endif
	}

	void
	ComplexDataType::binaryTypeId(const OpcUaNodeId& binaryTypeId)
	{
		binaryTypeId_ = binaryTypeId;
	}

	OpcUaNodeId&
	ComplexDataType::binaryTypeId(void)
	{
		return binaryTypeId_;
	}

	void
	ComplexDataType::xmlTypeId(OpcUaNodeId& xmlTypeId)
	{
		xmlTypeId_ = xmlTypeId;
	}

	OpcUaNodeId&
	ComplexDataType::xmlTypeId(void)
	{
		return xmlTypeId_;
	}

	void
	ComplexDataType::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	ComplexDataType::name(void)
	{
		return name_;
	}

	void
	ComplexDataType::supertype(const std::string& supertype)
	{
		supertype_ = supertype;
	}

	std::string&
	ComplexDataType::supertype(void)
	{
		return supertype_;
	}

	int32_t
	ComplexDataType::name2Index(const std::string& name)
	{
		NameIndexMap::iterator it;
		it = nameIndexMap_.find(name);
		if (it == nameIndexMap_.end()) return -1;
		return it->second;
	}

	std::string
	ComplexDataType::index2Name(uint32_t index)
	{
		if (index >= complexDataTypeItemVec_.size()) {
			return "";
		}
		return complexDataTypeItemVec_[index]->itemName();
	}

	uint32_t
	ComplexDataType::size(void)
	{
		return complexDataTypeItemVec_.size();
	}

}


