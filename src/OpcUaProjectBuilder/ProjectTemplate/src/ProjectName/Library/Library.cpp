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

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Log.h"
#include "ProjectName/Library/Library.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationService.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"
#include <iostream>
#include "BuildConfig.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

namespace ProjectName
{

	Library::Library(void)
	: ApplicationIf()
	{
	}

	Library::~Library(void)
	{
	}

	bool
	Library::startup(void)
	{
		Log(Debug, "Library::startup");
		return true;
	}

	bool
	Library::shutdown(void)
	{
		Log(Debug, "Library::shutdown");
		return true;
	}

	std::string
	Library::version(void)
	{
		std::stringstream version;

		version << LIBRARY_VERSION_MAJOR << "." << LIBRARY_VERSION_MINOR << "." << LIBRARY_VERSION_PATCH;
		return version.str();
	}

	std::string
	Library::gitCommit(void)
	{
		return LIBRARY_GIT_COMMIT;
	}

	std::string
	Library::gitBranch(void)
	{
		return LIBRARY_GIT_BRANCH;
	}

}

extern "C" DLLEXPORT void  init(ApplicationIf** applicationIf) {
    *applicationIf = new ProjectName::Library();
}

