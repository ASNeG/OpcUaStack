#include "OpcUaStackServer/SecureChannel/SecureChannelTransaction.h"

namespace OpcUaStackServer
{

	SecureChannelTransaction::SecureChannelTransaction(void)
	: channelId_(0)
	, authenticationToken_(0)
	{
	}

	SecureChannelTransaction::~SecureChannelTransaction(void)
	{
	}

}