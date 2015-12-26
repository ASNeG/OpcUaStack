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

#ifndef __OpcUaStackClient_SessionManager_h__
#define __OpcUaStackClient_SessionManager_h__

#include <boost/thread/mutex.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelClientConfig.h"
#include "OpcUaStackClient/ServiceSet/SessionConfig.h"
#include "OpcUaStackClient/ServiceSet/SessionManagerIf.h"

namespace OpcUaStackClient
{

	class DLLEXPORT SessionManager
	: public SessionManagerIf
	, public SecureChannelIf
	{
	  public:
		static SessionManager* instance_;
		static SessionManager* instance(void);

		SessionManager(void);
		~SessionManager(void);

		void start(void);
		void stop(void);

		SessionOld::SPtr getNewSession(
			const std::string& prefixSessionConfig, Config& sessionConfig, 
			const std::string& prefixSecureChannelConfig, Config& secureChannelConfig, 
			SessionIf* sessionIf,
			bool newSecureChannel = false
		);
		void deleteSession(void);
		IOService* ioService(void);

		//- SessionManagerIf --------------------------------------------------
		void connectToSecureChannel(void); 
	    void createSessionRequest(boost::asio::streambuf& sb);
		void activateSessionRequest(boost::asio::streambuf& sb);
		void send(SecureChannelTransaction::SPtr secureChannelTransaction);
		//- SessionManagerIf --------------------------------------------------

		//- SecureChannelIf ---------------------------------------------------
		void connect(void);
		void disconnect(void);
		bool receive(SecureChannelTransaction::SPtr secureChannelTransaction);
		//- SecureChannelIf ---------------------------------------------------

	  private:
		IOService ioService_;

		SecureChannelClient::SPtr secureChannel_;
		SessionOld::SPtr session_;
	};

}

#endif
