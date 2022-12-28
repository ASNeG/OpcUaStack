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

	UserExtensionOpenSSL::UserExtensionOpenSSL(void)
	: UserExtension()
	{
	}

	UserExtensionOpenSSL::~UserExtensionOpenSSL(void)
	{
		if (ex_ != nullptr) {
			X509_EXTENSION_free(ex_);
		}
	}

	void
	UserExtensionOpenSSL::setExtension(X509_EXTENSION* ex)
	{
		ex_ = ex;
	}

	X509_EXTENSION*
	UserExtensionOpenSSL::getExtension(void)
	{
		return ex_;
	}

	bool
	UserExtensionOpenSSL::encodeExtention(void)
	{
		// Check parameter
		if (ex_ != nullptr) {
			Log(Error, "encode extension error, because extension already exist");
			return false;
		}

		// Create extension string from entry map
		std::stringstream ss;
		for (auto it : entryMap_) {
			if (ss.str().size() != 0) ss << "/";
			ss << it.first << ":" << it.second;
		}

		// Convert extension string to octet string
		ASN1_OCTET_STRING* extOctetString = ASN1_OCTET_STRING_new();
		if (extOctetString == nullptr) {
			Log(Error, "encode extension error, because create octet string failed");
			return false;
		}
		int rc = ASN1_OCTET_STRING_set(extOctetString, (unsigned char *)ss.str().c_str(), ss.str().size());
		if (rc != 1) {
			ASN1_OCTET_STRING_free(extOctetString);
			Log(Error, "encode extension error, because set octet string failed");
			return false;
		}

	    // Create extension
		ex_ = X509_EXTENSION_create_by_NID(&ex_, nid_, 0, extOctetString);
	    if (ex_ == NULL) {
	    	Log(Error, "encode extension error, because create extension failed");
	    	ASN1_OCTET_STRING_free(extOctetString);
	    	X509_EXTENSION_free(ex_);
	    	ex_ = NULL;
	        return false;
	    }

	    ASN1_OCTET_STRING_free(extOctetString);
		return true;
	}

	bool
	UserExtensionOpenSSL::decodeExtention(void)
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

}
