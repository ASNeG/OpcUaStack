/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ApplicationCallback_h__
#define __OpcUaStackCore_ApplicationCallback_h__

#include <functional>
#include "OpcUaStackCore/Base/os.h"

namespace OpcUaStackCore
{

    class ApplicationMethodContext;
    class ApplicationRegisterServerContext;
    class ApplicationFindServerContext;
    class ApplicationEventItemStartContext;
    class ApplicationEventItemStopContext;
    class ApplicationAuthenticationContext;
    class ApplicationAutorizationContext;
    class ApplicationCloseSessionContext;
    class ApplicationNodeNewContext;
    class ApplicationNodeDeleteContext;
    class ApplicationReadContext;
    class ApplicationHReadContext;
    class ApplicationHReadEventContext;
    class ApplicationWriteContext;
    class ApplicationHWriteContext;
    class ApplicationMonitoredItemStartContext;
    class ApplicationMonitoredItemStopContext;

	class DLLEXPORT ApplicationCallback
	{
	  public:
		using RegisterServer = std::function<void (ApplicationRegisterServerContext*)>;
		using FindServer = std::function<void (ApplicationFindServerContext*)>;
		using EventItemStart = std::function<void (ApplicationEventItemStartContext*)>;
		using EventItemStop = std::function<void (ApplicationEventItemStopContext*)>;
		using Authentication = std::function<void (ApplicationAuthenticationContext*)>;
		using Autorization = std::function<void (ApplicationAutorizationContext*)>;
		using CloseSession = std::function<void (ApplicationCloseSessionContext*)>;
		using NodeNew = std::function<void (ApplicationNodeNewContext*)>;
		using NodeDelete = std::function<void (ApplicationNodeDeleteContext*)>;

		using Method = std::function<void (ApplicationMethodContext*)>;
		using Read = std::function<void (ApplicationReadContext*)>;
		using HRead = std::function<void (ApplicationHReadContext*)>;
		using HERead = std::function<void (ApplicationHReadEventContext*)>;
		using Write = std::function<void (ApplicationWriteContext*)>;
		using HWrite = std::function<void (ApplicationHWriteContext*)>;
		using MonitoredItemStart = std::function<void (ApplicationMonitoredItemStartContext*)>;
		using MonitoredItemStop = std::function<void (ApplicationMonitoredItemStopContext*)>;
	};

}

#endif
