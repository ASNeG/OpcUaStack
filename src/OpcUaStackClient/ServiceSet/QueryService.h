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

#ifndef __OpcUaStackClient_QueryService_h__
#define __OpcUaStackClient_QueryService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/QueryServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/QueryServiceIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient 
{

	class DLLEXPORT QueryService : public Component
	{
	  public:
		typedef boost::shared_ptr<QueryService> SPtr;

		QueryService(IOThread* ioThread);
		~QueryService(void);

		void setConfiguration(
			Component* componentSession,
			QueryServiceIf* queryServiceIf
		);
		void componentSession(Component* componentSession);
		void queryServiceIf(QueryServiceIf* queryServiceIf);

		void syncSend(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst);
		void asyncSend(ServiceTransactionQueryFirst::SPtr serviceTransactionQueryFirst);
		void syncSend(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext);
		void asyncSend(ServiceTransactionQueryNext::SPtr serviceTransactionQueryNext);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		Component* componentSession_;

		QueryServiceIf* queryServiceIf_;
	};

}

#endif
