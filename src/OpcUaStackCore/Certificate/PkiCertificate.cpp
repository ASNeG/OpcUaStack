/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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

#include <openssl/err.h>
#include <openssl/pkcs12.h>
#include <openssl/pem.h>
#include <openssl/x509v3.h>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Certificate/PkiCertificate.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// PkiExtensionEntry
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	PkiExtensionEntry::PkiExtensionEntry(void)
	: key_("")
	, value_("")
	{
	}

	PkiExtensionEntry::PkiExtensionEntry(const std::string& key, const std::string& value)
	: key_(key)
	, value_(value)
	{
	}

	PkiExtensionEntry::~PkiExtensionEntry(void)
	{
	}

	void
	PkiExtensionEntry::key(const std::string& key)
	{
		key_ = key;
	}

	std::string&
	PkiExtensionEntry::key(void)
	{
		return key_;
	}

	void
	PkiExtensionEntry::value(const std::string& value)
	{
		value_ = value;
	}

	std::string&
	PkiExtensionEntry::value(void)
	{
		return value_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// PkiCertificate
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool PkiCertificate::loadCryptoStrings_ = false;
	std::list<std::string> PkiCertificate::cryptoStringErrorList_;
	PkiExtensionEntry::Vec PkiCertificate::pkiEntensionEntryVec_;
	bool PkiCertificate::init_ = false;

	PkiCertificate::PkiCertificate(void)
	: x509Cert_(nullptr)
	, startTime_(time(NULL))
	{
		if (!init_) {
			init_ = true;

			// set pki extension entry
			pkiEntensionEntryVec_.push_back(PkiExtensionEntry("basicConstraints", "critical, CA:FALSE"));
			pkiEntensionEntryVec_.push_back(PkiExtensionEntry("nsComment", "\"Generated with OpcUaStack using OpenSSL\""));
			pkiEntensionEntryVec_.push_back(PkiExtensionEntry("subjectKeyIdentifier", "hash"));
			pkiEntensionEntryVec_.push_back(PkiExtensionEntry("authorityKeyIdentifier", "keyid, issuer:always"));
			pkiEntensionEntryVec_.push_back(PkiExtensionEntry("keyUsage", "critical, nonRepudiation, digitalSignature, keyEncipherment, dataEncipherment, keyCertSign"));
			pkiEntensionEntryVec_.push_back(PkiExtensionEntry("extendedKeyUsage", "critical, serverAuth,clientAuth"));
		}
	}

	PkiCertificate::~PkiCertificate(void)
	{
		if (x509Cert_ != nullptr) {
		    X509_free(x509Cert_);
		    x509Cert_ = nullptr;
		}
	}

	bool
	PkiCertificate::createNewCertificate(
		PkiCertificateInfo& pkiCertificateInfo,
		PkiIdentity& subjectPkiIdentity,
		PkiPublicKey& subjectPkiPublicKey,
		PkiIdentity& issuerPkiIdentity,
		PkiPrivateKey& issuerPrivateKey
	)
	{
		bool success = true;
		int resultCode;

		// allocate x509 certificate memory
		x509Cert_ = X509_new();
		if (x509Cert_ == nullptr) {
			Log(Error, "allocate memory error for x509 certificate");
			return false;
		}

		// set version (V3)
		if (success) {
			resultCode = X509_set_version(x509Cert_, 2);
			if (!resultCode) {
				success = false;
				openSSLError();
			}
		}

		// set start time
		if (success) {
			resultCode = ASN1_INTEGER_set(X509_get_serialNumber(x509Cert_), (long)startTime_);
			if (!resultCode) {
				success = false;
				openSSLError();
			}
		}

		//
		// set subject name
		//
		if (success) {
			X509_NAME* x509Name = nullptr;
	        x509Name = X509_NAME_new();

	        // set domain component
	        resultCode = X509_NAME_add_entry_by_txt (
	        	x509Name, "DC", MBSTRING_UTF8, (const unsigned char*)subjectPkiIdentity.domainComponent().c_str(), -1, -1, 0
	        );
            if (!resultCode) {
            	openSSLError();
            }

            // set country
            resultCode = X509_NAME_add_entry_by_txt (
            	x509Name, "C", MBSTRING_UTF8, (const unsigned char*)subjectPkiIdentity.country().c_str(), -1, -1, 0
            );
            if (!resultCode) {
            	openSSLError();
            }

            // set state
            resultCode = X509_NAME_add_entry_by_txt (
            	x509Name, "ST", MBSTRING_UTF8, (const unsigned char*)subjectPkiIdentity.state().c_str(), -1, -1, 0
            );
            if (!resultCode) {
            	openSSLError();
            }

            // set locality
            resultCode = X509_NAME_add_entry_by_txt (
                x509Name, "L", MBSTRING_UTF8, (const unsigned char*)subjectPkiIdentity.locality().c_str(), -1, -1, 0
            );
            if (!resultCode) {
            	openSSLError();
            }

            // set organization
            resultCode = X509_NAME_add_entry_by_txt (
                x509Name, "O", MBSTRING_UTF8, (const unsigned char*)subjectPkiIdentity.organization().c_str(), -1, -1, 0
            );
            if (!resultCode) {
            	openSSLError();
            }

            // set organization unit
            resultCode = X509_NAME_add_entry_by_txt (
               	x509Name, "OU", MBSTRING_UTF8, (const unsigned char*)subjectPkiIdentity.organizationUnit().c_str(), -1, -1, 0
            );
            if (!resultCode) {
            	openSSLError();
            }

            // set common name
            resultCode = X509_NAME_add_entry_by_txt (
               x509Name, "CN", MBSTRING_UTF8, (const unsigned char*)subjectPkiIdentity.commonName().c_str(), -1, -1, 0
            );
            if (!resultCode) {
            	openSSLError();
            }

            if (success) {
            	resultCode = X509_set_subject_name(x509Cert_, x509Name);
            	if (!resultCode) {
            		success = false;
            		openSSLError();
            	}
            }

	        X509_NAME_free (x509Name);
		}

		//
		// set issuer name
		//
		if (success) {
			X509_NAME* x509Name = nullptr;
	        x509Name = X509_NAME_new();

	        // set domain component
	        resultCode = X509_NAME_add_entry_by_txt (
	        	x509Name, "DC", MBSTRING_UTF8, (const unsigned char*)issuerPkiIdentity.domainComponent().c_str(), -1, -1, 0
	        );
            if (!resultCode) {
            	openSSLError();
            }

            // set country
            resultCode = X509_NAME_add_entry_by_txt (
            	x509Name, "C", MBSTRING_UTF8, (const unsigned char*)issuerPkiIdentity.country().c_str(), -1, -1, 0
            );
            if (!resultCode) {
            	openSSLError();
            }

            // set state
            resultCode = X509_NAME_add_entry_by_txt (
            	x509Name, "ST", MBSTRING_UTF8, (const unsigned char*)issuerPkiIdentity.state().c_str(), -1, -1, 0
            );
            if (!resultCode) {
            	openSSLError();
            }

            // set locality
            resultCode = X509_NAME_add_entry_by_txt (
                x509Name, "L", MBSTRING_UTF8, (const unsigned char*)issuerPkiIdentity.locality().c_str(), -1, -1, 0
            );
            if (!resultCode) {
            	openSSLError();
            }

            // set organization
            resultCode = X509_NAME_add_entry_by_txt (
                x509Name, "O", MBSTRING_UTF8, (const unsigned char*)issuerPkiIdentity.organization().c_str(), -1, -1, 0
            );
            if (!resultCode) {
            	openSSLError();
            }

            // set organization unit
            resultCode = X509_NAME_add_entry_by_txt (
               	x509Name, "OU", MBSTRING_UTF8, (const unsigned char*)issuerPkiIdentity.organizationUnit().c_str(), -1, -1, 0
            );
            if (!resultCode) {
            	openSSLError();
            }

            // set common name
            resultCode = X509_NAME_add_entry_by_txt (
               x509Name, "CN", MBSTRING_UTF8, (const unsigned char*)issuerPkiIdentity.commonName().c_str(), -1, -1, 0
            );
            if (!resultCode) {
            	openSSLError();
            }

            if (success) {
            	resultCode = X509_set_issuer_name(x509Cert_, x509Name);
            	if (!resultCode) {
            		success = false;
            		openSSLError();
            	}
            }

	        X509_NAME_free (x509Name);
		}

		// set valid time range
        if (success) {
        	PosixTimeToASN1Time(pkiCertificateInfo.validTimeNotBefore(), X509_get_notBefore(x509Cert_));
        	PosixTimeToASN1Time(pkiCertificateInfo.validTimeNotAfter(), X509_get_notAfter(x509Cert_));
        }

        if (success)
        {
            // set public key
            EVP_PKEY *pKey = subjectPkiPublicKey.publicKey();
            resultCode = X509_set_pubkey(x509Cert_, pKey);
            if (!resultCode) {
            	success = false;
            	openSSLError();
            }
            EVP_PKEY_free( pKey );
        }

        //
        // extension data
        //
        X509V3_CTX ctx;
        X509V3_set_ctx(&ctx, x509Cert_, x509Cert_, NULL, NULL, 0);
        if (success) {
        	X509_EXTENSION *pExt = 0;
            for (uint32_t idx = 0; idx < pkiEntensionEntryVec_.size(); idx++ )
            {
                pExt = X509V3_EXT_conf(
                	NULL, &ctx,
                	(char*)pkiEntensionEntryVec_[idx].key().c_str(),
                	(char*)pkiEntensionEntryVec_[idx].value().c_str(
                ));
                if (!pExt) {
                	success = false;
                	openSSLError();
                }
                else
                {
                    resultCode = X509_add_ext(x509Cert_, pExt, -1);
                    if (!resultCode)
                    {
                    	success = false;
                    	openSSLError();
                    }
                    X509_EXTENSION_free (pExt);
                }
            }
        }

        if (success) {
        	std::vector<std::string>::iterator it;
        	std::string subjectAltNameValue;

        	// add URI
        	subjectAltNameValue += "URI:";
        	subjectAltNameValue += pkiCertificateInfo.URI();

        	// added DNS
        	for (it = pkiCertificateInfo.dnsNames().begin(); it != pkiCertificateInfo.dnsNames().end(); it++) {
        		subjectAltNameValue += ",DNS:";
        		subjectAltNameValue += *it;
        	}

        	// added IP
        	for (it = pkiCertificateInfo.ipAddresses().begin(); it != pkiCertificateInfo.ipAddresses().end(); it++) {
        		subjectAltNameValue += ",IP:";
        		subjectAltNameValue += *it;
        	}

        	// added email
        	for (it = pkiCertificateInfo.email().begin(); it != pkiCertificateInfo.email().end(); it++) {
        		subjectAltNameValue += ",email:";
        		subjectAltNameValue += *it;
        	}

            X509_EXTENSION *pExt = X509V3_EXT_conf(NULL, &ctx, (char*)"subjectAltName", (char*)subjectAltNameValue.c_str());
            if (!pExt) {
            	success = false;
                openSSLError();
            }
            else
            {
                resultCode = X509_add_ext(x509Cert_, pExt, -1);
                if (!resultCode) {
                	success = false;
                    openSSLError();
                }
                X509_EXTENSION_free (pExt);
            }

        }

	    if (success) {
	        // sign the certificate
	        const EVP_MD* digest = EVP_sha1();
	        if (!digest) {
	        	success = false;
	        	openSSLError();
	        }

	        if (success) {
	        	EVP_PKEY* pKey = issuerPrivateKey.privateKey();
	            resultCode = X509_sign(x509Cert_, pKey, digest);
	            if (!resultCode) {
		        	success = false;
		        	openSSLError();
		        }
	        }
	    }

	    if (!success) {
	       X509_free (x509Cert_);
	       x509Cert_ = nullptr;
	    }

		return true;
	}

	bool
	PkiCertificate::getCertificate(
		PkiCertificateInfo& pkiCertificateInfo,
		PkiIdentity& subjectPkiIdentity,
		PkiPublicKey& subjectPkiPublicKey,
		PkiIdentity& issuerPkiIdentity,
		PkiPrivateKey& issuerPrivateKey
	)
	{
		bool success = true;
		int resultCode;

		// check memory of x509 certificate
		if (x509Cert_ == nullptr) {
			Log(Error, "memory error for x509 certificate");
			return false;
		}

		// get subject name
		if (success) {
			X509_NAME* name = X509_get_subject_name(x509Cert_);
			if (name == nullptr) {
				success = false;
				openSSLError();
			}


			success = success && getX509Name(name, NID_domainComponent, subjectPkiIdentity.domainComponent());
			success = success && getX509Name(name, NID_commonName, subjectPkiIdentity.commonName());
			success = success && getX509Name(name, NID_organizationName, subjectPkiIdentity.organization());
			success = success && getX509Name(name, NID_organizationalUnitName, subjectPkiIdentity.organizationUnit());
			success = success && getX509Name(name, NID_localityName, subjectPkiIdentity.locality());
			success = success && getX509Name(name, NID_stateOrProvinceName, subjectPkiIdentity.state());
			success = success && getX509Name(name, NID_countryName, subjectPkiIdentity.country());
		}

		// get issuer name
		if (success) {
			X509_NAME* name = X509_get_issuer_name(x509Cert_);
			if (name == nullptr) {
				success = false;
				openSSLError();
			}

			success = success && getX509Name(name, NID_domainComponent, issuerPkiIdentity.domainComponent());
			success = success && getX509Name(name, NID_commonName, issuerPkiIdentity.commonName());
			success = success && getX509Name(name, NID_organizationName, issuerPkiIdentity.organization());
			success = success && getX509Name(name, NID_organizationalUnitName, issuerPkiIdentity.organizationUnit());
			success = success && getX509Name(name, NID_localityName, issuerPkiIdentity.locality());
			success = success && getX509Name(name, NID_stateOrProvinceName, issuerPkiIdentity.state());
			success = success && getX509Name(name, NID_countryName, issuerPkiIdentity.country());
		}

		// get version
		if (success) {
			uint32_t version = X509_get_version(x509Cert_);
			pkiCertificateInfo.version(version);
		}

		// get serial number
		if (success) {
			uint32_t serialNumber = ASN1_INTEGER_get(X509_get_serialNumber(x509Cert_));
			pkiCertificateInfo.serialNumber(serialNumber);
		}

		// validation time not before
		if (success) {
			ASN1_TIME* notBefore = X509_get_notBefore(x509Cert_);
			if (notBefore == nullptr) {
				success = false;
				openSSLError();
			}
			else {
				if (!ASN1TimeToPosixTime(notBefore, pkiCertificateInfo.validTimeNotBefore())) {
					success = false;
					openSSLError("not before parameter invalid");
				}
			}
		}

		// validation time not after
		if (success) {
			ASN1_TIME* notAfter = X509_get_notAfter(x509Cert_);
			if (notAfter == nullptr) {
				success = false;
				openSSLError();
			}
			else {
				if (!ASN1TimeToPosixTime(notAfter, pkiCertificateInfo.validTimeNotAfter())) {
					success = false;
					openSSLError("not after parameter invalid");
				}
			}
		}

		// get SHA1 signature

		// get public key
		if (success) {
			EVP_PKEY* pkey = X509_get_pubkey(x509Cert_);
			if (pkey == nullptr) {
				success = false;
				openSSLError();
			}
			else {
				if (!subjectPkiPublicKey.publicKey(pkey)) {
					success = false;
					openSSLError("public key error");
				}
			}
		}

#if 0
	    UaPkiPublicKey ret;

	    if (!m_pCert) {addError("The certificate is NULL");}
	    else
	    {
	        X509_PUBKEY *pPubKey = X509_get_X509_PUBKEY( m_pCert );
	        if (!pPubKey) {addOpenSSLError();}
	        else
	        {
	            EVP_PKEY *pKey = X509_PUBKEY_get ( pPubKey );
	            if (!pKey) {addOpenSSLError();}
	            else
	            {
	                ret = UaPkiPublicKey(pKey);
	                EVP_PKEY_free(pKey);
	            }
	        }
	    }
#endif

		// extention data
		if (success) {
			uint32_t extCount = X509_get_ext_count(x509Cert_);
			for (uint32_t idx=0; idx<extCount; idx++) {
				X509_EXTENSION *ext = X509_get_ext(x509Cert_, idx);
				if (ext == nullptr) {
					success = false;
					openSSLError();
					break;
				}

				char buff[1024];
				ASN1_OBJECT* object = X509_EXTENSION_get_object(ext);
				OBJ_obj2txt(buff, 1024, object, 0);
				std::cout << "XXXXXX" << buff << std::endl;

				BIO *bio = BIO_new(BIO_s_mem());
				if(!X509V3_EXT_print(bio, ext, 0, 0)){
				    // error handling...
				}

				BUF_MEM *bptr = NULL;
				BIO_flush(bio);
				BIO_get_mem_ptr(bio, &bptr);

				// now bptr contains the strings of the key_usage, take
				// care that bptr->data is NOT NULL terminated, so
				// to print it well, let's do something..
				char *buf = NULL;
				buf = (char *)malloc( (bptr->length + 1)*sizeof(char) );

				memcpy(buf, bptr->data, bptr->length);
				buf[bptr->length] = '\0';

				// Now you can printf it or parse it, the way you want...
				printf ("%s\n", buf);
			}
		}

#if 0


	    if (success) {
	        // sign the certificate
	        const EVP_MD* digest = EVP_sha1();
	        if (!digest) {
	        	success = false;
	        	openSSLError();
	        }

	        if (success) {
	        	EVP_PKEY* pKey = issuerPrivateKey.privateKey();
	            resultCode = X509_sign(x509Cert_, pKey, digest);
	            if (!resultCode) {
		        	success = false;
		        	openSSLError();
		        }
	        }
	    }


	    if (!success) {
	       X509_free (x509Cert_);
	       x509Cert_ = nullptr;
	    }

		return true;
#endif
		return success;
	}

	bool
	PkiCertificate::getX509Name(X509_NAME* name, uint32_t nameId, std::string& value)
	{
		int loc = X509_NAME_get_index_by_NID(name, nameId, -1);
		if (loc == -1) {
	    	openSSLError();
	    	return false;
		}

		X509_NAME_ENTRY* entry = X509_NAME_get_entry(name, loc);
		if (entry == nullptr) {
			openSSLError();
			return false;
		}

		ASN1_STRING* string = X509_NAME_ENTRY_get_data(entry);
		if (string == nullptr) {
			openSSLError();
			return false;
		}

		char* buffer = nullptr;
		int bufferLen = -1;
		bufferLen = ASN1_STRING_to_UTF8((unsigned char**)&buffer, string);
		if (bufferLen < 0) {
			openSSLError();
			return false;
		}
		value = std::string(buffer, bufferLen);

		OPENSSL_free(buffer);

		return true;
	}

	bool
	PkiCertificate::ASN1TimeToPosixTime(ASN1_TIME* asn1Time, boost::posix_time::ptime& ptime)
	{
		uint32_t year;
		uint32_t month;
		uint32_t day;
		uint32_t hour;
		uint32_t min;
		uint32_t sec;

		uint32_t pos = 0;
		if (asn1Time->type == V_ASN1_UTCTIME) {
			year = ((asn1Time->data[pos] - '0') * 10) + (asn1Time->data[pos+1] - '0');
			if (year < 70) year += 2000;
			else year += 1900;
			pos += 2;

		}
		else if (asn1Time->type == V_ASN1_GENERALIZEDTIME) {
			year = ((asn1Time->data[pos] - '0') * 1000) + ((asn1Time->data[pos+1] - '0') * 100) +
				   ((asn1Time->data[pos+2] - '0') * 10) + (asn1Time->data[pos+3] - '0');
			pos += 4;
		}
		else {
			openSSLError("ASN1 time type invalid");
			return false;
		}
		month = ((asn1Time->data[pos] - '0') * 10) + (asn1Time->data[pos+1] - '0'); pos += 2;
		day   = ((asn1Time->data[pos] - '0') * 10) + (asn1Time->data[pos+1] - '0'); pos += 2;
		hour  = ((asn1Time->data[pos] - '0') * 10) + (asn1Time->data[pos+1] - '0'); pos += 2;
		min   = ((asn1Time->data[pos] - '0') * 10) + (asn1Time->data[pos+1] - '0'); pos += 2;
		sec   = ((asn1Time->data[pos] - '0') * 10) + (asn1Time->data[pos+1] - '0'); pos += 2;

		boost::posix_time::ptime t(
			boost::gregorian::date(year, month, day),
			boost::posix_time::time_duration(hour, min, sec)
		);
		ptime = t;
		return true;
	}

	bool
	PkiCertificate::PosixTimeToASN1Time(boost::posix_time::ptime& ptime, ASN1_TIME* asn1Time)
	{
		boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();
		boost::posix_time::time_duration dt = ptime - now;

		if (X509_gmtime_adj(asn1Time, (long)dt.total_seconds()) == nullptr) {
			openSSLError("ASN1 time type invalid");
			return false;
		}
		return true;
	}

	bool
	PkiCertificate::toDERFile(const std::string& derFileName)
	{
	    if (x509Cert_ == nullptr) {
	    	openSSLError("The certificate is NULL");
	    	return false;
	    }

	    BIO* bio = BIO_new(BIO_s_file());
	    if (bio == nullptr) {
	    	openSSLError();
	    	return false;
	    }

	    int resultCode = BIO_write_filename(bio, (void*)derFileName.c_str());
	    if (!resultCode) {
	    	openSSLError();
	    	BIO_free (bio);
	    	return false;
	    }

	    resultCode = i2d_X509_bio(bio, x509Cert_);
	    if (!resultCode) {
	    	openSSLError();
	    	BIO_free (bio);
	    	return false;
	    }

	    BIO_free (bio);
		return true;
	}

	bool
	PkiCertificate::fromDERFile(const std::string& derFileName)
	{
		if (x509Cert_ != nullptr) {
		    X509_free(x509Cert_);
		    x509Cert_ = nullptr;
		}

	    BIO* bio = BIO_new(BIO_s_file());
	    if (bio == nullptr) {
	    	openSSLError();
	    	return false;
	    }

	    int resultCode = BIO_read_filename(bio, (void*)derFileName.c_str());
	    if (!resultCode) {
	    	openSSLError();
	    	BIO_free (bio);
	    	return false;
	    }

	    x509Cert_ = d2i_X509_bio(bio, 0);
	    if (x509Cert_ == nullptr) {
	    	openSSLError();
	    	BIO_free (bio);
	    	return false;
	    }

	    BIO_free (bio);
		return true;
	}

	void
	PkiCertificate::signatureAlgorithm() const
	{

#if 0
	    SignatureAlgorithm sigAlg = SignatureAlgorithm_Sha1;
	    switch (OBJ_obj2nid(m_pCert->sig_alg->algorithm))
	    {
	    case NID_sha1WithRSAEncryption:     sigAlg = SignatureAlgorithm_Sha1; break;
	    case NID_sha256WithRSAEncryption:   sigAlg = SignatureAlgorithm_Sha256; break;
	    case NID_sha384WithRSAEncryption:
	    case NID_sha512WithRSAEncryption:
	    case NID_sha224WithRSAEncryption:
	    default:
	        // not available
	        break;
	    }
	    return sigAlg;
#endif
	}

#if 0
	UaByteString UaPkiCertificate::toByteStringDER() const
	{
	    UaByteString ret;

	    if (!m_pCert) {addError("The certificate is NULL");}
	    else
	    {
	        unsigned char *buf = NULL;
	        long length;

	        length = i2d_X509 ( m_pCert, &buf );
	        if ( length < 0 )
	        {
	            addOpenSSLError();
	        }
	        else
	        {
	            // copy cert data to result
	            ret.setByteString(length, buf);
	            OPENSSL_free(buf);
	        }
	    }

	    return ret;
	}



	UaString UaPkiCertificate::getNameEntryByNID( X509_NAME *pName, int id ) const
	{
	    UaString ret;
	    char    *pBuffer = 0;
	    int      length = -1;
	    int      loc = X509_NAME_get_index_by_NID ( pName, id, -1 );
	    if (loc == -1) {addOpenSSLError();}
	    else
	    {
	        X509_NAME_ENTRY *pEntry = X509_NAME_get_entry ( pName, loc );
	        if (!pEntry) {addOpenSSLError();}
	        else
	        {
	            ASN1_STRING *pString = X509_NAME_ENTRY_get_data ( pEntry );
	            if (!pString) {addOpenSSLError();}
	            else
	            {
	                length = ASN1_STRING_to_UTF8 ( ( unsigned char** ) &pBuffer, pString );
	                if (length < 0) {addOpenSSLError();}
	                else
	                {
	                    ret = pBuffer;
	                    OPENSSL_free ( pBuffer );
	                }
	            }
	        }
	    }
	    return ret;
	}

	UaString UaPkiCertificate::getExtensionByNID(int id) const
	{
	    UaString sRet;
	    if (!m_pCert) {addError("The certificate is NULL");}
	    else
	    {
	        int iPos = X509_get_ext_by_NID(m_pCert, id, -1);
	        if (iPos < 0) {addOpenSSLError();}
	        else
	        {
	            X509_EXTENSION *pExt = X509_get_ext(m_pCert, iPos);

	            BIO *pBio = BIO_new ( BIO_s_mem() );
	            int iRet = X509V3_EXT_print(pBio, pExt, 0, 0);
	            if (!iRet) {addOpenSSLError();}
	            else
	            {
	                BUF_MEM *pBufMem = OpcUa_Null;
	                BIO_get_mem_ptr(pBio, &pBufMem);

	                OpcUa_String *pContent = OpcUa_Null;
	                OpcUa_String_CreateNewString(pBufMem->data,
	                                             (OpcUa_UInt32)pBufMem->length,
	                                             (OpcUa_UInt32)pBufMem->length,
	                                             OpcUa_True,
	                                             OpcUa_True,
	                                             &pContent);

	                sRet = pContent;

	                OpcUa_String_Clear(pContent);
	                OpcUa_Free(pContent);
	            }
	            BIO_free(pBio);
	        }
	    }
	    return sRet;
	}
#endif

}


