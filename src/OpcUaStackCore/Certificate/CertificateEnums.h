/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Certificatermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackCore_CertificateEnums_h__
#define __OpcUaStackCore_CertificateEnums_h__

#include <openssl/x509.h>

namespace OpcUaStackCore
{

	typedef enum
	{
		KeyType_RSA        = EVP_PKEY_RSA,
		KeyType_DSA        = EVP_PKEY_DSA,
		KeyType_Unknown    = EVP_PKEY_NONE
	} KeyType;

	typedef enum
	{
		Extension_SubjectAltName            = NID_subject_alt_name,
		Extension_BasicConstraints          = NID_basic_constraints,
		Extension_NetscapeComment           = NID_netscape_comment,
		Extension_SubjectKeyIdentifier      = NID_subject_key_identifier,
		Extension_AuthorityKeyIdentifier    = NID_authority_key_identifier,
		Extension_KeyUsage                  = NID_key_usage,
		Extension_ExtendedKeyUsage          = NID_ext_key_usage
	} CertificateExtensionId;

	typedef enum
	{
		SignatureAlgorithm_Sha1,
		SignatureAlgorithm_Sha256
	} SignatureAlgorithm;

}

#endif
