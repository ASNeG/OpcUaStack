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

#ifndef __OpcUaStackCore_ApplicationAuthenticationContext_h__
#define __OpcUaStackCore_ApplicationAuthenticationContext_h__

#include "OpcUaStackCore/Base/UserContext.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaExtensibleParameter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT ApplicationAuthenticationContext
	{
	  public:
		ApplicationAuthenticationContext(void);
		~ApplicationAuthenticationContext(void);

		uint32_t authenticationType_;				// IN - authentication type
		OpcUaExtensibleParameter::SPtr parameter_;	// IN - authentication parameter
		uint32_t sessionId_;						// IN - session id
		OpcUaStatusCode statusCode_;				// OUT - result state of the write operation
		UserContext::SPtr userContext_;		    	// OUT - user context
	};

}

#endif
