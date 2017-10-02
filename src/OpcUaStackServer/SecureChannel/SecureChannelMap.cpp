/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/SecureChannel/SecureChannelMap.h"

namespace OpcUaStackServer
{

	SecureChannelMap::SecureChannelMap(void)
	: secureChannelElementMap_()
	{
	}
	
	SecureChannelMap::~SecureChannelMap(void)
	{
		secureChannelElementMap_.clear();
	}

	uint32_t 
	SecureChannelMap::size(void)
	{
		return secureChannelElementMap_.size();
	}

	bool 
	SecureChannelMap::insert(OpcUaInt32 channelId, SecureChannelServerOld::SPtr secureChannelServer)
	{
		SecureChannelElement::SPtr secureChannelElement = this->secureChannelElement(channelId);
		if (secureChannelElement.get() != nullptr) {
			Log(Error, "channel already exist in secure channel element map")
				.parameter("ChannelId", channelId);
			return false;
		}

		secureChannelElement = constructSPtr<SecureChannelElement>();
		secureChannelElement->channelId_ = channelId;
		secureChannelElement->secureChannelServer_ = secureChannelServer;
		secureChannelElement->secureChannelState_ = SecureChannelState_Init;
		secureChannelElementMap_.insert(std::make_pair(channelId, secureChannelElement));
		return true;
	}

	bool 
	SecureChannelMap::connect(OpcUaInt32 channelId)
	{
		SecureChannelElement::SPtr secureChannelElement = this->secureChannelElement(channelId);
		if (secureChannelElement.get() == nullptr) {
			Log(Error, "channel not exist in secure channel element map")
				.parameter("ChannelId", channelId);
			return false;
		}

		secureChannelElement->secureChannelState_ = SecureChannelState_Connect;
		return true;
	}

	bool 
	SecureChannelMap::disconnect(OpcUaInt32 channelId)
	{
		SecureChannelElement::SPtr secureChannelElement = this->secureChannelElement(channelId);
		if (secureChannelElement.get() == nullptr) {
			Log(Error, "channel not exist in secure channel element map")
				.parameter("ChannelId", channelId);
			return false;
		}

		secureChannelElementMap_.erase(channelId);
		return true;
	}

	SecureChannelServerOld::SPtr
	SecureChannelMap::get(OpcUaUInt32 channelId)
	{
		SecureChannelElement::SPtr secureChannelElement = this->secureChannelElement(channelId);
		if (secureChannelElement.get() != nullptr) {
			return secureChannelElement->secureChannelServer_;
		}

		SecureChannelServerOld::SPtr secureChannel;
		return secureChannel;
	}

	SecureChannelElement::SPtr 
	SecureChannelMap::secureChannelElement(OpcUaInt32 channelId)
	{
		SecureChannelElementMap::iterator it;
		it = secureChannelElementMap_.find(channelId);
		if (it != secureChannelElementMap_.end()) {
			return it->second;
		}

		SecureChannelElement::SPtr secureChannelElement;
		return secureChannelElement;
	}

}
