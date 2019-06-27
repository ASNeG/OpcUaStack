/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)

 */

#include "OpcUaStackCore/SecureChannel/SecureChannelConfig.h"
#include "OpcUaStackCore/SecureChannel/MessageDefaults.h"

namespace OpcUaStackCore
{


	SecureChannelConfig::SecureChannelConfig(void)
	: receivedBufferSize_(MessageDefaults::receivedBufferSizeDefault_)
	, sendBufferSize_(MessageDefaults::sendBufferSizeDefault_)
	, maxMessageSize_(MessageDefaults::maxMessageSizeDefault_)
	, maxChunkCount_(MessageDefaults::maxChunkCountDefault_)
	{
	}

	SecureChannelConfig::SecureChannelConfig(const SecureChannelConfig& secureChannelConfig)
	: receivedBufferSize_(secureChannelConfig.receivedBufferSize_)
	, sendBufferSize_(secureChannelConfig.sendBufferSize_)
	, maxMessageSize_(secureChannelConfig.maxMessageSize_)
	, maxChunkCount_(secureChannelConfig.maxChunkCount_)
	{
	}

	SecureChannelConfig::~SecureChannelConfig(void)
	{
	}

	void
	SecureChannelConfig::receivedBufferSize(OpcUaUInt32 receivedBufferSize)
	{
		receivedBufferSize_ = receivedBufferSize;
	}

	OpcUaUInt32
	SecureChannelConfig::receivedBufferSize(void)
	{
		return receivedBufferSize_;
	}

	void
	SecureChannelConfig::sendBufferSize(OpcUaUInt32 sendBufferSize)
	{
		sendBufferSize_ = sendBufferSize;
	}

	OpcUaUInt32
	SecureChannelConfig::sendBufferSize(void)
	{
		return sendBufferSize_;
	}

	void
	SecureChannelConfig::maxMessageSize(OpcUaUInt32 maxMessageSize)
	{
		maxMessageSize_ = maxMessageSize;
	}

	OpcUaUInt32
	SecureChannelConfig::maxMessageSize(void)
	{
		return maxMessageSize_;
	}

	void
	SecureChannelConfig::maxChunkCount(OpcUaUInt32 maxChunkCount)
	{
		maxChunkCount_ = maxChunkCount;
	}

	OpcUaUInt32
	SecureChannelConfig::maxChunkCount(void)
	{
		return maxChunkCount_;
	}

}
