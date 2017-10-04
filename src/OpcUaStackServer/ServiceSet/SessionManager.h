/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_SessionManager_h__
#define __OpcUaStackServer_SessionManager_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Base/Url.h"
#include "OpcUaStackCore/Utility/IOThread.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"
#include "OpcUaStackServer/ServiceSet/EndpointDescriptionConfig.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT SessionManager
	: public SecureChannelServerIf
	{
	  public:
		typedef boost::shared_ptr<SessionManager> SPtr;

		SessionManager(void);
		virtual ~SessionManager(void);

		void ioThread(IOThread* ioThread);
		void config(Config* config);

		bool startup(void);
		bool shutdown(void);

		//- SecureChannelServerIf ---------------------------------------------
		virtual void handleConnect(SecureChannel* secureChannel);
		virtual void handleDisconnect(SecureChannel* secureChannel);
		virtual void handleMessageRequest(SecureChannel* secureChannel);

		virtual void handleEndpointOpen(void);
		virtual void handleEndpointClose(void);
		//- SecureChannelServerId ---------------------------------------------

	  private:
		bool getSecureChannelServerConfig(
			SecureChannelServerConfig::SPtr& secureChannelServerConfig,
			EndpointDescription::SPtr& endpointDescription
		);

		IOThread* ioThread_;
		Config* config_;
		Url url_;

		SecureChannelServer::SPtr secureChannelServer_;
	};

}

#endif
