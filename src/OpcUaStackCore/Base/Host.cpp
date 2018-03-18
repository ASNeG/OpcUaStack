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
#include "OpcUaStackCore/Base/Host.h"

namespace OpcUaStackCore
{

	Host::Host(void)
	: hostname_("")
	, ipAddressVec_()
	{
	}

	Host::Host(const std::string& hostname)
	: hostname_(hostname)
	, ipAddressVec_()
	{
		hostnameToAddress();
	}

	Host::~Host(void)
	{
	}

	void
	Host::hostname(const std::string& hostname)
	{
		hostname_ = hostname;
		hostnameToAddress();
	}

	std::string&
	Host::hostname(void)
	{
		return hostname_;
	}

	bool
	Host::isGood(void)
	{
		return !isBad();
	}

	bool
	Host::isBad(void)
	{
		return ipAddressVec_.size() == 0;
	}

	void
	Host::getIpAddressVec(IpAddressVec& ipAddressVec)
	{
		ipAddressVec = ipAddressVec_;
	}

	void
	Host::getIpv4AddressVec(IpAddressVec& ipAddressVec)
	{
		IpAddressVec::iterator it;
		for (it = ipAddressVec_.begin(); it != ipAddressVec_.end(); it++) {
			if (it->is_v4()) {
				ipAddressVec.push_back(*it);
			}
		}
	}

	void
	Host::getIpv6AddressVec(IpAddressVec& ipAddressVec)
	{
		IpAddressVec::iterator it;
		for (it = ipAddressVec_.begin(); it != ipAddressVec_.end(); it++) {
			if (it->is_v6()) {
				ipAddressVec.push_back(*it);
			}
		}
	}

	void
	Host::hostnameToAddress(void)
	{
		ipAddressVec_.clear();

		boost::asio::io_service io_service;

		try  {
			// setup resolver query
			boost::asio::ip::tcp::resolver resolver(io_service);
			boost::asio::ip::tcp::resolver::query query(hostname_, "");

			// prepare response iterator
			boost::asio::ip::tcp::resolver::iterator destination = resolver.resolve(query);
			boost::asio::ip::tcp::resolver::iterator end;

			// iterate through multiple response
			while (destination != end) {
				ipAddressVec_.push_back(destination->endpoint().address());
				destination++;
			}
		}
		catch (boost::system::system_error& error) {
			ipAddressVec_.clear();
		}

	}

}
