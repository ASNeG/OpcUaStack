/*
   Copyright 2023 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), Aleksey Timin (atimin@gmail.com)
 */

#include "OpcUaStackCore/Certificate/CSR.h"
#include "OpcUaStackCore/Certificate/X509Extension.h"
#include "OpcUaStackCore/Certificate/UserExtensionOpenSSL.h"

namespace OpcUaStackCore
{

	CSR::CSR(void)
	: OpenSSLError()
	{
	}

	CSR::~CSR(void)
	{
		if (req_ != nullptr) {
			X509_REQ_free(req_);
			req_ = nullptr;
		}
	}

	bool
	CSR::createCSR(
		Identity& subject,
		CertificateInfo& info,
		PublicKey& publicKey,
		PrivateKey& privateKey,
		UserExtension::Vec* userExtensionVec
	)
	{
		bool error = false;
		int32_t result = 0;
		STACK_OF(X509_EXTENSION)* exts = nullptr;
		assert(req_ == nullptr);


		/* Create X509 certificate request */
		req_ = X509_REQ_new();
		if (req_ == NULL) {
			addError("create certificate signing request error in constructor");
		    return false;
		}

		// set version
		if (!error) {
			result = X509_REQ_set_version(req_, 2);
			if (!result) {
				error = true;
				addOpenSSLError();
				addError("call X509_REQ_set_version error");
			}
		}

		// Create extensions
		if (!error) {
			X509Extension x509Extension;
			exts = sk_X509_EXTENSION_new_null();

			// set subject alternative name
			x509Extension.subjectAltName(info.subjectAltName());

			// set key usage
			x509Extension.keyUsage("digitalSignature,nonRepudiation,keyEncipherment,dataEncipherment");

			// Encode extension
            x509Extension.logContent(std::string("create CSR ") + subject.commonName());
            if (!x509Extension.encode(req_, exts)) {
            	error = true;
            	addError(x509Extension.errorList());
            	addError("encode X509 extension error");
            	if (exts) sk_X509_EXTENSION_free(exts);
            }
		}

        // Create user extensions
        if (!error && userExtensionVec != nullptr) {
        	for (auto userExtension : *userExtensionVec) {
        		auto ext = boost::static_pointer_cast<UserExtensionOpenSSL>(userExtension);
        		ext->logContent(std::string("create user extension"));
        		if (!ext->encodeX509UserExtension(req_, exts)) {
        			error = true;
        			addError(ext->errorList());
        			addError("encode X509 user extension error");
        			sk_X509_EXTENSION_free(exts);
        		}
        	}
        }

		// Add extensions to request
        if (!error) {
        	int result = X509_REQ_add_extensions(req_, exts);
        	if (!result) {
        		error = true;
        		addOpenSSLError();
        		addError("call X509_REQ_add_extensions error");
        	}

        	sk_X509_EXTENSION_free(exts);
        }

		// Set subject
        if (!error) {
            X509_NAME *name = subject.encodeX509();
            if (!name) {
            	error = true;
            	addError(subject.errorList());
            }
            else {
                result = X509_REQ_set_subject_name(req_, name);
                if (!result) {
                	error = true;
                	addOpenSSLError();
                	addError("call X509_REQ_set_subject_name error");
                }
                X509_NAME_free(name);
            }
        }

		// Set public key
        if (!error) {
        	if (!X509_REQ_set_pubkey(req_, publicKey)) {
        		error = true;
        		addOpenSSLError();
        		addError("call X509_REQ_set_pubkey error");
        	}
        }

		// Sign CSR with private key
        if (!error) {
        	if (!X509_REQ_sign(req_, privateKey, EVP_sha256())) {
        		error = true;
        		addOpenSSLError();
        		addError("call X509_REQ_sign error");
        	}
        }

        if (error) {
        	X509_REQ_free(req_);
        	req_ = nullptr;
        }
		return !error;
	}

	bool
	CSR::getSubject(Identity& subject)
	{
		if (req_ == nullptr) {
			addError("certificate request is empty");
			return false;
		}

		X509_NAME* name = X509_REQ_get_subject_name(req_);
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
	CSR::getInfo(CertificateInfo& info)
	{
		if (req_ == nullptr) {
			addError("certificate request is empty");
			return false;
		}

		// Decode extension
		X509Extension ext;
		if (!ext.decode(req_)) {
			addError(ext.errorList());
			return false;
		}

		// Get subject alternative name
		info.subjectAltName(ext.subjectAltName());

		return true;
	}

	bool
	CSR::getPublicKey(PublicKey& publicKey)
	{
		if (req_ == nullptr) {
			addError("certificate request is empty");
			return false;
		}

		// Get public key
		EVP_PKEY* pKey = X509_REQ_get_pubkey(req_);
		if (pKey == nullptr) {
			addError("get public key error");
			return false;
		}
		PublicKey pulicKeyTmp(pKey);

		publicKey = pulicKeyTmp;
		return true;
	}

	bool
	CSR::getUserExtension(UserExtension::SPtr& userExtension)
	{
		if (req_ == nullptr) {
			addError("certificate requestis empty");
			return false;
		}

		UserExtensionOpenSSL::SPtr userExtensionOpenSSL =
			boost::static_pointer_cast<UserExtensionOpenSSL>(userExtension);

		// Get object from user extension
		if (!userExtensionOpenSSL->decodeX509UserExtension(req_)) {
			addError("decode user extension error");
			return false;
		}
		userExtensionOpenSSL->logContent(std::string("get user extension"));

		return true;
	}

	bool
	CSR::toDERBuf(MemoryBuffer& derBuf)
	{
		// Check parameter
		if (req_ == nullptr) {
			addError("CSR is empty");
			return false;
		}

		// Determine necessary length for CSR buffer
		int size = i2d_X509_REQ(req_, 0);
		if (size < 0) {

		    return false;
		}

		// Create CSR buffer in DER format
		derBuf.resize(size);
		if (derBuf.memLen() <= 0) {
			Log(Error, "DER buffer empty");
			return false;
		}
		char* ptr = derBuf.memBuf();
		i2d_X509_REQ(req_, (unsigned char**)&ptr);

		return true;
	}

	bool
	CSR::fromDERBuf(MemoryBuffer& derBuf)
	{
		if (req_ != nullptr) {
			addError("certificate is not empty");
			return false;
		}
		char* ptr =derBuf.memBuf();
        req_= d2i_X509_REQ(0, (const unsigned char**)&ptr, derBuf.memLen());
        if (req_ == nullptr) {
        	addOpenSSLError();
        	return false;
        }

		return true;
	}

	bool
	CSR::validateSignature(PublicKey& publicKey)
	{
		// Check parameter
		if (req_ == nullptr) {
			Log(Error, "key is null");
			return false;
		}

		// Get public key
		EVP_PKEY* pubkey = publicKey;
		if (pubkey == nullptr) {
			Log(Error, "public key is null");
			return false;
		}

		// Verify signature
		int32_t result = X509_REQ_verify(req_, pubkey);
		if (result <= 0) {
		    const_cast<CSR*>(this)->addOpenSSLError();
		}

	    if (result <= 0) {
	        return false;
	    }

		return true;
	}

}
