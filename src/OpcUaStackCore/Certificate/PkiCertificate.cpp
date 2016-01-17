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
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Certificate/PkiCertificate.h"

namespace OpcUaStackCore
{

	bool PkiCertificate::loadCryptoStrings_ = false;
	std::list<std::string> PkiCertificate::cryptoStringErrorList_;


	PkiCertificate::PkiCertificate(void)
	: x509Cert_(nullptr)
	{
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
			time_t startTime = time(NULL);
			resultCode = ASN1_INTEGER_set(X509_get_serialNumber(x509Cert_), (long)startTime);
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
            X509_gmtime_adj(X509_get_notBefore(x509Cert_), 0);
            X509_gmtime_adj(X509_get_notAfter(x509Cert_), (long)pkiCertificateInfo.validTime());
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

	 #ifdef CREATE_EXTENSIONS
	        X509V3_CTX ctx;
	        X509V3_set_ctx ( &ctx, m_pCert, m_pCert, NULL, NULL, 0 );
	        if (!bError)
	        {
	            X509_EXTENSION *pExt = 0;

	            /* add x509v3 extensions as specified */
	            for ( int i = 0; i < EXT_COUNT; i++ )
	            {
	                pExt = X509V3_EXT_conf ( NULL, &ctx, (char*)ext_ent[i].key, (char*)ext_ent[i].value );
	                if (!pExt) {bError = true; addOpenSSLError();}
	                else
	                {
	                    resultCode = X509_add_ext ( m_pCert, pExt, -1 );
	                    if (!resultCode) {bError = true; addOpenSSLError();}
	                    X509_EXTENSION_free ( pExt );
	                }
	            }
	        }

	        if (!bError)
	        {
	            // add subjectAltName
	            UaString subjectAltNameValue;
	            if ( !info.URI.isEmpty() )
	            {
	                subjectAltNameValue += "URI:";
	                subjectAltNameValue += info.URI; // URI is absolutely mandatory
	            }
	            for (OpcUa_UInt32 i = 0; i < info.DNSNames.length(); i++)
	            {
	                subjectAltNameValue += ",DNS:";
	                subjectAltNameValue += info.DNSNames[i];
	            }
	            for (OpcUa_UInt32 i = 0; i < info.IPAddresses.length(); i++)
	            {
	                subjectAltNameValue += ",IP:";
	                subjectAltNameValue += info.IPAddresses[i];
	            }
	            if ( !info.eMail.isEmpty() )
	            {
	                subjectAltNameValue += ",email:";
	                subjectAltNameValue += info.eMail;
	            }
	            X509_EXTENSION *pExt = X509V3_EXT_conf ( NULL, &ctx, (char*)"subjectAltName", ( char* ) subjectAltNameValue.toUtf8() );
	            if (!pExt) {bError = true; addOpenSSLError();}
	            else
	            {
	                resultCode = X509_add_ext ( m_pCert, pExt, -1 );
	                if (!resultCode) {bError = true; addOpenSSLError();}
	                X509_EXTENSION_free ( pExt );
	            }
	        }
	#endif


	    if (success) {
	        // sign the certificate
	        const EVP_MD* digest = EVP_sha1();
	        if (!digest) {
	        	success = false;
	        	openSSLError();
	        }
	        else {
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
	PkiCertificate::toDERFile(const std::string& derFileName)
	{
	    if (x509Cert_ == nullptr) {
	    	openSSLError("The certificate is NULL");
	    	return false;
	    }

	    BIO* bio = BIO_new(BIO_s_file());
	    if (bio == nullptr)
	    {
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
	    if (bio == nullptr)
	    {
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

}


