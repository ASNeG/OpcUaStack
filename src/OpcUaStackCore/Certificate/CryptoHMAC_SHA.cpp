/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include <openssl/sha.h>
#include "OpcUaStackCore/Certificate/CryptoHMAC_SHA.h"

namespace OpcUaStackCore
{

	CryptoHMAC_SHA::CryptoHMAC_SHA(void)
	: OpenSSLError()
	, isLogging_(false)
	{
	}

	CryptoHMAC_SHA::~CryptoHMAC_SHA(void)
	{
	}

	void
	CryptoHMAC_SHA::isLogging(bool isLogging)
	{
		isLogging_ = isLogging;
	}

	bool
	CryptoHMAC_SHA::isLogging(void)
	{
		return isLogging_;
	}

}
