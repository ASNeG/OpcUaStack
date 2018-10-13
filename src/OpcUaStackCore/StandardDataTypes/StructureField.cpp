/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackCore/StandardDataTypes/StructureField.h"

namespace OpcUaStackCore
{

	StructureField::StructureField(void)
	: ExtensionObjectBase()
	, name_()
	, description_()
	, dataType_()
	, valueRank_(-1)
	, arrayDimensions_(constructSPtr<OpcUaUInt32Array>())
	, maxStringLength_(0)
	, isOptional_(false)
	{
	}

	StructureField::~StructureField(void)
	{
	}

	void
	StructureField::name(OpcUaString& name)
	{
		name_ = name;
	}

	OpcUaString&
	StructureField::name(void)
	{
		return name_;
	}

	void
	StructureField::description(OpcUaLocalizedText& description)
	{
		description_ = description;
	}

	OpcUaLocalizedText&
	StructureField::description(void)
	{
		return description_;
	}

	void
	StructureField::dataType(OpcUaNodeId& dataType)
	{
		dataType_ = dataType;
	}

	OpcUaNodeId&
	StructureField::dataType(void)
	{
		return dataType_;
	}

	void
	StructureField::valueRank(int32_t valueRank)
	{
		valueRank_ = valueRank;
	}

	int32_t
	StructureField::valueRank(void)
	{
		return valueRank_;
	}

	void
	StructureField::arrayDimensions(OpcUaUInt32Array::SPtr& arrayDimensions)
	{
		arrayDimensions_ = arrayDimensions;
	}

	OpcUaUInt32Array::SPtr&
	StructureField::arrayDimensions(void)
	{
		return arrayDimensions_;
	}

	void
	StructureField::maxStringLength(uint32_t maxStringLength)
	{
		maxStringLength_ = maxStringLength;
	}

	uint32_t
	StructureField::maxStringLength(void)
	{
		return maxStringLength_;
	}

	void
	StructureField::isOptional(OpcUaBoolean isOptional)
	{
		isOptional_ = isOptional;
	}

	OpcUaBoolean
	StructureField::isOptional(void)
	{
		return isOptional_;
	}

	void
	StructureField::copyTo(StructureField& structureField)
	{
		name_.copyTo(structureField.name_);
		description_.copyTo(structureField.description_);
		dataType_.copyTo(structureField.dataType_);
		structureField.valueRank_ = valueRank_;
		arrayDimensions_->copyTo(*structureField.arrayDimensions_);
		structureField.maxStringLength_ = maxStringLength_;
		structureField.isOptional_ = isOptional_;
	}

	bool
	StructureField::operator==(const StructureField& structureField) const
	{
		StructureField* dst = const_cast<StructureField*>(&structureField);

		return
			name_ == dst->name_ &&
			description_ == dst->description_ &&
			dataType_ == dst->dataType_ &&
			valueRank_ == dst->valueRank_ &&
			*arrayDimensions_ == *dst->arrayDimensions_ &&
			maxStringLength_ == dst->maxStringLength_ &&
			isOptional_ == dst->isOptional_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	StructureField::factory(void)
	{
		return constructSPtr<StructureField>();
	}

	OpcUaNodeId
	StructureField::binaryTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_StructureField_Encoding_DefaultBinary);
	}

	OpcUaNodeId
	StructureField::xmlTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_StructureField_Encoding_DefaultXml);
	}

	void
	StructureField::opcUaBinaryEncode(std::ostream& os) const
	{
		name_.opcUaBinaryEncode(os);
		description_.opcUaBinaryEncode(os);
		dataType_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, valueRank_);
		arrayDimensions_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, maxStringLength_);
		OpcUaNumber::opcUaBinaryEncode(os, isOptional_);
	}

	void
	StructureField::opcUaBinaryDecode(std::istream& is)
	{
		name_.opcUaBinaryDecode(is);
		description_.opcUaBinaryDecode(is);
		dataType_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, valueRank_);
		arrayDimensions_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, maxStringLength_);
		OpcUaNumber::opcUaBinaryDecode(is, isOptional_);
	}

	bool
	StructureField::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		// FIXME: todo
		return false;
	}

	bool
	StructureField::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	StructureField::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	StructureField::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	StructureField::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	void
	StructureField::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		StructureField* dst = dynamic_cast<StructureField*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	StructureField::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		StructureField* dst = dynamic_cast<StructureField*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	StructureField::out(std::ostream& os)
	{
		os << "Name="; name_.out(os);
		os << ", Description="; description_.out(os);
		os << ", DataType="; dataType_.out(os);
		os << ", ArrayDimensions="; arrayDimensions_->out(os);
		os << ", MaxStringLength=" << maxStringLength_;
		os << ", IsOptional=" << isOptional_;
	}

}


