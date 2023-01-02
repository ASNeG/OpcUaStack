/*
   Copyright 2022-2023 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_UserExtensionOpenSSL_h__
#define __OpcUaStackCore_UserExtensionOpenSSL_h__

#include <boost/shared_ptr.hpp>

#include <string>
#include <vector>
#include <map>

#include <openssl/x509.h>

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Certificate/UserExtension.h"
#include "OpcUaStackCore/Certificate/OpenSSLError.h"

namespace OpcUaStackCore
{

	class DLLEXPORT UserExtensionOpenSSL
	: public UserExtension
	, public OpenSSLError
	{
	  public:
		using SPtr = boost::shared_ptr<UserExtensionOpenSSL>;

		UserExtensionOpenSSL(uint32_t nid = 0);
		virtual ~UserExtensionOpenSSL(void);

		bool encodeX509UserExtension(X509 *cert);
		bool decodeX509UserExtension(X509 *cert);

		bool encodeX509UserExtension(X509_REQ *req, STACK_OF(X509_EXTENSION)* exts);
		bool decodeX509UserExtension(X509_REQ *req);

	  private:
		X509_EXTENSION *ex_ = nullptr;

		bool encodeExtensionData(void) override;
		bool decodeExtensionData(void) override;
	};

}

#endif
