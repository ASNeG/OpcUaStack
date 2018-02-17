/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/Certificate/Certificate.h"
#include "OpcUaStackCore/Certificate/CertificateExtension.h"

namespace OpcUaStackCore
{

	Certificate::Certificate(void)
	: OpenSSLError()
	, cert_(nullptr)
	{
	}

	Certificate::Certificate(
		Info& info,
		Identity& subject,
	    RSAKey&rsaKey,
	    bool useCACert,
	    SignatureAlgorithm signatureAlgorithm
	)
	: cert_(nullptr)
	{
		cert_ = X509_new();
		if (cert_ == nullptr) {
			return;
		}

		bool error = false;
		int32_t result = 0;

		// set version
		if (!error) {
			result = X509_set_version(cert_, 2);
			if (!result) {
				error = true;
				addOpenSSLError();
			}
		}

		// set serial number
        if (!error) {
            uint32_t serialNumber = info.serialNumber();
            if (serialNumber == 0) {
                serialNumber = (long)time(NULL);
            }
            result = ASN1_INTEGER_set(X509_get_serialNumber(cert_), serialNumber);
            if (!result) {
            	error = true;
            	addOpenSSLError();
            }
        }

        // set subject and issuer
        if (!error) {
            X509_NAME *name = subject.encodeX509();
            if (!name) {
            	error = true;
            	addError(subject.errorList());
            }
            else {
                result = X509_set_subject_name(cert_, name);
                if (!result) {
                	error = true;
                	addOpenSSLError();
                }
                result = X509_set_issuer_name(cert_, name);
                if (!result) {
                	error = true;
                	addOpenSSLError();
                }
                X509_NAME_free(name);
            }
        }

        // set certificate valid times
        if (!error) {
            X509_gmtime_adj(X509_get_notBefore(cert_), info.validFrom());
            X509_gmtime_adj(X509_get_notAfter(cert_), info.validTime());
        }

        // set public key
        if (!error) {
	        EVP_PKEY* publicKey = (EVP_PKEY*)rsaKey.publicKey();
	        result = X509_set_pubkey(cert_, publicKey);
	        if (!result) {
	        	error = true;
	        	addOpenSSLError();
	        }
	        EVP_PKEY_free(publicKey);
	    }

        // set extensions
        X509V3_CTX ctx;
        X509V3_set_ctx(&ctx, cert_, cert_, NULL, NULL, 0);
        if (!error) {
            CertificateExtension certificateExtension(useCACert);
            certificateExtension.subjectAltName(info.subjectAltName());
            if (!certificateExtension.encodeX509(cert_, ctx)) {
            	error = true;
            	addError(certificateExtension.errorList());
            }
        }

        // sign the certificate
	    if (!error) {
	        EVP_PKEY* key = (EVP_PKEY*)(const EVP_PKEY*)rsaKey.privateKey();
	        if (signatureAlgorithm == SignatureAlgorithm_Sha1) {
	            result = X509_sign(cert_, key, EVP_sha1());
	        }
	        else {
	            result = X509_sign(cert_, key, EVP_sha256());
	        }
	        if (!result) {
	        	error = true;
	        	addOpenSSLError();
	        }
	    }

	    if (error) {
	       X509_free(cert_);
	       cert_ = nullptr;
	    }
	}

	Certificate::Certificate(
		Info& info,
		Identity& subject,
		PublicKey& subjectPublicKey,
		Certificate&  issuerCertificate,
		PrivateKey& issuerPrivateKey,
	    bool useCACert,
	    SignatureAlgorithm signatureAlgorithm
	)
	: OpenSSLError()
	, cert_(nullptr)
	{
		cert_ = X509_new();
		if (cert_ == nullptr) {
			return;
		}

		bool error = false;
		int32_t result = 0;

		// set version
		if (!error) {
			result = X509_set_version(cert_, 2);
			if (!result) {
				error = true;
				addOpenSSLError();
			}
		}

		// set serial number
        if (!error) {
            uint32_t serialNumber = info.serialNumber();
            if (serialNumber == 0) {
                serialNumber = (long)time(NULL);
            }
            result = ASN1_INTEGER_set(X509_get_serialNumber(cert_), serialNumber);
            if (!result) {
            	error = true;
            	addOpenSSLError();
            }
        }

        // FIXME: todo
	}

	Certificate::~Certificate(void)
	{
		if (cert_) {
		    X509_free(cert_);
		    cert_ = nullptr;
		}
	}

	bool
	Certificate::getSubject(Identity& subject)
	{
		if (cert_ == nullptr) {
			addError("certificate is empty");
			return false;
		}

		X509_NAME* name = X509_get_subject_name(cert_);
		if (name == nullptr) {
			addOpenSSLError();
			return false;
		}

		return subject.decodeX509(name);
	}

	bool
	Certificate::getIssuer(Identity& issuer)
	{
		if (cert_ == nullptr) {
			addError("certificate is empty");
			return false;
		}

		X509_NAME* name = X509_get_subject_name(cert_);
		if (name == nullptr) {
			addOpenSSLError();
			return false;
		}

		return issuer.decodeX509(name);
	}

	bool
	Certificate::toDERFile(const std::string& fileName)
	{
		int32_t result;

		if (cert_ == nullptr) {
			addError("certificate is empty");
			return false;
		}

        BIO* bio = BIO_new_file(fileName.c_str(), "wb");
        if (bio == nullptr) {
        	addOpenSSLError();
        	return false;
        }

        result = i2d_X509_bio(bio, cert_);
        if (!result) {
        	addOpenSSLError();
        	BIO_free(bio);
        	return false;
        }

        BIO_free(bio);
		return true;
	}

	bool
	Certificate::fromDERFile(const std::string& fileName)
	{
		if (cert_ != nullptr) {
			addError("certificate is not empty");
			return false;
		}

		BIO* bio = BIO_new_file(fileName.c_str(), "rb");
		if (bio == nullptr) {
			addOpenSSLError();
			return false;
		}

		cert_ = d2i_X509_bio(bio, 0);
		if (cert_ == nullptr) {
			addOpenSSLError();
			BIO_free(bio);
			return false;
		}

		BIO_free(bio);
		return true;
	}

}
