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

#ifndef __OpcUaStackCore_CreateSessionResponse_h__
#define __OpcUaStackCore_CreateSessionResponse_h__

#include <stdint.h>
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/SecureChannel/ApplicationInstanceCertificate.h"
#include "OpcUaStackCore/SecureChannel/SessionAuthenticationToken.h"
#include "OpcUaStackCore/ServiceSet/SignatureData.h"
#include "OpcUaStackCore/StandardDataTypes/EndpointDescription.h"
#include "OpcUaStackCore/StandardDataTypes/SignedSoftwareCertificate.h"

namespace OpcUaStackCore
{

	class DLLEXPORT CreateSessionResponse
	: public Object
	{
	  public:
		typedef boost::shared_ptr<CreateSessionResponse> SPtr;

		CreateSessionResponse(void);
		virtual ~CreateSessionResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void) const;
		OpcUaNodeId& sessionId(void);
		OpcUaNodeId& authenticationToken(void);
		void receivedSessionTimeout(const OpcUaDuration receivedSessionTimeout);
		OpcUaDuration receivedSessionTimeout(void) const;
		OpcUaByteString& serverNonce(void);
		void serverNonce(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void serverNonce(const OpcUaByte* buf, OpcUaInt32 bufLen);
		void serverCertificate(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void serverCertificate(const OpcUaByte* buf, OpcUaInt32 bufLen);
		OpcUaByteString& serverCertificate(void);
		void serverEndpoints(const EndpointDescriptionArray::SPtr serverEndpoints);
		EndpointDescriptionArray::SPtr serverEndpoints(void) const;
		void serverSoftwareCertificate(OpcUaByte** buf, OpcUaInt32* bufLen) const;
		void serverSoftwareCertificate(const OpcUaByte* buf, OpcUaInt32 bufLen);
		OpcUaByteString& serverSoftwareCertificate(void);
		void signatureData(const SignatureData::SPtr signatureData);
		SignatureData::SPtr signatureData(void) const;
		void maxRequestMessageSize(const OpcUaUInt32 maxRequestMessageSize);
		OpcUaUInt32 maxRequestMessageSize(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeader_;
		OpcUaNodeId sessionId_;
		OpcUaNodeId authenticationToken_;
		OpcUaDuration receivedSessionTimeout_;
		OpcUaByteString serverNonce_;
		OpcUaByteString serverCertificate_;
		EndpointDescriptionArray::SPtr serverEndpoints_;
		OpcUaByteString serverSoftwareCertificate_;
		SignatureData::SPtr signatureData_;
		OpcUaUInt32 maxRequestMessageSize_;
		
	};

}

#endif
