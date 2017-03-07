/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Certificate/OpcUaX509.h"
#include <openssl/x509v3.h>

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaX509NameEntry
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaX509NameEntry::OpcUaX509NameEntry(void)
	: name_("")
	, value_("")
	{
	}

	OpcUaX509NameEntry::OpcUaX509NameEntry(const std::string& name, const std::string& value)
	: name_("name")
	, value_("value")
	{
	}

	OpcUaX509NameEntry::~OpcUaX509NameEntry(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaX509Extension
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaX509Extension::OpcUaX509Extension(void)
	: name_("")
	, value_("")
	{
	}

	OpcUaX509Extension::OpcUaX509Extension(const std::string& name, const std::string& value)
	: name_("name")
	, value_("value")
	{
	}

	OpcUaX509Extension::~OpcUaX509Extension(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// X509Handle
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	X509Handle::X509Handle(X509** x509)
	: x509_(x509)
	{
	}

	X509Handle::~X509Handle(void)
	{
		if (x509_ != nullptr) {
			X509_free (*x509_);
			*x509_ = nullptr;
		}
	}

	void
	X509Handle::reset(void)
	{
		x509_ = nullptr;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpcUaX509
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaX509::OpcUaX509(void)
	: PkiError()
	, x509Cert_(nullptr)
	{
	}

	OpcUaX509::~OpcUaX509(void)
	{
		if (x509Cert_ != nullptr) {
		    X509_free(x509Cert_);
		    x509Cert_ = nullptr;
		}
	}

	OpcUaStatusCode
	OpcUaX509::addEntryByName(X509_NAME** x509Name, const std::string& name, const std::string& value)
	{
		return addEntryByName(x509Name, OpcUaX509NameEntry(name, value));
	}

	OpcUaStatusCode
	OpcUaX509::addEntryByName(X509_NAME** x509Name, const OpcUaX509NameEntry& x509NameEntry)
	{
		// map name to id
		int nid = OBJ_txt2nid(x509NameEntry.name_.c_str());
		if (nid == NID_undef) {
			openSSLError();
			return BadNotSupported;
		}

		// create name entry
		X509_NAME_ENTRY* entry = nullptr;
		entry = X509_NAME_ENTRY_create_by_NID(nullptr, nid, MBSTRING_ASC, (unsigned char*)x509NameEntry.value_.c_str(), -1);
		if(entry == nullptr) {
			openSSLError();
			return BadInternalError;
		}

		// add name entry to x509 name
		int rc = X509_NAME_add_entry(*x509Name, entry,-1,0);
	    if (rc != 1) {
			openSSLError();

			X509_NAME_ENTRY_free(entry);
			return BadInternalError;
	    }

	    X509_NAME_ENTRY_free(entry);
		return Success;
	}

	OpcUaStatusCode
	OpcUaX509::addV3Extension(X509** cert, const std::string& name, const std::string& value, X509V3_CTX* ctx)
	{
		return addV3Extension(cert, OpcUaX509Extension(name, value), ctx);
	}

	OpcUaStatusCode
	OpcUaX509::addV3Extension(X509** cert, const OpcUaX509Extension& extension, X509V3_CTX* ctx)
	{
		// create extension
		X509_EXTENSION* ext = nullptr;
		ext = X509V3_EXT_conf(nullptr, ctx, (char*)extension.name_.c_str(), (char*)extension.value_.c_str());
		if (ext == nullptr) {
			openSSLError();
			return BadInternalError;
		}

		// added extension to certificate
		int rc = X509_add_ext(*cert, ext, -1);
		if (rc != 1) {
			openSSLError();

			X509_EXTENSION_free(ext);
			return BadInternalError;
		}

	    X509_EXTENSION_free(ext);
		return Success;
	}

	OpcUaStatusCode
	OpcUaX509::addCustomExtension(X509** cert, const std::string& name, const std::string& value, X509V3_CTX* ctx)
	{
		return addCustomExtension(cert, OpcUaX509Extension(name, value), ctx);
	}

	OpcUaStatusCode
	OpcUaX509::addCustomExtension(X509** cert, const OpcUaX509Extension& extension, X509V3_CTX* ctx)
	{
		return addV3Extension(cert, extension, ctx);
	}

	OpcUaStatusCode
	OpcUaX509::createSelfSignedCerificate(
		EVP_PKEY* subjectPublicKey,
		EVP_PKEY* issuerPrivateKey
	)
	{
		int rc;

		// check subject and issuer keys
		if (subjectPublicKey->type != issuerPrivateKey->type) {
			openSSLError("subject public key and issuer private key with different types");
			return BadInvalidArgument;
		}

		// create new X509 certificate
		x509Cert_ = X509_new();
		if (x509Cert_ == nullptr) {
			Log(Error, "allocate memory error for x509 certificate");
			return BadInternalError;
		}
		X509Handle x509Handle(&x509Cert_); // cleanup cert memory automaticaly on return

		// set version of certificate
		rc = X509_set_version(x509Cert_, 2);
		if (!rc) {
			openSSLError();
			return BadInternalError;
		}

		// FIXME: todo

		x509Handle.reset(); // do not clean memory automaticaly on return
		return Success;
	}

}




