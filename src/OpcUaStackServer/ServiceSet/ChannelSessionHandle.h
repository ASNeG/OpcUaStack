/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_ChannelSessionHandle_h__
#define __OpcUaStackServer_ChannelSessionHandle_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/SecureChannel/SecureChannelServer.h"
#include "OpcUaStackServer/ServiceSet/Session.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ChannelSessionHandle
	: public Object
	{
	  public:

		typedef boost::shared_ptr<ChannelSessionHandle> SPtr;
		typedef std::map<uint32_t,ChannelSessionHandle::SPtr> Map;

		typedef enum
		{
			SCS_Valid,
			SCS_Invalid
		} SecureChannelState;

		typedef enum
		{
			SS_Valid,
			SS_Invalid
		} SessionState;

		ChannelSessionHandle(void);
		~ChannelSessionHandle(void);

		SecureChannelState secureChannelState(void);
		bool secureChannelIsValid(void);
		void secureChannel(SecureChannel* secureChannel);
		SecureChannel* secureChannel(void);
		void secureChannelServer(SecureChannelServer::SPtr& secureChannelServer);
		SecureChannelServer::SPtr& secureChannelServer(void);

		SessionState sessionState(void);
		bool sessionIsValid(void);
		void session(Session::SPtr& session);
		Session::SPtr& session(void);


	  private:
		SecureChannelState secureChannelState_;
		SecureChannel* secureChannel_;
		SecureChannelServer::SPtr secureChannelServer_;

		SessionState sessionState_;
		Session::SPtr session_;
	};

}

#endif
