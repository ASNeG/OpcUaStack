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

#ifndef __OpcUaStackCore_NotificationMessage_h__
#define __OpcUaStackCore_NotificationMessage_h__

#include "OpcUaStackCore/BuildInTypes/OpcUaNodeId.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/ServiceSet/ExtensibleParameter.h"

namespace OpcUaStackCore
{

	class DLLEXPORT NotificationMessage
	: public Object
	{
	  public:
		typedef boost::shared_ptr<NotificationMessage> SPtr;

	    NotificationMessage(void);
		~NotificationMessage(void);

		void sequenceNumber(const OpcUaUInt32& sequenceNumber);
		OpcUaUInt32 sequenceNumber(void);
		void publishTime(const boost::posix_time::ptime& time);
		UtcTime& publishTime(void);
		void notificationData(const ExtensibleParameterArray::SPtr notificationData);
		ExtensibleParameterArray::SPtr notificationData(void) const;

		void opcUaBinaryEncode(std::ostream& os) const;
		void opcUaBinaryDecode(std::istream& is);

	  private:
		OpcUaUInt32 sequenceNumber_;
		UtcTime publishTime_;
		ExtensibleParameterArray::SPtr notificationDataArraySPtr_;
	};
}

#endif
