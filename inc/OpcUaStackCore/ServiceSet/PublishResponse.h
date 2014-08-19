#ifndef __OpcUaStackCore_PublishResponse_h__
#define __OpcUaStackCore_PublishResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/NotificationMessage.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT PublishResponse : public ObjectPool<PublishResponse>
	{
	  public:
	    PublishResponse(void);
		~PublishResponse(void);

		void responseHeader(const ResponseHeader::SPtr responseHeader);
		ResponseHeader::SPtr responseHeader(void) const;
		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void availableSequenceNumbers(const OpcUaUInt32Array::SPtr availableSequenceNumbers);
		OpcUaUInt32Array::SPtr availableSequenceNumbers(void) const;
		void moreNotifications(const OpcUaBoolean& moreNotifications);
		OpcUaBoolean moreNotifications(void) const;
		void notificationMessage(const NotificationMessage::SPtr notificationMessage);
		NotificationMessage::SPtr notificationMessage(void);
		void results(const OpcUaStatusCodeArray::SPtr results);
		OpcUaStatusCodeArray::SPtr results(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		ResponseHeader::SPtr responseHeaderSPtr_;
		OpcUaUInt32 subscriptionId_;
		OpcUaUInt32Array::SPtr availableSequenceNumberArraySPtr_;
		OpcUaBoolean moreNotifications_;
		NotificationMessage::SPtr notficiationMessageSPtr_;
		OpcUaStatusCodeArray::SPtr statusCodeArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};
}

#endif