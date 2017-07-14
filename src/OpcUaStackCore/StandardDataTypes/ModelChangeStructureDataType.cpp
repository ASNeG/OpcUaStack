/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Samuel Huebl (samuel.huebl@asneg.de)
 */

#include "OpcUaStackCore/StandardDataTypes/ModelChangeStructureDataType.h"

namespace OpcUaStackCore
{

	ModelChangeStructureDataType::ModelChangeStructureDataType(void)
	: Object()
	, affected_()
	, affectedType_()
	, verb_()
	{
	}

	ModelChangeStructureDataType::~ModelChangeStructureDataType(void)
	{
	}

	OpcUaNodeId&
	ModelChangeStructureDataType::affected(void)
	{
		return affected_;
	}

	void
	ModelChangeStructureDataType::affected(OpcUaNodeId affected)
	{
		affected_ = affected;
	}

	OpcUaNodeId&
	ModelChangeStructureDataType::affectedType(void)
	{
		return affectedType_;
	}

	void
	ModelChangeStructureDataType::affectedType(OpcUaNodeId affectedType)
	{
		affectedType_ = affectedType;
	}

	OpcUaByte&
	ModelChangeStructureDataType::verb(void)
	{
		return verb_;
	}

	void
	ModelChangeStructureDataType::verb(OpcUaByte verb)
	{
		verb_ = verb;
	}

	void
	ModelChangeStructureDataType::copyTo(ModelChangeStructureDataType& modelChangeStructureDataType)
	{
		affected_.copyTo(modelChangeStructureDataType.affected());
		affectedType_.copyTo(modelChangeStructureDataType.affectedType());
		modelChangeStructureDataType.verb(verb_);

	}

	bool
	ModelChangeStructureDataType::operator==(const ModelChangeStructureDataType& modelChangeStructureDataType) const
	{
		ModelChangeStructureDataType* dst = const_cast<ModelChangeStructureDataType*>(&modelChangeStructureDataType);
		return
			affected_ == dst->affected() &&
			affectedType_ == dst->affectedType() &&
			verb_ == dst->verb();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	ModelChangeStructureDataType::factory(void)
	{
		return constructSPtr<ModelChangeStructureDataType>();
	}

	void
	ModelChangeStructureDataType::opcUaBinaryEncode(std::ostream& os) const
	{
		affected_.opcUaBinaryEncode(os);
		affectedType_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, verb_);
	}

	void
	ModelChangeStructureDataType::opcUaBinaryDecode(std::istream& is)
	{
		affected_.opcUaBinaryDecode(is);
		affectedType_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, verb_);
	}

	bool
	ModelChangeStructureDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	ModelChangeStructureDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	ModelChangeStructureDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	void
	ModelChangeStructureDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		ModelChangeStructureDataType* dst = dynamic_cast<ModelChangeStructureDataType*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	ModelChangeStructureDataType::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		ModelChangeStructureDataType* dst = dynamic_cast<ModelChangeStructureDataType*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	ModelChangeStructureDataType::out(std::ostream& os)
	{
		os << "Affected=" << affected_;
		os << ", AffectedType=" << affectedType_;
		os << ", Verb=" << verb_;
	}

}

