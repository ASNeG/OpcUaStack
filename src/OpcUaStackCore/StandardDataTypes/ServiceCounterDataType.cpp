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

#include "OpcUaStackCore/StandardDataTypes/ServiceCounterDataType.h"

namespace OpcUaStackCore
{

	ServiceCounterDataType::ServiceCounterDataType(void)
	: Object()
	, totalCount_()
	, errorCount_()
	{
	}

	ServiceCounterDataType::~ServiceCounterDataType(void)
	{
	}

	OpcUaUInt32&
	ServiceCounterDataType::totalCount(void)
	{
		return totalCount_;
	}

	void
	ServiceCounterDataType::totalCount(OpcUaUInt32 totalCount)
	{
		totalCount_ = totalCount;
	}

	OpcUaUInt32&
	ServiceCounterDataType::errorCount(void)
	{
		return errorCount_;
	}

	void
	ServiceCounterDataType::errorCount(OpcUaUInt32 errorCount)
	{
		errorCount_ = errorCount;
	}

	void
	ServiceCounterDataType::copyTo(ServiceCounterDataType& serviceCounterDataType)
	{
		serviceCounterDataType.totalCount(totalCount_);
		serviceCounterDataType.errorCount(errorCount_);
	}

	bool
	ServiceCounterDataType::operator==(const ServiceCounterDataType& serviceCounterDataType) const
	{
		ServiceCounterDataType* dst = const_cast<ServiceCounterDataType*>(&serviceCounterDataType);
		return
			totalCount_ == dst->totalCount() &&
			errorCount_ == dst->errorCount();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	ServiceCounterDataType::factory(void)
	{
		return constructSPtr<ServiceCounterDataType>();
	}

	void
	ServiceCounterDataType::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, totalCount_);
		OpcUaNumber::opcUaBinaryEncode(os, errorCount_);
	}

	void
	ServiceCounterDataType::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, totalCount_);
		OpcUaNumber::opcUaBinaryDecode(is, errorCount_);
	}

	bool
	ServiceCounterDataType::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	ServiceCounterDataType::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	ServiceCounterDataType::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	void
	ServiceCounterDataType::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		ServiceCounterDataType* dst = dynamic_cast<ServiceCounterDataType*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	ServiceCounterDataType::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		ServiceCounterDataType* dst = dynamic_cast<ServiceCounterDataType*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	ServiceCounterDataType::out(std::ostream& os)
	{
		os << "TotalCount=" << totalCount_;
		os << ", ErrorCount=" << errorCount_;
	}

}

