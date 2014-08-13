#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AnonymousIdentityToken
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AnonymousIdentityToken::AnonymousIdentityToken(void)
	{
	}

	AnonymousIdentityToken::~AnonymousIdentityToken(void)
	{
	}

	void 
	AnonymousIdentityToken::policyId(const std::string& policyId)
	{
		policyId_ = policyId;
	}
		
	std::string 
	AnonymousIdentityToken::policyId(void) const
	{
		return policyId_.value();
	}

	ExtensibleParameterBase::SPtr 
	AnonymousIdentityToken::factory(void)
	{
		return AnonymousIdentityToken::construct();
	}

		
	void 
	AnonymousIdentityToken::opcUaBinaryEncode(std::ostream& os) const
	{
		policyId_.opcUaBinaryEncode(os);
	}
	
	void 
	AnonymousIdentityToken::opcUaBinaryDecode(std::istream& is)
	{
		policyId_.opcUaBinaryDecode(is);
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// UserNameIdentityToken
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	UserNameIdentityToken::UserNameIdentityToken(void)
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
		return UserNameIdentityToken::construct();
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

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ExtensibleParameter
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	bool ExtensibleParameter::init_ = false;
	ExtensibleParameter::ExtensibleParameterMap ExtensibleParameter::extensibleParameterMap_;

	ExtensibleParameter::ExtensibleParameter(void)
	{
	}

	ExtensibleParameter::~ExtensibleParameter(void)
	{
	}

	void 
	ExtensibleParameter::opcUaBinaryEncode(std::ostream& os) const
	{
		parameterTypeId_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, (OpcUaByte)0x01);
	}

	void 
	ExtensibleParameter::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		parameterTypeId_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, encodingMask);
	}
}