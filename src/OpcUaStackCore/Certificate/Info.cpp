/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <sstream>
#include "OpcUaStackCore/Certificate/Info.h"

namespace OpcUaStackCore
{

	Info::Info(void)
	: uri_("")
	, ipAddresses_()
	, dnsNames_()
	, eMail_("")
	, validTime_(0)
	, serialNumber_(0)
	, validFrom_(0)
	{
	}

	Info::~Info(void)
	{
	}

	void
	Info::uri(const std::string& uri)
	{
		uri_ = uri;
	}
	std::string&
	Info::uri(void)
	{
		return uri_;
	}

	void
	Info::ipAddresses(const std::vector<std::string>& ipAddresses)
	{
		ipAddresses_ = ipAddresses;
	}

	std::vector<std::string>&
	Info::ipAddresses(void)
	{
		return ipAddresses_;
	}

	void
	Info::dnsNames(const std::vector<std::string>& dnsNames)
	{
		dnsNames_ = dnsNames;
	}

	std::vector<std::string>&
	Info::dnsNames(void)
	{
		return dnsNames_;
	}

	void
	Info::eMail(const std::string& eMail)
	{
		eMail_ = eMail;
	}

	std::string&
	Info::eMail(void)
	{
		return eMail_;
	}

	void
	Info::validTime(uint32_t validTime)
	{
		validTime_ = validTime;
	}

	uint32_t
	Info::validTime(void)
	{
		return validTime_;
	}

	void
	Info::serialNumber(uint32_t serialNumber)
	{
		serialNumber_ = serialNumber;
	}

	uint32_t
	Info::serialNumber(void)
	{
		return serialNumber_;
	}

	void
	Info::validFrom(uint32_t validFrom)
	{
		validFrom_ = validFrom;
	}

	uint32_t
	Info::validFrom(void)
	{
		return validFrom_;
	}

	std::string
	Info::subjectAltName(void)
	{
		std::vector<std::string>::iterator it;
		std::stringstream ss;

		if (uri_.length() > 0) {
			ss << "URI:" << uri_;
		}
		for (it = dnsNames_.begin(); it != dnsNames_.end(); it++) {
			ss << ",DNS:" << *it;
		}
		for (it = ipAddresses_.begin(); it != ipAddresses_.end(); it++) {
			ss << ",IP:" << *it;
		}
		if (eMail_.length() > 0) {
			ss << ",email:" << eMail_;
		}

		return ss.str();
	}

}
