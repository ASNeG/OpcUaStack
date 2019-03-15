/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpUaStackCore_SecureChannelConfig_h__
#define __OpUaStackCore_SecureChannelConfig_h__

#include "OpcUaStackCore/Base/Object.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaBaseEnums.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	class DLLEXPORT SecureChannelConfig
	: public Object
	{
	  public:
		typedef boost::shared_ptr<SecureChannelConfig> SPtr;

		SecureChannelConfig(void);
		SecureChannelConfig(const SecureChannelConfig& secureChannelConfig);
		virtual ~SecureChannelConfig(void);

		void receivedBufferSize(OpcUaUInt32 receivedBufferSize);
		OpcUaUInt32 receivedBufferSize(void);
		void sendBufferSize(OpcUaUInt32 sendBufferSize);
		OpcUaUInt32 sendBufferSize(void);
		void maxMessageSize(OpcUaUInt32 maxMessageSize);
		OpcUaUInt32 maxMessageSize(void);
		void maxChunkCount(OpcUaUInt32 maxChunkCount);
		OpcUaUInt32 maxChunkCount(void);

	  private:
		OpcUaUInt32 receivedBufferSize_;
		OpcUaUInt32 sendBufferSize_;
		OpcUaUInt32 maxMessageSize_;
		OpcUaUInt32 maxChunkCount_;
	};

}

#endif
