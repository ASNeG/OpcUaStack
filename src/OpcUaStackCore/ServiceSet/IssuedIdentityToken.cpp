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

#include "OpcUaStackCore/ServiceSet/IssuedIdentityToken.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// IssuedIdentityToken
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	IssuedIdentityToken::IssuedIdentityToken(void)
	: Object()
	, ExtensibleParameterBase()
	{
	}

	IssuedIdentityToken::~IssuedIdentityToken(void)
	{
	}

	void 
	IssuedIdentityToken::policyId(const std::string& policyId)
	{
		policyId_ = policyId;
	}

	std::string 
	IssuedIdentityToken::policyId(void) const
	{
		return policyId_.value();
	}

	void 
	IssuedIdentityToken::tokenData(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		tokenData_.value(buf, bufLen);
	}

	void 
	IssuedIdentityToken::tokenData(OpcUaByte** buf, OpcUaInt32* bufLen) const
	{
		tokenData_.value(buf, bufLen);
	}

	OpcUaByteString&
	IssuedIdentityToken::tokenData(void)
	{
		return tokenData_;
	}
		
	void 
	IssuedIdentityToken::encryptionAlgorithm(const std::string& encryptionAlgorithm)
	{
		encryptionAlgorithm_ = encryptionAlgorithm;
	}

	std::string 
	IssuedIdentityToken::encryptionAlgorithm(void) const
	{
		return encryptionAlgorithm_.value();
	}

	
	ExtensibleParameterBase::SPtr
	IssuedIdentityToken::factory(void)
	{
		return constructSPtr<IssuedIdentityToken>();
	}

	void 
	IssuedIdentityToken::opcUaBinaryEncode(std::ostream& os) const
	{
		policyId_.opcUaBinaryEncode(os);
		tokenData_.opcUaBinaryEncode(os);
		encryptionAlgorithm_.opcUaBinaryEncode(os);
	}

	void 
	IssuedIdentityToken::opcUaBinaryDecode(std::istream& is)
	{
		policyId_.opcUaBinaryDecode(is);
		tokenData_.opcUaBinaryDecode(is);
		encryptionAlgorithm_.opcUaBinaryDecode(is);
	}

}
