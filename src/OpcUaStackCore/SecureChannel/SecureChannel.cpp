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

#include "OpcUaStackCore/Base/Utility.h"
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	SecureChannel::SecureChannel(boost::asio::io_service& io_service)
	: TCPConnection(io_service)
	, closeFlag_(false)
	, recvBuffer_()
	, sendBuffer_()
	, slotTimerElement_(SlotTimerElement::construct())
	, timeout_(false)
	, partner_()
	, local_()
	, debug_(false)
	, messageHeader_()
	{
	}

	SecureChannel::~SecureChannel(void)
	{
	}

	void
	SecureChannel::debugReadHeader(void)
	{
		if (!debug_) return;

		std::stringstream ss;
		std::iostream ios(&recvBuffer_);
		OpcUaStackCore::dumpHex(ios, ss);
		Log(Debug, "opc ua secure channel read header message")
			.parameter("Local", local_.address().to_string())
			.parameter("Partner", partner_.address().to_string())
			.parameter("Data", ss);
	}

	void
	SecureChannel::debugReadHello(void)
	{
		if (!debug_) return;

		std::stringstream ss;
		std::iostream ios(&recvBuffer_);
		OpcUaStackCore::dumpHex(ios, ss);
		Log(Debug, "opc ua secure channel read hello message")
			.parameter("Local", local_.address().to_string())
			.parameter("Partner", partner_.address().to_string())
			.parameter("Data", ss);
	}

	void
	SecureChannel::debugReadAcknowledge(void)
	{
		if (!debug_) return;

		std::stringstream ss;
		std::iostream ios(&recvBuffer_);
		OpcUaStackCore::dumpHex(ios, ss);
		Log(Debug, "opc ua secure channel read achonledge message")
			.parameter("Local", local_.address().to_string())
			.parameter("Partner", partner_.address().to_string())
			.parameter("Data", ss);
	}

}


