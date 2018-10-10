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
#include "OpcUaStackCore/StandardDataTypes/EnumDefinition.h"

namespace OpcUaStackCore
{

	EnumDefinition::EnumDefinition(void)
	: DataTypeDefinition()
	{
	}

	EnumDefinition::~EnumDefinition(void)
	{
	}

	void
	EnumDefinition::copyTo(EnumDefinition& enumTypeDefinition)
	{
		// FIXME: todo
	}

	bool
	EnumDefinition::operator==(const EnumDefinition& enumTypeDefinition) const
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
	EnumDefinition::factory(void)
	{
		return constructSPtr<EnumDefinition>();
	}

	OpcUaNodeId
	EnumDefinition::binaryTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_EnumDefinition_Encoding_DefaultBinary);
	}

	OpcUaNodeId
	EnumDefinition::xmlTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_EnumDefinition_Encoding_DefaultXml);
	}

	void
	EnumDefinition::opcUaBinaryEncode(std::ostream& os) const
	{
		// FIXME: todo
	}

	void
	EnumDefinition::opcUaBinaryDecode(std::istream& is)
	{
		// FIXME: todo
	}

	bool
	EnumDefinition::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		// FIXME: todo
		return false;
	}

	bool
	EnumDefinition::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	EnumDefinition::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	EnumDefinition::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	EnumDefinition::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	void
	EnumDefinition::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		EnumDefinition* dst = dynamic_cast<EnumDefinition*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	EnumDefinition::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		EnumDefinition* dst = dynamic_cast<EnumDefinition*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	EnumDefinition::out(std::ostream& os)
	{
		// FIXME: todo
	}

}


