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

	ForwardSyncCallback<ApplicationCallback::Read>&
	ForwardNodeSync::readService(void)
	{
		return readService_;
	}

	ForwardSyncCallback<ApplicationCallback::HRead>&
	ForwardNodeSync::readHService(void)
	{
		return readHService_;
	}

	ForwardSyncCallback<ApplicationCallback::HERead>&
	ForwardNodeSync::readHEService(void)
	{
		return readHEService_;
	}

	ForwardSyncCallback<ApplicationCallback::Write>&
	ForwardNodeSync::writeService(void)
	{
		return writeService_;
	}

	ForwardSyncCallback<ApplicationCallback::HWrite>&
	ForwardNodeSync::writeHService(void)
	{
		return writeHService_;
	}

	ForwardSyncCallback<ApplicationCallback::Method>&
	ForwardNodeSync::methodService(void)
	{
		return methodService_;
	}

	ForwardSyncCallback<ApplicationCallback::MonitoredItemStart>&
	ForwardNodeSync::monitoredItemStartService(void)
	{
		return monitoredItemStartService_;
	}

	ForwardSyncCallback<ApplicationCallback::MonitoredItemStop>&
	ForwardNodeSync::monitoredItemStopService(void)
	{
		return monitoredItemStopService_;
	}

	void
	ForwardNodeSync::updateFrom(ForwardNodeSync& ForwardSyncCallbackSync)
	{
		readService_.updateFrom(ForwardSyncCallbackSync.readService());
		readHService_.updateFrom(ForwardSyncCallbackSync.readHService());
		readHEService_.updateFrom(ForwardSyncCallbackSync.readHEService());
		writeService_.updateFrom(ForwardSyncCallbackSync.writeService());
		writeHService_.updateFrom(ForwardSyncCallbackSync.writeHService());
		methodService_.updateFrom(ForwardSyncCallbackSync.methodService());
		monitoredItemStartService_.updateFrom(ForwardSyncCallbackSync.monitoredItemStartService());
		monitoredItemStopService_.updateFrom(ForwardSyncCallbackSync.monitoredItemStopService());
	}

}
