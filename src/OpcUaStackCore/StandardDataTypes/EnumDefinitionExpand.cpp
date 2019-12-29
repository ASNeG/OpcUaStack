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

#include <OpcUaStackCore/StandardDataTypes/EnumDefinitionExpand.h>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"

namespace OpcUaStackCore
{

	EnumDefinitionExpand::EnumDefinitionExpand(void)
	: DataTypeDefinition()
	, name_("")
	, enumFields_(boost::make_shared<EnumFieldArray>())
	{
	}

	EnumDefinitionExpand::~EnumDefinitionExpand(void)
	{
	}

	void
	EnumDefinitionExpand::name(const std::string& name)
	{
		name_ = name;
	}

	std::string&
	EnumDefinitionExpand::name(void)
	{
		return name_;
	}


	void
	EnumDefinitionExpand::enumFields(EnumFieldArray::SPtr& enumFields)
	{
		if (enumFields_.get() == nullptr) {
			return;
		}
		enumFields_ = enumFields;
	}

	EnumFieldArray::SPtr&
	EnumDefinitionExpand::enumFields(void)
	{
		return enumFields_;
	}

	void
	EnumDefinitionExpand::copyTo(EnumDefinitionExpand& enumTypeDefinition)
	{
		enumFields_->copyTo(*enumTypeDefinition.enumFields_);
	}

	bool
	EnumDefinitionExpand::operator==(const EnumDefinitionExpand& enumTypeDefinition) const
	{
		return *enumFields_ == *enumTypeDefinition.enumFields_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	EnumDefinitionExpand::factory(void)
	{
		return boost::make_shared<EnumDefinitionExpand>();
	}

	OpcUaNodeId
	EnumDefinitionExpand::binaryTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_EnumDefinition_Encoding_DefaultBinary);
	}

	OpcUaNodeId
	EnumDefinitionExpand::xmlTypeId(void)
	{
		return OpcUaNodeId((OpcUaUInt32)OpcUaId_EnumDefinition_Encoding_DefaultXml);
	}

	bool
	EnumDefinitionExpand::opcUaBinaryEncode(std::ostream& os) const
	{
		return enumFields_->opcUaBinaryEncode(os);
	}

	bool
	EnumDefinitionExpand::opcUaBinaryDecode(std::istream& is)
	{
		return enumFields_->opcUaBinaryDecode(is);
	}

	bool
	EnumDefinitionExpand::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		// FIXME: todo
		return false;
	}

	bool
	EnumDefinitionExpand::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	EnumDefinitionExpand::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	EnumDefinitionExpand::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	bool
	EnumDefinitionExpand::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return true;
	}

	void
	EnumDefinitionExpand::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		EnumDefinitionExpand* dst = dynamic_cast<EnumDefinitionExpand*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	EnumDefinitionExpand::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		EnumDefinitionExpand* dst = dynamic_cast<EnumDefinitionExpand*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	EnumDefinitionExpand::out(std::ostream& os)
	{
		os << "EnumFields="; enumFields_->out(os);
	}

}


