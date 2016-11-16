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

#ifndef __OpcUaStackCore_SecureChannelOld_h__
#define __OpcUaStackCore_SecureChannelOld_h__
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/TCPChannel/TCPConnection.h"
#include "OpcUaStackCore/SecureChannel/HelloMessage.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"
#include "OpcUaStackCore/SecureChannel/SequenceHeader.h"

namespace OpcUaStackCore
{
	typedef HelloMessage ChannelDataBase;

	class DLLEXPORT SecureChannelOld
	{
	  public:
		SecureChannelOld(IOService& ioService);
		~SecureChannelOld(void);

		void debugMode(bool debugMode);
		ChannelDataBase::SPtr channelDataBase(void);
		TCPConnection& tcpConnection(void);

		void asyncReadMessageHeader(void);
		void handleReadMessageHeader(const boost::system::error_code& error, std::size_t bytes_transfered);
		virtual void handleReadMessageHeaderError(void) = 0;
		virtual void handleReadMessageHeaderTypeUnknown(MessageHeader& messageHeader);
		virtual void handleReadMessageHeaderTypeHello(MessageHeader& messageHeader);
		virtual void handleReadMessageHeaderTypeAcknowledge(MessageHeader& messageHeader);
		virtual void handleReadMessageHeaderTypeOpenSecureChannel(MessageHeader& messageHeader);
		virtual void handleReadMessageHeaderTypeCloseSecureChannel(MessageHeader& messageHeader);
		virtual void handleReadMessageHeaderTypeError(MessageHeader& messageHeader);
		virtual void handleReadMessageHeaderTypeMessage(MessageHeader& messageHeader);

	  protected:
		void consumeAll(boost::asio::streambuf& streambuf);
		bool debugMode_;

		IOService* ioService_;
		TCPConnection tcpConnection_;
		boost::asio::ip::address partnerAddress_;
		uint32_t partnerPort_;

		boost::asio::streambuf is_;
		ChannelDataBase::SPtr channelDataBaseSPtr_;

		OpcUaUInt32 channelId_;
		SequenceHeader sequenceHeader_;
	};

}

#endif
