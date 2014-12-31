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
	}

	uint32_t 
	SecureChannelMap::size(void)
	{
		return secureChannelElementMap_.size();
	}

	bool 
	SecureChannelMap::insert(OpcUaInt32 channelId, SecureChannelServer::SPtr secureChannelServer)
	{
		SecureChannelElement::SPtr secureChannelElement = this->secureChannelElement(channelId);
		if (secureChannelElement.get() != nullptr) {
			Log(Error, "channel already exist in secure channel element map")
				.parameter("ChannelId", channelId);
			return false;
		}

		secureChannelElement = SecureChannelElement::construct();
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