/*
   Copyright 2015-2021 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/SecureChannel/SecureChannelTransaction.h"

namespace OpcUaStackCore
{

	SecureChannelTransaction::SecureChannelTransaction(void)
	: is_()
	, os_()
	, requestTypeNodeId_()
	, responseTypeNodeId_()
	, requestId_(0)
	, cryptoBase_()
	{
	}

	SecureChannelTransaction::~SecureChannelTransaction(void)
	{
	}

	void
	SecureChannelTransaction::isAppend(boost::asio::streambuf& sb)
	{
		std::iostream ios(&is_);
		boost::asio::const_buffer buffer(sb.data());
		std::size_t bufferSize = boost::asio::buffer_size(buffer);
		const char* bufferPtr = boost::asio::buffer_cast<const char*>(buffer);
		ios.write(bufferPtr,bufferSize);
		sb.consume(bufferSize);
	}

	void
	SecureChannelTransaction::osAppend(boost::asio::streambuf& sb)
	{
		std::iostream ios(&os_);
		boost::asio::const_buffer buffer(sb.data());
		std::size_t bufferSize = boost::asio::buffer_size(buffer);
		const char* bufferPtr = boost::asio::buffer_cast<const char*>(buffer);
		ios.write(bufferPtr,bufferSize);
		sb.consume(bufferSize);
	}

}



