#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	SecureChannel::SecureChannel(IOService& ioService)
	: ioService_(&ioService) 
	, tcpConnection_(ioService.io_service())
	{
	}

	SecureChannel::~SecureChannel(void)
	{
	}
}