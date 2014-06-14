#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"

namespace OpcUaStackCore
{

	const OpcUaUInt32 MessageDefaults::protocolVersionDefault_ = 1;
	const OpcUaUInt32 MessageDefaults::receivedBufferSizeDefault_ = 1000000;
	const OpcUaUInt32 MessageDefaults::sendBufferSizeDefault_ = 1000000;
	const OpcUaUInt32 MessageDefaults::maxMessageSizeDefault_ = 0;
	const OpcUaUInt32 MessageDefaults::maxChunkCountDefault_ = 0;

}