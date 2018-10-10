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
	{
	}

	StructureDefinition::~StructureDefinition(void)
	{
	}

	void
	StructureDefinition::copyTo(StructureDefinition& structureTypeDefinition)
	{
		// FIXME: todo
	}

	bool
	StructureDefinition::operator==(const StructureDefinition& structureTypeDefinition) const
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
		// FIXME: todo
	}

	void
	StructureDefinition::opcUaBinaryDecode(std::istream& is)
	{
		// FIXME: todo
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
		// FIXME: todo
	}

}


