
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

#include "OpcUaStackCore/SecureChannel/SecureChannelServerConfig.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecureChannelServerConfig
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecureChannelServerConfig::SecureChannelServerConfig(void)
	: SecureChannelConfig()
	, endpointDescriptionArray_()
	, endpointDescription_()
	, endpointUrl_("")
	, cryptoManager_()

	, secureChannelLog_(false)
	{
	}

	SecureChannelServerConfig::~SecureChannelServerConfig(void)
	{
	}

	void
	SecureChannelServerConfig::endpointDescriptionArray(EndpointDescriptionArray::SPtr& endpointDescriptionArray)
	{
		endpointDescriptionArray_ = endpointDescriptionArray;
	}

	EndpointDescriptionArray::SPtr&
	SecureChannelServerConfig::endpointDescriptionArray(void)
	{
		return endpointDescriptionArray_;
	}

	void
	SecureChannelServerConfig::endpointDescription(EndpointDescription::SPtr& endpointDescription)
	{
		endpointDescription_ = endpointDescription;
	}

	EndpointDescription::SPtr&
	SecureChannelServerConfig::endpointDescription(void)
	{
		return endpointDescription_;
	}

	void
	SecureChannelServerConfig::endpointUrl(const std::string& endpointUrl)
	{
		endpointUrl_ = endpointUrl;
	}

	std::string&
	SecureChannelServerConfig::endpointUrl(void)
	{
		return endpointUrl_;
	}

	void
	SecureChannelServerConfig::cryptoManager(CryptoManager::SPtr& cryptoManager)
	{
		cryptoManager_ = cryptoManager;
	}

	CryptoManager::SPtr&
	SecureChannelServerConfig::cryptoManager(void)
	{
		return cryptoManager_;
	}

	void
	SecureChannelServerConfig::secureChannelLog(bool secureChannelLog)
	{
		secureChannelLog_ = secureChannelLog;
	}

	bool
	SecureChannelServerConfig::secureChannelLog(void)
	{
		return secureChannelLog_;
	}

}
