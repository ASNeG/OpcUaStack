/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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

    X509_NAME*
	Identity::encodeX509(void)
    {
        X509_NAME *name = X509_NAME_new();
        if (name == nullptr) {
        	return nullptr;
        }

        int result = 1;

        // set domain component
        if (result && domainComponent_.length() > 0) {
            result = X509_NAME_add_entry_by_txt(name, "DC", MBSTRING_UTF8, (const unsigned char*)domainComponent_.c_str(), -1, -1, 0);
			if (!result) {
				addOpenSSLError();
			}
        }

        // set country
        if (result && country_.length() > 0) {
            result = X509_NAME_add_entry_by_txt(name, "C", MBSTRING_UTF8, (const unsigned char*)country_.c_str(), -1, -1, 0);
			if (!result) {
				addOpenSSLError();
			}
        }

        // set state
        if (result && state_.length() > 0) {
            result = X509_NAME_add_entry_by_txt(name, "ST", MBSTRING_UTF8, (const unsigned char*)state_.c_str(), -1, -1, 0);
			if (!result) {
				addOpenSSLError();
			}
        }

        // set locality
        if (result && locality_.length() > 0) {
            result = X509_NAME_add_entry_by_txt(name, "L", MBSTRING_UTF8, (const unsigned char*)locality_.c_str(), -1, -1, 0);
			if (!result) {
				addOpenSSLError();
			}
        }

        // set organization
        if (result && organization_.length() > 0) {
            result = X509_NAME_add_entry_by_txt(name, "O", MBSTRING_UTF8, (const unsigned char*)organization_.c_str(), -1, -1, 0);
			if (!result) {
				addOpenSSLError();
			}
        }

        // set organization unit
        if (result && organizationUnit_.length() > 0) {
            result = X509_NAME_add_entry_by_txt(name, "OU", MBSTRING_UTF8, (const unsigned char*)organizationUnit_.c_str(), -1, -1, 0);
			if (!result) {
				addOpenSSLError();
			}
        }

        // set common name
        if (result && commonName_.length() > 0) {
            result = X509_NAME_add_entry_by_txt(name, "CN", MBSTRING_UTF8, (const unsigned char*)commonName_.c_str(), -1, -1, 0);
			if (!result) {
				addOpenSSLError();
			}
        }

        if (!result) {
            X509_NAME_free(name);
            return nullptr;
        }

        return name;
    }

}
