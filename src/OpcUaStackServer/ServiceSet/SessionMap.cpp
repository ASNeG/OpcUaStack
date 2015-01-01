#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/ServiceSet/SessionMap.h"

namespace OpcUaStackServer
{

	SessionMap::SessionMap(void)
	: sessionElementMap_()
	{
	}
		
	SessionMap::~SessionMap(void)
	{
		sessionElementMap_.clear();
	}

	uint32_t 
	SessionMap::size(void)
	{
		return sessionElementMap_.size();
	}

	bool 
	SessionMap::insert(OpcUaInt32 authenticationToken, Session::SPtr session)
	{
		SessionElement::SPtr sessionElement = this->sessionElement(authenticationToken);
		if (sessionElement.get() != nullptr) {
			Log(Error, "session already exist in sessionl element map")
				.parameter("AuthenticationToken", authenticationToken);
			return false;
		}

		sessionElement = SessionElement::construct();
		sessionElement->authenticationToken_ = authenticationToken;
		sessionElement->session_ = session;
		sessionElementMap_.insert(std::make_pair(authenticationToken, sessionElement));
		return true;
	}
		
	bool 
	SessionMap::remove(OpcUaInt32 authenticationToken)
	{
		SessionElement::SPtr secureChannelElement = this->sessionElement(authenticationToken);
		if (secureChannelElement.get() == nullptr) {
			Log(Error, "session not exist in session element map")
				.parameter("AuthenticationToken", authenticationToken);
			return false;
		}

		sessionElementMap_.erase(authenticationToken);
		return true;
	}

	SessionElement::SPtr 
	SessionMap::sessionElement(OpcUaInt32 authenticationToken)
	{
		SessionElementMap::iterator it;
		it = sessionElementMap_.find(authenticationToken);
		if (it != sessionElementMap_.end()) {
			return it->second;
		}

		SessionElement::SPtr sessionElement;
		return sessionElement;
	}
}