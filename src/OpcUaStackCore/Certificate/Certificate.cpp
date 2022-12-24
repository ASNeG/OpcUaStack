/*
   Copyright 2018-2022 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Certificatermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include <iostream>
#include <time.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time_adjustor.hpp>
#include <boost/date_time/c_local_time_adjustor.hpp>
#include "OpcUaStackCore/Base/MemoryBuffer.h"
#include "OpcUaStackCore/Certificate/Certificate.h"

namespace OpcUaStackCore
{

	Certificate::Certificate(void)
	: OpenSSLError()
	, cert_(nullptr)
	{
		OpenSSL_add_all_algorithms();
	}

	Certificate::Certificate(
		CertificateInfo& info,
		Identity& subject,
	    RSAKey& rsaKey,
	    bool useCACert,
	    SignatureAlgorithm signatureAlgorithm
	)
	: cert_(nullptr)
	{
		OpenSSL_add_all_algorithms();

		createCertificate(
			info,
			subject,
			rsaKey,
			useCACert,
			signatureAlgorithm
		);
	}

	Certificate::Certificate(
		CertificateInfo& info,
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
		OpenSSL_add_all_algorithms();

		createCertificate(
			info,
			subject,
			subjectPublicKey,
			issuerCertificate,
			issuerPrivateKey,
			useCACert,
			signatureAlgorithm
		);
	}

	Certificate::~Certificate(void)
	{
		if (cert_ != nullptr) {
		    X509_free(cert_);
		    cert_ = nullptr;
		}
	}

	bool
	Certificate::createCertificate(
		CertificateInfo& info,
		Identity& subject,
		RSAKey& rsaKey,
		bool useCACert,
		SignatureAlgorithm signatureAlgorithm
	)
	{
		assert(cert_ == nullptr);

		cert_ = X509_new();
		if (cert_ == nullptr) {
			addError("create certificate error in constructor");
			return false;
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
        	auto now = boost::posix_time::microsec_clock::universal_time();

           	long validFrom;
        	if (info.validFrom() <= now) {
        		validFrom = 0;
        	}
        	else {
        		 auto dt = info.validFrom() - now;
        		 validFrom = dt.total_seconds();
        	}

        	long validTime;
           	if (info.validTime() <= now) {
           		validTime = 0;
            }
            else {
            	auto dt = info.validTime() - now;
            	validTime = dt.total_seconds();
            }

            X509_gmtime_adj(X509_get_notBefore(cert_), validFrom);
            X509_gmtime_adj(X509_get_notAfter(cert_), validTime);
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
            if (!info.keyUsage().empty()) {
           	   certificateExtension.keyUsage(info.keyUsage());
            }
            certificateExtension.logContent(std::string("create certificate ") + subject.commonName());
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

	        EVP_PKEY_free(key);
	    }

	    if (error && cert_ != nullptr) {
	       X509_free(cert_);
	       cert_ = nullptr;
	    }

		return !error;
	}

	bool
	Certificate::createCertificate(
		CertificateInfo& info,
		Identity& subject,
		PublicKey& subjectPublicKey,
		Certificate&  issuerCertificate,
		PrivateKey& issuerPrivateKey,
		bool useCACert,
		SignatureAlgorithm signatureAlgorithm
	)
	{
		assert(cert_ == nullptr);

		cert_ = X509_new();
		if (cert_ == nullptr) {
			addError("create certificate error in constructor");
			return false;
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

        // set subject
        if (!error) {
            X509_NAME* name = subject.encodeX509();
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
                X509_NAME_free(name);
            }
        }

        // set issuer
       	Identity issuer;
        if (!issuerCertificate.getSubject(issuer)) {
        	error = true;
        	addError(subject.errorList());
        }
        if (!error) {
            X509_NAME* name = issuer.encodeX509();
            if (!name) {
            	error = true;
            	addError(subject.errorList());
            }
            else {
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
           	auto now = boost::posix_time::microsec_clock::universal_time();

            long validFrom;
            if (info.validFrom() <= now) {
            	validFrom = 0;
            }
            else {
            	auto dt = info.validFrom() - now;
            	validFrom = dt.total_seconds();
            }

            long validTime;
            if (info.validTime() <= now) {
               	validTime = 0;
            }
            else {
                auto dt = info.validTime() - now;
                validTime = dt.total_seconds();
            }

            X509_gmtime_adj(X509_get_notBefore(cert_), validFrom);
            X509_gmtime_adj(X509_get_notAfter(cert_), validTime);
        }

        // set public key
         if (!error) {
 	        EVP_PKEY* publicKey = (EVP_PKEY*)subjectPublicKey;
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
             if (!info.keyUsage().empty()) {
            	 certificateExtension.keyUsage(info.keyUsage());
             }
             certificateExtension.logContent(std::string("create certificate ") + subject.commonName());
             if (!certificateExtension.encodeX509(cert_, ctx)) {
                 error = true;
              	 addError(certificateExtension.errorList());
             }
         }

         // sign the certificate
  	     if (!error) {
  	        EVP_PKEY* key = (EVP_PKEY*)(const EVP_PKEY*)issuerPrivateKey;
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
  	        EVP_PKEY_free(key);
  	    }

  	    if (error && cert_ != nullptr) {
  	       X509_free(cert_);
  	       cert_ = nullptr;
  	    }

		return !error;
	}

	bool
	Certificate::isCaCertificate(void)
	{
		// 1. The CA attribute must be set to true
		CertificateExtension certificateExtension(true);
		if (!getExtension(certificateExtension)) {
			addError("read certificate extension error");
			return false;
		}
		if (certificateExtension.basicConstraints().find("CA:TRUE") == std::string::npos) {
			return false;
		}

		return true;
	}

	bool
	Certificate::isCaRoot(void)
	{
		// 1. The CA attribute must be set to true
		if (!isCaCertificate()) {
			return false;
		}

		// 2. The subject name and the issuer name must be the same
		Identity subject;
		if (!getSubject(subject)) {
			addError("read certificate subject error");
			return false;
		}
		Identity issuer;
		if (!getIssuer(issuer)) {
			addError("read certificate issuer error");
			return false;
		}
		if (subject.commonName() != issuer.commonName()) {
			return false;
		}

		return true;
	}

	bool
	Certificate::isIntermediateCertificate(void)
	{
		// 1. The CA attribute must be set to true
		CertificateExtension certificateExtension(true);
		if (!getExtension(certificateExtension)) {
			addError("read certificate extension error");
			return false;
		}
		if (certificateExtension.basicConstraints().find("CA:TRUE") == std::string::npos) {
			return false;
		}

		// 2. The subject name and the issuer name must be different
		Identity subject;
		if (!getSubject(subject)) {
			addError("read certificate subject error");
			return false;
		}
		Identity issuer;
		if (!getIssuer(issuer)) {
			addError("read certificate issuer error");
			return false;
		}
		if (subject.commonName() == issuer.commonName()) {
			return false;
		}

		return true;
	}

	bool
	Certificate::isApplCertificate(void)
	{
		return !isCaCertificate();
	}

	X509*
	Certificate::getX509(void)
	{
		return cert_;
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

		if (!subject.decodeX509(name)) {
			addError(subject.errorList());
			return false;
		}

		return true;
	}

	bool
	Certificate::getIssuer(Identity& issuer)
	{
		if (cert_ == nullptr) {
			addError("certificate is empty");
			return false;
		}

		X509_NAME* name = X509_get_issuer_name(cert_);
		if (name == nullptr) {
			addOpenSSLError();
			return false;
		}

		if (!issuer.decodeX509(name)) {
			addError(issuer.errorList());
			return false;
		}

		return true;
	}

	bool
	Certificate::getInfo(CertificateInfo& info)
	{
		auto timeDiff = (boost::posix_time::microsec_clock::local_time() -
	        boost::posix_time::microsec_clock::universal_time()).total_seconds();

		if (cert_ == nullptr) {
			addError("certificate is empty");
			return false;
		}

		// get extensions
		auto isCACert = isCaCertificate() || isIntermediateCertificate();
		CertificateExtension ext(isCACert);
		if (!ext.decodeX509(cert_)) {
			addError(ext.errorList());
			return false;
		}
		info.keyUsage(ext.keyUsage());
		if (!isCACert) {
			info.subjectAltName(ext.subjectAltName());
		}

		// get serial number
		info.serialNumber(ASN1_INTEGER_get(X509_get_serialNumber(cert_)));

		struct tm timeinfo;

		// Get NotBefore time
		ASN1_TIME* notBefore = X509_get_notBefore(cert_);
		if (notBefore == NULL) {
			addError("not before time format invalid");
			return false;
		}
		if (!ASN1_TIME_to_tm(notBefore, &timeinfo)) {
			addError("not before time format invalid");
			return false;
		}
		info.validFrom(boost::posix_time::ptime_from_tm(timeinfo));

		// Get NotAfter time
		ASN1_TIME* notAfter = X509_get_notAfter(cert_);
		if (notAfter == NULL) {
			addError("not after time format invalid");
			return false;
		}
		if (!ASN1_TIME_to_tm(notAfter, &timeinfo)) {
			addError("not after time format invalid");
			return false;
		}
		info.validTime(boost::posix_time::ptime_from_tm(timeinfo));

		return true;
	}

	bool
	Certificate::getExtension(CertificateExtension& certificateExtension)
	{
		if (cert_ == nullptr) {
			addError("certificate is empty");
			return false;
		}

		if (!certificateExtension.decodeX509(cert_)) {
			addError(certificateExtension.errorList());
			return false;
		}

		return true;
	}

	OpcUaByteString
	Certificate::thumbPrint(void)
	{
		MemoryBuffer mem(20);
		uint32_t memLen = 20;

		if (!thumbPrint(mem.memBuf(), &memLen)) {
			return OpcUaByteString();
		}

		return OpcUaByteString((const OpcUaByte*)mem.memBuf(), mem.memLen());
	}

	bool
	Certificate::thumbPrint(char* buf, uint32_t* bufLen)
	{
		if (cert_ == nullptr) {
			addError("certificate is empty");
			return false;
		}

		if (*bufLen != 20) {
			addError("length of thumbPrint must be 20 bytes");
			return false;
		}

		// creater DER buffer
		uint32_t derLen;
		if (!toDERBufLen(&derLen)) {
			return false;
		}
		char* derBuf = new char[derLen];
		if (!toDERBuf(derBuf, &derLen)) {
			delete [] derBuf;
			return false;
		}

		// create thumb print
		SHA1((const unsigned char*)derBuf, derLen, (unsigned char* )buf);
		delete [] derBuf;

		return true;
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

	bool
	Certificate::toDERBufLen(uint32_t* bufLen)
	{
		*bufLen = 0;
		if (cert_ == nullptr) {
			addError("certificate is empty");
			return false;
		}

		int32_t length = i2d_X509(cert_, 0);
	    if (length < 0) {
	         addOpenSSLError();
	         return false;
	    }

	    *bufLen = length;
		return true;
	}

	bool
	Certificate::toDERBuf(OpcUaByteString& derBuf)
	{
		uint32_t derBufLen;
		if (!toDERBufLen(&derBufLen)) {
			log(Error, "toDERBufLen error");
			return false;
		}
		if (!derBuf.resize(derBufLen)) {
			Log(Error, "DER buffer resize error");
			return false;
		}

		char *buf;
		int32_t len;
		derBuf.value(&buf, &len);
		if (len <= 0) {
			Log(Error, "DER buffer empty");
			return false;
		}

		uint32_t length = len;
		if (!toDERBuf(buf, &length)) {
			log(Error, "toDERBufLen error");
			return false;
		}
		return true;
	}

	bool
	Certificate::toDERBuf(MemoryBuffer& derBuf)
	{
		uint32_t derBufLen;
		if (!toDERBufLen(&derBufLen)) {
			log(Error, "toDERBufLen error");
			return false;
		}
		derBuf.resize(derBufLen);

		if (!toDERBuf(derBuf.memBuf(), &derBufLen)) {
			log(Error, "toDERBufLen error");
			return false;
		}
		return true;
	}

	bool
	Certificate::toDERBuf(char* buf, uint32_t* bufLen)
	{
		if (cert_ == nullptr) {
			addError("certificate is empty");
			return false;
		}

		// check buffer length
		int32_t length = i2d_X509(cert_, 0);
	    if (length < 0) {
	         addOpenSSLError();
	         return false;
	    }
		if (length > *bufLen) {
			addError("buffer too short");
			return false;
		}

		*bufLen = length;
		char* ptr = buf;
		i2d_X509(cert_, (unsigned char**)&ptr);
		return true;
	}

	bool
	Certificate::fromDERBuf(char* buf, uint32_t bufLen)
	{
		if (cert_ != nullptr) {
			addError("certificate is not empty");
			return false;
		}
		char* ptr = buf;
        cert_= d2i_X509(0, (const unsigned char**)&ptr, bufLen);
        if (cert_ == nullptr) {
        	addOpenSSLError();
        	return false;
        }

		return true;
	}

	bool
	Certificate::fromDERBuf(MemoryBuffer& derBuf)
	{
		if (cert_ != nullptr) {
			addError("certificate is not empty");
			return false;
		}
		char* mem = derBuf.memBuf();
        cert_= d2i_X509(0, (const unsigned char**)&mem, derBuf.memLen());
        if (cert_ == nullptr) {
        	addOpenSSLError();
        	return false;
        }

		return true;
	}

	uint32_t
	Certificate::getDERBufSize(void)
	{
		if (cert_ == nullptr) {
			return 0;
		}

		int32_t length = i2d_X509(cert_, 0);
		if (length < 0) {
			return 0;
		}

		return (uint32_t)length;
	}

	bool
	Certificate::isIssuerFrom(Certificate&  certificate)
	{
	    if (X509_check_issued(certificate.getX509(), cert_) != 0) {
	        return false;
	    }
	    return true;
	}

	bool
	Certificate::isSelfSigned(void) const
	{
	    if (X509_check_issued(cert_, cert_) != 0) {
	        return false;
	    }

	    EVP_PKEY* issuerPublicKey = X509_get_pubkey(cert_);
	    if (issuerPublicKey == nullptr)  {
	        return false;
	    }

	    int32_t result = X509_verify(cert_, issuerPublicKey);
	    if (result <= 0) {
	    	const_cast<Certificate*>(this)->addOpenSSLError();
	    }
	    EVP_PKEY_free(issuerPublicKey);

	    if (result <= 0) {
	        return false;
	    }
	    return true;
	}

	bool
	Certificate::verifySignature(Certificate& issuerCertificate) const
	{
#if 0
	    if (X509_check_issued(issuerCertificate.getX509(), cert_) != 0) {
	    	Log(Error, "check issued certificate error");
	        return false;
	    }
#endif

	    EVP_PKEY* issuerPublicKey = X509_get_pubkey(issuerCertificate.getX509());
	    if (issuerPublicKey == nullptr)  {
	    	Log(Error, "issuer public key is null");
	        return false;
	    }

	    int32_t result = X509_verify(cert_, issuerPublicKey);
	    if (result <= 0) {
	    	const_cast<Certificate*>(this)->addOpenSSLError();
	    }
	    EVP_PKEY_free(issuerPublicKey);

	    if (result <= 0) {
	        return false;
	    }

		return true;
	}

	PublicKey
	Certificate::publicKey(void)
	{
		if (cert_ == nullptr) {
			PublicKey publicKey;
			return publicKey;
		}

		// get key with reference count incremented
		EVP_PKEY* key = X509_get_pubkey(cert_);
		if (key == nullptr) {
			addOpenSSLError();
			PublicKey publicKey;
			return publicKey;
		}

		PublicKey publicKey(key);
		EVP_PKEY_free(key);
		return publicKey;
	}

	bool
	Certificate::operator!=(const Certificate& rhs) const
	{
		return !operator==(rhs);
	}

	bool
	Certificate::operator==(const Certificate& rhs) const
	{
		OpcUaByteString derBuf1, derBuf2;
		const_cast<Certificate*>(this)->toDERBuf(derBuf1);
		const_cast<Certificate*>(&rhs)->toDERBuf(derBuf2);
		return derBuf1 == derBuf2;
	}

}
