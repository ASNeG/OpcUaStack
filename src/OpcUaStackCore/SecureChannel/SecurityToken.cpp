#include "OpcUaStackCore/SecureChannel/SecurityToken.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SecurityToken
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SecurityToken::SecurityToken(void)
	: channelId_()
	, tokenId_()
	, createAt_()
	, revisedLifetime_()
	{
	}

	SecurityToken::~SecurityToken(void)
	{
	}

	void 
	SecurityToken::channelId(const OpcUaUInt32& channelId)
	{
		channelId_ = channelId;
	}
		
	OpcUaUInt32 
	SecurityToken::channelId(void) const
	{
		return channelId_;
	}

	void 
	SecurityToken::tokenId(const OpcUaUInt32& tokenId)
	{
		tokenId_ = tokenId;
	}
		
	OpcUaUInt32 
	SecurityToken::tokenId(void) const
	{
		return tokenId_;
	}

	void 
	SecurityToken::createAt(const UtcTime& createAt)
	{
		createAt_ = createAt;
	}

	UtcTime 
	SecurityToken::createAt(void) const
	{
		return createAt_;
	}
	void 
	SecurityToken::revisedLifetime(const OpcUaInt32& revisedLifetime)
	{
		revisedLifetime_ = revisedLifetime;
	}

	OpcUaInt32 
	SecurityToken::revisedLifetime(void) const
	{
		return revisedLifetime_;
	}

	void 
	SecurityToken::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaStackCore::opcUaBinaryEncode(os, channelId_);
		OpcUaStackCore::opcUaBinaryEncode(os, tokenId_);
		OpcUaStackCore::opcUaBinaryEncode(os, createAt_);
		OpcUaStackCore::opcUaBinaryEncode(os, revisedLifetime_);
	}

	void 
	SecurityToken::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaStackCore::opcUaBinaryDecode(is, channelId_);
		OpcUaStackCore::opcUaBinaryDecode(is, tokenId_);
		OpcUaStackCore::opcUaBinaryDecode(is, createAt_);
		OpcUaStackCore::opcUaBinaryDecode(is, revisedLifetime_);
	}


	void opcUaBinaryEncode(std::ostream& os, const SecurityToken& value)
	{
		value.opcUaBinaryEncode(os);
	}

	void opcUaBinaryEncode(std::ostream& os, const SecurityToken::SPtr& value)
	{
		value->opcUaBinaryEncode(os);
	}

	void opcUaBinaryDecode(std::istream& is, SecurityToken& value)
	{
		value.opcUaBinaryDecode(is);
	}

	void opcUaBinaryDecode(std::istream& is, SecurityToken::SPtr& value)
	{
		value->opcUaBinaryDecode(is);
	}

}