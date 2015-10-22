/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
	: ObjectPool<BuildInfo>()
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

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensionObjectBase
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ExtensionObjectBase::BSPtr
	BuildInfo::factory(void)
	{
		return BuildInfo::construct();
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

	void
	BuildInfo::copyTo(ExtensionObjectBase& extensionObjectBase)
	{
		BuildInfo* dst = dynamic_cast<BuildInfo*>(&extensionObjectBase);
		if (dst == NULL) std::cout << "MIST" << std::endl;
		return;
		productUri_.copyTo(dst->productUri_);
		manufacturerName_.copyTo(dst->manufacturerName_);
		productName_.copyTo(dst->productName_);
		softwareVersion_.copyTo(dst->softwareVersion_);
		buildNumber_.copyTo(dst->buildNumber_);
		buildDate_.copyTo(dst->buildDate_);
	}

}


