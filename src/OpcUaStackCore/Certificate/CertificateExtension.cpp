/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   CertificateExtensionrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <OpcUaStackCore/Certificate/CertificateExtension.h>

namespace OpcUaStackCore
{

	CertificateExtension::CertificateExtension(void)
	: OpenSSLError()
	, basicConstraints_("critical, CA:FALSE")
	, nsComment_("\"Generated with ASNeG OpcUaStack using OpenSSL\"")
	, subjectKeyIdentifier_("hash")
	, authorityKeyIdentifier_("keyid, issuer:always")
	, keyUsage_("critical, nonRepudiation, digitalSignature, keyEncipherment, dataEncipherment, keyCertSign")
	, extendedKeyUsage_("critical, serverAuth,clientAuth")
	{
	}

	CertificateExtension::~CertificateExtension(void)
	{
	}

	void
	CertificateExtension::basicConstraints(const std::string& basicConstraints)
	{
		basicConstraints_ = basicConstraints;
	}

	std::string&
	CertificateExtension::basicConstraints(void)
	{
		return basicConstraints_;
	}

	void
	CertificateExtension::nsComment(const std::string& nsComment)
	{
		nsComment_ = nsComment;
	}

	std::string&
	CertificateExtension::nsComment(void)
	{
		return nsComment_;
	}

	void
	CertificateExtension::subjectKeyIdentifier(const std::string& subjectKeyIdentifier)
	{
		subjectKeyIdentifier_ = subjectKeyIdentifier;
	}

	std::string&
	CertificateExtension::subjectKeyIdentifier(void)
	{
		return subjectKeyIdentifier_;
	}

	void
	CertificateExtension::authorityKeyIdentifier(const std::string& authorityKeyIdentifier)
	{
		authorityKeyIdentifier_ = authorityKeyIdentifier;
	}

	std::string&
	CertificateExtension::authorityKeyIdentifier(void)
	{
		return authorityKeyIdentifier_;
	}

	void
	CertificateExtension::keyUsage(const std::string& keyUsage)
	{
		keyUsage_ = keyUsage;
	}

	std::string&
	CertificateExtension::keyUsage(void)
	{
		return keyUsage_;
	}

	void
	CertificateExtension::extendedKeyUsage(const std::string& extendedKeyUsage)
	{
		extendedKeyUsage_ = extendedKeyUsage;
	}

	std::string&
	CertificateExtension::extendedKeyUsage(void)
	{
		return extendedKeyUsage_;
	}

	bool
	CertificateExtension::encodeX509(X509 *cert, X509V3_CTX& ctx)
	{
		if (!encodeX509Extension(cert, ctx, "basicConstraints", basicConstraints_)) return false;
		if (!encodeX509Extension(cert, ctx, "nsComment", nsComment_)) return false;
		if (!encodeX509Extension(cert, ctx, "subjectKeyIdentifier", subjectKeyIdentifier_)) return false;
		if (!encodeX509Extension(cert, ctx, "authorityKeyIdentifier", authorityKeyIdentifier_)) return false;
		if (!encodeX509Extension(cert, ctx, "keyUsage", keyUsage_)) return false;
		if (!encodeX509Extension(cert, ctx, "extendedKeyUsage", extendedKeyUsage_)) return false;
		return true;
	}

	bool
	CertificateExtension::encodeX509Extension(X509 *cert, X509V3_CTX& ctx, const std::string& key, const std::string& value)
	{
		int32_t result;
		X509_EXTENSION* ext = nullptr;

		// set key value
		ext = X509V3_EXT_conf(nullptr, &ctx, (char*)key.c_str(), (char*)value.c_str());
		if (!ext) {
			addOpenSSLError();
			return false;
		}
		result = X509_add_ext(cert, ext, -1);
		if (!result) {
			addOpenSSLError();
			X509_EXTENSION_free(ext);
			return false;
		}

		X509_EXTENSION_free(ext);
		return true;

	}

}
