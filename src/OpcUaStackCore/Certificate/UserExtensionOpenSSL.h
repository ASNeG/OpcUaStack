/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

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

namespace OpcUaStackCore
{

	class DLLEXPORT UserExtensionOpenSSL
	: public UserExtension
	{
	  public:
		UserExtensionOpenSSL(void);
		virtual ~UserExtensionOpenSSL(void);

		void setExtension(X509_EXTENSION* ex);
		X509_EXTENSION* getExtension(void);

		bool encodeExtention(void) override;
		bool decodeExtention(void) override;

	  private:
		X509_EXTENSION *ex_ = nullptr;
	};

}

#endif
