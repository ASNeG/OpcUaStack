/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include <iostream>
#include <OpcUaStackCore/Certificate/CertificateExtension.h>

namespace OpcUaStackCore
{

	CertificateExtension::CertificateExtension(bool useCACert)
	: OpenSSLError()
	, useCACert_(useCACert)
	, basicConstraints_("")
	, nsComment_("")
	, subjectKeyIdentifier_("")
	, authorityKeyIdentifier_("")
	, keyUsage_("")
	, extendedKeyUsage_("")
	, subjectAltName_("")
	{
		if (useCACert_) {
		    basicConstraints_ = "critical, CA:TRUE";
		    nsComment_ = "\"CA certificate generated with ASNeG OpcUaStack using OpenSSL\"";
		    keyUsage_ = "critical, nonRepudiation, digitalSignature, keyEncipherment, keyCertSign, cRLSign";
		    extendedKeyUsage_ = "critical, serverAuth,clientAuth";
		    subjectKeyIdentifier_ = "hash";
		}
		else {
			basicConstraints_ = "critical, CA:FALSE";
			nsComment_ = "\"Generated with ASNeG OpcUaStack using OpenSSL\"";
			subjectKeyIdentifier_ = "hash";
			authorityKeyIdentifier_ = "keyid, issuer:always";
			keyUsage_ = "critical, nonRepudiation, digitalSignature, keyEncipherment, dataEncipherment, keyCertSign";
			extendedKeyUsage_ = "critical, serverAuth,clientAuth";
		}
	}

	CertificateExtension::~CertificateExtension(void)
	{
	}

	void
	CertificateExtension::clear(void)
	{
		basicConstraints_ = "";
		nsComment_ = "";
		subjectKeyIdentifier_ = "";
		authorityKeyIdentifier_ = "";
		keyUsage_ = "";
		extendedKeyUsage_ = "";
		subjectAltName_ = "";
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

	void
	CertificateExtension::subjectAltName(const std::string& subjectAltName)
	{
		subjectAltName_ = subjectAltName;
	}

	std::string&
	CertificateExtension::subjectAltName(void)
	{
		return subjectAltName_;
	}

	bool
	CertificateExtension::encodeX509(X509 *cert, X509V3_CTX& ctx)
	{
		if (!encodeX509Extension(cert, ctx, "basicConstraints", basicConstraints_)) {
			addError("encode NID_basic_constraints error");
			return false;
		}
		if (!encodeX509Extension(cert, ctx, "nsComment", nsComment_)) {
			addError("encode NID_netscape_comment error");
			return false;
		}
		if (!encodeX509Extension(cert, ctx, "keyUsage", keyUsage_)) {
			addError("encode NID_key_usage error");
			return false;
		}
		if (!encodeX509Extension(cert, ctx, "subjectKeyIdentifier", subjectKeyIdentifier_)) {
			addError("encode NID_subject_key_identifier error");
			return false;
		}

		if (!useCACert_) {
			if (!encodeX509Extension(cert, ctx, "extendedKeyUsage", extendedKeyUsage_)) {
				addError("encode NID_ext_key_usage error");
				return false;
			}
			if (!encodeX509Extension(cert, ctx, "authorityKeyIdentifier", authorityKeyIdentifier_)) {
				addError("encode NID_authority_key_identifier error");
				return false;
			}
			if (!encodeX509Extension(cert, ctx, "subjectAltName", subjectAltName_)) {
				addError("encode NID_subject_alt_name error");
				return false;
			}
		}

		return true;
	}

	bool
	CertificateExtension::decodeX509(X509 *cert)
	{
		clear();

		if (!decodeX509Extension(cert, NID_basic_constraints, basicConstraints_)) {
			addError("decode NID_basic_constraints error");
			return false;
		}
		if (!decodeX509Extension(cert, NID_netscape_comment, nsComment_, false)) {
			addError("decode NID_netscape_comment error");
			return false;
		}
		if (!decodeX509Extension(cert, NID_key_usage, keyUsage_)) {
			addError("decode NID_key_usage error");
			return false;
		}
		if (!decodeX509Extension(cert, NID_subject_key_identifier, subjectKeyIdentifier_)) {
			addError("decode NID_subject_key_identifier error");
			return false;
		}

		if (!useCACert_) {
			if (!decodeX509Extension(cert, NID_ext_key_usage, extendedKeyUsage_)) {
				addError("decode NID_ext_key_usage error");
				return false;
			}
			if (!decodeX509Extension(cert, NID_authority_key_identifier, authorityKeyIdentifier_)) {
				addError("decode NID_authority_key_identifier error");
				return false;
			}
			if (!decodeX509Extension(cert, NID_subject_alt_name, subjectAltName_)) {
				addError("decode NID_subject_alt_name error");
				return false;
			}
		}

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

	bool
	CertificateExtension::decodeX509Extension(X509 *cert, int32_t key, std::string& value, bool mandatory)
	{
	    int32_t pos = X509_get_ext_by_NID(cert, key, -1);
		if (pos < 0) {
			if (!mandatory) {
				value = "";
				return true;
			}
			addOpenSSLError();
			return false;
		}

		X509_EXTENSION* ext = X509_get_ext(cert, pos);
		BIO* bio = BIO_new (BIO_s_mem());
		int32_t result = X509V3_EXT_print(bio, ext, 0, 0);
		if (!result) {
			addOpenSSLError();
			BIO_free(bio);
			return false;
		}

		BUF_MEM* buf = nullptr;
		BIO_get_mem_ptr(bio, &buf);

		std::string str(buf->data, buf->length);
		value = str;

		BIO_free(bio);
		return true;
	}

	void
	CertificateExtension::logContent(const std::string& message)
	{
		Log(Debug, message)
			.parameter("UseCACert", useCACert_)
			.parameter("BasicContrains", basicConstraints_)
			.parameter("NsComment", nsComment_)
			.parameter("SubjectKeyIdentifier", subjectKeyIdentifier_)
			.parameter("AuthorityKeyIdentifier", authorityKeyIdentifier_)
			.parameter("KeyUsage", keyUsage_)
			.parameter("ExtendedKeyUsage", extendedKeyUsage_)
			.parameter("SubjectAltName", subjectAltName_);
	}

}
