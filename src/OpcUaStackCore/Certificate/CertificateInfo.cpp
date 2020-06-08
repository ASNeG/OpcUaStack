/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   CertificateInformationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/algorithm/string.hpp>
#include <sstream>
#include "OpcUaStackCore/Certificate/CertificateInfo.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	CertificateInfo::CertificateInfo(void)
	: uri_("")
	, ipAddresses_()
	, dnsNames_()
	, eMail_("")
	, validTime_(boost::posix_time::microsec_clock::universal_time())
	, serialNumber_(0)
	, validFrom_(boost::posix_time::microsec_clock::universal_time())
	, keyUsage_("")
	{
	}

	CertificateInfo::~CertificateInfo(void)
	{
	}

	void
	CertificateInfo::clear(void)
	{
		uri_ = "";
		ipAddresses_.clear();
		dnsNames_.clear();
		eMail_ = "";
		validTime_ = boost::posix_time::microsec_clock::universal_time();
		serialNumber_ = 0;
		validFrom_ = boost::posix_time::microsec_clock::universal_time();
	}

	void
	CertificateInfo::uri(const std::string& uri)
	{
		uri_ = uri;
	}
	std::string&
	CertificateInfo::uri(void)
	{
		return uri_;
	}

	void
	CertificateInfo::ipAddresses(const std::vector<std::string>& ipAddresses)
	{
		ipAddresses_ = ipAddresses;
	}

	std::vector<std::string>&
	CertificateInfo::ipAddresses(void)
	{
		return ipAddresses_;
	}

	void
	CertificateInfo::dnsNames(const std::vector<std::string>& dnsNames)
	{
		dnsNames_ = dnsNames;
	}

	std::vector<std::string>&
	CertificateInfo::dnsNames(void)
	{
		return dnsNames_;
	}

	void
	CertificateInfo::eMail(const std::string& eMail)
	{
		eMail_ = eMail;
	}

	std::string&
	CertificateInfo::eMail(void)
	{
		return eMail_;
	}

	void
	CertificateInfo::validTime(boost::posix_time::ptime validTime)
	{
		validTime_ = validTime;
	}

	boost::posix_time::ptime
	CertificateInfo::validTime(void)
	{
		return validTime_;
	}

	void
	CertificateInfo::serialNumber(uint32_t serialNumber)
	{
		serialNumber_ = serialNumber;
	}

	uint32_t
	CertificateInfo::serialNumber(void)
	{
		return serialNumber_;
	}

	void
	CertificateInfo::validFrom(boost::posix_time::ptime validFrom)
	{
		validFrom_ = validFrom;
	}

	boost::posix_time::ptime
	CertificateInfo::validFrom(void)
	{
		return validFrom_;
	}

	void
	CertificateInfo::keyUsage(const std::string& keyUsage)
	{
		keyUsage_ = keyUsage;
	}

	std::string&
	CertificateInfo::keyUsage(void)
	{
		return keyUsage_;
	}

	void
	CertificateInfo::subjectAltName(const std::string& subjectAltName)
	{
		// split subject alt name
		std::vector<std::string> strVec;
		boost::split(strVec, subjectAltName, boost::is_any_of(","));

		// read parameter
		for (auto it = strVec.begin(); it != strVec.end(); it++) {
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
	CertificateInfo::subjectAltName(void)
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

	void
	CertificateInfo::log(const std::string& message)
	{
		std::string ipAddresses = "";
		for (auto ipAddress : ipAddresses_) {
			if (!ipAddresses.empty()) {
				ipAddresses += ",";
			}
			ipAddresses += ipAddress;
		}

		std::string dnsNames = "";
		for (auto dnsName : dnsNames_) {
			if (!dnsNames.empty()) {
				dnsNames += ",";
			}
			dnsNames += dnsName;
		}

		Log(Debug, message)
		    .parameter("Uri", uri_)
			.parameter("IPAdresses", ipAddresses)
			.parameter("DNSNames", dnsNames)
			.parameter("EMail", eMail_)
			.parameter("ValidTime", validTime_)
			.parameter("ValidFrom", validFrom_)
			.parameter("SerialNumber", serialNumber_);
	}

}
