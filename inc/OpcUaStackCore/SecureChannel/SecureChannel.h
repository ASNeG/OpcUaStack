#ifndef __OpcUaStackCore_SecureChannel_h__
#define __OpcUaStackCore_SecureChannel_h__
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/TCPChannel/TCPConnection.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannel
	{
	  public:
		SecureChannel(IOService& ioService);
		~SecureChannel(void);

	  private:
		IOService* ioService_;

	  protected:
		TCPConnection tcpConnection_;
		boost::asio::ip::address partnerAddress_;
		uint32_t partnerPort_;

	};

}

#endif