/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/ForwardMethodSync.h"

namespace OpcUaStackCore
{

	ForwardMethodSync::ForwardMethodSync(void)
	: readService_()
	, readHService_()
	, writeService_()
	, writeHService_()
	, methodService_()
	, monitoredItemStartService_()
	, monitoredItemStopService_()
	{
	}

	ForwardMethodSync::~ForwardMethodSync(void)
	{
	}

	ForwardCallback&
	ForwardMethodSync::readService(void)
	{
		return readService_;
	}

	ForwardCallback&
	ForwardMethodSync::readHService(void)
	{
		return readHService_;
	}

	ForwardCallback&
	ForwardMethodSync::writeService(void)
	{
		return writeService_;
	}

	ForwardCallback&
	ForwardMethodSync::writeHService(void)
	{
		return writeHService_;
	}

	ForwardCallback&
	ForwardMethodSync::methodService(void)
	{
		return methodService_;
	}

	ForwardCallback&
	ForwardMethodSync::monitoredItemStartService(void)
	{
		return monitoredItemStartService_;
	}

	ForwardCallback&
	ForwardMethodSync::monitoredItemStopService(void)
	{
		return monitoredItemStopService_;
	}

	void
	ForwardMethodSync::updateFrom(ForwardMethodSync& forwardCallbackSync)
	{
		readService_.updateFrom(forwardCallbackSync.readService());
		readHService_.updateFrom(forwardCallbackSync.readHService());
		writeService_.updateFrom(forwardCallbackSync.writeService());
		writeHService_.updateFrom(forwardCallbackSync.writeHService());
		methodService_.updateFrom(forwardCallbackSync.methodService());
		monitoredItemStartService_.updateFrom(forwardCallbackSync.monitoredItemStartService());
		monitoredItemStopService_.updateFrom(forwardCallbackSync.monitoredItemStopService());
	}

}
