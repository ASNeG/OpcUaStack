/*
   Copyright 2019-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_Resolver_h__
#define __OpcUaStackCore_Resolver_h__

#include <boost/asio.hpp>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

	/**
	 * This class determines the IP address for a hostname.
	 */
	class DLLEXPORT Resolver
	: public std::enable_shared_from_this<Resolver>
	{
	  public:
		typedef std::shared_ptr<Resolver> SPtr;
		typedef std::function<void (
			bool error,
			const boost::asio::ip::address addr
		)> ResponseCallback;

		Resolver(
			boost::asio::io_service& io_service,
			const boost::shared_ptr<boost::asio::io_service::strand>& strand
		);
		~Resolver(void);

		void ipv6On(bool ipv6On);
		void ipv4On(bool ipv4On);
		void getAddrFromUrl(
			const std::string& urlString,
			ResponseCallback responseCallback
		);

	  private:
		void callResponseCallback(
			ResponseCallback responseCallback,
			bool error,
			const boost::asio::ip::address addr
		);

		boost::shared_ptr<boost::asio::io_service::strand> strand_;

		bool ipv4On_ = true;
		bool ipv6On_ = false;
		boost::asio::ip::tcp::resolver resolver_;
	};

}

#endif
