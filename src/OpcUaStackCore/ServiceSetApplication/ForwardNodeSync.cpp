/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/ForwardNodeSync.h"

namespace OpcUaStackCore
{

	ForwardNodeSync::ForwardNodeSync(void)
	: readService_()
	, readHService_()
	, readHEService_()
	, writeService_()
	, writeHService_()
	, methodService_()
	, monitoredItemStartService_()
	, monitoredItemStopService_()
	{
	}

	ForwardNodeSync::~ForwardNodeSync(void)
	{
	}

	ForwardCallback<ApplicationCallback::Read>&
	ForwardNodeSync::readService(void)
	{
		return readService_;
	}

	ForwardCallback<ApplicationCallback::HRead>&
	ForwardNodeSync::readHService(void)
	{
		return readHService_;
	}

	ForwardCallback<ApplicationCallback::HERead>&
	ForwardNodeSync::readHEService(void)
	{
		return readHEService_;
	}

	ForwardCallback<ApplicationCallback::Write>&
	ForwardNodeSync::writeService(void)
	{
		return writeService_;
	}

	ForwardCallback<ApplicationCallback::HWrite>&
	ForwardNodeSync::writeHService(void)
	{
		return writeHService_;
	}

	ForwardCallback<ApplicationCallback::Method>&
	ForwardNodeSync::methodService(void)
	{
		return methodService_;
	}

	ForwardCallback<ApplicationCallback::MonitoredItemStart>&
	ForwardNodeSync::monitoredItemStartService(void)
	{
		return monitoredItemStartService_;
	}

	ForwardCallback<ApplicationCallback::MonitoredItemStop>&
	ForwardNodeSync::monitoredItemStopService(void)
	{
		return monitoredItemStopService_;
	}

	void
	ForwardNodeSync::updateFrom(ForwardNodeSync& forwardCallbackSync)
	{
		readService_.updateFrom(forwardCallbackSync.readService());
		readHService_.updateFrom(forwardCallbackSync.readHService());
		readHEService_.updateFrom(forwardCallbackSync.readHEService());
		writeService_.updateFrom(forwardCallbackSync.writeService());
		writeHService_.updateFrom(forwardCallbackSync.writeHService());
		methodService_.updateFrom(forwardCallbackSync.methodService());
		monitoredItemStartService_.updateFrom(forwardCallbackSync.monitoredItemStartService());
		monitoredItemStopService_.updateFrom(forwardCallbackSync.monitoredItemStopService());
	}

}
