/*
   Copyright 2022 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/tokenizer.hpp>

#include <iostream>
#include <sstream>

#include "OpcUaStackCore/Certificate/UserExtensionOpenSSL.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	UserExtensionOpenSSL::UserExtensionOpenSSL(uint32_t nid)
	: UserExtension()
	, OpenSSLError()
	{
		nid_ = nid;
	}

	UserExtensionOpenSSL::~UserExtensionOpenSSL(void)
	{
		if (ex_ != nullptr) {
			X509_EXTENSION_free(ex_);
			ex_ = NULL;
		}
	}

	bool
	UserExtensionOpenSSL::encodeExtensionData(void)
	{
		// Create new X509 extension
		if (ex_ != nullptr) {
			X509_EXTENSION_free(ex_);
			ex_ = NULL;
		}

		// Create extension string from entry map
		std::stringstream ss;
		for (auto it : entryMap_) {
			if (ss.str().size() != 0) ss << "/";
			ss << it.first << ":" << it.second;
		}

	    ASN1_OCTET_STRING* data0 = ASN1_OCTET_STRING_new();
	    ASN1_OCTET_STRING_set(data0, (unsigned char *)ss.str().c_str(), ss.str().size());

	    // Create extension
		ex_ = X509_EXTENSION_create_by_NID(nullptr, nid_ + OBJ_new_nid(0), 0, data0);
	    if (ex_ == NULL) {
	    	Log(Error, "encode extension error, because create extension failed");
	    	X509_EXTENSION_free(ex_);
	    	ex_ = NULL;
	        return false;
	    }

		return true;
	}

	bool
	UserExtensionOpenSSL::decodeExtensionData(void)
	{
		// Check parameter
		if (ex_ == nullptr) {
			Log(Error, "decode extension error, because extension not exist");
			return false;
		}

		// Get and check nid from extension
		ASN1_OBJECT* obj = X509_EXTENSION_get_object(ex_);
		if (obj == nullptr) {
			Log(Error, "decode extension error, because obj not found");
			return false;
		}

		// Read octet string from extension
		ASN1_OCTET_STRING* extOctetString = X509_EXTENSION_get_data(ex_);
		if (obj == nullptr) {
			Log(Error, "decode extension error, because data not found");
			return false;
		}

		// Convert octet string to extension string
		std::string str((char*)extOctetString->data, extOctetString->length);

		// Create entry map from extension string
		boost::char_separator<char> sep("/");
		boost::tokenizer<boost::char_separator<char> > tokens(str, sep);
		for (auto token : tokens) {
			size_t pos = token.find(":");
			if (pos == std::string::npos) continue;
			std::string name = token.substr(0, pos);
			std::string value = token.substr(pos+1, token.length() - pos - 1);
			entryMap_.insert(std::make_pair(name, value));
		}

		return true;
	}

	bool
	UserExtensionOpenSSL::encodeX509UserExtension(X509 *cert)
	{
		// Create user extension object
		if (!encodeExtensionData()) {
			addError("encode user extension data error");
			return false;
		}

		// Add user extension object to certificate
		int32_t result = X509_add_ext(cert, ex_, -1);
 		if (!result) {
 			addOpenSSLError();
			return false;
		}

		return true;
	}

	bool
	UserExtensionOpenSSL::decodeX509UserExtension(X509 *cert)
	{
		// Get user extension from certificate
	    int32_t pos = X509_get_ext_by_NID(cert, nid_ + OBJ_new_nid(0), -1);
		if (pos < 0) {
			addOpenSSLError();
			return false;
		}

		ex_ = X509_get_ext(cert, pos);
		if (ex_ == nullptr) {
			addOpenSSLError();
			return false;
		}

		// Get data from user extension
		if (!decodeExtensionData()) {
			ex_ = nullptr;
			addError("decode user extension data error");
			return false;
		}

		ex_ = nullptr;
		return true;
	}

}
