/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ComplexDataTypes/ComplexDataValue.h"

namespace OpcUaStackCore
{

	ComplexDataValue::ComplexDataValue(void)
	: Object()
	, ExtensionObjectBase()
	{
	}

	ComplexDataValue::~ComplexDataValue(void)
	{
	}

	ExtensionObjectBase::SPtr
	ComplexDataValue::factory(void)
	{
		// FIXME: todo
		ExtensionObjectBase::SPtr x;
		return x;
	}
	OpcUaNodeId
	ComplexDataValue::binaryTypeId(void)
	{
		// FIXME: todo
		OpcUaNodeId x;
		return x;
	}

	OpcUaNodeId
	ComplexDataValue::xmlTypeId(void)
	{
		// FIXME: todo
		OpcUaNodeId x;
		return x;
	}

	void
	ComplexDataValue::opcUaBinaryEncode(std::ostream& os) const
	{
		// FIXME: todo
	}

	void
	ComplexDataValue::opcUaBinaryDecode(std::istream& is)
	{
		// FIXME: todo
	}

	bool
	ComplexDataValue::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
	{
		// FIXME: todo
		return true;
	}

	bool
	ComplexDataValue::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: too
		return true;
	}

	void
	ComplexDataValue::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		// FIXME: todo
	}

	bool
	ComplexDataValue::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		// FIXME: todo
		return true;
	}

	void
	ComplexDataValue::out(std::ostream& os)
	{
		// FIXME: todo
	}

}


