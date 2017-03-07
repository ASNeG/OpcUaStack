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
	// OpcUaX509
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaX509::OpcUaX509(void)
	: PkiError()
	{
	}

	OpcUaX509::~OpcUaX509(void)
	{
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

}




