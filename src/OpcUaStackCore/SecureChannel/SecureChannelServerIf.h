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

#ifndef __OpUaStackCore_SecureChannelServerIf_h__
#define __OpUaStackCore_SecureChannelServerIf_h__

#include "OpcUaStackCore/SecureChannel/SecureChannel.h"

namespace OpcUaStackCore
{

	class SecureChannelServerIf
	{
	  public:
		SecureChannelServerIf(void) {}
		virtual ~SecureChannelServerIf(void) {}

		virtual void handleConnect(SecureChannel* secureChannel) = 0;
		virtual void handleDisconnect(SecureChannel* secureChannel) = 0;
		virtual void handleMessageRequest(SecureChannel* secureChannel) = 0;
	};

}

#endif

