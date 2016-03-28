/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include <openssl/err.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Certificate/PkiDsaKey.h"

namespace OpcUaStackCore
{

	PkiDsaKey::PkiDsaKey(void)
	: PkiError()
	{
	}

	PkiDsaKey::~PkiDsaKey(void)
	{
	}

	bool
	PkiDsaKey::createKey(uint32_t bits)
	{
	    return true;
	}

	bool
	PkiDsaKey::getPublicKey(PkiPublicKey& publicKey)
	{
		return publicKey.publicKey(key_);
	}

	bool
	PkiDsaKey::getPrivateKey(PkiPrivateKey& privateKey)
	{
		privateKey.privateKey(key_);
		return true;
	}

	bool
	PkiDsaKey::setPublicKey(PkiPublicKey& publicKey)
	{
		key_ = publicKey.publicKey();
		return true;
	}

	bool
	PkiDsaKey::setPrivateKey(PkiPrivateKey& privateKey)
	{
		key_ = privateKey.privateKey();
		return true;
	}

	bool
	PkiDsaKey::writePEMFile(const std::string& fileName, const std::string& password)
	{
		return true;
	}

	bool
	PkiDsaKey::readPEMFile(const std::string& fileName, const std::string& password)
	{
		return true;
	}

}




