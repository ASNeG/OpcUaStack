/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/StandardDataTypes/Argument.h"

namespace OpcUaStackCore
{

	Argument::Argument(void)
	: Object()
	, productUri_()
	, manufacturerName_()
	, productName_()
	, softwareVersion_()
	, buildNumber_()
	, buildDate_()
	{
	}

	Argument::~Argument(void)
	{
	}

	OpcUaString&
	Argument::productUri(void)
	{
		return productUri_;
	}

	OpcUaString&
	Argument::manufacturerName(void)
	{
		return manufacturerName_;
	}

	OpcUaString&
	Argument::productName(void)
	{
		return productName_;
	}

	OpcUaString&
	Argument::softwareVersion(void)
	{
		return softwareVersion_;
	}

	OpcUaString&
	Argument::buildNumber(void)
	{
		return buildNumber_;
	}

	OpcUaDateTime&
	Argument::buildDate(void)
	{
		return buildDate_;
	}

	void
	Argument::copyTo(Argument& buildInfo)
	{
		productUri_.copyTo(buildInfo.productUri_);
		manufacturerName_.copyTo(buildInfo.manufacturerName_);
		productName_.copyTo(buildInfo.productName_);
		softwareVersion_.copyTo(buildInfo.softwareVersion_);
		buildNumber_.copyTo(buildInfo.buildNumber_);
		buildDate_.copyTo(buildInfo.buildDate_);
	}

	bool
	Argument::operator==(const Argument& buildInfo) const
	{
		Argument* dst = const_cast<Argument*>(&buildInfo);
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
	ExtensionObjectBase::BSPtr
	Argument::factory(void)
	{
		return constructSPtr<Argument>();
	}

	void
	Argument::opcUaBinaryEncode(std::ostream& os) const
	{
		productUri_.opcUaBinaryEncode(os);
		manufacturerName_.opcUaBinaryEncode(os);
		productName_.opcUaBinaryEncode(os);
		softwareVersion_.opcUaBinaryEncode(os);
		buildNumber_.opcUaBinaryEncode(os);
		buildDate_.opcUaBinaryEncode(os);
	}

	void
	Argument::opcUaBinaryDecode(std::istream& is)
	{
		productUri_.opcUaBinaryDecode(is);
		manufacturerName_.opcUaBinaryDecode(is);
		productName_.opcUaBinaryDecode(is);
		softwareVersion_.opcUaBinaryDecode(is);
		buildNumber_.opcUaBinaryDecode(is);
		buildDate_.opcUaBinaryDecode(is);
	}

	void
	Argument::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		Argument* dst = dynamic_cast<Argument*>(&extensionObjectBase);
		copyTo(*dst);
	}

	bool
	Argument::equal(ExtensionObjectBase& extensionObjectBase) const
	{
		Argument* dst = dynamic_cast<Argument*>(&extensionObjectBase);
		return *this == *dst;
	}

	void
	Argument::out(std::ostream& os)
	{
		os << "ProductUri="; productUri_.out(os);
		os << ", ManufacturerName="; manufacturerName_.out(os);
		os << ", ProductName="; productName_.out(os);
		os << ", SoftwareVersion="; softwareVersion_.out(os);
		os << ", BuildNumber="; buildNumber_.out(os);
		os << ", BuildDate="; buildDate_.out(os);
	}

}


