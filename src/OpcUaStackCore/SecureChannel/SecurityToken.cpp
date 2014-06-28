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
	SecurityToken::channelId(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		channelId_.value(buf, bufLen);
	}

	void 
	SecurityToken::channelId(OpcUaByte** buf, OpcUaInt32* bufLen) const
	{
		channelId_.value(buf, bufLen);
	}

	void 
	SecurityToken::tokenId(const OpcUaByte* buf, OpcUaInt32 bufLen)
	{
		tokenId_.value(buf, bufLen);
	}

	void 
	SecurityToken::tokenId(OpcUaByte** buf, OpcUaInt32 *bufLen) const
	{
		tokenId_.value(buf, bufLen);
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
	SecurityToken::revisedLifetime(const Duration& revisedLifetime)
	{
		revisedLifetime_ = revisedLifetime;
	}

	Duration 
	SecurityToken::revisedLiefetime(void) const
	{
		return revisedLifetime_;
	}

	void 
	SecurityToken::opcUaBinaryEncode(std::ostream& os) const
	{
		channelId_.opcUaBinaryEncode(os);
		tokenId_.opcUaBinaryEncode(os);
		OpcUaStackCore::opcUaBinaryEncode(os, createAt_);
		OpcUaStackCore::opcUaBinaryEncode(os, revisedLifetime_);
	}

	void 
	SecurityToken::opcUaBinaryDecode(std::istream& is)
	{
		channelId_.opcUaBinaryDecode(is);
		tokenId_.opcUaBinaryDecode(is);
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