/*
   Copyright 2015-2016 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/StandardDataTypes/BuildInfo.h"

namespace OpcUaStackCore
{

	BuildInfo::BuildInfo(void)
	: Object()
	, productUri_()
	, manufacturerName_()
	, productName_()
	, softwareVersion_()
	, buildNumber_()
	, buildDate_()
	{
	}

	BuildInfo::~BuildInfo(void)
	{
	}

	OpcUaString&
	BuildInfo::productUri(void)
	{
		return productUri_;
	}

	OpcUaString&
	BuildInfo::manufacturerName(void)
	{
		return manufacturerName_;
	}

	OpcUaString&
	BuildInfo::productName(void)
	{
		return productName_;
	}

	OpcUaString&
	BuildInfo::softwareVersion(void)
	{
		return softwareVersion_;
	}

	OpcUaString&
	BuildInfo::buildNumber(void)
	{
		return buildNumber_;
	}

	OpcUaDateTime&
	BuildInfo::buildDate(void)
	{
		return buildDate_;
	}

	void
	BuildInfo::copyTo(BuildInfo& buildInfo)
	{
		productUri_.copyTo(buildInfo.productUri_);
		manufacturerName_.copyTo(buildInfo.manufacturerName_);
		productName_.copyTo(buildInfo.productName_);
		softwareVersion_.copyTo(buildInfo.softwareVersion_);
		buildNumber_.copyTo(buildInfo.buildNumber_);
		buildDate_.copyTo(buildInfo.buildDate_);
	}

	bool
	BuildInfo::operator==(const BuildInfo& buildInfo) const
	{
		BuildInfo* dst = const_cast<BuildInfo*>(&buildInfo);
		return
			productUri_ == dst->productUri() &&
			manufacturerName_ == dst->manufacturerName() &&
			productName_ == dst->productName() &&
			softwareVersion_ == dst->softwareVersion() &&
			buildNumber_ == dst->buildNumber() &&
			buildDate_ == dst->buildDate();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::SPtr
	BuildInfo::factory(void)
	{
		return constructSPtr<BuildInfo>();
	}

	void
	BuildInfo::opcUaBinaryEncode(std::ostream& os) const
	{
		productUri_.opcUaBinaryEncode(os);
		manufacturerName_.opcUaBinaryEncode(os);
		productName_.opcUaBinaryEncode(os);
		softwareVersion_.opcUaBinaryEncode(os);
		buildNumber_.opcUaBinaryEncode(os);
		buildDate_.opcUaBinaryEncode(os);
	}

	void
	BuildInfo::opcUaBinaryDecode(std::istream& is)
	{
		productUri_.opcUaBinaryDecode(is);
		manufacturerName_.opcUaBinaryDecode(is);
		productName_.opcUaBinaryDecode(is);
		softwareVersion_.opcUaBinaryDecode(is);
		buildNumber_.opcUaBinaryDecode(is);
		buildDate_.opcUaBinaryDecode(is);
	}

	bool
	BuildInfo::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	BuildInfo::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	bool
	BuildInfo::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
	{
		// FIXME: todo
		return false;
	}

	void
	BuildInfo::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		BuildInfo* dst = dynamic_cast<BuildInfo*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	BuildInfo::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		BuildInfo* dst = dynamic_cast<BuildInfo*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	BuildInfo::out(std::ostream& os)
	{
		os << "ProductUri="; productUri_.out(os);
		os << ", ManufacturerName="; manufacturerName_.out(os);
		os << ", ProductName="; productName_.out(os);
		os << ", SoftwareVersion="; softwareVersion_.out(os);
		os << ", BuildNumber="; buildNumber_.out(os);
		os << ", BuildDate="; buildDate_.out(os);
	}

}


