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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelBase.h"

namespace OpcUaStackCore
{

	SecureChannelBase::SecureChannelBase(SecureChannelType secureChannelType)
	: asyncWriteCount_(0)
	, secureChannelType_(secureChannelType)
	{
	}

	SecureChannelBase::~SecureChannelBase(void)
	{
	}

	void
	SecureChannelBase::asyncRead(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::handleReadHeader,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			8
		);
	}

	void
	SecureChannelBase::handleReadHeader(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		// error accurred
		if (error) {
			Log(Error, "opc ua secure channel read message header error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		// debug output
		secureChannel->debugReadHello();

		// decode message header
		std::iostream is(&secureChannel->recvBuffer_);
		secureChannel->messageHeader_.opcUaBinaryDecode(is);

		switch(secureChannel->messageHeader_.messageType())
		{
			case MessageType_Unknown:
			{
				Log(Error, "opc ua secure channel received unknown message type")
					.parameter("Local", secureChannel->local_.address().to_string())
					.parameter("Partner", secureChannel->partner_.address().to_string())
					.parameter("MessageType", secureChannel->messageHeader_.messageType());

				closeChannel(secureChannel, true);
				return;
			}
			case MessageType_Hello:
			{
				asyncReadHello(secureChannel);
				break;
			}
			case MessageType_Acknowledge:
			{
				asyncReadAcknowledge(secureChannel);
				break;
			}
			case MessageType_OpenSecureChannel:
			{
				if (secureChannelType_ == SCT_Client) {
					asyncReadOpenSecureChannelResponse(secureChannel);
				}
				else {
					asyncReadOpenSecureChannelRequest(secureChannel);
				}
				break;
			}
			case MessageType_CloseSecureChannel:
			{
				asyncReadCloseSecureChannel(secureChannel);
				break;
			}
#if 0
			case MessageType_Error:
			{
				handleReadMessageHeaderTypeError(messageHeader);
				break;
			}
			case MessageType_Message:
			{
				handleReadMessageHeaderTypeMessage(messageHeader);
				break;
			}
#endif
		}
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// hello message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadHello(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::handleReadHello,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::handleReadHello(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		// error accurred
		if (error) {
			Log(Error, "opc ua secure channel read hello message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		// debug output
		secureChannel->debugReadHello();

		std::iostream is(&secureChannel->recvBuffer_);
		HelloMessage hello;
		hello.opcUaBinaryDecode(is);

		handleReadHello(secureChannel, hello);
	}

	void
	SecureChannelBase::handleReadHello(SecureChannel* secureChannel, HelloMessage& hello)
	{
		Log(Error, "opc ua secure channel error, because handleReadHello no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());

	}

	void
	SecureChannelBase::asyncWriteHello(SecureChannel* secureChannel, HelloMessage& hello)
	{
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		hello.opcUaBinaryEncode(ios1);

		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);
		secureChannel->messageHeader_.messageType(MessageType_Hello);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);

		asyncWriteCount_++;
		secureChannel->async_write(
			sb2,
			sb1,
			boost::bind(
				&SecureChannelBase::handleWriteHelloComplete,
				this,
				boost::asio::placeholders::error,
				secureChannel
			)
		);
	}

	void
	SecureChannelBase::handleWriteHelloComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		asyncWriteCount_--;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// acknowledge message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadAcknowledge(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::handleReadAcknowledge,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::handleReadAcknowledge(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		// error accurred
		if (error) {
			Log(Error, "opc ua secure channel read hello message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		// debug output
		secureChannel->debugReadAcknowledge();

		std::iostream is(&secureChannel->recvBuffer_);
		AcknowledgeMessage acknowledge;
		acknowledge.opcUaBinaryDecode(is);

		handleReadAcknowledge(secureChannel, acknowledge);
	}

	void
	SecureChannelBase::handleReadAcknowledge(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge)
	{
		Log(Error, "opc ua secure channel error, because handleReadAcknowledge no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());
	}

	void
	SecureChannelBase::asyncWriteAcknowledge(SecureChannel* secureChannel, AcknowledgeMessage& acknowledge)
	{
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		acknowledge.opcUaBinaryEncode(ios1);

		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);
		secureChannel->messageHeader_.messageType(MessageType_Acknowledge);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);

		asyncWriteCount_++;
		secureChannel->async_write(
			sb2,
			sb1,
			boost::bind(
				&SecureChannelBase::handleWriteAcknowledgeComplete,
				this,
				boost::asio::placeholders::error,
				secureChannel
			)
		);
	}

	void
	SecureChannelBase::handleWriteAcknowledgeComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		asyncWriteCount_--;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpenSecureChannelRequest message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadOpenSecureChannelRequest(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::handleReadOpenSecureChannelRequest,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::handleReadOpenSecureChannelRequest(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		// error accurred
		if (error) {
			Log(Error, "opc ua secure channel read OpenSecureChannelRequest message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		// debug output
		secureChannel->debugReadOpenSecureChannelRequest();

		std::iostream is(&secureChannel->recvBuffer_);

		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(is, channelId);

		SecurityHeader securityHeader;
		securityHeader.opcUaBinaryDecode(is);

		SequenceHeader sequenceHeader;
		sequenceHeader.opcUaBinaryDecode(is);

		OpcUaNodeId typeIdRequest;
		typeIdRequest.opcUaBinaryDecode(is);

		OpenSecureChannelRequest openSecureChannelRequest;
		openSecureChannelRequest.opcUaBinaryDecode(is);
		consumeAll(secureChannel->recvBuffer_);

		handleReadOpenSecureChannelRequest(
			secureChannel,
			channelId,
			securityHeader,
			sequenceHeader,
			typeIdRequest,
			openSecureChannelRequest
		);
	}

	void
	SecureChannelBase::handleReadOpenSecureChannelRequest(
		SecureChannel* secureChannel,
		uint32_t channelId,
		SecurityHeader& securityHeader,
		SequenceHeader& sequenceHeader,
		OpcUaNodeId& typeIdRequest,
		OpenSecureChannelRequest& openSecureChannelRequest
	)
	{
		Log(Error, "opc ua secure channel error, because handleReadSecureChannelRequest no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());
	}

	void
	SecureChannelBase::asyncWriteOpenSecureChannelRequest(
		SecureChannel* secureChannel,
		uint32_t channelId,
		SecurityHeader& securityHeader,
		SequenceHeader& sequenceHeader,
		OpcUaNodeId& typeIdRequest,
		OpenSecureChannelRequest& openSecureChannelRequest
	)
	{
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		OpcUaNumber::opcUaBinaryEncode(ios1, channelId);

		securityHeader.opcUaBinaryEncode(ios1);

		sequenceHeader.opcUaBinaryEncode(ios1);

		typeIdRequest.opcUaBinaryEncode(ios1);

		openSecureChannelRequest.opcUaBinaryEncode(ios1);

		secureChannel->messageHeader_.messageType(MessageType_OpenSecureChannel);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);

		asyncWriteCount_++;
		secureChannel->async_write(
			sb2,
			sb1,
			boost::bind(
				&SecureChannelBase::handleWriteOpenSecureChannelRequestComplete,
				this,
				boost::asio::placeholders::error,
				secureChannel
			)
		);
	}

	void
	SecureChannelBase::handleWriteOpenSecureChannelRequestComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		asyncWriteCount_--;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpenSecureChannelResponse message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadOpenSecureChannelResponse(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::handleReadOpenSecureChannelResponse,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::handleReadOpenSecureChannelResponse(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		// error accurred
		if (error) {
			Log(Error, "opc ua secure channel read OpenSecureChannelResponse message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		// debug output
		secureChannel->debugReadOpenSecureChannelResponse();

		std::iostream is(&secureChannel->recvBuffer_);

		OpcUaUInt32 channelId;
		OpcUaNumber::opcUaBinaryDecode(is, channelId);

		SecurityHeader securityHeader;
		securityHeader.opcUaBinaryDecode(is);

		SequenceHeader sequenceHeader;
		sequenceHeader.opcUaBinaryDecode(is);

		OpcUaNodeId typeIdResponse;
		typeIdResponse.opcUaBinaryDecode(is);

		OpenSecureChannelResponse openSecureChannelResponse;
		openSecureChannelResponse.opcUaBinaryDecode(is);
		consumeAll(secureChannel->recvBuffer_);

		handleReadOpenSecureChannelResponse(
			secureChannel,
			channelId,
			securityHeader,
			sequenceHeader,
			typeIdResponse,
			openSecureChannelResponse
		);
	}

	void
	SecureChannelBase::handleReadOpenSecureChannelResponse(
		SecureChannel* secureChannel,
		uint32_t channelId,
		SecurityHeader& securityHeader,
		SequenceHeader& sequenceHeader,
		OpcUaNodeId& typeIdResponse,
		OpenSecureChannelResponse& openSecureChannelResponse
	)
	{
		Log(Error, "opc ua secure channel error, because handleReadSecureChannelResponse no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());
	}

	void
	SecureChannelBase::asyncWriteOpenSecureChannelResponse(
		SecureChannel* secureChannel,
		uint32_t channelId,
		SecurityHeader& securityHeader,
		SequenceHeader& sequenceHeader,
		OpcUaNodeId& typeIdResponse,
		OpenSecureChannelResponse& openSecureChannelResponse
	)
	{
		boost::asio::streambuf sb1;
		std::iostream ios1(&sb1);
		boost::asio::streambuf sb2;
		std::iostream ios2(&sb2);

		OpcUaNumber::opcUaBinaryEncode(ios1, channelId);

		securityHeader.opcUaBinaryEncode(ios1);

		sequenceHeader.opcUaBinaryEncode(ios1);

		typeIdResponse.opcUaBinaryEncode(ios1);

		openSecureChannelResponse.opcUaBinaryEncode(ios1);

		secureChannel->messageHeader_.messageType(MessageType_OpenSecureChannel);
		secureChannel->messageHeader_.messageSize(OpcUaStackCore::count(sb1)+8);
		secureChannel->messageHeader_.opcUaBinaryEncode(ios2);

		asyncWriteCount_++;
		secureChannel->async_write(
			sb2,
			sb1,
			boost::bind(
				&SecureChannelBase::handleWriteOpenSecureChannelResponseComplete,
				this,
				boost::asio::placeholders::error,
				secureChannel
			)
		);
	}

	void
	SecureChannelBase::handleWriteOpenSecureChannelResponseComplete(const boost::system::error_code& error, SecureChannel* secureChannel)
	{
		asyncWriteCount_--;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// CloseSecureChannel message
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::asyncReadCloseSecureChannel(SecureChannel* secureChannel)
	{
		secureChannel->async_read_exactly(
			secureChannel->recvBuffer_,
			boost::bind(
				&SecureChannelBase::handleReadCloseSecureChannel,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred,
				secureChannel
			),
			secureChannel->messageHeader_.messageSize() - 8
		);
	}

	void
	SecureChannelBase::handleReadCloseSecureChannel(
		const boost::system::error_code& error,
		std::size_t bytes_transfered,
		SecureChannel* secureChannel
	)
	{
		// error accurred
		if (error) {
			Log(Error, "opc ua secure channel read close secure channel message error; close channel")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel);
			return;
		}

		// partner has closed the connection
		if (bytes_transfered == 0) {
			Log(Debug, "opc ua secure channel is closed by partner")
				.parameter("Local", secureChannel->local_.address().to_string())
				.parameter("Partner", secureChannel->partner_.address().to_string());

			closeChannel(secureChannel, true);
			return;
		}

		// debug output
		secureChannel->debugReadCloseSecureChannelRequest();
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// channel functions
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	void
	SecureChannelBase::closeChannel(SecureChannel* secureChannel, bool close)
	{
		if (close) secureChannel->close();
		handleDisconnect(secureChannel);
	}

	void
	SecureChannelBase::handleDisconnect(SecureChannel* secureChannel)
	{
		Log(Error, "opc ua secure channel error, because handleDisconnect no implemented")
			.parameter("Local", secureChannel->local_.address().to_string())
			.parameter("Partner", secureChannel->partner_.address().to_string());
	}

	void
	SecureChannelBase::consumeAll(boost::asio::streambuf& streambuf)
	{
		boost::asio::const_buffer buffer(streambuf.data());
		std::size_t bufferSize = boost::asio::buffer_size(buffer);
		streambuf.consume(bufferSize);
	}

}
