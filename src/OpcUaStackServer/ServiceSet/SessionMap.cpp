/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
	SessionMap::insert(OpcUaInt32 authenticationToken, SessionOld::SPtr session)
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

	SessionOld::SPtr
	SessionMap::get(OpcUaInt32 authenticationToken)
	{
		SessionElement::SPtr sessionElement = this->sessionElement(authenticationToken);
		if (sessionElement.get() != nullptr) {
			return sessionElement->session_;
		}

		SessionOld::SPtr session;
		return session;
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
