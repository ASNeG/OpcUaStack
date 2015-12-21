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

#ifndef __OpcUaStackCore_SecureChannel_h__
#define __OpcUaStackCore_SecureChannel_h__

#include "OpcUaStackCore/TCPChannel/TCPConnection.h"
#include "OpcUaStackCore/Utility/SlotTimer.h"
#include "OpcUaStackCore/SecureChannel/MessageHeader.h"

namespace OpcUaStackCore
{

	class SecureChannel
	: public TCPConnection
	{
	  public:
		SecureChannel(boost::asio::io_service& io_service);
		virtual ~SecureChannel(void);

		void debugReadHeader(void);
		void debugReadHello(void);
		void debugReadAcknowledge(void);
		void debugReadOpenSecureChannelRequest(void);
		void debugReadOpenSecureChannelResponse(void);
		void debugReadCloseSecureChannelRequest(void);
		void debugReadCloseSecureChannelResponse(void);

		OpcUaStackCore::SlotTimerElement::SPtr slotTimerElement_;

		bool closeFlag_;
		bool timeout_;
		bool debug_;
		boost::asio::streambuf recvBuffer_;
		boost::asio::streambuf sendBuffer_;
		boost::asio::ip::tcp::endpoint local_;
		boost::asio::ip::tcp::endpoint partner_;

		MessageHeader messageHeader_;
	};

}

#endif
