/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackCore/ServiceSetApplication/ForwardCallbackSync.h"

namespace OpcUaStackCore
{

	ForwardCallbackSync::ForwardCallbackSync(void)
	: readService_()
	, readHService_()
	, writeService_()
	, writeHService_()
	, methodService_()
	, monitoredItemStartService_()
	, monitoredItemStopService_()
	{
	}

	ForwardCallbackSync::~ForwardCallbackSync(void)
	{
	}

	ForwardCallback&
	ForwardCallbackSync::readService(void)
	{
		return readService_;
	}

	ForwardCallback&
	ForwardCallbackSync::readHService(void)
	{
		return readHService_;
	}

	ForwardCallback&
	ForwardCallbackSync::writeService(void)
	{
		return writeService_;
	}

	ForwardCallback&
	ForwardCallbackSync::writeHService(void)
	{
		return writeHService_;
	}

	ForwardCallback&
	ForwardCallbackSync::methodService(void)
	{
		return methodService_;
	}

	ForwardCallback&
	ForwardCallbackSync::monitoredItemStartService(void)
	{
		return monitoredItemStartService_;
	}

	ForwardCallback&
	ForwardCallbackSync::monitoredItemStopService(void)
	{
		return monitoredItemStopService_;
	}

	void
	ForwardCallbackSync::updateFrom(ForwardCallbackSync& forwardInfoSync)
	{
		readService_.updateFrom(forwardInfoSync.readService());
		readHService_.updateFrom(forwardInfoSync.readHService());
		writeService_.updateFrom(forwardInfoSync.writeService());
		writeHService_.updateFrom(forwardInfoSync.writeHService());
		methodService_.updateFrom(forwardInfoSync.methodService());
		monitoredItemStartService_.updateFrom(forwardInfoSync.monitoredItemStartService());
		monitoredItemStopService_.updateFrom(forwardInfoSync.monitoredItemStopService());
	}

}
