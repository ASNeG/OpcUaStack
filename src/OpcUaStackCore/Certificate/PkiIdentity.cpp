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

#include "OpcUaStackCore/Certificate/PkiIdentity.h"

namespace OpcUaStackCore
{

	PkiIdentity::PkiIdentity(void)
    : organization_("")
    , organizationUnit_("")
    , locality_("")
    , state_("")
    , country_("")
    , commonName_("")
    , domainComponent_("")
	{
	}

	PkiIdentity::~PkiIdentity(void)
	{
	}

	void
	PkiIdentity::organization(const std::string& organization)
	{
		organization_ = organization;
	}

	std::string&
	PkiIdentity::organization(void)
	{
		return organization_;
	}

	void
	PkiIdentity::organizationUnit(const std::string& organizationUnit)
	{
		organizationUnit_ = organizationUnit;
	}

	std::string&
	PkiIdentity::organizationUnit(void)
	{
		return organizationUnit_;
	}

	void
	PkiIdentity::locality(const std::string& locality)
	{
		locality_ = locality;
	}

	std::string&
	PkiIdentity::locality(void)
	{
		return locality_;
	}

	void
	PkiIdentity::state(const std::string& state)
	{
		state_ = state;
	}

	std::string&
	PkiIdentity::state(void)
	{
		return state_;
	}

	void
	PkiIdentity::country(const std::string& country)
	{
		country_ = country;
	}

	std::string&
	PkiIdentity::country(void)
	{
		return country_;
	}

	void
	PkiIdentity::commonName(const std::string& commonName)
	{
		commonName_ = commonName;
	}

	std::string&
	PkiIdentity::commonName(void)
	{
		return commonName_;
	}

	void
	PkiIdentity::domainComponent(const std::string& domainComponent)
	{
		domainComponent_ = domainComponent;
	}

	std::string&
	PkiIdentity::domainComponent(void)
	{
		return domainComponent_;
	}

	bool
	PkiIdentity::operator==(const PkiIdentity &other) const
	{
		return (
		    organization_ == const_cast<PkiIdentity&>(other).organization() &&
			organizationUnit_ == const_cast<PkiIdentity&>(other).organizationUnit() &&
			locality_ == const_cast<PkiIdentity&>(other).locality() &&
			state_ == const_cast<PkiIdentity&>(other).state() &&
			country_ == const_cast<PkiIdentity&>(other).country() &&
			commonName_ == const_cast<PkiIdentity&>(other).commonName() &&
			domainComponent_ == const_cast<PkiIdentity&>(other).domainComponent()
		);
	}

}

