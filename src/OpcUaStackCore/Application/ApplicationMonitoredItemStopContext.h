/*
   Copyright 2016-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ApplicationMonitoredItemStopContext_h__
#define __OpcUaStackCore_ApplicationMonitoredItemStopContext_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackCore/Base/UserContext.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/ServiceSetApplication/NodeReference.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ApplicationMonitoredItemStopContext
	{
	  public:
		ApplicationMonitoredItemStopContext(void);
		~ApplicationMonitoredItemStopContext(void);

		BaseClass::SPtr applicationContext_;	// IN - application context from register call
		OpcUaNodeId nodeId_;					// IN - node id to be monitored
		bool lastMonitoredItem_;				// IN - the last monitored item has been closed
		NodeReference::SPtr nodeReference_;		// IN - reference to base node class
		UserContext::SPtr userContext_;			// IN - user context
	};

}

#endif
