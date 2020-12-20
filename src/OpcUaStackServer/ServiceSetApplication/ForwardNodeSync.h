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

#ifndef __OpcUaStackServer_ForwardNodeSync_h__
#define __OpcUaStackServer_ForwardNodeSync_h__

#include <OpcUaStackCore/ServiceSetApplication/ForwardSyncCallback.h>
#include "OpcUaStackCore/Application/ApplicationCallback.h"
#include "OpcUaStackCore/Application/ApplicationReadContext.h"
#include "OpcUaStackCore/Application/ApplicationHReadContext.h"
#include "OpcUaStackCore/Application/ApplicationHReadEventContext.h"
#include "OpcUaStackCore/Application/ApplicationWriteContext.h"
#include "OpcUaStackCore/Application/ApplicationHWriteContext.h"
#include "OpcUaStackCore/Application/ApplicationMethodContext.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStartContext.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStopContext.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ForwardNodeSync
	: public OpcUaStackCore::Object
	{
	  public:
		using SPtr = boost::shared_ptr<ForwardNodeSync>;

		ForwardNodeSync(void);
		virtual ~ForwardNodeSync(void);

		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Read>& readService(void);
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::HRead>& readHService(void);
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::HERead>& readHEService(void);
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Write>& writeService(void);
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::HWrite>& writeHService(void);
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Method>& methodService(void);
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::MonitoredItemStart>& monitoredItemStartService(void);
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::MonitoredItemStop>& monitoredItemStopService(void);

		void updateFrom(ForwardNodeSync& forwardInfoSync);

	  private:
		// attribute service
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Read> readService_;
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::HRead> readHService_;
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::HERead> readHEService_;
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Write> writeService_;
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::HWrite> writeHService_;
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::MonitoredItemStart> monitoredItemStartService_;
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::MonitoredItemStop> monitoredItemStopService_;

		// method service
		OpcUaStackCore::ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Method> methodService_;
	};

}

#endif
