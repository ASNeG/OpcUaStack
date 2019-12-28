/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/SecureChannel/OpenSecureChannelRequest.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// OpenSecureChannelRequest
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpenSecureChannelRequest::OpenSecureChannelRequest(void)
	: requestHeaderSPtr_(boost::make_shared<RequestHeader>())
	, clientProtocolVersion_(0)
	, requestType_()
	, securityMode_(MessageSecurityMode::EnumInvalid)
	, clientNonce_()
	, requestedLifetime_()
	{
	}
		
	OpenSecureChannelRequest::~OpenSecureChannelRequest(void)
	{
	}

	void 
	OpenSecureChannelRequest::requestHeader(const RequestHeader::SPtr requestHeaderSPtr)
	{
		requestHeaderSPtr_ = requestHeaderSPtr;
	}

	RequestHeader::SPtr  
	OpenSecureChannelRequest::requestHeader(void) const
	{
		return requestHeaderSPtr_;
	}

	void 
	OpenSecureChannelRequest::clientProtocolVersion(const OpcUaInt32& clientProtocolVersion)
	{
		clientProtocolVersion_ = clientProtocolVersion;
	}
		
	OpcUaInt32 
	OpenSecureChannelRequest::clientProtocolVersion(void)
	{
		return clientProtocolVersion_;
	}

	void  
	OpenSecureChannelRequest::requestType(const RequestType& requestType)
	{
		requestType_ = requestType;
	}

	RequestType  
	OpenSecureChannelRequest::requestType(void)
	{
		return requestType_;
	}

	void  
	OpenSecureChannelRequest::securityMode(MessageSecurityMode::Enum securityMode)
	{
		securityMode_ = securityMode;
	}

	MessageSecurityMode::Enum
	OpenSecureChannelRequest::securityMode(void) const
	{
		return securityMode_;
	}

	void  
	OpenSecureChannelRequest::clientNonce(OpcUaByte *buf, OpcUaInt32 bufLen)
	{
		clientNonce_.value(buf, bufLen);
	}

	void  
	OpenSecureChannelRequest::clientNonce(OpcUaByte **buf, OpcUaInt32* bufLen) const
	{
		clientNonce_.value(buf, bufLen);
	}

	void  
	OpenSecureChannelRequest::requestedLifetime(const OpcUaInt32& requestedLifetime)
	{
		requestedLifetime_ = requestedLifetime;
	}

	OpcUaInt32  
	OpenSecureChannelRequest::requestedLifetime(void) const
	{
		return requestedLifetime_;
	}

	bool
	OpenSecureChannelRequest::opcUaBinaryEncode(std::ostream& os) const
	{
		bool rc = true;

		rc &= requestHeaderSPtr_->opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, clientProtocolVersion_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)requestType_);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, (OpcUaUInt32)securityMode_);
		rc &= clientNonce_.opcUaBinaryEncode(os);
		rc &= OpcUaNumber::opcUaBinaryEncode(os, requestedLifetime_);

		return rc;
	}

	bool
	OpenSecureChannelRequest::opcUaBinaryDecode(std::istream& is)
	{
		bool rc = true;

		OpcUaUInt32 tmp;
		rc &= requestHeaderSPtr_->opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, clientProtocolVersion_);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp); requestType_ = (RequestType)tmp;
		rc &= OpcUaNumber::opcUaBinaryDecode(is, tmp); securityMode_ = (MessageSecurityMode::Enum)tmp;
		rc &= clientNonce_.opcUaBinaryDecode(is);
		rc &= OpcUaNumber::opcUaBinaryDecode(is, requestedLifetime_);

		return rc;
	}

}
