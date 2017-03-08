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
		if (x509_ != nullptr && *x509_ != nullptr) {
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
	// X509NameHandle
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	X509NameHandle::X509NameHandle(X509_NAME** x509Name)
	: x509Name_(x509Name)
	{
	}

	X509NameHandle::~X509NameHandle(void)
	{
		if (x509Name_ != nullptr && *x509Name_ != nullptr) {
			X509_NAME_free (*x509Name_);
			*x509Name_ = nullptr;
		}
	}

	void
	X509NameHandle::reset(void)
	{
		x509Name_ = nullptr;
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
	OpcUaX509::PosixTimeToASN1Time(boost::posix_time::ptime& ptime, ASN1_TIME* asn1Time)
	{
		boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();
		boost::posix_time::time_duration dt = ptime - now;

		if (X509_gmtime_adj(asn1Time, (long)dt.total_seconds()) == nullptr) {
			openSSLError("ASN1 time type invalid");
			return BadInternalError;
		}
		return Success;
	}

	OpcUaStatusCode
	OpcUaX509::createSelfSignedCerificate(
		EVP_PKEY* subjectPublicKey,
		EVP_PKEY* issuerPrivateKey,
		int serialNumber,
		OpcUaX509NameEntry::Vec& nameEntries,
		OpcUaX509Extension::Vec& extensionEntries,
		boost::posix_time::ptime notBefore,
		boost::posix_time::ptime notAfter
	)
	{
		OpcUaStatusCode statusCode;
		int rc;

		// check subject and issuer keys
		if (subjectPublicKey->type != issuerPrivateKey->type) {
			openSSLError("subject public key and issuer private key with different types");
			return BadInvalidArgument;
		}

		// create new X509 certificate
		x509Cert_ = X509_new();
		if (x509Cert_ == nullptr) {
			openSSLError("allocate memory error for x509 certificate");
			return BadInternalError;
		}
		X509Handle x509Handle(&x509Cert_); // cleanup cert memory automaticaly on return

		// set version of certificate
		rc = X509_set_version(x509Cert_, 2);
		if (!rc) {
			openSSLError();
			return BadInternalError;
		}

		// set serial number
		rc = ASN1_INTEGER_set(X509_get_serialNumber(x509Cert_), serialNumber);
		if (!rc) {
			openSSLError();
			return BadInternalError;
		}

		// set subject public key
        rc = X509_set_pubkey(x509Cert_, subjectPublicKey);
        if (!rc) {
            openSSLError();
 			return BadInternalError;
        }

        // set subject name
        X509_NAME* x509Name = X509_NAME_new();
        if (x509Name == nullptr) {
			openSSLError("allocate memory error for x509_NAME");
			return BadInternalError;
        }
        X509NameHandle x509NameHandleSubject(&x509Name); // cleanup x509 name memory automaticaly on return

        // create and add entries to subject name
        OpcUaX509NameEntry::Vec::iterator it0;
        for (it0 = nameEntries.begin(); it0 != nameEntries.end(); it0++) {
        	OpcUaStatusCode statusCode;
        	statusCode = addEntryByName(&x509Name, *it0);
        	if (statusCode != Success) return statusCode;
        }

        // set subject name
        rc = X509_set_subject_name(x509Cert_, x509Name);
        if (!rc) {
            openSSLError();
 			return BadInternalError;
        }

        // set issuer name
        rc = X509_set_issuer_name(x509Cert_, x509Name);
        if (!rc) {
            openSSLError();
 			return BadInternalError;
        }

        // set valid time range
        statusCode = PosixTimeToASN1Time(notBefore, X509_get_notBefore(x509Cert_));
        if (statusCode != Success) return statusCode;
        statusCode = PosixTimeToASN1Time(notAfter, X509_get_notAfter(x509Cert_));
        if (statusCode != Success) return statusCode;

        // set v3 extensions
        X509V3_CTX ctx;
        X509V3_set_ctx(&ctx, x509Cert_, x509Cert_, NULL, NULL, 0);
        OpcUaX509Extension::Vec::iterator it1;
        for (it1 = extensionEntries.begin(); it1 != extensionEntries.end(); it1++) {
        	OpcUaStatusCode statusCode;
        	statusCode = addV3Extension(&x509Cert_, *it1, &ctx);
        	if (statusCode != Success) return statusCode;
        }

        // sign the certificate with the private key
        const EVP_MD* digest = EVP_sha1();
        if (!digest) {
        	openSSLError();
        	return BadInternalError;
        }
        rc = X509_sign(x509Cert_, issuerPrivateKey, digest);
        if (!rc) {
        	openSSLError();
        	return BadInternalError;
        }

		x509Handle.reset(); // do not clean cert memory automaticaly on return
		return Success;
	}

}




