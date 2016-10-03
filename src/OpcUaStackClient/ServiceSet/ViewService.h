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
#include "OpcUaStackClient/ServiceSet/ViewServiceIf.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient 
{

	class DLLEXPORT ViewService
	: public Component
	{
	  public:
		typedef boost::shared_ptr<ViewService> SPtr;

		ViewService(IOThread* ioThread);
		~ViewService(void);

		void setConfiguration(
			Component* componentSession,
			ViewServiceIf* viewServiceIf
		);
		void componentSession(Component* componentSession);
		void viewServiceIf(ViewServiceIf* viewServiceIf);

		void syncSend(ServiceTransactionBrowse::SPtr serviceTransactionBrowse);
		void asyncSend(ServiceTransactionBrowse::SPtr serviceTransactionBrowse);
		void syncSend(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext);
		void asyncSend(ServiceTransactionBrowseNext::SPtr serviceTransactionBrowseNext);
		void syncSend(ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTransactionTranslateBrowsePathsToNodeIds);
		void asyncSend(ServiceTransactionTranslateBrowsePathsToNodeIds::SPtr serviceTransactionTranslateBrowsePathsToNodeIds);


		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		Component* componentSession_;

		ViewServiceIf* viewServiceIf_;
	};

}

#endif
