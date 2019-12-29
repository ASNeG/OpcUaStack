/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#ifndef __OpcUaStackCore_PublishResponse_h__
#define __OpcUaStackCore_PublishResponse_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaDiagnosticInfo.h"
#include "OpcUaStackCore/StandardDataTypes/NotificationMessage.h"
#include "OpcUaStackCore/SecureChannel/ResponseHeader.h"

namespace OpcUaStackCore
{

	class DLLEXPORT PublishResponse
	: public Object
	{
	  public:
		typedef boost::shared_ptr<PublishResponse> SPtr;

	    PublishResponse(void);
		~PublishResponse(void);

		void subscriptionId(const OpcUaUInt32& subscriptionId);
		OpcUaUInt32 subscriptionId(void) const;
		void availableSequenceNumbers(const OpcUaUInt32Array::SPtr availableSequenceNumbers);
		OpcUaUInt32Array::SPtr& availableSequenceNumbers(void);
		void moreNotifications(const OpcUaBoolean& moreNotifications);
		OpcUaBoolean moreNotifications(void) const;
		void notificationMessage(const NotificationMessage::SPtr notificationMessage);
		NotificationMessage::SPtr notificationMessage(void);
		void results(const OpcUaStatusCodeArray::SPtr results);
		OpcUaStatusCodeArray::SPtr results(void) const;
		void diagnosticInfos(const OpcUaDiagnosticInfoArray::SPtr diagnosticInfos);
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfos(void) const;

		bool opcUaBinaryEncode(std::ostream& os) const;
		bool opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 subscriptionId_;
		OpcUaUInt32Array::SPtr availableSequenceNumberArraySPtr_;
		OpcUaBoolean moreNotifications_;
		NotificationMessage::SPtr notficiationMessageSPtr_;
		OpcUaStatusCodeArray::SPtr statusCodeArraySPtr_;
		OpcUaDiagnosticInfoArray::SPtr diagnosticInfoArraySPtr_;
	};
}

#endif
