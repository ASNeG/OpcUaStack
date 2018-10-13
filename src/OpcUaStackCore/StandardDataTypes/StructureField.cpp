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
	: EnumValueType()
	, name_()
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
	StructureField::copyTo(StructureField& enumField)
	{
		EnumValueType::copyTo(enumField);
		enumField.name_ = name_;
	}

	bool
	StructureField::operator==(const StructureField& enumField) const
	{
		StructureField* dst = const_cast<StructureField*>(&enumField);

		return
			this->EnumValueType::operator==(*dst) &&
			name_ == dst->name_;
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
		EnumValueType::opcUaBinaryEncode(os);
		name_.opcUaBinaryEncode(os);
	}

	void
	StructureField::opcUaBinaryDecode(std::istream& is)
	{
		EnumValueType::opcUaBinaryDecode(is);
		name_.opcUaBinaryDecode(is);
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
		EnumValueType::out(os);
		os << ", Name="; name_.out(os);
	}

}


