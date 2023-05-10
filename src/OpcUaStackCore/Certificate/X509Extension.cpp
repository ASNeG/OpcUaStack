/*
   Copyright 2018-2023 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   X509Extensionrmationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#include <iostream>

#include "OpcUaStackCore/Certificate/X509Extension.h"

namespace OpcUaStackCore
{

	X509Extension::X509Extension(bool useCACert)
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

	X509Extension::~X509Extension(void)
	{
	}

	void
	X509Extension::clear(void)
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
	X509Extension::basicConstraints(const std::string& basicConstraints)
	{
		basicConstraints_ = basicConstraints;
	}

	std::string&
	X509Extension::basicConstraints(void)
	{
		return basicConstraints_;
	}

	void
	X509Extension::nsComment(const std::string& nsComment)
	{
		nsComment_ = nsComment;
	}

	std::string&
	X509Extension::nsComment(void)
	{
		return nsComment_;
	}

	void
	X509Extension::subjectKeyIdentifier(const std::string& subjectKeyIdentifier)
	{
		subjectKeyIdentifier_ = subjectKeyIdentifier;
	}

	std::string&
	X509Extension::subjectKeyIdentifier(void)
	{
		return subjectKeyIdentifier_;
	}

	void
	X509Extension::authorityKeyIdentifier(const std::string& authorityKeyIdentifier)
	{
		authorityKeyIdentifier_ = authorityKeyIdentifier;
	}

	std::string&
	X509Extension::authorityKeyIdentifier(void)
	{
		return authorityKeyIdentifier_;
	}

	void
	X509Extension::keyUsage(const std::string& keyUsage)
	{
		keyUsage_ = keyUsage;
	}

	std::string&
	X509Extension::keyUsage(void)
	{
		return keyUsage_;
	}

	void
	X509Extension::extendedKeyUsage(const std::string& extendedKeyUsage)
	{
		extendedKeyUsage_ = extendedKeyUsage;
	}

	std::string&
	X509Extension::extendedKeyUsage(void)
	{
		return extendedKeyUsage_;
	}

	void
	X509Extension::subjectAltName(const std::string& subjectAltName)
	{
		subjectAltName_ = subjectAltName;
	}

	std::string&
	X509Extension::subjectAltName(void)
	{
		return subjectAltName_;
	}

	bool
	X509Extension::encode(X509 *cert, X509V3_CTX& ctx)
	{
		if (!encode(cert, ctx, "basicConstraints", basicConstraints_)) {
			addError("encode NID_basic_constraints error");
			return false;
		}
		if (!encode(cert, ctx, "nsComment", nsComment_)) {
			addError("encode NID_netscape_comment error");
			return false;
		}
		if (!encode(cert, ctx, "keyUsage", keyUsage_)) {
			addError("encode NID_key_usage error");
			return false;
		}
		if (!encode(cert, ctx, "subjectKeyIdentifier", subjectKeyIdentifier_)) {
			addError("encode NID_subject_key_identifier error");
			return false;
		}

		if (!useCACert_) {
			if (!encode(cert, ctx, "extendedKeyUsage", extendedKeyUsage_)) {
				addError("encode NID_ext_key_usage error");
				return false;
			}
			if (!encode(cert, ctx, "authorityKeyIdentifier", authorityKeyIdentifier_)) {
				addError("encode NID_authority_key_identifier error");
				return false;
			}
			if (!encode(cert, ctx, "subjectAltName", subjectAltName_)) {
				addError("encode NID_subject_alt_name error");
				return false;
			}
		}

		return true;
	}

	bool
	X509Extension::decode(X509 *cert)
	{
		clear();

		if (!decode(cert, NID_basic_constraints, basicConstraints_)) {
			addError("decode NID_basic_constraints error");
			return false;
		}
		if (!decode(cert, NID_netscape_comment, nsComment_, false)) {
			addError("decode NID_netscape_comment error");
			return false;
		}
		if (!decode(cert, NID_key_usage, keyUsage_)) {
			addError("decode NID_key_usage error");
			return false;
		}
		if (!decode(cert, NID_subject_key_identifier, subjectKeyIdentifier_)) {
			addError("decode NID_subject_key_identifier error");
			return false;
		}

		if (!useCACert_) {
			if (!decode(cert, NID_ext_key_usage, extendedKeyUsage_)) {
				addError("decode NID_ext_key_usage error");
				return false;
			}
			if (!decode(cert, NID_authority_key_identifier, authorityKeyIdentifier_)) {
				addError("decode NID_authority_key_identifier error");
				return false;
			}
			if (!decode(cert, NID_subject_alt_name, subjectAltName_)) {
				addError("decode NID_subject_alt_name error");
				return false;
			}
		}

		return true;
	}

	bool
	X509Extension::encode(X509 *cert, X509V3_CTX& ctx, const std::string& key, const std::string& value)
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
	X509Extension::decode(X509 *cert, int32_t key, std::string& value, bool mandatory)
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

	bool
	X509Extension::encode(X509_REQ *req, STACK_OF(X509_EXTENSION)* exts)
	{
		// Create key usage extension
		if (!encode(exts, "keyUsage", keyUsage_)) {
			addError("encode NID_key_usage error");
			sk_X509_EXTENSION_free(exts);
			return false;
		}

		// Create subject alternative name extension
		if (!encode(exts, "subjectAltName", subjectAltName_)) {
			addError("encode NID_subject_alt_name error");
			sk_X509_EXTENSION_free(exts);
			return false;
		}

		return true;
	}

	bool
	X509Extension::decode(X509_REQ *req)
	{
		// get extensions from request
		STACK_OF(X509_EXTENSION)* exts = X509_REQ_get_extensions(req);
		if (exts == NULL) {
			addOpenSSLError();
			return false;
		}

		if (!decode(exts, NID_key_usage, keyUsage_)) {
			addError("decode NID_key_usage error");
			return false;
		}

		if (!decode(exts, NID_subject_alt_name, subjectAltName_)) {
			addError("decode NID_subject_alt_name error");
			return false;
		}

		sk_X509_EXTENSION_free(exts);
		return true;
	}

	bool
	X509Extension::encode(
		STACK_OF(X509_EXTENSION)* exts,
		const std::string& key,
		const std::string& value
	)
	{
		int32_t result;
		X509_EXTENSION* ext = nullptr;

		// set key value
		ext = X509V3_EXT_conf(nullptr, nullptr, (char*)key.c_str(), (char*)value.c_str());
		if (!ext) {
			addOpenSSLError();
			return false;
		}
		result = sk_X509_EXTENSION_push(exts, ext);
		if (!result) {
			addOpenSSLError();
			X509_EXTENSION_free(ext);
			return false;
		}

		return true;
	}

	bool
	X509Extension::decode(
		STACK_OF(X509_EXTENSION)* exts,
		int32_t key,
		std::string& value,
		bool mandatory
	)
	{
	    int32_t pos = X509v3_get_ext_by_NID(exts, key, -1);
		if (pos < 0) {
			if (!mandatory) {
				value = "";
				return true;
			}
			addOpenSSLError();
			return false;
		}

		X509_EXTENSION* ext = X509v3_get_ext(exts, pos);
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
	X509Extension::logContent(const std::string& message)
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
