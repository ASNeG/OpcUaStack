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

#ifndef __OpcUaStackClient_SecureChannelIf_h__
#define __OpcUaStackClient_SecureChannelIf_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackClient/SecureChannel/SecureChannelTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT SecureChannelIf
	{
	  public:
		virtual ~SecureChannelIf(void) {}

		virtual void connect(void) = 0;
		virtual void disconnect(void) = 0;
		virtual bool receive(SecureChannelTransaction::SPtr secureChannelTransaction) = 0;
	};

}

#endif
