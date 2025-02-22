/*
   Copyright 2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de), , Aleksey Timin (atimin@gmail.com)
 */

#ifndef __OpcUaStackServer_ServerInfoService_h__
#define __OpcUaStackServer_ServerInfoService_h__

#include <map>
#include "OpcUaStackCore/ServiceSetServerInfo/ServerInfoServiceTransaction.h"
#include "OpcUaStackServer/ServiceSet/ServiceSetBase.h"
#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"
#include "OpcUaStackServer/CustomerObjectType/SessionInfo.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ServerInfoService
	: public ServiceSetBase
	, public OpcUaStackCore::Object
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		using SPtr = boost::shared_ptr<ServerInfoService>;
		using SessionInfoMap = std::map<uint32_t, SessionInfo::SPtr>;

		ServerInfoService(
			const std::string& serviceName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~ServerInfoService(void);

		bool init(void) override;

	  private:
		bool activate_ = true;
		SessionInfoMap sessionInfoMap_;

		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr& message
		);
		void addSessionRequest(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction);
		void delSessionRequest(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction);
		void updSessionRequest(OpcUaStackCore::ServiceTransaction::SPtr& serviceTransaction);
	};

}

#endif
