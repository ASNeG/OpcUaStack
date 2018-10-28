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
	: channelId_(0)
	, tokenId_(0)
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
	SecurityToken::createAt(const OpcUaUtcTime& createAt)
	{
		createAt_ = createAt;
	}

	OpcUaUtcTime
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
		OpcUaNumber::opcUaBinaryEncode(os, channelId_);
		OpcUaNumber::opcUaBinaryEncode(os, tokenId_);
		createAt_.opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, revisedLifetime_);
	}

	void 
	SecurityToken::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, channelId_);
		OpcUaNumber::opcUaBinaryDecode(is, tokenId_);
		createAt_.opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, revisedLifetime_);
	}


}
