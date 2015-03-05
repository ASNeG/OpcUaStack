#include "OpcUaStackServer/SecureChannel/SecureChannelTransaction.h"

namespace OpcUaStackServer
{

	SecureChannelTransaction::SecureChannelTransaction(void)
	: channelId_(0)
	, authenticationToken_(0)
	, is_()
	, os_()
	{
	}

	SecureChannelTransaction::~SecureChannelTransaction(void)
	{
	}

}
