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

#ifndef __OpcUaStackCore_OpenSecureChannelRequest_h__
#define __OpcUaStackCore_OpenSecureChannelRequest_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaByteString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaString.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaBaseEnums.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ApplicationInstanceCertificate.h"
#include "OpcUaStackCore/StandardDataTypes/MessageSecurityMode.h"

namespace OpcUaStackCore
{

	class DLLEXPORT OpenSecureChannelRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<OpenSecureChannelRequest> SPtr;

		OpenSecureChannelRequest(void);
		virtual ~OpenSecureChannelRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void clientProtocolVersion(const OpcUaInt32& clientProtocolVersion);
		OpcUaInt32 clientProtocolVersion(void);
		void requestType(const RequestType& requestType);
		RequestType requestType(void);
		void securityMode(MessageSecurityMode::Enum securityMode);
		MessageSecurityMode::Enum securityMode(void) const;
		void clientNonce(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void clientNonce(OpcUaByte *buf, OpcUaInt32 bufLen);
		void requestedLifetime(const OpcUaInt32& requestedLifetime);
		OpcUaInt32 requestedLifetime(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		OpcUaInt32 clientProtocolVersion_;
		RequestType requestType_;
		MessageSecurityMode::Enum securityMode_;
		OpcUaByteString clientNonce_;
		OpcUaInt32 requestedLifetime_;
	};

}

#endif
