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

#ifndef __OpcUaStackCore_ApplicationWriteContext_h__
#define __OpcUaStackCore_ApplicationWriteContext_h__

#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackCore/Base/UserContext.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDataValue.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ApplicationWriteContext
	{
	  public:
		ApplicationWriteContext(void);
		~ApplicationWriteContext(void);

		BaseClass::SPtr applicationContext_;	// IN - application context from register call
		OpcUaNodeId nodeId_;					// IN - node id to be write
		uint32_t attributeId_;					// IN - attribute id to be write
		OpcUaDataValue dataValue_;				// IN - variable
		UserContext::SPtr userContext_;			// IN - user context
		OpcUaStatusCode statusCode_;			// OUT - result state of the write operation
	};

}

#endif
