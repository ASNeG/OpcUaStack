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

#ifndef __OpcUaStackCore_OpenSecureChannelResponse_h__
#define __OpcUaStackCore_OpenSecureChannelResponse_h__

#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"
#include "OpcUaStackCore/SecureChannel/SecurityToken.h"


namespace OpcUaStackCore
{
	
	class DLLEXPORT OpenSecureChannelResponse
	: public Object
	{
	  public:
		typedef boost::shared_ptr<OpenSecureChannelResponse> SPtr;
		typedef std::list<OpenSecureChannelResponse::SPtr> List;

		OpenSecureChannelResponse(void);
		virtual ~OpenSecureChannelResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void) const;
		void serverProtocolVersion(const OpcUaInt32& serverProtocolVersion);
		OpcUaInt32 serverProtocolVersion(void) const;
		void securityToken(const SecurityToken::SPtr securityToken);
		SecurityToken::SPtr securityToken(void);
		void serverNonce(OpcUaByte** buf, OpcUaInt32 *bufLen) const;
		void serverNonce(const OpcUaByte* buf, OpcUaInt32 bufLen);

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeaderSPtr_;
		OpcUaUInt32 serverProtocolVersion_;
		SecurityToken::SPtr securityTokenSPtr_;	
		OpcUaByteString serverNonce_;
	};

}

#endif
