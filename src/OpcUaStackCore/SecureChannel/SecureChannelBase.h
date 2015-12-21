/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf modbusTCPMaster://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)

 */

#ifndef __OpUaStackCore_SecureChannelBase_h__
#define __OpUaStackCore_SecureChannelBase_h__

#include "OpcUaStackCore/SecureChannel/SecureChannel.h"
#include "OpcUaStackCore/SecureChannel/HelloMessage.h"

namespace OpcUaStackCore
{

	class SecureChannelBase
	{
	  public:
		SecureChannelBase(void);
		virtual ~SecureChannelBase(void);

		virtual void handleDisconnect(SecureChannel* secureChannel) = 0;
		virtual void handleReadHello(SecureChannel* secureChannel, HelloMessage& hello) = 0;

	  private:
		void asyncRead(SecureChannel* secureChannel);
		void asyncReadHello(SecureChannel* secureChannel);

		void handleReadHeader(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel);
		void handleReadHello(const boost::system::error_code& error, std::size_t bytes_transfered, SecureChannel* secureChannel);

		void closeChannel(SecureChannel* secureChannel, bool close = false);
	};

}

#endif
