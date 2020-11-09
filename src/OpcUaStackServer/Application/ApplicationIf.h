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

#ifndef __OpcUaStackServer_ApplicationIf_h__
#define __OpcUaStackServer_ApplicationIf_h__

#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"
#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "OpcUaStackServer/Application/ApplicationServiceIf.h"
#include "OpcUaStackServer/Application/ApplicationInfo.h"
#include "OpcUaStackServer/Forward/ForwardTransaction.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationData
	{
	  public:
		typedef boost::shared_ptr<ApplicationData> SPtr;

		ApplicationData(void);
		~ApplicationData(void);

		void applicationServiceIf(ApplicationServiceIf* applicationServiceIf);
		ApplicationServiceIf& applicationServiceIf(void);
		void config(OpcUaStackCore::Config* config);
		OpcUaStackCore::Config* config(void);
		void applicationInfo(ApplicationInfo* applicationInfo);
		ApplicationInfo* applicationInfo(void);
		void cryptoManager(const OpcUaStackCore::CryptoManager::SPtr& cryptoManager);
		OpcUaStackCore::CryptoManager::SPtr& cryptoManager(void);

		void applicationThreadPool(const OpcUaStackCore::IOThread::SPtr& applicationThreadPool);
		OpcUaStackCore::IOThread::SPtr& applicationThreadPool(void);

		void messageBusThreadPool(const OpcUaStackCore::IOThread::SPtr& messageBusThreadPool);
		OpcUaStackCore::IOThread::SPtr& messageBusThreadPool(void);
		void messageBusStrand(boost::shared_ptr<boost::asio::io_service::strand>& messageBusStrand);
		boost::shared_ptr<boost::asio::io_service::strand>& messageBusStrand(void);

	  private:
		ApplicationServiceIf* applicationServiceIf_;
		OpcUaStackCore::Config* config_;
		ApplicationInfo* applicationInfo_;
		OpcUaStackCore::CryptoManager::SPtr cryptoManager_;

		// This thread pool can be used by the application. This thread pool
		// is independent of the opc ua server. The number of threads in the
		// thread pool is specified in the opc ua server configuration file.
		// (ApplThreadPool)
		OpcUaStackCore::IOThread::SPtr applicationThreadPool_ = nullptr;

		// This thread pool can be used by the application. This thread pool
		// is used by the applications's message bus and can therefore be used
		// together with the stand to synchronize the application. The number
		// of threads in the thread pool is specified in the OPC UA configuration
		// file. (ServerThreadPool)
		OpcUaStackCore::IOThread::SPtr messageBusThreadPool_ = nullptr;
		boost::shared_ptr<boost::asio::io_service::strand> messageBusStrand_ = nullptr;
	};


	class DLLEXPORT ApplicationIf
	{
	  public:
		ApplicationIf(void);
		virtual ~ApplicationIf(void);

		virtual bool startup(void) = 0;
		virtual bool shutdown(void) = 0;
		virtual void receive(OpcUaStackCore::ServiceTransaction::SPtr serviceTransaction);
		virtual void receiveForwardTrx(ForwardTransaction::SPtr forwardTransaction);
		virtual std::string version(void);
		virtual std::string gitCommit(void);
		virtual std::string gitBranch(void);

		void service(ApplicationServiceIf* applicationServiceIf);
		ApplicationServiceIf& service(void);
		void config(OpcUaStackCore::Config* config);
		OpcUaStackCore::Config* config(void);
		void applicationInfo(ApplicationInfo* applicationInfo);
		ApplicationInfo* applicationInfo(void);
		void cryptoManager(OpcUaStackCore::CryptoManager::SPtr cryptoManager);
		OpcUaStackCore::CryptoManager::SPtr& cryptoManager(void);
		void applicationThreadPool(const OpcUaStackCore::IOThread::SPtr& applicationThreadPool);
		OpcUaStackCore::IOThread::SPtr& applicationThreadPool(void);
		void applicationData(ApplicationData::SPtr& applicationData);
		ApplicationData::SPtr& applicationData(void);

	  private:
		ApplicationData::SPtr applicationData_;

	};

}

#endif
