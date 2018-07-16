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

#ifndef __OpcUaStackServer_ApplicationIf_h__
#define __OpcUaStackServer_ApplicationIf_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Config.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"
#include "OpcUaStackCore/Certificate/CryptoManager.h"
#include "OpcUaStackServer/Application/ApplicationServiceIf.h"
#include "OpcUaStackServer/Application/ApplicationInfo.h"

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
		void config(Config* config);
		Config* config(void);
		void applicationInfo(ApplicationInfo* applicationInfo);
		ApplicationInfo* applicationInfo(void);
		void applicationCertificate(const ApplicationCertificate::SPtr& applicationCertificate);
		ApplicationCertificate::SPtr& applicationCertificate(void);
		void cryptoManager(const CryptoManager::SPtr& cryptoManager);
		CryptoManager::SPtr& cryptoManager(void);

	  private:
		ApplicationServiceIf* applicationServiceIf_;
		Config* config_;
		ApplicationInfo* applicationInfo_;
		ApplicationCertificate::SPtr applicationCertificate_;
		CryptoManager::SPtr cryptoManager_;
	};


	class DLLEXPORT ApplicationIf
	{
	  public:
		ApplicationIf(void);
		virtual ~ApplicationIf(void);

		virtual bool startup(void) = 0;
		virtual bool shutdown(void) = 0;
		virtual void receive(ServiceTransaction::SPtr serviceTransaction);
		virtual std::string version(void);

		void service(ApplicationServiceIf* applicationServiceIf);
		ApplicationServiceIf& service(void);
		void config(Config* config);
		Config* config(void);
		void applicationInfo(ApplicationInfo* applicationInfo);
		ApplicationInfo* applicationInfo(void);
		void applicationCertificate(ApplicationCertificate::SPtr& applicationCertificate);
		ApplicationCertificate::SPtr& applicationCertificate(void);
		void cryptoManager(CryptoManager::SPtr cryptoManager);
		CryptoManager::SPtr& cryptoManager(void);
		void applicationData(ApplicationData::SPtr& applicationData);
		ApplicationData::SPtr& applicationData(void);

	  private:
		ApplicationData::SPtr applicationData_;

	};

}

#endif
