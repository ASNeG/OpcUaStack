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

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>
#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>
#include "OpcUaStackCore/Base/Url.h"

namespace OpcUaStackCore
{

	Url::Url(void)
	{
		clear();
	}

	Url::Url(const std::string& url)
	{
		clear();
		url_ = url;
		parse();
	}

	Url::~Url(void)
	{
	}

	void 
	Url::url(const std::string& url)
	{
		clear();
		url_ = url;
		parse();
	}

	bool
	Url::good(void)
	{
		return good_;
	}

	std::string
	Url::protocol(void) const
	{
		return protocol_;
	}

	void
	Url::protocol(const std::string& protocol)
	{
		protocol_ = protocol;
	}
		
	std::string 
	Url::host(void)
	{
		return host_;
	}

	void
	Url::host(const std::string& host)
	{
		host_ = host;
	}
		
	int32_t 
	Url::port(void)
	{
		return port_;
	}

	void
	Url::port(int32_t port)
	{
		port_ = port;
	}

	std::string
	Url::portToString(void)
	{
		std::stringstream ss;
		ss << port_;
		return ss.str();
	}

	std::string
	Url::path(void)
	{
		return path_;
	}

	void
	Url::path(const std::string& path)
	{
		path_ = path;
	}

	std::string 
	Url::query(void)
	{
		return query_;
	}

	void
	Url::query(const std::string& query)
	{
		query_ = query;
	}

	std::string
	Url::url(void)
	{
		std::stringstream ss;
		ss << protocol_ << "://" << host_;
		if (port_ != -1) {
			ss << ":" << port_;
		}
		if (path_ != "") {
			ss << "/" << path_;
		}
		if (query_ != "") {
			ss << "?" << query_;
		}

		return url_;
	}

	void 
	Url::clear(void)
	{
		good_ = true;
		url_ = "";
		protocol_ = "";
		host_ = "";
		port_ = -1;
		path_ = "";
		query_ = "";
	}

	bool
	Url::isLocalAddress(void)
	{
		// check localhost
		if (boost::to_upper_copy(host_) == "LOCALHOST") return true;

		// convert string to ip address
		boost::system::error_code ec;
		boost::asio::ip::address_v4 ipv4;
		ipv4 = boost::asio::ip::address_v4::from_string(host_, ec);
		if (ec) {
			return false;
		}

		// check ip address
		return ipv4.to_ulong() == 0x7f000001;
	}

	bool
	Url::isAnyAddress(void)
	{
		return host_ == "0.0.0.0";
	}

	bool
	Url::isIPAddress(void)
	{
		if (!boost::regex_match(host_, boost::regex("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}"))) {
			return false;
		}

		// convert string to ip address
		boost::system::error_code ec;
		boost::asio::ip::address_v4 ipv4;
		ipv4 = boost::asio::ip::address_v4::from_string(host_, ec);
		if (ec) {
			return false;
		}
		return true;
	}

	bool
	Url::isHostAddress(void)
	{
		return !isLocalAddress() && !isIPAddress();
	}

	bool
	Url::normalizeHost(void)
	{
		if (!boost::regex_match(host_, boost::regex("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}"))) {
			return false;
		}

		std::vector<std::string>::iterator it;
		std::vector<std::string> ipVec;
		boost::split(ipVec, host_, boost::is_any_of("."));

		for (uint32_t idx=0; idx<ipVec.size(); idx++) {
			std::string str = ipVec[idx];
			str.erase(0, str.find_first_not_of("0"));
			if (str.empty()) str = "0";
			ipVec[idx] = str;
		}

		host_ = boost::join(ipVec, ".");
		return true;
	}

	size_t
	Url::findString(const std::string& str, size_t pos)
	{
		size_t p = url_.find_first_of(str[0], pos);
		if (p == std::string::npos) {
			return std::string::npos;
		}

		if (p + str.length() > url_.length()) {
			return std::string::npos;
		}

		for (uint32_t idx=0; idx<str.length(); idx++) {
			if (url_[p+idx] != str[idx]) {
				return findString(str, p+1);
			}
		}

		return p;
	}
	  
	void
	Url::parse(void)
	{

		if (url_.length() == 0) {
			good_ = false;
			return;
		}

		// parse protocol
		size_t endProtocol = url_.find("://");
		if (endProtocol == std::string::npos) {
			endProtocol = 0;
		}
		else {
			protocol_ = url_.substr(0, endProtocol);
			endProtocol += 3;
		}

		// parse host
		if (endProtocol >= url_.length()) {
			good_ = false;
			return;
		}

		size_t beginHost = endProtocol;
		size_t endHost = url_.find_first_of(":", beginHost);
		if (endHost == std::string::npos) {
			endHost = url_.find_first_of("/", beginHost);
			if (endHost == std::string::npos) {
				endHost = url_.find_first_of("?", beginHost);
				if (endHost == std::string::npos) {
					host_ = url_.substr(beginHost);
					return;
				}
				else {
					host_ = url_.substr(beginHost, endHost-beginHost);
					endHost += 1;
				}
			}
			else {
				host_ = url_.substr(beginHost, endHost-beginHost);
				endHost += 1;
			}
		}
		else {
			host_ = url_.substr(beginHost, endHost-beginHost);
			endHost += 1;
		}

		// parse port
		size_t beginPort = endHost;
		size_t endPort;
		if (url_.substr(beginPort-1, 1) == ":") {
			endPort = url_.find_first_of("/", beginPort);
			if (endPort == std::string::npos) {
				endPort = url_.find_first_of("?", beginPort);
				if (endPort == std::string::npos) {
					try {
						port_ = boost::lexical_cast<int32_t>(url_.substr(beginPort));
					} catch(boost::bad_lexical_cast&) {
						good_ = false;
						return;
					}
					return;
				}
				else {
					try {
						port_ = boost::lexical_cast<int32_t>(url_.substr(beginPort, endPort-beginPort));
					} catch(boost::bad_lexical_cast&) {
						good_ = false;
						return;
					}
					endPort += 1;
				}
			}
			else {
				try {
					port_ = boost::lexical_cast<int32_t>(url_.substr(beginPort, endPort-beginPort));
				} catch(boost::bad_lexical_cast&) {
					good_ = false;
					return;
				}
				endPort += 1;
			}
		}
		else {
			endPort = beginPort;
		}

		// path
		size_t beginPath = endPort;
		size_t endPath;
		if (url_.substr(beginPath-1, 1) == "/") {
			endPath = url_.find_first_of("?", beginPath);
			if (endPath == std::string::npos) {
				path_ = url_.substr(beginPath);
				return;
			}
			else {
				path_ = url_.substr(beginPath, endPath-beginPath);
				endPath += 1;
			}
		}
		else {
			endPath = beginPath;
		}

		// parse query
		size_t beginQuery = endPath;
		query_ = url_.substr(beginQuery);

		normalizeHost();
	}

}
