#ifndef __OpcUaStackServer_SecureChannelTransaction_h__
#define __OpcUaStackServer_SecureChannelTransaction_h__

#include <boost/shared_ptr.hpp>
#include <boost/asio/streambuf.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include <stdint.h>
#include <list>

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SecureChannelTransaction : public ObjectPool<SecureChannelTransaction> 
	{
	  public:
		typedef boost::shared_ptr<SecureChannelTransaction> SPtr;
		typedef std::list<SecureChannelTransaction::SPtr> List;

	    SecureChannelTransaction(void);
	    ~SecureChannelTransaction(void);

	    void isAppend(boost::asio::streambuf& sb);
	    void osAppend(boost::asio::streambuf& sb);

		OpcUaNodeId requestTypeNodeId_;
		OpcUaNodeId responseTypeNodeId_;
		uint32_t requestId_;
		OpcUaUInt32 channelId_;
		OpcUaUInt32 authenticationToken_;

		boost::asio::streambuf is_;
		boost::asio::streambuf os_;
	};

}

#endif
