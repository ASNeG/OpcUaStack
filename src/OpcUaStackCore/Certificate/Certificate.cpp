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

namespace OpcUaStackCore
{

	Certificate::Certificate(void)
	: OpenSSLError()
	, cert_(nullptr)
	{
	}

	Certificate::Certificate(
		const Info& info,
		const Identity& subject,
	    const RSAKey&rsaKey,
	    bool bCACert,
	    SignatureAlgorithm signatureAlgorithm
	)
	: cert_(nullptr)
	{
		// FIXME: todo

#if 0
	    m_pCert = X509_new();
	    if (m_pCert)
	    {
	        bool bError = false;
	        int iRet = 0;

	        if (!bError)
	        {
	            iRet = X509_set_version ( m_pCert, 2 ); /* Set version to V3 (yes 2=V3)*/
	            if (!iRet) {bError = true; addOpenSSLError();}
	        }

	        if (!bError)
	        {
	            long serialNumber = info.serialNumber;
	            if (serialNumber == 0)
	            {
	                serialNumber = (long)time(NULL);
	            }
	            iRet = ASN1_INTEGER_set ( X509_get_serialNumber ( m_pCert ), serialNumber );
	            if (!iRet) {bError = true; addOpenSSLError();}
	        }

	        if (!bError)
	        {
	            X509_NAME *pName = createX509_NAME(subject);
	            if (!pName) {bError = true; addOpenSSLError();}
	            else
	            {
	                iRet = X509_set_subject_name ( m_pCert, pName );
	                if (!iRet) {bError = true; addOpenSSLError();}
	                iRet = X509_set_issuer_name ( m_pCert, pName );
	                if (!iRet) {bError = true; addOpenSSLError();}
	                X509_NAME_free ( pName );
	            }
	        }

	        if (!bError)
	        {
	            X509_gmtime_adj ( X509_get_notBefore ( m_pCert ), info.validFrom );
	            X509_gmtime_adj ( X509_get_notAfter ( m_pCert ), info.validTime );
	        }

	        if (!bError)
	        {
	            // set public key
	            EVP_PKEY *pKey = (EVP_PKEY*)subjectKeyPair.publicKey();
	            iRet = X509_set_pubkey ( m_pCert, pKey );
	            if (!iRet) {bError = true; addOpenSSLError();}
	            EVP_PKEY_free( pKey );
	        }

	        X509V3_CTX ctx;
	        X509V3_set_ctx ( &ctx, m_pCert, m_pCert, NULL, NULL, 0 );
	        if (!bError)
	        {
	            X509_EXTENSION *pExt = 0;

	            if (bCACert == false)
	            {
	                /* add x509v3 extensions as specified */
	                for ( int i = 0; i < ext_ent_count; i++ )
	                {
	                    pExt = X509V3_EXT_conf ( NULL, &ctx, (char*)ext_ent[i].key, (char*)ext_ent[i].value );
	                    if (!pExt) {bError = true; addOpenSSLError();}
	                    else
	                    {
	                        iRet = X509_add_ext ( m_pCert, pExt, -1 );
	                        if (!iRet) {bError = true; addOpenSSLError();}
	                        X509_EXTENSION_free ( pExt );
	                    }
	                }
	            }
	            else
	            {
	                /* add x509v3 CA extensions as specified */
	                for ( int i = 0; i < ca_ext_ent_count; i++ )
	                {
	                    pExt = X509V3_EXT_conf ( NULL, &ctx, (char*)ca_ext_ent[i].key, (char*)ca_ext_ent[i].value );
	                    if (!pExt) {bError = true; addOpenSSLError();}
	                    else
	                    {
	                        iRet = X509_add_ext ( m_pCert, pExt, -1 );
	                        if (!iRet) {bError = true; addOpenSSLError();}
	                        X509_EXTENSION_free ( pExt );
	                    }
	                }
	            }
	        }

	        if (!bError && bCACert == false)
	        {
	            X509_EXTENSION *pExt = createSubjectAltName(&ctx, info);
	            if (pExt)
	            {
	                iRet = X509_add_ext ( m_pCert, pExt, -1 );
	                if (!iRet) {bError = true; addOpenSSLError();}
	                X509_EXTENSION_free ( pExt );
	            }
	            else { bError = true; addOpenSSLError(); }
	        }

	        if (!bError)
	        {
	            // sign the certificate
	            EVP_PKEY *pKey = ( EVP_PKEY* ) ( const EVP_PKEY* ) subjectKeyPair.privateKey();
	            if (signatureAlgorithm == SignatureAlgorithm_Sha1)
	            {
	                iRet = X509_sign ( m_pCert, pKey, EVP_sha1() );
	            }
	            else
	            {
	                iRet = X509_sign ( m_pCert, pKey, EVP_sha256() );
	            }
	            if (!iRet) {bError = true; addOpenSSLError();}
	        }

	        if (bError)
	        {
	            X509_free ( m_pCert );
	            m_pCert = 0;
	        }
	    }
#endif
	}

	Certificate::~Certificate(void)
	{
	}



}
