#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"

namespace OpcUaStackCore
{

	const OpcUaUInt32 MessageDefaults::protocolVersionDefault_ = 0;
	const OpcUaUInt32 MessageDefaults::receivedBufferSizeDefault_ = 65536;
	const OpcUaUInt32 MessageDefaults::sendBufferSizeDefault_ = 65536;
	const OpcUaUInt32 MessageDefaults::maxMessageSizeDefault_ = 16777216;
	const OpcUaUInt32 MessageDefaults::maxChunkCountDefault_ = 5000;

}