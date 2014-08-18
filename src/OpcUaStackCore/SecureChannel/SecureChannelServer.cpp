#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"

namespace OpcUaStackCore
{

	SecureChannelServer::SecureChannelServer(IOService& ioService)
	: SecureChannel(ioService)
	{
	}

	SecureChannelServer::~SecureChannelServer(void)
	{
	}

}