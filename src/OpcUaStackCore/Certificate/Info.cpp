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

#include <boost/algorithm/string.hpp>
#include <sstream>
#include "OpcUaStackCore/Certificate/Info.h"

namespace OpcUaStackCore
{

	Info::Info(void)
	: uri_("")
	, ipAddresses_()
	, dnsNames_()
	, eMail_("")
	, validTime_(boost::posix_time::microsec_clock::local_time())
	, serialNumber_(0)
	, validFrom_(boost::posix_time::microsec_clock::local_time())
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
	Info::validTime(boost::posix_time::ptime validTime)
	{
		validTime_ = validTime;
	}

	boost::posix_time::ptime
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
	Info::validFrom(boost::posix_time::ptime validFrom)
	{
		validFrom_ = validFrom;
	}

	boost::posix_time::ptime
	Info::validFrom(void)
	{
		return validFrom_;
	}

	void
	Info::subjectAltName(const std::string& subjectAltName)
	{
		// split subject alt name
		std::vector<std::string> strVec;
		boost::split(strVec, subjectAltName, boost::is_any_of(","));

		// read parameter
		std::vector<std::string>::iterator it;
		for (it = strVec.begin(); it != strVec.end(); it++) {
			std::string str = *it;
			boost::algorithm::trim(str);

			size_t pos;
			pos = str.find_first_of(':');
			if (pos == std::string::npos) {
				continue;
			}

			std::string key = str.substr(0, pos);
			std::string value = str.substr(pos+1);

			if (key == "URI") {
				uri_ = value;
			}
			else if (key == "DNS") {
				dnsNames_.push_back(value);
			}
			else if (key == "IP Address") {
				ipAddresses_.push_back(value);
			}
			else if (key == "email") {
				eMail_= value;
			}
		}
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
