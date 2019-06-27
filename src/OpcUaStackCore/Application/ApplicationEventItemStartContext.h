/*
   Copyright 2017-2018 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ApplicationEventItemStartContext_h__
#define __OpcUaStackCore_ApplicationEventItemStartContext_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackCore/Base/UserContext.h"


namespace OpcUaStackCore
{

	class DLLEXPORT ApplicationEventItemStartContext
	{
	  public:
		ApplicationEventItemStartContext(void);
		~ApplicationEventItemStartContext(void);

		BaseClass::SPtr applicationContext_;	// IN - application context from register call
		uint32_t eventItemId_;					// IN - event item identifier
		UserContext::SPtr userContext_;			// IN - user context
	};

}

#endif
