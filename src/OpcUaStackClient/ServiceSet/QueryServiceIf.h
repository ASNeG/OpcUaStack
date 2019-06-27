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

#ifndef __OpcUaStackClient_QueryServiceIf_h__
#define __OpcUaStackClient_QueryServiceIf_h__

#include "OpcUaStackCore/Base/Condition.h"
#include "OpcUaStackCore/ServiceSet/QueryServiceTransaction.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient
{

	class DLLEXPORT QueryServiceIf
	{
	  public:
		QueryServiceIf(void) {}
		virtual ~QueryServiceIf(void) {}

        virtual void queryServiceQueryFirstResponse(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst) {};
        virtual void queryServiceQueryNextResponse(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext) {};
	};

	class DLLEXPORT QueryServiceIfTestHandler
	: public QueryServiceIf
	{
	  public:
		QueryServiceIfTestHandler(void);
		virtual ~QueryServiceIfTestHandler(void);

		Condition queryServiceQueryFirstResponse_;
        void queryServiceQueryFirstResponse(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst);

        Condition queryServiceQueryNextResponse_;
        void queryServiceQueryNextResponse(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext);
	};

}

#endif
