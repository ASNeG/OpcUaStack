#ifndef __OpcUaStackClient_AttributeService_h__
#define __OpcUaStackClient_AttributeService_h__

#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Component/Component.h"
#include "OpcUaStackCore/ServiceSet/AttributeServiceTransaction.h"
#include "OpcUaStackClient/ServiceSet/Session.h"

using namespace OpcUaStackCore;

namespace OpcUaStackClient 
{

	class DLLEXPORT AttributeServiceIf
	{
	  public:
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
