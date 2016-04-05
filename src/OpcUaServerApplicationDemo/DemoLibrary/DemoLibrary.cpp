/*
   Copyright 2015 Kai Huebl (kai@huebl-sgh.de)

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
#include "OpcUaServerApplicationDemo/DemoLibrary/DemoLibrary.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationService.h"
#include "OpcUaStackServer/ServiceSetApplication/NodeReferenceApplication.h"
#include <iostream>

namespace OpcUaServerApplicationDemo
{

	DemoLibrary::DemoLibrary(void)
	: ApplicationIf()
	, cameraAnimation_()
	, testFolderLib_()
	{
		Log(Debug, "DemoLibrary::DemoLibrary");
	}

	DemoLibrary::~DemoLibrary(void)
	{
		Log(Debug, "DemoLibrary::~DemoLibrary");
	}

	bool
	DemoLibrary::startup(void)
	{
		Log(Debug, "DemoLibrary::startup");

		ioThread_.startup();
		testFolderLib_.startup(ioThread_, service(), applicationInfo());
		cameraAnimation_.startup(ioThread_, service(), applicationInfo());
		return true;
	}

	bool
	DemoLibrary::shutdown(void)
	{
		Log(Debug, "DemoLibrary::shutdown");

		cameraAnimation_.shutdown();
		testFolderLib_.shutdown();
		ioThread_.shutdown();

		return true;
	}

}

extern "C" DLLEXPORT void  init(ApplicationIf** applicationIf) {
    *applicationIf = new OpcUaServerApplicationDemo::DemoLibrary();
}

