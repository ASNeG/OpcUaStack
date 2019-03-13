/*
   Copyright 2019 Kai Huebl (kai@huebl-sgh.de)

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
#ifndef __OpcUaStackClient_SessionTransaction_h__
#define __OpcUaStackClient_SessionTransaction_h__

#include <future>
#include "OpcUaStackCore/BuildInTypes/OpcUaStatusCode.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	enum class Operation
	{
		None,
		Connect,
		Disconnect
	};

	class DLLEXPORT SessionTransaction
	{
	  public:
		typedef boost::shared_ptr<SessionTransaction> SPtr;
		typedef boost::weak_ptr<SessionTransaction> WPtr;

		SessionTransaction(void);
		~SessionTransaction(void);

		Operation operation_;
		std::promise<OpcUaStatusCode> prom_;
	};

}

#endif
