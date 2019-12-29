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

#ifndef __OpcUaStackCore_CreateSessionRequest_h__
#define __OpcUaStackCore_CreateSessionRequest_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/RequestHeader.h"
#include "OpcUaStackCore/SecureChannel/ApplicationInstanceCertificate.h"
#include "OpcUaStackCore/StandardDataTypes/ApplicationDescription.h"


namespace OpcUaStackCore
{

	class DLLEXPORT CreateSessionRequest
	: public  Object
	{
	  public:
		typedef boost::shared_ptr<CreateSessionRequest> SPtr;

		CreateSessionRequest(void);
		virtual ~CreateSessionRequest(void);

		void requestHeader(const RequestHeader::SPtr requestHeaderSPtr);
		RequestHeader::SPtr requestHeader(void) const;
		void clientDescription(const ApplicationDescription::SPtr clientDescriptionSPtr);
		ApplicationDescription::SPtr clientDescription(void) const;
		void serverUri(const std::string& serverUri);
		std::string serverUri(void) const;
		void endpointUrl(const std::string& endpointUrl);
		std::string endpointUrl(void) const;
		void sessionName(const std::string& sessionName);
		std::string sessionName(void) const;
		void clientNonce(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void clientNonce(const OpcUaByte *buf, OpcUaInt32 bufLen);
		OpcUaByteString& clientNonce(void);
		void clientCertificate(OpcUaByte **buf, OpcUaInt32* bufLen) const;
		void clientCertificate(const OpcUaByte *buf, OpcUaInt32 bufLen);
		OpcUaByteString& clientCertificate(void);
		void requestSessionTimeout(const OpcUaDuration requestSessionTimeout);
		OpcUaDuration requestSessionTimeout(void) const;
		void maxResponseMessageSize(const OpcUaUInt32& maxResponseMessageSize);
		OpcUaUInt32 maxResponseMessageSize(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		RequestHeader::SPtr requestHeaderSPtr_;
		ApplicationDescription::SPtr clientDescriptionSPtr_;
		OpcUaString serverUri_;
		OpcUaString endpointUrl_;
		OpcUaString sessionName_;
		OpcUaByteString clientNonce_;
		OpcUaByteString clientCertificate_;
		OpcUaDuration requestSessionTimeout_;
		OpcUaUInt32 maxResponseMessageSize_;
	};

}

#endif
