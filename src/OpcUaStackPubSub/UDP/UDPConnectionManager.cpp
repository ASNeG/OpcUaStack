/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Aleksey Timin (atimin@gmail.com)
 */

#include <OpcUaStackPubSub/UDP/UDPConnectionManager.h>

namespace OpcUaStackPubSub
{

	UDPConnectionManager::UDPConnectionManager(void)
	: server_()
	, ioThread_(constructSPtr<IOThread>())
	, is_()
	, address_("127.0.0.1")
	, port_(4840)
	{
	}

	UDPConnectionManager::~UDPConnectionManager(void)
	{
	}

	void
	UDPConnectionManager::address(const std::string& address)
	{
		address_ = address;
	}

	std::string
	UDPConnectionManager::address() const
	{
		return address_;
	}

	void
	UDPConnectionManager::port(uint16_t port)
	{
		port_ = port;
	}

	uint16_t
	UDPConnectionManager::port() const
	{
		return port_;
	}

	bool
	UDPConnectionManager::startup()
	{
		ioThread_->startup();

		server_.ioThread(ioThread_);
		server_.endpoint(boost::asio::ip::udp::endpoint(
				boost::asio::ip::address::from_string(address_),
				port_
		));

		if (server_.open()) {
			boost::asio::mutable_buffers_1 buf = is_.prepare(512);
			server_.asyncReceive(buf, boost::bind(
							&UDPConnectionManager::handleReadMessage,
							this,
							boost::asio::placeholders::error,
							boost::asio::placeholders::bytes_transferred));

			return true;
		}

		return false;
	}

	bool
	UDPConnectionManager::shutdown()
	{
		server_.close();
		ioThread_->shutdown();

		return true;
	}

	void
	UDPConnectionManager::handleReadMessage(const boost::system::error_code& error, std::size_t bytes_transfered)
	{
		Log(Debug, "receive UDP network message")
					.parameter("Size", bytes_transfered);

		if (error) {
			Log(Error, "cannot read UDP network message")
				.parameter("ErrorMessage", error.message());
			return;
		}

		std::iostream is(&is_);


		NetworkMessage networkMessage;
		networkMessage.opcUaBinaryDecode(is);

		for (NetworkReceiverIf::Set::const_iterator it = receiverSet_.begin();
				it != receiverSet_.end(); ++it) {

			assert((*it)->receive(networkMessage));
		}
	}

}
