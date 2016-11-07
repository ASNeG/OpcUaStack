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

#include "OpcUaStackCore/Certificate/PkiCertificateInfo.h"

namespace OpcUaStackCore
{

	PkiCertificateInfo::PkiCertificateInfo(void)
    : validTimeNotBefore_(boost::posix_time::microsec_clock::universal_time())
    , validTimeNotAfter_()
	, version_(3)
	, serialNumber_(0)
	, URI_("")
    , ipAddresses_()
    , dnsNames_()
    , emails_()
	, extensionMap_()
	{
	}

	PkiCertificateInfo::~PkiCertificateInfo(void)
	{
	}

	void
	PkiCertificateInfo::validTimeNotAfter(const boost::posix_time::ptime& validTimeNotAfter)
	{
		validTimeNotAfter_ = validTimeNotAfter;
	}

	boost::posix_time::ptime&
	PkiCertificateInfo::validTimeNotAfter(void)
	{
		return validTimeNotAfter_;
	}

	void
	PkiCertificateInfo::validTimeNotBefore(const boost::posix_time::ptime& validTimeNotBefore)
	{
		validTimeNotBefore_ = validTimeNotBefore;
	}

	boost::posix_time::ptime&
	PkiCertificateInfo::validTimeNotBefore(void)
	{
		return validTimeNotBefore_;
	}

	void
	PkiCertificateInfo::version(uint32_t version)
	{
		version_ = version;
	}
    uint32_t
    PkiCertificateInfo::version(void)
    {
    	return version_;
    }

    void
    PkiCertificateInfo::serialNumber(uint32_t serialNumber)
    {
    	serialNumber_ = serialNumber;
    }

    uint32_t
    PkiCertificateInfo::serialNumber(void)
    {
    	return serialNumber_;
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

	PkiCertificateInfo::ExtensionMap&
	PkiCertificateInfo::extensionMap(void)
	{
		return extensionMap_;
	}

	bool
	PkiCertificateInfo::existExtension(const std::string& extName)
	{
		ExtensionMap::iterator it;
		it = extensionMap_.find(extName);
		if (it == extensionMap_.end()) return false;
		return true;
	}

	std::string
	PkiCertificateInfo::extension(const std::string& extName)
	{
		ExtensionMap::iterator it;
		it = extensionMap_.find(extName);
		if (it == extensionMap_.end()) return std::string("NotExist");
		return it->second;
	}

	bool
	PkiCertificateInfo::extension(const std::string& extName, const std::string& extValue)
	{
		ExtensionMap::iterator it;
		it = extensionMap_.find(extName);
		if (it != extensionMap_.end()) return false;
		extensionMap_.insert(std::make_pair(extName, extValue));
		return true;
	}

}



