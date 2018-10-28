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
#include "OpcUaStackCore/StandardDataTypes/StructureDefinition.h"

namespace OpcUaStackCore
{

	StructureDefinition::StructureDefinition(void)
	: DataTypeDefinition()
	, name_("")
	, symbolicName_("")
	, defaultEncodingId_()
	, baseDataType_()
	, structureType_(0)
	, fields_(constructSPtr<StructureFieldArray>())
	{
	}

	StructureDefinition::~StructureDefinition(void)
	{
	}

	void
	StructureDefinition::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	StructureDefinition::name(void)
	{
		return name_;
	}

	void
	StructureDefinition::symbolicName(const std::string& symbolicName)
	{
		symbolicName_ = symbolicName;
	}

	std::string&
	StructureDefinition::symbolicName(void)
	{
		return symbolicName_;
	}

	void
	StructureDefinition::defaultEncodingId(OpcUaNodeId& defaultEncodingId)
	{
		defaultEncodingId_ = defaultEncodingId;
	}

	OpcUaNodeId&
	StructureDefinition::defaultEncodingId(void)
	{
		return defaultEncodingId_;
	}

	void
	StructureDefinition::baseDataType(OpcUaNodeId& baseDataType)
	{
		baseDataType_ = baseDataType;
	}

	OpcUaNodeId&
	StructureDefinition::baseDataType(void)
	{
		return baseDataType_;
	}

	void
	StructureDefinition::structureType(uint32_t structureType)
	{
		structureType_ = structureType;
	}

	uint32_t
	StructureDefinition::structureType(void)
	{
		return structureType_;
	}

	void
	StructureDefinition::fields(StructureFieldArray::SPtr& fields)
	{
		if (fields_.get() == nullptr) return;
		fields_ = fields;
	}

	StructureFieldArray::SPtr&
	StructureDefinition::fields(void)
	{
		return fields_;
	}

	void
	StructureDefinition::copyTo(StructureDefinition& structureTypeDefinition)
	{
		defaultEncodingId_.copyTo(structureTypeDefinition.defaultEncodingId_);
		baseDataType_.copyTo(structureTypeDefinition.baseDataType_);
		structureTypeDefinition.structureType_ = structureType_;
		fields_->copyTo(*structureTypeDefinition.fields_);
	}

	bool
	StructureDefinition::operator==(const StructureDefinition& structureTypeDefinition) const
	{
		return
			defaultEncodingId_ == structureTypeDefinition.defaultEncodingId_ &&
			baseDataType_ == structureTypeDefinition.baseDataType_ &&
			structureType_ == structureTypeDefinition.structureType_ &&
			*fields_ == *structureTypeDefinition.fields_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	StructureDefinition::factory(void)
	{
		return constructSPtr<StructureDefinition>();
	}

	OpcUaNodeId
	StructureDefinition::binaryTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_StructureDefinition_Encoding_DefaultBinary);
	}

	OpcUaNodeId
	StructureDefinition::xmlTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_StructureDefinition_Encoding_DefaultXml);
	}

	void
	StructureDefinition::opcUaBinaryEncode(std::ostream& os) const
	{
		defaultEncodingId_.opcUaBinaryEncode(os);
		baseDataType_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, structureType_);
		fields_->opcUaBinaryEncode(os);
	}

	void
	StructureDefinition::opcUaBinaryDecode(std::istream& is)
	{
		defaultEncodingId_.opcUaBinaryDecode(is);
		baseDataType_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, structureType_);
		fields_->opcUaBinaryDecode(is);
	}

	bool
	StructureDefinition::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		// FIXME: todo
		return false;
	}

	bool
	StructureDefinition::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	StructureDefinition::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	StructureDefinition::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	StructureDefinition::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	void
	StructureDefinition::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		StructureDefinition* dst = dynamic_cast<StructureDefinition*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	StructureDefinition::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		StructureDefinition* dst = dynamic_cast<StructureDefinition*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	StructureDefinition::out(std::ostream& os)
	{
		os << "DefaultEncodingId="; defaultEncodingId_.out(os);
		os << ", BaseDataType="; baseDataType_.out(os);
		os << ", StructureType=" << structureType_;
		os << ", Fields="; fields_->out(os);
	}

}


