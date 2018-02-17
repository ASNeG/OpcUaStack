/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   CertificateExtensionBasicrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include "OpcUaStackCore/Certificate/CertificateExtensionBasic.h"

namespace OpcUaStackCore
{

	CertificateExtensionBasic::CertificateExtensionBasic(void)
	: OpenSSLError()
	, basicConstraints_("critical, CA:FALSE")
	, nsComment_("\"Generated with ASNeG OpcUaStack using OpenSSL\"")
	, subjectKeyIdentifier_("hash")
	, authorityKeyIdentifier_("keyid, issuer:always")
	, keyUsage_("critical, nonRepudiation, digitalSignature, keyEncipherment, dataEncipherment, keyCertSign")
	, extendedKeyUsage_("critical, serverAuth,clientAuth")
	{
	}

	CertificateExtensionBasic::~CertificateExtensionBasic(void)
	{
	}

	void
	CertificateExtensionBasic::basicConstraints(const std::string& basicConstraints)
	{
		basicConstraints_ = basicConstraints;
	}

	std::string&
	CertificateExtensionBasic::basicConstraints(void)
	{
		return basicConstraints_;
	}

	void
	CertificateExtensionBasic::nsComment(const std::string& nsComment)
	{
		nsComment_ = nsComment;
	}

	std::string&
	CertificateExtensionBasic::nsComment(void)
	{
		return nsComment_;
	}

	void
	CertificateExtensionBasic::subjectKeyIdentifier(const std::string& subjectKeyIdentifier)
	{
		subjectKeyIdentifier_ = subjectKeyIdentifier;
	}

	std::string&
	CertificateExtensionBasic::subjectKeyIdentifier(void)
	{
		return subjectKeyIdentifier_;
	}

	void
	CertificateExtensionBasic::authorityKeyIdentifier(const std::string& authorityKeyIdentifier)
	{
		authorityKeyIdentifier_ = authorityKeyIdentifier;
	}

	std::string&
	CertificateExtensionBasic::authorityKeyIdentifier(void)
	{
		return authorityKeyIdentifier_;
	}

	void
	CertificateExtensionBasic::keyUsage(const std::string& keyUsage)
	{
		keyUsage_ = keyUsage;
	}

	std::string&
	CertificateExtensionBasic::keyUsage(void)
	{
		return keyUsage_;
	}

	void
	CertificateExtensionBasic::extendedKeyUsage(const std::string& extendedKeyUsage)
	{
		extendedKeyUsage_ = extendedKeyUsage;
	}

	std::string&
	CertificateExtensionBasic::extendedKeyUsage(void)
	{
		return extendedKeyUsage_;
	}

	bool
	CertificateExtensionBasic::encodeX509(X509 *cert, X509V3_CTX& ctx)
	{
		int32_t result;
		X509_EXTENSION* ext = nullptr;

		// set basic constrains
		ext = X509V3_EXT_conf(nullptr, &ctx, (char*)"basicConstraints", (char*)basicConstraints_.c_str());
		if (!ext) {
			addOpenSSLError();
			return false;
		}
		result = X509_add_ext(cert, ext, -1);
		if (!result) {
			addOpenSSLError();
		}
		X509_EXTENSION_free(ext);

		// set basic nsComment
		ext = X509V3_EXT_conf(nullptr, &ctx, (char*)"nsComment", (char*)nsComment_.c_str());
		if (!ext) {
			addOpenSSLError();
			return false;
		}
		result = X509_add_ext(cert, ext, -1);
		if (!result) {
			addOpenSSLError();
		}
		X509_EXTENSION_free(ext);

		// set basic subjectKeyIdentifier
		ext = X509V3_EXT_conf(nullptr, &ctx, (char*)"subjectKeyIdentifier", (char*)subjectKeyIdentifier_.c_str());
		if (!ext) {
			addOpenSSLError();
			return false;
		}
		result = X509_add_ext(cert, ext, -1);
		if (!result) {
			addOpenSSLError();
		}
		X509_EXTENSION_free(ext);

		// set basic authorityKeyIdentifier
		ext = X509V3_EXT_conf(nullptr, &ctx, (char*)"authorityKeyIdentifier", (char*)authorityKeyIdentifier_.c_str());
		if (!ext) {
			addOpenSSLError();
			return false;
		}
		result = X509_add_ext(cert, ext, -1);
		if (!result) {
			addOpenSSLError();
		}
		X509_EXTENSION_free(ext);

		// set basic keyUsage
		ext = X509V3_EXT_conf(nullptr, &ctx, (char*)"keyUsage", (char*)keyUsage_.c_str());
		if (!ext) {
			addOpenSSLError();
			return false;
		}
		result = X509_add_ext(cert, ext, -1);
		if (!result) {
			addOpenSSLError();
		}
		X509_EXTENSION_free(ext);

		// set basic extendedKeyUsage
		ext = X509V3_EXT_conf(nullptr, &ctx, (char*)"extendedKeyUsage", (char*)extendedKeyUsage_.c_str());
		if (!ext) {
			addOpenSSLError();
			return false;
		}
		result = X509_add_ext(cert, ext, -1);
		if (!result) {
			addOpenSSLError();
		}
		X509_EXTENSION_free(ext);

		return true;
	}

}
