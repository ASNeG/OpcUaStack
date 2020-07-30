/*
   Copyright 2018-2020 Kai Huebl (kai@huebl-sgh.de)

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

#include <iostream>
#include "OpcUaStackCore/Certificate/Identity.h"

namespace OpcUaStackCore
{

	Identity::Identity(void)
	: OpenSSLError()
	, organization_("")
	, organizationUnit_("")
	, locality_("")
	, state_("")
	, country_("")
	, commonName_("")
	, domainComponent_("")
	{
	}

	Identity::~Identity(void)
	{
	}

	void
	Identity::organization(const std::string& organization)
	{
		organization_  = organization;
	}

	std::string&
	Identity::organization(void)
	{
		return organization_;
	}

	void
	Identity::organizationUnit(const std::string& organizationUnit)
	{
		organizationUnit_ = organizationUnit;
	}

	std::string&
	Identity::organizationUnit(void)
	{
		return organizationUnit_;
	}

	void
	Identity::locality(const std::string& locality)
	{
		locality_ = locality;
	}

	std::string&
	Identity::locality(void)
	{
		return locality_;
	}

	void
	Identity::state(const std::string& state)
	{
		state_ = state;
	}

	std::string&
	Identity::state(void)
	{
		return state_;
	}

	void
	Identity::country(const std::string& country)
	{
		country_ = country;
	}

	std::string&
	Identity::country(void)
	{
		return country_;
	}

	void
	Identity::commonName(const std::string& commonName)
	{
		commonName_ = commonName;
	}

	std::string&
	Identity::commonName(void)
	{
		return commonName_;
	}

	void
	Identity::domainComponent(const std::string& domainComponent)
	{
		domainComponent_ = domainComponent;
	}

	std::string&
	Identity::domainComponent(void)
	{
		return domainComponent_;
	}

	Identity&
	Identity::operator=(const Identity& value)
	{
   		organization_ = value.organization_;
		organizationUnit_ = value.organizationUnit_;
		locality_ = value.locality_;
		state_ = value.state_;
		country_ = value.country_;
		commonName_ = value.commonName_;
		domainComponent_ = value.domainComponent_;
		return *this;
	}

    bool
	Identity::operator==(const Identity &identity) const
	{
    	return (
    		organization_ == identity.organization_			&&
			organizationUnit_ == identity.organizationUnit_	&&
			locality_ == identity.locality_ 				&&
			state_ == identity.state_						&&
			country_ == identity.country_					&&
			commonName_ == identity.commonName_				&&
			domainComponent_ == identity.domainComponent_
    	);
	}
    bool
	Identity::operator!=(const Identity &identity) const
	{
    	return !operator==(identity);
	}

    bool
	Identity::isEmpty(void) const
    {
    	return (
    		organization_.size() == 0						&&
			organizationUnit_.size() == 0					&&
			locality_.size() == 0							&&
			state_.size() == 0								&&
			country_.size() == 0							&&
			commonName_.size() == 0							&&
			domainComponent_.size() == 0
		);
    }

    void
	Identity::log(const std::string& message)
    {
    	Log(Debug, message)
    	    .parameter("CommonName", commonName_)
			.parameter("Organization", organization_)
			.parameter("OrganizationUnit", organizationUnit_)
			.parameter("Locality", locality_)
			.parameter("State", state_)
			.parameter("Countery", country_)
			.parameter("DomainComponent", domainComponent_);
    }

    X509_NAME*
	Identity::encodeX509(void)
    {
        X509_NAME *name = X509_NAME_new();
        if (name == nullptr) {
        	return nullptr;
        }

        int32_t result = 1;

        // set domain component
        if (result) {
        	result = encodeX509(name, "DC", domainComponent_);
        }

        // set country
        if (result) {
        	result = encodeX509(name, "C", country_);
        }

        // set state
        if (result) {
        	result = encodeX509(name, "ST", state_);
        }

        // set locality
        if (result) {
        	result = encodeX509(name, "L", locality_);
        }

        // set organization
        if (result) {
        	result = encodeX509(name, "O", organization_);
        }

        // set organization unit
        if (result) {
        	result = encodeX509(name, "OU", organizationUnit_);
        }

        // set common name
        if (result) {
        	result = encodeX509(name, "CN", commonName_);
        }

        if (!result) {
            X509_NAME_free(name);
            return nullptr;
        }

        return name;
    }

    bool
	Identity::decodeX509(X509_NAME* name)
    {
    	if (!decodeX509(name, NID_domainComponent, domainComponent_, true)) return false;
    	if (!decodeX509(name, NID_countryName, country_, true)) return false;
    	if (!decodeX509(name, NID_stateOrProvinceName, state_, true)) return false;
    	if (!decodeX509(name, NID_localityName, locality_, true)) return false;
    	if (!decodeX509(name, NID_organizationName, organization_, true)) return false;
    	if (!decodeX509(name, NID_organizationalUnitName, organizationUnit_, true)) return false;
    	if (!decodeX509(name, NID_commonName, commonName_)) return false;
    	return true;
    }

    int32_t
	Identity::encodeX509(
		X509_NAME* name,
		const std::string& key,
		const std::string& value,
		bool optional
	)
    {
    	if (optional && value.empty()) {
    		return 1;
    	}

    	int32_t result = 1;
        if (key.length() > 0) {
            result = X509_NAME_add_entry_by_txt(name, key.c_str(), MBSTRING_UTF8, (const unsigned char*)value.c_str(), -1, -1, 0);
			if (!result) {
				addOpenSSLError();
			}
        }
        return result;
    }

    bool
	Identity::decodeX509(
		X509_NAME* name,
		int32_t id,
		std::string& value,
		bool optional
	)
    {
    	int32_t entryId = X509_NAME_get_index_by_NID(name, id, -1);
    	if (entryId == -1) {
    		if (optional) {
    		    value = "";
    		    return true;
    		}

    		addOpenSSLError();
    		std::stringstream message;
    		message << "object " << id << " not found in identity decoder";
    		addError(message.str());
    		return false;
    	}

    	 X509_NAME_ENTRY* entry = X509_NAME_get_entry(name, entryId);
    	 if (!entry) {
    		 addOpenSSLError();
     		 std::stringstream message;
     		 message << "entry " << id << " not found in identity decoder";
     		 addError(message.str());
    		 return false;
    	 }

    	 ASN1_STRING* asn1String = X509_NAME_ENTRY_get_data(entry);
    	 if (!asn1String) {
    		 addOpenSSLError();
     		 std::stringstream message;
     		 message << "data " << id << " not found in identity decoder";
     		 addError(message.str());
    		 return false;
    	 }

    	 unsigned char* buf;
    	 int32_t bufLen;

    	 bufLen = ASN1_STRING_to_UTF8(( unsigned char**)&buf, asn1String);
    	 if (bufLen < 0) {
    		 addOpenSSLError();
    		 return false;
    	 }

    	 std::string str((char*)buf, bufLen);
    	 value = str;
    	 return true;
    }

}
