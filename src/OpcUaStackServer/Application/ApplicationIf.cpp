/*
   Copyright 2018 Kai Huebl (kai@huebl-sgh.de)

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
	, applicationCertificate_()
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

	ApplicationServiceIf*
	ApplicationData::applicationServiceIf(void)
	{
		return applicationServiceIf_;
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
	ApplicationData::applicationCertificate(const ApplicationCertificate::SPtr& applicationCertificate)
	{
		applicationCertificate_ = applicationCertificate;
	}

	ApplicationCertificate::SPtr&
	ApplicationData::applicationCertificate(void)
	{
		return applicationCertificate_;
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
	: applicationServiceIf_(nullptr)
	, config_(nullptr)
	, applicationInfo_(nullptr)
	, applicationCertificate_()
	, cryptoManager_()
	{
	}

	ApplicationIf::~ApplicationIf(void)
	{
	}

	void
	ApplicationIf::receive(ServiceTransaction::SPtr serviceTransaction)
	{
	}

	void
	ApplicationIf::service(ApplicationServiceIf* applicationServiceIf)
	{
		applicationServiceIf_ = applicationServiceIf;
	}

	ApplicationServiceIf&
	ApplicationIf::service(void)
	{
		return *applicationServiceIf_;
	}

	void
	ApplicationIf::config(Config* config)
	{
		config_ = config;
	}

	Config*
	ApplicationIf::config(void)
	{
		return config_;
	}

	void
	ApplicationIf::applicationInfo(ApplicationInfo* applicationInfo)
	{
		applicationInfo_ = applicationInfo;
	}

	ApplicationInfo*
	ApplicationIf::applicationInfo(void)
	{
		return applicationInfo_;
	}

	void
	ApplicationIf::applicationCertificate(ApplicationCertificate::SPtr& applicationCertificate)
	{
		applicationCertificate_ = applicationCertificate;
	}

	ApplicationCertificate::SPtr&
	ApplicationIf::applicationCertificate(void)
	{
		return applicationCertificate_;
	}

	void
	ApplicationIf::cryptoManager(CryptoManager::SPtr cryptoManager)
	{
		cryptoManager_ = cryptoManager;
	}

	CryptoManager::SPtr&
	ApplicationIf::cryptoManager(void)
	{
		return cryptoManager_;
	}

	std::string
	ApplicationIf::version(void)
	{
		return "0.0.0";
	}

}
