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

#include "OpcUaStackCore/Certificate/PkiCertificateInfo.h"

namespace OpcUaStackCore
{

	PkiCertificateInfo::PkiCertificateInfo(void)
    : URI_("")
    , ipAddresses_()
    , dnsNames_()
    , emails_()
    , validTime_(0)
	{
	}

	PkiCertificateInfo::~PkiCertificateInfo(void)
	{
	}

	void
	PkiCertificateInfo::URI(const std::string& URI)
	{
		URI_ = URI;
	}

	std::string&
	PkiCertificateInfo::URI(void)
	{
		return URI_;
	}

	void
	PkiCertificateInfo::ipAddresses(const std::vector<std::string>& ipAddresses)
	{
		ipAddresses_ = ipAddresses;
	}

	std::vector<std::string>&
	PkiCertificateInfo::ipAddresses(void)
	{
		return ipAddresses_;
	}

	void
	PkiCertificateInfo::dnsNames(const std::vector<std::string>& dnsNames)
	{
		dnsNames_ = dnsNames;
	}

	std::vector<std::string>&
	PkiCertificateInfo::dnsNames(void)
	{
		return dnsNames_;
	}

	void
	PkiCertificateInfo::email(const std::vector<std::string>& emails)
	{
		emails_ = emails;
	}

	std::vector<std::string>&
	PkiCertificateInfo::email(void)
	{
		return emails_;
	}

	void
	PkiCertificateInfo::validTime(const uint32_t validTime)
	{
		validTime_ = validTime;
	}

	uint32_t
	PkiCertificateInfo::validTime(void)
	{
		return validTime_;
	}

}



