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

#include "OpcUaStackCore/Certificate/UserExtensionObject.h"
#include "OpcUaStackCore/Base/Log.h"

namespace OpcUaStackCore
{

	UserExtensionObject::UserExtensionObject(void)
	: OpenSSLError()
	{
	}

	UserExtensionObject::~UserExtensionObject(void)
	{
	}

    bool
	UserExtensionObject::registerUserExtension(
    	uint32_t nid,
		const std::string& oid,
		const std::string& shortName,
		const std::string& longName
    )
    {
    	// Convert oid to ASN1 object
		ASN1_OBJECT* oidObj = OBJ_txt2obj(oid.c_str(), 0);
		if (oidObj == nullptr) {
			addOpenSSLError();
			return false;
		}

		// Create user extension type object
		ASN1_OBJECT* typeObj = ASN1_OBJECT_create(
			nid + OBJ_new_nid(0),
			(unsigned char*)OBJ_get0_data(oidObj),
			OBJ_length(oidObj),
			shortName.c_str(),
			longName.c_str()
		);
		if (typeObj == nullptr) {
			ASN1_OBJECT_free(oidObj);
			addOpenSSLError();
			return false;
		}

		// Register user extension type object
	    int new_nid = OBJ_add_object(typeObj);
	    if (new_nid == NID_undef) {
	    	ASN1_OBJECT_free(oidObj);
	    	ASN1_OBJECT_free(typeObj);
	    	return false;
	    }

    	ASN1_OBJECT_free(oidObj);
    	ASN1_OBJECT_free(typeObj);
    	return true;
    }

}
