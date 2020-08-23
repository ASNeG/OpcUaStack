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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackServer/Application/ApplicationIf.h"
#include "OpcUaServer/ApplicationLibrary/ApplicationLibrary.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace OpcUaServer
{

	ApplicationLibrary::ApplicationLibrary(void)
	: Object()
	, applicationInfo_()
	, dynamicLibrary_()
	, initFunction_(nullptr)
	, applicationIf_(nullptr)
	{
	}

	ApplicationLibrary::~ApplicationLibrary(void)
	{
	}

	void
	ApplicationLibrary::applicationInfo(const ApplicationInfo& applicationInfo)
	{
		applicationInfo_ = applicationInfo;
	}

	ApplicationInfo&
	ApplicationLibrary::applicationInfo(void)
	{
		return applicationInfo_;
	}

	ApplicationLibrary::InitFunction*
	ApplicationLibrary::initFunction(void)
	{
		return initFunction_;
	}

	ApplicationIf*
	ApplicationLibrary::applicationIf(void)
	{
		return applicationIf_;
	}

	std::string
	ApplicationLibrary::version(void)
	{
		return applicationIf_->version();
	}

	std::string
	ApplicationLibrary::gitCommit(void)
	{
		return applicationIf_->gitCommit();
	}

	std::string
	ApplicationLibrary::gitBranch(void)
	{
		return applicationIf_->gitBranch();
	}

	bool
	ApplicationLibrary::startup(void)
	{
		// load library
		if (!dynamicLibrary_.open(applicationInfo_.libraryName())) {
			return false;
		}

		// load init function
		if (!dynamicLibrary_.get("init", (void**)&initFunction_)) {
			return false;
		}

		// call in function in library
		(*initFunction_)(&applicationIf_);
		if (applicationIf_ == NULL) {
			Log(Error, "init function library error")
			    .parameter("ApplicationName", applicationInfo_.applicationName())
			    .parameter("LibraryName", applicationInfo_.libraryName());
			return false;
		}

		return true;
	}

	bool
	ApplicationLibrary::shutdown(void)
	{
		if (!dynamicLibrary_.close()) {
			return false;
		}
		return true;
	}

}
