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

#include "OpcUaStackCore/Application/ApplicationCallback.h"
#include "OpcUaStackCore/Application/ApplicationReadContext.h"
#include "OpcUaStackCore/Application/ApplicationHReadContext.h"
#include "OpcUaStackCore/Application/ApplicationHReadEventContext.h"
#include "OpcUaStackCore/Application/ApplicationWriteContext.h"
#include "OpcUaStackCore/Application/ApplicationHWriteContext.h"
#include "OpcUaStackCore/Application/ApplicationMethodContext.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStartContext.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStopContext.h"
#include "OpcUaStackServer/ServiceSetApplication/ForwardSyncCallback.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ForwardNodeSync
	: public OpcUaStackCore::Object
	{
	  public:
		using SPtr = boost::shared_ptr<ForwardNodeSync>;

		ForwardNodeSync(void);
		virtual ~ForwardNodeSync(void);

		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Read>& readService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::HRead>& readHService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::HERead>& readHEService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Write>& writeService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::HWrite>& writeHService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Method>& methodService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::MonitoredItemStart>& monitoredItemStartService(void);
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::MonitoredItemStop>& monitoredItemStopService(void);

		void updateFrom(ForwardNodeSync& forwardInfoSync);

	  private:
		// attribute service
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Read> readService_;
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::HRead> readHService_;
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::HERead> readHEService_;
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Write> writeService_;
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::HWrite> writeHService_;
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::MonitoredItemStart> monitoredItemStartService_;
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::MonitoredItemStop> monitoredItemStopService_;

		// method service
		ForwardSyncCallback<OpcUaStackCore::ApplicationCallback::Method> methodService_;
	};

}

#endif
