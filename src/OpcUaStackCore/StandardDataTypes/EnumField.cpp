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
#include "OpcUaStackCore/StandardDataTypes/EnumField.h"

namespace OpcUaStackCore
{

	EnumField::EnumField(void)
	: EnumValueType()
	, name_()
	{
	}

	EnumField::~EnumField(void)
	{
	}

	void
	EnumField::name(OpcUaString& name)
	{
		name_ = name;
	}

	OpcUaString&
	EnumField::name(void)
	{
		return name_;
	}

	void
	EnumField::copyTo(EnumField& enumField)
	{
		EnumValueType::copyTo(enumField);
		enumField.name_ = name_;
	}

	bool
	EnumField::operator==(const EnumField& enumField) const
	{
		EnumField* dst = const_cast<EnumField*>(&enumField);

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
	EnumField::factory(void)
	{
		return constructSPtr<EnumField>();
	}

	OpcUaNodeId
	EnumField::binaryTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_EnumField_Encoding_DefaultBinary);
	}

	OpcUaNodeId
	EnumField::xmlTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_EnumField_Encoding_DefaultXml);
	}

	void
	EnumField::opcUaBinaryEncode(std::ostream& os) const
	{
		EnumValueType::opcUaBinaryEncode(os);
		name_.opcUaBinaryEncode(os);
	}

	void
	EnumField::opcUaBinaryDecode(std::istream& is)
	{
		EnumValueType::opcUaBinaryDecode(is);
		name_.opcUaBinaryDecode(is);
	}

	bool
	EnumField::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		// FIXME: todo
		return false;
	}

	bool
	EnumField::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	EnumField::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	EnumField::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	EnumField::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	void
	EnumField::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		EnumField* dst = dynamic_cast<EnumField*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	EnumField::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		EnumField* dst = dynamic_cast<EnumField*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	EnumField::out(std::ostream& os)
	{
		EnumValueType::out(os);
		os << ", Name="; name_.out(os);
	}

}


