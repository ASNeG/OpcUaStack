/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/Application/ApplicationIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ApplicationData
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ApplicationData::ApplicationData(void)
	: applicationServiceIf_(nullptr)
	, config_(nullptr)
	, applicationInfo_(nullptr)
	, cryptoManager_()
	{
	}

	ApplicationData::~ApplicationData(void)
	{
	}

	void
	ApplicationData::applicationServiceIf(ApplicationServiceIf* applicationServiceIf)
	{
		applicationServiceIf_ = applicationServiceIf;
	}

	ApplicationServiceIf&
	ApplicationData::applicationServiceIf(void)
	{
		return *applicationServiceIf_;
	}

	void
	ApplicationData::config(Config* config)
	{
		config_ = config;
	}

	Config*
	ApplicationData::config(void)
	{
		return config_;
	}

	void
	ApplicationData::applicationInfo(ApplicationInfo* applicationInfo)
	{
		applicationInfo_ = applicationInfo;
	}

	ApplicationInfo*
	ApplicationData::applicationInfo(void)
	{
		return applicationInfo_;
	}

	void
	ApplicationData::cryptoManager(const CryptoManager::SPtr& cryptoManager)
	{
		cryptoManager_ = cryptoManager;
	}

	CryptoManager::SPtr&
	ApplicationData::cryptoManager(void)
	{
		return cryptoManager_;
	}

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ApplicationIf
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ApplicationIf::ApplicationIf(void)
	: applicationData_(constructSPtr<ApplicationData>())
	{
	}

	ApplicationIf::~ApplicationIf(void)
	{
	}

	void
	ApplicationIf::receive(ServiceTransaction::SPtr serviceTransaction)
	{
	}

	std::string
	ApplicationIf::version(void)
	{
		return "0.0.0";
	}

	void
	ApplicationIf::service(ApplicationServiceIf* applicationServiceIf)
	{
		applicationData_->applicationServiceIf(applicationServiceIf);
	}

	ApplicationServiceIf&
	ApplicationIf::service(void)
	{
		return applicationData_->applicationServiceIf();
	}

	void
	ApplicationIf::config(Config* config)
	{
		applicationData_->config(config);
	}

	Config*
	ApplicationIf::config(void)
	{
		return applicationData_->config();
	}

	void
	ApplicationIf::applicationInfo(ApplicationInfo* applicationInfo)
	{
		applicationData_->applicationInfo(applicationInfo);
	}

	ApplicationInfo*
	ApplicationIf::applicationInfo(void)
	{
		return applicationData_->applicationInfo();
	}

	void
	ApplicationIf::cryptoManager(CryptoManager::SPtr cryptoManager)
	{
		applicationData_->cryptoManager(cryptoManager);
	}

	CryptoManager::SPtr&
	ApplicationIf::cryptoManager(void)
	{
		return applicationData_->cryptoManager();
	}

	void
	ApplicationIf::applicationData(ApplicationData::SPtr& applicationData)
	{
		applicationData_ = applicationData;
	}

	ApplicationData::SPtr&
	ApplicationIf::applicationData(void)
	{
		return applicationData_;
	}

}
