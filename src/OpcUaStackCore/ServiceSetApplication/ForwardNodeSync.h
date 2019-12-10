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

#ifndef __OpcUaStackCore_ForwardNodeSync_h__
#define __OpcUaStackCore_ForwardNodeSync_h__

#include "OpcUaStackCore/ServiceSetApplication/ForwardCallback.h"
#include "OpcUaStackCore/Application/ApplicationCallback.h"
#include "OpcUaStackCore/Application/ApplicationReadContext.h"
#include "OpcUaStackCore/Application/ApplicationHReadContext.h"
#include "OpcUaStackCore/Application/ApplicationHReadEventContext.h"
#include "OpcUaStackCore/Application/ApplicationWriteContext.h"
#include "OpcUaStackCore/Application/ApplicationHWriteContext.h"
#include "OpcUaStackCore/Application/ApplicationMethodContext.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStartContext.h"
#include "OpcUaStackCore/Application/ApplicationMonitoredItemStopContext.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ForwardNodeSync
	: public  Object
	{
	  public:
		using SPtr = boost::shared_ptr<ForwardNodeSync>;

		ForwardNodeSync(void);
		virtual ~ForwardNodeSync(void);

		ForwardCallback<ApplicationCallback::Read>& readService(void);
		ForwardCallback<ApplicationCallback::HRead>& readHService(void);
		ForwardCallback<ApplicationCallback::HERead>& readHEService(void);
		ForwardCallback<ApplicationCallback::Write>& writeService(void);
		ForwardCallback<ApplicationCallback::HWrite>& writeHService(void);
		ForwardCallback<ApplicationCallback::Method>& methodService(void);
		ForwardCallback<ApplicationCallback::MonitoredItemStart>& monitoredItemStartService(void);
		ForwardCallback<ApplicationCallback::MonitoredItemStop>& monitoredItemStopService(void);

		void updateFrom(ForwardNodeSync& forwardInfoSync);

	  private:
		// attribute service
		ForwardCallback<ApplicationCallback::Read> readService_;
		ForwardCallback<ApplicationCallback::HRead> readHService_;
		ForwardCallback<ApplicationCallback::HERead> readHEService_;
		ForwardCallback<ApplicationCallback::Write> writeService_;
		ForwardCallback<ApplicationCallback::HWrite> writeHService_;
		ForwardCallback<ApplicationCallback::MonitoredItemStart> monitoredItemStartService_;
		ForwardCallback<ApplicationCallback::MonitoredItemStop> monitoredItemStopService_;

		// method service
		ForwardCallback<ApplicationCallback::Method> methodService_;
	};

}

#endif
