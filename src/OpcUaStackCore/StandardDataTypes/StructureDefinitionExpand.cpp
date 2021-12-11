/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <OpcUaStackCore/StandardDataTypes/StructureDefinitionExpand.h>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackCore
{

	StructureDefinitionExpand::StructureDefinitionExpand(void)
	: DataTypeDefinition()
	, name_("")
	, symbolicName_("")
	, defaultEncodingId_()
	, baseDataType_()
	, structureType_(0)
	, fields_(boost::make_shared<StructureFieldArray>())
	{
	}

	StructureDefinitionExpand::~StructureDefinitionExpand(void)
	{
	}

	void
	StructureDefinitionExpand::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	StructureDefinitionExpand::name(void)
	{
		return name_;
	}

	void
	StructureDefinitionExpand::symbolicName(const std::string& symbolicName)
	{
		symbolicName_ = symbolicName;
	}

	std::string&
	StructureDefinitionExpand::symbolicName(void)
	{
		return symbolicName_;
	}

	void
	StructureDefinitionExpand::defaultEncodingId(OpcUaNodeId& defaultEncodingId)
	{
		defaultEncodingId_ = defaultEncodingId;
	}

	OpcUaNodeId&
	StructureDefinitionExpand::defaultEncodingId(void)
	{
		return defaultEncodingId_;
	}

	void
	StructureDefinitionExpand::baseDataType(OpcUaNodeId& baseDataType)
	{
		baseDataType_ = baseDataType;
	}

	OpcUaNodeId&
	StructureDefinitionExpand::baseDataType(void)
	{
		return baseDataType_;
	}

	void
	StructureDefinitionExpand::structureType(uint32_t structureType)
	{
		structureType_ = structureType;
	}

	uint32_t
	StructureDefinitionExpand::structureType(void)
	{
		return structureType_;
	}

	void
	StructureDefinitionExpand::fields(StructureFieldArray::SPtr& fields)
	{
		if (fields_.get() == nullptr) return;
		fields_ = fields;
	}

	StructureFieldArray::SPtr&
	StructureDefinitionExpand::fields(void)
	{
		return fields_;
	}

	void
	StructureDefinitionExpand::copyTo(StructureDefinitionExpand& structureTypeDefinition)
	{
		defaultEncodingId_.copyTo(structureTypeDefinition.defaultEncodingId_);
		baseDataType_.copyTo(structureTypeDefinition.baseDataType_);
		structureTypeDefinition.structureType_ = structureType_;
		fields_->copyTo(*structureTypeDefinition.fields_);
	}

	bool
	StructureDefinitionExpand::operator==(const StructureDefinitionExpand& structureTypeDefinition) const
	{
		return
			defaultEncodingId_ == structureTypeDefinition.defaultEncodingId_ &&
			baseDataType_ == structureTypeDefinition.baseDataType_ &&
			structureType_ == structureTypeDefinition.structureType_ &&
			*fields_ == *structureTypeDefinition.fields_;
	}

	bool
	StructureDefinitionExpand::operator!=(const StructureDefinitionExpand& value)
	{
	    return !this->operator==(value);
	}

	StructureDefinitionExpand&
	StructureDefinitionExpand::operator=(const StructureDefinitionExpand& value)
    {
	    const_cast<StructureDefinitionExpand*>(&value)->copyTo(*this);
	    return *this;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	StructureDefinitionExpand::factory(void)
	{
		return boost::make_shared<StructureDefinitionExpand>();
	}

	std::string
	StructureDefinitionExpand::namespaceName(void)
	{
	    return "http://opcfoundation.org/UA/";
	}

	std::string
	StructureDefinitionExpand::typeName(void)
	{
	    return "StructureDefinition";
	}

	OpcUaNodeId
	StructureDefinitionExpand::typeId(void)
	{
	    return OpcUaNodeId((OpcUaUInt32)99,0);
	}

	OpcUaNodeId
	StructureDefinitionExpand::binaryTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_StructureDefinition_Encoding_DefaultBinary);
	}

	OpcUaNodeId
	StructureDefinitionExpand::xmlTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_StructureDefinition_Encoding_DefaultXml);
	}

	bool
	StructureDefinitionExpand::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= defaultEncodingId_.opcUaBinaryEncode(os);
		rc &= baseDataType_.opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, structureType_);
		rc &= fields_->opcUaBinaryEncode(os);

		return rc;
	}

	bool
	StructureDefinitionExpand::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		rc &= defaultEncodingId_.opcUaBinaryDecode(is);
		rc &= baseDataType_.opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, structureType_);
		rc &= fields_->opcUaBinaryDecode(is);

		return rc;
	}

	bool
	StructureDefinitionExpand::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		// FIXME: todo
		return false;
	}

	bool
	StructureDefinitionExpand::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	StructureDefinitionExpand::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	StructureDefinitionExpand::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	StructureDefinitionExpand::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	void
	StructureDefinitionExpand::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		StructureDefinitionExpand* dst = dynamic_cast<StructureDefinitionExpand*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	StructureDefinitionExpand::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		StructureDefinitionExpand* dst = dynamic_cast<StructureDefinitionExpand*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	StructureDefinitionExpand::out(std::ostream& os)
	{
		os << "DefaultEncodingId="; defaultEncodingId_.out(os);
		os << ", BaseDataType="; baseDataType_.out(os);
		os << ", StructureType=" << structureType_;
		os << ", Fields="; fields_->out(os);
	}

}


