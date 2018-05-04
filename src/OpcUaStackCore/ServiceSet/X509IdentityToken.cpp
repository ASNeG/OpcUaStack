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

#include "OpcUaStackCore/ServiceSet/X509IdentityToken.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// X509IdentityToken
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	X509IdentityToken::X509IdentityToken(void)
	: Object()
	, ExtensibleParameterBase()
	{
	}

	X509IdentityToken::~X509IdentityToken(void)
	{
	}

	void 
	X509IdentityToken::policyId(const std::string& policyId)
	{
		policyId_ = policyId;
	}

	std::string 
	X509IdentityToken::policyId(void) const
	{
		return policyId_.value();
	}
		
	void 
	X509IdentityToken::certificateData(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		certificateData_.value(buf, bufLen);
	}

	void 
	X509IdentityToken::certificateData(OpcUaByte** buf, OpcUaInt32* bufLen) const
	{
		certificateData_.value(buf, bufLen);
	}
	
	OpcUaByteString&
	X509IdentityToken::certificateData(void)
	{
		return certificateData_;
	}

	ExtensibleParameterBase::SPtr
	X509IdentityToken::factory(void)
	{
		return constructSPtr<X509IdentityToken>();
	}

	void 
	X509IdentityToken::opcUaBinaryEncode(std::ostream& os) const
	{
		policyId_.opcUaBinaryEncode(os);
		certificateData_.opcUaBinaryEncode(os);
	}

	void 
	X509IdentityToken::opcUaBinaryDecode(std::istream& is)
	{
		policyId_.opcUaBinaryDecode(is);
		certificateData_.opcUaBinaryDecode(is);
	}

}
