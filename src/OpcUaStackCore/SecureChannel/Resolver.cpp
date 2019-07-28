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

#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/SecureChannel/Resolver.h"

namespace OpcUaStackCore
{

	Resolver::Resolver(boost::asio::io_service& io_service)
	: std::enable_shared_from_this<Resolver>()
	, resolver_(io_service)
	{
	}

	Resolver::~Resolver(void)
	{
	}

	void
	Resolver::ipv4On(bool ipv4On)
	{
		ipv4On_ = ipv4On;
	}

	void
	Resolver::ipv6On(bool ipv6On)
	{
		ipv6On_ = ipv6On;
	}

	void
	Resolver::getAddrFromUrl(
		const std::string& urlString,
		ResponseCallback responseCallback
	)
	{
		// check url
		Url url(urlString);
		if (!url.good()) {
			Log(Error, "url invalid in address resolver")
			    .parameter("Url", urlString);
			boost::asio::ip::address addr;
			responseCallback(true, addr);
			return;
		}

		// get address from url
		auto self = shared_from_this();
		Log(Debug, "resolve host")
			.parameter("Host", url.host())
			.parameter("Port", url.portToString());
		boost::asio::ip::tcp::resolver::query query(url.host(), url.portToString());
		resolver_.async_resolve(
			query,
			[self, responseCallback, urlString, this](
				const boost::system::error_code& error,
				boost::asio::ip::tcp::resolver::iterator endpointIterator
			) {
				boost::asio::ip::address addr;

				// check error code
				if (error) {
					Log(Error, "address resolver error")
						.parameter("Url", urlString)
						.parameter("Message", error.message());
					responseCallback(true, addr);
					return;
				}

				// get address
				boost::asio::ip::tcp::resolver::iterator end;
				while (endpointIterator != end) {
					auto address = (*endpointIterator).endpoint().address();

					if (address.is_v4() && ipv4On_) {
						responseCallback(false, address);
						return;
					}

					if (address.is_v6() && ipv6On_) {
						responseCallback(false, address);
						return;
					}

					endpointIterator++;
				}

				Log(Error, "address resolver error")
					.parameter("Url", urlString)
					.parameter("Message", "no address found");
				responseCallback(true, addr);
			}
		);
	}

}
