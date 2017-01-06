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
	{
	}

	ComplexDataTypeItem::ComplexDataTypeItem(const std::string& itemName, OpcUaBuildInType itemType)
	: itemName_(itemName)
	, itemType_(itemType)
	{
	}

	ComplexDataTypeItem::~ComplexDataTypeItem(void)
	{
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

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ComplexDataType
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ComplexDataType::ComplexDataType(void)
	{
	}

	ComplexDataType::~ComplexDataType(void)
	{
	}

}


