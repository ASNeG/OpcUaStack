/*
   Copyright 2016-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ApplicationRegisterServerContext_h__
#define __OpcUaStackCore_ApplicationRegisterServerContext_h__

#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackCore/StandardDataTypes/RegisteredServer.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ApplicationRegisterServerContext
	{
	  public:
		ApplicationRegisterServerContext(void);
		~ApplicationRegisterServerContext(void);

		BaseClass::SPtr applicationContext_;	// IN - application context from register call
		RegisteredServer server_;				// IN - information about the server to be registered
		OpcUaStatusCode statusCode_;			// OUT - result state of the register operation
	};

}

#endif
