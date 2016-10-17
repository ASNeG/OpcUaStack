/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_ApplicationFindServerContext_h__
#define __OpcUaStackCore_ApplicationFindServerContext_h__

#include "OpcUaStackCore/Base/BaseClass.h"
#include "OpcUaStackCore/ServiceSet/ApplicationDescription.h"

namespace OpcUaStackCore
{

	class ApplicationFindServerContext
	{
	  public:
		BaseClass::SPtr applicationContext_;	// IN - application context from register call

		OpcUaString endpointUrl_;				// IN -
		OpcUaStringArray::SPtr localeIdArraySPtr_; // IN -
		OpcUaStringArray::SPtr serverUriArraySPtr_; // IN -

		ApplicationDescriptionArray::SPtr servers_; // OUT -
		OpcUaStatusCode statusCode_;			// OUT - result state of the find operation

	};

}

#endif
