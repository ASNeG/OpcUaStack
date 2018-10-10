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
	{
	}

	EnumValueType::~EnumValueType(void)
	{
	}

	void
	EnumValueType::copyTo(EnumValueType& enumTypeDefinition)
	{
		// FIXME: todo
	}

	bool
	EnumValueType::operator==(const EnumValueType& enumTypeDefinition) const
	{
		// FIXME: todo
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
		// FIXME: todo
	}

	void
	EnumValueType::opcUaBinaryDecode(std::istream& is)
	{
		// FIXME: todo
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
		// FIXME: todo
	}

}


