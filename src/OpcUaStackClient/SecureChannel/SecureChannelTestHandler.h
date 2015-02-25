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
		, receiveCount_(0)
		, receiveCondition_()
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

		void receive(OpcUaNodeId& nodeId, boost::asio::streambuf& sb)
		{
			std::iostream sbs(&sb);
			std::iostream sbt(&sb_);
			OpcUaStackCore::duplicate(sbs, sbt);
			OpcUaStackCore::clear(sbs);
			receiveCondition_.conditionValueDec();
			nodeId.copyTo(nodeId_);
			receiveCount_++;

		}

		uint32_t connectCount_;
		Condition connectCondition_;

		uint32_t disconnectCount_;
		Condition disconnectConndition_;

		uint32_t receiveCount_;
		Condition receiveCondition_;
		OpcUaNodeId nodeId_;
		boost::asio::streambuf sb_;
	};

}

#endif