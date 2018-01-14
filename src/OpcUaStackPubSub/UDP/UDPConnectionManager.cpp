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

	size_t UDPConnectionManager::RECV_BUFFER_SIZE = 512;

	UDPConnectionManager::UDPConnectionManager(void)
	: server_()
	, ioThread_(constructSPtr<IOThread>())
	, is_()
	{
	}

	UDPConnectionManager::~UDPConnectionManager(void)
	{
	}

	bool
	UDPConnectionManager::startup()
	{
		ioThread_->startup();

		server_.ioThread_(ioThread_);
		server_.endpoint({
				boost::asio::ip::address::from_string("127.0.0.1"),
				(unsigned short)4444
		});

		if (server_.open()) {
			server_.asyncReceive(is_, handleReadMessage);

			return true;
		}

		return false;
	}

	bool
	UDPConnectionManager::shutdown()
	{
		server_.close();
		ioThread_->shutdown();

		return false;
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

			(*it)->receive(networkMessage);
		}
	}
}


