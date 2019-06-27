/*
   Copyright 2015-2017 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackServer_ApplicationServiceIf_h__
#define __OpcUaStackServer_ApplicationServiceIf_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/Callback.h"
#include "OpcUaStackCore/ServiceSet/ServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackServer
{

	class DLLEXPORT ApplicationServiceIf
	{
	  public:
		ApplicationServiceIf(void) {}
		virtual ~ApplicationServiceIf(void) {}

		virtual void send(ServiceTransaction::SPtr serviceTransaction) = 0;
		virtual void sendSync(ServiceTransaction::SPtr serviceTransaction) = 0;
		virtual void reload(void) {}
	};

}

#endif
