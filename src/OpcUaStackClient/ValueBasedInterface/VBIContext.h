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

#ifndef __OpcUaStackClient_VBIContext_h__
#define __OpcUaStackClient_VBIContext_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackClient/ServiceSet/ServiceSetManager.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackClient;

namespace OpcUaStackClient
{

	class DLLEXPORT ConnectContext
	{
	  public:
		ConnectContext(void);
		~ConnectContext(void);

		std::string endpointUrl_;
		std::string sessionName_;
	};


	class DLLEXPORT ReadContext
	{
	  public:
		ReadContext(void);
		~ReadContext(void);

		OpcUaInt32 attributeId_;
	};


	class DLLEXPORT WriteContext
	{
	  public:
		WriteContext(void);
		~WriteContext(void);

		OpcUaInt32 attributeId_;
	};

	class DLLEXPORT CreateSubscriptionContext
	{
	  public:
		CreateSubscriptionContext(void);
		~CreateSubscriptionContext(void);

		OpcUaDouble requestedPublishingInterval_;
		OpcUaUInt32 requestedLifetimeCount_;
		OpcUaUInt32 requestedMaxKeepAliveCount_;
		OpcUaUInt32 maxNotificationsPerPublish_;
		OpcUaBoolean publishingEnabled_;
		OpcUaByte priority_;
	};

	class DLLEXPORT DeleteSubscriptionContext
	{
	  public:
		DeleteSubscriptionContext(void);
		~DeleteSubscriptionContext(void);
	};

	class DLLEXPORT CreateMonitoredItemContext
	{
	  public:
		CreateMonitoredItemContext(void);
		~CreateMonitoredItemContext(void);

		OpcUaDouble samplingInterval_;
		ExtensibleParameter filter_;
		OpcUaUInt32 queueSize_;
		OpcUaBoolean discardOldest_;
		OpcUaUInt32 attributeId_;
	};

	class DLLEXPORT DeleteMonitoredItemContext
	{
	  public:
		DeleteMonitoredItemContext(void);
		~DeleteMonitoredItemContext(void);
	};

}

#endif
