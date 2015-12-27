/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#ifndef __OpcUaStackClient_Session_h__
#define __OpcUaStackClient_Session_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClient.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelClientIf.h"
#include "OpcUaStackClient/ServiceSet/SessionIf.h"
#include "OpcUaStackClient/ServiceSet/SessionBase.h"
#include "OpcUaStackClient/ServiceSet/SessionConfig.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT Session
	: public SessionBase
	, public SecureChannelClientIf
	{
	  public:
		typedef boost::shared_ptr<Session> SPtr;

		Session(IOService& ioService);
		~Session(void);

		void sessionIf(SessionIf* sessionIf);
		void asyncConnect(SecureChannelClientConfig::SPtr& secureChannelClientConfig);
		void asyncConnect(SessionConfig::SPtr& sessionConfig, SecureChannelClientConfig::SPtr& secureChannelClientConfig);
		void asyncDisconnect(void);

		//- SecureChannelClientIf ---------------------------------------------
		virtual void handleConnect(SecureChannel* secureChannel);
		virtual void handleDisconnect(SecureChannel* secureChannel);
		virtual void handleMessageResponse(SecureChannel* secureChannel);
		//- SecureChannelClientIf ---------------------------------------------

	  private:
		void sendCreateSessionRequest(void);

		IOService* ioService_;
		SessionIf* sessionIf_;
		SecureChannel* secureChannel_;
		SecureChannelClient secureChannelClient_;
		SessionConfig::SPtr sessionConfig_;
		SecureChannelClientConfig::SPtr secureChannelClientConfig_;

		OpcUaUInt32 requestHandle_;
	};

}

#endif
