/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_Application_h__
#define __OpcUaStackServer_Application_h__

#include "OpcUaStackServer/ServiceSet/ServerServiceBase.h"
#include "OpcUaStackServer/Application/ApplicationBase.h"
#include "OpcUaStackServer/Application/ApplicationServiceIf.h"
#include "OpcUaStackServer/Application/ReloadIf.h"
#include "OpcUaStackServer/Forward/ForwardTransaction.h"
#include <map>

namespace OpcUaStackServer
{

	class DLLEXPORT Application
	: public ApplicationBase
	, public OpcUaStackCore::Object
	, public ApplicationServiceIf
	, public OpcUaStackServer::ServerServiceBase
	{
	  public:
		typedef boost::shared_ptr<Application> SPtr;
		typedef std::map<std::string, Application::SPtr> Map;

		typedef enum
		{
			ApplConstruct,
			ApplStartup,
			ApplShutdown
		} State;

		Application(
			const std::string& serviceName,
			OpcUaStackCore::IOThread::SPtr& ioThread,
			OpcUaStackCore::MessageBus::SPtr& messageBus
		);
		~Application(void);

		void applicationIf(ApplicationIf* applicationIf);
		ApplicationIf* applicationIf(void);
		void reloadIf(ReloadIf* reloadIf);
		void applicationName(const std::string& applicationName);

		bool startup(void);
		bool shutdown(void);

		//- ApplicationServiceIf ------------------------------------------------------
		void send(
			OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction
		) override;
		void sendForwardTrx(
			OpcUaStackServer::ForwardTransaction::SPtr forwardTransaction
		) override;
		void sendSync(
			OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction
		) override;
		void reload(
		    void
		) override;
		//- ApplicationServiceIf ------------------------------------------------------

	  private:
		void receive(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr message
		);
		void receiveServiceTrx(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr message
		);
		void receiveForwardTrx(
			const OpcUaStackCore::MessageBusMember::WPtr& handleFrom,
			OpcUaStackCore::Message::SPtr message
		);
		void updateServiceTransactionRequest(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);

		State state_;
		ApplicationIf* applicationIf_;
		ReloadIf* reloadIf_;
		std::string applicationName_;

		OpcUaStackCore::IOThread::SPtr ioThread_ = nullptr;
		OpcUaStackCore::MessageBusMember::WPtr messageBusMemberApplication_;
	};

}

#endif
