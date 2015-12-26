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

#ifndef __OpcUaStackClient_AttributeService_h__
#define __OpcUaStackClient_AttributeService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/SessionOld.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient 
{

	class DLLEXPORT AttributeServiceIf
	{
	  public:
		virtual ~AttributeServiceIf(void) {}

        virtual void attributeServiceReadResponse(ServiceTransactionRead::SPtr serviceTransactionRead) {};
		virtual void attributeServiceWriteResponse(ServiceTransactionWrite::SPtr serviceTransactionWrite) {};
		virtual void attributeServiceHistoryReadResponse(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead) {};
		virtual void attributeServiceHistoryUpdateResponse(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate) {};
	};

	class DLLEXPORT AttributeService : public Component
	{
	  public:
		boost::shared_ptr<AttributeService> SPtr;

		AttributeService(void);
		~AttributeService(void);

		void componentSession(Component* componentSession);
		void attributeServiceIf(AttributeServiceIf* attributeServiceIf);

		void sendSync(ServiceTransactionRead::SPtr serviceTransactionRead);
		void send(ServiceTransactionRead::SPtr serviceTransactionRead);
		void sendSync(ServiceTransactionWrite::SPtr serviceTransactionWrite);
		void send(ServiceTransactionWrite::SPtr serviceTransactionWrite);
		void sendSync(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead);
		void send(ServiceTransactionHistoryRead::SPtr serviceTransactionHistoryRead);
		void sendSync(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate);
		void send(ServiceTransactionHistoryUpdate::SPtr serviceTransactionHistoryUpdate);

		//- Component -----------------------------------------------------------------
		void receive(Message::SPtr message);
		//- Component -----------------------------------------------------------------

	  private:
		Component* componentSession_;

		AttributeServiceIf* attributeServiceIf_;
	};

}

#endif
