/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ApplicationAutorizationContext_h__
#define __OpcUaStackCore_ApplicationAutorizationContext_h__

#include "OpcUaStackCore/Base/UserContext.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"

namespace OpcUaStackCore
{

	typedef enum
	{
		Read,
		Write,
		HRead,
		HWrite,
		MonitoredItem,
		EventItem,
		Method
	} ServiceOperation;

	class DLLEXPORT ApplicationAutorizationContext
	{
	  public:
		ApplicationAutorizationContext(void);
		~ApplicationAutorizationContext(void);

		UserContext::SPtr userContext_;			// IN - user context
		ServiceOperation serviceOperation_;		// IN - service operation
		OpcUaNodeId nodeId_;					// IN - node id
		OpcUaNodeId nodeId1_;					// IN - second node id (method object node id)
		uint32_t attributeId_;					// IN - attribute id
		OpcUaStatusCode statusCode_;			// OUT - result state of the write operation
	};

}

#endif
