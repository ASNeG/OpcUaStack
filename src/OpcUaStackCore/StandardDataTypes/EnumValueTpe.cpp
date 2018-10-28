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
#include "OpcUaStackCore/StandardDataTypes/EnumValueType.h"

namespace OpcUaStackCore
{

	EnumValueType::EnumValueType(void)
	: DataTypeDefinition()
	, value_(0)
	, displayName_()
	, description_()
	{
	}

	EnumValueType::~EnumValueType(void)
	{
	}

	void
	EnumValueType::value(OpcUaInt64 value)
	{
		value_ = value;
	}

	OpcUaInt64
	EnumValueType::value(void)
	{
		return value_;
	}

	void
	EnumValueType::displayName(OpcUaLocalizedText& displayName)
	{
		displayName_ = displayName;
	}

	OpcUaLocalizedText&
	EnumValueType::displayName(void)
	{
		return displayName_;
	}

	void
	EnumValueType::description(OpcUaLocalizedText& description)
	{
		description_ = description;
	}

	OpcUaLocalizedText&
	EnumValueType::description(void)
	{
		return description_;
	}

	void
	EnumValueType::copyTo(EnumValueType& enumValueType)
	{
		enumValueType.value_ = value_;
		displayName_.copyTo(enumValueType.displayName_);
		description_.copyTo(enumValueType.description_);
	}

	bool
	EnumValueType::operator==(const EnumValueType& enumValueType) const
	{
		EnumValueType* dst = const_cast<EnumValueType*>(&enumValueType);

		return
			value_ == dst->value_ &&
			displayName_ == dst->displayName_ &&
			description_ == dst->description_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	EnumValueType::factory(void)
	{
		return constructSPtr<EnumValueType>();
	}

	OpcUaNodeId
	EnumValueType::binaryTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_EnumValueType_Encoding_DefaultBinary);
	}

	OpcUaNodeId
	EnumValueType::xmlTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_EnumValueType_Encoding_DefaultXml);
	}

	void
	EnumValueType::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, value_);
		displayName_.opcUaBinaryEncode(os);
		description_.opcUaBinaryEncode(os);
	}

	void
	EnumValueType::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, value_);
		displayName_.opcUaBinaryDecode(is);
		description_.opcUaBinaryDecode(is);
	}

	bool
	EnumValueType::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		// FIXME: todo
		return false;
	}

	bool
	EnumValueType::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	EnumValueType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	EnumValueType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	EnumValueType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	void
	EnumValueType::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		EnumValueType* dst = dynamic_cast<EnumValueType*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	EnumValueType::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		EnumValueType* dst = dynamic_cast<EnumValueType*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	EnumValueType::out(std::ostream& os)
	{
		os << "Value=" << value_;
		os << ", DisplayName="; displayName_.out(os);
		os << ", Description="; description_.out(os);
	}

}


