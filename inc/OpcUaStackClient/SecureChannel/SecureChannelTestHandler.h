#ifndef __OpcUaStackClient_SecureChannelTestHandler_h__
#define __OpcUaStackClient_SecureChannelTestHandler_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackClient/Securechannel/SecureChannelIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class SecureChannelTestHandler : public SecureChannelIf
	{
	  public:
		SecureChannelTestHandler(void)
		: connectCount_(0)
		, connectCondition_()
		, disconnectCount_(0)
		, disconnectConndition_()
		{
		}

		void connect(void)
		{
			connectCondition_.conditionValueDec();
			connectCount_++;
		}

		void disconnect(void)
		{
			disconnectConndition_.conditionValueDec();
			disconnectCount_++;
		}

		uint32_t connectCount_;
		Condition connectCondition_;

		uint32_t disconnectCount_;
		Condition disconnectConndition_;
	};

}

#endif