#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	SecureChannel::SecureChannel(IOService& ioService)
	: ioService_(&ioService) 
	, tcpConnection_(ioService.io_service())
	, partnerAddress_(boost::asio::ip::address::from_string("127.0.0.1"))
	, partnerPort_(4841)
	{
	}

	SecureChannel::~SecureChannel(void)
	{
	}
}