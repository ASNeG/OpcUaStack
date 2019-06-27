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

#include "OpcUaStackCore/StandardDataTypes/StatusResult.h"

namespace OpcUaStackCore
{

	StatusResult::StatusResult(void)
	: Object()
	, statusCode_()
	, diagnosticInfo_()
	{
	}

	StatusResult::~StatusResult(void)
	{
	}

	OpcUaUInt32&
	StatusResult::statusCode(void)
	{
		return statusCode_;
	}

	void
	StatusResult::statusCode(OpcUaUInt32 statusCode)
	{
		statusCode_ = statusCode;
	}

	OpcUaDiagnosticInfo&
	StatusResult::diagnosticInfo(void)
	{
		return diagnosticInfo_;
	}

	void
	StatusResult::diagnosticInfo(OpcUaDiagnosticInfo diagnosticInfo)
	{
		diagnosticInfo_ = diagnosticInfo;
	}

	void
	StatusResult::copyTo(StatusResult& statusResult)
	{
		statusResult.statusCode(statusCode_);
		diagnosticInfo_.copyTo(statusResult.diagnosticInfo());
	}

	bool
	StatusResult::operator==(const StatusResult& statusResult) const
	{
		StatusResult* dst = const_cast<StatusResult*>(&statusResult);
		return
			statusCode_ == dst->statusCode(); // &&
			// FIXME: diagnosticInfo_ == dst->diagnosticInfo();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	StatusResult::factory(void)
	{
		return constructSPtr<StatusResult>();
	}

	void
	StatusResult::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, statusCode_);
		diagnosticInfo_.opcUaBinaryEncode(os);
	}

	void
	StatusResult::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, statusCode_);
		diagnosticInfo_.opcUaBinaryDecode(is);
	}

	bool
	StatusResult::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	StatusResult::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	StatusResult::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	void
	StatusResult::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		StatusResult* dst = dynamic_cast<StatusResult*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	StatusResult::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		StatusResult* dst = dynamic_cast<StatusResult*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	StatusResult::out(std::ostream& os)
	{
		os << "StatusCode=" << statusCode_;
		os << ", DiagnosticInfo="; diagnosticInfo_.out(os);
	}

}

