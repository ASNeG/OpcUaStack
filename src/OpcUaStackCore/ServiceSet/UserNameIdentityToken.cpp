/*
   Copyright 2015-2018 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSet/UserNameIdentityToken.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// UserNameIdentityToken
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	UserNameIdentityToken::UserNameIdentityToken(void)
	: Object()
	, ExtensibleParameterBase()
	{
	}

	UserNameIdentityToken::~UserNameIdentityToken(void)
	{
	}

	void 
	UserNameIdentityToken::policyId(const std::string& policyId)
	{
		policyId_ = policyId;
	}

	std::string 
	UserNameIdentityToken::policyId(void) const
	{
		return policyId_.value();
	}
		
	void 
	UserNameIdentityToken::userName(const std::string& userName)
	{
		userName_ = userName;
	}
		
	std::string 
	UserNameIdentityToken::userName(void) const
	{
		return userName_.value();
	}
		
	void 
	UserNameIdentityToken::password(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		password_.value(buf, bufLen);
	}

	void 
	UserNameIdentityToken::password(OpcUaByte** buf, OpcUaInt32* bufLen) const
	{
		password_.value(buf, bufLen);
	}

	std::string
	UserNameIdentityToken::password() const
	{
		char* buf;
		int32_t bufLen;

		password_.value((OpcUaByte**)&buf, (OpcUaInt32*)&bufLen);
		return std::string(buf, bufLen);
	}



	uint32_t
	UserNameIdentityToken::passwordLen(void)
	{
		return password_.size();
	}

	void 
	UserNameIdentityToken::encryptionAlgorithm(const std::string& encryptionAlgorithm)
	{
		encryptionAlgorithm_ = encryptionAlgorithm;
	}

	std::string 
	UserNameIdentityToken::encryptionAlgorithm(void) const
	{
		return encryptionAlgorithm_.value();
	}

	
	ExtensibleParameterBase::SPtr
	UserNameIdentityToken::factory(void)
	{
		return constructSPtr<UserNameIdentityToken>();
	}

	void 
	UserNameIdentityToken::opcUaBinaryEncode(std::ostream& os) const
	{
		policyId_.opcUaBinaryEncode(os);
		userName_.opcUaBinaryEncode(os);
		password_.opcUaBinaryEncode(os);
		encryptionAlgorithm_.opcUaBinaryEncode(os);
	}

	void 
	UserNameIdentityToken::opcUaBinaryDecode(std::istream& is)
	{
		policyId_.opcUaBinaryDecode(is);
		userName_.opcUaBinaryDecode(is);
		password_.opcUaBinaryDecode(is);
		encryptionAlgorithm_.opcUaBinaryDecode(is);
	}

}
