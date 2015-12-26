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

#ifndef __OpcUaStackClient_ViewService_h__
#define __OpcUaStackClient_ViewService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/ViewServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/SessionOld.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient 
{

	class DLLEXPORT ViewServiceIf
	{
	  public:
        virtual void viewServiceBrowseResponse(ServiceTransactionBrowse::SPtr serviceTransactionBrowse) {};
        virtual void viewServiceBrowseNextResponse(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext) {};
	};

	class DLLEXPORT ViewService : public Component
	{
	  public:
		typedef boost::shared_ptr<ViewService> SPtr;

		ViewService(void);
		~ViewService(void);

		void componentSession(Component* componentSession);
		void viewServiceIf(ViewServiceIf* viewServiceIf);

		void sendSync(ServiceTransactionBrowse::SPtr serviceTransactionBrowse);
		void send(ServiceTransactionBrowse::SPtr serviceTransactionBrowse);

		void sendSync(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext);
		void send(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext);


		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		Component* componentSession_;

		ViewServiceIf* viewServiceIf_;
	};

}

#endif
